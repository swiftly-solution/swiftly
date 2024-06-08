class GVMixDynamicsDesc_t;

#ifndef _gcvmixdynamicsdesc_t_h
#define _gcvmixdynamicsdesc_t_h

#include "../../../scripting.h"




class GVMixDynamicsDesc_t
{
private:
    void *m_ptr;

public:
    GVMixDynamicsDesc_t() {}
    GVMixDynamicsDesc_t(void *ptr) : m_ptr(ptr) {}

    float GetFldbGain() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_fldbGain"); }
    void SetFldbGain(float value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_fldbGain", true, value); }
    float GetFldbNoiseGateThreshold() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_fldbNoiseGateThreshold"); }
    void SetFldbNoiseGateThreshold(float value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_fldbNoiseGateThreshold", true, value); }
    float GetFldbCompressionThreshold() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_fldbCompressionThreshold"); }
    void SetFldbCompressionThreshold(float value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_fldbCompressionThreshold", true, value); }
    float GetFldbLimiterThreshold() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_fldbLimiterThreshold"); }
    void SetFldbLimiterThreshold(float value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_fldbLimiterThreshold", true, value); }
    float GetFldbKneeWidth() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_fldbKneeWidth"); }
    void SetFldbKneeWidth(float value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_fldbKneeWidth", true, value); }
    float GetRatio() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flRatio"); }
    void SetRatio(float value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flRatio", true, value); }
    float GetLimiterRatio() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flLimiterRatio"); }
    void SetLimiterRatio(float value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flLimiterRatio", true, value); }
    float GetAttackTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flAttackTimeMS"); }
    void SetAttackTimeMS(float value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flAttackTimeMS", true, value); }
    float GetReleaseTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flReleaseTimeMS"); }
    void SetReleaseTimeMS(float value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flReleaseTimeMS", true, value); }
    float GetRMSTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flRMSTimeMS"); }
    void SetRMSTimeMS(float value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flRMSTimeMS", true, value); }
    float GetWetMix() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flWetMix"); }
    void SetWetMix(float value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flWetMix", true, value); }
    bool GetPeakMode() const { return GetSchemaValue<bool>(m_ptr, "VMixDynamicsDesc_t", "m_bPeakMode"); }
    void SetPeakMode(bool value) { SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_bPeakMode", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif