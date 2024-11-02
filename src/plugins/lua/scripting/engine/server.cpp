#include "../core.h"

LoadLuaScriptingComponent(
    server,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginServer>("Server")
            .addConstructor<void (*)(std::string)>()
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

        luaL_dostring(state, "server = Server(GetCurrentPluginName())");
    }
)