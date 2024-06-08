class GC_OP_RemapCrossProductOfTwoVectorsToVector;

#ifndef _gcc_op_remapcrossproductoftwovectorstovector_h
#define _gcc_op_remapcrossproductoftwovectorstovector_h

#include "../../../scripting.h"


#include "GCPerParticleVecInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapCrossProductOfTwoVectorsToVector
{
private:
    void *m_ptr;

public:
    GC_OP_RemapCrossProductOfTwoVectorsToVector() {}
    GC_OP_RemapCrossProductOfTwoVectorsToVector(void *ptr) : m_ptr(ptr) {}

    GCPerParticleVecInput GetInputVec1() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_RemapCrossProductOfTwoVectorsToVector", "m_InputVec1"); }
    void SetInputVec1(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_RemapCrossProductOfTwoVectorsToVector", "m_InputVec1", false, value); }
    GCPerParticleVecInput GetInputVec2() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_RemapCrossProductOfTwoVectorsToVector", "m_InputVec2"); }
    void SetInputVec2(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_RemapCrossProductOfTwoVectorsToVector", "m_InputVec2", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapCrossProductOfTwoVectorsToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCrossProductOfTwoVectorsToVector", "m_nFieldOutput", false, value); }
    bool GetNormalize() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapCrossProductOfTwoVectorsToVector", "m_bNormalize"); }
    void SetNormalize(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapCrossProductOfTwoVectorsToVector", "m_bNormalize", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif