class GCWeaponHKP2000;

#ifndef _gccweaponhkp2000_h
#define _gccweaponhkp2000_h

#include "../../../scripting.h"




class GCWeaponHKP2000
{
private:
    void *m_ptr;

public:
    GCWeaponHKP2000() {}
    GCWeaponHKP2000(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif