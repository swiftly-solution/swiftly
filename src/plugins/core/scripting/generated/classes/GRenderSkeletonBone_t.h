class GRenderSkeletonBone_t;

#ifndef _gcrenderskeletonbone_t_h
#define _gcrenderskeletonbone_t_h

#include "../../../scripting.h"


#include "GSkeletonBoneBounds_t.h"

class GRenderSkeletonBone_t
{
private:
    void *m_ptr;

public:
    GRenderSkeletonBone_t() {}
    GRenderSkeletonBone_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetBoneName() const { return GetSchemaValue<CUtlString>(m_ptr, "RenderSkeletonBone_t", "m_boneName"); }
    void SetBoneName(CUtlString value) { SetSchemaValue(m_ptr, "RenderSkeletonBone_t", "m_boneName", true, value); }
    CUtlString GetParentName() const { return GetSchemaValue<CUtlString>(m_ptr, "RenderSkeletonBone_t", "m_parentName"); }
    void SetParentName(CUtlString value) { SetSchemaValue(m_ptr, "RenderSkeletonBone_t", "m_parentName", true, value); }
    matrix3x4_t GetInvBindPose() const { return GetSchemaValue<matrix3x4_t>(m_ptr, "RenderSkeletonBone_t", "m_invBindPose"); }
    void SetInvBindPose(matrix3x4_t value) { SetSchemaValue(m_ptr, "RenderSkeletonBone_t", "m_invBindPose", true, value); }
    GSkeletonBoneBounds_t GetBbox() const { return GetSchemaValue<GSkeletonBoneBounds_t>(m_ptr, "RenderSkeletonBone_t", "m_bbox"); }
    void SetBbox(GSkeletonBoneBounds_t value) { SetSchemaValue(m_ptr, "RenderSkeletonBone_t", "m_bbox", true, value); }
    float GetSphereRadius() const { return GetSchemaValue<float>(m_ptr, "RenderSkeletonBone_t", "m_flSphereRadius"); }
    void SetSphereRadius(float value) { SetSchemaValue(m_ptr, "RenderSkeletonBone_t", "m_flSphereRadius", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif