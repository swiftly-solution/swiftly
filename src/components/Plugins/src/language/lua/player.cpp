#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

class LuaPlayerClass
{
public:
    int playerSlot;
    bool fakeClient;
    bool firstSpawn = false;

    LuaPlayerClass(int m_playerSlot, bool m_fakeClient) : playerSlot(m_playerSlot), fakeClient(m_fakeClient) {}
};

void SetupLuaPlayer(luacpp::LuaState *state, Plugin *plugin)
{
    auto playerClass = state->CreateClass<LuaPlayerClass>("Player").DefConstructor<int, bool>();

    playerClass.DefMember("GetSteamID", [](LuaPlayerClass *base) -> uint64_t
                          { return scripting_Player_GetSteamID(base->playerSlot); })
        .DefMember("GetName", [](LuaPlayerClass *base) -> const char *
                   { return scripting_Player_GetName(base->playerSlot); })
        .DefMember("GetHealth", [](LuaPlayerClass *base) -> int
                   { return scripting_Player_GetHealth(base->playerSlot); })
        .DefMember("IsFirstSpawn", [](LuaPlayerClass *base) -> bool
                   { return (base->firstSpawn == false); })
        .DefMember("SetFirstSpawn", [](LuaPlayerClass *base, bool firstSpawn) -> void
                   { base->firstSpawn = firstSpawn; });

    PRINT("Scripting - Lua", "Player loaded.\n");
}