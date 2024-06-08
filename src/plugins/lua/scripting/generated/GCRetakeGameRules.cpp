#include "../../../core/scripting/generated/classes/GCRetakeGameRules.h"
#include "../core.h"

void SetupLuaClassGCRetakeGameRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRetakeGameRules>("CRetakeGameRules")
        .addProperty("MatchSeed", &GCRetakeGameRules::GetMatchSeed, &GCRetakeGameRules::SetMatchSeed)
        .addProperty("BlockersPresent", &GCRetakeGameRules::GetBlockersPresent, &GCRetakeGameRules::SetBlockersPresent)
        .addProperty("RoundInProgress", &GCRetakeGameRules::GetRoundInProgress, &GCRetakeGameRules::SetRoundInProgress)
        .addProperty("FirstSecondHalfRound", &GCRetakeGameRules::GetFirstSecondHalfRound, &GCRetakeGameRules::SetFirstSecondHalfRound)
        .addProperty("BombSite", &GCRetakeGameRules::GetBombSite, &GCRetakeGameRules::SetBombSite)
        .endClass();
}