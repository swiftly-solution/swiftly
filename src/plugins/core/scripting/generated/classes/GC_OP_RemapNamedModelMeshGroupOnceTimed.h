class GC_OP_RemapNamedModelMeshGroupOnceTimed;

#ifndef _gcc_op_remapnamedmodelmeshgrouponcetimed_h
#define _gcc_op_remapnamedmodelmeshgrouponcetimed_h

#include "../../../scripting.h"




class GC_OP_RemapNamedModelMeshGroupOnceTimed
{
private:
    void *m_ptr;

public:
    GC_OP_RemapNamedModelMeshGroupOnceTimed() {}
    GC_OP_RemapNamedModelMeshGroupOnceTimed(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif