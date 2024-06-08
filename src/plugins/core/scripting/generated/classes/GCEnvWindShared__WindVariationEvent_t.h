class GCEnvWindShared__WindVariationEvent_t;

#ifndef _gccenvwindshared__windvariationevent_t_h
#define _gccenvwindshared__windvariationevent_t_h

#include "../../../scripting.h"




class GCEnvWindShared__WindVariationEvent_t
{
private:
    void *m_ptr;

public:
    GCEnvWindShared__WindVariationEvent_t() {}
    GCEnvWindShared__WindVariationEvent_t(void *ptr) : m_ptr(ptr) {}

    float GetWindAngleVariation() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared__WindVariationEvent_t", "m_flWindAngleVariation"); }
    void SetWindAngleVariation(float value) { SetSchemaValue(m_ptr, "CEnvWindShared__WindVariationEvent_t", "m_flWindAngleVariation", true, value); }
    float GetWindSpeedVariation() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared__WindVariationEvent_t", "m_flWindSpeedVariation"); }
    void SetWindSpeedVariation(float value) { SetSchemaValue(m_ptr, "CEnvWindShared__WindVariationEvent_t", "m_flWindSpeedVariation", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif