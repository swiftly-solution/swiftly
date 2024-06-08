class GCWeaponP90;

#ifndef _gccweaponp90_h
#define _gccweaponp90_h

#include "../../../scripting.h"




class GCWeaponP90
{
private:
    void *m_ptr;

public:
    GCWeaponP90() {}
    GCWeaponP90(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif