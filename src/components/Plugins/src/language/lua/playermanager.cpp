#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

class LuaPlayerManagerClass
{
public:
    LuaPlayerManagerClass() {}
};

void SetupLuaPlayerManager(luacpp::LuaState *state, Plugin *plugin)
{
    auto playerManagerClass = state->CreateClass<LuaPlayerManagerClass>("PlayerManager").DefConstructor();

    playerManagerClass.DefMember("GetPlayerCount", [state](LuaPlayerManagerClass *base) -> uint16
                                 { return g_playerManager->GetPlayers(); })
        .DefMember("GetPlayerCap", [](LuaPlayerManagerClass *base) -> uint16
                   { return g_playerManager->GetPlayerCap(); })
        .DefMember("SendMsg", [](LuaPlayerManagerClass *base, int dest, const char *message) -> void
                   { scripting_Players_SendMessage(dest, message); });

    state->DoString("playermanager = PlayerManager()");

    PRINT("Scripting - Lua", "Player Manager loaded.\n");
}