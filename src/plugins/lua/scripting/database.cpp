#include "core.h"

void SetupLuaDatabase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<PluginDatabase>("Database")
        .addConstructor<void (*)(std::string)>()
        .addFunction("IsConnected", &PluginDatabase::IsConnected)
        .addFunction("EscapeString", &PluginDatabase::EscapeString)
        .addFunction("Query", &PluginDatabase::QueryLua)
        .endClass();

    luabridge::setGlobal(state, luabridge::LuaRef(state), "db");
}