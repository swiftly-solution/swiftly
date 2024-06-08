class GCWeaponG3SG1;

#ifndef _gccweapong3sg1_h
#define _gccweapong3sg1_h

#include "../../../scripting.h"




class GCWeaponG3SG1
{
private:
    void *m_ptr;

public:
    GCWeaponG3SG1() {}
    GCWeaponG3SG1(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif