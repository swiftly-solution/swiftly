class GC_OP_SpinUpdate;

#ifndef _gcc_op_spinupdate_h
#define _gcc_op_spinupdate_h

#include "../../../scripting.h"




class GC_OP_SpinUpdate
{
private:
    void *m_ptr;

public:
    GC_OP_SpinUpdate() {}
    GC_OP_SpinUpdate(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif