class GCWeaponM249;

#ifndef _gccweaponm249_h
#define _gccweaponm249_h

#include "../../../scripting.h"




class GCWeaponM249
{
private:
    void *m_ptr;

public:
    GCWeaponM249() {}
    GCWeaponM249(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif