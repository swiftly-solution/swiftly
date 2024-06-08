class GCFootCycle;

#ifndef _gccfootcycle_h
#define _gccfootcycle_h

#include "../../../scripting.h"




class GCFootCycle
{
private:
    void *m_ptr;

public:
    GCFootCycle() {}
    GCFootCycle(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif