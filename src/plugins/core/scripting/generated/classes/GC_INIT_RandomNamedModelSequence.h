class GC_INIT_RandomNamedModelSequence;

#ifndef _gcc_init_randomnamedmodelsequence_h
#define _gcc_init_randomnamedmodelsequence_h

#include "../../../scripting.h"




class GC_INIT_RandomNamedModelSequence
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomNamedModelSequence() {}
    GC_INIT_RandomNamedModelSequence(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif