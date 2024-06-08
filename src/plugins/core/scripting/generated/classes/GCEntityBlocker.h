class GCEntityBlocker;

#ifndef _gccentityblocker_h
#define _gccentityblocker_h

#include "../../../scripting.h"




class GCEntityBlocker
{
private:
    void *m_ptr;

public:
    GCEntityBlocker() {}
    GCEntityBlocker(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif