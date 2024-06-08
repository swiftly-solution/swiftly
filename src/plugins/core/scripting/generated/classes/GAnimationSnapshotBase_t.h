class GAnimationSnapshotBase_t;

#ifndef _gcanimationsnapshotbase_t_h
#define _gcanimationsnapshotbase_t_h

#include "../../../scripting.h"

#include "../types/GAnimationSnapshotType_t.h"
#include "GAnimationDecodeDebugDumpElement_t.h"

class GAnimationSnapshotBase_t
{
private:
    void *m_ptr;

public:
    GAnimationSnapshotBase_t() {}
    GAnimationSnapshotBase_t(void *ptr) : m_ptr(ptr) {}

    float GetRealTime() const { return GetSchemaValue<float>(m_ptr, "AnimationSnapshotBase_t", "m_flRealTime"); }
    void SetRealTime(float value) { SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_flRealTime", true, value); }
    matrix3x4a_t GetRootToWorld() const { return GetSchemaValue<matrix3x4a_t>(m_ptr, "AnimationSnapshotBase_t", "m_rootToWorld"); }
    void SetRootToWorld(matrix3x4a_t value) { SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_rootToWorld", true, value); }
    bool GetBonesInWorldSpace() const { return GetSchemaValue<bool>(m_ptr, "AnimationSnapshotBase_t", "m_bBonesInWorldSpace"); }
    void SetBonesInWorldSpace(bool value) { SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_bBonesInWorldSpace", true, value); }
    std::vector<uint32> GetBoneSetupMask() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "AnimationSnapshotBase_t", "m_boneSetupMask"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneSetupMask(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "AnimationSnapshotBase_t", "m_boneSetupMask", true, value); }
    std::vector<matrix3x4a_t> GetBoneTransforms() const { CUtlVector<matrix3x4a_t>* vec = GetSchemaValue<CUtlVector<matrix3x4a_t>*>(m_ptr, "AnimationSnapshotBase_t", "m_boneTransforms"); std::vector<matrix3x4a_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneTransforms(std::vector<matrix3x4a_t> value) { SetSchemaValueCUtlVector<matrix3x4a_t>(m_ptr, "AnimationSnapshotBase_t", "m_boneTransforms", true, value); }
    std::vector<float32> GetFlexControllers() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "AnimationSnapshotBase_t", "m_flexControllers"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFlexControllers(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "AnimationSnapshotBase_t", "m_flexControllers", true, value); }
    AnimationSnapshotType_t GetSnapshotType() const { return GetSchemaValue<AnimationSnapshotType_t>(m_ptr, "AnimationSnapshotBase_t", "m_SnapshotType"); }
    void SetSnapshotType(AnimationSnapshotType_t value) { SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_SnapshotType", true, value); }
    bool GetHasDecodeDump() const { return GetSchemaValue<bool>(m_ptr, "AnimationSnapshotBase_t", "m_bHasDecodeDump"); }
    void SetHasDecodeDump(bool value) { SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_bHasDecodeDump", true, value); }
    GAnimationDecodeDebugDumpElement_t GetDecodeDump() const { return GetSchemaValue<GAnimationDecodeDebugDumpElement_t>(m_ptr, "AnimationSnapshotBase_t", "m_DecodeDump"); }
    void SetDecodeDump(GAnimationDecodeDebugDumpElement_t value) { SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_DecodeDump", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif