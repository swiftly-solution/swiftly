class GVMixDynamicsCompressorDesc_t;

#ifndef _gcvmixdynamicscompressordesc_t_h
#define _gcvmixdynamicscompressordesc_t_h

#include "../../../scripting.h"




class GVMixDynamicsCompressorDesc_t
{
private:
    void *m_ptr;

public:
    GVMixDynamicsCompressorDesc_t() {}
    GVMixDynamicsCompressorDesc_t(void *ptr) : m_ptr(ptr) {}

    float GetFldbOutputGain() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbOutputGain"); }
    void SetFldbOutputGain(float value) { SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbOutputGain", true, value); }
    float GetFldbCompressionThreshold() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbCompressionThreshold"); }
    void SetFldbCompressionThreshold(float value) { SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbCompressionThreshold", true, value); }
    float GetFldbKneeWidth() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbKneeWidth"); }
    void SetFldbKneeWidth(float value) { SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbKneeWidth", true, value); }
    float GetCompressionRatio() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flCompressionRatio"); }
    void SetCompressionRatio(float value) { SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flCompressionRatio", true, value); }
    float GetAttackTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flAttackTimeMS"); }
    void SetAttackTimeMS(float value) { SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flAttackTimeMS", true, value); }
    float GetReleaseTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flReleaseTimeMS"); }
    void SetReleaseTimeMS(float value) { SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flReleaseTimeMS", true, value); }
    float GetRMSTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flRMSTimeMS"); }
    void SetRMSTimeMS(float value) { SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flRMSTimeMS", true, value); }
    float GetWetMix() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flWetMix"); }
    void SetWetMix(float value) { SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flWetMix", true, value); }
    bool GetPeakMode() const { return GetSchemaValue<bool>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_bPeakMode"); }
    void SetPeakMode(bool value) { SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_bPeakMode", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif