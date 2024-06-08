class GCVoiceContainerRandomSampler;

#ifndef _gccvoicecontainerrandomsampler_h
#define _gccvoicecontainerrandomsampler_h

#include "../../../scripting.h"




class GCVoiceContainerRandomSampler
{
private:
    void *m_ptr;

public:
    GCVoiceContainerRandomSampler() {}
    GCVoiceContainerRandomSampler(void *ptr) : m_ptr(ptr) {}

    float GetAmplitude() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerRandomSampler", "m_flAmplitude"); }
    void SetAmplitude(float value) { SetSchemaValue(m_ptr, "CVoiceContainerRandomSampler", "m_flAmplitude", false, value); }
    float GetAmplitudeJitter() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerRandomSampler", "m_flAmplitudeJitter"); }
    void SetAmplitudeJitter(float value) { SetSchemaValue(m_ptr, "CVoiceContainerRandomSampler", "m_flAmplitudeJitter", false, value); }
    float GetTimeJitter() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerRandomSampler", "m_flTimeJitter"); }
    void SetTimeJitter(float value) { SetSchemaValue(m_ptr, "CVoiceContainerRandomSampler", "m_flTimeJitter", false, value); }
    float GetMaxLength() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerRandomSampler", "m_flMaxLength"); }
    void SetMaxLength(float value) { SetSchemaValue(m_ptr, "CVoiceContainerRandomSampler", "m_flMaxLength", false, value); }
    int32_t GetNumDelayVariations() const { return GetSchemaValue<int32_t>(m_ptr, "CVoiceContainerRandomSampler", "m_nNumDelayVariations"); }
    void SetNumDelayVariations(int32_t value) { SetSchemaValue(m_ptr, "CVoiceContainerRandomSampler", "m_nNumDelayVariations", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif