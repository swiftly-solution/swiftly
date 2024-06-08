class GCPhysicsPropOverride;

#ifndef _gccphysicspropoverride_h
#define _gccphysicspropoverride_h

#include "../../../scripting.h"




class GCPhysicsPropOverride
{
private:
    void *m_ptr;

public:
    GCPhysicsPropOverride() {}
    GCPhysicsPropOverride(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif