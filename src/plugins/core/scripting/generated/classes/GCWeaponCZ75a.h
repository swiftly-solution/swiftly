class GCWeaponCZ75a;

#ifndef _gccweaponcz75a_h
#define _gccweaponcz75a_h

#include "../../../scripting.h"




class GCWeaponCZ75a
{
private:
    void *m_ptr;

public:
    GCWeaponCZ75a() {}
    GCWeaponCZ75a(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif