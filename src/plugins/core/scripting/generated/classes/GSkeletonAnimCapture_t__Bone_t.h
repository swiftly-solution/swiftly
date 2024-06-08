class GSkeletonAnimCapture_t__Bone_t;

#ifndef _gcskeletonanimcapture_t__bone_t_h
#define _gcskeletonanimcapture_t__bone_t_h

#include "../../../scripting.h"




class GSkeletonAnimCapture_t__Bone_t
{
private:
    void *m_ptr;

public:
    GSkeletonAnimCapture_t__Bone_t() {}
    GSkeletonAnimCapture_t__Bone_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "SkeletonAnimCapture_t__Bone_t", "m_Name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Bone_t", "m_Name", true, value); }
    int32_t GetParent() const { return GetSchemaValue<int32_t>(m_ptr, "SkeletonAnimCapture_t__Bone_t", "m_nParent"); }
    void SetParent(int32_t value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Bone_t", "m_nParent", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif