class GCCSPlayerController;

#ifndef _gcccsplayercontroller_h
#define _gcccsplayercontroller_h

#include "../../../scripting.h"

#include "../types/GEKillTypes_t.h"
#include "GCCSPlayerController_InGameMoneyServices.h"
#include "GCCSPlayerController.h"
#include "GCCSPlayerController_InventoryServices.h"
#include "GCCSPlayerController_ActionTrackingServices.h"
#include "GCCSPlayerController_DamageServices.h"
#include "GQuestProgress.h"
#include "GCCSPlayerPawn.h"
#include "GCCSObserverPawn.h"
#include "GCEntityInstance.h"
#include "GIntervalTimer.h"

class GCCSPlayerController
{
private:
    void *m_ptr;

public:
    GCCSPlayerController() {}
    GCCSPlayerController(void *ptr) : m_ptr(ptr) {}

    GCCSPlayerController_InGameMoneyServices* GetInGameMoneyServices() const { return GetSchemaValue<GCCSPlayerController_InGameMoneyServices*>(m_ptr, "CCSPlayerController", "m_pInGameMoneyServices"); }
    void SetInGameMoneyServices(GCCSPlayerController_InGameMoneyServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'InGameMoneyServices' is not possible.\n"); }
    GCCSPlayerController_InventoryServices* GetInventoryServices() const { return GetSchemaValue<GCCSPlayerController_InventoryServices*>(m_ptr, "CCSPlayerController", "m_pInventoryServices"); }
    void SetInventoryServices(GCCSPlayerController_InventoryServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'InventoryServices' is not possible.\n"); }
    GCCSPlayerController_ActionTrackingServices* GetActionTrackingServices() const { return GetSchemaValue<GCCSPlayerController_ActionTrackingServices*>(m_ptr, "CCSPlayerController", "m_pActionTrackingServices"); }
    void SetActionTrackingServices(GCCSPlayerController_ActionTrackingServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ActionTrackingServices' is not possible.\n"); }
    GCCSPlayerController_DamageServices* GetDamageServices() const { return GetSchemaValue<GCCSPlayerController_DamageServices*>(m_ptr, "CCSPlayerController", "m_pDamageServices"); }
    void SetDamageServices(GCCSPlayerController_DamageServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'DamageServices' is not possible.\n"); }
    uint32_t GetPing() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_iPing"); }
    void SetPing(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPing", false, value); }
    bool GetHasCommunicationAbuseMute() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bHasCommunicationAbuseMute"); }
    void SetHasCommunicationAbuseMute(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bHasCommunicationAbuseMute", false, value); }
    CUtlSymbolLarge GetCrosshairCodes() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCSPlayerController", "m_szCrosshairCodes"); }
    void SetCrosshairCodes(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_szCrosshairCodes", false, value); }
    uint8_t GetPendingTeamNum() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSPlayerController", "m_iPendingTeamNum"); }
    void SetPendingTeamNum(uint8_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPendingTeamNum", false, value); }
    int32_t GetCompTeammateColor() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompTeammateColor"); }
    void SetCompTeammateColor(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompTeammateColor", false, value); }
    bool GetEverPlayedOnTeam() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bEverPlayedOnTeam"); }
    void SetEverPlayedOnTeam(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bEverPlayedOnTeam", false, value); }
    bool GetAttemptedToGetColor() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bAttemptedToGetColor"); }
    void SetAttemptedToGetColor(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bAttemptedToGetColor", false, value); }
    int32_t GetTeammatePreferredColor() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iTeammatePreferredColor"); }
    void SetTeammatePreferredColor(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iTeammatePreferredColor", false, value); }
    bool GetTeamChanged() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bTeamChanged"); }
    void SetTeamChanged(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bTeamChanged", false, value); }
    bool GetInSwitchTeam() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bInSwitchTeam"); }
    void SetInSwitchTeam(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bInSwitchTeam", false, value); }
    bool GetHasSeenJoinGame() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bHasSeenJoinGame"); }
    void SetHasSeenJoinGame(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bHasSeenJoinGame", false, value); }
    bool GetJustBecameSpectator() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bJustBecameSpectator"); }
    void SetJustBecameSpectator(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bJustBecameSpectator", false, value); }
    bool GetSwitchTeamsOnNextRoundReset() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bSwitchTeamsOnNextRoundReset"); }
    void SetSwitchTeamsOnNextRoundReset(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bSwitchTeamsOnNextRoundReset", false, value); }
    bool GetRemoveAllItemsOnNextRoundReset() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bRemoveAllItemsOnNextRoundReset"); }
    void SetRemoveAllItemsOnNextRoundReset(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bRemoveAllItemsOnNextRoundReset", false, value); }
    CUtlSymbolLarge GetClan() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCSPlayerController", "m_szClan"); }
    void SetClan(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_szClan", false, value); }
    std::string GetClanName() const { return GetSchemaValue<char*>(m_ptr, "CCSPlayerController", "m_szClanName"); }
    void SetClanName(std::string value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_szClanName", false, value); }
    int32_t GetCoachingTeam() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCoachingTeam"); }
    void SetCoachingTeam(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCoachingTeam", false, value); }
    uint64_t GetPlayerDominated() const { return GetSchemaValue<uint64_t>(m_ptr, "CCSPlayerController", "m_nPlayerDominated"); }
    void SetPlayerDominated(uint64_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_nPlayerDominated", false, value); }
    uint64_t GetPlayerDominatingMe() const { return GetSchemaValue<uint64_t>(m_ptr, "CCSPlayerController", "m_nPlayerDominatingMe"); }
    void SetPlayerDominatingMe(uint64_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_nPlayerDominatingMe", false, value); }
    int32_t GetCompetitiveRanking() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveRanking"); }
    void SetCompetitiveRanking(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveRanking", false, value); }
    int32_t GetCompetitiveWins() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveWins"); }
    void SetCompetitiveWins(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveWins", false, value); }
    int8_t GetCompetitiveRankType() const { return GetSchemaValue<int8_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveRankType"); }
    void SetCompetitiveRankType(int8_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveRankType", false, value); }
    int32_t GetCompetitiveRankingPredicted_Win() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Win"); }
    void SetCompetitiveRankingPredicted_Win(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Win", false, value); }
    int32_t GetCompetitiveRankingPredicted_Loss() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Loss"); }
    void SetCompetitiveRankingPredicted_Loss(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Loss", false, value); }
    int32_t GetCompetitiveRankingPredicted_Tie() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Tie"); }
    void SetCompetitiveRankingPredicted_Tie(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Tie", false, value); }
    int32_t GetEndMatchNextMapVote() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_nEndMatchNextMapVote"); }
    void SetEndMatchNextMapVote(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_nEndMatchNextMapVote", false, value); }
    uint16_t GetActiveQuestId() const { return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerController", "m_unActiveQuestId"); }
    void SetActiveQuestId(uint16_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_unActiveQuestId", false, value); }
    GQuestProgress GetQuestProgressReason() const { return GetSchemaValue<GQuestProgress>(m_ptr, "CCSPlayerController", "m_nQuestProgressReason"); }
    void SetQuestProgressReason(GQuestProgress value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_nQuestProgressReason", false, value); }
    uint32_t GetPlayerTvControlFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_unPlayerTvControlFlags"); }
    void SetPlayerTvControlFlags(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_unPlayerTvControlFlags", false, value); }
    int32_t GetDraftIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iDraftIndex"); }
    void SetDraftIndex(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iDraftIndex", false, value); }
    uint32_t GetMsQueuedModeDisconnectionTimestamp() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_msQueuedModeDisconnectionTimestamp"); }
    void SetMsQueuedModeDisconnectionTimestamp(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_msQueuedModeDisconnectionTimestamp", false, value); }
    uint32_t GetUiAbandonRecordedReason() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_uiAbandonRecordedReason"); }
    void SetUiAbandonRecordedReason(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_uiAbandonRecordedReason", false, value); }
    bool GetCannotBeKicked() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bCannotBeKicked"); }
    void SetCannotBeKicked(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bCannotBeKicked", false, value); }
    bool GetEverFullyConnected() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bEverFullyConnected"); }
    void SetEverFullyConnected(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bEverFullyConnected", false, value); }
    bool GetAbandonAllowsSurrender() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bAbandonAllowsSurrender"); }
    void SetAbandonAllowsSurrender(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bAbandonAllowsSurrender", false, value); }
    bool GetAbandonOffersInstantSurrender() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bAbandonOffersInstantSurrender"); }
    void SetAbandonOffersInstantSurrender(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bAbandonOffersInstantSurrender", false, value); }
    bool GetDisconnection1MinWarningPrinted() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bDisconnection1MinWarningPrinted"); }
    void SetDisconnection1MinWarningPrinted(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bDisconnection1MinWarningPrinted", false, value); }
    bool GetScoreReported() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bScoreReported"); }
    void SetScoreReported(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bScoreReported", false, value); }
    int32_t GetDisconnectionTick() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_nDisconnectionTick"); }
    void SetDisconnectionTick(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_nDisconnectionTick", false, value); }
    bool GetControllingBot() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bControllingBot"); }
    void SetControllingBot(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bControllingBot", false, value); }
    bool GetHasControlledBotThisRound() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bHasControlledBotThisRound"); }
    void SetHasControlledBotThisRound(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bHasControlledBotThisRound", false, value); }
    bool GetHasBeenControlledByPlayerThisRound() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bHasBeenControlledByPlayerThisRound"); }
    void SetHasBeenControlledByPlayerThisRound(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bHasBeenControlledByPlayerThisRound", false, value); }
    int32_t GetBotsControlledThisRound() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_nBotsControlledThisRound"); }
    void SetBotsControlledThisRound(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_nBotsControlledThisRound", false, value); }
    bool GetCanControlObservedBot() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bCanControlObservedBot"); }
    void SetCanControlObservedBot(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bCanControlObservedBot", false, value); }
    GCCSPlayerPawn* GetPlayerPawn() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CCSPlayerController", "m_hPlayerPawn"); }
    void SetPlayerPawn(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerPawn' is not possible.\n"); }
    GCCSObserverPawn* GetObserverPawn() const { return GetSchemaValue<GCCSObserverPawn*>(m_ptr, "CCSPlayerController", "m_hObserverPawn"); }
    void SetObserverPawn(GCCSObserverPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ObserverPawn' is not possible.\n"); }
    int32_t GetDesiredObserverMode() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_DesiredObserverMode"); }
    void SetDesiredObserverMode(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_DesiredObserverMode", false, value); }
    GCEntityInstance* GetDesiredObserverTarget() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CCSPlayerController", "m_hDesiredObserverTarget"); }
    void SetDesiredObserverTarget(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'DesiredObserverTarget' is not possible.\n"); }
    bool GetPawnIsAlive() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bPawnIsAlive"); }
    void SetPawnIsAlive(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bPawnIsAlive", false, value); }
    uint32_t GetPawnHealth() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_iPawnHealth"); }
    void SetPawnHealth(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPawnHealth", false, value); }
    int32_t GetPawnArmor() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iPawnArmor"); }
    void SetPawnArmor(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPawnArmor", false, value); }
    bool GetPawnHasDefuser() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bPawnHasDefuser"); }
    void SetPawnHasDefuser(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bPawnHasDefuser", false, value); }
    bool GetPawnHasHelmet() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bPawnHasHelmet"); }
    void SetPawnHasHelmet(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bPawnHasHelmet", false, value); }
    uint16_t GetPawnCharacterDefIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerController", "m_nPawnCharacterDefIndex"); }
    void SetPawnCharacterDefIndex(uint16_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_nPawnCharacterDefIndex", false, value); }
    int32_t GetPawnLifetimeStart() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iPawnLifetimeStart"); }
    void SetPawnLifetimeStart(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPawnLifetimeStart", false, value); }
    int32_t GetPawnLifetimeEnd() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iPawnLifetimeEnd"); }
    void SetPawnLifetimeEnd(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPawnLifetimeEnd", false, value); }
    int32_t GetPawnBotDifficulty() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iPawnBotDifficulty"); }
    void SetPawnBotDifficulty(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPawnBotDifficulty", false, value); }
    GCCSPlayerController* GetOriginalControllerOfCurrentPawn() const { return GetSchemaValue<GCCSPlayerController*>(m_ptr, "CCSPlayerController", "m_hOriginalControllerOfCurrentPawn"); }
    void SetOriginalControllerOfCurrentPawn(GCCSPlayerController* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'OriginalControllerOfCurrentPawn' is not possible.\n"); }
    int32_t GetScore() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iScore"); }
    void SetScore(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iScore", false, value); }
    int32_t GetRoundScore() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iRoundScore"); }
    void SetRoundScore(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iRoundScore", false, value); }
    int32_t GetRoundsWon() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iRoundsWon"); }
    void SetRoundsWon(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iRoundsWon", false, value); }
    std::vector<EKillTypes_t> GetKills() const { CUtlVector<EKillTypes_t>* vec = GetSchemaValue<CUtlVector<EKillTypes_t>*>(m_ptr, "CCSPlayerController", "m_vecKills"); std::vector<EKillTypes_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetKills(std::vector<EKillTypes_t> value) { SetSchemaValueCUtlVector<EKillTypes_t>(m_ptr, "CCSPlayerController", "m_vecKills", false, value); }
    bool GetMvpNoMusic() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bMvpNoMusic"); }
    void SetMvpNoMusic(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bMvpNoMusic", false, value); }
    int32_t GetMvpReason() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_eMvpReason"); }
    void SetMvpReason(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_eMvpReason", false, value); }
    int32_t GetMusicKitID() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iMusicKitID"); }
    void SetMusicKitID(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iMusicKitID", false, value); }
    int32_t GetMusicKitMVPs() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iMusicKitMVPs"); }
    void SetMusicKitMVPs(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iMusicKitMVPs", false, value); }
    int32_t GetMVPs() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iMVPs"); }
    void SetMVPs(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iMVPs", false, value); }
    int32_t GetUpdateCounter() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_nUpdateCounter"); }
    void SetUpdateCounter(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_nUpdateCounter", false, value); }
    float GetSmoothedPing() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerController", "m_flSmoothedPing"); }
    void SetSmoothedPing(float value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_flSmoothedPing", false, value); }
    GIntervalTimer GetLastHeldVoteTimer() const { return GetSchemaValue<GIntervalTimer>(m_ptr, "CCSPlayerController", "m_lastHeldVoteTimer"); }
    void SetLastHeldVoteTimer(GIntervalTimer value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_lastHeldVoteTimer", false, value); }
    bool GetShowHints() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bShowHints"); }
    void SetShowHints(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bShowHints", false, value); }
    int32_t GetNextTimeCheck() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iNextTimeCheck"); }
    void SetNextTimeCheck(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_iNextTimeCheck", false, value); }
    bool GetJustDidTeamKill() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bJustDidTeamKill"); }
    void SetJustDidTeamKill(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bJustDidTeamKill", false, value); }
    bool GetPunishForTeamKill() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bPunishForTeamKill"); }
    void SetPunishForTeamKill(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bPunishForTeamKill", false, value); }
    bool GetGaveTeamDamageWarning() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bGaveTeamDamageWarning"); }
    void SetGaveTeamDamageWarning(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bGaveTeamDamageWarning", false, value); }
    bool GetGaveTeamDamageWarningThisRound() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bGaveTeamDamageWarningThisRound"); }
    void SetGaveTeamDamageWarningThisRound(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_bGaveTeamDamageWarningThisRound", false, value); }
    double GetDblLastReceivedPacketPlatFloatTime() const { return GetSchemaValue<double>(m_ptr, "CCSPlayerController", "m_dblLastReceivedPacketPlatFloatTime"); }
    void SetDblLastReceivedPacketPlatFloatTime(double value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_dblLastReceivedPacketPlatFloatTime", false, value); }
    uint32_t GetSuspiciousHitCount() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_nSuspiciousHitCount"); }
    void SetSuspiciousHitCount(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_nSuspiciousHitCount", false, value); }
    uint32_t GetNonSuspiciousHitStreak() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_nNonSuspiciousHitStreak"); }
    void SetNonSuspiciousHitStreak(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController", "m_nNonSuspiciousHitStreak", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif