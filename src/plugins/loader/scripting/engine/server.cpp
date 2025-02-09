#include "../../core.h"

LoadScriptingComponent(
    server,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginServer>("Server")
            .addFunction("GetMap", &PluginServer::GetMap)
            .addFunction("IsMapValid", &PluginServer::IsMapValid)
            .addFunction("ChangeMap", &PluginServer::ChangeMap)
            .addFunction("GetMaxPlayers", &PluginServer::GetMaxPlayers)
            .addFunction("TerminateRound", &PluginServer::TerminateRound)
            .addFunction("Execute", &PluginServer::Execute)
            .addFunction("GetCurrentTime", &PluginServer::GetCurrentTime)
            .addFunction("GetTickCount", &PluginServer::GetTickCount)
            .addFunction("GetIP", &PluginServer::GetIP)
            .endClass()
            .addConstant("server", new PluginServer(FetchPluginName(state)));
    }
)