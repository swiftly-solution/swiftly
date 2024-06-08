class GCStaticPoseCache;

#ifndef _gccstaticposecache_h
#define _gccstaticposecache_h

#include "../../../scripting.h"


#include "GCCachedPose.h"

class GCStaticPoseCache
{
private:
    void *m_ptr;

public:
    GCStaticPoseCache() {}
    GCStaticPoseCache(void *ptr) : m_ptr(ptr) {}

    std::vector<GCCachedPose> GetPoses() const { CUtlVector<GCCachedPose>* vec = GetSchemaValue<CUtlVector<GCCachedPose>*>(m_ptr, "CStaticPoseCache", "m_poses"); std::vector<GCCachedPose> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPoses(std::vector<GCCachedPose> value) { SetSchemaValueCUtlVector<GCCachedPose>(m_ptr, "CStaticPoseCache", "m_poses", false, value); }
    int32_t GetBoneCount() const { return GetSchemaValue<int32_t>(m_ptr, "CStaticPoseCache", "m_nBoneCount"); }
    void SetBoneCount(int32_t value) { SetSchemaValue(m_ptr, "CStaticPoseCache", "m_nBoneCount", false, value); }
    int32_t GetMorphCount() const { return GetSchemaValue<int32_t>(m_ptr, "CStaticPoseCache", "m_nMorphCount"); }
    void SetMorphCount(int32_t value) { SetSchemaValue(m_ptr, "CStaticPoseCache", "m_nMorphCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif