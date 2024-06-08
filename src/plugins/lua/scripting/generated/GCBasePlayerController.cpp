#include "../../../core/scripting/generated/classes/GCBasePlayerController.h"
#include "../core.h"

void SetupLuaClassGCBasePlayerController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerController>("CBasePlayerController")
        .addProperty("InButtonsWhichAreToggles", &GCBasePlayerController::GetInButtonsWhichAreToggles, &GCBasePlayerController::SetInButtonsWhichAreToggles)
        .addProperty("TickBase", &GCBasePlayerController::GetTickBase, &GCBasePlayerController::SetTickBase)
        .addProperty("Pawn", &GCBasePlayerController::GetPawn, &GCBasePlayerController::SetPawn)
        .addProperty("KnownTeamMismatch", &GCBasePlayerController::GetKnownTeamMismatch, &GCBasePlayerController::SetKnownTeamMismatch)
        .addProperty("SplitScreenSlot", &GCBasePlayerController::GetSplitScreenSlot, &GCBasePlayerController::SetSplitScreenSlot)
        .addProperty("SplitOwner", &GCBasePlayerController::GetSplitOwner, &GCBasePlayerController::SetSplitOwner)
        .addProperty("IsHLTV", &GCBasePlayerController::GetIsHLTV, &GCBasePlayerController::SetIsHLTV)
        .addProperty("Connected", &GCBasePlayerController::GetConnected, &GCBasePlayerController::SetConnected)
        .addProperty("PlayerName", &GCBasePlayerController::GetPlayerName, &GCBasePlayerController::SetPlayerName)
        .addProperty("NetworkIDString", &GCBasePlayerController::GetNetworkIDString, &GCBasePlayerController::SetNetworkIDString)
        .addProperty("LerpTime", &GCBasePlayerController::GetLerpTime, &GCBasePlayerController::SetLerpTime)
        .addProperty("LagCompensation", &GCBasePlayerController::GetLagCompensation, &GCBasePlayerController::SetLagCompensation)
        .addProperty("Predict", &GCBasePlayerController::GetPredict, &GCBasePlayerController::SetPredict)
        .addProperty("AutoKickDisabled", &GCBasePlayerController::GetAutoKickDisabled, &GCBasePlayerController::SetAutoKickDisabled)
        .addProperty("IsLowViolence", &GCBasePlayerController::GetIsLowViolence, &GCBasePlayerController::SetIsLowViolence)
        .addProperty("GamePaused", &GCBasePlayerController::GetGamePaused, &GCBasePlayerController::SetGamePaused)
        .addProperty("LastRealCommandNumberExecuted", &GCBasePlayerController::GetLastRealCommandNumberExecuted, &GCBasePlayerController::SetLastRealCommandNumberExecuted)
        .addProperty("LastLateCommandExecuted", &GCBasePlayerController::GetLastLateCommandExecuted, &GCBasePlayerController::SetLastLateCommandExecuted)
        .addProperty("IgnoreGlobalChat", &GCBasePlayerController::GetIgnoreGlobalChat, &GCBasePlayerController::SetIgnoreGlobalChat)
        .addProperty("LastPlayerTalkTime", &GCBasePlayerController::GetLastPlayerTalkTime, &GCBasePlayerController::SetLastPlayerTalkTime)
        .addProperty("LastEntitySteadyState", &GCBasePlayerController::GetLastEntitySteadyState, &GCBasePlayerController::SetLastEntitySteadyState)
        .addProperty("AvailableEntitySteadyState", &GCBasePlayerController::GetAvailableEntitySteadyState, &GCBasePlayerController::SetAvailableEntitySteadyState)
        .addProperty("HasAnySteadyStateEnts", &GCBasePlayerController::GetHasAnySteadyStateEnts, &GCBasePlayerController::SetHasAnySteadyStateEnts)
        .addProperty("SteamID", &GCBasePlayerController::GetSteamID, &GCBasePlayerController::SetSteamID)
        .addProperty("DesiredFOV", &GCBasePlayerController::GetDesiredFOV, &GCBasePlayerController::SetDesiredFOV)
        .endClass();
}