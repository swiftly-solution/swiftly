class GCSoundEnvelope;

#ifndef _gccsoundenvelope_h
#define _gccsoundenvelope_h

#include "../../../scripting.h"




class GCSoundEnvelope
{
private:
    void *m_ptr;

public:
    GCSoundEnvelope() {}
    GCSoundEnvelope(void *ptr) : m_ptr(ptr) {}

    float GetCurrent() const { return GetSchemaValue<float>(m_ptr, "CSoundEnvelope", "m_current"); }
    void SetCurrent(float value) { SetSchemaValue(m_ptr, "CSoundEnvelope", "m_current", false, value); }
    float GetTarget() const { return GetSchemaValue<float>(m_ptr, "CSoundEnvelope", "m_target"); }
    void SetTarget(float value) { SetSchemaValue(m_ptr, "CSoundEnvelope", "m_target", false, value); }
    float GetRate() const { return GetSchemaValue<float>(m_ptr, "CSoundEnvelope", "m_rate"); }
    void SetRate(float value) { SetSchemaValue(m_ptr, "CSoundEnvelope", "m_rate", false, value); }
    bool GetForceupdate() const { return GetSchemaValue<bool>(m_ptr, "CSoundEnvelope", "m_forceupdate"); }
    void SetForceupdate(bool value) { SetSchemaValue(m_ptr, "CSoundEnvelope", "m_forceupdate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif