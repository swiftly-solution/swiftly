class GC_OP_ForceControlPointStub;

#ifndef _gcc_op_forcecontrolpointstub_h
#define _gcc_op_forcecontrolpointstub_h

#include "../../../scripting.h"




class GC_OP_ForceControlPointStub
{
private:
    void *m_ptr;

public:
    GC_OP_ForceControlPointStub() {}
    GC_OP_ForceControlPointStub(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ForceControlPointStub", "m_ControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ForceControlPointStub", "m_ControlPoint", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif