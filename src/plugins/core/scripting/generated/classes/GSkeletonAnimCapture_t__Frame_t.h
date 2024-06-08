class GSkeletonAnimCapture_t__Frame_t;

#ifndef _gcskeletonanimcapture_t__frame_t_h
#define _gcskeletonanimcapture_t__frame_t_h

#include "../../../scripting.h"


#include "GSkeletonAnimCapture_t.h"

class GSkeletonAnimCapture_t__Frame_t
{
private:
    void *m_ptr;

public:
    GSkeletonAnimCapture_t__Frame_t() {}
    GSkeletonAnimCapture_t__Frame_t(void *ptr) : m_ptr(ptr) {}

    float GetTime() const { return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_flTime"); }
    void SetTime(float value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_flTime", true, value); }
    GSkeletonAnimCapture_t GetStamp() const { return GetSchemaValue<GSkeletonAnimCapture_t>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_Stamp"); }
    void SetStamp(GSkeletonAnimCapture_t value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_Stamp", true, value); }
    bool GetTeleport() const { return GetSchemaValue<bool>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_bTeleport"); }
    void SetTeleport(bool value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_bTeleport", true, value); }
    std::vector<Vector> GetFeModelPos() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_FeModelPos"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFeModelPos(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_FeModelPos", true, value); }
    std::vector<float32> GetFlexControllerWeights() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_FlexControllerWeights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFlexControllerWeights(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_FlexControllerWeights", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif