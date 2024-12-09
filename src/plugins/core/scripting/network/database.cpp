#include "../../scripting.h"
#include "../../../../entrypoint.h"
#include "../../../../player/playermanager/PlayerManager.h"

#include <deque>
#include <thread>

#include <vector>
#include <map>

std::string FetchPluginName(lua_State* state);
#define FetchPluginByState(state) g_pluginManager->FetchPlugin(FetchPluginName(state))

struct DatabaseQueryQueue
{
    std::string query;
    std::string requestID;
    IDatabase* db;
    Plugin* plugin;
};

std::deque<DatabaseQueryQueue> queryQueue;
bool dbThreadStarted = false;

std::string QueryToJSON(const std::vector<std::map<std::string, std::any>>& data)
{
    rapidjson::Document document(rapidjson::kArrayType);

    for (const auto& map : data)
    {
        rapidjson::Value entry(rapidjson::kObjectType);

        for (const auto& pair : map)
        {
            const char* key = pair.first.c_str();
            const std::any& value = pair.second;

            if (value.type() == typeid(const char*))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetString(std::any_cast<const char*>(value), document.GetAllocator()), document.GetAllocator());
            else if (value.type() == typeid(std::string))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetString(std::any_cast<std::string>(value).c_str(), document.GetAllocator()), document.GetAllocator());
            else if (value.type() == typeid(uint64))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetUint64(std::any_cast<uint64>(value)), document.GetAllocator());
            else if (value.type() == typeid(uint32))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetUint(std::any_cast<uint32>(value)), document.GetAllocator());
            else if (value.type() == typeid(uint16))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetUint(std::any_cast<uint16>(value)), document.GetAllocator());
            else if (value.type() == typeid(uint8))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetUint(std::any_cast<uint8>(value)), document.GetAllocator());
            else if (value.type() == typeid(int64))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetInt64(std::any_cast<int64>(value)), document.GetAllocator());
            else if (value.type() == typeid(int32))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetInt(std::any_cast<int32>(value)), document.GetAllocator());
            else if (value.type() == typeid(int16))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetInt(std::any_cast<int16>(value)), document.GetAllocator());
            else if (value.type() == typeid(int8))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetInt(std::any_cast<int8>(value)), document.GetAllocator());
            else if (value.type() == typeid(bool))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetBool(std::any_cast<bool>(value)), document.GetAllocator());
            else if (value.type() == typeid(float))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetFloat(std::any_cast<float>(value)), document.GetAllocator());
            else if (value.type() == typeid(double))
                entry.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetDouble(std::any_cast<double>(value)), document.GetAllocator());
        }

        document.PushBack(entry, document.GetAllocator());
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    return std::string(buffer.GetString());
}

void DatabaseLuaCallback(std::vector<std::any> res)
{
    std::string databaseRequestID = std::any_cast<std::string>(res[0]);
    std::string result = std::any_cast<std::string>(res[1]);
    std::string err = std::any_cast<std::string>(res[2]);
    LuaPlugin* plugin = std::any_cast<LuaPlugin*>(res[3]);

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    plugin->PluginTriggerEvent("core", "OnDatabaseActionPerformed", encoders::msgpack::SerializeToString({ databaseRequestID, result, err }), event);
    delete event;
}

void DatabaseQueryThread()
{
    while (true)
    {
        while (!queryQueue.empty())
        {
            DatabaseQueryQueue queue = queryQueue.front();

            if (!queue.db->IsConnected()) {
                PRINT("The following query has been skipped due to the database not being connected.\n");
                PRINTF("Query: \"%s\".\n", queue.query.c_str());
                queryQueue.pop_front();
                continue;
            }

            auto queryResult = queue.db->Query(queue.query);
            std::string error = queue.db->GetError();
            if (error == "MySQL server has gone away") {
                if (queue.db->Connect())
                    continue;
                else
                    error = queue.db->GetError();
            }
            std::string result = QueryToJSON(queryResult);

            if (queue.plugin->GetKind() == PluginKind_t::Lua)
                g_Plugin.NextFrame(DatabaseLuaCallback, { queue.requestID, result, error, (LuaPlugin*)queue.plugin });

            queryQueue.pop_front();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

PluginDatabase::PluginDatabase(std::string m_connection_name)
{
    this->connection_name = m_connection_name;
    this->db = g_dbManager->GetDatabase(this->connection_name);
    
    if(!this->db && this->connection_name != "default_connection") {
        PRINTF("Database connection \"%s\" doesn't exists inside the database configurations. Automatically falling back to \"default_connection\".\n", m_connection_name.c_str());
        this->db = g_dbManager->GetDatabase("default_connection");
    }

    if (!this->db)
        this->dbConnected = false;
    else
        this->dbConnected = this->db->Connect();
}

bool PluginDatabase::IsConnected()
{
    return this->dbConnected;
}

std::string PluginDatabase::EscapeString(std::string str)
{
    return this->db->EscapeValue(str);
}

void PluginDatabase::QueryLua(std::string query, luabridge::LuaRef callback, lua_State* L)
{
    std::string uuid = get_uuid();

    DatabaseQueryQueue queue = {
        query,
        uuid,
        this->db,
        FetchPluginByState(L),
    };
    queryQueue.push_back(queue);

    luabridge::LuaRef databaseRequestsQueue = luabridge::getGlobal(L, "databaseRequestsQueue");
    if (databaseRequestsQueue.isTable())
        databaseRequestsQueue[uuid] = callback;

    if (!dbThreadStarted)
    {
        dbThreadStarted = true;
        std::thread(DatabaseQueryThread).detach();
    }
}

void PluginDatabase::QueryParamsLua(std::string query, std::map<luabridge::LuaRef, luabridge::LuaRef> params, luabridge::LuaRef callback, lua_State* L)
{
    bool has_ats = (query.find_first_of("@") != std::string::npos);
    bool has_brace = (query.find_first_of("{") != std::string::npos);
    bool has_bracket = (query.find_first_of("[") != std::string::npos);

    for (auto it = params.begin(); it != params.end(); ++it)
    {
        std::string key = it->first.isString() ? it->first.cast<char const*>() : it->first.tostring();
        std::string value = EscapeString(it->second.isString() ? it->second.cast<char const*>() : it->second.tostring());

        if (has_ats)
            query = replace(query, "@" + key, value);

        if (has_brace)
            query = replace(query, "{" + key + "}", value);

        if (has_bracket)
            query = replace(query, "[" + key + "]", value);
    }

    return QueryLua(query, callback, L);
}

PluginDatabaseQueryBuilder PluginDatabase::QueryBuilderLua()
{
    return PluginDatabaseQueryBuilder(this);
}

#define ENSURE_TABLE_SET() \
    if (this->tableName.empty()) { \
        throw std::runtime_error("Table name must be set before executing the query."); \
    }


PluginDatabaseQueryBuilder::PluginDatabaseQueryBuilder(PluginDatabase* db)
{
    this->db = db;
}

void PluginDatabaseQueryBuilder::Clear()
{
    tableName.clear();
    query.clear();
    selectColumns.clear();
    whereClauses.clear();
    orWhereClauses.clear();
    joinClauses.clear();
    groupByClauses.clear();
    orderByClauses.clear();
    onDuplicateClauses.clear();
    havingClauses.clear();
    unionClauses.clear();
    updatePairs.clear();

    isDistinct = false;
    limitCount = -1;
    offsetCount = -1;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Table(const std::string& tableName)
{
    this->tableName = tableName;
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Create(const std::map<std::string, std::string>& columns)
{
    ENSURE_TABLE_SET();
    this->query = "CREATE TABLE IF NOT EXISTS " + this->tableName + " (";
    std::vector<std::string> columnDefinitions;
    for (const auto& pair : columns)
    {
        columnDefinitions.push_back(pair.first + " " + pair.second);
    }
    this->query += join(columnDefinitions, ", ") + ")";
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Alter(const std::string& alterCommand)
{
    ENSURE_TABLE_SET()
    this->query = "ALTER TABLE " + this->tableName + " " + alterCommand;
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Drop()
{
    ENSURE_TABLE_SET();
    this->query = "DROP TABLE IF EXISTS " + this->tableName;
    return this;
}


PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Select(const std::vector<std::string>& columns) {
    ENSURE_TABLE_SET();
    if (columns.empty()) {
        this->query = "SELECT * FROM " + this->tableName;
    } else {
        this->query = "SELECT " + join(columns, ", ") + " FROM " + this->tableName;
    }
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Insert(const std::map<std::string, luabridge::LuaRef>& data, lua_State* L) {
    ENSURE_TABLE_SET();

    if (data.empty()) {
        throw std::invalid_argument("Insert requires at least one column-value pair.");
    }

    std::vector<std::string> columns;
    std::vector<std::string> values;

    for (const auto& pair : data) {
        columns.push_back(pair.first);
        values.push_back(FormatValue(pair.second, L));
    }

    this->query = "INSERT INTO " + tableName + " (" + join(columns, ", ") + ") VALUES (" + join(values, ", ") + ")";
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Update(const std::map<std::string, luabridge::LuaRef>& data, lua_State* L) {
    ENSURE_TABLE_SET();

    if (data.empty()) {
        throw std::invalid_argument("Update requires at least one column-value pair.");
    }
    std::vector<std::string> updates;
    for (const auto& pair : data) {
        updates.push_back(pair.first + " = " + FormatValue(pair.second, L));
    }

    this->query = "UPDATE " + tableName + " SET " + join(updates, ", ");
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Delete() {
    ENSURE_TABLE_SET();

    this->query = "DELETE FROM " + tableName;
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Where(const std::string& column, const std::string& operator_, const luabridge::LuaRef& value, lua_State* L) {
    this->whereClauses.push_back(column + " " + operator_ + " " + FormatValue(value, L));
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::OrWhere(const std::string& column, const std::string& operator_, const luabridge::LuaRef& value, lua_State* L) {
    this->orWhereClauses.push_back(column + " " + operator_ + " " + FormatValue(value, L));
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Join(const std::string& table, const std::string& onCondition, const std::string& joinType) {
    this->joinClauses.push_back(joinType + " JOIN " + table + " ON " + onCondition);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::OrderBy(const std::vector<std::pair<std::string, std::string>>& columns) {
    if (columns.empty())
    {
        throw std::invalid_argument("OrderBy requires at least one column-value pair.");
    }
    for (const auto& column : columns) {
        this->orderByClauses.push_back(column.first + " " + column.second);
    }
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Limit(int count) {
    this->limitCount = count;
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::GroupBy(const std::vector<std::string>& columns) {
    this->groupByClauses = columns;
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::OnDuplicate(const std::map<std::string, luabridge::LuaRef>& data, lua_State* L) {
    if (data.empty()) {
        throw std::invalid_argument("OnDuplicate requires at least one column-value pair.");
    }

    for (const auto& pair : data) {
        this->onDuplicateClauses.push_back(pair.first + " = " + FormatValue(pair.second, L));
    }
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Having(const std::string& condition) {
    if (condition.empty()) {
        throw std::invalid_argument("Having condition cannot be empty.");
    }
    this->havingClauses.push_back(condition);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Distinct() {
    ENSURE_TABLE_SET();
    this->isDistinct = true;
    return this;
}


PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Offset(int count) {
    if (count < 0) {
        throw std::invalid_argument("Offset cannot be negative.");
    }
    this->offsetCount = count;
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Union(const std::string& query, bool all) {
    if (query.empty()) {
        throw std::invalid_argument("Union query cannot be empty.");
    }
    std::string unionType = all ? "UNION ALL" : "UNION";
    this->unionClauses.push_back(unionType + " " + query);
    return this;
}

void PluginDatabaseQueryBuilder::Execute(luabridge::LuaRef callback, lua_State* L) {
    std::string finalQuery = this->ToString();
    this->db->QueryLua(finalQuery, callback, L);
    this->Clear();
}

std::string PluginDatabaseQueryBuilder::ToString() {
    std::string finalQuery = this->query;

    // Add DISTINCT after SELECT if needed
    if (this->query.rfind("SELECT", 0) == 0 && this->isDistinct) {
        finalQuery.insert(6, " DISTINCT");
    }

    // Join clauses
    if (!this->joinClauses.empty()) {
        finalQuery += " " + join(this->joinClauses, " ");
    }

    // Add WHERE clause, handle AND/OR combination
    if (!this->whereClauses.empty() || !this->orWhereClauses.empty()) {
        std::string combinedWhereClause;
        
        // Handle WHERE
        if (!this->whereClauses.empty()) {
            combinedWhereClause += join(whereClauses, " AND ");
        }
        
        // Handle OR WHERE
        if (!this->orWhereClauses.empty()) {
            if (!combinedWhereClause.empty()) {
                combinedWhereClause += " OR ";
            }
            combinedWhereClause += join(orWhereClauses, " OR ");
        }
        
        // Add to final query
        finalQuery += " WHERE " + combinedWhereClause;
    }

    // Add GROUP BY clauses
    if (!this->groupByClauses.empty()) {
        finalQuery += " GROUP BY " + join(groupByClauses, ", ");
    }

    // Add HAVING clauses
    if (!this->havingClauses.empty()) {
        finalQuery += " HAVING " + join(this->havingClauses, " AND ");
    }

    // Add ORDER BY clauses
    if (!this->orderByClauses.empty()) {
        finalQuery += " ORDER BY " + join(this->orderByClauses, ", ");
    }

    // Add LIMIT if specified
    if (this->limitCount >= 0) {
        finalQuery += " LIMIT " + std::to_string(limitCount);
    }

    // Add OFFSET if specified
    if (this->offsetCount >= 0) {
        finalQuery += " OFFSET " + std::to_string(offsetCount);
    }

    // Add ON DUPLICATE KEY UPDATE if specified
    if (!this->onDuplicateClauses.empty()) {
        finalQuery += " ON DUPLICATE KEY UPDATE " + join(this->onDuplicateClauses, ", ");
    }

    // Add UNION clauses if any
    if (!this->unionClauses.empty()) {
        finalQuery += " " + join(this->unionClauses, " ");
    }

    return finalQuery;
}


bool isInteger(luabridge::LuaRef r) {
    if(!r.isNumber()) return false;
    double d = r.cast<double>();
    return ((double)(int64_t)d == d); 
}

std::string LuaTableToJson(const luabridge::LuaRef& luaValue, lua_State* L) {
    rapidjson::Document document;
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

    std::function<rapidjson::Value(const luabridge::LuaRef&)> LuaTableToJsonValue =
        [&](const luabridge::LuaRef& luaValue) -> rapidjson::Value {
        rapidjson::Value result;
        bool isArray = true;

        for (luabridge::Iterator it(luaValue); !it.isNil(); ++it) {
            if (!it.key().isNumber()) {
                isArray = false;
                break;
            }
        }

        if (isArray) {
            result.SetArray();
            for (luabridge::Iterator it(luaValue); !it.isNil(); ++it) {
                const luabridge::LuaRef& value = it.value();
                if (value.isTable()) {
                    result.PushBack(LuaTableToJsonValue(value), allocator);
                } else if (value.isBool()) {
                    result.PushBack(rapidjson::Value().SetBool(value.cast<bool>()), allocator);
                } else if (value.isNumber()) {
                    if (value.cast<double>() == static_cast<int64_t>(value.cast<double>())) {
                        result.PushBack(rapidjson::Value().SetInt64(value.cast<int64_t>()), allocator);
                    } else {
                        result.PushBack(rapidjson::Value().SetDouble(value.cast<double>()), allocator);
                    }
                } else if (value.isString()) {
                    result.PushBack(rapidjson::Value(value.cast<std::string>().c_str(), allocator), allocator);
                } else {
                    result.PushBack(rapidjson::Value("unsupported_type", allocator), allocator);
                }
            }
        } else {
            result.SetObject();
            for (luabridge::Iterator it(luaValue); !it.isNil(); ++it) {
                const luabridge::LuaRef& key = it.key();
                const luabridge::LuaRef& value = it.value();
                std::string keyStr = key.isString() ? key.cast<std::string>() : std::to_string(key.cast<int>());
                rapidjson::Value jsonKey(keyStr.c_str(), allocator);

                if (value.isTable()) {
                    result.AddMember(jsonKey, LuaTableToJsonValue(value), allocator);
                } else if (value.isBool()) {
                    result.AddMember(jsonKey, rapidjson::Value().SetBool(value.cast<bool>()), allocator);
                } else if (value.isNumber()) {
                    if (value.cast<double>() == static_cast<int64_t>(value.cast<double>())) {
                        result.AddMember(jsonKey, rapidjson::Value().SetInt64(value.cast<int64_t>()), allocator);
                    } else {
                        result.AddMember(jsonKey, rapidjson::Value().SetDouble(value.cast<double>()), allocator);
                    }
                } else if (value.isString()) {
                    result.AddMember(jsonKey, rapidjson::Value(value.cast<std::string>().c_str(), allocator), allocator);
                } else {
                    result.AddMember(jsonKey, rapidjson::Value("unsupported_type", allocator), allocator);
                }
            }
        }

        return result;
    };

    rapidjson::Value jsonRoot = LuaTableToJsonValue(luaValue);
    document.Swap(jsonRoot);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    return buffer.GetString();
}

std::string PluginDatabaseQueryBuilder::FormatValue(const luabridge::LuaRef& luaValue, lua_State* L) {
    if (luaValue.isNil()) {
        return "NULL";
    }
    else if (luaValue.isBool()) {
        return luaValue.cast<bool>() ? "1" : "0";
    }
    else if (isInteger(luaValue)) { 
        return std::to_string(luaValue.cast<int64_t>());
    }
    else if (luaValue.isNumber()) {
        return std::to_string(luaValue.cast<double>());
    }
    else if (luaValue.isString()) {
        return "\'" + this->db->EscapeString(luaValue.cast<std::string>()) + "\'";
    }
    else if (luaValue.isTable()) {
        try {
            std::string json = LuaTableToJson(luaValue, L);
            return "\'" + json + "\'";
        } catch (const std::exception& e) {
            throw std::invalid_argument(std::string("Error serializing Lua table to JSON: ") + e.what());
        }
    }
    else {
        throw std::invalid_argument("Unsupported Lua value type for SQL query");
    }
}
template<typename T>
std::string PluginDatabaseQueryBuilder::join(const std::vector<T>& vec, const std::string& delimiter) {
    std::ostringstream oss;
    for (size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if (i != vec.size() - 1) {
            oss << delimiter;
        }
    }
    return oss.str();
}
