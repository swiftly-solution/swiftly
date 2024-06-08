class GCWeaponSawedoff;

#ifndef _gccweaponsawedoff_h
#define _gccweaponsawedoff_h

#include "../../../scripting.h"




class GCWeaponSawedoff
{
private:
    void *m_ptr;

public:
    GCWeaponSawedoff() {}
    GCWeaponSawedoff(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif