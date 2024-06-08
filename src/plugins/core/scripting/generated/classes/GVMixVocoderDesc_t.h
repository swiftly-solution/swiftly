class GVMixVocoderDesc_t;

#ifndef _gcvmixvocoderdesc_t_h
#define _gcvmixvocoderdesc_t_h

#include "../../../scripting.h"




class GVMixVocoderDesc_t
{
private:
    void *m_ptr;

public:
    GVMixVocoderDesc_t() {}
    GVMixVocoderDesc_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetBandCount() const { return GetSchemaValue<int32_t>(m_ptr, "VMixVocoderDesc_t", "m_nBandCount"); }
    void SetBandCount(int32_t value) { SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_nBandCount", true, value); }
    float GetBandwidth() const { return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_flBandwidth"); }
    void SetBandwidth(float value) { SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_flBandwidth", true, value); }
    float GetFldBModGain() const { return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_fldBModGain"); }
    void SetFldBModGain(float value) { SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_fldBModGain", true, value); }
    float GetFreqRangeStart() const { return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_flFreqRangeStart"); }
    void SetFreqRangeStart(float value) { SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_flFreqRangeStart", true, value); }
    float GetFreqRangeEnd() const { return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_flFreqRangeEnd"); }
    void SetFreqRangeEnd(float value) { SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_flFreqRangeEnd", true, value); }
    float GetFldBUnvoicedGain() const { return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_fldBUnvoicedGain"); }
    void SetFldBUnvoicedGain(float value) { SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_fldBUnvoicedGain", true, value); }
    float GetAttackTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_flAttackTimeMS"); }
    void SetAttackTimeMS(float value) { SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_flAttackTimeMS", true, value); }
    float GetReleaseTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_flReleaseTimeMS"); }
    void SetReleaseTimeMS(float value) { SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_flReleaseTimeMS", true, value); }
    int32_t GetDebugBand() const { return GetSchemaValue<int32_t>(m_ptr, "VMixVocoderDesc_t", "m_nDebugBand"); }
    void SetDebugBand(int32_t value) { SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_nDebugBand", true, value); }
    bool GetPeakMode() const { return GetSchemaValue<bool>(m_ptr, "VMixVocoderDesc_t", "m_bPeakMode"); }
    void SetPeakMode(bool value) { SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_bPeakMode", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif