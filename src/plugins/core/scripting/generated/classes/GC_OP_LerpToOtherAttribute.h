class GC_OP_LerpToOtherAttribute;

#ifndef _gcc_op_lerptootherattribute_h
#define _gcc_op_lerptootherattribute_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_LerpToOtherAttribute
{
private:
    void *m_ptr;

public:
    GC_OP_LerpToOtherAttribute() {}
    GC_OP_LerpToOtherAttribute(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetInterpolation() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_LerpToOtherAttribute", "m_flInterpolation"); }
    void SetInterpolation(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LerpToOtherAttribute", "m_flInterpolation", false, value); }
    GParticleAttributeIndex_t GetFieldInputFrom() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_LerpToOtherAttribute", "m_nFieldInputFrom"); }
    void SetFieldInputFrom(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_LerpToOtherAttribute", "m_nFieldInputFrom", false, value); }
    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_LerpToOtherAttribute", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_LerpToOtherAttribute", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_LerpToOtherAttribute", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_LerpToOtherAttribute", "m_nFieldOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif