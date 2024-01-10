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

class LuaPlayerArgsClass
{
public:
    int playerSlot;

    LuaPlayerArgsClass(int m_playerSlot) : playerSlot(m_playerSlot) {}
};

void SetupLuaPlayer(luacpp::LuaState *state, Plugin *plugin)
{
    auto playerClass = state->CreateClass<LuaPlayerClass>("Player").DefConstructor<int, bool>();

    auto healthClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor();
    auto armorClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor();
    auto clantagClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor();
    auto teamClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor();

    playerClass.DefMember("GetSteamID", [](LuaPlayerClass *base) -> uint64_t
                          { return scripting_Player_GetSteamID(base->playerSlot); })
        .DefMember("GetName", [](LuaPlayerClass *base) -> const char *
                   { return scripting_Player_GetName(base->playerSlot); })
        .DefMember("GetHealth", [](LuaPlayerClass *base) -> int
                   { return scripting_Player_GetHealth(base->playerSlot); })
        .DefMember("IsFirstSpawn", [](LuaPlayerClass *base) -> bool
                   { return (base->firstSpawn == false); })
        .DefMember("SetFirstSpawn", [](LuaPlayerClass *base, bool firstSpawn) -> void
                   { base->firstSpawn = firstSpawn; })
        .DefMember("GetConnectedTime", [](LuaPlayerClass *base) -> uint32_t
                   { return scripting_Player_GetConnectedTime(base->playerSlot); })
        .DefMember("SendMsg", [](LuaPlayerClass *base, int dest, const char *message) -> void
                   { return scripting_Player_SendMessage(base->playerSlot, dest, message); })
        .DefMember("GetConvarValue", [](LuaPlayerClass *base, const char *name) -> const char *
                   { return scripting_Player_GetConvar(base->playerSlot, name); })
        .DefMember("IsAuthenticated", [](LuaPlayerClass *base) -> bool
                   { return scripting_Player_IsAuthenticated(base->playerSlot); })
        .DefMember("Kill", [](LuaPlayerClass *base) -> void
                   { scripting_Player_Kill(base->playerSlot); })
        .DefMember("Drop", [](LuaPlayerClass *base, int reason) -> void
                   { scripting_Player_Drop(base->playerSlot, (ENetworkDisconnectionReason)reason); })
        .DefMember("IsFakeClient", [](LuaPlayerClass *base) -> bool
                   { return base->fakeClient; })
        .DefMember("GetSlot", [](LuaPlayerClass *base) -> int
                   { return base->playerSlot; })
        .DefMember("health", [healthClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return healthClass.CreateInstance(base->playerSlot); })
        .DefMember("armor", [armorClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return armorClass.CreateInstance(base->playerSlot); })
        .DefMember("clantag", [clantagClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return clantagClass.CreateInstance(base->playerSlot); })
        .DefMember("team", [teamClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return teamClass.CreateInstance(base->playerSlot); });

    healthClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int
                          { return scripting_Player_GetHealth(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int health) -> void
                   { scripting_Player_SetHealth(base->playerSlot, health); })
        .DefMember("Take", [](LuaPlayerArgsClass *base, int health) -> void
                   { scripting_Player_TakeHealth(base->playerSlot, health); });

    armorClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int
                         { return scripting_Player_GetArmor(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int armor) -> void
                   { scripting_Player_SetArmor(base->playerSlot, armor); })
        .DefMember("Take", [](LuaPlayerArgsClass *base, int armor) -> void
                   { scripting_Player_TakeArmor(base->playerSlot, armor); });

    clantagClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> const char *
                           { return scripting_Player_GetClanTag(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, const char *tag) -> void
                   { scripting_Player_SetClanTag(base->playerSlot, tag); });

    teamClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint8
                        { return scripting_Player_GetTeam(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int team) -> void
                   { scripting_Player_SetTeam(base->playerSlot, team); });

    PRINT("Scripting - Lua", "Player loaded.\n");
}