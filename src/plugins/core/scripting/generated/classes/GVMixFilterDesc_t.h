class GVMixFilterDesc_t;

#ifndef _gcvmixfilterdesc_t_h
#define _gcvmixfilterdesc_t_h

#include "../../../scripting.h"

#include "../types/GVMixFilterType_t.h"
#include "../types/GVMixFilterSlope_t.h"


class GVMixFilterDesc_t
{
private:
    void *m_ptr;

public:
    GVMixFilterDesc_t() {}
    GVMixFilterDesc_t(void *ptr) : m_ptr(ptr) {}

    VMixFilterType_t GetFilterType() const { return GetSchemaValue<VMixFilterType_t>(m_ptr, "VMixFilterDesc_t", "m_nFilterType"); }
    void SetFilterType(VMixFilterType_t value) { SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_nFilterType", true, value); }
    VMixFilterSlope_t GetFilterSlope() const { return GetSchemaValue<VMixFilterSlope_t>(m_ptr, "VMixFilterDesc_t", "m_nFilterSlope"); }
    void SetFilterSlope(VMixFilterSlope_t value) { SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_nFilterSlope", true, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "VMixFilterDesc_t", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_bEnabled", true, value); }
    float GetFldbGain() const { return GetSchemaValue<float>(m_ptr, "VMixFilterDesc_t", "m_fldbGain"); }
    void SetFldbGain(float value) { SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_fldbGain", true, value); }
    float GetCutoffFreq() const { return GetSchemaValue<float>(m_ptr, "VMixFilterDesc_t", "m_flCutoffFreq"); }
    void SetCutoffFreq(float value) { SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_flCutoffFreq", true, value); }
    float GetQ() const { return GetSchemaValue<float>(m_ptr, "VMixFilterDesc_t", "m_flQ"); }
    void SetQ(float value) { SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_flQ", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif