class GCSAdditionalPerRoundStats_t;

#ifndef _gccsadditionalperroundstats_t_h
#define _gccsadditionalperroundstats_t_h

#include "../../../scripting.h"




class GCSAdditionalPerRoundStats_t
{
private:
    void *m_ptr;

public:
    GCSAdditionalPerRoundStats_t() {}
    GCSAdditionalPerRoundStats_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetNumChickensKilled() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_numChickensKilled"); }
    void SetNumChickensKilled(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_numChickensKilled", true, value); }
    int32_t GetKillsWhileBlind() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_killsWhileBlind"); }
    void SetKillsWhileBlind(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_killsWhileBlind", true, value); }
    int32_t GetBombCarrierkills() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_bombCarrierkills"); }
    void SetBombCarrierkills(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_bombCarrierkills", true, value); }
    int32_t GetBurnDamageInflicted() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_iBurnDamageInflicted"); }
    void SetBurnDamageInflicted(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_iBurnDamageInflicted", true, value); }
    int32_t GetBlastDamageInflicted() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_iBlastDamageInflicted"); }
    void SetBlastDamageInflicted(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_iBlastDamageInflicted", true, value); }
    int32_t GetDinks() const { return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_iDinks"); }
    void SetDinks(int32_t value) { SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_iDinks", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif