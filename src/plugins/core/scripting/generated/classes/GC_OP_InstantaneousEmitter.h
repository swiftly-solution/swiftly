class GC_OP_InstantaneousEmitter;

#ifndef _gcc_op_instantaneousemitter_h
#define _gcc_op_instantaneousemitter_h

#include "../../../scripting.h"

#include "../types/GEventTypeSelection_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_InstantaneousEmitter
{
private:
    void *m_ptr;

public:
    GC_OP_InstantaneousEmitter() {}
    GC_OP_InstantaneousEmitter(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetParticlesToEmit() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_InstantaneousEmitter", "m_nParticlesToEmit"); }
    void SetParticlesToEmit(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_InstantaneousEmitter", "m_nParticlesToEmit", false, value); }
    GCParticleCollectionFloatInput GetStartTime() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_InstantaneousEmitter", "m_flStartTime"); }
    void SetStartTime(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_InstantaneousEmitter", "m_flStartTime", false, value); }
    float GetInitFromKilledParentParticles() const { return GetSchemaValue<float>(m_ptr, "C_OP_InstantaneousEmitter", "m_flInitFromKilledParentParticles"); }
    void SetInitFromKilledParentParticles(float value) { SetSchemaValue(m_ptr, "C_OP_InstantaneousEmitter", "m_flInitFromKilledParentParticles", false, value); }
    EventTypeSelection_t GetEventType() const { return GetSchemaValue<EventTypeSelection_t>(m_ptr, "C_OP_InstantaneousEmitter", "m_nEventType"); }
    void SetEventType(EventTypeSelection_t value) { SetSchemaValue(m_ptr, "C_OP_InstantaneousEmitter", "m_nEventType", false, value); }
    GCParticleCollectionFloatInput GetParentParticleScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_InstantaneousEmitter", "m_flParentParticleScale"); }
    void SetParentParticleScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_InstantaneousEmitter", "m_flParentParticleScale", false, value); }
    int32_t GetMaxEmittedPerFrame() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_InstantaneousEmitter", "m_nMaxEmittedPerFrame"); }
    void SetMaxEmittedPerFrame(int32_t value) { SetSchemaValue(m_ptr, "C_OP_InstantaneousEmitter", "m_nMaxEmittedPerFrame", false, value); }
    int32_t GetSnapshotControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_InstantaneousEmitter", "m_nSnapshotControlPoint"); }
    void SetSnapshotControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_InstantaneousEmitter", "m_nSnapshotControlPoint", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif