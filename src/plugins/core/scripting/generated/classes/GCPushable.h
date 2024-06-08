class GCPushable;

#ifndef _gccpushable_h
#define _gccpushable_h

#include "../../../scripting.h"




class GCPushable
{
private:
    void *m_ptr;

public:
    GCPushable() {}
    GCPushable(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif