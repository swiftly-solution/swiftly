class GCWeaponTec9;

#ifndef _gccweapontec9_h
#define _gccweapontec9_h

#include "../../../scripting.h"




class GCWeaponTec9
{
private:
    void *m_ptr;

public:
    GCWeaponTec9() {}
    GCWeaponTec9(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif