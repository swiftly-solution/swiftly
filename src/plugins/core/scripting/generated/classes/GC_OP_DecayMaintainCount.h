class GC_OP_DecayMaintainCount;

#ifndef _gcc_op_decaymaintaincount_h
#define _gcc_op_decaymaintaincount_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_DecayMaintainCount
{
private:
    void *m_ptr;

public:
    GC_OP_DecayMaintainCount() {}
    GC_OP_DecayMaintainCount(void *ptr) : m_ptr(ptr) {}

    int32_t GetParticlesToMaintain() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_DecayMaintainCount", "m_nParticlesToMaintain"); }
    void SetParticlesToMaintain(int32_t value) { SetSchemaValue(m_ptr, "C_OP_DecayMaintainCount", "m_nParticlesToMaintain", false, value); }
    float GetDecayDelay() const { return GetSchemaValue<float>(m_ptr, "C_OP_DecayMaintainCount", "m_flDecayDelay"); }
    void SetDecayDelay(float value) { SetSchemaValue(m_ptr, "C_OP_DecayMaintainCount", "m_flDecayDelay", false, value); }
    int32_t GetSnapshotControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_DecayMaintainCount", "m_nSnapshotControlPoint"); }
    void SetSnapshotControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_DecayMaintainCount", "m_nSnapshotControlPoint", false, value); }
    bool GetLifespanDecay() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DecayMaintainCount", "m_bLifespanDecay"); }
    void SetLifespanDecay(bool value) { SetSchemaValue(m_ptr, "C_OP_DecayMaintainCount", "m_bLifespanDecay", false, value); }
    GCParticleCollectionFloatInput GetScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_DecayMaintainCount", "m_flScale"); }
    void SetScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DecayMaintainCount", "m_flScale", false, value); }
    bool GetKillNewest() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DecayMaintainCount", "m_bKillNewest"); }
    void SetKillNewest(bool value) { SetSchemaValue(m_ptr, "C_OP_DecayMaintainCount", "m_bKillNewest", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif