class GCWeaponNOVA;

#ifndef _gccweaponnova_h
#define _gccweaponnova_h

#include "../../../scripting.h"




class GCWeaponNOVA
{
private:
    void *m_ptr;

public:
    GCWeaponNOVA() {}
    GCWeaponNOVA(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif