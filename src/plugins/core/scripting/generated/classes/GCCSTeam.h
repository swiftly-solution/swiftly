class GCCSTeam;

#ifndef _gcccsteam_h
#define _gcccsteam_h

#include "../../../scripting.h"




class GCCSTeam
{
private:
    void *m_ptr;

public:
    GCCSTeam() {}
    GCCSTeam(void *ptr) : m_ptr(ptr) {}

    int32_t GetLastRecievedShorthandedRoundBonus() const { return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_nLastRecievedShorthandedRoundBonus"); }
    void SetLastRecievedShorthandedRoundBonus(int32_t value) { SetSchemaValue(m_ptr, "CCSTeam", "m_nLastRecievedShorthandedRoundBonus", false, value); }
    int32_t GetShorthandedRoundBonusStartRound() const { return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_nShorthandedRoundBonusStartRound"); }
    void SetShorthandedRoundBonusStartRound(int32_t value) { SetSchemaValue(m_ptr, "CCSTeam", "m_nShorthandedRoundBonusStartRound", false, value); }
    bool GetSurrendered() const { return GetSchemaValue<bool>(m_ptr, "CCSTeam", "m_bSurrendered"); }
    void SetSurrendered(bool value) { SetSchemaValue(m_ptr, "CCSTeam", "m_bSurrendered", false, value); }
    std::string GetTeamMatchStat() const { return GetSchemaValue<char*>(m_ptr, "CCSTeam", "m_szTeamMatchStat"); }
    void SetTeamMatchStat(std::string value) { SetSchemaValue(m_ptr, "CCSTeam", "m_szTeamMatchStat", false, value); }
    int32_t GetNumMapVictories() const { return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_numMapVictories"); }
    void SetNumMapVictories(int32_t value) { SetSchemaValue(m_ptr, "CCSTeam", "m_numMapVictories", false, value); }
    int32_t GetScoreFirstHalf() const { return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_scoreFirstHalf"); }
    void SetScoreFirstHalf(int32_t value) { SetSchemaValue(m_ptr, "CCSTeam", "m_scoreFirstHalf", false, value); }
    int32_t GetScoreSecondHalf() const { return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_scoreSecondHalf"); }
    void SetScoreSecondHalf(int32_t value) { SetSchemaValue(m_ptr, "CCSTeam", "m_scoreSecondHalf", false, value); }
    int32_t GetScoreOvertime() const { return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_scoreOvertime"); }
    void SetScoreOvertime(int32_t value) { SetSchemaValue(m_ptr, "CCSTeam", "m_scoreOvertime", false, value); }
    std::string GetClanTeamname() const { return GetSchemaValue<char*>(m_ptr, "CCSTeam", "m_szClanTeamname"); }
    void SetClanTeamname(std::string value) { SetSchemaValue(m_ptr, "CCSTeam", "m_szClanTeamname", false, value); }
    uint32_t GetClanID() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSTeam", "m_iClanID"); }
    void SetClanID(uint32_t value) { SetSchemaValue(m_ptr, "CCSTeam", "m_iClanID", false, value); }
    std::string GetTeamFlagImage() const { return GetSchemaValue<char*>(m_ptr, "CCSTeam", "m_szTeamFlagImage"); }
    void SetTeamFlagImage(std::string value) { SetSchemaValue(m_ptr, "CCSTeam", "m_szTeamFlagImage", false, value); }
    std::string GetTeamLogoImage() const { return GetSchemaValue<char*>(m_ptr, "CCSTeam", "m_szTeamLogoImage"); }
    void SetTeamLogoImage(std::string value) { SetSchemaValue(m_ptr, "CCSTeam", "m_szTeamLogoImage", false, value); }
    float GetNextResourceTime() const { return GetSchemaValue<float>(m_ptr, "CCSTeam", "m_flNextResourceTime"); }
    void SetNextResourceTime(float value) { SetSchemaValue(m_ptr, "CCSTeam", "m_flNextResourceTime", false, value); }
    int32_t GetLastUpdateSentAt() const { return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_iLastUpdateSentAt"); }
    void SetLastUpdateSentAt(int32_t value) { SetSchemaValue(m_ptr, "CCSTeam", "m_iLastUpdateSentAt", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif