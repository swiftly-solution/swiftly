class GCAnimEventListenerBase;

#ifndef _gccanimeventlistenerbase_h
#define _gccanimeventlistenerbase_h

#include "../../../scripting.h"




class GCAnimEventListenerBase
{
private:
    void *m_ptr;

public:
    GCAnimEventListenerBase() {}
    GCAnimEventListenerBase(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif