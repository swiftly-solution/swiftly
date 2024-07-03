#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGameRules::GCCSGameRules(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGameRules::GCCSGameRules(void *ptr) {
    m_ptr = ptr;
}
bool GCCSGameRules::GetFreezePeriod() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bFreezePeriod");
}
void GCCSGameRules::SetFreezePeriod(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bFreezePeriod", false, value);
}
bool GCCSGameRules::GetWarmupPeriod() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bWarmupPeriod");
}
void GCCSGameRules::SetWarmupPeriod(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bWarmupPeriod", false, value);
}
float GCCSGameRules::GetWarmupPeriodEnd() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fWarmupPeriodEnd");
}
void GCCSGameRules::SetWarmupPeriodEnd(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_fWarmupPeriodEnd", false, value);
}
float GCCSGameRules::GetWarmupPeriodStart() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fWarmupPeriodStart");
}
void GCCSGameRules::SetWarmupPeriodStart(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_fWarmupPeriodStart", false, value);
}
bool GCCSGameRules::GetServerPaused() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bServerPaused");
}
void GCCSGameRules::SetServerPaused(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bServerPaused", false, value);
}
bool GCCSGameRules::GetTerroristTimeOutActive() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bTerroristTimeOutActive");
}
void GCCSGameRules::SetTerroristTimeOutActive(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bTerroristTimeOutActive", false, value);
}
bool GCCSGameRules::GetCTTimeOutActive() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bCTTimeOutActive");
}
void GCCSGameRules::SetCTTimeOutActive(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bCTTimeOutActive", false, value);
}
float GCCSGameRules::GetTerroristTimeOutRemaining() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flTerroristTimeOutRemaining");
}
void GCCSGameRules::SetTerroristTimeOutRemaining(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flTerroristTimeOutRemaining", false, value);
}
float GCCSGameRules::GetCTTimeOutRemaining() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flCTTimeOutRemaining");
}
void GCCSGameRules::SetCTTimeOutRemaining(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flCTTimeOutRemaining", false, value);
}
int32_t GCCSGameRules::GetTerroristTimeOuts() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nTerroristTimeOuts");
}
void GCCSGameRules::SetTerroristTimeOuts(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nTerroristTimeOuts", false, value);
}
int32_t GCCSGameRules::GetCTTimeOuts() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nCTTimeOuts");
}
void GCCSGameRules::SetCTTimeOuts(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nCTTimeOuts", false, value);
}
bool GCCSGameRules::GetTechnicalTimeOut() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bTechnicalTimeOut");
}
void GCCSGameRules::SetTechnicalTimeOut(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bTechnicalTimeOut", false, value);
}
bool GCCSGameRules::GetMatchWaitingForResume() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bMatchWaitingForResume");
}
void GCCSGameRules::SetMatchWaitingForResume(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bMatchWaitingForResume", false, value);
}
int32_t GCCSGameRules::GetRoundTime() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundTime");
}
void GCCSGameRules::SetRoundTime(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundTime", false, value);
}
float GCCSGameRules::GetMatchStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fMatchStartTime");
}
void GCCSGameRules::SetMatchStartTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_fMatchStartTime", false, value);
}
float GCCSGameRules::GetRoundStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fRoundStartTime");
}
void GCCSGameRules::SetRoundStartTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_fRoundStartTime", false, value);
}
float GCCSGameRules::GetRestartRoundTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flRestartRoundTime");
}
void GCCSGameRules::SetRestartRoundTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flRestartRoundTime", false, value);
}
bool GCCSGameRules::GetGameRestart() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bGameRestart");
}
void GCCSGameRules::SetGameRestart(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bGameRestart", false, value);
}
float GCCSGameRules::GetGameStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flGameStartTime");
}
void GCCSGameRules::SetGameStartTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flGameStartTime", false, value);
}
float GCCSGameRules::GetTimeUntilNextPhaseStarts() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_timeUntilNextPhaseStarts");
}
void GCCSGameRules::SetTimeUntilNextPhaseStarts(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_timeUntilNextPhaseStarts", false, value);
}
int32_t GCCSGameRules::GetGamePhase() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_gamePhase");
}
void GCCSGameRules::SetGamePhase(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_gamePhase", false, value);
}
int32_t GCCSGameRules::GetTotalRoundsPlayed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_totalRoundsPlayed");
}
void GCCSGameRules::SetTotalRoundsPlayed(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_totalRoundsPlayed", false, value);
}
int32_t GCCSGameRules::GetRoundsPlayedThisPhase() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nRoundsPlayedThisPhase");
}
void GCCSGameRules::SetRoundsPlayedThisPhase(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nRoundsPlayedThisPhase", false, value);
}
int32_t GCCSGameRules::GetOvertimePlaying() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nOvertimePlaying");
}
void GCCSGameRules::SetOvertimePlaying(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nOvertimePlaying", false, value);
}
int32_t GCCSGameRules::GetHostagesRemaining() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iHostagesRemaining");
}
void GCCSGameRules::SetHostagesRemaining(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iHostagesRemaining", false, value);
}
bool GCCSGameRules::GetAnyHostageReached() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bAnyHostageReached");
}
void GCCSGameRules::SetAnyHostageReached(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bAnyHostageReached", false, value);
}
bool GCCSGameRules::GetMapHasBombTarget() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bMapHasBombTarget");
}
void GCCSGameRules::SetMapHasBombTarget(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bMapHasBombTarget", false, value);
}
bool GCCSGameRules::GetMapHasRescueZone() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bMapHasRescueZone");
}
void GCCSGameRules::SetMapHasRescueZone(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bMapHasRescueZone", false, value);
}
bool GCCSGameRules::GetMapHasBuyZone() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bMapHasBuyZone");
}
void GCCSGameRules::SetMapHasBuyZone(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bMapHasBuyZone", false, value);
}
bool GCCSGameRules::GetIsQueuedMatchmaking() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsQueuedMatchmaking");
}
void GCCSGameRules::SetIsQueuedMatchmaking(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsQueuedMatchmaking", false, value);
}
int32_t GCCSGameRules::GetQueuedMatchmakingMode() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nQueuedMatchmakingMode");
}
void GCCSGameRules::SetQueuedMatchmakingMode(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nQueuedMatchmakingMode", false, value);
}
bool GCCSGameRules::GetIsValveDS() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsValveDS");
}
void GCCSGameRules::SetIsValveDS(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsValveDS", false, value);
}
bool GCCSGameRules::GetLogoMap() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bLogoMap");
}
void GCCSGameRules::SetLogoMap(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bLogoMap", false, value);
}
bool GCCSGameRules::GetPlayAllStepSoundsOnServer() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bPlayAllStepSoundsOnServer");
}
void GCCSGameRules::SetPlayAllStepSoundsOnServer(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bPlayAllStepSoundsOnServer", false, value);
}
int32_t GCCSGameRules::GetSpectatorSlotCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iSpectatorSlotCount");
}
void GCCSGameRules::SetSpectatorSlotCount(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iSpectatorSlotCount", false, value);
}
int32_t GCCSGameRules::GetMatchDevice() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_MatchDevice");
}
void GCCSGameRules::SetMatchDevice(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_MatchDevice", false, value);
}
bool GCCSGameRules::GetHasMatchStarted() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bHasMatchStarted");
}
void GCCSGameRules::SetHasMatchStarted(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bHasMatchStarted", false, value);
}
int32_t GCCSGameRules::GetNextMapInMapgroup() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nNextMapInMapgroup");
}
void GCCSGameRules::SetNextMapInMapgroup(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nNextMapInMapgroup", false, value);
}
std::string GCCSGameRules::GetTournamentEventName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSGameRules", "m_szTournamentEventName");
}
void GCCSGameRules::SetTournamentEventName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSGameRules", "m_szTournamentEventName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 512);
}
std::string GCCSGameRules::GetTournamentEventStage() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSGameRules", "m_szTournamentEventStage");
}
void GCCSGameRules::SetTournamentEventStage(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSGameRules", "m_szTournamentEventStage", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 512);
}
std::string GCCSGameRules::GetMatchStatTxt() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSGameRules", "m_szMatchStatTxt");
}
void GCCSGameRules::SetMatchStatTxt(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSGameRules", "m_szMatchStatTxt", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 512);
}
std::string GCCSGameRules::GetTournamentPredictionsTxt() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSGameRules", "m_szTournamentPredictionsTxt");
}
void GCCSGameRules::SetTournamentPredictionsTxt(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSGameRules", "m_szTournamentPredictionsTxt", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 512);
}
int32_t GCCSGameRules::GetTournamentPredictionsPct() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nTournamentPredictionsPct");
}
void GCCSGameRules::SetTournamentPredictionsPct(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nTournamentPredictionsPct", false, value);
}
float GCCSGameRules::GetCMMItemDropRevealStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flCMMItemDropRevealStartTime");
}
void GCCSGameRules::SetCMMItemDropRevealStartTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flCMMItemDropRevealStartTime", false, value);
}
float GCCSGameRules::GetCMMItemDropRevealEndTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flCMMItemDropRevealEndTime");
}
void GCCSGameRules::SetCMMItemDropRevealEndTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flCMMItemDropRevealEndTime", false, value);
}
bool GCCSGameRules::GetIsDroppingItems() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsDroppingItems");
}
void GCCSGameRules::SetIsDroppingItems(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsDroppingItems", false, value);
}
bool GCCSGameRules::GetIsQuestEligible() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsQuestEligible");
}
void GCCSGameRules::SetIsQuestEligible(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsQuestEligible", false, value);
}
bool GCCSGameRules::GetIsHltvActive() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsHltvActive");
}
void GCCSGameRules::SetIsHltvActive(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsHltvActive", false, value);
}
std::vector<uint16_t> GCCSGameRules::GetProhibitedItemIndices() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "CCSGameRules", "m_arrProhibitedItemIndices"); std::vector<uint16_t> ret; for(int i = 0; i < 100; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSGameRules::SetProhibitedItemIndices(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "CCSGameRules", "m_arrProhibitedItemIndices"); for(int i = 0; i < 100; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_arrProhibitedItemIndices", false, outValue);
}
std::vector<uint32_t> GCCSGameRules::GetTournamentActiveCasterAccounts() const {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSGameRules", "m_arrTournamentActiveCasterAccounts"); std::vector<uint32_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSGameRules::SetTournamentActiveCasterAccounts(std::vector<uint32_t> value) {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSGameRules", "m_arrTournamentActiveCasterAccounts"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_arrTournamentActiveCasterAccounts", false, outValue);
}
int32_t GCCSGameRules::GetNumBestOfMaps() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_numBestOfMaps");
}
void GCCSGameRules::SetNumBestOfMaps(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_numBestOfMaps", false, value);
}
int32_t GCCSGameRules::GetHalloweenMaskListSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nHalloweenMaskListSeed");
}
void GCCSGameRules::SetHalloweenMaskListSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nHalloweenMaskListSeed", false, value);
}
bool GCCSGameRules::GetBombDropped() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bBombDropped");
}
void GCCSGameRules::SetBombDropped(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bBombDropped", false, value);
}
bool GCCSGameRules::GetBombPlanted() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bBombPlanted");
}
void GCCSGameRules::SetBombPlanted(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bBombPlanted", false, value);
}
int32_t GCCSGameRules::GetRoundWinStatus() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundWinStatus");
}
void GCCSGameRules::SetRoundWinStatus(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundWinStatus", false, value);
}
int32_t GCCSGameRules::GetRoundWinReason() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_eRoundWinReason");
}
void GCCSGameRules::SetRoundWinReason(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_eRoundWinReason", false, value);
}
bool GCCSGameRules::GetTCantBuy() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bTCantBuy");
}
void GCCSGameRules::SetTCantBuy(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bTCantBuy", false, value);
}
bool GCCSGameRules::GetCTCantBuy() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bCTCantBuy");
}
void GCCSGameRules::SetCTCantBuy(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bCTCantBuy", false, value);
}
std::vector<int32_t> GCCSGameRules::GetMatchStats_RoundResults() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_RoundResults"); std::vector<int32_t> ret; for(int i = 0; i < 30; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSGameRules::SetMatchStats_RoundResults(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_RoundResults"); for(int i = 0; i < 30; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_iMatchStats_RoundResults", false, outValue);
}
std::vector<int32_t> GCCSGameRules::GetMatchStats_PlayersAlive_CT() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_CT"); std::vector<int32_t> ret; for(int i = 0; i < 30; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSGameRules::SetMatchStats_PlayersAlive_CT(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_CT"); for(int i = 0; i < 30; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_CT", false, outValue);
}
std::vector<int32_t> GCCSGameRules::GetMatchStats_PlayersAlive_T() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_T"); std::vector<int32_t> ret; for(int i = 0; i < 30; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSGameRules::SetMatchStats_PlayersAlive_T(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_T"); for(int i = 0; i < 30; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_T", false, outValue);
}
std::vector<float> GCCSGameRules::GetTeamRespawnWaveTimes() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSGameRules", "m_TeamRespawnWaveTimes"); std::vector<float> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSGameRules::SetTeamRespawnWaveTimes(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSGameRules", "m_TeamRespawnWaveTimes"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_TeamRespawnWaveTimes", false, outValue);
}
std::vector<float> GCCSGameRules::GetNextRespawnWave() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSGameRules", "m_flNextRespawnWave"); std::vector<float> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSGameRules::SetNextRespawnWave(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSGameRules", "m_flNextRespawnWave"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_flNextRespawnWave", false, outValue);
}
int32_t GCCSGameRules::GetServerQuestID() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nServerQuestID");
}
void GCCSGameRules::SetServerQuestID(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nServerQuestID", false, value);
}
Vector GCCSGameRules::GetMinimapMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSGameRules", "m_vMinimapMins");
}
void GCCSGameRules::SetMinimapMins(Vector value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_vMinimapMins", false, value);
}
Vector GCCSGameRules::GetMinimapMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSGameRules", "m_vMinimapMaxs");
}
void GCCSGameRules::SetMinimapMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_vMinimapMaxs", false, value);
}
std::vector<float> GCCSGameRules::GetMinimapVerticalSectionHeights() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSGameRules", "m_MinimapVerticalSectionHeights"); std::vector<float> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSGameRules::SetMinimapVerticalSectionHeights(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSGameRules", "m_MinimapVerticalSectionHeights"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_MinimapVerticalSectionHeights", false, outValue);
}
bool GCCSGameRules::GetSpawnedTerrorHuntHeavy() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bSpawnedTerrorHuntHeavy");
}
void GCCSGameRules::SetSpawnedTerrorHuntHeavy(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bSpawnedTerrorHuntHeavy", false, value);
}
std::vector<int32_t> GCCSGameRules::GetEndMatchMapGroupVoteTypes() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteTypes"); std::vector<int32_t> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSGameRules::SetEndMatchMapGroupVoteTypes(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteTypes"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteTypes", false, outValue);
}
std::vector<int32_t> GCCSGameRules::GetEndMatchMapGroupVoteOptions() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteOptions"); std::vector<int32_t> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSGameRules::SetEndMatchMapGroupVoteOptions(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteOptions"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteOptions", false, outValue);
}
int32_t GCCSGameRules::GetEndMatchMapVoteWinner() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nEndMatchMapVoteWinner");
}
void GCCSGameRules::SetEndMatchMapVoteWinner(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nEndMatchMapVoteWinner", false, value);
}
int32_t GCCSGameRules::GetNumConsecutiveCTLoses() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumConsecutiveCTLoses");
}
void GCCSGameRules::SetNumConsecutiveCTLoses(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumConsecutiveCTLoses", false, value);
}
int32_t GCCSGameRules::GetNumConsecutiveTerroristLoses() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumConsecutiveTerroristLoses");
}
void GCCSGameRules::SetNumConsecutiveTerroristLoses(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumConsecutiveTerroristLoses", false, value);
}
bool GCCSGameRules::GetHasHostageBeenTouched() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bHasHostageBeenTouched");
}
void GCCSGameRules::SetHasHostageBeenTouched(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bHasHostageBeenTouched", false, value);
}
float GCCSGameRules::GetIntermissionStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flIntermissionStartTime");
}
void GCCSGameRules::SetIntermissionStartTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flIntermissionStartTime", false, value);
}
float GCCSGameRules::GetIntermissionEndTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flIntermissionEndTime");
}
void GCCSGameRules::SetIntermissionEndTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flIntermissionEndTime", false, value);
}
bool GCCSGameRules::GetLevelInitialized() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bLevelInitialized");
}
void GCCSGameRules::SetLevelInitialized(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bLevelInitialized", false, value);
}
int32_t GCCSGameRules::GetTotalRoundsPlayed1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iTotalRoundsPlayed");
}
void GCCSGameRules::SetTotalRoundsPlayed1(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iTotalRoundsPlayed", false, value);
}
int32_t GCCSGameRules::GetUnBalancedRounds() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iUnBalancedRounds");
}
void GCCSGameRules::SetUnBalancedRounds(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iUnBalancedRounds", false, value);
}
bool GCCSGameRules::GetEndMatchOnRoundReset() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_endMatchOnRoundReset");
}
void GCCSGameRules::SetEndMatchOnRoundReset(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_endMatchOnRoundReset", false, value);
}
bool GCCSGameRules::GetEndMatchOnThink() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_endMatchOnThink");
}
void GCCSGameRules::SetEndMatchOnThink(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_endMatchOnThink", false, value);
}
int32_t GCCSGameRules::GetFreezeTime() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iFreezeTime");
}
void GCCSGameRules::SetFreezeTime(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iFreezeTime", false, value);
}
int32_t GCCSGameRules::GetNumTerrorist() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumTerrorist");
}
void GCCSGameRules::SetNumTerrorist(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumTerrorist", false, value);
}
int32_t GCCSGameRules::GetNumCT() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumCT");
}
void GCCSGameRules::SetNumCT(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumCT", false, value);
}
int32_t GCCSGameRules::GetNumSpawnableTerrorist() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumSpawnableTerrorist");
}
void GCCSGameRules::SetNumSpawnableTerrorist(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumSpawnableTerrorist", false, value);
}
int32_t GCCSGameRules::GetNumSpawnableCT() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumSpawnableCT");
}
void GCCSGameRules::SetNumSpawnableCT(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumSpawnableCT", false, value);
}
std::vector<int32> GCCSGameRules::GetSelectedHostageSpawnIndices() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CCSGameRules", "m_arrSelectedHostageSpawnIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSGameRules::SetSelectedHostageSpawnIndices(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CCSGameRules", "m_arrSelectedHostageSpawnIndices", false, value);
}
int32_t GCCSGameRules::GetSpawnPointsRandomSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nSpawnPointsRandomSeed");
}
void GCCSGameRules::SetSpawnPointsRandomSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nSpawnPointsRandomSeed", false, value);
}
bool GCCSGameRules::GetFirstConnected() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bFirstConnected");
}
void GCCSGameRules::SetFirstConnected(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bFirstConnected", false, value);
}
bool GCCSGameRules::GetCompleteReset() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bCompleteReset");
}
void GCCSGameRules::SetCompleteReset(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bCompleteReset", false, value);
}
bool GCCSGameRules::GetPickNewTeamsOnReset() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bPickNewTeamsOnReset");
}
void GCCSGameRules::SetPickNewTeamsOnReset(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bPickNewTeamsOnReset", false, value);
}
bool GCCSGameRules::GetScrambleTeamsOnRestart() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bScrambleTeamsOnRestart");
}
void GCCSGameRules::SetScrambleTeamsOnRestart(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bScrambleTeamsOnRestart", false, value);
}
bool GCCSGameRules::GetSwapTeamsOnRestart() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bSwapTeamsOnRestart");
}
void GCCSGameRules::SetSwapTeamsOnRestart(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bSwapTeamsOnRestart", false, value);
}
std::vector<int32> GCCSGameRules::GetEndMatchTiedVotes() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CCSGameRules", "m_nEndMatchTiedVotes"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSGameRules::SetEndMatchTiedVotes(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CCSGameRules", "m_nEndMatchTiedVotes", false, value);
}
bool GCCSGameRules::GetNeedToAskPlayersForContinueVote() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bNeedToAskPlayersForContinueVote");
}
void GCCSGameRules::SetNeedToAskPlayersForContinueVote(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bNeedToAskPlayersForContinueVote", false, value);
}
uint32_t GCCSGameRules::GetNumQueuedMatchmakingAccounts() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSGameRules", "m_numQueuedMatchmakingAccounts");
}
void GCCSGameRules::SetNumQueuedMatchmakingAccounts(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_numQueuedMatchmakingAccounts", false, value);
}
float GCCSGameRules::GetAvgPlayerRank() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fAvgPlayerRank");
}
void GCCSGameRules::SetAvgPlayerRank(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_fAvgPlayerRank", false, value);
}
std::string GCCSGameRules::GetQueuedMatchmakingReservationString() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSGameRules", "m_pQueuedMatchmakingReservationString");
}
void GCCSGameRules::SetQueuedMatchmakingReservationString(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSGameRules", "m_pQueuedMatchmakingReservationString", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
uint32_t GCCSGameRules::GetNumTotalTournamentDrops() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSGameRules", "m_numTotalTournamentDrops");
}
void GCCSGameRules::SetNumTotalTournamentDrops(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_numTotalTournamentDrops", false, value);
}
uint32_t GCCSGameRules::GetNumSpectatorsCountMax() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSGameRules", "m_numSpectatorsCountMax");
}
void GCCSGameRules::SetNumSpectatorsCountMax(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_numSpectatorsCountMax", false, value);
}
uint32_t GCCSGameRules::GetNumSpectatorsCountMaxTV() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSGameRules", "m_numSpectatorsCountMaxTV");
}
void GCCSGameRules::SetNumSpectatorsCountMaxTV(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_numSpectatorsCountMaxTV", false, value);
}
uint32_t GCCSGameRules::GetNumSpectatorsCountMaxLnk() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSGameRules", "m_numSpectatorsCountMaxLnk");
}
void GCCSGameRules::SetNumSpectatorsCountMaxLnk(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_numSpectatorsCountMaxLnk", false, value);
}
bool GCCSGameRules::GetForceTeamChangeSilent() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bForceTeamChangeSilent");
}
void GCCSGameRules::SetForceTeamChangeSilent(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bForceTeamChangeSilent", false, value);
}
bool GCCSGameRules::GetLoadingRoundBackupData() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bLoadingRoundBackupData");
}
void GCCSGameRules::SetLoadingRoundBackupData(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bLoadingRoundBackupData", false, value);
}
int32_t GCCSGameRules::GetMatchInfoShowType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nMatchInfoShowType");
}
void GCCSGameRules::SetMatchInfoShowType(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nMatchInfoShowType", false, value);
}
float GCCSGameRules::GetMatchInfoDecidedTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flMatchInfoDecidedTime");
}
void GCCSGameRules::SetMatchInfoDecidedTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flMatchInfoDecidedTime", false, value);
}
int32_t GCCSGameRules::GetMTeamDMLastWinningTeamNumber() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "mTeamDMLastWinningTeamNumber");
}
void GCCSGameRules::SetMTeamDMLastWinningTeamNumber(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "mTeamDMLastWinningTeamNumber", false, value);
}
float GCCSGameRules::GetMTeamDMLastThinkTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "mTeamDMLastThinkTime");
}
void GCCSGameRules::SetMTeamDMLastThinkTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "mTeamDMLastThinkTime", false, value);
}
float GCCSGameRules::GetTeamDMLastAnnouncementTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flTeamDMLastAnnouncementTime");
}
void GCCSGameRules::SetTeamDMLastAnnouncementTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flTeamDMLastAnnouncementTime", false, value);
}
int32_t GCCSGameRules::GetAccountTerrorist() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iAccountTerrorist");
}
void GCCSGameRules::SetAccountTerrorist(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iAccountTerrorist", false, value);
}
int32_t GCCSGameRules::GetAccountCT() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iAccountCT");
}
void GCCSGameRules::SetAccountCT(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iAccountCT", false, value);
}
int32_t GCCSGameRules::GetSpawnPointCount_Terrorist() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iSpawnPointCount_Terrorist");
}
void GCCSGameRules::SetSpawnPointCount_Terrorist(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iSpawnPointCount_Terrorist", false, value);
}
int32_t GCCSGameRules::GetSpawnPointCount_CT() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iSpawnPointCount_CT");
}
void GCCSGameRules::SetSpawnPointCount_CT(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iSpawnPointCount_CT", false, value);
}
int32_t GCCSGameRules::GetMaxNumTerrorists() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iMaxNumTerrorists");
}
void GCCSGameRules::SetMaxNumTerrorists(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iMaxNumTerrorists", false, value);
}
int32_t GCCSGameRules::GetMaxNumCTs() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iMaxNumCTs");
}
void GCCSGameRules::SetMaxNumCTs(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iMaxNumCTs", false, value);
}
int32_t GCCSGameRules::GetLoserBonusMostRecentTeam() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iLoserBonusMostRecentTeam");
}
void GCCSGameRules::SetLoserBonusMostRecentTeam(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iLoserBonusMostRecentTeam", false, value);
}
float GCCSGameRules::GetTmNextPeriodicThink() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_tmNextPeriodicThink");
}
void GCCSGameRules::SetTmNextPeriodicThink(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_tmNextPeriodicThink", false, value);
}
bool GCCSGameRules::GetVoiceWonMatchBragFired() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bVoiceWonMatchBragFired");
}
void GCCSGameRules::SetVoiceWonMatchBragFired(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bVoiceWonMatchBragFired", false, value);
}
float GCCSGameRules::GetWarmupNextChatNoticeTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fWarmupNextChatNoticeTime");
}
void GCCSGameRules::SetWarmupNextChatNoticeTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_fWarmupNextChatNoticeTime", false, value);
}
int32_t GCCSGameRules::GetHostagesRescued() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iHostagesRescued");
}
void GCCSGameRules::SetHostagesRescued(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iHostagesRescued", false, value);
}
int32_t GCCSGameRules::GetHostagesTouched() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iHostagesTouched");
}
void GCCSGameRules::SetHostagesTouched(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iHostagesTouched", false, value);
}
float GCCSGameRules::GetNextHostageAnnouncement() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flNextHostageAnnouncement");
}
void GCCSGameRules::SetNextHostageAnnouncement(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flNextHostageAnnouncement", false, value);
}
bool GCCSGameRules::GetNoTerroristsKilled() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bNoTerroristsKilled");
}
void GCCSGameRules::SetNoTerroristsKilled(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bNoTerroristsKilled", false, value);
}
bool GCCSGameRules::GetNoCTsKilled() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bNoCTsKilled");
}
void GCCSGameRules::SetNoCTsKilled(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bNoCTsKilled", false, value);
}
bool GCCSGameRules::GetNoEnemiesKilled() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bNoEnemiesKilled");
}
void GCCSGameRules::SetNoEnemiesKilled(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bNoEnemiesKilled", false, value);
}
bool GCCSGameRules::GetCanDonateWeapons() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bCanDonateWeapons");
}
void GCCSGameRules::SetCanDonateWeapons(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bCanDonateWeapons", false, value);
}
float GCCSGameRules::GetFirstKillTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_firstKillTime");
}
void GCCSGameRules::SetFirstKillTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_firstKillTime", false, value);
}
float GCCSGameRules::GetFirstBloodTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_firstBloodTime");
}
void GCCSGameRules::SetFirstBloodTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_firstBloodTime", false, value);
}
bool GCCSGameRules::GetHostageWasInjured() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_hostageWasInjured");
}
void GCCSGameRules::SetHostageWasInjured(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_hostageWasInjured", false, value);
}
bool GCCSGameRules::GetHostageWasKilled() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_hostageWasKilled");
}
void GCCSGameRules::SetHostageWasKilled(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_hostageWasKilled", false, value);
}
bool GCCSGameRules::GetVoteCalled() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bVoteCalled");
}
void GCCSGameRules::SetVoteCalled(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bVoteCalled", false, value);
}
bool GCCSGameRules::GetServerVoteOnReset() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bServerVoteOnReset");
}
void GCCSGameRules::SetServerVoteOnReset(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bServerVoteOnReset", false, value);
}
float GCCSGameRules::GetVoteCheckThrottle() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flVoteCheckThrottle");
}
void GCCSGameRules::SetVoteCheckThrottle(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flVoteCheckThrottle", false, value);
}
bool GCCSGameRules::GetBuyTimeEnded() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bBuyTimeEnded");
}
void GCCSGameRules::SetBuyTimeEnded(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bBuyTimeEnded", false, value);
}
int32_t GCCSGameRules::GetLastFreezeEndBeep() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nLastFreezeEndBeep");
}
void GCCSGameRules::SetLastFreezeEndBeep(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nLastFreezeEndBeep", false, value);
}
bool GCCSGameRules::GetTargetBombed() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bTargetBombed");
}
void GCCSGameRules::SetTargetBombed(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bTargetBombed", false, value);
}
bool GCCSGameRules::GetBombDefused() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bBombDefused");
}
void GCCSGameRules::SetBombDefused(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bBombDefused", false, value);
}
bool GCCSGameRules::GetMapHasBombZone() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bMapHasBombZone");
}
void GCCSGameRules::SetMapHasBombZone(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bMapHasBombZone", false, value);
}
Vector GCCSGameRules::GetMainCTSpawnPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSGameRules", "m_vecMainCTSpawnPos");
}
void GCCSGameRules::SetMainCTSpawnPos(Vector value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_vecMainCTSpawnPos", false, value);
}
std::vector<GSpawnPoint*> GCCSGameRules::GetCTSpawnPointsMasterList() const {
    CUtlVector<GSpawnPoint*>* vec = GetSchemaValue<CUtlVector<GSpawnPoint*>*>(m_ptr, "CCSGameRules", "m_CTSpawnPointsMasterList"); std::vector<GSpawnPoint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSGameRules::SetCTSpawnPointsMasterList(std::vector<GSpawnPoint*> value) {
    SetSchemaValueCUtlVector<GSpawnPoint*>(m_ptr, "CCSGameRules", "m_CTSpawnPointsMasterList", false, value);
}
std::vector<GSpawnPoint*> GCCSGameRules::GetTerroristSpawnPointsMasterList() const {
    CUtlVector<GSpawnPoint*>* vec = GetSchemaValue<CUtlVector<GSpawnPoint*>*>(m_ptr, "CCSGameRules", "m_TerroristSpawnPointsMasterList"); std::vector<GSpawnPoint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSGameRules::SetTerroristSpawnPointsMasterList(std::vector<GSpawnPoint*> value) {
    SetSchemaValueCUtlVector<GSpawnPoint*>(m_ptr, "CCSGameRules", "m_TerroristSpawnPointsMasterList", false, value);
}
bool GCCSGameRules::GetRespawningAllRespawnablePlayers() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bRespawningAllRespawnablePlayers");
}
void GCCSGameRules::SetRespawningAllRespawnablePlayers(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bRespawningAllRespawnablePlayers", false, value);
}
int32_t GCCSGameRules::GetNextCTSpawnPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNextCTSpawnPoint");
}
void GCCSGameRules::SetNextCTSpawnPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iNextCTSpawnPoint", false, value);
}
float GCCSGameRules::GetCTSpawnPointUsedTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flCTSpawnPointUsedTime");
}
void GCCSGameRules::SetCTSpawnPointUsedTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flCTSpawnPointUsedTime", false, value);
}
int32_t GCCSGameRules::GetNextTerroristSpawnPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNextTerroristSpawnPoint");
}
void GCCSGameRules::SetNextTerroristSpawnPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iNextTerroristSpawnPoint", false, value);
}
float GCCSGameRules::GetTerroristSpawnPointUsedTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flTerroristSpawnPointUsedTime");
}
void GCCSGameRules::SetTerroristSpawnPointUsedTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flTerroristSpawnPointUsedTime", false, value);
}
std::vector<GSpawnPoint*> GCCSGameRules::GetCTSpawnPoints() const {
    CUtlVector<GSpawnPoint*>* vec = GetSchemaValue<CUtlVector<GSpawnPoint*>*>(m_ptr, "CCSGameRules", "m_CTSpawnPoints"); std::vector<GSpawnPoint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSGameRules::SetCTSpawnPoints(std::vector<GSpawnPoint*> value) {
    SetSchemaValueCUtlVector<GSpawnPoint*>(m_ptr, "CCSGameRules", "m_CTSpawnPoints", false, value);
}
std::vector<GSpawnPoint*> GCCSGameRules::GetTerroristSpawnPoints() const {
    CUtlVector<GSpawnPoint*>* vec = GetSchemaValue<CUtlVector<GSpawnPoint*>*>(m_ptr, "CCSGameRules", "m_TerroristSpawnPoints"); std::vector<GSpawnPoint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSGameRules::SetTerroristSpawnPoints(std::vector<GSpawnPoint*> value) {
    SetSchemaValueCUtlVector<GSpawnPoint*>(m_ptr, "CCSGameRules", "m_TerroristSpawnPoints", false, value);
}
bool GCCSGameRules::GetIsUnreservedGameServer() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsUnreservedGameServer");
}
void GCCSGameRules::SetIsUnreservedGameServer(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsUnreservedGameServer", false, value);
}
float GCCSGameRules::GetAutobalanceDisplayTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fAutobalanceDisplayTime");
}
void GCCSGameRules::SetAutobalanceDisplayTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_fAutobalanceDisplayTime", false, value);
}
bool GCCSGameRules::GetAllowWeaponSwitch() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bAllowWeaponSwitch");
}
void GCCSGameRules::SetAllowWeaponSwitch(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bAllowWeaponSwitch", false, value);
}
bool GCCSGameRules::GetRoundTimeWarningTriggered() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bRoundTimeWarningTriggered");
}
void GCCSGameRules::SetRoundTimeWarningTriggered(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bRoundTimeWarningTriggered", false, value);
}
float GCCSGameRules::GetPhaseChangeAnnouncementTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_phaseChangeAnnouncementTime");
}
void GCCSGameRules::SetPhaseChangeAnnouncementTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_phaseChangeAnnouncementTime", false, value);
}
float GCCSGameRules::GetNextUpdateTeamClanNamesTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fNextUpdateTeamClanNamesTime");
}
void GCCSGameRules::SetNextUpdateTeamClanNamesTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_fNextUpdateTeamClanNamesTime", false, value);
}
float GCCSGameRules::GetLastThinkTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flLastThinkTime");
}
void GCCSGameRules::SetLastThinkTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flLastThinkTime", false, value);
}
float GCCSGameRules::GetAccumulatedRoundOffDamage() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fAccumulatedRoundOffDamage");
}
void GCCSGameRules::SetAccumulatedRoundOffDamage(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_fAccumulatedRoundOffDamage", false, value);
}
int32_t GCCSGameRules::GetShorthandedBonusLastEvalRound() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nShorthandedBonusLastEvalRound");
}
void GCCSGameRules::SetShorthandedBonusLastEvalRound(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nShorthandedBonusLastEvalRound", false, value);
}
int32_t GCCSGameRules::GetMatchAbortedEarlyReason() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nMatchAbortedEarlyReason");
}
void GCCSGameRules::SetMatchAbortedEarlyReason(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nMatchAbortedEarlyReason", false, value);
}
bool GCCSGameRules::GetHasTriggeredRoundStartMusic() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bHasTriggeredRoundStartMusic");
}
void GCCSGameRules::SetHasTriggeredRoundStartMusic(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bHasTriggeredRoundStartMusic", false, value);
}
bool GCCSGameRules::GetSwitchingTeamsAtRoundReset() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bSwitchingTeamsAtRoundReset");
}
void GCCSGameRules::SetSwitchingTeamsAtRoundReset(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bSwitchingTeamsAtRoundReset", false, value);
}
GCCSGameModeRules GCCSGameRules::GetGameModeRules() const {
    GCCSGameModeRules value(*GetSchemaValuePtr<void*>(m_ptr, "CCSGameRules", "m_pGameModeRules"));
    return value;
}
void GCCSGameRules::SetGameModeRules(GCCSGameModeRules* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'GameModeRules' is not possible.\n");
}
GCBaseEntity GCCSGameRules::GetPlayerResource() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CCSGameRules", "m_hPlayerResource"));
    return value;
}
void GCCSGameRules::SetPlayerResource(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerResource' is not possible.\n");
}
GCRetakeGameRules GCCSGameRules::GetRetakeRules() const {
    GCRetakeGameRules value(GetSchemaPtr(m_ptr, "CCSGameRules", "m_RetakeRules"));
    return value;
}
void GCCSGameRules::SetRetakeRules(GCRetakeGameRules value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_RetakeRules", false, value);
}
std::vector<bool> GCCSGameRules::GetTeamLastKillUsedUniqueWeaponMatch() const {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSGameRules", "m_bTeamLastKillUsedUniqueWeaponMatch"); std::vector<bool> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSGameRules::SetTeamLastKillUsedUniqueWeaponMatch(std::vector<bool> value) {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSGameRules", "m_bTeamLastKillUsedUniqueWeaponMatch"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_bTeamLastKillUsedUniqueWeaponMatch", false, outValue);
}
uint8_t GCCSGameRules::GetMatchEndCount() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSGameRules", "m_nMatchEndCount");
}
void GCCSGameRules::SetMatchEndCount(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nMatchEndCount", false, value);
}
int32_t GCCSGameRules::GetTTeamIntroVariant() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nTTeamIntroVariant");
}
void GCCSGameRules::SetTTeamIntroVariant(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nTTeamIntroVariant", false, value);
}
int32_t GCCSGameRules::GetCTTeamIntroVariant() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nCTTeamIntroVariant");
}
void GCCSGameRules::SetCTTeamIntroVariant(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nCTTeamIntroVariant", false, value);
}
bool GCCSGameRules::GetTeamIntroPeriod() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bTeamIntroPeriod");
}
void GCCSGameRules::SetTeamIntroPeriod(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bTeamIntroPeriod", false, value);
}
float GCCSGameRules::GetTeamIntroPeriodEnd() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fTeamIntroPeriodEnd");
}
void GCCSGameRules::SetTeamIntroPeriodEnd(float value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_fTeamIntroPeriodEnd", false, value);
}
bool GCCSGameRules::GetPlayedTeamIntroVO() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bPlayedTeamIntroVO");
}
void GCCSGameRules::SetPlayedTeamIntroVO(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bPlayedTeamIntroVO", false, value);
}
int32_t GCCSGameRules::GetRoundEndWinnerTeam() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndWinnerTeam");
}
void GCCSGameRules::SetRoundEndWinnerTeam(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndWinnerTeam", false, value);
}
int32_t GCCSGameRules::GetRoundEndReason() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_eRoundEndReason");
}
void GCCSGameRules::SetRoundEndReason(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_eRoundEndReason", false, value);
}
bool GCCSGameRules::GetRoundEndShowTimerDefend() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bRoundEndShowTimerDefend");
}
void GCCSGameRules::SetRoundEndShowTimerDefend(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bRoundEndShowTimerDefend", false, value);
}
int32_t GCCSGameRules::GetRoundEndTimerTime() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndTimerTime");
}
void GCCSGameRules::SetRoundEndTimerTime(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndTimerTime", false, value);
}
std::string GCCSGameRules::GetRoundEndFunFactToken() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CCSGameRules", "m_sRoundEndFunFactToken").Get();
}
void GCCSGameRules::SetRoundEndFunFactToken(std::string value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_sRoundEndFunFactToken", false, CUtlString(value.c_str()));
}
int32_t GCCSGameRules::GetRoundEndFunFactPlayerSlot() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndFunFactPlayerSlot");
}
void GCCSGameRules::SetRoundEndFunFactPlayerSlot(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndFunFactPlayerSlot", false, value);
}
int32_t GCCSGameRules::GetRoundEndFunFactData1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData1");
}
void GCCSGameRules::SetRoundEndFunFactData1(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData1", false, value);
}
int32_t GCCSGameRules::GetRoundEndFunFactData2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData2");
}
void GCCSGameRules::SetRoundEndFunFactData2(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData2", false, value);
}
int32_t GCCSGameRules::GetRoundEndFunFactData3() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData3");
}
void GCCSGameRules::SetRoundEndFunFactData3(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData3", false, value);
}
std::string GCCSGameRules::GetRoundEndMessage() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CCSGameRules", "m_sRoundEndMessage").Get();
}
void GCCSGameRules::SetRoundEndMessage(std::string value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_sRoundEndMessage", false, CUtlString(value.c_str()));
}
int32_t GCCSGameRules::GetRoundEndPlayerCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndPlayerCount");
}
void GCCSGameRules::SetRoundEndPlayerCount(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndPlayerCount", false, value);
}
bool GCCSGameRules::GetRoundEndNoMusic() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bRoundEndNoMusic");
}
void GCCSGameRules::SetRoundEndNoMusic(bool value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_bRoundEndNoMusic", false, value);
}
int32_t GCCSGameRules::GetRoundEndLegacy() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndLegacy");
}
void GCCSGameRules::SetRoundEndLegacy(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndLegacy", false, value);
}
uint8_t GCCSGameRules::GetRoundEndCount() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSGameRules", "m_nRoundEndCount");
}
void GCCSGameRules::SetRoundEndCount(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nRoundEndCount", false, value);
}
int32_t GCCSGameRules::GetRoundStartRoundNumber() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundStartRoundNumber");
}
void GCCSGameRules::SetRoundStartRoundNumber(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundStartRoundNumber", false, value);
}
uint8_t GCCSGameRules::GetRoundStartCount() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSGameRules", "m_nRoundStartCount");
}
void GCCSGameRules::SetRoundStartCount(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_nRoundStartCount", false, value);
}
double GCCSGameRules::GetLastPerfSampleTime() const {
    return GetSchemaValue<double>(m_ptr, "CCSGameRules", "m_flLastPerfSampleTime");
}
void GCCSGameRules::SetLastPerfSampleTime(double value) {
    SetSchemaValue(m_ptr, "CCSGameRules", "m_flLastPerfSampleTime", false, value);
}
std::string GCCSGameRules::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGameRules::IsValid() {
    return (m_ptr != nullptr);
}
GCTeamplayRules GCCSGameRules::GetParent() const {
    GCTeamplayRules value(m_ptr);
    return value;
}
void GCCSGameRules::SetParent(GCTeamplayRules value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGameRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGameRules>("CCSGameRules")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FreezePeriod", &GCCSGameRules::GetFreezePeriod, &GCCSGameRules::SetFreezePeriod)
        .addProperty("WarmupPeriod", &GCCSGameRules::GetWarmupPeriod, &GCCSGameRules::SetWarmupPeriod)
        .addProperty("WarmupPeriodEnd", &GCCSGameRules::GetWarmupPeriodEnd, &GCCSGameRules::SetWarmupPeriodEnd)
        .addProperty("WarmupPeriodStart", &GCCSGameRules::GetWarmupPeriodStart, &GCCSGameRules::SetWarmupPeriodStart)
        .addProperty("ServerPaused", &GCCSGameRules::GetServerPaused, &GCCSGameRules::SetServerPaused)
        .addProperty("TerroristTimeOutActive", &GCCSGameRules::GetTerroristTimeOutActive, &GCCSGameRules::SetTerroristTimeOutActive)
        .addProperty("CTTimeOutActive", &GCCSGameRules::GetCTTimeOutActive, &GCCSGameRules::SetCTTimeOutActive)
        .addProperty("TerroristTimeOutRemaining", &GCCSGameRules::GetTerroristTimeOutRemaining, &GCCSGameRules::SetTerroristTimeOutRemaining)
        .addProperty("CTTimeOutRemaining", &GCCSGameRules::GetCTTimeOutRemaining, &GCCSGameRules::SetCTTimeOutRemaining)
        .addProperty("TerroristTimeOuts", &GCCSGameRules::GetTerroristTimeOuts, &GCCSGameRules::SetTerroristTimeOuts)
        .addProperty("CTTimeOuts", &GCCSGameRules::GetCTTimeOuts, &GCCSGameRules::SetCTTimeOuts)
        .addProperty("TechnicalTimeOut", &GCCSGameRules::GetTechnicalTimeOut, &GCCSGameRules::SetTechnicalTimeOut)
        .addProperty("MatchWaitingForResume", &GCCSGameRules::GetMatchWaitingForResume, &GCCSGameRules::SetMatchWaitingForResume)
        .addProperty("RoundTime", &GCCSGameRules::GetRoundTime, &GCCSGameRules::SetRoundTime)
        .addProperty("MatchStartTime", &GCCSGameRules::GetMatchStartTime, &GCCSGameRules::SetMatchStartTime)
        .addProperty("RoundStartTime", &GCCSGameRules::GetRoundStartTime, &GCCSGameRules::SetRoundStartTime)
        .addProperty("RestartRoundTime", &GCCSGameRules::GetRestartRoundTime, &GCCSGameRules::SetRestartRoundTime)
        .addProperty("GameRestart", &GCCSGameRules::GetGameRestart, &GCCSGameRules::SetGameRestart)
        .addProperty("GameStartTime", &GCCSGameRules::GetGameStartTime, &GCCSGameRules::SetGameStartTime)
        .addProperty("TimeUntilNextPhaseStarts", &GCCSGameRules::GetTimeUntilNextPhaseStarts, &GCCSGameRules::SetTimeUntilNextPhaseStarts)
        .addProperty("GamePhase", &GCCSGameRules::GetGamePhase, &GCCSGameRules::SetGamePhase)
        .addProperty("TotalRoundsPlayed", &GCCSGameRules::GetTotalRoundsPlayed, &GCCSGameRules::SetTotalRoundsPlayed)
        .addProperty("RoundsPlayedThisPhase", &GCCSGameRules::GetRoundsPlayedThisPhase, &GCCSGameRules::SetRoundsPlayedThisPhase)
        .addProperty("OvertimePlaying", &GCCSGameRules::GetOvertimePlaying, &GCCSGameRules::SetOvertimePlaying)
        .addProperty("HostagesRemaining", &GCCSGameRules::GetHostagesRemaining, &GCCSGameRules::SetHostagesRemaining)
        .addProperty("AnyHostageReached", &GCCSGameRules::GetAnyHostageReached, &GCCSGameRules::SetAnyHostageReached)
        .addProperty("MapHasBombTarget", &GCCSGameRules::GetMapHasBombTarget, &GCCSGameRules::SetMapHasBombTarget)
        .addProperty("MapHasRescueZone", &GCCSGameRules::GetMapHasRescueZone, &GCCSGameRules::SetMapHasRescueZone)
        .addProperty("MapHasBuyZone", &GCCSGameRules::GetMapHasBuyZone, &GCCSGameRules::SetMapHasBuyZone)
        .addProperty("IsQueuedMatchmaking", &GCCSGameRules::GetIsQueuedMatchmaking, &GCCSGameRules::SetIsQueuedMatchmaking)
        .addProperty("QueuedMatchmakingMode", &GCCSGameRules::GetQueuedMatchmakingMode, &GCCSGameRules::SetQueuedMatchmakingMode)
        .addProperty("IsValveDS", &GCCSGameRules::GetIsValveDS, &GCCSGameRules::SetIsValveDS)
        .addProperty("LogoMap", &GCCSGameRules::GetLogoMap, &GCCSGameRules::SetLogoMap)
        .addProperty("PlayAllStepSoundsOnServer", &GCCSGameRules::GetPlayAllStepSoundsOnServer, &GCCSGameRules::SetPlayAllStepSoundsOnServer)
        .addProperty("SpectatorSlotCount", &GCCSGameRules::GetSpectatorSlotCount, &GCCSGameRules::SetSpectatorSlotCount)
        .addProperty("MatchDevice", &GCCSGameRules::GetMatchDevice, &GCCSGameRules::SetMatchDevice)
        .addProperty("HasMatchStarted", &GCCSGameRules::GetHasMatchStarted, &GCCSGameRules::SetHasMatchStarted)
        .addProperty("NextMapInMapgroup", &GCCSGameRules::GetNextMapInMapgroup, &GCCSGameRules::SetNextMapInMapgroup)
        .addProperty("TournamentEventName", &GCCSGameRules::GetTournamentEventName, &GCCSGameRules::SetTournamentEventName)
        .addProperty("TournamentEventStage", &GCCSGameRules::GetTournamentEventStage, &GCCSGameRules::SetTournamentEventStage)
        .addProperty("MatchStatTxt", &GCCSGameRules::GetMatchStatTxt, &GCCSGameRules::SetMatchStatTxt)
        .addProperty("TournamentPredictionsTxt", &GCCSGameRules::GetTournamentPredictionsTxt, &GCCSGameRules::SetTournamentPredictionsTxt)
        .addProperty("TournamentPredictionsPct", &GCCSGameRules::GetTournamentPredictionsPct, &GCCSGameRules::SetTournamentPredictionsPct)
        .addProperty("CMMItemDropRevealStartTime", &GCCSGameRules::GetCMMItemDropRevealStartTime, &GCCSGameRules::SetCMMItemDropRevealStartTime)
        .addProperty("CMMItemDropRevealEndTime", &GCCSGameRules::GetCMMItemDropRevealEndTime, &GCCSGameRules::SetCMMItemDropRevealEndTime)
        .addProperty("IsDroppingItems", &GCCSGameRules::GetIsDroppingItems, &GCCSGameRules::SetIsDroppingItems)
        .addProperty("IsQuestEligible", &GCCSGameRules::GetIsQuestEligible, &GCCSGameRules::SetIsQuestEligible)
        .addProperty("IsHltvActive", &GCCSGameRules::GetIsHltvActive, &GCCSGameRules::SetIsHltvActive)
        .addProperty("ProhibitedItemIndices", &GCCSGameRules::GetProhibitedItemIndices, &GCCSGameRules::SetProhibitedItemIndices)
        .addProperty("TournamentActiveCasterAccounts", &GCCSGameRules::GetTournamentActiveCasterAccounts, &GCCSGameRules::SetTournamentActiveCasterAccounts)
        .addProperty("NumBestOfMaps", &GCCSGameRules::GetNumBestOfMaps, &GCCSGameRules::SetNumBestOfMaps)
        .addProperty("HalloweenMaskListSeed", &GCCSGameRules::GetHalloweenMaskListSeed, &GCCSGameRules::SetHalloweenMaskListSeed)
        .addProperty("BombDropped", &GCCSGameRules::GetBombDropped, &GCCSGameRules::SetBombDropped)
        .addProperty("BombPlanted", &GCCSGameRules::GetBombPlanted, &GCCSGameRules::SetBombPlanted)
        .addProperty("RoundWinStatus", &GCCSGameRules::GetRoundWinStatus, &GCCSGameRules::SetRoundWinStatus)
        .addProperty("RoundWinReason", &GCCSGameRules::GetRoundWinReason, &GCCSGameRules::SetRoundWinReason)
        .addProperty("TCantBuy", &GCCSGameRules::GetTCantBuy, &GCCSGameRules::SetTCantBuy)
        .addProperty("CTCantBuy", &GCCSGameRules::GetCTCantBuy, &GCCSGameRules::SetCTCantBuy)
        .addProperty("MatchStats_RoundResults", &GCCSGameRules::GetMatchStats_RoundResults, &GCCSGameRules::SetMatchStats_RoundResults)
        .addProperty("MatchStats_PlayersAlive_CT", &GCCSGameRules::GetMatchStats_PlayersAlive_CT, &GCCSGameRules::SetMatchStats_PlayersAlive_CT)
        .addProperty("MatchStats_PlayersAlive_T", &GCCSGameRules::GetMatchStats_PlayersAlive_T, &GCCSGameRules::SetMatchStats_PlayersAlive_T)
        .addProperty("TeamRespawnWaveTimes", &GCCSGameRules::GetTeamRespawnWaveTimes, &GCCSGameRules::SetTeamRespawnWaveTimes)
        .addProperty("NextRespawnWave", &GCCSGameRules::GetNextRespawnWave, &GCCSGameRules::SetNextRespawnWave)
        .addProperty("ServerQuestID", &GCCSGameRules::GetServerQuestID, &GCCSGameRules::SetServerQuestID)
        .addProperty("MinimapMins", &GCCSGameRules::GetMinimapMins, &GCCSGameRules::SetMinimapMins)
        .addProperty("MinimapMaxs", &GCCSGameRules::GetMinimapMaxs, &GCCSGameRules::SetMinimapMaxs)
        .addProperty("MinimapVerticalSectionHeights", &GCCSGameRules::GetMinimapVerticalSectionHeights, &GCCSGameRules::SetMinimapVerticalSectionHeights)
        .addProperty("SpawnedTerrorHuntHeavy", &GCCSGameRules::GetSpawnedTerrorHuntHeavy, &GCCSGameRules::SetSpawnedTerrorHuntHeavy)
        .addProperty("EndMatchMapGroupVoteTypes", &GCCSGameRules::GetEndMatchMapGroupVoteTypes, &GCCSGameRules::SetEndMatchMapGroupVoteTypes)
        .addProperty("EndMatchMapGroupVoteOptions", &GCCSGameRules::GetEndMatchMapGroupVoteOptions, &GCCSGameRules::SetEndMatchMapGroupVoteOptions)
        .addProperty("EndMatchMapVoteWinner", &GCCSGameRules::GetEndMatchMapVoteWinner, &GCCSGameRules::SetEndMatchMapVoteWinner)
        .addProperty("NumConsecutiveCTLoses", &GCCSGameRules::GetNumConsecutiveCTLoses, &GCCSGameRules::SetNumConsecutiveCTLoses)
        .addProperty("NumConsecutiveTerroristLoses", &GCCSGameRules::GetNumConsecutiveTerroristLoses, &GCCSGameRules::SetNumConsecutiveTerroristLoses)
        .addProperty("HasHostageBeenTouched", &GCCSGameRules::GetHasHostageBeenTouched, &GCCSGameRules::SetHasHostageBeenTouched)
        .addProperty("IntermissionStartTime", &GCCSGameRules::GetIntermissionStartTime, &GCCSGameRules::SetIntermissionStartTime)
        .addProperty("IntermissionEndTime", &GCCSGameRules::GetIntermissionEndTime, &GCCSGameRules::SetIntermissionEndTime)
        .addProperty("LevelInitialized", &GCCSGameRules::GetLevelInitialized, &GCCSGameRules::SetLevelInitialized)
        .addProperty("TotalRoundsPlayed1", &GCCSGameRules::GetTotalRoundsPlayed1, &GCCSGameRules::SetTotalRoundsPlayed1)
        .addProperty("UnBalancedRounds", &GCCSGameRules::GetUnBalancedRounds, &GCCSGameRules::SetUnBalancedRounds)
        .addProperty("EndMatchOnRoundReset", &GCCSGameRules::GetEndMatchOnRoundReset, &GCCSGameRules::SetEndMatchOnRoundReset)
        .addProperty("EndMatchOnThink", &GCCSGameRules::GetEndMatchOnThink, &GCCSGameRules::SetEndMatchOnThink)
        .addProperty("FreezeTime", &GCCSGameRules::GetFreezeTime, &GCCSGameRules::SetFreezeTime)
        .addProperty("NumTerrorist", &GCCSGameRules::GetNumTerrorist, &GCCSGameRules::SetNumTerrorist)
        .addProperty("NumCT", &GCCSGameRules::GetNumCT, &GCCSGameRules::SetNumCT)
        .addProperty("NumSpawnableTerrorist", &GCCSGameRules::GetNumSpawnableTerrorist, &GCCSGameRules::SetNumSpawnableTerrorist)
        .addProperty("NumSpawnableCT", &GCCSGameRules::GetNumSpawnableCT, &GCCSGameRules::SetNumSpawnableCT)
        .addProperty("SelectedHostageSpawnIndices", &GCCSGameRules::GetSelectedHostageSpawnIndices, &GCCSGameRules::SetSelectedHostageSpawnIndices)
        .addProperty("SpawnPointsRandomSeed", &GCCSGameRules::GetSpawnPointsRandomSeed, &GCCSGameRules::SetSpawnPointsRandomSeed)
        .addProperty("FirstConnected", &GCCSGameRules::GetFirstConnected, &GCCSGameRules::SetFirstConnected)
        .addProperty("CompleteReset", &GCCSGameRules::GetCompleteReset, &GCCSGameRules::SetCompleteReset)
        .addProperty("PickNewTeamsOnReset", &GCCSGameRules::GetPickNewTeamsOnReset, &GCCSGameRules::SetPickNewTeamsOnReset)
        .addProperty("ScrambleTeamsOnRestart", &GCCSGameRules::GetScrambleTeamsOnRestart, &GCCSGameRules::SetScrambleTeamsOnRestart)
        .addProperty("SwapTeamsOnRestart", &GCCSGameRules::GetSwapTeamsOnRestart, &GCCSGameRules::SetSwapTeamsOnRestart)
        .addProperty("EndMatchTiedVotes", &GCCSGameRules::GetEndMatchTiedVotes, &GCCSGameRules::SetEndMatchTiedVotes)
        .addProperty("NeedToAskPlayersForContinueVote", &GCCSGameRules::GetNeedToAskPlayersForContinueVote, &GCCSGameRules::SetNeedToAskPlayersForContinueVote)
        .addProperty("NumQueuedMatchmakingAccounts", &GCCSGameRules::GetNumQueuedMatchmakingAccounts, &GCCSGameRules::SetNumQueuedMatchmakingAccounts)
        .addProperty("AvgPlayerRank", &GCCSGameRules::GetAvgPlayerRank, &GCCSGameRules::SetAvgPlayerRank)
        .addProperty("QueuedMatchmakingReservationString", &GCCSGameRules::GetQueuedMatchmakingReservationString, &GCCSGameRules::SetQueuedMatchmakingReservationString)
        .addProperty("NumTotalTournamentDrops", &GCCSGameRules::GetNumTotalTournamentDrops, &GCCSGameRules::SetNumTotalTournamentDrops)
        .addProperty("NumSpectatorsCountMax", &GCCSGameRules::GetNumSpectatorsCountMax, &GCCSGameRules::SetNumSpectatorsCountMax)
        .addProperty("NumSpectatorsCountMaxTV", &GCCSGameRules::GetNumSpectatorsCountMaxTV, &GCCSGameRules::SetNumSpectatorsCountMaxTV)
        .addProperty("NumSpectatorsCountMaxLnk", &GCCSGameRules::GetNumSpectatorsCountMaxLnk, &GCCSGameRules::SetNumSpectatorsCountMaxLnk)
        .addProperty("ForceTeamChangeSilent", &GCCSGameRules::GetForceTeamChangeSilent, &GCCSGameRules::SetForceTeamChangeSilent)
        .addProperty("LoadingRoundBackupData", &GCCSGameRules::GetLoadingRoundBackupData, &GCCSGameRules::SetLoadingRoundBackupData)
        .addProperty("MatchInfoShowType", &GCCSGameRules::GetMatchInfoShowType, &GCCSGameRules::SetMatchInfoShowType)
        .addProperty("MatchInfoDecidedTime", &GCCSGameRules::GetMatchInfoDecidedTime, &GCCSGameRules::SetMatchInfoDecidedTime)
        .addProperty("MTeamDMLastWinningTeamNumber", &GCCSGameRules::GetMTeamDMLastWinningTeamNumber, &GCCSGameRules::SetMTeamDMLastWinningTeamNumber)
        .addProperty("MTeamDMLastThinkTime", &GCCSGameRules::GetMTeamDMLastThinkTime, &GCCSGameRules::SetMTeamDMLastThinkTime)
        .addProperty("TeamDMLastAnnouncementTime", &GCCSGameRules::GetTeamDMLastAnnouncementTime, &GCCSGameRules::SetTeamDMLastAnnouncementTime)
        .addProperty("AccountTerrorist", &GCCSGameRules::GetAccountTerrorist, &GCCSGameRules::SetAccountTerrorist)
        .addProperty("AccountCT", &GCCSGameRules::GetAccountCT, &GCCSGameRules::SetAccountCT)
        .addProperty("SpawnPointCount_Terrorist", &GCCSGameRules::GetSpawnPointCount_Terrorist, &GCCSGameRules::SetSpawnPointCount_Terrorist)
        .addProperty("SpawnPointCount_CT", &GCCSGameRules::GetSpawnPointCount_CT, &GCCSGameRules::SetSpawnPointCount_CT)
        .addProperty("MaxNumTerrorists", &GCCSGameRules::GetMaxNumTerrorists, &GCCSGameRules::SetMaxNumTerrorists)
        .addProperty("MaxNumCTs", &GCCSGameRules::GetMaxNumCTs, &GCCSGameRules::SetMaxNumCTs)
        .addProperty("LoserBonusMostRecentTeam", &GCCSGameRules::GetLoserBonusMostRecentTeam, &GCCSGameRules::SetLoserBonusMostRecentTeam)
        .addProperty("TmNextPeriodicThink", &GCCSGameRules::GetTmNextPeriodicThink, &GCCSGameRules::SetTmNextPeriodicThink)
        .addProperty("VoiceWonMatchBragFired", &GCCSGameRules::GetVoiceWonMatchBragFired, &GCCSGameRules::SetVoiceWonMatchBragFired)
        .addProperty("WarmupNextChatNoticeTime", &GCCSGameRules::GetWarmupNextChatNoticeTime, &GCCSGameRules::SetWarmupNextChatNoticeTime)
        .addProperty("HostagesRescued", &GCCSGameRules::GetHostagesRescued, &GCCSGameRules::SetHostagesRescued)
        .addProperty("HostagesTouched", &GCCSGameRules::GetHostagesTouched, &GCCSGameRules::SetHostagesTouched)
        .addProperty("NextHostageAnnouncement", &GCCSGameRules::GetNextHostageAnnouncement, &GCCSGameRules::SetNextHostageAnnouncement)
        .addProperty("NoTerroristsKilled", &GCCSGameRules::GetNoTerroristsKilled, &GCCSGameRules::SetNoTerroristsKilled)
        .addProperty("NoCTsKilled", &GCCSGameRules::GetNoCTsKilled, &GCCSGameRules::SetNoCTsKilled)
        .addProperty("NoEnemiesKilled", &GCCSGameRules::GetNoEnemiesKilled, &GCCSGameRules::SetNoEnemiesKilled)
        .addProperty("CanDonateWeapons", &GCCSGameRules::GetCanDonateWeapons, &GCCSGameRules::SetCanDonateWeapons)
        .addProperty("FirstKillTime", &GCCSGameRules::GetFirstKillTime, &GCCSGameRules::SetFirstKillTime)
        .addProperty("FirstBloodTime", &GCCSGameRules::GetFirstBloodTime, &GCCSGameRules::SetFirstBloodTime)
        .addProperty("HostageWasInjured", &GCCSGameRules::GetHostageWasInjured, &GCCSGameRules::SetHostageWasInjured)
        .addProperty("HostageWasKilled", &GCCSGameRules::GetHostageWasKilled, &GCCSGameRules::SetHostageWasKilled)
        .addProperty("VoteCalled", &GCCSGameRules::GetVoteCalled, &GCCSGameRules::SetVoteCalled)
        .addProperty("ServerVoteOnReset", &GCCSGameRules::GetServerVoteOnReset, &GCCSGameRules::SetServerVoteOnReset)
        .addProperty("VoteCheckThrottle", &GCCSGameRules::GetVoteCheckThrottle, &GCCSGameRules::SetVoteCheckThrottle)
        .addProperty("BuyTimeEnded", &GCCSGameRules::GetBuyTimeEnded, &GCCSGameRules::SetBuyTimeEnded)
        .addProperty("LastFreezeEndBeep", &GCCSGameRules::GetLastFreezeEndBeep, &GCCSGameRules::SetLastFreezeEndBeep)
        .addProperty("TargetBombed", &GCCSGameRules::GetTargetBombed, &GCCSGameRules::SetTargetBombed)
        .addProperty("BombDefused", &GCCSGameRules::GetBombDefused, &GCCSGameRules::SetBombDefused)
        .addProperty("MapHasBombZone", &GCCSGameRules::GetMapHasBombZone, &GCCSGameRules::SetMapHasBombZone)
        .addProperty("MainCTSpawnPos", &GCCSGameRules::GetMainCTSpawnPos, &GCCSGameRules::SetMainCTSpawnPos)
        .addProperty("CTSpawnPointsMasterList", &GCCSGameRules::GetCTSpawnPointsMasterList, &GCCSGameRules::SetCTSpawnPointsMasterList)
        .addProperty("TerroristSpawnPointsMasterList", &GCCSGameRules::GetTerroristSpawnPointsMasterList, &GCCSGameRules::SetTerroristSpawnPointsMasterList)
        .addProperty("RespawningAllRespawnablePlayers", &GCCSGameRules::GetRespawningAllRespawnablePlayers, &GCCSGameRules::SetRespawningAllRespawnablePlayers)
        .addProperty("NextCTSpawnPoint", &GCCSGameRules::GetNextCTSpawnPoint, &GCCSGameRules::SetNextCTSpawnPoint)
        .addProperty("CTSpawnPointUsedTime", &GCCSGameRules::GetCTSpawnPointUsedTime, &GCCSGameRules::SetCTSpawnPointUsedTime)
        .addProperty("NextTerroristSpawnPoint", &GCCSGameRules::GetNextTerroristSpawnPoint, &GCCSGameRules::SetNextTerroristSpawnPoint)
        .addProperty("TerroristSpawnPointUsedTime", &GCCSGameRules::GetTerroristSpawnPointUsedTime, &GCCSGameRules::SetTerroristSpawnPointUsedTime)
        .addProperty("CTSpawnPoints", &GCCSGameRules::GetCTSpawnPoints, &GCCSGameRules::SetCTSpawnPoints)
        .addProperty("TerroristSpawnPoints", &GCCSGameRules::GetTerroristSpawnPoints, &GCCSGameRules::SetTerroristSpawnPoints)
        .addProperty("IsUnreservedGameServer", &GCCSGameRules::GetIsUnreservedGameServer, &GCCSGameRules::SetIsUnreservedGameServer)
        .addProperty("AutobalanceDisplayTime", &GCCSGameRules::GetAutobalanceDisplayTime, &GCCSGameRules::SetAutobalanceDisplayTime)
        .addProperty("AllowWeaponSwitch", &GCCSGameRules::GetAllowWeaponSwitch, &GCCSGameRules::SetAllowWeaponSwitch)
        .addProperty("RoundTimeWarningTriggered", &GCCSGameRules::GetRoundTimeWarningTriggered, &GCCSGameRules::SetRoundTimeWarningTriggered)
        .addProperty("PhaseChangeAnnouncementTime", &GCCSGameRules::GetPhaseChangeAnnouncementTime, &GCCSGameRules::SetPhaseChangeAnnouncementTime)
        .addProperty("NextUpdateTeamClanNamesTime", &GCCSGameRules::GetNextUpdateTeamClanNamesTime, &GCCSGameRules::SetNextUpdateTeamClanNamesTime)
        .addProperty("LastThinkTime", &GCCSGameRules::GetLastThinkTime, &GCCSGameRules::SetLastThinkTime)
        .addProperty("AccumulatedRoundOffDamage", &GCCSGameRules::GetAccumulatedRoundOffDamage, &GCCSGameRules::SetAccumulatedRoundOffDamage)
        .addProperty("ShorthandedBonusLastEvalRound", &GCCSGameRules::GetShorthandedBonusLastEvalRound, &GCCSGameRules::SetShorthandedBonusLastEvalRound)
        .addProperty("MatchAbortedEarlyReason", &GCCSGameRules::GetMatchAbortedEarlyReason, &GCCSGameRules::SetMatchAbortedEarlyReason)
        .addProperty("HasTriggeredRoundStartMusic", &GCCSGameRules::GetHasTriggeredRoundStartMusic, &GCCSGameRules::SetHasTriggeredRoundStartMusic)
        .addProperty("SwitchingTeamsAtRoundReset", &GCCSGameRules::GetSwitchingTeamsAtRoundReset, &GCCSGameRules::SetSwitchingTeamsAtRoundReset)
        .addProperty("GameModeRules", &GCCSGameRules::GetGameModeRules, &GCCSGameRules::SetGameModeRules)
        .addProperty("PlayerResource", &GCCSGameRules::GetPlayerResource, &GCCSGameRules::SetPlayerResource)
        .addProperty("RetakeRules", &GCCSGameRules::GetRetakeRules, &GCCSGameRules::SetRetakeRules)
        .addProperty("TeamLastKillUsedUniqueWeaponMatch", &GCCSGameRules::GetTeamLastKillUsedUniqueWeaponMatch, &GCCSGameRules::SetTeamLastKillUsedUniqueWeaponMatch)
        .addProperty("MatchEndCount", &GCCSGameRules::GetMatchEndCount, &GCCSGameRules::SetMatchEndCount)
        .addProperty("TTeamIntroVariant", &GCCSGameRules::GetTTeamIntroVariant, &GCCSGameRules::SetTTeamIntroVariant)
        .addProperty("CTTeamIntroVariant", &GCCSGameRules::GetCTTeamIntroVariant, &GCCSGameRules::SetCTTeamIntroVariant)
        .addProperty("TeamIntroPeriod", &GCCSGameRules::GetTeamIntroPeriod, &GCCSGameRules::SetTeamIntroPeriod)
        .addProperty("TeamIntroPeriodEnd", &GCCSGameRules::GetTeamIntroPeriodEnd, &GCCSGameRules::SetTeamIntroPeriodEnd)
        .addProperty("PlayedTeamIntroVO", &GCCSGameRules::GetPlayedTeamIntroVO, &GCCSGameRules::SetPlayedTeamIntroVO)
        .addProperty("RoundEndWinnerTeam", &GCCSGameRules::GetRoundEndWinnerTeam, &GCCSGameRules::SetRoundEndWinnerTeam)
        .addProperty("RoundEndReason", &GCCSGameRules::GetRoundEndReason, &GCCSGameRules::SetRoundEndReason)
        .addProperty("RoundEndShowTimerDefend", &GCCSGameRules::GetRoundEndShowTimerDefend, &GCCSGameRules::SetRoundEndShowTimerDefend)
        .addProperty("RoundEndTimerTime", &GCCSGameRules::GetRoundEndTimerTime, &GCCSGameRules::SetRoundEndTimerTime)
        .addProperty("RoundEndFunFactToken", &GCCSGameRules::GetRoundEndFunFactToken, &GCCSGameRules::SetRoundEndFunFactToken)
        .addProperty("RoundEndFunFactPlayerSlot", &GCCSGameRules::GetRoundEndFunFactPlayerSlot, &GCCSGameRules::SetRoundEndFunFactPlayerSlot)
        .addProperty("RoundEndFunFactData1", &GCCSGameRules::GetRoundEndFunFactData1, &GCCSGameRules::SetRoundEndFunFactData1)
        .addProperty("RoundEndFunFactData2", &GCCSGameRules::GetRoundEndFunFactData2, &GCCSGameRules::SetRoundEndFunFactData2)
        .addProperty("RoundEndFunFactData3", &GCCSGameRules::GetRoundEndFunFactData3, &GCCSGameRules::SetRoundEndFunFactData3)
        .addProperty("RoundEndMessage", &GCCSGameRules::GetRoundEndMessage, &GCCSGameRules::SetRoundEndMessage)
        .addProperty("RoundEndPlayerCount", &GCCSGameRules::GetRoundEndPlayerCount, &GCCSGameRules::SetRoundEndPlayerCount)
        .addProperty("RoundEndNoMusic", &GCCSGameRules::GetRoundEndNoMusic, &GCCSGameRules::SetRoundEndNoMusic)
        .addProperty("RoundEndLegacy", &GCCSGameRules::GetRoundEndLegacy, &GCCSGameRules::SetRoundEndLegacy)
        .addProperty("RoundEndCount", &GCCSGameRules::GetRoundEndCount, &GCCSGameRules::SetRoundEndCount)
        .addProperty("RoundStartRoundNumber", &GCCSGameRules::GetRoundStartRoundNumber, &GCCSGameRules::SetRoundStartRoundNumber)
        .addProperty("RoundStartCount", &GCCSGameRules::GetRoundStartCount, &GCCSGameRules::SetRoundStartCount)
        .addProperty("LastPerfSampleTime", &GCCSGameRules::GetLastPerfSampleTime, &GCCSGameRules::SetLastPerfSampleTime)
        .addProperty("Parent", &GCCSGameRules::GetParent, &GCCSGameRules::SetParent)
        .addFunction("ToPtr", &GCCSGameRules::ToPtr)
        .addFunction("IsValid", &GCCSGameRules::IsValid)
        .endClass();
}