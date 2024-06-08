class GC_INIT_RandomRotation;

#ifndef _gcc_init_randomrotation_h
#define _gcc_init_randomrotation_h

#include "../../../scripting.h"




class GC_INIT_RandomRotation
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomRotation() {}
    GC_INIT_RandomRotation(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif