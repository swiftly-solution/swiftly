class GCPhysicsPropMultiplayer;

#ifndef _gccphysicspropmultiplayer_h
#define _gccphysicspropmultiplayer_h

#include "../../../scripting.h"




class GCPhysicsPropMultiplayer
{
private:
    void *m_ptr;

public:
    GCPhysicsPropMultiplayer() {}
    GCPhysicsPropMultiplayer(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif