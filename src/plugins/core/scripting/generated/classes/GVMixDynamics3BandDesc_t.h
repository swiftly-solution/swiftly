class GVMixDynamics3BandDesc_t;

#ifndef _gcvmixdynamics3banddesc_t_h
#define _gcvmixdynamics3banddesc_t_h

#include "../../../scripting.h"


#include "GVMixDynamicsBand_t.h"

class GVMixDynamics3BandDesc_t
{
private:
    void *m_ptr;

public:
    GVMixDynamics3BandDesc_t() {}
    GVMixDynamics3BandDesc_t(void *ptr) : m_ptr(ptr) {}

    float GetFldbGainOutput() const { return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_fldbGainOutput"); }
    void SetFldbGainOutput(float value) { SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_fldbGainOutput", true, value); }
    float GetRMSTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flRMSTimeMS"); }
    void SetRMSTimeMS(float value) { SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flRMSTimeMS", true, value); }
    float GetFldbKneeWidth() const { return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_fldbKneeWidth"); }
    void SetFldbKneeWidth(float value) { SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_fldbKneeWidth", true, value); }
    float GetDepth() const { return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flDepth"); }
    void SetDepth(float value) { SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flDepth", true, value); }
    float GetWetMix() const { return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flWetMix"); }
    void SetWetMix(float value) { SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flWetMix", true, value); }
    float GetTimeScale() const { return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flTimeScale"); }
    void SetTimeScale(float value) { SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flTimeScale", true, value); }
    float GetLowCutoffFreq() const { return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flLowCutoffFreq"); }
    void SetLowCutoffFreq(float value) { SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flLowCutoffFreq", true, value); }
    float GetHighCutoffFreq() const { return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flHighCutoffFreq"); }
    void SetHighCutoffFreq(float value) { SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flHighCutoffFreq", true, value); }
    bool GetPeakMode() const { return GetSchemaValue<bool>(m_ptr, "VMixDynamics3BandDesc_t", "m_bPeakMode"); }
    void SetPeakMode(bool value) { SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_bPeakMode", true, value); }
    std::vector<GVMixDynamicsBand_t> GetBandDesc() const { GVMixDynamicsBand_t* outValue = GetSchemaValue<GVMixDynamicsBand_t*>(m_ptr, "VMixDynamics3BandDesc_t", "m_bandDesc"); std::vector<GVMixDynamicsBand_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetBandDesc(std::vector<GVMixDynamicsBand_t> value) { GVMixDynamicsBand_t* outValue = GetSchemaValue<GVMixDynamicsBand_t*>(m_ptr, "VMixDynamics3BandDesc_t", "m_bandDesc"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_bandDesc", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif