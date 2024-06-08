class GC_OP_QuantizeCPComponent;

#ifndef _gcc_op_quantizecpcomponent_h
#define _gcc_op_quantizecpcomponent_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_QuantizeCPComponent
{
private:
    void *m_ptr;

public:
    GC_OP_QuantizeCPComponent() {}
    GC_OP_QuantizeCPComponent(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetInputValue() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_QuantizeCPComponent", "m_flInputValue"); }
    void SetInputValue(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_QuantizeCPComponent", "m_flInputValue", false, value); }
    int32_t GetCPOutput() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_QuantizeCPComponent", "m_nCPOutput"); }
    void SetCPOutput(int32_t value) { SetSchemaValue(m_ptr, "C_OP_QuantizeCPComponent", "m_nCPOutput", false, value); }
    int32_t GetOutVectorField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_QuantizeCPComponent", "m_nOutVectorField"); }
    void SetOutVectorField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_QuantizeCPComponent", "m_nOutVectorField", false, value); }
    GCParticleCollectionFloatInput GetQuantizeValue() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_QuantizeCPComponent", "m_flQuantizeValue"); }
    void SetQuantizeValue(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_QuantizeCPComponent", "m_flQuantizeValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif