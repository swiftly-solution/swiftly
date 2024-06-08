class GCWaterBullet;

#ifndef _gccwaterbullet_h
#define _gccwaterbullet_h

#include "../../../scripting.h"




class GCWaterBullet
{
private:
    void *m_ptr;

public:
    GCWaterBullet() {}
    GCWaterBullet(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif