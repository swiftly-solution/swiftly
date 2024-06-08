class GCHEGrenade;

#ifndef _gcchegrenade_h
#define _gcchegrenade_h

#include "../../../scripting.h"




class GCHEGrenade
{
private:
    void *m_ptr;

public:
    GCHEGrenade() {}
    GCHEGrenade(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif