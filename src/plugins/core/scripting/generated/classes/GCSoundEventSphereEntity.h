class GCSoundEventSphereEntity;

#ifndef _gccsoundeventsphereentity_h
#define _gccsoundeventsphereentity_h

#include "../../../scripting.h"




class GCSoundEventSphereEntity
{
private:
    void *m_ptr;

public:
    GCSoundEventSphereEntity() {}
    GCSoundEventSphereEntity(void *ptr) : m_ptr(ptr) {}

    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CSoundEventSphereEntity", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CSoundEventSphereEntity", "m_flRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif