class GCWeaponFamas;

#ifndef _gccweaponfamas_h
#define _gccweaponfamas_h

#include "../../../scripting.h"




class GCWeaponFamas
{
private:
    void *m_ptr;

public:
    GCWeaponFamas() {}
    GCWeaponFamas(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif