class GCWeaponNegev;

#ifndef _gccweaponnegev_h
#define _gccweaponnegev_h

#include "../../../scripting.h"




class GCWeaponNegev
{
private:
    void *m_ptr;

public:
    GCWeaponNegev() {}
    GCWeaponNegev(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif