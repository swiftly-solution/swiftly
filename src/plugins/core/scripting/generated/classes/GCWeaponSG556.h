class GCWeaponSG556;

#ifndef _gccweaponsg556_h
#define _gccweaponsg556_h

#include "../../../scripting.h"




class GCWeaponSG556
{
private:
    void *m_ptr;

public:
    GCWeaponSG556() {}
    GCWeaponSG556(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif