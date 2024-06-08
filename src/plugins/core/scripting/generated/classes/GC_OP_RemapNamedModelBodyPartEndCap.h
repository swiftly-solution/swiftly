class GC_OP_RemapNamedModelBodyPartEndCap;

#ifndef _gcc_op_remapnamedmodelbodypartendcap_h
#define _gcc_op_remapnamedmodelbodypartendcap_h

#include "../../../scripting.h"




class GC_OP_RemapNamedModelBodyPartEndCap
{
private:
    void *m_ptr;

public:
    GC_OP_RemapNamedModelBodyPartEndCap() {}
    GC_OP_RemapNamedModelBodyPartEndCap(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif