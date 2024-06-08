class GC_OP_RopeSpringConstraint;

#ifndef _gcc_op_ropespringconstraint_h
#define _gcc_op_ropespringconstraint_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_RopeSpringConstraint
{
private:
    void *m_ptr;

public:
    GC_OP_RopeSpringConstraint() {}
    GC_OP_RopeSpringConstraint(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetRestLength() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RopeSpringConstraint", "m_flRestLength"); }
    void SetRestLength(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RopeSpringConstraint", "m_flRestLength", false, value); }
    GCParticleCollectionFloatInput GetMinDistance() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RopeSpringConstraint", "m_flMinDistance"); }
    void SetMinDistance(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RopeSpringConstraint", "m_flMinDistance", false, value); }
    GCParticleCollectionFloatInput GetMaxDistance() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RopeSpringConstraint", "m_flMaxDistance"); }
    void SetMaxDistance(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RopeSpringConstraint", "m_flMaxDistance", false, value); }
    float GetAdjustmentScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RopeSpringConstraint", "m_flAdjustmentScale"); }
    void SetAdjustmentScale(float value) { SetSchemaValue(m_ptr, "C_OP_RopeSpringConstraint", "m_flAdjustmentScale", false, value); }
    GCParticleCollectionFloatInput GetInitialRestingLength() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RopeSpringConstraint", "m_flInitialRestingLength"); }
    void SetInitialRestingLength(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RopeSpringConstraint", "m_flInitialRestingLength", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif