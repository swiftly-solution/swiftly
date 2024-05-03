#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

class LuaServerClass
{
public:
    LuaServerClass() {}
};

void SetupLuaServer(luacpp::LuaState *state, Plugin *plugin)
{
    auto serverClass = state->CreateClass<LuaServerClass>("Server").DefConstructor();

    serverClass.DefMember("GetMap", [](LuaServerClass *base) -> const char *
                          { return scripting_Server_GetMapName(); })
        .DefMember("GetMaxPlayers", [](LuaServerClass *base) -> uint16
                   { return scripting_Server_GetMaxPlayers(); })
        .DefMember("IsMapValid", [](LuaServerClass *base, const char *map) -> bool
                   { return scripting_Server_IsMapValid(map); })
        .DefMember("ExecuteCommand", [](LuaServerClass *base, const char *command) -> void
                   { scripting_Server_ExecuteCommand(command); })
        .DefMember("ChangeLevel", [](LuaServerClass *base, const char *map) -> void
                   {
            if(!scripting_Server_IsMapValid(map)) return;
            scripting_Server_ExecuteCommand(string_format("map %s", map).c_str()); })
        .DefMember("IsPistolRound", [](LuaServerClass *base) -> bool
                   { return scripting_Server_IsPistolRound(); })
        .DefMember("IsWarmup", [](LuaServerClass *base) -> bool
                   { return scripting_Server_IsWarmup(); })
        .DefMember("IsFreezeTime", [](LuaServerClass *base) -> bool
                   { return scripting_Server_IsFreezeTime(); })
        .DefMember("GetTotalRounds", [](LuaServerClass *base) -> int32_t
                   { return scripting_server_GetTotalRounds(); })
        .DefMember("SetQueuedMatchmaking", [](LuaServerClass *base, bool status) -> void
                   { scripting_Server_SetQueuedMatchmaking(status); })
        .DefMember("SetQueuedMatchmakingMode", [](LuaServerClass *base, int mode) -> void
                   { scripting_Server_SetQueuedMatchmakingMode(mode); })
        .DefMember("GetQueuedMatchmaking", [](LuaServerClass *base) -> bool
                   { return scripting_Server_GetQueuedMatchmaking(); })
        .DefMember("GetCurrentTime", [](LuaServerClass *base) -> float
                   { return scripting_Server_GetCurrentTime(); })
        .DefMember("GetTickCount", [](LuaServerClass *base) -> int32_t
                   { return scripting_Server_GetTickCount(); });

    state->DoString("server = Server()");
}