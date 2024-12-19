#include "../core.h"

luabridge::LuaRef PluginDatabase::QueryBuilderLua(lua_State* L)
{
    if(!this->db || !this->db->IsConnected()) return luabridge::LuaRef(L);
    
    luabridge::LuaRef global = luabridge::getGlobal(L, db->ProvideQueryBuilderTable());
    return global(this);
}

void PluginDatabase::ExecuteQBLua(std::string query, luabridge::LuaRef cb, lua_State* L)
{
    std::string uuid = get_uuid();

    luabridge::LuaRef databaseRequestsQueue = luabridge::getGlobal(L, "databaseRequestsQueue");
    if (databaseRequestsQueue.isTable())
        databaseRequestsQueue[uuid] = luabridge::LuaRef(cb);

    DatabaseQueryQueue queue = {
        query,
        uuid,
    };
    this->db->AddQueryQueue(queue);
}

LoadLuaScriptingComponent(
    database,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginDatabase>("Database")
            .addConstructor<void (*)(std::string)>()
            .addFunction("IsConnected", &PluginDatabase::IsConnected)
            .addFunction("EscapeString", &PluginDatabase::EscapeString)
            .addFunction("QueryBuilder", &PluginDatabase::QueryBuilderLua)
            .addFunction("GetVersion", &PluginDatabase::GetVersion)
            .addFunction("ExecuteQB", &PluginDatabase::ExecuteQBLua)
            .endClass();

        luaL_dostring(state, "db = Database(\"default_connection\")");
    }
)
