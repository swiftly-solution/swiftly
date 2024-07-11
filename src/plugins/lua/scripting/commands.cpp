#include "core.h"

void SetupLuaCommands(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<PluginCommands>("Commands")
        .addConstructor<void (*)(std::string)>()
        .addFunction("Register", &PluginCommands::RegisterCommandLua)
        .addFunction("Unregister", &PluginCommands::UnregisterCommand)
        .addFunction("RegisterAlias", &PluginCommands::RegisterAlias)
        .addFunction("UnregisterAlias", &PluginCommands::UnregisterAlias)
        .endClass();

    luaL_dostring(state, "commands = Commands(GetCurrentPluginName())");
}