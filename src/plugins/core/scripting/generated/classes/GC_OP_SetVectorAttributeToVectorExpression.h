class GC_OP_SetVectorAttributeToVectorExpression;

#ifndef _gcc_op_setvectorattributetovectorexpression_h
#define _gcc_op_setvectorattributetovectorexpression_h

#include "../../../scripting.h"

#include "../types/GVectorExpressionType_t.h"
#include "../types/GParticleSetMethod_t.h"
#include "GCPerParticleVecInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_SetVectorAttributeToVectorExpression
{
private:
    void *m_ptr;

public:
    GC_OP_SetVectorAttributeToVectorExpression() {}
    GC_OP_SetVectorAttributeToVectorExpression(void *ptr) : m_ptr(ptr) {}

    VectorExpressionType_t GetExpression() const { return GetSchemaValue<VectorExpressionType_t>(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_nExpression"); }
    void SetExpression(VectorExpressionType_t value) { SetSchemaValue(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_nExpression", false, value); }
    GCPerParticleVecInput GetInput1() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_vInput1"); }
    void SetInput1(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_vInput1", false, value); }
    GCPerParticleVecInput GetInput2() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_vInput2"); }
    void SetInput2(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_vInput2", false, value); }
    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_nOutputField", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_nSetMethod", false, value); }
    bool GetNormalizedOutput() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_bNormalizedOutput"); }
    void SetNormalizedOutput(bool value) { SetSchemaValue(m_ptr, "C_OP_SetVectorAttributeToVectorExpression", "m_bNormalizedOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif