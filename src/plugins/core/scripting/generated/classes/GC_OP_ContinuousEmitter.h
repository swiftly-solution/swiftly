class GC_OP_ContinuousEmitter;

#ifndef _gcc_op_continuousemitter_h
#define _gcc_op_continuousemitter_h

#include "../../../scripting.h"

#include "../types/GEventTypeSelection_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_ContinuousEmitter
{
private:
    void *m_ptr;

public:
    GC_OP_ContinuousEmitter() {}
    GC_OP_ContinuousEmitter(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetEmissionDuration() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_ContinuousEmitter", "m_flEmissionDuration"); }
    void SetEmissionDuration(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ContinuousEmitter", "m_flEmissionDuration", false, value); }
    GCParticleCollectionFloatInput GetStartTime() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_ContinuousEmitter", "m_flStartTime"); }
    void SetStartTime(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ContinuousEmitter", "m_flStartTime", false, value); }
    GCParticleCollectionFloatInput GetEmitRate() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_ContinuousEmitter", "m_flEmitRate"); }
    void SetEmitRate(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ContinuousEmitter", "m_flEmitRate", false, value); }
    float GetEmissionScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_ContinuousEmitter", "m_flEmissionScale"); }
    void SetEmissionScale(float value) { SetSchemaValue(m_ptr, "C_OP_ContinuousEmitter", "m_flEmissionScale", false, value); }
    float GetScalePerParentParticle() const { return GetSchemaValue<float>(m_ptr, "C_OP_ContinuousEmitter", "m_flScalePerParentParticle"); }
    void SetScalePerParentParticle(float value) { SetSchemaValue(m_ptr, "C_OP_ContinuousEmitter", "m_flScalePerParentParticle", false, value); }
    bool GetInitFromKilledParentParticles() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ContinuousEmitter", "m_bInitFromKilledParentParticles"); }
    void SetInitFromKilledParentParticles(bool value) { SetSchemaValue(m_ptr, "C_OP_ContinuousEmitter", "m_bInitFromKilledParentParticles", false, value); }
    EventTypeSelection_t GetEventType() const { return GetSchemaValue<EventTypeSelection_t>(m_ptr, "C_OP_ContinuousEmitter", "m_nEventType"); }
    void SetEventType(EventTypeSelection_t value) { SetSchemaValue(m_ptr, "C_OP_ContinuousEmitter", "m_nEventType", false, value); }
    int32_t GetSnapshotControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ContinuousEmitter", "m_nSnapshotControlPoint"); }
    void SetSnapshotControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ContinuousEmitter", "m_nSnapshotControlPoint", false, value); }
    int32_t GetLimitPerUpdate() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ContinuousEmitter", "m_nLimitPerUpdate"); }
    void SetLimitPerUpdate(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ContinuousEmitter", "m_nLimitPerUpdate", false, value); }
    bool GetForceEmitOnFirstUpdate() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ContinuousEmitter", "m_bForceEmitOnFirstUpdate"); }
    void SetForceEmitOnFirstUpdate(bool value) { SetSchemaValue(m_ptr, "C_OP_ContinuousEmitter", "m_bForceEmitOnFirstUpdate", false, value); }
    bool GetForceEmitOnLastUpdate() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ContinuousEmitter", "m_bForceEmitOnLastUpdate"); }
    void SetForceEmitOnLastUpdate(bool value) { SetSchemaValue(m_ptr, "C_OP_ContinuousEmitter", "m_bForceEmitOnLastUpdate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif