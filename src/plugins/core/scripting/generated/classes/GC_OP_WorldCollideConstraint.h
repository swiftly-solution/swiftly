class GC_OP_WorldCollideConstraint;

#ifndef _gcc_op_worldcollideconstraint_h
#define _gcc_op_worldcollideconstraint_h

#include "../../../scripting.h"




class GC_OP_WorldCollideConstraint
{
private:
    void *m_ptr;

public:
    GC_OP_WorldCollideConstraint() {}
    GC_OP_WorldCollideConstraint(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif