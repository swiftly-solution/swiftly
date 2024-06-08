class GC_OP_SetControlPointFieldFromVectorExpression;

#ifndef _gcc_op_setcontrolpointfieldfromvectorexpression_h
#define _gcc_op_setcontrolpointfieldfromvectorexpression_h

#include "../../../scripting.h"

#include "../types/GVectorFloatExpressionType_t.h"
#include "GCParticleRemapFloatInput.h"

class GC_OP_SetControlPointFieldFromVectorExpression
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointFieldFromVectorExpression() {}
    GC_OP_SetControlPointFieldFromVectorExpression(void *ptr) : m_ptr(ptr) {}

    VectorFloatExpressionType_t GetExpression() const { return GetSchemaValue<VectorFloatExpressionType_t>(m_ptr, "C_OP_SetControlPointFieldFromVectorExpression", "m_nExpression"); }
    void SetExpression(VectorFloatExpressionType_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldFromVectorExpression", "m_nExpression", false, value); }
    GCParticleRemapFloatInput GetOutputRemap() const { return GetSchemaValue<GCParticleRemapFloatInput>(m_ptr, "C_OP_SetControlPointFieldFromVectorExpression", "m_flOutputRemap"); }
    void SetOutputRemap(GCParticleRemapFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldFromVectorExpression", "m_flOutputRemap", false, value); }
    int32_t GetOutputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointFieldFromVectorExpression", "m_nOutputCP"); }
    void SetOutputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldFromVectorExpression", "m_nOutputCP", false, value); }
    int32_t GetOutVectorField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointFieldFromVectorExpression", "m_nOutVectorField"); }
    void SetOutVectorField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldFromVectorExpression", "m_nOutVectorField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif