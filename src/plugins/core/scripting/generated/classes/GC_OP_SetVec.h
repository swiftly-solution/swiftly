class GC_OP_SetVec;

#ifndef _gcc_op_setvec_h
#define _gcc_op_setvec_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GCPerParticleVecInput.h"
#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_SetVec
{
private:
    void *m_ptr;

public:
    GC_OP_SetVec() {}
    GC_OP_SetVec(void *ptr) : m_ptr(ptr) {}

    GCPerParticleVecInput GetInputValue() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_SetVec", "m_InputValue"); }
    void SetInputValue(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_SetVec", "m_InputValue", false, value); }
    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SetVec", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SetVec", "m_nOutputField", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_SetVec", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_SetVec", "m_nSetMethod", false, value); }
    GCPerParticleFloatInput GetLerp() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_SetVec", "m_Lerp"); }
    void SetLerp(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetVec", "m_Lerp", false, value); }
    bool GetNormalizedOutput() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetVec", "m_bNormalizedOutput"); }
    void SetNormalizedOutput(bool value) { SetSchemaValue(m_ptr, "C_OP_SetVec", "m_bNormalizedOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif