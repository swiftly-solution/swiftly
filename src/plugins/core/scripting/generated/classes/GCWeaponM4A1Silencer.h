class GCWeaponM4A1Silencer;

#ifndef _gccweaponm4a1silencer_h
#define _gccweaponm4a1silencer_h

#include "../../../scripting.h"




class GCWeaponM4A1Silencer
{
private:
    void *m_ptr;

public:
    GCWeaponM4A1Silencer() {}
    GCWeaponM4A1Silencer(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif