class GVMixOscDesc_t;

#ifndef _gcvmixoscdesc_t_h
#define _gcvmixoscdesc_t_h

#include "../../../scripting.h"

#include "../types/GVMixLFOShape_t.h"


class GVMixOscDesc_t
{
private:
    void *m_ptr;

public:
    GVMixOscDesc_t() {}
    GVMixOscDesc_t(void *ptr) : m_ptr(ptr) {}

    VMixLFOShape_t GetOscType() const { return GetSchemaValue<VMixLFOShape_t>(m_ptr, "VMixOscDesc_t", "oscType"); }
    void SetOscType(VMixLFOShape_t value) { SetSchemaValue(m_ptr, "VMixOscDesc_t", "oscType", true, value); }
    float GetFreq() const { return GetSchemaValue<float>(m_ptr, "VMixOscDesc_t", "m_freq"); }
    void SetFreq(float value) { SetSchemaValue(m_ptr, "VMixOscDesc_t", "m_freq", true, value); }
    float GetPhase() const { return GetSchemaValue<float>(m_ptr, "VMixOscDesc_t", "m_flPhase"); }
    void SetPhase(float value) { SetSchemaValue(m_ptr, "VMixOscDesc_t", "m_flPhase", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif