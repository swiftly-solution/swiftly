class GC_OP_ExternalGameImpulseForce;

#ifndef _gcc_op_externalgameimpulseforce_h
#define _gcc_op_externalgameimpulseforce_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"

class GC_OP_ExternalGameImpulseForce
{
private:
    void *m_ptr;

public:
    GC_OP_ExternalGameImpulseForce() {}
    GC_OP_ExternalGameImpulseForce(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetForceScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ExternalGameImpulseForce", "m_flForceScale"); }
    void SetForceScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ExternalGameImpulseForce", "m_flForceScale", false, value); }
    bool GetRopes() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ExternalGameImpulseForce", "m_bRopes"); }
    void SetRopes(bool value) { SetSchemaValue(m_ptr, "C_OP_ExternalGameImpulseForce", "m_bRopes", false, value); }
    bool GetRopesZOnly() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ExternalGameImpulseForce", "m_bRopesZOnly"); }
    void SetRopesZOnly(bool value) { SetSchemaValue(m_ptr, "C_OP_ExternalGameImpulseForce", "m_bRopesZOnly", false, value); }
    bool GetExplosions() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ExternalGameImpulseForce", "m_bExplosions"); }
    void SetExplosions(bool value) { SetSchemaValue(m_ptr, "C_OP_ExternalGameImpulseForce", "m_bExplosions", false, value); }
    bool GetParticles() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ExternalGameImpulseForce", "m_bParticles"); }
    void SetParticles(bool value) { SetSchemaValue(m_ptr, "C_OP_ExternalGameImpulseForce", "m_bParticles", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif