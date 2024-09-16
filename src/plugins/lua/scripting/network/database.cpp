#include "../core.h"

LoadLuaScriptingComponent(
    database,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginDatabase>("Database")
            .addConstructor<void (*)(std::string)>()
            .addFunction("IsConnected", &PluginDatabase::IsConnected)
            .addFunction("EscapeString", &PluginDatabase::EscapeString)
            .addFunction("Query", &PluginDatabase::QueryLua)
            .addFunction("QueryParams", &PluginDatabase::QueryParamsLua)
            .endClass();

        luaL_dostring(state, "db = Database(\"default_connection\")");
    }
)
