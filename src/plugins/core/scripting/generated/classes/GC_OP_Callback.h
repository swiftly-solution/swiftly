class GC_OP_Callback;

#ifndef _gcc_op_callback_h
#define _gcc_op_callback_h

#include "../../../scripting.h"




class GC_OP_Callback
{
private:
    void *m_ptr;

public:
    GC_OP_Callback() {}
    GC_OP_Callback(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif