class GC_INIT_CreateParticleImpulse;

#ifndef _gcc_init_createparticleimpulse_h
#define _gcc_init_createparticleimpulse_h

#include "../../../scripting.h"

#include "../types/GParticleFalloffFunction_t.h"
#include "../types/GParticleImpulseType_t.h"
#include "GCPerParticleFloatInput.h"

class GC_INIT_CreateParticleImpulse
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateParticleImpulse() {}
    GC_INIT_CreateParticleImpulse(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetInputRadius() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateParticleImpulse", "m_InputRadius"); }
    void SetInputRadius(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateParticleImpulse", "m_InputRadius", false, value); }
    GCPerParticleFloatInput GetInputMagnitude() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateParticleImpulse", "m_InputMagnitude"); }
    void SetInputMagnitude(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateParticleImpulse", "m_InputMagnitude", false, value); }
    ParticleFalloffFunction_t GetFalloffFunction() const { return GetSchemaValue<ParticleFalloffFunction_t>(m_ptr, "C_INIT_CreateParticleImpulse", "m_nFalloffFunction"); }
    void SetFalloffFunction(ParticleFalloffFunction_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateParticleImpulse", "m_nFalloffFunction", false, value); }
    GCPerParticleFloatInput GetInputFalloffExp() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateParticleImpulse", "m_InputFalloffExp"); }
    void SetInputFalloffExp(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateParticleImpulse", "m_InputFalloffExp", false, value); }
    ParticleImpulseType_t GetImpulseType() const { return GetSchemaValue<ParticleImpulseType_t>(m_ptr, "C_INIT_CreateParticleImpulse", "m_nImpulseType"); }
    void SetImpulseType(ParticleImpulseType_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateParticleImpulse", "m_nImpulseType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif