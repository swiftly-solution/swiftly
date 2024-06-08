class GCBumpMineProjectile;

#ifndef _gccbumpmineprojectile_h
#define _gccbumpmineprojectile_h

#include "../../../scripting.h"




class GCBumpMineProjectile
{
private:
    void *m_ptr;

public:
    GCBumpMineProjectile() {}
    GCBumpMineProjectile(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif