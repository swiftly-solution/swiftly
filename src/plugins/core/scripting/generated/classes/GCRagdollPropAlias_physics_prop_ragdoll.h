class GCRagdollPropAlias_physics_prop_ragdoll;

#ifndef _gccragdollpropalias_physics_prop_ragdoll_h
#define _gccragdollpropalias_physics_prop_ragdoll_h

#include "../../../scripting.h"




class GCRagdollPropAlias_physics_prop_ragdoll
{
private:
    void *m_ptr;

public:
    GCRagdollPropAlias_physics_prop_ragdoll() {}
    GCRagdollPropAlias_physics_prop_ragdoll(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif