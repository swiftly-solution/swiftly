class GC_INIT_InitVec;

#ifndef _gcc_init_initvec_h
#define _gcc_init_initvec_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GCPerParticleVecInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_InitVec
{
private:
    void *m_ptr;

public:
    GC_INIT_InitVec() {}
    GC_INIT_InitVec(void *ptr) : m_ptr(ptr) {}

    GCPerParticleVecInput GetInputValue() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_InitVec", "m_InputValue"); }
    void SetInputValue(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_InitVec", "m_InputValue", false, value); }
    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_InitVec", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_InitVec", "m_nOutputField", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_INIT_InitVec", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_INIT_InitVec", "m_nSetMethod", false, value); }
    bool GetNormalizedOutput() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitVec", "m_bNormalizedOutput"); }
    void SetNormalizedOutput(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitVec", "m_bNormalizedOutput", false, value); }
    bool GetWritePreviousPosition() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitVec", "m_bWritePreviousPosition"); }
    void SetWritePreviousPosition(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitVec", "m_bWritePreviousPosition", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif