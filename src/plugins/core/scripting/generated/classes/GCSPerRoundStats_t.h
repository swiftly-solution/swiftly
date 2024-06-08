class GCSPerRoundStats_t;

#ifndef _gccsperroundstats_t_h
#define _gccsperroundstats_t_h

#include "../../../scripting.h"




class GCSPerRoundStats_t
{
private:
    void *m_ptr;

public:
    GCSPerRoundStats_t() {}
    GCSPerRoundStats_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetKills() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iKills"); }
    void SetKills(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iKills", true, value); }
    int32_t GetDeaths() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iDeaths"); }
    void SetDeaths(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iDeaths", true, value); }
    int32_t GetAssists() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iAssists"); }
    void SetAssists(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iAssists", true, value); }
    int32_t GetDamage() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iDamage"); }
    void SetDamage(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iDamage", true, value); }
    int32_t GetEquipmentValue() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iEquipmentValue"); }
    void SetEquipmentValue(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iEquipmentValue", true, value); }
    int32_t GetMoneySaved() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iMoneySaved"); }
    void SetMoneySaved(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iMoneySaved", true, value); }
    int32_t GetKillReward() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iKillReward"); }
    void SetKillReward(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iKillReward", true, value); }
    int32_t GetLiveTime() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iLiveTime"); }
    void SetLiveTime(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iLiveTime", true, value); }
    int32_t GetHeadShotKills() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iHeadShotKills"); }
    void SetHeadShotKills(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iHeadShotKills", true, value); }
    int32_t GetObjective() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iObjective"); }
    void SetObjective(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iObjective", true, value); }
    int32_t GetCashEarned() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iCashEarned"); }
    void SetCashEarned(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iCashEarned", true, value); }
    int32_t GetUtilityDamage() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iUtilityDamage"); }
    void SetUtilityDamage(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iUtilityDamage", true, value); }
    int32_t GetEnemiesFlashed() const { return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iEnemiesFlashed"); }
    void SetEnemiesFlashed(int32_t value) { SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iEnemiesFlashed", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif