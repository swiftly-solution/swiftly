class GCWeaponMAC10;

#ifndef _gccweaponmac10_h
#define _gccweaponmac10_h

#include "../../../scripting.h"




class GCWeaponMAC10
{
private:
    void *m_ptr;

public:
    GCWeaponMAC10() {}
    GCWeaponMAC10(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif