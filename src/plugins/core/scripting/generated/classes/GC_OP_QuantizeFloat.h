class GC_OP_QuantizeFloat;

#ifndef _gcc_op_quantizefloat_h
#define _gcc_op_quantizefloat_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_QuantizeFloat
{
private:
    void *m_ptr;

public:
    GC_OP_QuantizeFloat() {}
    GC_OP_QuantizeFloat(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetInputValue() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_QuantizeFloat", "m_InputValue"); }
    void SetInputValue(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_QuantizeFloat", "m_InputValue", false, value); }
    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_QuantizeFloat", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_QuantizeFloat", "m_nOutputField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif