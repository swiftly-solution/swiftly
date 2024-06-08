class GCVoiceContainerAmpedDecayingSineWave;

#ifndef _gccvoicecontainerampeddecayingsinewave_h
#define _gccvoicecontainerampeddecayingsinewave_h

#include "../../../scripting.h"




class GCVoiceContainerAmpedDecayingSineWave
{
private:
    void *m_ptr;

public:
    GCVoiceContainerAmpedDecayingSineWave() {}
    GCVoiceContainerAmpedDecayingSineWave(void *ptr) : m_ptr(ptr) {}

    float GetGainAmount() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerAmpedDecayingSineWave", "m_flGainAmount"); }
    void SetGainAmount(float value) { SetSchemaValue(m_ptr, "CVoiceContainerAmpedDecayingSineWave", "m_flGainAmount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif