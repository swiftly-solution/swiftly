class GCCSGameRules;

#ifndef _gcccsgamerules_h
#define _gcccsgamerules_h

#include "../../../scripting.h"


#include "GSpawnPoint.h"
#include "GCCSGameModeRules.h"
#include "GCBaseEntity.h"
#include "GCRetakeGameRules.h"

class GCCSGameRules
{
private:
    void *m_ptr;

public:
    GCCSGameRules() {}
    GCCSGameRules(void *ptr) : m_ptr(ptr) {}

    bool GetFreezePeriod() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bFreezePeriod"); }
    void SetFreezePeriod(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bFreezePeriod", false, value); }
    bool GetWarmupPeriod() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bWarmupPeriod"); }
    void SetWarmupPeriod(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bWarmupPeriod", false, value); }
    bool GetServerPaused() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bServerPaused"); }
    void SetServerPaused(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bServerPaused", false, value); }
    bool GetTerroristTimeOutActive() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bTerroristTimeOutActive"); }
    void SetTerroristTimeOutActive(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bTerroristTimeOutActive", false, value); }
    bool GetCTTimeOutActive() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bCTTimeOutActive"); }
    void SetCTTimeOutActive(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bCTTimeOutActive", false, value); }
    float GetTerroristTimeOutRemaining() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flTerroristTimeOutRemaining"); }
    void SetTerroristTimeOutRemaining(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_flTerroristTimeOutRemaining", false, value); }
    float GetCTTimeOutRemaining() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flCTTimeOutRemaining"); }
    void SetCTTimeOutRemaining(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_flCTTimeOutRemaining", false, value); }
    int32_t GetTerroristTimeOuts() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nTerroristTimeOuts"); }
    void SetTerroristTimeOuts(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nTerroristTimeOuts", false, value); }
    int32_t GetCTTimeOuts() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nCTTimeOuts"); }
    void SetCTTimeOuts(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nCTTimeOuts", false, value); }
    bool GetTechnicalTimeOut() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bTechnicalTimeOut"); }
    void SetTechnicalTimeOut(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bTechnicalTimeOut", false, value); }
    bool GetMatchWaitingForResume() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bMatchWaitingForResume"); }
    void SetMatchWaitingForResume(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bMatchWaitingForResume", false, value); }
    int32_t GetRoundTime() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundTime"); }
    void SetRoundTime(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundTime", false, value); }
    float GetMatchStartTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fMatchStartTime"); }
    void SetMatchStartTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_fMatchStartTime", false, value); }
    bool GetGameRestart() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bGameRestart"); }
    void SetGameRestart(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bGameRestart", false, value); }
    float GetGameStartTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flGameStartTime"); }
    void SetGameStartTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_flGameStartTime", false, value); }
    float GetTimeUntilNextPhaseStarts() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_timeUntilNextPhaseStarts"); }
    void SetTimeUntilNextPhaseStarts(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_timeUntilNextPhaseStarts", false, value); }
    int32_t GetGamePhase() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_gamePhase"); }
    void SetGamePhase(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_gamePhase", false, value); }
    int32_t GetTotalRoundsPlayed() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_totalRoundsPlayed"); }
    void SetTotalRoundsPlayed(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_totalRoundsPlayed", false, value); }
    int32_t GetRoundsPlayedThisPhase() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nRoundsPlayedThisPhase"); }
    void SetRoundsPlayedThisPhase(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nRoundsPlayedThisPhase", false, value); }
    int32_t GetOvertimePlaying() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nOvertimePlaying"); }
    void SetOvertimePlaying(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nOvertimePlaying", false, value); }
    int32_t GetHostagesRemaining() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iHostagesRemaining"); }
    void SetHostagesRemaining(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iHostagesRemaining", false, value); }
    bool GetAnyHostageReached() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bAnyHostageReached"); }
    void SetAnyHostageReached(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bAnyHostageReached", false, value); }
    bool GetMapHasBombTarget() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bMapHasBombTarget"); }
    void SetMapHasBombTarget(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bMapHasBombTarget", false, value); }
    bool GetMapHasRescueZone() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bMapHasRescueZone"); }
    void SetMapHasRescueZone(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bMapHasRescueZone", false, value); }
    bool GetMapHasBuyZone() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bMapHasBuyZone"); }
    void SetMapHasBuyZone(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bMapHasBuyZone", false, value); }
    bool GetIsQueuedMatchmaking() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsQueuedMatchmaking"); }
    void SetIsQueuedMatchmaking(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsQueuedMatchmaking", false, value); }
    int32_t GetQueuedMatchmakingMode() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nQueuedMatchmakingMode"); }
    void SetQueuedMatchmakingMode(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nQueuedMatchmakingMode", false, value); }
    bool GetIsValveDS() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsValveDS"); }
    void SetIsValveDS(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsValveDS", false, value); }
    bool GetLogoMap() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bLogoMap"); }
    void SetLogoMap(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bLogoMap", false, value); }
    bool GetPlayAllStepSoundsOnServer() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bPlayAllStepSoundsOnServer"); }
    void SetPlayAllStepSoundsOnServer(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bPlayAllStepSoundsOnServer", false, value); }
    int32_t GetSpectatorSlotCount() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iSpectatorSlotCount"); }
    void SetSpectatorSlotCount(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iSpectatorSlotCount", false, value); }
    int32_t GetMatchDevice() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_MatchDevice"); }
    void SetMatchDevice(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_MatchDevice", false, value); }
    bool GetHasMatchStarted() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bHasMatchStarted"); }
    void SetHasMatchStarted(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bHasMatchStarted", false, value); }
    int32_t GetNextMapInMapgroup() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nNextMapInMapgroup"); }
    void SetNextMapInMapgroup(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nNextMapInMapgroup", false, value); }
    std::string GetTournamentEventName() const { return GetSchemaValue<char*>(m_ptr, "CCSGameRules", "m_szTournamentEventName"); }
    void SetTournamentEventName(std::string value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_szTournamentEventName", false, value); }
    std::string GetTournamentEventStage() const { return GetSchemaValue<char*>(m_ptr, "CCSGameRules", "m_szTournamentEventStage"); }
    void SetTournamentEventStage(std::string value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_szTournamentEventStage", false, value); }
    std::string GetMatchStatTxt() const { return GetSchemaValue<char*>(m_ptr, "CCSGameRules", "m_szMatchStatTxt"); }
    void SetMatchStatTxt(std::string value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_szMatchStatTxt", false, value); }
    std::string GetTournamentPredictionsTxt() const { return GetSchemaValue<char*>(m_ptr, "CCSGameRules", "m_szTournamentPredictionsTxt"); }
    void SetTournamentPredictionsTxt(std::string value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_szTournamentPredictionsTxt", false, value); }
    int32_t GetTournamentPredictionsPct() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nTournamentPredictionsPct"); }
    void SetTournamentPredictionsPct(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nTournamentPredictionsPct", false, value); }
    bool GetIsDroppingItems() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsDroppingItems"); }
    void SetIsDroppingItems(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsDroppingItems", false, value); }
    bool GetIsQuestEligible() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsQuestEligible"); }
    void SetIsQuestEligible(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsQuestEligible", false, value); }
    bool GetIsHltvActive() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsHltvActive"); }
    void SetIsHltvActive(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsHltvActive", false, value); }
    std::vector<uint16_t> GetProhibitedItemIndices() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "CCSGameRules", "m_arrProhibitedItemIndices"); std::vector<uint16_t> ret; for(int i = 0; i < 100; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetProhibitedItemIndices(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "CCSGameRules", "m_arrProhibitedItemIndices"); for(int i = 0; i < 100; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_arrProhibitedItemIndices", false, outValue); }
    std::vector<uint32_t> GetTournamentActiveCasterAccounts() const { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSGameRules", "m_arrTournamentActiveCasterAccounts"); std::vector<uint32_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetTournamentActiveCasterAccounts(std::vector<uint32_t> value) { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSGameRules", "m_arrTournamentActiveCasterAccounts"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_arrTournamentActiveCasterAccounts", false, outValue); }
    int32_t GetNumBestOfMaps() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_numBestOfMaps"); }
    void SetNumBestOfMaps(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_numBestOfMaps", false, value); }
    int32_t GetHalloweenMaskListSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nHalloweenMaskListSeed"); }
    void SetHalloweenMaskListSeed(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nHalloweenMaskListSeed", false, value); }
    bool GetBombDropped() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bBombDropped"); }
    void SetBombDropped(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bBombDropped", false, value); }
    bool GetBombPlanted() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bBombPlanted"); }
    void SetBombPlanted(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bBombPlanted", false, value); }
    int32_t GetRoundWinStatus() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundWinStatus"); }
    void SetRoundWinStatus(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundWinStatus", false, value); }
    int32_t GetRoundWinReason() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_eRoundWinReason"); }
    void SetRoundWinReason(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_eRoundWinReason", false, value); }
    bool GetTCantBuy() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bTCantBuy"); }
    void SetTCantBuy(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bTCantBuy", false, value); }
    bool GetCTCantBuy() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bCTCantBuy"); }
    void SetCTCantBuy(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bCTCantBuy", false, value); }
    std::vector<int32_t> GetMatchStats_RoundResults() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_RoundResults"); std::vector<int32_t> ret; for(int i = 0; i < 30; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetMatchStats_RoundResults(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_RoundResults"); for(int i = 0; i < 30; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_iMatchStats_RoundResults", false, outValue); }
    std::vector<int32_t> GetMatchStats_PlayersAlive_CT() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_CT"); std::vector<int32_t> ret; for(int i = 0; i < 30; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetMatchStats_PlayersAlive_CT(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_CT"); for(int i = 0; i < 30; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_CT", false, outValue); }
    std::vector<int32_t> GetMatchStats_PlayersAlive_T() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_T"); std::vector<int32_t> ret; for(int i = 0; i < 30; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetMatchStats_PlayersAlive_T(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_T"); for(int i = 0; i < 30; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_iMatchStats_PlayersAlive_T", false, outValue); }
    std::vector<float> GetTeamRespawnWaveTimes() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CCSGameRules", "m_TeamRespawnWaveTimes"); std::vector<float> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetTeamRespawnWaveTimes(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CCSGameRules", "m_TeamRespawnWaveTimes"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_TeamRespawnWaveTimes", false, outValue); }
    int32_t GetServerQuestID() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nServerQuestID"); }
    void SetServerQuestID(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nServerQuestID", false, value); }
    Vector GetMinimapMins() const { return GetSchemaValue<Vector>(m_ptr, "CCSGameRules", "m_vMinimapMins"); }
    void SetMinimapMins(Vector value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_vMinimapMins", false, value); }
    Vector GetMinimapMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CCSGameRules", "m_vMinimapMaxs"); }
    void SetMinimapMaxs(Vector value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_vMinimapMaxs", false, value); }
    std::vector<float> GetMinimapVerticalSectionHeights() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CCSGameRules", "m_MinimapVerticalSectionHeights"); std::vector<float> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetMinimapVerticalSectionHeights(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CCSGameRules", "m_MinimapVerticalSectionHeights"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_MinimapVerticalSectionHeights", false, outValue); }
    bool GetSpawnedTerrorHuntHeavy() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bSpawnedTerrorHuntHeavy"); }
    void SetSpawnedTerrorHuntHeavy(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bSpawnedTerrorHuntHeavy", false, value); }
    std::vector<int32_t> GetEndMatchMapGroupVoteTypes() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteTypes"); std::vector<int32_t> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetEndMatchMapGroupVoteTypes(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteTypes"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteTypes", false, outValue); }
    std::vector<int32_t> GetEndMatchMapGroupVoteOptions() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteOptions"); std::vector<int32_t> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetEndMatchMapGroupVoteOptions(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteOptions"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_nEndMatchMapGroupVoteOptions", false, outValue); }
    int32_t GetEndMatchMapVoteWinner() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nEndMatchMapVoteWinner"); }
    void SetEndMatchMapVoteWinner(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nEndMatchMapVoteWinner", false, value); }
    int32_t GetNumConsecutiveCTLoses() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumConsecutiveCTLoses"); }
    void SetNumConsecutiveCTLoses(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumConsecutiveCTLoses", false, value); }
    int32_t GetNumConsecutiveTerroristLoses() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumConsecutiveTerroristLoses"); }
    void SetNumConsecutiveTerroristLoses(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumConsecutiveTerroristLoses", false, value); }
    bool GetHasHostageBeenTouched() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bHasHostageBeenTouched"); }
    void SetHasHostageBeenTouched(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bHasHostageBeenTouched", false, value); }
    bool GetLevelInitialized() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bLevelInitialized"); }
    void SetLevelInitialized(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bLevelInitialized", false, value); }
    int32_t GetTotalRoundsPlayed1() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iTotalRoundsPlayed"); }
    void SetTotalRoundsPlayed1(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iTotalRoundsPlayed", false, value); }
    int32_t GetUnBalancedRounds() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iUnBalancedRounds"); }
    void SetUnBalancedRounds(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iUnBalancedRounds", false, value); }
    bool GetEndMatchOnRoundReset() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_endMatchOnRoundReset"); }
    void SetEndMatchOnRoundReset(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_endMatchOnRoundReset", false, value); }
    bool GetEndMatchOnThink() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_endMatchOnThink"); }
    void SetEndMatchOnThink(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_endMatchOnThink", false, value); }
    int32_t GetFreezeTime() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iFreezeTime"); }
    void SetFreezeTime(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iFreezeTime", false, value); }
    int32_t GetNumTerrorist() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumTerrorist"); }
    void SetNumTerrorist(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumTerrorist", false, value); }
    int32_t GetNumCT() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumCT"); }
    void SetNumCT(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumCT", false, value); }
    int32_t GetNumSpawnableTerrorist() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumSpawnableTerrorist"); }
    void SetNumSpawnableTerrorist(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumSpawnableTerrorist", false, value); }
    int32_t GetNumSpawnableCT() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNumSpawnableCT"); }
    void SetNumSpawnableCT(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iNumSpawnableCT", false, value); }
    std::vector<int32> GetSelectedHostageSpawnIndices() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CCSGameRules", "m_arrSelectedHostageSpawnIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSelectedHostageSpawnIndices(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CCSGameRules", "m_arrSelectedHostageSpawnIndices", false, value); }
    int32_t GetSpawnPointsRandomSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nSpawnPointsRandomSeed"); }
    void SetSpawnPointsRandomSeed(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nSpawnPointsRandomSeed", false, value); }
    bool GetFirstConnected() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bFirstConnected"); }
    void SetFirstConnected(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bFirstConnected", false, value); }
    bool GetCompleteReset() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bCompleteReset"); }
    void SetCompleteReset(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bCompleteReset", false, value); }
    bool GetPickNewTeamsOnReset() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bPickNewTeamsOnReset"); }
    void SetPickNewTeamsOnReset(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bPickNewTeamsOnReset", false, value); }
    bool GetScrambleTeamsOnRestart() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bScrambleTeamsOnRestart"); }
    void SetScrambleTeamsOnRestart(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bScrambleTeamsOnRestart", false, value); }
    bool GetSwapTeamsOnRestart() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bSwapTeamsOnRestart"); }
    void SetSwapTeamsOnRestart(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bSwapTeamsOnRestart", false, value); }
    std::vector<int32> GetEndMatchTiedVotes() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CCSGameRules", "m_nEndMatchTiedVotes"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetEndMatchTiedVotes(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CCSGameRules", "m_nEndMatchTiedVotes", false, value); }
    bool GetNeedToAskPlayersForContinueVote() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bNeedToAskPlayersForContinueVote"); }
    void SetNeedToAskPlayersForContinueVote(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bNeedToAskPlayersForContinueVote", false, value); }
    uint32_t GetNumQueuedMatchmakingAccounts() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSGameRules", "m_numQueuedMatchmakingAccounts"); }
    void SetNumQueuedMatchmakingAccounts(uint32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_numQueuedMatchmakingAccounts", false, value); }
    float GetAvgPlayerRank() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fAvgPlayerRank"); }
    void SetAvgPlayerRank(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_fAvgPlayerRank", false, value); }
    std::string GetQueuedMatchmakingReservationString() const { return GetSchemaValue<char*>(m_ptr, "CCSGameRules", "m_pQueuedMatchmakingReservationString"); }
    void SetQueuedMatchmakingReservationString(std::string value) { WriteSchemaPtrValue(m_ptr, "CCSGameRules", "m_pQueuedMatchmakingReservationString", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    uint32_t GetNumTotalTournamentDrops() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSGameRules", "m_numTotalTournamentDrops"); }
    void SetNumTotalTournamentDrops(uint32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_numTotalTournamentDrops", false, value); }
    uint32_t GetNumSpectatorsCountMax() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSGameRules", "m_numSpectatorsCountMax"); }
    void SetNumSpectatorsCountMax(uint32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_numSpectatorsCountMax", false, value); }
    uint32_t GetNumSpectatorsCountMaxTV() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSGameRules", "m_numSpectatorsCountMaxTV"); }
    void SetNumSpectatorsCountMaxTV(uint32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_numSpectatorsCountMaxTV", false, value); }
    uint32_t GetNumSpectatorsCountMaxLnk() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSGameRules", "m_numSpectatorsCountMaxLnk"); }
    void SetNumSpectatorsCountMaxLnk(uint32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_numSpectatorsCountMaxLnk", false, value); }
    bool GetForceTeamChangeSilent() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bForceTeamChangeSilent"); }
    void SetForceTeamChangeSilent(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bForceTeamChangeSilent", false, value); }
    bool GetLoadingRoundBackupData() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bLoadingRoundBackupData"); }
    void SetLoadingRoundBackupData(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bLoadingRoundBackupData", false, value); }
    int32_t GetMatchInfoShowType() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nMatchInfoShowType"); }
    void SetMatchInfoShowType(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nMatchInfoShowType", false, value); }
    float GetMatchInfoDecidedTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flMatchInfoDecidedTime"); }
    void SetMatchInfoDecidedTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_flMatchInfoDecidedTime", false, value); }
    int32_t GetMTeamDMLastWinningTeamNumber() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "mTeamDMLastWinningTeamNumber"); }
    void SetMTeamDMLastWinningTeamNumber(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "mTeamDMLastWinningTeamNumber", false, value); }
    float GetMTeamDMLastThinkTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "mTeamDMLastThinkTime"); }
    void SetMTeamDMLastThinkTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "mTeamDMLastThinkTime", false, value); }
    float GetTeamDMLastAnnouncementTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flTeamDMLastAnnouncementTime"); }
    void SetTeamDMLastAnnouncementTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_flTeamDMLastAnnouncementTime", false, value); }
    int32_t GetAccountTerrorist() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iAccountTerrorist"); }
    void SetAccountTerrorist(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iAccountTerrorist", false, value); }
    int32_t GetAccountCT() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iAccountCT"); }
    void SetAccountCT(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iAccountCT", false, value); }
    int32_t GetSpawnPointCount_Terrorist() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iSpawnPointCount_Terrorist"); }
    void SetSpawnPointCount_Terrorist(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iSpawnPointCount_Terrorist", false, value); }
    int32_t GetSpawnPointCount_CT() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iSpawnPointCount_CT"); }
    void SetSpawnPointCount_CT(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iSpawnPointCount_CT", false, value); }
    int32_t GetMaxNumTerrorists() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iMaxNumTerrorists"); }
    void SetMaxNumTerrorists(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iMaxNumTerrorists", false, value); }
    int32_t GetMaxNumCTs() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iMaxNumCTs"); }
    void SetMaxNumCTs(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iMaxNumCTs", false, value); }
    int32_t GetLoserBonusMostRecentTeam() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iLoserBonusMostRecentTeam"); }
    void SetLoserBonusMostRecentTeam(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iLoserBonusMostRecentTeam", false, value); }
    float GetTmNextPeriodicThink() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_tmNextPeriodicThink"); }
    void SetTmNextPeriodicThink(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_tmNextPeriodicThink", false, value); }
    bool GetVoiceWonMatchBragFired() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bVoiceWonMatchBragFired"); }
    void SetVoiceWonMatchBragFired(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bVoiceWonMatchBragFired", false, value); }
    float GetWarmupNextChatNoticeTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fWarmupNextChatNoticeTime"); }
    void SetWarmupNextChatNoticeTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_fWarmupNextChatNoticeTime", false, value); }
    int32_t GetHostagesRescued() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iHostagesRescued"); }
    void SetHostagesRescued(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iHostagesRescued", false, value); }
    int32_t GetHostagesTouched() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iHostagesTouched"); }
    void SetHostagesTouched(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iHostagesTouched", false, value); }
    float GetNextHostageAnnouncement() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flNextHostageAnnouncement"); }
    void SetNextHostageAnnouncement(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_flNextHostageAnnouncement", false, value); }
    bool GetNoTerroristsKilled() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bNoTerroristsKilled"); }
    void SetNoTerroristsKilled(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bNoTerroristsKilled", false, value); }
    bool GetNoCTsKilled() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bNoCTsKilled"); }
    void SetNoCTsKilled(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bNoCTsKilled", false, value); }
    bool GetNoEnemiesKilled() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bNoEnemiesKilled"); }
    void SetNoEnemiesKilled(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bNoEnemiesKilled", false, value); }
    bool GetCanDonateWeapons() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bCanDonateWeapons"); }
    void SetCanDonateWeapons(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bCanDonateWeapons", false, value); }
    float GetFirstKillTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_firstKillTime"); }
    void SetFirstKillTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_firstKillTime", false, value); }
    float GetFirstBloodTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_firstBloodTime"); }
    void SetFirstBloodTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_firstBloodTime", false, value); }
    bool GetHostageWasInjured() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_hostageWasInjured"); }
    void SetHostageWasInjured(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_hostageWasInjured", false, value); }
    bool GetHostageWasKilled() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_hostageWasKilled"); }
    void SetHostageWasKilled(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_hostageWasKilled", false, value); }
    bool GetVoteCalled() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bVoteCalled"); }
    void SetVoteCalled(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bVoteCalled", false, value); }
    bool GetServerVoteOnReset() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bServerVoteOnReset"); }
    void SetServerVoteOnReset(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bServerVoteOnReset", false, value); }
    float GetVoteCheckThrottle() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flVoteCheckThrottle"); }
    void SetVoteCheckThrottle(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_flVoteCheckThrottle", false, value); }
    bool GetBuyTimeEnded() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bBuyTimeEnded"); }
    void SetBuyTimeEnded(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bBuyTimeEnded", false, value); }
    int32_t GetLastFreezeEndBeep() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nLastFreezeEndBeep"); }
    void SetLastFreezeEndBeep(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nLastFreezeEndBeep", false, value); }
    bool GetTargetBombed() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bTargetBombed"); }
    void SetTargetBombed(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bTargetBombed", false, value); }
    bool GetBombDefused() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bBombDefused"); }
    void SetBombDefused(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bBombDefused", false, value); }
    bool GetMapHasBombZone() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bMapHasBombZone"); }
    void SetMapHasBombZone(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bMapHasBombZone", false, value); }
    Vector GetMainCTSpawnPos() const { return GetSchemaValue<Vector>(m_ptr, "CCSGameRules", "m_vecMainCTSpawnPos"); }
    void SetMainCTSpawnPos(Vector value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_vecMainCTSpawnPos", false, value); }
    std::vector<GSpawnPoint*> GetCTSpawnPointsMasterList() const { CUtlVector<GSpawnPoint*>* vec = GetSchemaValue<CUtlVector<GSpawnPoint*>*>(m_ptr, "CCSGameRules", "m_CTSpawnPointsMasterList"); std::vector<GSpawnPoint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCTSpawnPointsMasterList(std::vector<GSpawnPoint*> value) { SetSchemaValueCUtlVector<GSpawnPoint*>(m_ptr, "CCSGameRules", "m_CTSpawnPointsMasterList", false, value); }
    std::vector<GSpawnPoint*> GetTerroristSpawnPointsMasterList() const { CUtlVector<GSpawnPoint*>* vec = GetSchemaValue<CUtlVector<GSpawnPoint*>*>(m_ptr, "CCSGameRules", "m_TerroristSpawnPointsMasterList"); std::vector<GSpawnPoint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTerroristSpawnPointsMasterList(std::vector<GSpawnPoint*> value) { SetSchemaValueCUtlVector<GSpawnPoint*>(m_ptr, "CCSGameRules", "m_TerroristSpawnPointsMasterList", false, value); }
    bool GetRespawningAllRespawnablePlayers() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bRespawningAllRespawnablePlayers"); }
    void SetRespawningAllRespawnablePlayers(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bRespawningAllRespawnablePlayers", false, value); }
    int32_t GetNextCTSpawnPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNextCTSpawnPoint"); }
    void SetNextCTSpawnPoint(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iNextCTSpawnPoint", false, value); }
    float GetCTSpawnPointUsedTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flCTSpawnPointUsedTime"); }
    void SetCTSpawnPointUsedTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_flCTSpawnPointUsedTime", false, value); }
    int32_t GetNextTerroristSpawnPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iNextTerroristSpawnPoint"); }
    void SetNextTerroristSpawnPoint(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iNextTerroristSpawnPoint", false, value); }
    float GetTerroristSpawnPointUsedTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_flTerroristSpawnPointUsedTime"); }
    void SetTerroristSpawnPointUsedTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_flTerroristSpawnPointUsedTime", false, value); }
    std::vector<GSpawnPoint*> GetCTSpawnPoints() const { CUtlVector<GSpawnPoint*>* vec = GetSchemaValue<CUtlVector<GSpawnPoint*>*>(m_ptr, "CCSGameRules", "m_CTSpawnPoints"); std::vector<GSpawnPoint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCTSpawnPoints(std::vector<GSpawnPoint*> value) { SetSchemaValueCUtlVector<GSpawnPoint*>(m_ptr, "CCSGameRules", "m_CTSpawnPoints", false, value); }
    std::vector<GSpawnPoint*> GetTerroristSpawnPoints() const { CUtlVector<GSpawnPoint*>* vec = GetSchemaValue<CUtlVector<GSpawnPoint*>*>(m_ptr, "CCSGameRules", "m_TerroristSpawnPoints"); std::vector<GSpawnPoint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTerroristSpawnPoints(std::vector<GSpawnPoint*> value) { SetSchemaValueCUtlVector<GSpawnPoint*>(m_ptr, "CCSGameRules", "m_TerroristSpawnPoints", false, value); }
    bool GetIsUnreservedGameServer() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bIsUnreservedGameServer"); }
    void SetIsUnreservedGameServer(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bIsUnreservedGameServer", false, value); }
    float GetAutobalanceDisplayTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fAutobalanceDisplayTime"); }
    void SetAutobalanceDisplayTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_fAutobalanceDisplayTime", false, value); }
    bool GetAllowWeaponSwitch() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bAllowWeaponSwitch"); }
    void SetAllowWeaponSwitch(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bAllowWeaponSwitch", false, value); }
    bool GetRoundTimeWarningTriggered() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bRoundTimeWarningTriggered"); }
    void SetRoundTimeWarningTriggered(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bRoundTimeWarningTriggered", false, value); }
    float GetNextUpdateTeamClanNamesTime() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fNextUpdateTeamClanNamesTime"); }
    void SetNextUpdateTeamClanNamesTime(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_fNextUpdateTeamClanNamesTime", false, value); }
    float GetAccumulatedRoundOffDamage() const { return GetSchemaValue<float>(m_ptr, "CCSGameRules", "m_fAccumulatedRoundOffDamage"); }
    void SetAccumulatedRoundOffDamage(float value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_fAccumulatedRoundOffDamage", false, value); }
    int32_t GetShorthandedBonusLastEvalRound() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nShorthandedBonusLastEvalRound"); }
    void SetShorthandedBonusLastEvalRound(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nShorthandedBonusLastEvalRound", false, value); }
    int32_t GetMatchAbortedEarlyReason() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nMatchAbortedEarlyReason"); }
    void SetMatchAbortedEarlyReason(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nMatchAbortedEarlyReason", false, value); }
    bool GetHasTriggeredRoundStartMusic() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bHasTriggeredRoundStartMusic"); }
    void SetHasTriggeredRoundStartMusic(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bHasTriggeredRoundStartMusic", false, value); }
    bool GetSwitchingTeamsAtRoundReset() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bSwitchingTeamsAtRoundReset"); }
    void SetSwitchingTeamsAtRoundReset(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bSwitchingTeamsAtRoundReset", false, value); }
    GCCSGameModeRules* GetGameModeRules() const { return GetSchemaValue<GCCSGameModeRules*>(m_ptr, "CCSGameRules", "m_pGameModeRules"); }
    void SetGameModeRules(GCCSGameModeRules* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'GameModeRules' is not possible.\n"); }
    GCBaseEntity* GetPlayerResource() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CCSGameRules", "m_hPlayerResource"); }
    void SetPlayerResource(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerResource' is not possible.\n"); }
    GCRetakeGameRules GetRetakeRules() const { return GetSchemaValue<GCRetakeGameRules>(m_ptr, "CCSGameRules", "m_RetakeRules"); }
    void SetRetakeRules(GCRetakeGameRules value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_RetakeRules", false, value); }
    std::vector<bool> GetTeamLastKillUsedUniqueWeaponMatch() const { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSGameRules", "m_bTeamLastKillUsedUniqueWeaponMatch"); std::vector<bool> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetTeamLastKillUsedUniqueWeaponMatch(std::vector<bool> value) { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSGameRules", "m_bTeamLastKillUsedUniqueWeaponMatch"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSGameRules", "m_bTeamLastKillUsedUniqueWeaponMatch", false, outValue); }
    uint8_t GetMatchEndCount() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSGameRules", "m_nMatchEndCount"); }
    void SetMatchEndCount(uint8_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nMatchEndCount", false, value); }
    int32_t GetTTeamIntroVariant() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nTTeamIntroVariant"); }
    void SetTTeamIntroVariant(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nTTeamIntroVariant", false, value); }
    int32_t GetCTTeamIntroVariant() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_nCTTeamIntroVariant"); }
    void SetCTTeamIntroVariant(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nCTTeamIntroVariant", false, value); }
    bool GetTeamIntroPeriod() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bTeamIntroPeriod"); }
    void SetTeamIntroPeriod(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bTeamIntroPeriod", false, value); }
    bool GetPlayedTeamIntroVO() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bPlayedTeamIntroVO"); }
    void SetPlayedTeamIntroVO(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bPlayedTeamIntroVO", false, value); }
    int32_t GetRoundEndWinnerTeam() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndWinnerTeam"); }
    void SetRoundEndWinnerTeam(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndWinnerTeam", false, value); }
    int32_t GetRoundEndReason() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_eRoundEndReason"); }
    void SetRoundEndReason(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_eRoundEndReason", false, value); }
    bool GetRoundEndShowTimerDefend() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bRoundEndShowTimerDefend"); }
    void SetRoundEndShowTimerDefend(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bRoundEndShowTimerDefend", false, value); }
    int32_t GetRoundEndTimerTime() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndTimerTime"); }
    void SetRoundEndTimerTime(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndTimerTime", false, value); }
    CUtlString GetRoundEndFunFactToken() const { return GetSchemaValue<CUtlString>(m_ptr, "CCSGameRules", "m_sRoundEndFunFactToken"); }
    void SetRoundEndFunFactToken(CUtlString value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_sRoundEndFunFactToken", false, value); }
    int32_t GetRoundEndFunFactPlayerSlot() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndFunFactPlayerSlot"); }
    void SetRoundEndFunFactPlayerSlot(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndFunFactPlayerSlot", false, value); }
    int32_t GetRoundEndFunFactData1() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData1"); }
    void SetRoundEndFunFactData1(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData1", false, value); }
    int32_t GetRoundEndFunFactData2() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData2"); }
    void SetRoundEndFunFactData2(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData2", false, value); }
    int32_t GetRoundEndFunFactData3() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData3"); }
    void SetRoundEndFunFactData3(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndFunFactData3", false, value); }
    CUtlString GetRoundEndMessage() const { return GetSchemaValue<CUtlString>(m_ptr, "CCSGameRules", "m_sRoundEndMessage"); }
    void SetRoundEndMessage(CUtlString value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_sRoundEndMessage", false, value); }
    int32_t GetRoundEndPlayerCount() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndPlayerCount"); }
    void SetRoundEndPlayerCount(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndPlayerCount", false, value); }
    bool GetRoundEndNoMusic() const { return GetSchemaValue<bool>(m_ptr, "CCSGameRules", "m_bRoundEndNoMusic"); }
    void SetRoundEndNoMusic(bool value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_bRoundEndNoMusic", false, value); }
    int32_t GetRoundEndLegacy() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundEndLegacy"); }
    void SetRoundEndLegacy(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundEndLegacy", false, value); }
    uint8_t GetRoundEndCount() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSGameRules", "m_nRoundEndCount"); }
    void SetRoundEndCount(uint8_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nRoundEndCount", false, value); }
    int32_t GetRoundStartRoundNumber() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGameRules", "m_iRoundStartRoundNumber"); }
    void SetRoundStartRoundNumber(int32_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_iRoundStartRoundNumber", false, value); }
    uint8_t GetRoundStartCount() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSGameRules", "m_nRoundStartCount"); }
    void SetRoundStartCount(uint8_t value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_nRoundStartCount", false, value); }
    double GetLastPerfSampleTime() const { return GetSchemaValue<double>(m_ptr, "CCSGameRules", "m_flLastPerfSampleTime"); }
    void SetLastPerfSampleTime(double value) { SetSchemaValue(m_ptr, "CCSGameRules", "m_flLastPerfSampleTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif