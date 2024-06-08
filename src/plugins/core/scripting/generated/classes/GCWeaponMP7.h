class GCWeaponMP7;

#ifndef _gccweaponmp7_h
#define _gccweaponmp7_h

#include "../../../scripting.h"




class GCWeaponMP7
{
private:
    void *m_ptr;

public:
    GCWeaponMP7() {}
    GCWeaponMP7(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif