class GCSAdditionalMatchStats_t;

#ifndef _gccsadditionalmatchstats_t_h
#define _gccsadditionalmatchstats_t_h

#include "../../../scripting.h"




class GCSAdditionalMatchStats_t
{
private:
    void *m_ptr;

public:
    GCSAdditionalMatchStats_t() {}
    GCSAdditionalMatchStats_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetNumRoundsSurvived() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numRoundsSurvived"); }
    void SetNumRoundsSurvived(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numRoundsSurvived", true, value); }
    int32_t GetMaxNumRoundsSurvived() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_maxNumRoundsSurvived"); }
    void SetMaxNumRoundsSurvived(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_maxNumRoundsSurvived", true, value); }
    int32_t GetNumRoundsSurvivedTotal() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numRoundsSurvivedTotal"); }
    void SetNumRoundsSurvivedTotal(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numRoundsSurvivedTotal", true, value); }
    int32_t GetRoundsWonWithoutPurchase() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_iRoundsWonWithoutPurchase"); }
    void SetRoundsWonWithoutPurchase(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_iRoundsWonWithoutPurchase", true, value); }
    int32_t GetRoundsWonWithoutPurchaseTotal() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_iRoundsWonWithoutPurchaseTotal"); }
    void SetRoundsWonWithoutPurchaseTotal(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_iRoundsWonWithoutPurchaseTotal", true, value); }
    int32_t GetNumFirstKills() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numFirstKills"); }
    void SetNumFirstKills(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numFirstKills", true, value); }
    int32_t GetNumClutchKills() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numClutchKills"); }
    void SetNumClutchKills(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numClutchKills", true, value); }
    int32_t GetNumPistolKills() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numPistolKills"); }
    void SetNumPistolKills(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numPistolKills", true, value); }
    int32_t GetNumSniperKills() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numSniperKills"); }
    void SetNumSniperKills(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numSniperKills", true, value); }
    int32_t GetNumSuicides() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_iNumSuicides"); }
    void SetNumSuicides(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_iNumSuicides", true, value); }
    int32_t GetNumTeamKills() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_iNumTeamKills"); }
    void SetNumTeamKills(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_iNumTeamKills", true, value); }
    int32_t GetTeamDamage() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_iTeamDamage"); }
    void SetTeamDamage(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_iTeamDamage", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif