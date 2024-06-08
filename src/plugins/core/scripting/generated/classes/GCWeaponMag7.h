class GCWeaponMag7;

#ifndef _gccweaponmag7_h
#define _gccweaponmag7_h

#include "../../../scripting.h"




class GCWeaponMag7
{
private:
    void *m_ptr;

public:
    GCWeaponMag7() {}
    GCWeaponMag7(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif