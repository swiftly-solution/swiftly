class GC_OP_EndCapDecay;

#ifndef _gcc_op_endcapdecay_h
#define _gcc_op_endcapdecay_h

#include "../../../scripting.h"




class GC_OP_EndCapDecay
{
private:
    void *m_ptr;

public:
    GC_OP_EndCapDecay() {}
    GC_OP_EndCapDecay(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif