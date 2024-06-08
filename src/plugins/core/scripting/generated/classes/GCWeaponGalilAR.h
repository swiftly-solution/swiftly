class GCWeaponGalilAR;

#ifndef _gccweapongalilar_h
#define _gccweapongalilar_h

#include "../../../scripting.h"




class GCWeaponGalilAR
{
private:
    void *m_ptr;

public:
    GCWeaponGalilAR() {}
    GCWeaponGalilAR(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif