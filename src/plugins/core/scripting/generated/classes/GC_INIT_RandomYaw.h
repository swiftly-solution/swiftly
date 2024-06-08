class GC_INIT_RandomYaw;

#ifndef _gcc_init_randomyaw_h
#define _gcc_init_randomyaw_h

#include "../../../scripting.h"




class GC_INIT_RandomYaw
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomYaw() {}
    GC_INIT_RandomYaw(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif