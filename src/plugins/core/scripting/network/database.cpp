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
    Database* db;
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

            RegisterCallStack* callStack = new RegisterCallStack(queue.plugin->GetName(), string_format("database::Query(database=%p, query=\"%s\")", (void*)queue.db, queue.query.c_str()));

            auto queryResult = queue.db->Query(queue.query.c_str());
            std::string error = queue.db->GetError();
            if (error == "MySQL server has gone away") {
                if (queue.db->Connect())
                {
                    delete callStack;
                    continue;
                }
                else
                    error = queue.db->GetError();
            }
            std::string result = QueryToJSON(queryResult);

            if (queue.plugin->GetKind() == PluginKind_t::Lua)
                g_Plugin.NextFrame(DatabaseLuaCallback, { queue.requestID, result, error, (LuaPlugin*)queue.plugin });

            delete callStack;

            queryQueue.pop_front();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

PluginDatabase::PluginDatabase(std::string m_connection_name)
{
    this->connection_name = m_connection_name;
    this->db = g_dbManager->GetDatabase(this->connection_name);
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
    return this->db->QueryEscape(str.c_str());
}

void PluginDatabase::QueryLua(std::string query, luabridge::LuaRef callback, lua_State* L)
{
    REGISTER_CALLSTACK(FetchPluginName(L), string_format("PluginDatabase::QueryLua(query=\"%s\")", query.c_str()));

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

PluginDatabaseQueryBuilder::PluginDatabaseQueryBuilder(PluginDatabase* db)
{
    this->db = db;
}

PluginDatabaseQueryBuilder& PluginDatabaseQueryBuilder::Table(const std::string& tableName)
{
    this->tableName = tableName;
    this->query = "SELECT * FROM " + tableName;
    this->whereClauses.clear();
    this->orderByClauses.clear();
    this->limitCount = -1;
    return *this;
}

PluginDatabaseQueryBuilder& PluginDatabaseQueryBuilder::Select(const std::vector<std::string>& columns) {
    if (columns.empty()) {
        throw std::invalid_argument("Select requires at least one column.");
    }

    this->query = "SELECT " + join(columns, ", ") + " FROM " + this->tableName;
    return *this;
}

PluginDatabaseQueryBuilder& PluginDatabaseQueryBuilder::Insert(const std::map<std::string, luabridge::LuaRef>& data) {
    this->query = "INSERT INTO " + this->tableName;
    
    std::vector<std::string> columns;
    std::vector<std::string> valueStrings;

    for (const auto& pair : data) {
        columns.push_back(pair.first);
        valueStrings.push_back(FormatValue(pair.second, nullptr));
    }

    this->query += " (" + join(columns, ", ") + ") VALUES (" + join(valueStrings, ", ") + ")";
    return *this;
}

PluginDatabaseQueryBuilder& PluginDatabaseQueryBuilder::Update(const std::map<std::string, luabridge::LuaRef>& data) {
    this->query = "UPDATE " + this->tableName + " SET ";
    
    this->updatePairs.clear();
    for (const auto& pair : data) {
        this->updatePairs.push_back({pair.first, pair.second});
    }

    std::vector<std::string> updateStrings;
    for (const auto& pair : this->updatePairs) {
        updateStrings.push_back(pair.first + " = " + FormatValue(pair.second, nullptr));
    }

    this->query += join(updateStrings, ", ");
    return *this;
}

PluginDatabaseQueryBuilder& PluginDatabaseQueryBuilder::Remove() {
    this->query = "DELETE FROM " + this->tableName;
    return *this;
}

PluginDatabaseQueryBuilder& PluginDatabaseQueryBuilder::Where(const std::string& column, const std::string& operator_, const luabridge::LuaRef& value) {
    this->whereClauses.push_back(column + " " + operator_ + " " + FormatValue(value, nullptr));
    return *this;
}

PluginDatabaseQueryBuilder& PluginDatabaseQueryBuilder::OrderBy(const std::string& column, const std::string& direction) {
    this->orderByClauses.push_back("ORDER BY " + column + " " + direction);
    return *this;
}

PluginDatabaseQueryBuilder& PluginDatabaseQueryBuilder::Limit(int count) {
    this->limitCount = count;
    return *this;
}

void PluginDatabaseQueryBuilder::Execute(luabridge::LuaRef callback, lua_State* L) {
    std::string finalQuery = this->ToString();
    this->db->QueryLua(finalQuery, callback, L);
}

std::string PluginDatabaseQueryBuilder::ToString()
{

    std::string finalQuery = this->query;

    if (!whereClauses.empty()) {
        finalQuery += " WHERE " + join(whereClauses, " AND ");
    }

    if (!orderByClauses.empty()) {
        finalQuery += " " + join(orderByClauses, " ");
    }

    if (limitCount >= 0) {
        finalQuery += " LIMIT " + std::to_string(limitCount);
    }

    return finalQuery.c_str();
}

std::string PluginDatabaseQueryBuilder::FormatValue(const luabridge::LuaRef& luaValue, lua_State* L) {
    if (luaValue.isNil()) {
        return "NULL";
    }
    else if (luaValue.isBool()) {
        return luaValue.cast<bool>() ? "1" : "0";
    }
    else if (luaValue.isNumber()) {
        return std::to_string(luaValue.cast<double>());
    }
    else if (luaValue.isString()) {
        return "'" + this->db->EscapeString(luaValue.cast<std::string>()) + "'";
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
