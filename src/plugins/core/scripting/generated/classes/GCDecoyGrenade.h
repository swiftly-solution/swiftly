class GCDecoyGrenade;

#ifndef _gccdecoygrenade_h
#define _gccdecoygrenade_h

#include "../../../scripting.h"




class GCDecoyGrenade
{
private:
    void *m_ptr;

public:
    GCDecoyGrenade() {}
    GCDecoyGrenade(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif