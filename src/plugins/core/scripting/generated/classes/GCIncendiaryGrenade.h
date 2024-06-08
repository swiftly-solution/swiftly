class GCIncendiaryGrenade;

#ifndef _gccincendiarygrenade_h
#define _gccincendiarygrenade_h

#include "../../../scripting.h"




class GCIncendiaryGrenade
{
private:
    void *m_ptr;

public:
    GCIncendiaryGrenade() {}
    GCIncendiaryGrenade(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif