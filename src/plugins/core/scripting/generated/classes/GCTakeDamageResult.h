class GCTakeDamageResult;

#ifndef _gcctakedamageresult_h
#define _gcctakedamageresult_h

#include "../../../scripting.h"


#include "GCTakeDamageInfo.h"

class GCTakeDamageResult
{
private:
    void *m_ptr;

public:
    GCTakeDamageResult() {}
    GCTakeDamageResult(void *ptr) : m_ptr(ptr) {}

    GCTakeDamageInfo* GetOriginatingInfo() const { return GetSchemaValue<GCTakeDamageInfo*>(m_ptr, "CTakeDamageResult", "m_pOriginatingInfo"); }
    void SetOriginatingInfo(GCTakeDamageInfo* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'OriginatingInfo' is not possible.\n"); }
    int32_t GetHealthLost() const { return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageResult", "m_nHealthLost"); }
    void SetHealthLost(int32_t value) { SetSchemaValue(m_ptr, "CTakeDamageResult", "m_nHealthLost", false, value); }
    int32_t GetDamageTaken() const { return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageResult", "m_nDamageTaken"); }
    void SetDamageTaken(int32_t value) { SetSchemaValue(m_ptr, "CTakeDamageResult", "m_nDamageTaken", false, value); }
    int32_t GetTotalledHealthLost() const { return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageResult", "m_nTotalledHealthLost"); }
    void SetTotalledHealthLost(int32_t value) { SetSchemaValue(m_ptr, "CTakeDamageResult", "m_nTotalledHealthLost", false, value); }
    int32_t GetTotalledDamageTaken() const { return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageResult", "m_nTotalledDamageTaken"); }
    void SetTotalledDamageTaken(int32_t value) { SetSchemaValue(m_ptr, "CTakeDamageResult", "m_nTotalledDamageTaken", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif