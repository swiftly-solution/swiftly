class GC_OP_LightningSnapshotGenerator;

#ifndef _gcc_op_lightningsnapshotgenerator_h
#define _gcc_op_lightningsnapshotgenerator_h

#include "../../../scripting.h"

#include "../types/GParticleLightnintBranchBehavior_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_LightningSnapshotGenerator
{
private:
    void *m_ptr;

public:
    GC_OP_LightningSnapshotGenerator() {}
    GC_OP_LightningSnapshotGenerator(void *ptr) : m_ptr(ptr) {}

    int32_t GetCPSnapshot() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_nCPSnapshot"); }
    void SetCPSnapshot(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_nCPSnapshot", false, value); }
    int32_t GetCPStartPnt() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_nCPStartPnt"); }
    void SetCPStartPnt(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_nCPStartPnt", false, value); }
    int32_t GetCPEndPnt() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_nCPEndPnt"); }
    void SetCPEndPnt(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_nCPEndPnt", false, value); }
    GCParticleCollectionFloatInput GetSegments() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flSegments"); }
    void SetSegments(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flSegments", false, value); }
    GCParticleCollectionFloatInput GetOffset() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flOffset"); }
    void SetOffset(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flOffset", false, value); }
    GCParticleCollectionFloatInput GetOffsetDecay() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flOffsetDecay"); }
    void SetOffsetDecay(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flOffsetDecay", false, value); }
    GCParticleCollectionFloatInput GetRecalcRate() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flRecalcRate"); }
    void SetRecalcRate(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flRecalcRate", false, value); }
    GCParticleCollectionFloatInput GetUVScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flUVScale"); }
    void SetUVScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flUVScale", false, value); }
    GCParticleCollectionFloatInput GetUVOffset() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flUVOffset"); }
    void SetUVOffset(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flUVOffset", false, value); }
    GCParticleCollectionFloatInput GetSplitRate() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flSplitRate"); }
    void SetSplitRate(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flSplitRate", false, value); }
    GCParticleCollectionFloatInput GetBranchTwist() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flBranchTwist"); }
    void SetBranchTwist(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flBranchTwist", false, value); }
    ParticleLightnintBranchBehavior_t GetBranchBehavior() const { return GetSchemaValue<ParticleLightnintBranchBehavior_t>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_nBranchBehavior"); }
    void SetBranchBehavior(ParticleLightnintBranchBehavior_t value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_nBranchBehavior", false, value); }
    GCParticleCollectionFloatInput GetRadiusStart() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flRadiusStart"); }
    void SetRadiusStart(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flRadiusStart", false, value); }
    GCParticleCollectionFloatInput GetRadiusEnd() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flRadiusEnd"); }
    void SetRadiusEnd(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flRadiusEnd", false, value); }
    GCParticleCollectionFloatInput GetDedicatedPool() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flDedicatedPool"); }
    void SetDedicatedPool(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LightningSnapshotGenerator", "m_flDedicatedPool", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif