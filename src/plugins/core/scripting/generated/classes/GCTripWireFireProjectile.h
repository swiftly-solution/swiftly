class GCTripWireFireProjectile;

#ifndef _gcctripwirefireprojectile_h
#define _gcctripwirefireprojectile_h

#include "../../../scripting.h"




class GCTripWireFireProjectile
{
private:
    void *m_ptr;

public:
    GCTripWireFireProjectile() {}
    GCTripWireFireProjectile(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif