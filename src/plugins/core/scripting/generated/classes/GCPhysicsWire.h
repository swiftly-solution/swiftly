class GCPhysicsWire;

#ifndef _gccphysicswire_h
#define _gccphysicswire_h

#include "../../../scripting.h"




class GCPhysicsWire
{
private:
    void *m_ptr;

public:
    GCPhysicsWire() {}
    GCPhysicsWire(void *ptr) : m_ptr(ptr) {}

    int32_t GetDensity() const { return GetSchemaValue<int32_t>(m_ptr, "CPhysicsWire", "m_nDensity"); }
    void SetDensity(int32_t value) { SetSchemaValue(m_ptr, "CPhysicsWire", "m_nDensity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif