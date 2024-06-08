class GC_OP_ClampScalar;

#ifndef _gcc_op_clampscalar_h
#define _gcc_op_clampscalar_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_ClampScalar
{
private:
    void *m_ptr;

public:
    GC_OP_ClampScalar() {}
    GC_OP_ClampScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_ClampScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_ClampScalar", "m_nFieldOutput", false, value); }
    GCPerParticleFloatInput GetOutputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ClampScalar", "m_flOutputMin"); }
    void SetOutputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ClampScalar", "m_flOutputMin", false, value); }
    GCPerParticleFloatInput GetOutputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ClampScalar", "m_flOutputMax"); }
    void SetOutputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ClampScalar", "m_flOutputMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif