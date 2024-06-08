class GC_OP_MovementRotateParticleAroundAxis;

#ifndef _gcc_op_movementrotateparticlearoundaxis_h
#define _gcc_op_movementrotateparticlearoundaxis_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"
#include "GCParticleTransformInput.h"

class GC_OP_MovementRotateParticleAroundAxis
{
private:
    void *m_ptr;

public:
    GC_OP_MovementRotateParticleAroundAxis() {}
    GC_OP_MovementRotateParticleAroundAxis(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetRotRate() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_MovementRotateParticleAroundAxis", "m_flRotRate"); }
    void SetRotRate(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MovementRotateParticleAroundAxis", "m_flRotRate", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_MovementRotateParticleAroundAxis", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_MovementRotateParticleAroundAxis", "m_TransformInput", false, value); }
    bool GetLocalSpace() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementRotateParticleAroundAxis", "m_bLocalSpace"); }
    void SetLocalSpace(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementRotateParticleAroundAxis", "m_bLocalSpace", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif