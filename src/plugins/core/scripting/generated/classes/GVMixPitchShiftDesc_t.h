class GVMixPitchShiftDesc_t;

#ifndef _gcvmixpitchshiftdesc_t_h
#define _gcvmixpitchshiftdesc_t_h

#include "../../../scripting.h"




class GVMixPitchShiftDesc_t
{
private:
    void *m_ptr;

public:
    GVMixPitchShiftDesc_t() {}
    GVMixPitchShiftDesc_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetGrainSampleCount() const { return GetSchemaValue<int32_t>(m_ptr, "VMixPitchShiftDesc_t", "m_nGrainSampleCount"); }
    void SetGrainSampleCount(int32_t value) { SetSchemaValue(m_ptr, "VMixPitchShiftDesc_t", "m_nGrainSampleCount", true, value); }
    float GetPitchShift() const { return GetSchemaValue<float>(m_ptr, "VMixPitchShiftDesc_t", "m_flPitchShift"); }
    void SetPitchShift(float value) { SetSchemaValue(m_ptr, "VMixPitchShiftDesc_t", "m_flPitchShift", true, value); }
    int32_t GetQuality() const { return GetSchemaValue<int32_t>(m_ptr, "VMixPitchShiftDesc_t", "m_nQuality"); }
    void SetQuality(int32_t value) { SetSchemaValue(m_ptr, "VMixPitchShiftDesc_t", "m_nQuality", true, value); }
    int32_t GetProcType() const { return GetSchemaValue<int32_t>(m_ptr, "VMixPitchShiftDesc_t", "m_nProcType"); }
    void SetProcType(int32_t value) { SetSchemaValue(m_ptr, "VMixPitchShiftDesc_t", "m_nProcType", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif