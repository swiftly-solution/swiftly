#include "core.h"

void SetupLuaPlayerManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<PluginPlayerManager>("PlayerManager")
        .addConstructor<void (*)(std::string)>()
        .addFunction("GetPlayerCount", &PluginPlayerManager::GetPlayerCount)
        .addFunction("GetPlayerCap", &PluginPlayerManager::GetPlayerCap)
        .addFunction("SendMsg", &PluginPlayerManager::SendMsg)
        .endClass();

    luaL_dostring(state, "playermanager = PlayerManager(GetCurrentPluginName())");
}