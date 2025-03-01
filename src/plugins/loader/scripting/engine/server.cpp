#include "../../core.h"

LoadScriptingComponent(
    server,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginServer>("Server", state)
            .addConstructor<std::string>()
            .addFunction("GetMap", &PluginServer::GetMap)
            .addFunction("IsMapValid", &PluginServer::IsMapValid)
            .addFunction("ChangeMap", &PluginServer::ChangeMap)
            .addFunction("GetMaxPlayers", &PluginServer::GetMaxPlayers)
            .addFunction("TerminateRound", &PluginServer::TerminateRound)
            .addFunction("Execute", &PluginServer::Execute)
            .addFunction("GetCurrentTime", &PluginServer::GetCurrentTime)
            .addFunction("GetTickCount", &PluginServer::GetTickCount)
            .addFunction("GetIP", &PluginServer::GetIP)
        .endClass();

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("server = Server(GetCurrentPluginName())");
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.server = Server(GetCurrentPluginName())");
    }
)