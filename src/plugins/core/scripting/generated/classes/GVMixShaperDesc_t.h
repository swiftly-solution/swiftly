class GVMixShaperDesc_t;

#ifndef _gcvmixshaperdesc_t_h
#define _gcvmixshaperdesc_t_h

#include "../../../scripting.h"




class GVMixShaperDesc_t
{
private:
    void *m_ptr;

public:
    GVMixShaperDesc_t() {}
    GVMixShaperDesc_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetShape() const { return GetSchemaValue<int32_t>(m_ptr, "VMixShaperDesc_t", "m_nShape"); }
    void SetShape(int32_t value) { SetSchemaValue(m_ptr, "VMixShaperDesc_t", "m_nShape", true, value); }
    float GetFldbDrive() const { return GetSchemaValue<float>(m_ptr, "VMixShaperDesc_t", "m_fldbDrive"); }
    void SetFldbDrive(float value) { SetSchemaValue(m_ptr, "VMixShaperDesc_t", "m_fldbDrive", true, value); }
    float GetFldbOutputGain() const { return GetSchemaValue<float>(m_ptr, "VMixShaperDesc_t", "m_fldbOutputGain"); }
    void SetFldbOutputGain(float value) { SetSchemaValue(m_ptr, "VMixShaperDesc_t", "m_fldbOutputGain", true, value); }
    float GetWetMix() const { return GetSchemaValue<float>(m_ptr, "VMixShaperDesc_t", "m_flWetMix"); }
    void SetWetMix(float value) { SetSchemaValue(m_ptr, "VMixShaperDesc_t", "m_flWetMix", true, value); }
    int32_t GetOversampleFactor() const { return GetSchemaValue<int32_t>(m_ptr, "VMixShaperDesc_t", "m_nOversampleFactor"); }
    void SetOversampleFactor(int32_t value) { SetSchemaValue(m_ptr, "VMixShaperDesc_t", "m_nOversampleFactor", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif