class GCReplicationParameters;

#ifndef _gccreplicationparameters_h
#define _gccreplicationparameters_h

#include "../../../scripting.h"

#include "../types/GParticleReplicationMode_t.h"
#include "GCParticleCollectionFloatInput.h"

class GCReplicationParameters
{
private:
    void *m_ptr;

public:
    GCReplicationParameters() {}
    GCReplicationParameters(void *ptr) : m_ptr(ptr) {}

    ParticleReplicationMode_t GetReplicationMode() const { return GetSchemaValue<ParticleReplicationMode_t>(m_ptr, "CReplicationParameters", "m_nReplicationMode"); }
    void SetReplicationMode(ParticleReplicationMode_t value) { SetSchemaValue(m_ptr, "CReplicationParameters", "m_nReplicationMode", false, value); }
    bool GetScaleChildParticleRadii() const { return GetSchemaValue<bool>(m_ptr, "CReplicationParameters", "m_bScaleChildParticleRadii"); }
    void SetScaleChildParticleRadii(bool value) { SetSchemaValue(m_ptr, "CReplicationParameters", "m_bScaleChildParticleRadii", false, value); }
    GCParticleCollectionFloatInput GetMinRandomRadiusScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "CReplicationParameters", "m_flMinRandomRadiusScale"); }
    void SetMinRandomRadiusScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "CReplicationParameters", "m_flMinRandomRadiusScale", false, value); }
    GCParticleCollectionFloatInput GetMaxRandomRadiusScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "CReplicationParameters", "m_flMaxRandomRadiusScale"); }
    void SetMaxRandomRadiusScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "CReplicationParameters", "m_flMaxRandomRadiusScale", false, value); }
    GCParticleCollectionFloatInput GetModellingScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "CReplicationParameters", "m_flModellingScale"); }
    void SetModellingScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "CReplicationParameters", "m_flModellingScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif