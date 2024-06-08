class GC_OP_LerpScalar;

#ifndef _gcc_op_lerpscalar_h
#define _gcc_op_lerpscalar_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_LerpScalar
{
private:
    void *m_ptr;

public:
    GC_OP_LerpScalar() {}
    GC_OP_LerpScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_LerpScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_LerpScalar", "m_nFieldOutput", false, value); }
    GCPerParticleFloatInput GetOutput() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_LerpScalar", "m_flOutput"); }
    void SetOutput(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LerpScalar", "m_flOutput", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_LerpScalar", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_OP_LerpScalar", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_LerpScalar", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "C_OP_LerpScalar", "m_flEndTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif