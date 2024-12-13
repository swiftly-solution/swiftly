#include "../../scripting.h"
#include "../../../../entrypoint.h"
#include "../../../../player/playermanager/PlayerManager.h"

#include <vector>
#include <map>

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
    if(this->db->GetKind() != "mysql") {
        PLUGIN_PRINT("Database - Query", "This function is supporting only MySQL databases.\n");
        return;
    }
    std::string uuid = get_uuid();

    luabridge::LuaRef databaseRequestsQueue = luabridge::getGlobal(L, "databaseRequestsQueue");
    if (databaseRequestsQueue.isTable())
        databaseRequestsQueue[uuid] = callback;

    DatabaseQueryQueue queue = {
        query,
        uuid,
    };
    this->db->AddQueryQueue(queue);
}

void PluginDatabase::QueryParamsLua(std::string query, std::map<luabridge::LuaRef, luabridge::LuaRef> params, luabridge::LuaRef callback, lua_State* L)
{
    if(this->db->GetKind() != "mysql") {
        PLUGIN_PRINT("Database - Query", "This function is supporting only MySQL databases.\n");
        return;
    }

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
    return PluginDatabaseQueryBuilder(this->db->ProvideQueryBuilder(), this->db);
}

PluginDatabaseQueryBuilder::PluginDatabaseQueryBuilder(IQueryBuilder* mqb, IDatabase* mdb)
{
    this->qb = mqb;
    this->db = mdb;
}

PluginDatabaseQueryBuilder::~PluginDatabaseQueryBuilder()
{
    if(this->qb != nullptr) delete this->qb;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Table(const std::string& tableName)
{
    if(this->qb != nullptr) this->qb->Table(tableName);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Create(const std::unordered_map<std::string, std::string>& columns)
{
    if(this->qb != nullptr) this->qb->Create(columns);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Alter(const std::map<std::string, std::string>& columns)
{
    if(this->qb != nullptr) this->qb->Alter(columns);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Drop()
{
    if(this->qb != nullptr) this->qb->Drop();
    return this;
}


PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Select(const std::vector<std::string>& columns) {
    if(this->qb != nullptr) this->qb->Select(columns);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Insert(const std::map<std::string, luabridge::LuaRef>& data, lua_State* L) {
    std::map<std::string, std::string> d;
    for(const auto& pair : data) {
        d.insert({ pair.first, FormatValue(pair.second, L) });
    }
    if(this->qb != nullptr) this->qb->Insert(d);

    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Update(const std::map<std::string, luabridge::LuaRef>& data, lua_State* L) {
    std::map<std::string, std::string> d;
    for(const auto& pair : data) {
        d.insert({ pair.first, FormatValue(pair.second, L) });
    }
    if(this->qb != nullptr) this->qb->Update(d);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Delete() {
    if(this->qb != nullptr) this->qb->Delete();
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Where(const std::string& column, const std::string& operator_, const luabridge::LuaRef& value, lua_State* L) {
    if(this->qb != nullptr) this->qb->Where(column, operator_, FormatValue(value, L));
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::OrWhere(const std::string& column, const std::string& operator_, const luabridge::LuaRef& value, lua_State* L) {
    if(this->qb != nullptr) this->qb->OrWhere(column, operator_, FormatValue(value, L));
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Join(const std::string& table, const std::string& onCondition, const std::string& joinType) {
    if(this->qb != nullptr) this->qb->Join(table, onCondition, joinType);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::OrderBy(const std::vector<std::pair<std::string, std::string>>& columns) {
    if(this->qb != nullptr) this->qb->OrderBy(columns);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Limit(int count) {
    if(this->qb != nullptr) this->qb->Limit(count);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::GroupBy(const std::vector<std::string>& columns) {
    if(this->qb != nullptr) this->qb->GroupBy(columns);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::OnDuplicate(const std::map<std::string, luabridge::LuaRef>& data, lua_State* L) {
    std::map<std::string, std::string> d;
    for(const auto& pair : data) {
        d.insert({ pair.first, FormatValue(pair.second, L) });
    }
    if(this->qb != nullptr) this->qb->OnDuplicate(d);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Having(const std::string& condition) {
    if(this->qb != nullptr) this->qb->Having(condition);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Distinct() {
    if(this->qb != nullptr) this->qb->Distinct();
    return this;
}


PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Offset(int count) {
    if(this->qb != nullptr) this->qb->Offset(count);
    return this;
}

PluginDatabaseQueryBuilder* PluginDatabaseQueryBuilder::Union(const std::string& query, bool all) {
    if(this->qb != nullptr) this->qb->Union(query, all);
    return this;
}

void PluginDatabaseQueryBuilder::Execute(luabridge::LuaRef callback, lua_State* L) {
    std::string uuid = get_uuid();

    luabridge::LuaRef databaseRequestsQueue = luabridge::getGlobal(L, "databaseRequestsQueue");
    if (databaseRequestsQueue.isTable())
        databaseRequestsQueue[uuid] = luabridge::LuaRef(callback);

    DatabaseQueryQueue queue = {
        this->qb->PrepareQuery(),
        uuid,
    };
    this->db->AddQueryQueue(queue);
    delete this->qb;
    this->qb = nullptr;
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
        return "\'" + this->db->EscapeValue(luaValue.cast<std::string>()) + "\'";
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
