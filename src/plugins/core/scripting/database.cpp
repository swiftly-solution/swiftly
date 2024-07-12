#include "../scripting.h"

#include <deque>
#include <thread>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#define FetchPluginName(state) luabridge::getGlobal(state, "plugin_name").tostring()
#define FetchPluginByState(state) g_pluginManager->FetchPlugin(FetchPluginName(state))

struct DatabaseQueryQueue
{
    std::string query;
    void *callback;
    Database *db;
    Plugin *plugin;
};

std::deque<DatabaseQueryQueue> queryQueue;
bool dbThreadStarted = false;

void DatabaseQueryThread()
{
    while (true)
    {
        while (!queryQueue.empty())
        {
            DatabaseQueryQueue queue = queryQueue.front();

            auto queryResult = queue.db->Query(queue.query.c_str());
            if (queue.plugin->GetKind() == PluginKind_t::Lua)
            {
                lua_State *state = ((LuaPlugin *)queue.plugin)->GetState();
                luabridge::LuaRef tbl = luabridge::LuaRef::newTable(state);
                for (uint32_t i = 0; i < queryResult.size(); i++)
                {
                    luabridge::LuaRef rowTbl = luabridge::LuaRef::newTable(state);

                    for (std::map<const char *, std::any>::iterator it = queryResult[i].begin(); it != queryResult[i].end(); ++it)
                    {
                        const char *key = it->first;
                        std::any value = it->second;

                        if (value.type() == typeid(const char *))
                            rowTbl[key] = std::string(std::any_cast<const char *>(value));
                        else if (value.type() == typeid(std::string))
                            rowTbl[key] = std::any_cast<std::string>(value);
                        else if (value.type() == typeid(uint64))
                            rowTbl[key] = std::any_cast<uint64>(value);
                        else if (value.type() == typeid(uint32))
                            rowTbl[key] = std::any_cast<uint32>(value);
                        else if (value.type() == typeid(uint16))
                            rowTbl[key] = std::any_cast<uint16>(value);
                        else if (value.type() == typeid(uint8))
                            rowTbl[key] = std::any_cast<uint8>(value);
                        else if (value.type() == typeid(int64))
                            rowTbl[key] = std::any_cast<int64>(value);
                        else if (value.type() == typeid(int32))
                            rowTbl[key] = std::any_cast<int32>(value);
                        else if (value.type() == typeid(int16))
                            rowTbl[key] = std::any_cast<int16>(value);
                        else if (value.type() == typeid(int8))
                            rowTbl[key] = std::any_cast<int8>(value);
                        else if (value.type() == typeid(bool))
                            rowTbl[key] = std::any_cast<bool>(value);
                        else if (value.type() == typeid(float))
                            rowTbl[key] = std::any_cast<float>(value);
                        else if (value.type() == typeid(double))
                            rowTbl[key] = std::any_cast<double>(value);
                    }

                    tbl.append(rowTbl);
                }

                luabridge::LuaRef ref = *(luabridge::LuaRef *)queue.callback;
                try
                {
                    std::string error = queue.db->GetError();
                    if (ref.isFunction())
                        ref(error.size() == 0 ? luabridge::LuaRef(state) : error, tbl);
                }
                catch (luabridge::LuaException &e)
                {
                    PRINTF("An error has occured: %s\n", e.what());
                }
            }

            delete ((luabridge::LuaRef *)queue.callback);
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

void PluginDatabase::QueryLua(std::string query, luabridge::LuaRef callback, lua_State *L)
{
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