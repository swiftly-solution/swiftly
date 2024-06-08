class GCWeaponXM1014;

#ifndef _gccweaponxm1014_h
#define _gccweaponxm1014_h

#include "../../../scripting.h"




class GCWeaponXM1014
{
private:
    void *m_ptr;

public:
    GCWeaponXM1014() {}
    GCWeaponXM1014(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif