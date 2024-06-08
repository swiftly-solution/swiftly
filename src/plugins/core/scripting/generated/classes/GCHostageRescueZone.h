class GCHostageRescueZone;

#ifndef _gcchostagerescuezone_h
#define _gcchostagerescuezone_h

#include "../../../scripting.h"




class GCHostageRescueZone
{
private:
    void *m_ptr;

public:
    GCHostageRescueZone() {}
    GCHostageRescueZone(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif