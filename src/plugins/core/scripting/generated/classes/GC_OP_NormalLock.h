class GC_OP_NormalLock;

#ifndef _gcc_op_normallock_h
#define _gcc_op_normallock_h

#include "../../../scripting.h"




class GC_OP_NormalLock
{
private:
    void *m_ptr;

public:
    GC_OP_NormalLock() {}
    GC_OP_NormalLock(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_NormalLock", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_NormalLock", "m_nControlPointNumber", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif