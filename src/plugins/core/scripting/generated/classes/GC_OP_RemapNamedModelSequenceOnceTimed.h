class GC_OP_RemapNamedModelSequenceOnceTimed;

#ifndef _gcc_op_remapnamedmodelsequenceoncetimed_h
#define _gcc_op_remapnamedmodelsequenceoncetimed_h

#include "../../../scripting.h"




class GC_OP_RemapNamedModelSequenceOnceTimed
{
private:
    void *m_ptr;

public:
    GC_OP_RemapNamedModelSequenceOnceTimed() {}
    GC_OP_RemapNamedModelSequenceOnceTimed(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif