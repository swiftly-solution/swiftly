class GC_OP_MaintainEmitter;

#ifndef _gcc_op_maintainemitter_h
#define _gcc_op_maintainemitter_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_MaintainEmitter
{
private:
    void *m_ptr;

public:
    GC_OP_MaintainEmitter() {}
    GC_OP_MaintainEmitter(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetParticlesToMaintain() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_MaintainEmitter", "m_nParticlesToMaintain"); }
    void SetParticlesToMaintain(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MaintainEmitter", "m_nParticlesToMaintain", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_MaintainEmitter", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_OP_MaintainEmitter", "m_flStartTime", false, value); }
    GCParticleCollectionFloatInput GetEmissionDuration() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_MaintainEmitter", "m_flEmissionDuration"); }
    void SetEmissionDuration(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MaintainEmitter", "m_flEmissionDuration", false, value); }
    float GetEmissionRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_MaintainEmitter", "m_flEmissionRate"); }
    void SetEmissionRate(float value) { SetSchemaValue(m_ptr, "C_OP_MaintainEmitter", "m_flEmissionRate", false, value); }
    int32_t GetSnapshotControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MaintainEmitter", "m_nSnapshotControlPoint"); }
    void SetSnapshotControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MaintainEmitter", "m_nSnapshotControlPoint", false, value); }
    bool GetEmitInstantaneously() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MaintainEmitter", "m_bEmitInstantaneously"); }
    void SetEmitInstantaneously(bool value) { SetSchemaValue(m_ptr, "C_OP_MaintainEmitter", "m_bEmitInstantaneously", false, value); }
    bool GetFinalEmitOnStop() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MaintainEmitter", "m_bFinalEmitOnStop"); }
    void SetFinalEmitOnStop(bool value) { SetSchemaValue(m_ptr, "C_OP_MaintainEmitter", "m_bFinalEmitOnStop", false, value); }
    GCParticleCollectionFloatInput GetScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_MaintainEmitter", "m_flScale"); }
    void SetScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MaintainEmitter", "m_flScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif