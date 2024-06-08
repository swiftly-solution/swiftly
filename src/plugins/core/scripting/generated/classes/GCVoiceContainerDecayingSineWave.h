class GCVoiceContainerDecayingSineWave;

#ifndef _gccvoicecontainerdecayingsinewave_h
#define _gccvoicecontainerdecayingsinewave_h

#include "../../../scripting.h"




class GCVoiceContainerDecayingSineWave
{
private:
    void *m_ptr;

public:
    GCVoiceContainerDecayingSineWave() {}
    GCVoiceContainerDecayingSineWave(void *ptr) : m_ptr(ptr) {}

    float GetFrequency() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerDecayingSineWave", "m_flFrequency"); }
    void SetFrequency(float value) { SetSchemaValue(m_ptr, "CVoiceContainerDecayingSineWave", "m_flFrequency", false, value); }
    float GetDecayTime() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerDecayingSineWave", "m_flDecayTime"); }
    void SetDecayTime(float value) { SetSchemaValue(m_ptr, "CVoiceContainerDecayingSineWave", "m_flDecayTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif