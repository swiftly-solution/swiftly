class GC_INIT_VelocityRandom;

#ifndef _gcc_init_velocityrandom_h
#define _gcc_init_velocityrandom_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"
#include "GCPerParticleVecInput.h"
#include "GCRandomNumberGeneratorParameters.h"

class GC_INIT_VelocityRandom
{
private:
    void *m_ptr;

public:
    GC_INIT_VelocityRandom() {}
    GC_INIT_VelocityRandom(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_VelocityRandom", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRandom", "m_nControlPointNumber", false, value); }
    GCPerParticleFloatInput GetSpeedMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_VelocityRandom", "m_fSpeedMin"); }
    void SetSpeedMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRandom", "m_fSpeedMin", false, value); }
    GCPerParticleFloatInput GetSpeedMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_VelocityRandom", "m_fSpeedMax"); }
    void SetSpeedMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRandom", "m_fSpeedMax", false, value); }
    GCPerParticleVecInput GetLocalCoordinateSystemSpeedMin() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_VelocityRandom", "m_LocalCoordinateSystemSpeedMin"); }
    void SetLocalCoordinateSystemSpeedMin(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRandom", "m_LocalCoordinateSystemSpeedMin", false, value); }
    GCPerParticleVecInput GetLocalCoordinateSystemSpeedMax() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_VelocityRandom", "m_LocalCoordinateSystemSpeedMax"); }
    void SetLocalCoordinateSystemSpeedMax(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRandom", "m_LocalCoordinateSystemSpeedMax", false, value); }
    bool GetIgnoreDT() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_VelocityRandom", "m_bIgnoreDT"); }
    void SetIgnoreDT(bool value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRandom", "m_bIgnoreDT", false, value); }
    GCRandomNumberGeneratorParameters GetRandomnessParameters() const { return GetSchemaValue<GCRandomNumberGeneratorParameters>(m_ptr, "C_INIT_VelocityRandom", "m_randomnessParameters"); }
    void SetRandomnessParameters(GCRandomNumberGeneratorParameters value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRandom", "m_randomnessParameters", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif