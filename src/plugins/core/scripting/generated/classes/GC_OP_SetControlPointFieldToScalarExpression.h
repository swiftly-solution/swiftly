class GC_OP_SetControlPointFieldToScalarExpression;

#ifndef _gcc_op_setcontrolpointfieldtoscalarexpression_h
#define _gcc_op_setcontrolpointfieldtoscalarexpression_h

#include "../../../scripting.h"

#include "../types/GScalarExpressionType_t.h"
#include "GCParticleCollectionFloatInput.h"
#include "GCParticleRemapFloatInput.h"

class GC_OP_SetControlPointFieldToScalarExpression
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointFieldToScalarExpression() {}
    GC_OP_SetControlPointFieldToScalarExpression(void *ptr) : m_ptr(ptr) {}

    ScalarExpressionType_t GetExpression() const { return GetSchemaValue<ScalarExpressionType_t>(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_nExpression"); }
    void SetExpression(ScalarExpressionType_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_nExpression", false, value); }
    GCParticleCollectionFloatInput GetInput1() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_flInput1"); }
    void SetInput1(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_flInput1", false, value); }
    GCParticleCollectionFloatInput GetInput2() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_flInput2"); }
    void SetInput2(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_flInput2", false, value); }
    GCParticleRemapFloatInput GetOutputRemap() const { return GetSchemaValue<GCParticleRemapFloatInput>(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_flOutputRemap"); }
    void SetOutputRemap(GCParticleRemapFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_flOutputRemap", false, value); }
    int32_t GetOutputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_nOutputCP"); }
    void SetOutputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_nOutputCP", false, value); }
    int32_t GetOutVectorField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_nOutVectorField"); }
    void SetOutVectorField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldToScalarExpression", "m_nOutVectorField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif