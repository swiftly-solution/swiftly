class GCWeaponUSPSilencer;

#ifndef _gccweaponuspsilencer_h
#define _gccweaponuspsilencer_h

#include "../../../scripting.h"




class GCWeaponUSPSilencer
{
private:
    void *m_ptr;

public:
    GCWeaponUSPSilencer() {}
    GCWeaponUSPSilencer(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif