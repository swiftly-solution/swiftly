class GC_OP_Spin;

#ifndef _gcc_op_spin_h
#define _gcc_op_spin_h

#include "../../../scripting.h"




class GC_OP_Spin
{
private:
    void *m_ptr;

public:
    GC_OP_Spin() {}
    GC_OP_Spin(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif