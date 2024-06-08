class GCWeaponMP9;

#ifndef _gccweaponmp9_h
#define _gccweaponmp9_h

#include "../../../scripting.h"




class GCWeaponMP9
{
private:
    void *m_ptr;

public:
    GCWeaponMP9() {}
    GCWeaponMP9(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif