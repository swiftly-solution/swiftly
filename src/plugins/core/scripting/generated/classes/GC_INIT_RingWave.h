class GC_INIT_RingWave;

#ifndef _gcc_init_ringwave_h
#define _gcc_init_ringwave_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"
#include "GCParticleCollectionFloatInput.h"
#include "GCPerParticleFloatInput.h"

class GC_INIT_RingWave
{
private:
    void *m_ptr;

public:
    GC_INIT_RingWave() {}
    GC_INIT_RingWave(void *ptr) : m_ptr(ptr) {}

    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_RingWave", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_RingWave", "m_TransformInput", false, value); }
    GCParticleCollectionFloatInput GetParticlesPerOrbit() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_RingWave", "m_flParticlesPerOrbit"); }
    void SetParticlesPerOrbit(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_RingWave", "m_flParticlesPerOrbit", false, value); }
    GCPerParticleFloatInput GetInitialRadius() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_RingWave", "m_flInitialRadius"); }
    void SetInitialRadius(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_RingWave", "m_flInitialRadius", false, value); }
    GCPerParticleFloatInput GetThickness() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_RingWave", "m_flThickness"); }
    void SetThickness(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_RingWave", "m_flThickness", false, value); }
    GCPerParticleFloatInput GetInitialSpeedMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_RingWave", "m_flInitialSpeedMin"); }
    void SetInitialSpeedMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_RingWave", "m_flInitialSpeedMin", false, value); }
    GCPerParticleFloatInput GetInitialSpeedMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_RingWave", "m_flInitialSpeedMax"); }
    void SetInitialSpeedMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_RingWave", "m_flInitialSpeedMax", false, value); }
    GCPerParticleFloatInput GetRoll() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_RingWave", "m_flRoll"); }
    void SetRoll(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_RingWave", "m_flRoll", false, value); }
    GCPerParticleFloatInput GetPitch() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_RingWave", "m_flPitch"); }
    void SetPitch(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_RingWave", "m_flPitch", false, value); }
    GCPerParticleFloatInput GetYaw() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_RingWave", "m_flYaw"); }
    void SetYaw(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_RingWave", "m_flYaw", false, value); }
    bool GetEvenDistribution() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RingWave", "m_bEvenDistribution"); }
    void SetEvenDistribution(bool value) { SetSchemaValue(m_ptr, "C_INIT_RingWave", "m_bEvenDistribution", false, value); }
    bool GetXYVelocityOnly() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RingWave", "m_bXYVelocityOnly"); }
    void SetXYVelocityOnly(bool value) { SetSchemaValue(m_ptr, "C_INIT_RingWave", "m_bXYVelocityOnly", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif