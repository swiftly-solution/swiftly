class GCEnvWindShared__WindAveEvent_t;

#ifndef _gccenvwindshared__windaveevent_t_h
#define _gccenvwindshared__windaveevent_t_h

#include "../../../scripting.h"




class GCEnvWindShared__WindAveEvent_t
{
private:
    void *m_ptr;

public:
    GCEnvWindShared__WindAveEvent_t() {}
    GCEnvWindShared__WindAveEvent_t(void *ptr) : m_ptr(ptr) {}

    float GetStartWindSpeed() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared__WindAveEvent_t", "m_flStartWindSpeed"); }
    void SetStartWindSpeed(float value) { SetSchemaValue(m_ptr, "CEnvWindShared__WindAveEvent_t", "m_flStartWindSpeed", true, value); }
    float GetAveWindSpeed() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared__WindAveEvent_t", "m_flAveWindSpeed"); }
    void SetAveWindSpeed(float value) { SetSchemaValue(m_ptr, "CEnvWindShared__WindAveEvent_t", "m_flAveWindSpeed", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif