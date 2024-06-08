class GC_OP_RemapNamedModelSequenceEndCap;

#ifndef _gcc_op_remapnamedmodelsequenceendcap_h
#define _gcc_op_remapnamedmodelsequenceendcap_h

#include "../../../scripting.h"




class GC_OP_RemapNamedModelSequenceEndCap
{
private:
    void *m_ptr;

public:
    GC_OP_RemapNamedModelSequenceEndCap() {}
    GC_OP_RemapNamedModelSequenceEndCap(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif