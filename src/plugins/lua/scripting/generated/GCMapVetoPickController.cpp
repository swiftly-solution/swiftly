#include "../../../core/scripting/generated/classes/GCMapVetoPickController.h"
#include "../core.h"

void SetupLuaClassGCMapVetoPickController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMapVetoPickController>("CMapVetoPickController")
        .addProperty("PlayedIntroVcd", &GCMapVetoPickController::GetPlayedIntroVcd, &GCMapVetoPickController::SetPlayedIntroVcd)
        .addProperty("NeedToPlayFiveSecondsRemaining", &GCMapVetoPickController::GetNeedToPlayFiveSecondsRemaining, &GCMapVetoPickController::SetNeedToPlayFiveSecondsRemaining)
        .addProperty("DblPreMatchDraftSequenceTime", &GCMapVetoPickController::GetDblPreMatchDraftSequenceTime, &GCMapVetoPickController::SetDblPreMatchDraftSequenceTime)
        .addProperty("PreMatchDraftStateChanged", &GCMapVetoPickController::GetPreMatchDraftStateChanged, &GCMapVetoPickController::SetPreMatchDraftStateChanged)
        .addProperty("DraftType", &GCMapVetoPickController::GetDraftType, &GCMapVetoPickController::SetDraftType)
        .addProperty("TeamWinningCoinToss", &GCMapVetoPickController::GetTeamWinningCoinToss, &GCMapVetoPickController::SetTeamWinningCoinToss)
        .addProperty("TeamWithFirstChoice", &GCMapVetoPickController::GetTeamWithFirstChoice, &GCMapVetoPickController::SetTeamWithFirstChoice)
        .addProperty("VoteMapIdsList", &GCMapVetoPickController::GetVoteMapIdsList, &GCMapVetoPickController::SetVoteMapIdsList)
        .addProperty("AccountIDs", &GCMapVetoPickController::GetAccountIDs, &GCMapVetoPickController::SetAccountIDs)
        .addProperty("MapId0", &GCMapVetoPickController::GetMapId0, &GCMapVetoPickController::SetMapId0)
        .addProperty("MapId1", &GCMapVetoPickController::GetMapId1, &GCMapVetoPickController::SetMapId1)
        .addProperty("MapId2", &GCMapVetoPickController::GetMapId2, &GCMapVetoPickController::SetMapId2)
        .addProperty("MapId3", &GCMapVetoPickController::GetMapId3, &GCMapVetoPickController::SetMapId3)
        .addProperty("MapId4", &GCMapVetoPickController::GetMapId4, &GCMapVetoPickController::SetMapId4)
        .addProperty("MapId5", &GCMapVetoPickController::GetMapId5, &GCMapVetoPickController::SetMapId5)
        .addProperty("StartingSide0", &GCMapVetoPickController::GetStartingSide0, &GCMapVetoPickController::SetStartingSide0)
        .addProperty("CurrentPhase", &GCMapVetoPickController::GetCurrentPhase, &GCMapVetoPickController::SetCurrentPhase)
        .addProperty("PhaseStartTick", &GCMapVetoPickController::GetPhaseStartTick, &GCMapVetoPickController::SetPhaseStartTick)
        .addProperty("PhaseDurationTicks", &GCMapVetoPickController::GetPhaseDurationTicks, &GCMapVetoPickController::SetPhaseDurationTicks)
        .endClass();
}