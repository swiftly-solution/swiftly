class GCWeaponP250;

#ifndef _gccweaponp250_h
#define _gccweaponp250_h

#include "../../../scripting.h"




class GCWeaponP250
{
private:
    void *m_ptr;

public:
    GCWeaponP250() {}
    GCWeaponP250(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif