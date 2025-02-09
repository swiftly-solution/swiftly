#include "../../core.h"

LoadScriptingComponent(
    playermanager,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginPlayerManager>("PlayerManager")
            .addConstructor<std::string>()
            .addFunction("GetPlayerCount", &PluginPlayerManager::GetPlayerCount)
            .addFunction("GetPlayerCap", &PluginPlayerManager::GetPlayerCap)
            .addFunction("SendMsg", &PluginPlayerManager::SendMsg)
            .endClass()
            .addConstant("playermanager", new PluginPlayerManager(FetchPluginName(state)));
    }
)