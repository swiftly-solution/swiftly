class GCWeaponRevolver;

#ifndef _gccweaponrevolver_h
#define _gccweaponrevolver_h

#include "../../../scripting.h"




class GCWeaponRevolver
{
private:
    void *m_ptr;

public:
    GCWeaponRevolver() {}
    GCWeaponRevolver(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif