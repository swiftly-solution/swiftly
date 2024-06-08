class GCParticleMassCalculationParameters;

#ifndef _gccparticlemasscalculationparameters_h
#define _gccparticlemasscalculationparameters_h

#include "../../../scripting.h"

#include "../types/GParticleMassMode_t.h"
#include "GCPerParticleFloatInput.h"

class GCParticleMassCalculationParameters
{
private:
    void *m_ptr;

public:
    GCParticleMassCalculationParameters() {}
    GCParticleMassCalculationParameters(void *ptr) : m_ptr(ptr) {}

    ParticleMassMode_t GetMassMode() const { return GetSchemaValue<ParticleMassMode_t>(m_ptr, "CParticleMassCalculationParameters", "m_nMassMode"); }
    void SetMassMode(ParticleMassMode_t value) { SetSchemaValue(m_ptr, "CParticleMassCalculationParameters", "m_nMassMode", false, value); }
    GCPerParticleFloatInput GetRadius() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "CParticleMassCalculationParameters", "m_flRadius"); }
    void SetRadius(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "CParticleMassCalculationParameters", "m_flRadius", false, value); }
    GCPerParticleFloatInput GetNominalRadius() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "CParticleMassCalculationParameters", "m_flNominalRadius"); }
    void SetNominalRadius(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "CParticleMassCalculationParameters", "m_flNominalRadius", false, value); }
    GCPerParticleFloatInput GetScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "CParticleMassCalculationParameters", "m_flScale"); }
    void SetScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "CParticleMassCalculationParameters", "m_flScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif