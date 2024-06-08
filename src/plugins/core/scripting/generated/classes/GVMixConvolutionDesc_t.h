class GVMixConvolutionDesc_t;

#ifndef _gcvmixconvolutiondesc_t_h
#define _gcvmixconvolutiondesc_t_h

#include "../../../scripting.h"




class GVMixConvolutionDesc_t
{
private:
    void *m_ptr;

public:
    GVMixConvolutionDesc_t() {}
    GVMixConvolutionDesc_t(void *ptr) : m_ptr(ptr) {}

    float GetFldbGain() const { return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_fldbGain"); }
    void SetFldbGain(float value) { SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_fldbGain", true, value); }
    float GetPreDelayMS() const { return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_flPreDelayMS"); }
    void SetPreDelayMS(float value) { SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_flPreDelayMS", true, value); }
    float GetWetMix() const { return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_flWetMix"); }
    void SetWetMix(float value) { SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_flWetMix", true, value); }
    float GetFldbLow() const { return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_fldbLow"); }
    void SetFldbLow(float value) { SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_fldbLow", true, value); }
    float GetFldbMid() const { return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_fldbMid"); }
    void SetFldbMid(float value) { SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_fldbMid", true, value); }
    float GetFldbHigh() const { return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_fldbHigh"); }
    void SetFldbHigh(float value) { SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_fldbHigh", true, value); }
    float GetLowCutoffFreq() const { return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_flLowCutoffFreq"); }
    void SetLowCutoffFreq(float value) { SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_flLowCutoffFreq", true, value); }
    float GetHighCutoffFreq() const { return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_flHighCutoffFreq"); }
    void SetHighCutoffFreq(float value) { SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_flHighCutoffFreq", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif