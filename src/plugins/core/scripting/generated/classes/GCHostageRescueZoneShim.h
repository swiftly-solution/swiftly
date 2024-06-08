class GCHostageRescueZoneShim;

#ifndef _gcchostagerescuezoneshim_h
#define _gcchostagerescuezoneshim_h

#include "../../../scripting.h"




class GCHostageRescueZoneShim
{
private:
    void *m_ptr;

public:
    GCHostageRescueZoneShim() {}
    GCHostageRescueZoneShim(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif