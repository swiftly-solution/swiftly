class GC_OP_SetToCP;

#ifndef _gcc_op_settocp_h
#define _gcc_op_settocp_h

#include "../../../scripting.h"




class GC_OP_SetToCP
{
private:
    void *m_ptr;

public:
    GC_OP_SetToCP() {}
    GC_OP_SetToCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetToCP", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetToCP", "m_nControlPointNumber", false, value); }
    Vector GetOffset() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetToCP", "m_vecOffset"); }
    void SetOffset(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetToCP", "m_vecOffset", false, value); }
    bool GetOffsetLocal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetToCP", "m_bOffsetLocal"); }
    void SetOffsetLocal(bool value) { SetSchemaValue(m_ptr, "C_OP_SetToCP", "m_bOffsetLocal", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif