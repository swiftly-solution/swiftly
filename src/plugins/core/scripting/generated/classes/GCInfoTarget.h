class GCInfoTarget;

#ifndef _gccinfotarget_h
#define _gccinfotarget_h

#include "../../../scripting.h"




class GCInfoTarget
{
private:
    void *m_ptr;

public:
    GCInfoTarget() {}
    GCInfoTarget(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif