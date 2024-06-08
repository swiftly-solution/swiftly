class GCTriggerImpact;

#ifndef _gcctriggerimpact_h
#define _gcctriggerimpact_h

#include "../../../scripting.h"




class GCTriggerImpact
{
private:
    void *m_ptr;

public:
    GCTriggerImpact() {}
    GCTriggerImpact(void *ptr) : m_ptr(ptr) {}

    float GetMagnitude() const { return GetSchemaValue<float>(m_ptr, "CTriggerImpact", "m_flMagnitude"); }
    void SetMagnitude(float value) { SetSchemaValue(m_ptr, "CTriggerImpact", "m_flMagnitude", false, value); }
    float GetNoise() const { return GetSchemaValue<float>(m_ptr, "CTriggerImpact", "m_flNoise"); }
    void SetNoise(float value) { SetSchemaValue(m_ptr, "CTriggerImpact", "m_flNoise", false, value); }
    float GetViewkick() const { return GetSchemaValue<float>(m_ptr, "CTriggerImpact", "m_flViewkick"); }
    void SetViewkick(float value) { SetSchemaValue(m_ptr, "CTriggerImpact", "m_flViewkick", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif