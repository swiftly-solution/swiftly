class GC_OP_PerParticleForce;

#ifndef _gcc_op_perparticleforce_h
#define _gcc_op_perparticleforce_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"
#include "GCPerParticleVecInput.h"

class GC_OP_PerParticleForce
{
private:
    void *m_ptr;

public:
    GC_OP_PerParticleForce() {}
    GC_OP_PerParticleForce(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetForceScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_PerParticleForce", "m_flForceScale"); }
    void SetForceScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_PerParticleForce", "m_flForceScale", false, value); }
    GCPerParticleVecInput GetForce() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_PerParticleForce", "m_vForce"); }
    void SetForce(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_PerParticleForce", "m_vForce", false, value); }
    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_PerParticleForce", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_PerParticleForce", "m_nCP", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif