class GC_OP_MovementSkinnedPositionFromCPSnapshot;

#ifndef _gcc_op_movementskinnedpositionfromcpsnapshot_h
#define _gcc_op_movementskinnedpositionfromcpsnapshot_h

#include "../../../scripting.h"

#include "../types/GSnapshotIndexType_t.h"
#include "GCPerParticleFloatInput.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_MovementSkinnedPositionFromCPSnapshot
{
private:
    void *m_ptr;

public:
    GC_OP_MovementSkinnedPositionFromCPSnapshot() {}
    GC_OP_MovementSkinnedPositionFromCPSnapshot(void *ptr) : m_ptr(ptr) {}

    int32_t GetSnapshotControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nSnapshotControlPointNumber"); }
    void SetSnapshotControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nSnapshotControlPointNumber", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nControlPointNumber", false, value); }
    bool GetRandom() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_bRandom"); }
    void SetRandom(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_bRandom", false, value); }
    int32_t GetRandomSeed() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nRandomSeed"); }
    void SetRandomSeed(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nRandomSeed", false, value); }
    bool GetSetNormal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_bSetNormal"); }
    void SetSetNormal(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_bSetNormal", false, value); }
    bool GetSetRadius() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_bSetRadius"); }
    void SetSetRadius(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_bSetRadius", false, value); }
    SnapshotIndexType_t GetIndexType() const { return GetSchemaValue<SnapshotIndexType_t>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nIndexType"); }
    void SetIndexType(SnapshotIndexType_t value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nIndexType", false, value); }
    GCPerParticleFloatInput GetReadIndex() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_flReadIndex"); }
    void SetReadIndex(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_flReadIndex", false, value); }
    GCParticleCollectionFloatInput GetIncrement() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_flIncrement"); }
    void SetIncrement(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_flIncrement", false, value); }
    GCParticleCollectionFloatInput GetFullLoopIncrement() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nFullLoopIncrement"); }
    void SetFullLoopIncrement(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nFullLoopIncrement", false, value); }
    GCParticleCollectionFloatInput GetSnapShotStartPoint() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nSnapShotStartPoint"); }
    void SetSnapShotStartPoint(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_nSnapShotStartPoint", false, value); }
    GCPerParticleFloatInput GetInterpolation() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_flInterpolation"); }
    void SetInterpolation(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MovementSkinnedPositionFromCPSnapshot", "m_flInterpolation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif