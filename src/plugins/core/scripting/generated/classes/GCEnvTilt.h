class GCEnvTilt;

#ifndef _gccenvtilt_h
#define _gccenvtilt_h

#include "../../../scripting.h"




class GCEnvTilt
{
private:
    void *m_ptr;

public:
    GCEnvTilt() {}
    GCEnvTilt(void *ptr) : m_ptr(ptr) {}

    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CEnvTilt", "m_Duration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CEnvTilt", "m_Duration", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CEnvTilt", "m_Radius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CEnvTilt", "m_Radius", false, value); }
    float GetTiltTime() const { return GetSchemaValue<float>(m_ptr, "CEnvTilt", "m_TiltTime"); }
    void SetTiltTime(float value) { SetSchemaValue(m_ptr, "CEnvTilt", "m_TiltTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif