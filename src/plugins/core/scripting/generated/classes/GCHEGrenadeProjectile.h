class GCHEGrenadeProjectile;

#ifndef _gcchegrenadeprojectile_h
#define _gcchegrenadeprojectile_h

#include "../../../scripting.h"




class GCHEGrenadeProjectile
{
private:
    void *m_ptr;

public:
    GCHEGrenadeProjectile() {}
    GCHEGrenadeProjectile(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif