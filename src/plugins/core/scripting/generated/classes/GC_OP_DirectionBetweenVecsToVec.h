class GC_OP_DirectionBetweenVecsToVec;

#ifndef _gcc_op_directionbetweenvecstovec_h
#define _gcc_op_directionbetweenvecstovec_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleVecInput.h"

class GC_OP_DirectionBetweenVecsToVec
{
private:
    void *m_ptr;

public:
    GC_OP_DirectionBetweenVecsToVec() {}
    GC_OP_DirectionBetweenVecsToVec(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_DirectionBetweenVecsToVec", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_DirectionBetweenVecsToVec", "m_nFieldOutput", false, value); }
    GCPerParticleVecInput GetPoint1() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_DirectionBetweenVecsToVec", "m_vecPoint1"); }
    void SetPoint1(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_DirectionBetweenVecsToVec", "m_vecPoint1", false, value); }
    GCPerParticleVecInput GetPoint2() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_DirectionBetweenVecsToVec", "m_vecPoint2"); }
    void SetPoint2(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_DirectionBetweenVecsToVec", "m_vecPoint2", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif