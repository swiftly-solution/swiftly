class GC_OP_RemapNamedModelMeshGroupEndCap;

#ifndef _gcc_op_remapnamedmodelmeshgroupendcap_h
#define _gcc_op_remapnamedmodelmeshgroupendcap_h

#include "../../../scripting.h"




class GC_OP_RemapNamedModelMeshGroupEndCap
{
private:
    void *m_ptr;

public:
    GC_OP_RemapNamedModelMeshGroupEndCap() {}
    GC_OP_RemapNamedModelMeshGroupEndCap(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif