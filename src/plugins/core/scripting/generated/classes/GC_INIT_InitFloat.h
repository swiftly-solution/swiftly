class GC_INIT_InitFloat;

#ifndef _gcc_init_initfloat_h
#define _gcc_init_initfloat_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GCPerParticleFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_InitFloat
{
private:
    void *m_ptr;

public:
    GC_INIT_InitFloat() {}
    GC_INIT_InitFloat(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetInputValue() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_InitFloat", "m_InputValue"); }
    void SetInputValue(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_InitFloat", "m_InputValue", false, value); }
    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_InitFloat", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFloat", "m_nOutputField", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_INIT_InitFloat", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFloat", "m_nSetMethod", false, value); }
    GCPerParticleFloatInput GetInputStrength() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_InitFloat", "m_InputStrength"); }
    void SetInputStrength(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_InitFloat", "m_InputStrength", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif