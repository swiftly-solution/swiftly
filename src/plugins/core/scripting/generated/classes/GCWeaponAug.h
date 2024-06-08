class GCWeaponAug;

#ifndef _gccweaponaug_h
#define _gccweaponaug_h

#include "../../../scripting.h"




class GCWeaponAug
{
private:
    void *m_ptr;

public:
    GCWeaponAug() {}
    GCWeaponAug(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif