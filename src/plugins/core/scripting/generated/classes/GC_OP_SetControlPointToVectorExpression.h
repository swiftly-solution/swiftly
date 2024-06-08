class GC_OP_SetControlPointToVectorExpression;

#ifndef _gcc_op_setcontrolpointtovectorexpression_h
#define _gcc_op_setcontrolpointtovectorexpression_h

#include "../../../scripting.h"

#include "../types/GVectorExpressionType_t.h"


class GC_OP_SetControlPointToVectorExpression
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointToVectorExpression() {}
    GC_OP_SetControlPointToVectorExpression(void *ptr) : m_ptr(ptr) {}

    VectorExpressionType_t GetExpression() const { return GetSchemaValue<VectorExpressionType_t>(m_ptr, "C_OP_SetControlPointToVectorExpression", "m_nExpression"); }
    void SetExpression(VectorExpressionType_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToVectorExpression", "m_nExpression", false, value); }
    int32_t GetOutputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToVectorExpression", "m_nOutputCP"); }
    void SetOutputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToVectorExpression", "m_nOutputCP", false, value); }
    bool GetNormalizedOutput() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointToVectorExpression", "m_bNormalizedOutput"); }
    void SetNormalizedOutput(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToVectorExpression", "m_bNormalizedOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif