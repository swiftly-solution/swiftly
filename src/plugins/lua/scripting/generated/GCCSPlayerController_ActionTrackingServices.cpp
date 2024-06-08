#include "../../../core/scripting/generated/classes/GCCSPlayerController_ActionTrackingServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayerController_ActionTrackingServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerController_ActionTrackingServices>("CCSPlayerController_ActionTrackingServices")
        .addProperty("PerRoundStats", &GCCSPlayerController_ActionTrackingServices::GetPerRoundStats, &GCCSPlayerController_ActionTrackingServices::SetPerRoundStats)
        .addProperty("MatchStats", &GCCSPlayerController_ActionTrackingServices::GetMatchStats, &GCCSPlayerController_ActionTrackingServices::SetMatchStats)
        .addProperty("NumRoundKills", &GCCSPlayerController_ActionTrackingServices::GetNumRoundKills, &GCCSPlayerController_ActionTrackingServices::SetNumRoundKills)
        .addProperty("NumRoundKillsHeadshots", &GCCSPlayerController_ActionTrackingServices::GetNumRoundKillsHeadshots, &GCCSPlayerController_ActionTrackingServices::SetNumRoundKillsHeadshots)
        .addProperty("TotalRoundDamageDealt", &GCCSPlayerController_ActionTrackingServices::GetTotalRoundDamageDealt, &GCCSPlayerController_ActionTrackingServices::SetTotalRoundDamageDealt)
        .endClass();
}