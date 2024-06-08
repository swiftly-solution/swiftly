class GCWeaponElite;

#ifndef _gccweaponelite_h
#define _gccweaponelite_h

#include "../../../scripting.h"




class GCWeaponElite
{
private:
    void *m_ptr;

public:
    GCWeaponElite() {}
    GCWeaponElite(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif