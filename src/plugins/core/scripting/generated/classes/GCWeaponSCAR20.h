class GCWeaponSCAR20;

#ifndef _gccweaponscar20_h
#define _gccweaponscar20_h

#include "../../../scripting.h"




class GCWeaponSCAR20
{
private:
    void *m_ptr;

public:
    GCWeaponSCAR20() {}
    GCWeaponSCAR20(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif