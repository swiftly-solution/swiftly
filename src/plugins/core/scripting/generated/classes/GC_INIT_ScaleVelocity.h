class GC_INIT_ScaleVelocity;

#ifndef _gcc_init_scalevelocity_h
#define _gcc_init_scalevelocity_h

#include "../../../scripting.h"




class GC_INIT_ScaleVelocity
{
private:
    void *m_ptr;

public:
    GC_INIT_ScaleVelocity() {}
    GC_INIT_ScaleVelocity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif