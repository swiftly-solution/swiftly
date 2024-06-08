class GCSoundEventOBBEntity;

#ifndef _gccsoundeventobbentity_h
#define _gccsoundeventobbentity_h

#include "../../../scripting.h"




class GCSoundEventOBBEntity
{
private:
    void *m_ptr;

public:
    GCSoundEventOBBEntity() {}
    GCSoundEventOBBEntity(void *ptr) : m_ptr(ptr) {}

    Vector GetMins() const { return GetSchemaValue<Vector>(m_ptr, "CSoundEventOBBEntity", "m_vMins"); }
    void SetMins(Vector value) { SetSchemaValue(m_ptr, "CSoundEventOBBEntity", "m_vMins", false, value); }
    Vector GetMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CSoundEventOBBEntity", "m_vMaxs"); }
    void SetMaxs(Vector value) { SetSchemaValue(m_ptr, "CSoundEventOBBEntity", "m_vMaxs", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif