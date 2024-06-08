class GCWeaponSSG08;

#ifndef _gccweaponssg08_h
#define _gccweaponssg08_h

#include "../../../scripting.h"




class GCWeaponSSG08
{
private:
    void *m_ptr;

public:
    GCWeaponSSG08() {}
    GCWeaponSSG08(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif