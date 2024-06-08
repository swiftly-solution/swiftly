class GCSoundEventAABBEntity;

#ifndef _gccsoundeventaabbentity_h
#define _gccsoundeventaabbentity_h

#include "../../../scripting.h"




class GCSoundEventAABBEntity
{
private:
    void *m_ptr;

public:
    GCSoundEventAABBEntity() {}
    GCSoundEventAABBEntity(void *ptr) : m_ptr(ptr) {}

    Vector GetMins() const { return GetSchemaValue<Vector>(m_ptr, "CSoundEventAABBEntity", "m_vMins"); }
    void SetMins(Vector value) { SetSchemaValue(m_ptr, "CSoundEventAABBEntity", "m_vMins", false, value); }
    Vector GetMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CSoundEventAABBEntity", "m_vMaxs"); }
    void SetMaxs(Vector value) { SetSchemaValue(m_ptr, "CSoundEventAABBEntity", "m_vMaxs", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif