class GC_OP_SpringToVectorConstraint;

#ifndef _gcc_op_springtovectorconstraint_h
#define _gcc_op_springtovectorconstraint_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"
#include "GCPerParticleVecInput.h"

class GC_OP_SpringToVectorConstraint
{
private:
    void *m_ptr;

public:
    GC_OP_SpringToVectorConstraint() {}
    GC_OP_SpringToVectorConstraint(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetRestLength() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_SpringToVectorConstraint", "m_flRestLength"); }
    void SetRestLength(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SpringToVectorConstraint", "m_flRestLength", false, value); }
    GCPerParticleFloatInput GetMinDistance() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_SpringToVectorConstraint", "m_flMinDistance"); }
    void SetMinDistance(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SpringToVectorConstraint", "m_flMinDistance", false, value); }
    GCPerParticleFloatInput GetMaxDistance() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_SpringToVectorConstraint", "m_flMaxDistance"); }
    void SetMaxDistance(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SpringToVectorConstraint", "m_flMaxDistance", false, value); }
    GCPerParticleFloatInput GetRestingLength() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_SpringToVectorConstraint", "m_flRestingLength"); }
    void SetRestingLength(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SpringToVectorConstraint", "m_flRestingLength", false, value); }
    GCPerParticleVecInput GetAnchorVector() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_SpringToVectorConstraint", "m_vecAnchorVector"); }
    void SetAnchorVector(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_SpringToVectorConstraint", "m_vecAnchorVector", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif