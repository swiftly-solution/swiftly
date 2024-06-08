class GCMolotovGrenade;

#ifndef _gccmolotovgrenade_h
#define _gccmolotovgrenade_h

#include "../../../scripting.h"




class GCMolotovGrenade
{
private:
    void *m_ptr;

public:
    GCMolotovGrenade() {}
    GCMolotovGrenade(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif