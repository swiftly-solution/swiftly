#include "../../../core/scripting/generated/classes/GCPlantedC4.h"
#include "../core.h"

void SetupLuaClassGCPlantedC4(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlantedC4>("CPlantedC4")
        .addProperty("BombTicking", &GCPlantedC4::GetBombTicking, &GCPlantedC4::SetBombTicking)
        .addProperty("BombSite", &GCPlantedC4::GetBombSite, &GCPlantedC4::SetBombSite)
        .addProperty("SourceSoundscapeHash", &GCPlantedC4::GetSourceSoundscapeHash, &GCPlantedC4::SetSourceSoundscapeHash)
        .addProperty("OnBombDefused", &GCPlantedC4::GetOnBombDefused, &GCPlantedC4::SetOnBombDefused)
        .addProperty("OnBombBeginDefuse", &GCPlantedC4::GetOnBombBeginDefuse, &GCPlantedC4::SetOnBombBeginDefuse)
        .addProperty("OnBombDefuseAborted", &GCPlantedC4::GetOnBombDefuseAborted, &GCPlantedC4::SetOnBombDefuseAborted)
        .addProperty("CannotBeDefused", &GCPlantedC4::GetCannotBeDefused, &GCPlantedC4::SetCannotBeDefused)
        .addProperty("EntitySpottedState", &GCPlantedC4::GetEntitySpottedState, &GCPlantedC4::SetEntitySpottedState)
        .addProperty("SpotRules", &GCPlantedC4::GetSpotRules, &GCPlantedC4::SetSpotRules)
        .addProperty("TrainingPlacedByPlayer", &GCPlantedC4::GetTrainingPlacedByPlayer, &GCPlantedC4::SetTrainingPlacedByPlayer)
        .addProperty("HasExploded", &GCPlantedC4::GetHasExploded, &GCPlantedC4::SetHasExploded)
        .addProperty("TimerLength", &GCPlantedC4::GetTimerLength, &GCPlantedC4::SetTimerLength)
        .addProperty("BeingDefused", &GCPlantedC4::GetBeingDefused, &GCPlantedC4::SetBeingDefused)
        .addProperty("DefuseLength", &GCPlantedC4::GetDefuseLength, &GCPlantedC4::SetDefuseLength)
        .addProperty("BombDefused", &GCPlantedC4::GetBombDefused, &GCPlantedC4::SetBombDefused)
        .addProperty("BombDefuser", &GCPlantedC4::GetBombDefuser, &GCPlantedC4::SetBombDefuser)
        .addProperty("ControlPanel", &GCPlantedC4::GetControlPanel, &GCPlantedC4::SetControlPanel)
        .addProperty("ProgressBarTime", &GCPlantedC4::GetProgressBarTime, &GCPlantedC4::SetProgressBarTime)
        .addProperty("VoiceAlertFired", &GCPlantedC4::GetVoiceAlertFired, &GCPlantedC4::SetVoiceAlertFired)
        .addProperty("VoiceAlertPlayed", &GCPlantedC4::GetVoiceAlertPlayed, &GCPlantedC4::SetVoiceAlertPlayed)
        .addProperty("CatchUpToPlayerEye", &GCPlantedC4::GetCatchUpToPlayerEye, &GCPlantedC4::SetCatchUpToPlayerEye)
        .endClass();
}