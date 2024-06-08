class GC_OP_SetFloatAttributeToVectorExpression;

#ifndef _gcc_op_setfloatattributetovectorexpression_h
#define _gcc_op_setfloatattributetovectorexpression_h

#include "../../../scripting.h"

#include "../types/GVectorFloatExpressionType_t.h"
#include "../types/GParticleSetMethod_t.h"
#include "GCPerParticleVecInput.h"
#include "GCParticleRemapFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_SetFloatAttributeToVectorExpression
{
private:
    void *m_ptr;

public:
    GC_OP_SetFloatAttributeToVectorExpression() {}
    GC_OP_SetFloatAttributeToVectorExpression(void *ptr) : m_ptr(ptr) {}

    VectorFloatExpressionType_t GetExpression() const { return GetSchemaValue<VectorFloatExpressionType_t>(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_nExpression"); }
    void SetExpression(VectorFloatExpressionType_t value) { SetSchemaValue(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_nExpression", false, value); }
    GCPerParticleVecInput GetInput1() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_vInput1"); }
    void SetInput1(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_vInput1", false, value); }
    GCPerParticleVecInput GetInput2() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_vInput2"); }
    void SetInput2(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_vInput2", false, value); }
    GCParticleRemapFloatInput GetOutputRemap() const { return GetSchemaValue<GCParticleRemapFloatInput>(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_flOutputRemap"); }
    void SetOutputRemap(GCParticleRemapFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_flOutputRemap", false, value); }
    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_nOutputField", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_SetFloatAttributeToVectorExpression", "m_nSetMethod", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif