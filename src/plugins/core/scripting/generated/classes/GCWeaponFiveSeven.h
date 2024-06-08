class GCWeaponFiveSeven;

#ifndef _gccweaponfiveseven_h
#define _gccweaponfiveseven_h

#include "../../../scripting.h"




class GCWeaponFiveSeven
{
private:
    void *m_ptr;

public:
    GCWeaponFiveSeven() {}
    GCWeaponFiveSeven(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif