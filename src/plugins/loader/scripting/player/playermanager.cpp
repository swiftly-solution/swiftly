#include "../../core.h"

LoadScriptingComponent(
    playermanager,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginPlayerManager>("PlayerManager", state)
            .addConstructor<std::string>()
            .addFunction("GetPlayerCount", &PluginPlayerManager::GetPlayerCount)
            .addFunction("GetPlayerCap", &PluginPlayerManager::GetPlayerCap)
            .addFunction("SendMsg", &PluginPlayerManager::SendMsg)
        .endClass();

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("playermanager = PlayerManager(GetCurrentPluginName())");  
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.playermanager = PlayerManager(GetCurrentPluginName())");
    }
)