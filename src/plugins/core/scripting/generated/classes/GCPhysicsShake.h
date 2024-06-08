class GCPhysicsShake;

#ifndef _gccphysicsshake_h
#define _gccphysicsshake_h

#include "../../../scripting.h"




class GCPhysicsShake
{
private:
    void *m_ptr;

public:
    GCPhysicsShake() {}
    GCPhysicsShake(void *ptr) : m_ptr(ptr) {}

    Vector GetForce() const { return GetSchemaValue<Vector>(m_ptr, "CPhysicsShake", "m_force"); }
    void SetForce(Vector value) { SetSchemaValue(m_ptr, "CPhysicsShake", "m_force", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif