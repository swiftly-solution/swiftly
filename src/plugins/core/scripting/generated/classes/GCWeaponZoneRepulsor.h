class GCWeaponZoneRepulsor;

#ifndef _gccweaponzonerepulsor_h
#define _gccweaponzonerepulsor_h

#include "../../../scripting.h"




class GCWeaponZoneRepulsor
{
private:
    void *m_ptr;

public:
    GCWeaponZoneRepulsor() {}
    GCWeaponZoneRepulsor(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif