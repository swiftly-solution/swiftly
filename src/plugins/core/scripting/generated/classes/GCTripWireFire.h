class GCTripWireFire;

#ifndef _gcctripwirefire_h
#define _gcctripwirefire_h

#include "../../../scripting.h"




class GCTripWireFire
{
private:
    void *m_ptr;

public:
    GCTripWireFire() {}
    GCTripWireFire(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif