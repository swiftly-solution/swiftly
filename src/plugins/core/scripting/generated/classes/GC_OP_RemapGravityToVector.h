class GC_OP_RemapGravityToVector;

#ifndef _gcc_op_remapgravitytovector_h
#define _gcc_op_remapgravitytovector_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GCPerParticleVecInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapGravityToVector
{
private:
    void *m_ptr;

public:
    GC_OP_RemapGravityToVector() {}
    GC_OP_RemapGravityToVector(void *ptr) : m_ptr(ptr) {}

    GCPerParticleVecInput GetInput1() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_RemapGravityToVector", "m_vInput1"); }
    void SetInput1(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_RemapGravityToVector", "m_vInput1", false, value); }
    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapGravityToVector", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapGravityToVector", "m_nOutputField", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_RemapGravityToVector", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_RemapGravityToVector", "m_nSetMethod", false, value); }
    bool GetNormalizedOutput() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapGravityToVector", "m_bNormalizedOutput"); }
    void SetNormalizedOutput(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapGravityToVector", "m_bNormalizedOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif