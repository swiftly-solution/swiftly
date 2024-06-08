class GC_INIT_SetAttributeToScalarExpression;

#ifndef _gcc_init_setattributetoscalarexpression_h
#define _gcc_init_setattributetoscalarexpression_h

#include "../../../scripting.h"

#include "../types/GScalarExpressionType_t.h"
#include "../types/GParticleSetMethod_t.h"
#include "GCPerParticleFloatInput.h"
#include "GCParticleRemapFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_SetAttributeToScalarExpression
{
private:
    void *m_ptr;

public:
    GC_INIT_SetAttributeToScalarExpression() {}
    GC_INIT_SetAttributeToScalarExpression(void *ptr) : m_ptr(ptr) {}

    ScalarExpressionType_t GetExpression() const { return GetSchemaValue<ScalarExpressionType_t>(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_nExpression"); }
    void SetExpression(ScalarExpressionType_t value) { SetSchemaValue(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_nExpression", false, value); }
    GCPerParticleFloatInput GetInput1() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_flInput1"); }
    void SetInput1(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_flInput1", false, value); }
    GCPerParticleFloatInput GetInput2() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_flInput2"); }
    void SetInput2(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_flInput2", false, value); }
    GCParticleRemapFloatInput GetOutputRemap() const { return GetSchemaValue<GCParticleRemapFloatInput>(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_flOutputRemap"); }
    void SetOutputRemap(GCParticleRemapFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_flOutputRemap", false, value); }
    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_nOutputField", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_INIT_SetAttributeToScalarExpression", "m_nSetMethod", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif