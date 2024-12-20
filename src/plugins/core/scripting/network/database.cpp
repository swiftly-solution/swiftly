#include "../../scripting.h"
#include "../../../../entrypoint.h"
#include "../../../../player/playermanager/PlayerManager.h"

#include <vector>
#include <map>

PluginDatabase::PluginDatabase(std::string m_connection_name)
{
    this->connection_name = m_connection_name;
    this->db = g_dbManager->GetDatabase(this->connection_name);

    if (!this->db && this->connection_name != "default_connection") {
        PRINTF("Database connection \"%s\" doesn't exists inside the database configurations. Automatically falling back to \"default_connection\".\n", m_connection_name.c_str());
        this->db = g_dbManager->GetDatabase("default_connection");
    }

    if (!this->db)
        this->dbConnected = false;
    else
        this->dbConnected = this->db->Connect();
}


void PluginDatabase::QueryLua(std::string query, luabridge::LuaRef callback, lua_State* L)
{
    if (this->db->GetKind() != "mysql") {
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
    if (this->db->GetKind() != "mysql") {
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

bool PluginDatabase::IsConnected()
{
    if (!this->db || !this->db->IsConnected()) return false;
    return this->dbConnected;
}

std::string PluginDatabase::EscapeString(std::string str)
{
    if (!this->db || !this->db->IsConnected()) return str;
    return this->db->EscapeValue(str);
}

std::string PluginDatabase::GetVersion()
{
    if (!this->db || !this->db->IsConnected()) return "";
    return this->db->GetVersion();
}