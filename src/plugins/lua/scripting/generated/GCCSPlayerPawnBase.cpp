#include "../../../core/scripting/generated/classes/GCCSPlayerPawnBase.h"
#include "../core.h"

void SetupLuaClassGCCSPlayerPawnBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerPawnBase>("CCSPlayerPawnBase")
        .addProperty("CTouchExpansionComponent", &GCCSPlayerPawnBase::GetCTouchExpansionComponent, &GCCSPlayerPawnBase::SetCTouchExpansionComponent)
        .addProperty("PingServices", &GCCSPlayerPawnBase::GetPingServices, &GCCSPlayerPawnBase::SetPingServices)
        .addProperty("ViewModelServices", &GCCSPlayerPawnBase::GetViewModelServices, &GCCSPlayerPawnBase::SetViewModelServices)
        .addProperty("PlayerState", &GCCSPlayerPawnBase::GetPlayerState, &GCCSPlayerPawnBase::SetPlayerState)
        .addProperty("Respawning", &GCCSPlayerPawnBase::GetRespawning, &GCCSPlayerPawnBase::SetRespawning)
        .addProperty("GunGameImmunity", &GCCSPlayerPawnBase::GetGunGameImmunity, &GCCSPlayerPawnBase::SetGunGameImmunity)
        .addProperty("MolotovDamageTime", &GCCSPlayerPawnBase::GetMolotovDamageTime, &GCCSPlayerPawnBase::SetMolotovDamageTime)
        .addProperty("HasMovedSinceSpawn", &GCCSPlayerPawnBase::GetHasMovedSinceSpawn, &GCCSPlayerPawnBase::SetHasMovedSinceSpawn)
        .addProperty("NumSpawns", &GCCSPlayerPawnBase::GetNumSpawns, &GCCSPlayerPawnBase::SetNumSpawns)
        .addProperty("IdleTimeSinceLastAction", &GCCSPlayerPawnBase::GetIdleTimeSinceLastAction, &GCCSPlayerPawnBase::SetIdleTimeSinceLastAction)
        .addProperty("NextRadarUpdateTime", &GCCSPlayerPawnBase::GetNextRadarUpdateTime, &GCCSPlayerPawnBase::SetNextRadarUpdateTime)
        .addProperty("FlashDuration", &GCCSPlayerPawnBase::GetFlashDuration, &GCCSPlayerPawnBase::SetFlashDuration)
        .addProperty("FlashMaxAlpha", &GCCSPlayerPawnBase::GetFlashMaxAlpha, &GCCSPlayerPawnBase::SetFlashMaxAlpha)
        .addProperty("ProgressBarStartTime", &GCCSPlayerPawnBase::GetProgressBarStartTime, &GCCSPlayerPawnBase::SetProgressBarStartTime)
        .addProperty("ProgressBarDuration", &GCCSPlayerPawnBase::GetProgressBarDuration, &GCCSPlayerPawnBase::SetProgressBarDuration)
        .addProperty("EyeAngles", &GCCSPlayerPawnBase::GetEyeAngles, &GCCSPlayerPawnBase::SetEyeAngles)
        .addProperty("NumEnemiesAtRoundStart", &GCCSPlayerPawnBase::GetNumEnemiesAtRoundStart, &GCCSPlayerPawnBase::SetNumEnemiesAtRoundStart)
        .addProperty("WasNotKilledNaturally", &GCCSPlayerPawnBase::GetWasNotKilledNaturally, &GCCSPlayerPawnBase::SetWasNotKilledNaturally)
        .addProperty("CommittingSuicideOnTeamChange", &GCCSPlayerPawnBase::GetCommittingSuicideOnTeamChange, &GCCSPlayerPawnBase::SetCommittingSuicideOnTeamChange)
        .addProperty("OriginalController", &GCCSPlayerPawnBase::GetOriginalController, &GCCSPlayerPawnBase::SetOriginalController)
        .endClass();
}