class GCAnimCycle;

#ifndef _gccanimcycle_h
#define _gccanimcycle_h

#include "../../../scripting.h"




class GCAnimCycle
{
private:
    void *m_ptr;

public:
    GCAnimCycle() {}
    GCAnimCycle(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif