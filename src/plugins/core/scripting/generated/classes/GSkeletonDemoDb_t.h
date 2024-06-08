class GSkeletonDemoDb_t;

#ifndef _gcskeletondemodb_t_h
#define _gcskeletondemodb_t_h

#include "../../../scripting.h"


#include "GSkeletonAnimCapture_t.h"

class GSkeletonDemoDb_t
{
private:
    void *m_ptr;

public:
    GSkeletonDemoDb_t() {}
    GSkeletonDemoDb_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GSkeletonAnimCapture_t*> GetAnimCaptures() const { CUtlVector<GSkeletonAnimCapture_t*>* vec = GetSchemaValue<CUtlVector<GSkeletonAnimCapture_t*>*>(m_ptr, "SkeletonDemoDb_t", "m_AnimCaptures"); std::vector<GSkeletonAnimCapture_t*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAnimCaptures(std::vector<GSkeletonAnimCapture_t*> value) { SetSchemaValueCUtlVector<GSkeletonAnimCapture_t*>(m_ptr, "SkeletonDemoDb_t", "m_AnimCaptures", true, value); }
    std::vector<GSkeletonAnimCapture_t> GetCameraTrack() const { CUtlVector<GSkeletonAnimCapture_t>* vec = GetSchemaValue<CUtlVector<GSkeletonAnimCapture_t>*>(m_ptr, "SkeletonDemoDb_t", "m_CameraTrack"); std::vector<GSkeletonAnimCapture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCameraTrack(std::vector<GSkeletonAnimCapture_t> value) { SetSchemaValueCUtlVector<GSkeletonAnimCapture_t>(m_ptr, "SkeletonDemoDb_t", "m_CameraTrack", true, value); }
    float GetRecordingTime() const { return GetSchemaValue<float>(m_ptr, "SkeletonDemoDb_t", "m_flRecordingTime"); }
    void SetRecordingTime(float value) { SetSchemaValue(m_ptr, "SkeletonDemoDb_t", "m_flRecordingTime", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif