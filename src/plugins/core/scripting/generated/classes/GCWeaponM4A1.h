class GCWeaponM4A1;

#ifndef _gccweaponm4a1_h
#define _gccweaponm4a1_h

#include "../../../scripting.h"




class GCWeaponM4A1
{
private:
    void *m_ptr;

public:
    GCWeaponM4A1() {}
    GCWeaponM4A1(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif