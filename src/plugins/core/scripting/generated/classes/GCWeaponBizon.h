class GCWeaponBizon;

#ifndef _gccweaponbizon_h
#define _gccweaponbizon_h

#include "../../../scripting.h"




class GCWeaponBizon
{
private:
    void *m_ptr;

public:
    GCWeaponBizon() {}
    GCWeaponBizon(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif