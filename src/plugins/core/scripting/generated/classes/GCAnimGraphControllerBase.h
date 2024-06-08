class GCAnimGraphControllerBase;

#ifndef _gccanimgraphcontrollerbase_h
#define _gccanimgraphcontrollerbase_h

#include "../../../scripting.h"




class GCAnimGraphControllerBase
{
private:
    void *m_ptr;

public:
    GCAnimGraphControllerBase() {}
    GCAnimGraphControllerBase(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif