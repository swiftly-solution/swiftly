class GCWeaponMP5SD;

#ifndef _gccweaponmp5sd_h
#define _gccweaponmp5sd_h

#include "../../../scripting.h"




class GCWeaponMP5SD
{
private:
    void *m_ptr;

public:
    GCWeaponMP5SD() {}
    GCWeaponMP5SD(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif