class GC_OP_SpinYaw;

#ifndef _gcc_op_spinyaw_h
#define _gcc_op_spinyaw_h

#include "../../../scripting.h"




class GC_OP_SpinYaw
{
private:
    void *m_ptr;

public:
    GC_OP_SpinYaw() {}
    GC_OP_SpinYaw(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif