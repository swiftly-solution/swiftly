#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayerController::GCCSPlayerController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayerController::GCCSPlayerController(void *ptr) {
    m_ptr = ptr;
}
GCCSPlayerController_InGameMoneyServices GCCSPlayerController::GetInGameMoneyServices() const {
    GCCSPlayerController_InGameMoneyServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerController", "m_pInGameMoneyServices"));
    return value;
}
void GCCSPlayerController::SetInGameMoneyServices(GCCSPlayerController_InGameMoneyServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'InGameMoneyServices' is not possible.\n");
}
GCCSPlayerController_InventoryServices GCCSPlayerController::GetInventoryServices() const {
    GCCSPlayerController_InventoryServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerController", "m_pInventoryServices"));
    return value;
}
void GCCSPlayerController::SetInventoryServices(GCCSPlayerController_InventoryServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'InventoryServices' is not possible.\n");
}
GCCSPlayerController_ActionTrackingServices GCCSPlayerController::GetActionTrackingServices() const {
    GCCSPlayerController_ActionTrackingServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerController", "m_pActionTrackingServices"));
    return value;
}
void GCCSPlayerController::SetActionTrackingServices(GCCSPlayerController_ActionTrackingServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ActionTrackingServices' is not possible.\n");
}
GCCSPlayerController_DamageServices GCCSPlayerController::GetDamageServices() const {
    GCCSPlayerController_DamageServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerController", "m_pDamageServices"));
    return value;
}
void GCCSPlayerController::SetDamageServices(GCCSPlayerController_DamageServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'DamageServices' is not possible.\n");
}
uint32_t GCCSPlayerController::GetPing() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_iPing");
}
void GCCSPlayerController::SetPing(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPing", false, value);
}
bool GCCSPlayerController::GetHasCommunicationAbuseMute() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bHasCommunicationAbuseMute");
}
void GCCSPlayerController::SetHasCommunicationAbuseMute(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bHasCommunicationAbuseMute", false, value);
}
std::string GCCSPlayerController::GetCrosshairCodes() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCSPlayerController", "m_szCrosshairCodes").String();
}
void GCCSPlayerController::SetCrosshairCodes(std::string value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_szCrosshairCodes", false, CUtlSymbolLarge(value.c_str()));
}
uint8_t GCCSPlayerController::GetPendingTeamNum() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSPlayerController", "m_iPendingTeamNum");
}
void GCCSPlayerController::SetPendingTeamNum(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPendingTeamNum", false, value);
}
float GCCSPlayerController::GetForceTeamTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerController", "m_flForceTeamTime");
}
void GCCSPlayerController::SetForceTeamTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_flForceTeamTime", false, value);
}
int32_t GCCSPlayerController::GetCompTeammateColor() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompTeammateColor");
}
void GCCSPlayerController::SetCompTeammateColor(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompTeammateColor", false, value);
}
bool GCCSPlayerController::GetEverPlayedOnTeam() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bEverPlayedOnTeam");
}
void GCCSPlayerController::SetEverPlayedOnTeam(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bEverPlayedOnTeam", false, value);
}
bool GCCSPlayerController::GetAttemptedToGetColor() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bAttemptedToGetColor");
}
void GCCSPlayerController::SetAttemptedToGetColor(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bAttemptedToGetColor", false, value);
}
int32_t GCCSPlayerController::GetTeammatePreferredColor() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iTeammatePreferredColor");
}
void GCCSPlayerController::SetTeammatePreferredColor(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iTeammatePreferredColor", false, value);
}
bool GCCSPlayerController::GetTeamChanged() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bTeamChanged");
}
void GCCSPlayerController::SetTeamChanged(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bTeamChanged", false, value);
}
bool GCCSPlayerController::GetInSwitchTeam() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bInSwitchTeam");
}
void GCCSPlayerController::SetInSwitchTeam(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bInSwitchTeam", false, value);
}
bool GCCSPlayerController::GetHasSeenJoinGame() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bHasSeenJoinGame");
}
void GCCSPlayerController::SetHasSeenJoinGame(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bHasSeenJoinGame", false, value);
}
bool GCCSPlayerController::GetJustBecameSpectator() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bJustBecameSpectator");
}
void GCCSPlayerController::SetJustBecameSpectator(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bJustBecameSpectator", false, value);
}
bool GCCSPlayerController::GetSwitchTeamsOnNextRoundReset() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bSwitchTeamsOnNextRoundReset");
}
void GCCSPlayerController::SetSwitchTeamsOnNextRoundReset(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bSwitchTeamsOnNextRoundReset", false, value);
}
bool GCCSPlayerController::GetRemoveAllItemsOnNextRoundReset() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bRemoveAllItemsOnNextRoundReset");
}
void GCCSPlayerController::SetRemoveAllItemsOnNextRoundReset(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bRemoveAllItemsOnNextRoundReset", false, value);
}
std::string GCCSPlayerController::GetClan() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCSPlayerController", "m_szClan").String();
}
void GCCSPlayerController::SetClan(std::string value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_szClan", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCCSPlayerController::GetClanName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSPlayerController", "m_szClanName");
}
void GCCSPlayerController::SetClanName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSPlayerController", "m_szClanName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 32);
}
int32_t GCCSPlayerController::GetCoachingTeam() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCoachingTeam");
}
void GCCSPlayerController::SetCoachingTeam(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCoachingTeam", false, value);
}
uint64_t GCCSPlayerController::GetPlayerDominated() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSPlayerController", "m_nPlayerDominated");
}
void GCCSPlayerController::SetPlayerDominated(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_nPlayerDominated", false, value);
}
uint64_t GCCSPlayerController::GetPlayerDominatingMe() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSPlayerController", "m_nPlayerDominatingMe");
}
void GCCSPlayerController::SetPlayerDominatingMe(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_nPlayerDominatingMe", false, value);
}
int32_t GCCSPlayerController::GetCompetitiveRanking() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveRanking");
}
void GCCSPlayerController::SetCompetitiveRanking(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveRanking", false, value);
}
int32_t GCCSPlayerController::GetCompetitiveWins() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveWins");
}
void GCCSPlayerController::SetCompetitiveWins(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveWins", false, value);
}
int8_t GCCSPlayerController::GetCompetitiveRankType() const {
    return GetSchemaValue<int8_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveRankType");
}
void GCCSPlayerController::SetCompetitiveRankType(int8_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveRankType", false, value);
}
int32_t GCCSPlayerController::GetCompetitiveRankingPredicted_Win() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Win");
}
void GCCSPlayerController::SetCompetitiveRankingPredicted_Win(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Win", false, value);
}
int32_t GCCSPlayerController::GetCompetitiveRankingPredicted_Loss() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Loss");
}
void GCCSPlayerController::SetCompetitiveRankingPredicted_Loss(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Loss", false, value);
}
int32_t GCCSPlayerController::GetCompetitiveRankingPredicted_Tie() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Tie");
}
void GCCSPlayerController::SetCompetitiveRankingPredicted_Tie(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Tie", false, value);
}
int32_t GCCSPlayerController::GetEndMatchNextMapVote() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_nEndMatchNextMapVote");
}
void GCCSPlayerController::SetEndMatchNextMapVote(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_nEndMatchNextMapVote", false, value);
}
uint16_t GCCSPlayerController::GetActiveQuestId() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerController", "m_unActiveQuestId");
}
void GCCSPlayerController::SetActiveQuestId(uint16_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_unActiveQuestId", false, value);
}
GQuestProgress GCCSPlayerController::GetQuestProgressReason() const {
    GQuestProgress value(GetSchemaPtr(m_ptr, "CCSPlayerController", "m_nQuestProgressReason"));
    return value;
}
void GCCSPlayerController::SetQuestProgressReason(GQuestProgress value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_nQuestProgressReason", false, value);
}
uint32_t GCCSPlayerController::GetPlayerTvControlFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_unPlayerTvControlFlags");
}
void GCCSPlayerController::SetPlayerTvControlFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_unPlayerTvControlFlags", false, value);
}
int32_t GCCSPlayerController::GetDraftIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iDraftIndex");
}
void GCCSPlayerController::SetDraftIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iDraftIndex", false, value);
}
uint32_t GCCSPlayerController::GetMsQueuedModeDisconnectionTimestamp() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_msQueuedModeDisconnectionTimestamp");
}
void GCCSPlayerController::SetMsQueuedModeDisconnectionTimestamp(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_msQueuedModeDisconnectionTimestamp", false, value);
}
uint32_t GCCSPlayerController::GetUiAbandonRecordedReason() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_uiAbandonRecordedReason");
}
void GCCSPlayerController::SetUiAbandonRecordedReason(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_uiAbandonRecordedReason", false, value);
}
bool GCCSPlayerController::GetCannotBeKicked() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bCannotBeKicked");
}
void GCCSPlayerController::SetCannotBeKicked(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bCannotBeKicked", false, value);
}
bool GCCSPlayerController::GetEverFullyConnected() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bEverFullyConnected");
}
void GCCSPlayerController::SetEverFullyConnected(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bEverFullyConnected", false, value);
}
bool GCCSPlayerController::GetAbandonAllowsSurrender() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bAbandonAllowsSurrender");
}
void GCCSPlayerController::SetAbandonAllowsSurrender(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bAbandonAllowsSurrender", false, value);
}
bool GCCSPlayerController::GetAbandonOffersInstantSurrender() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bAbandonOffersInstantSurrender");
}
void GCCSPlayerController::SetAbandonOffersInstantSurrender(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bAbandonOffersInstantSurrender", false, value);
}
bool GCCSPlayerController::GetDisconnection1MinWarningPrinted() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bDisconnection1MinWarningPrinted");
}
void GCCSPlayerController::SetDisconnection1MinWarningPrinted(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bDisconnection1MinWarningPrinted", false, value);
}
bool GCCSPlayerController::GetScoreReported() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bScoreReported");
}
void GCCSPlayerController::SetScoreReported(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bScoreReported", false, value);
}
int32_t GCCSPlayerController::GetDisconnectionTick() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_nDisconnectionTick");
}
void GCCSPlayerController::SetDisconnectionTick(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_nDisconnectionTick", false, value);
}
bool GCCSPlayerController::GetControllingBot() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bControllingBot");
}
void GCCSPlayerController::SetControllingBot(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bControllingBot", false, value);
}
bool GCCSPlayerController::GetHasControlledBotThisRound() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bHasControlledBotThisRound");
}
void GCCSPlayerController::SetHasControlledBotThisRound(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bHasControlledBotThisRound", false, value);
}
bool GCCSPlayerController::GetHasBeenControlledByPlayerThisRound() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bHasBeenControlledByPlayerThisRound");
}
void GCCSPlayerController::SetHasBeenControlledByPlayerThisRound(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bHasBeenControlledByPlayerThisRound", false, value);
}
int32_t GCCSPlayerController::GetBotsControlledThisRound() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_nBotsControlledThisRound");
}
void GCCSPlayerController::SetBotsControlledThisRound(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_nBotsControlledThisRound", false, value);
}
bool GCCSPlayerController::GetCanControlObservedBot() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bCanControlObservedBot");
}
void GCCSPlayerController::SetCanControlObservedBot(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bCanControlObservedBot", false, value);
}
GCCSPlayerPawn GCCSPlayerController::GetPlayerPawn() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerController", "m_hPlayerPawn"));
    return value;
}
void GCCSPlayerController::SetPlayerPawn(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerPawn' is not possible.\n");
}
GCCSObserverPawn GCCSPlayerController::GetObserverPawn() const {
    GCCSObserverPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerController", "m_hObserverPawn"));
    return value;
}
void GCCSPlayerController::SetObserverPawn(GCCSObserverPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ObserverPawn' is not possible.\n");
}
int32_t GCCSPlayerController::GetDesiredObserverMode() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_DesiredObserverMode");
}
void GCCSPlayerController::SetDesiredObserverMode(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_DesiredObserverMode", false, value);
}
GCEntityInstance GCCSPlayerController::GetDesiredObserverTarget() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerController", "m_hDesiredObserverTarget"));
    return value;
}
void GCCSPlayerController::SetDesiredObserverTarget(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'DesiredObserverTarget' is not possible.\n");
}
bool GCCSPlayerController::GetPawnIsAlive() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bPawnIsAlive");
}
void GCCSPlayerController::SetPawnIsAlive(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bPawnIsAlive", false, value);
}
uint32_t GCCSPlayerController::GetPawnHealth() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_iPawnHealth");
}
void GCCSPlayerController::SetPawnHealth(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPawnHealth", false, value);
}
int32_t GCCSPlayerController::GetPawnArmor() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iPawnArmor");
}
void GCCSPlayerController::SetPawnArmor(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPawnArmor", false, value);
}
bool GCCSPlayerController::GetPawnHasDefuser() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bPawnHasDefuser");
}
void GCCSPlayerController::SetPawnHasDefuser(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bPawnHasDefuser", false, value);
}
bool GCCSPlayerController::GetPawnHasHelmet() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bPawnHasHelmet");
}
void GCCSPlayerController::SetPawnHasHelmet(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bPawnHasHelmet", false, value);
}
uint16_t GCCSPlayerController::GetPawnCharacterDefIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerController", "m_nPawnCharacterDefIndex");
}
void GCCSPlayerController::SetPawnCharacterDefIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_nPawnCharacterDefIndex", false, value);
}
int32_t GCCSPlayerController::GetPawnLifetimeStart() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iPawnLifetimeStart");
}
void GCCSPlayerController::SetPawnLifetimeStart(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPawnLifetimeStart", false, value);
}
int32_t GCCSPlayerController::GetPawnLifetimeEnd() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iPawnLifetimeEnd");
}
void GCCSPlayerController::SetPawnLifetimeEnd(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPawnLifetimeEnd", false, value);
}
int32_t GCCSPlayerController::GetPawnBotDifficulty() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iPawnBotDifficulty");
}
void GCCSPlayerController::SetPawnBotDifficulty(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iPawnBotDifficulty", false, value);
}
GCCSPlayerController GCCSPlayerController::GetOriginalControllerOfCurrentPawn() const {
    GCCSPlayerController value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerController", "m_hOriginalControllerOfCurrentPawn"));
    return value;
}
void GCCSPlayerController::SetOriginalControllerOfCurrentPawn(GCCSPlayerController* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'OriginalControllerOfCurrentPawn' is not possible.\n");
}
int32_t GCCSPlayerController::GetScore() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iScore");
}
void GCCSPlayerController::SetScore(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iScore", false, value);
}
int32_t GCCSPlayerController::GetRoundScore() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iRoundScore");
}
void GCCSPlayerController::SetRoundScore(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iRoundScore", false, value);
}
int32_t GCCSPlayerController::GetRoundsWon() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iRoundsWon");
}
void GCCSPlayerController::SetRoundsWon(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iRoundsWon", false, value);
}
std::vector<EKillTypes_t> GCCSPlayerController::GetKills() const {
    CUtlVector<EKillTypes_t>* vec = GetSchemaValue<CUtlVector<EKillTypes_t>*>(m_ptr, "CCSPlayerController", "m_vecKills"); std::vector<EKillTypes_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSPlayerController::SetKills(std::vector<EKillTypes_t> value) {
    SetSchemaValueCUtlVector<EKillTypes_t>(m_ptr, "CCSPlayerController", "m_vecKills", false, value);
}
bool GCCSPlayerController::GetMvpNoMusic() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bMvpNoMusic");
}
void GCCSPlayerController::SetMvpNoMusic(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bMvpNoMusic", false, value);
}
int32_t GCCSPlayerController::GetMvpReason() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_eMvpReason");
}
void GCCSPlayerController::SetMvpReason(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_eMvpReason", false, value);
}
int32_t GCCSPlayerController::GetMusicKitID() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iMusicKitID");
}
void GCCSPlayerController::SetMusicKitID(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iMusicKitID", false, value);
}
int32_t GCCSPlayerController::GetMusicKitMVPs() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iMusicKitMVPs");
}
void GCCSPlayerController::SetMusicKitMVPs(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iMusicKitMVPs", false, value);
}
int32_t GCCSPlayerController::GetMVPs() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iMVPs");
}
void GCCSPlayerController::SetMVPs(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iMVPs", false, value);
}
int32_t GCCSPlayerController::GetUpdateCounter() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_nUpdateCounter");
}
void GCCSPlayerController::SetUpdateCounter(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_nUpdateCounter", false, value);
}
float GCCSPlayerController::GetSmoothedPing() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerController", "m_flSmoothedPing");
}
void GCCSPlayerController::SetSmoothedPing(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_flSmoothedPing", false, value);
}
GIntervalTimer GCCSPlayerController::GetLastHeldVoteTimer() const {
    GIntervalTimer value(GetSchemaPtr(m_ptr, "CCSPlayerController", "m_lastHeldVoteTimer"));
    return value;
}
void GCCSPlayerController::SetLastHeldVoteTimer(GIntervalTimer value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_lastHeldVoteTimer", false, value);
}
bool GCCSPlayerController::GetShowHints() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bShowHints");
}
void GCCSPlayerController::SetShowHints(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bShowHints", false, value);
}
int32_t GCCSPlayerController::GetNextTimeCheck() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController", "m_iNextTimeCheck");
}
void GCCSPlayerController::SetNextTimeCheck(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_iNextTimeCheck", false, value);
}
bool GCCSPlayerController::GetJustDidTeamKill() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bJustDidTeamKill");
}
void GCCSPlayerController::SetJustDidTeamKill(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bJustDidTeamKill", false, value);
}
bool GCCSPlayerController::GetPunishForTeamKill() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bPunishForTeamKill");
}
void GCCSPlayerController::SetPunishForTeamKill(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bPunishForTeamKill", false, value);
}
bool GCCSPlayerController::GetGaveTeamDamageWarning() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bGaveTeamDamageWarning");
}
void GCCSPlayerController::SetGaveTeamDamageWarning(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bGaveTeamDamageWarning", false, value);
}
bool GCCSPlayerController::GetGaveTeamDamageWarningThisRound() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController", "m_bGaveTeamDamageWarningThisRound");
}
void GCCSPlayerController::SetGaveTeamDamageWarningThisRound(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_bGaveTeamDamageWarningThisRound", false, value);
}
double GCCSPlayerController::GetDblLastReceivedPacketPlatFloatTime() const {
    return GetSchemaValue<double>(m_ptr, "CCSPlayerController", "m_dblLastReceivedPacketPlatFloatTime");
}
void GCCSPlayerController::SetDblLastReceivedPacketPlatFloatTime(double value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_dblLastReceivedPacketPlatFloatTime", false, value);
}
float GCCSPlayerController::GetLastTeamDamageWarningTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerController", "m_LastTeamDamageWarningTime");
}
void GCCSPlayerController::SetLastTeamDamageWarningTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_LastTeamDamageWarningTime", false, value);
}
float GCCSPlayerController::GetLastTimePlayerWasDisconnectedForPawnsRemove() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerController", "m_LastTimePlayerWasDisconnectedForPawnsRemove");
}
void GCCSPlayerController::SetLastTimePlayerWasDisconnectedForPawnsRemove(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_LastTimePlayerWasDisconnectedForPawnsRemove", false, value);
}
uint32_t GCCSPlayerController::GetSuspiciousHitCount() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_nSuspiciousHitCount");
}
void GCCSPlayerController::SetSuspiciousHitCount(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_nSuspiciousHitCount", false, value);
}
uint32_t GCCSPlayerController::GetNonSuspiciousHitStreak() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController", "m_nNonSuspiciousHitStreak");
}
void GCCSPlayerController::SetNonSuspiciousHitStreak(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController", "m_nNonSuspiciousHitStreak", false, value);
}
std::string GCCSPlayerController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayerController::IsValid() {
    return (m_ptr != nullptr);
}
GCBasePlayerController GCCSPlayerController::GetParent() const {
    GCBasePlayerController value(m_ptr);
    return value;
}
void GCCSPlayerController::SetParent(GCBasePlayerController value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayerController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerController>("CCSPlayerController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InGameMoneyServices", &GCCSPlayerController::GetInGameMoneyServices, &GCCSPlayerController::SetInGameMoneyServices)
        .addProperty("InventoryServices", &GCCSPlayerController::GetInventoryServices, &GCCSPlayerController::SetInventoryServices)
        .addProperty("ActionTrackingServices", &GCCSPlayerController::GetActionTrackingServices, &GCCSPlayerController::SetActionTrackingServices)
        .addProperty("DamageServices", &GCCSPlayerController::GetDamageServices, &GCCSPlayerController::SetDamageServices)
        .addProperty("Ping", &GCCSPlayerController::GetPing, &GCCSPlayerController::SetPing)
        .addProperty("HasCommunicationAbuseMute", &GCCSPlayerController::GetHasCommunicationAbuseMute, &GCCSPlayerController::SetHasCommunicationAbuseMute)
        .addProperty("CrosshairCodes", &GCCSPlayerController::GetCrosshairCodes, &GCCSPlayerController::SetCrosshairCodes)
        .addProperty("PendingTeamNum", &GCCSPlayerController::GetPendingTeamNum, &GCCSPlayerController::SetPendingTeamNum)
        .addProperty("ForceTeamTime", &GCCSPlayerController::GetForceTeamTime, &GCCSPlayerController::SetForceTeamTime)
        .addProperty("CompTeammateColor", &GCCSPlayerController::GetCompTeammateColor, &GCCSPlayerController::SetCompTeammateColor)
        .addProperty("EverPlayedOnTeam", &GCCSPlayerController::GetEverPlayedOnTeam, &GCCSPlayerController::SetEverPlayedOnTeam)
        .addProperty("AttemptedToGetColor", &GCCSPlayerController::GetAttemptedToGetColor, &GCCSPlayerController::SetAttemptedToGetColor)
        .addProperty("TeammatePreferredColor", &GCCSPlayerController::GetTeammatePreferredColor, &GCCSPlayerController::SetTeammatePreferredColor)
        .addProperty("TeamChanged", &GCCSPlayerController::GetTeamChanged, &GCCSPlayerController::SetTeamChanged)
        .addProperty("InSwitchTeam", &GCCSPlayerController::GetInSwitchTeam, &GCCSPlayerController::SetInSwitchTeam)
        .addProperty("HasSeenJoinGame", &GCCSPlayerController::GetHasSeenJoinGame, &GCCSPlayerController::SetHasSeenJoinGame)
        .addProperty("JustBecameSpectator", &GCCSPlayerController::GetJustBecameSpectator, &GCCSPlayerController::SetJustBecameSpectator)
        .addProperty("SwitchTeamsOnNextRoundReset", &GCCSPlayerController::GetSwitchTeamsOnNextRoundReset, &GCCSPlayerController::SetSwitchTeamsOnNextRoundReset)
        .addProperty("RemoveAllItemsOnNextRoundReset", &GCCSPlayerController::GetRemoveAllItemsOnNextRoundReset, &GCCSPlayerController::SetRemoveAllItemsOnNextRoundReset)
        .addProperty("Clan", &GCCSPlayerController::GetClan, &GCCSPlayerController::SetClan)
        .addProperty("ClanName", &GCCSPlayerController::GetClanName, &GCCSPlayerController::SetClanName)
        .addProperty("CoachingTeam", &GCCSPlayerController::GetCoachingTeam, &GCCSPlayerController::SetCoachingTeam)
        .addProperty("PlayerDominated", &GCCSPlayerController::GetPlayerDominated, &GCCSPlayerController::SetPlayerDominated)
        .addProperty("PlayerDominatingMe", &GCCSPlayerController::GetPlayerDominatingMe, &GCCSPlayerController::SetPlayerDominatingMe)
        .addProperty("CompetitiveRanking", &GCCSPlayerController::GetCompetitiveRanking, &GCCSPlayerController::SetCompetitiveRanking)
        .addProperty("CompetitiveWins", &GCCSPlayerController::GetCompetitiveWins, &GCCSPlayerController::SetCompetitiveWins)
        .addProperty("CompetitiveRankType", &GCCSPlayerController::GetCompetitiveRankType, &GCCSPlayerController::SetCompetitiveRankType)
        .addProperty("CompetitiveRankingPredicted_Win", &GCCSPlayerController::GetCompetitiveRankingPredicted_Win, &GCCSPlayerController::SetCompetitiveRankingPredicted_Win)
        .addProperty("CompetitiveRankingPredicted_Loss", &GCCSPlayerController::GetCompetitiveRankingPredicted_Loss, &GCCSPlayerController::SetCompetitiveRankingPredicted_Loss)
        .addProperty("CompetitiveRankingPredicted_Tie", &GCCSPlayerController::GetCompetitiveRankingPredicted_Tie, &GCCSPlayerController::SetCompetitiveRankingPredicted_Tie)
        .addProperty("EndMatchNextMapVote", &GCCSPlayerController::GetEndMatchNextMapVote, &GCCSPlayerController::SetEndMatchNextMapVote)
        .addProperty("ActiveQuestId", &GCCSPlayerController::GetActiveQuestId, &GCCSPlayerController::SetActiveQuestId)
        .addProperty("QuestProgressReason", &GCCSPlayerController::GetQuestProgressReason, &GCCSPlayerController::SetQuestProgressReason)
        .addProperty("PlayerTvControlFlags", &GCCSPlayerController::GetPlayerTvControlFlags, &GCCSPlayerController::SetPlayerTvControlFlags)
        .addProperty("DraftIndex", &GCCSPlayerController::GetDraftIndex, &GCCSPlayerController::SetDraftIndex)
        .addProperty("MsQueuedModeDisconnectionTimestamp", &GCCSPlayerController::GetMsQueuedModeDisconnectionTimestamp, &GCCSPlayerController::SetMsQueuedModeDisconnectionTimestamp)
        .addProperty("UiAbandonRecordedReason", &GCCSPlayerController::GetUiAbandonRecordedReason, &GCCSPlayerController::SetUiAbandonRecordedReason)
        .addProperty("CannotBeKicked", &GCCSPlayerController::GetCannotBeKicked, &GCCSPlayerController::SetCannotBeKicked)
        .addProperty("EverFullyConnected", &GCCSPlayerController::GetEverFullyConnected, &GCCSPlayerController::SetEverFullyConnected)
        .addProperty("AbandonAllowsSurrender", &GCCSPlayerController::GetAbandonAllowsSurrender, &GCCSPlayerController::SetAbandonAllowsSurrender)
        .addProperty("AbandonOffersInstantSurrender", &GCCSPlayerController::GetAbandonOffersInstantSurrender, &GCCSPlayerController::SetAbandonOffersInstantSurrender)
        .addProperty("Disconnection1MinWarningPrinted", &GCCSPlayerController::GetDisconnection1MinWarningPrinted, &GCCSPlayerController::SetDisconnection1MinWarningPrinted)
        .addProperty("ScoreReported", &GCCSPlayerController::GetScoreReported, &GCCSPlayerController::SetScoreReported)
        .addProperty("DisconnectionTick", &GCCSPlayerController::GetDisconnectionTick, &GCCSPlayerController::SetDisconnectionTick)
        .addProperty("ControllingBot", &GCCSPlayerController::GetControllingBot, &GCCSPlayerController::SetControllingBot)
        .addProperty("HasControlledBotThisRound", &GCCSPlayerController::GetHasControlledBotThisRound, &GCCSPlayerController::SetHasControlledBotThisRound)
        .addProperty("HasBeenControlledByPlayerThisRound", &GCCSPlayerController::GetHasBeenControlledByPlayerThisRound, &GCCSPlayerController::SetHasBeenControlledByPlayerThisRound)
        .addProperty("BotsControlledThisRound", &GCCSPlayerController::GetBotsControlledThisRound, &GCCSPlayerController::SetBotsControlledThisRound)
        .addProperty("CanControlObservedBot", &GCCSPlayerController::GetCanControlObservedBot, &GCCSPlayerController::SetCanControlObservedBot)
        .addProperty("PlayerPawn", &GCCSPlayerController::GetPlayerPawn, &GCCSPlayerController::SetPlayerPawn)
        .addProperty("ObserverPawn", &GCCSPlayerController::GetObserverPawn, &GCCSPlayerController::SetObserverPawn)
        .addProperty("DesiredObserverMode", &GCCSPlayerController::GetDesiredObserverMode, &GCCSPlayerController::SetDesiredObserverMode)
        .addProperty("DesiredObserverTarget", &GCCSPlayerController::GetDesiredObserverTarget, &GCCSPlayerController::SetDesiredObserverTarget)
        .addProperty("PawnIsAlive", &GCCSPlayerController::GetPawnIsAlive, &GCCSPlayerController::SetPawnIsAlive)
        .addProperty("PawnHealth", &GCCSPlayerController::GetPawnHealth, &GCCSPlayerController::SetPawnHealth)
        .addProperty("PawnArmor", &GCCSPlayerController::GetPawnArmor, &GCCSPlayerController::SetPawnArmor)
        .addProperty("PawnHasDefuser", &GCCSPlayerController::GetPawnHasDefuser, &GCCSPlayerController::SetPawnHasDefuser)
        .addProperty("PawnHasHelmet", &GCCSPlayerController::GetPawnHasHelmet, &GCCSPlayerController::SetPawnHasHelmet)
        .addProperty("PawnCharacterDefIndex", &GCCSPlayerController::GetPawnCharacterDefIndex, &GCCSPlayerController::SetPawnCharacterDefIndex)
        .addProperty("PawnLifetimeStart", &GCCSPlayerController::GetPawnLifetimeStart, &GCCSPlayerController::SetPawnLifetimeStart)
        .addProperty("PawnLifetimeEnd", &GCCSPlayerController::GetPawnLifetimeEnd, &GCCSPlayerController::SetPawnLifetimeEnd)
        .addProperty("PawnBotDifficulty", &GCCSPlayerController::GetPawnBotDifficulty, &GCCSPlayerController::SetPawnBotDifficulty)
        .addProperty("OriginalControllerOfCurrentPawn", &GCCSPlayerController::GetOriginalControllerOfCurrentPawn, &GCCSPlayerController::SetOriginalControllerOfCurrentPawn)
        .addProperty("Score", &GCCSPlayerController::GetScore, &GCCSPlayerController::SetScore)
        .addProperty("RoundScore", &GCCSPlayerController::GetRoundScore, &GCCSPlayerController::SetRoundScore)
        .addProperty("RoundsWon", &GCCSPlayerController::GetRoundsWon, &GCCSPlayerController::SetRoundsWon)
        .addProperty("Kills", &GCCSPlayerController::GetKills, &GCCSPlayerController::SetKills)
        .addProperty("MvpNoMusic", &GCCSPlayerController::GetMvpNoMusic, &GCCSPlayerController::SetMvpNoMusic)
        .addProperty("MvpReason", &GCCSPlayerController::GetMvpReason, &GCCSPlayerController::SetMvpReason)
        .addProperty("MusicKitID", &GCCSPlayerController::GetMusicKitID, &GCCSPlayerController::SetMusicKitID)
        .addProperty("MusicKitMVPs", &GCCSPlayerController::GetMusicKitMVPs, &GCCSPlayerController::SetMusicKitMVPs)
        .addProperty("MVPs", &GCCSPlayerController::GetMVPs, &GCCSPlayerController::SetMVPs)
        .addProperty("UpdateCounter", &GCCSPlayerController::GetUpdateCounter, &GCCSPlayerController::SetUpdateCounter)
        .addProperty("SmoothedPing", &GCCSPlayerController::GetSmoothedPing, &GCCSPlayerController::SetSmoothedPing)
        .addProperty("LastHeldVoteTimer", &GCCSPlayerController::GetLastHeldVoteTimer, &GCCSPlayerController::SetLastHeldVoteTimer)
        .addProperty("ShowHints", &GCCSPlayerController::GetShowHints, &GCCSPlayerController::SetShowHints)
        .addProperty("NextTimeCheck", &GCCSPlayerController::GetNextTimeCheck, &GCCSPlayerController::SetNextTimeCheck)
        .addProperty("JustDidTeamKill", &GCCSPlayerController::GetJustDidTeamKill, &GCCSPlayerController::SetJustDidTeamKill)
        .addProperty("PunishForTeamKill", &GCCSPlayerController::GetPunishForTeamKill, &GCCSPlayerController::SetPunishForTeamKill)
        .addProperty("GaveTeamDamageWarning", &GCCSPlayerController::GetGaveTeamDamageWarning, &GCCSPlayerController::SetGaveTeamDamageWarning)
        .addProperty("GaveTeamDamageWarningThisRound", &GCCSPlayerController::GetGaveTeamDamageWarningThisRound, &GCCSPlayerController::SetGaveTeamDamageWarningThisRound)
        .addProperty("DblLastReceivedPacketPlatFloatTime", &GCCSPlayerController::GetDblLastReceivedPacketPlatFloatTime, &GCCSPlayerController::SetDblLastReceivedPacketPlatFloatTime)
        .addProperty("LastTeamDamageWarningTime", &GCCSPlayerController::GetLastTeamDamageWarningTime, &GCCSPlayerController::SetLastTeamDamageWarningTime)
        .addProperty("LastTimePlayerWasDisconnectedForPawnsRemove", &GCCSPlayerController::GetLastTimePlayerWasDisconnectedForPawnsRemove, &GCCSPlayerController::SetLastTimePlayerWasDisconnectedForPawnsRemove)
        .addProperty("SuspiciousHitCount", &GCCSPlayerController::GetSuspiciousHitCount, &GCCSPlayerController::SetSuspiciousHitCount)
        .addProperty("NonSuspiciousHitStreak", &GCCSPlayerController::GetNonSuspiciousHitStreak, &GCCSPlayerController::SetNonSuspiciousHitStreak)
        .addProperty("Parent", &GCCSPlayerController::GetParent, &GCCSPlayerController::SetParent)
        .addFunction("ToPtr", &GCCSPlayerController::ToPtr)
        .addFunction("IsValid", &GCCSPlayerController::IsValid)
        .endClass();
}