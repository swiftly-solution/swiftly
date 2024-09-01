#include "../scripting.h"
#include "../../../entrypoint.h"
#include "../../../player/PlayerManager.h"

#include <deque>
#include <thread>

#include <vector>
#include <map>

std::string FetchPluginName(lua_State* state);
#define FetchPluginByState(state) g_pluginManager->FetchPlugin(FetchPluginName(state))

extern std::string currentMap;
struct DatabaseQueryQueue
{
    std::string query;
    void* callback;
    Database* db;
    Plugin* plugin;
};

std::deque<DatabaseQueryQueue> queryQueue;
bool dbThreadStarted = false;

void DatabaseLuaCallback(std::vector<std::any> values)
{
    std::vector<std::map<const char*, std::any>> queryResult = std::any_cast<std::vector<std::map<const char*, std::any>>>(values[0]);
    lua_State* state = std::any_cast<lua_State*>(values[1]);
    luabridge::LuaRef* ref = std::any_cast<luabridge::LuaRef*>(values[2]);
    std::string error = std::any_cast<std::string>(values[3]);

    std::vector<std::map<std::string, luabridge::LuaRef>> tbl;

    for (uint32_t i = 0; i < queryResult.size(); i++)
    {
        std::map<std::string, luabridge::LuaRef> rowTbl;

        for (auto it = queryResult[i].begin(); it != queryResult[i].end(); ++it)
            rowTbl.insert({ it->first, LuaSerializeData(it->second, state) });

        tbl.push_back(rowTbl);
    }

    try
    {
        if (ref != nullptr) {
            if (ref->isFunction())
                ref->operator()(error.size() == 0 ? luabridge::LuaRef(state) : error, tbl);

            delete ref;
        }
    }
    catch (luabridge::LuaException& e)
    {
        PRINTF("An error has occured: %s\n", e.what());
    }
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
                delete queue.callback;
                queryQueue.pop_front();
                continue;
            }

            RegisterCallStack* callStack = new RegisterCallStack(queue.plugin->GetName(), string_format("database::Query(database=%p, query=\"%s\")", (void*)queue.db, queue.query.c_str()));

            auto queryResult = queue.db->Query(queue.query.c_str());
            if (queue.plugin->GetKind() == PluginKind_t::Lua)
            {
                lua_State* state = ((LuaPlugin*)queue.plugin)->GetState();

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

                luabridge::LuaRef* ref = (luabridge::LuaRef*)queue.callback;
                if (currentMap != "None") g_Plugin.NextFrame(DatabaseLuaCallback, { queryResult, state, ref, error });
                else DatabaseLuaCallback({ queryResult, state, ref, error });
            }

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

    DatabaseQueryQueue queue = {
        query,
        new luabridge::LuaRef(callback),
        this->db,
        FetchPluginByState(L),
    };
    queryQueue.push_back(queue);

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
        std::string key = it->first.tostring();
        std::string value = EscapeString(it->second.tostring());

        if (has_ats)
            query = replace(query, "@" + key, value);

        if (has_brace)
            query = replace(query, "{" + key + "}", value);

        if (has_bracket)
            query = replace(query, "[" + key + "]", value);
    }

    return QueryLua(query, callback, L);
}