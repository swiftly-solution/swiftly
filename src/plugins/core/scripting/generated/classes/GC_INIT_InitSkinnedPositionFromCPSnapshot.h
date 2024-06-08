class GC_INIT_InitSkinnedPositionFromCPSnapshot;

#ifndef _gcc_init_initskinnedpositionfromcpsnapshot_h
#define _gcc_init_initskinnedpositionfromcpsnapshot_h

#include "../../../scripting.h"

#include "../types/GSnapshotIndexType_t.h"
#include "GCPerParticleFloatInput.h"

class GC_INIT_InitSkinnedPositionFromCPSnapshot
{
private:
    void *m_ptr;

public:
    GC_INIT_InitSkinnedPositionFromCPSnapshot() {}
    GC_INIT_InitSkinnedPositionFromCPSnapshot(void *ptr) : m_ptr(ptr) {}

    int32_t GetSnapshotControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nSnapshotControlPointNumber"); }
    void SetSnapshotControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nSnapshotControlPointNumber", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nControlPointNumber", false, value); }
    bool GetRandom() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bRandom"); }
    void SetRandom(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bRandom", false, value); }
    int32_t GetRandomSeed() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nRandomSeed"); }
    void SetRandomSeed(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nRandomSeed", false, value); }
    bool GetRigid() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bRigid"); }
    void SetRigid(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bRigid", false, value); }
    bool GetSetNormal() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bSetNormal"); }
    void SetSetNormal(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bSetNormal", false, value); }
    bool GetIgnoreDt() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bIgnoreDt"); }
    void SetIgnoreDt(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bIgnoreDt", false, value); }
    float GetMinNormalVelocity() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flMinNormalVelocity"); }
    void SetMinNormalVelocity(float value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flMinNormalVelocity", false, value); }
    float GetMaxNormalVelocity() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flMaxNormalVelocity"); }
    void SetMaxNormalVelocity(float value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flMaxNormalVelocity", false, value); }
    SnapshotIndexType_t GetIndexType() const { return GetSchemaValue<SnapshotIndexType_t>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nIndexType"); }
    void SetIndexType(SnapshotIndexType_t value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nIndexType", false, value); }
    GCPerParticleFloatInput GetReadIndex() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flReadIndex"); }
    void SetReadIndex(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flReadIndex", false, value); }
    float GetIncrement() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flIncrement"); }
    void SetIncrement(float value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flIncrement", false, value); }
    int32_t GetFullLoopIncrement() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nFullLoopIncrement"); }
    void SetFullLoopIncrement(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nFullLoopIncrement", false, value); }
    int32_t GetSnapShotStartPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nSnapShotStartPoint"); }
    void SetSnapShotStartPoint(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_nSnapShotStartPoint", false, value); }
    float GetBoneVelocity() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flBoneVelocity"); }
    void SetBoneVelocity(float value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flBoneVelocity", false, value); }
    float GetBoneVelocityMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flBoneVelocityMax"); }
    void SetBoneVelocityMax(float value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_flBoneVelocityMax", false, value); }
    bool GetCopyColor() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bCopyColor"); }
    void SetCopyColor(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bCopyColor", false, value); }
    bool GetCopyAlpha() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bCopyAlpha"); }
    void SetCopyAlpha(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bCopyAlpha", false, value); }
    bool GetSetRadius() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bSetRadius"); }
    void SetSetRadius(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitSkinnedPositionFromCPSnapshot", "m_bSetRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif