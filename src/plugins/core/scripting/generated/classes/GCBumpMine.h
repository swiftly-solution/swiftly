class GCBumpMine;

#ifndef _gccbumpmine_h
#define _gccbumpmine_h

#include "../../../scripting.h"




class GCBumpMine
{
private:
    void *m_ptr;

public:
    GCBumpMine() {}
    GCBumpMine(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif