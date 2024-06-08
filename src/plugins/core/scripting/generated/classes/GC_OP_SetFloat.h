class GC_OP_SetFloat;

#ifndef _gcc_op_setfloat_h
#define _gcc_op_setfloat_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GCPerParticleFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_SetFloat
{
private:
    void *m_ptr;

public:
    GC_OP_SetFloat() {}
    GC_OP_SetFloat(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetInputValue() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_SetFloat", "m_InputValue"); }
    void SetInputValue(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetFloat", "m_InputValue", false, value); }
    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SetFloat", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SetFloat", "m_nOutputField", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_SetFloat", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_SetFloat", "m_nSetMethod", false, value); }
    GCPerParticleFloatInput GetLerp() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_SetFloat", "m_Lerp"); }
    void SetLerp(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetFloat", "m_Lerp", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif