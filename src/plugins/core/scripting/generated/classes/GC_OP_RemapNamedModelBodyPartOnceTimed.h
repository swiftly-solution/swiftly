class GC_OP_RemapNamedModelBodyPartOnceTimed;

#ifndef _gcc_op_remapnamedmodelbodypartoncetimed_h
#define _gcc_op_remapnamedmodelbodypartoncetimed_h

#include "../../../scripting.h"




class GC_OP_RemapNamedModelBodyPartOnceTimed
{
private:
    void *m_ptr;

public:
    GC_OP_RemapNamedModelBodyPartOnceTimed() {}
    GC_OP_RemapNamedModelBodyPartOnceTimed(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif