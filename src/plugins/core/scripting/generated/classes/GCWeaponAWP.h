class GCWeaponAWP;

#ifndef _gccweaponawp_h
#define _gccweaponawp_h

#include "../../../scripting.h"




class GCWeaponAWP
{
private:
    void *m_ptr;

public:
    GCWeaponAWP() {}
    GCWeaponAWP(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif