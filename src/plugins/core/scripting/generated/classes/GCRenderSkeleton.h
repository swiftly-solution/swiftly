class GCRenderSkeleton;

#ifndef _gccrenderskeleton_h
#define _gccrenderskeleton_h

#include "../../../scripting.h"


#include "GRenderSkeletonBone_t.h"

class GCRenderSkeleton
{
private:
    void *m_ptr;

public:
    GCRenderSkeleton() {}
    GCRenderSkeleton(void *ptr) : m_ptr(ptr) {}

    std::vector<GRenderSkeletonBone_t> GetBones() const { CUtlVector<GRenderSkeletonBone_t>* vec = GetSchemaValue<CUtlVector<GRenderSkeletonBone_t>*>(m_ptr, "CRenderSkeleton", "m_bones"); std::vector<GRenderSkeletonBone_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBones(std::vector<GRenderSkeletonBone_t> value) { SetSchemaValueCUtlVector<GRenderSkeletonBone_t>(m_ptr, "CRenderSkeleton", "m_bones", false, value); }
    std::vector<int32> GetBoneParents() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CRenderSkeleton", "m_boneParents"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneParents(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CRenderSkeleton", "m_boneParents", false, value); }
    int32_t GetBoneWeightCount() const { return GetSchemaValue<int32_t>(m_ptr, "CRenderSkeleton", "m_nBoneWeightCount"); }
    void SetBoneWeightCount(int32_t value) { SetSchemaValue(m_ptr, "CRenderSkeleton", "m_nBoneWeightCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif