class GPointDefinitionWithTimeValues_t;

#ifndef _gcpointdefinitionwithtimevalues_t_h
#define _gcpointdefinitionwithtimevalues_t_h

#include "../../../scripting.h"




class GPointDefinitionWithTimeValues_t
{
private:
    void *m_ptr;

public:
    GPointDefinitionWithTimeValues_t() {}
    GPointDefinitionWithTimeValues_t(void *ptr) : m_ptr(ptr) {}

    float GetTimeDuration() const { return GetSchemaValue<float>(m_ptr, "PointDefinitionWithTimeValues_t", "m_flTimeDuration"); }
    void SetTimeDuration(float value) { SetSchemaValue(m_ptr, "PointDefinitionWithTimeValues_t", "m_flTimeDuration", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif