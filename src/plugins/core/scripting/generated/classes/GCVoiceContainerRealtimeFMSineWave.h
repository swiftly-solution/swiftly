class GCVoiceContainerRealtimeFMSineWave;

#ifndef _gccvoicecontainerrealtimefmsinewave_h
#define _gccvoicecontainerrealtimefmsinewave_h

#include "../../../scripting.h"




class GCVoiceContainerRealtimeFMSineWave
{
private:
    void *m_ptr;

public:
    GCVoiceContainerRealtimeFMSineWave() {}
    GCVoiceContainerRealtimeFMSineWave(void *ptr) : m_ptr(ptr) {}

    float GetCarrierFrequency() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flCarrierFrequency"); }
    void SetCarrierFrequency(float value) { SetSchemaValue(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flCarrierFrequency", false, value); }
    float GetModulatorFrequency() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flModulatorFrequency"); }
    void SetModulatorFrequency(float value) { SetSchemaValue(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flModulatorFrequency", false, value); }
    float GetModulatorAmount() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flModulatorAmount"); }
    void SetModulatorAmount(float value) { SetSchemaValue(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flModulatorAmount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif