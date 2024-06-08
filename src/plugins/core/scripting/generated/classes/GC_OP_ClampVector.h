class GC_OP_ClampVector;

#ifndef _gcc_op_clampvector_h
#define _gcc_op_clampvector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleVecInput.h"

class GC_OP_ClampVector
{
private:
    void *m_ptr;

public:
    GC_OP_ClampVector() {}
    GC_OP_ClampVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_ClampVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_ClampVector", "m_nFieldOutput", false, value); }
    GCPerParticleVecInput GetOutputMin() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_ClampVector", "m_vecOutputMin"); }
    void SetOutputMin(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_ClampVector", "m_vecOutputMin", false, value); }
    GCPerParticleVecInput GetOutputMax() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_ClampVector", "m_vecOutputMax"); }
    void SetOutputMax(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_ClampVector", "m_vecOutputMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif