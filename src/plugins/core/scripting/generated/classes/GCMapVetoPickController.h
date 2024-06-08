class GCMapVetoPickController;

#ifndef _gccmapvetopickcontroller_h
#define _gccmapvetopickcontroller_h

#include "../../../scripting.h"




class GCMapVetoPickController
{
private:
    void *m_ptr;

public:
    GCMapVetoPickController() {}
    GCMapVetoPickController(void *ptr) : m_ptr(ptr) {}

    bool GetPlayedIntroVcd() const { return GetSchemaValue<bool>(m_ptr, "CMapVetoPickController", "m_bPlayedIntroVcd"); }
    void SetPlayedIntroVcd(bool value) { SetSchemaValue(m_ptr, "CMapVetoPickController", "m_bPlayedIntroVcd", false, value); }
    bool GetNeedToPlayFiveSecondsRemaining() const { return GetSchemaValue<bool>(m_ptr, "CMapVetoPickController", "m_bNeedToPlayFiveSecondsRemaining"); }
    void SetNeedToPlayFiveSecondsRemaining(bool value) { SetSchemaValue(m_ptr, "CMapVetoPickController", "m_bNeedToPlayFiveSecondsRemaining", false, value); }
    double GetDblPreMatchDraftSequenceTime() const { return GetSchemaValue<double>(m_ptr, "CMapVetoPickController", "m_dblPreMatchDraftSequenceTime"); }
    void SetDblPreMatchDraftSequenceTime(double value) { SetSchemaValue(m_ptr, "CMapVetoPickController", "m_dblPreMatchDraftSequenceTime", false, value); }
    bool GetPreMatchDraftStateChanged() const { return GetSchemaValue<bool>(m_ptr, "CMapVetoPickController", "m_bPreMatchDraftStateChanged"); }
    void SetPreMatchDraftStateChanged(bool value) { SetSchemaValue(m_ptr, "CMapVetoPickController", "m_bPreMatchDraftStateChanged", false, value); }
    int32_t GetDraftType() const { return GetSchemaValue<int32_t>(m_ptr, "CMapVetoPickController", "m_nDraftType"); }
    void SetDraftType(int32_t value) { SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nDraftType", false, value); }
    int32_t GetTeamWinningCoinToss() const { return GetSchemaValue<int32_t>(m_ptr, "CMapVetoPickController", "m_nTeamWinningCoinToss"); }
    void SetTeamWinningCoinToss(int32_t value) { SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nTeamWinningCoinToss", false, value); }
    std::vector<int32_t> GetTeamWithFirstChoice() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nTeamWithFirstChoice"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetTeamWithFirstChoice(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nTeamWithFirstChoice"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nTeamWithFirstChoice", false, outValue); }
    std::vector<int32_t> GetVoteMapIdsList() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nVoteMapIdsList"); std::vector<int32_t> ret; for(int i = 0; i < 7; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetVoteMapIdsList(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nVoteMapIdsList"); for(int i = 0; i < 7; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nVoteMapIdsList", false, outValue); }
    std::vector<int32_t> GetAccountIDs() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nAccountIDs"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetAccountIDs(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nAccountIDs"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nAccountIDs", false, outValue); }
    std::vector<int32_t> GetMapId0() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId0"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetMapId0(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId0"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId0", false, outValue); }
    std::vector<int32_t> GetMapId1() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId1"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetMapId1(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId1"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId1", false, outValue); }
    std::vector<int32_t> GetMapId2() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId2"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetMapId2(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId2"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId2", false, outValue); }
    std::vector<int32_t> GetMapId3() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId3"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetMapId3(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId3"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId3", false, outValue); }
    std::vector<int32_t> GetMapId4() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId4"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetMapId4(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId4"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId4", false, outValue); }
    std::vector<int32_t> GetMapId5() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId5"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetMapId5(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId5"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId5", false, outValue); }
    std::vector<int32_t> GetStartingSide0() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nStartingSide0"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetStartingSide0(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nStartingSide0"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nStartingSide0", false, outValue); }
    int32_t GetCurrentPhase() const { return GetSchemaValue<int32_t>(m_ptr, "CMapVetoPickController", "m_nCurrentPhase"); }
    void SetCurrentPhase(int32_t value) { SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nCurrentPhase", false, value); }
    int32_t GetPhaseStartTick() const { return GetSchemaValue<int32_t>(m_ptr, "CMapVetoPickController", "m_nPhaseStartTick"); }
    void SetPhaseStartTick(int32_t value) { SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nPhaseStartTick", false, value); }
    int32_t GetPhaseDurationTicks() const { return GetSchemaValue<int32_t>(m_ptr, "CMapVetoPickController", "m_nPhaseDurationTicks"); }
    void SetPhaseDurationTicks(int32_t value) { SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nPhaseDurationTicks", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif