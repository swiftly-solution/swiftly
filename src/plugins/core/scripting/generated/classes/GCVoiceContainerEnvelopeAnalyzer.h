class GCVoiceContainerEnvelopeAnalyzer;

#ifndef _gccvoicecontainerenvelopeanalyzer_h
#define _gccvoicecontainerenvelopeanalyzer_h

#include "../../../scripting.h"

#include "../types/GEMode_t.h"


class GCVoiceContainerEnvelopeAnalyzer
{
private:
    void *m_ptr;

public:
    GCVoiceContainerEnvelopeAnalyzer() {}
    GCVoiceContainerEnvelopeAnalyzer(void *ptr) : m_ptr(ptr) {}

    EMode_t GetMode() const { return GetSchemaValue<EMode_t>(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_mode"); }
    void SetMode(EMode_t value) { SetSchemaValue(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_mode", false, value); }
    int32_t GetSamples() const { return GetSchemaValue<int32_t>(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_nSamples"); }
    void SetSamples(int32_t value) { SetSchemaValue(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_nSamples", false, value); }
    float GetThreshold() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_flThreshold"); }
    void SetThreshold(float value) { SetSchemaValue(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_flThreshold", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif