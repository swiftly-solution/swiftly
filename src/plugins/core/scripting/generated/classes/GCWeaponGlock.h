class GCWeaponGlock;

#ifndef _gccweaponglock_h
#define _gccweaponglock_h

#include "../../../scripting.h"




class GCWeaponGlock
{
private:
    void *m_ptr;

public:
    GCWeaponGlock() {}
    GCWeaponGlock(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif