class GCTriggerProximity;

#ifndef _gcctriggerproximity_h
#define _gcctriggerproximity_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCTriggerProximity
{
private:
    void *m_ptr;

public:
    GCTriggerProximity() {}
    GCTriggerProximity(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetMeasureTarget() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CTriggerProximity", "m_hMeasureTarget"); }
    void SetMeasureTarget(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'MeasureTarget' is not possible.\n"); }
    CUtlSymbolLarge GetMeasureTarget1() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerProximity", "m_iszMeasureTarget"); }
    void SetMeasureTarget1(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerProximity", "m_iszMeasureTarget", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CTriggerProximity", "m_fRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CTriggerProximity", "m_fRadius", false, value); }
    int32_t GetTouchers() const { return GetSchemaValue<int32_t>(m_ptr, "CTriggerProximity", "m_nTouchers"); }
    void SetTouchers(int32_t value) { SetSchemaValue(m_ptr, "CTriggerProximity", "m_nTouchers", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif