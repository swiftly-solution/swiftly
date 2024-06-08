class GCWeaponUMP45;

#ifndef _gccweaponump45_h
#define _gccweaponump45_h

#include "../../../scripting.h"




class GCWeaponUMP45
{
private:
    void *m_ptr;

public:
    GCWeaponUMP45() {}
    GCWeaponUMP45(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif