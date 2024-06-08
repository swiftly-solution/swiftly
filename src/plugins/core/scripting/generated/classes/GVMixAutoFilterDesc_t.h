class GVMixAutoFilterDesc_t;

#ifndef _gcvmixautofilterdesc_t_h
#define _gcvmixautofilterdesc_t_h

#include "../../../scripting.h"

#include "../types/GVMixLFOShape_t.h"
#include "GVMixFilterDesc_t.h"

class GVMixAutoFilterDesc_t
{
private:
    void *m_ptr;

public:
    GVMixAutoFilterDesc_t() {}
    GVMixAutoFilterDesc_t(void *ptr) : m_ptr(ptr) {}

    float GetEnvelopeAmount() const { return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flEnvelopeAmount"); }
    void SetEnvelopeAmount(float value) { SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flEnvelopeAmount", true, value); }
    float GetAttackTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flAttackTimeMS"); }
    void SetAttackTimeMS(float value) { SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flAttackTimeMS", true, value); }
    float GetReleaseTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flReleaseTimeMS"); }
    void SetReleaseTimeMS(float value) { SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flReleaseTimeMS", true, value); }
    GVMixFilterDesc_t GetFilter() const { return GetSchemaValue<GVMixFilterDesc_t>(m_ptr, "VMixAutoFilterDesc_t", "m_filter"); }
    void SetFilter(GVMixFilterDesc_t value) { SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_filter", true, value); }
    float GetLFOAmount() const { return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flLFOAmount"); }
    void SetLFOAmount(float value) { SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flLFOAmount", true, value); }
    float GetLFORate() const { return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flLFORate"); }
    void SetLFORate(float value) { SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flLFORate", true, value); }
    float GetPhase() const { return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flPhase"); }
    void SetPhase(float value) { SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flPhase", true, value); }
    VMixLFOShape_t GetLFOShape() const { return GetSchemaValue<VMixLFOShape_t>(m_ptr, "VMixAutoFilterDesc_t", "m_nLFOShape"); }
    void SetLFOShape(VMixLFOShape_t value) { SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_nLFOShape", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif