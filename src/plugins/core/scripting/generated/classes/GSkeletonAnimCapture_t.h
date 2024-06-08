class GSkeletonAnimCapture_t;

#ifndef _gcskeletonanimcapture_t_h
#define _gcskeletonanimcapture_t_h

#include "../../../scripting.h"


#include "GSkeletonAnimCapture_t.h"

class GSkeletonAnimCapture_t
{
private:
    void *m_ptr;

public:
    GSkeletonAnimCapture_t() {}
    GSkeletonAnimCapture_t(void *ptr) : m_ptr(ptr) {}

    CEntityIndex GetEntIndex() const { return GetSchemaValue<CEntityIndex>(m_ptr, "SkeletonAnimCapture_t", "m_nEntIndex"); }
    void SetEntIndex(CEntityIndex value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_nEntIndex", true, value); }
    CEntityIndex GetEntParent() const { return GetSchemaValue<CEntityIndex>(m_ptr, "SkeletonAnimCapture_t", "m_nEntParent"); }
    void SetEntParent(CEntityIndex value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_nEntParent", true, value); }
    std::vector<CEntityIndex> GetImportedCollision() const { CUtlVector<CEntityIndex>* vec = GetSchemaValue<CUtlVector<CEntityIndex>*>(m_ptr, "SkeletonAnimCapture_t", "m_ImportedCollision"); std::vector<CEntityIndex> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetImportedCollision(std::vector<CEntityIndex> value) { SetSchemaValueCUtlVector<CEntityIndex>(m_ptr, "SkeletonAnimCapture_t", "m_ImportedCollision", true, value); }
    CUtlString GetModelName() const { return GetSchemaValue<CUtlString>(m_ptr, "SkeletonAnimCapture_t", "m_ModelName"); }
    void SetModelName(CUtlString value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_ModelName", true, value); }
    CUtlString GetCaptureName() const { return GetSchemaValue<CUtlString>(m_ptr, "SkeletonAnimCapture_t", "m_CaptureName"); }
    void SetCaptureName(CUtlString value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_CaptureName", true, value); }
    std::vector<GSkeletonAnimCapture_t> GetModelBindPose() const { CUtlVector<GSkeletonAnimCapture_t>* vec = GetSchemaValue<CUtlVector<GSkeletonAnimCapture_t>*>(m_ptr, "SkeletonAnimCapture_t", "m_ModelBindPose"); std::vector<GSkeletonAnimCapture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetModelBindPose(std::vector<GSkeletonAnimCapture_t> value) { SetSchemaValueCUtlVector<GSkeletonAnimCapture_t>(m_ptr, "SkeletonAnimCapture_t", "m_ModelBindPose", true, value); }
    std::vector<GSkeletonAnimCapture_t> GetFeModelInitPose() const { CUtlVector<GSkeletonAnimCapture_t>* vec = GetSchemaValue<CUtlVector<GSkeletonAnimCapture_t>*>(m_ptr, "SkeletonAnimCapture_t", "m_FeModelInitPose"); std::vector<GSkeletonAnimCapture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFeModelInitPose(std::vector<GSkeletonAnimCapture_t> value) { SetSchemaValueCUtlVector<GSkeletonAnimCapture_t>(m_ptr, "SkeletonAnimCapture_t", "m_FeModelInitPose", true, value); }
    int32_t GetFlexControllers() const { return GetSchemaValue<int32_t>(m_ptr, "SkeletonAnimCapture_t", "m_nFlexControllers"); }
    void SetFlexControllers(int32_t value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_nFlexControllers", true, value); }
    bool GetPredicted() const { return GetSchemaValue<bool>(m_ptr, "SkeletonAnimCapture_t", "m_bPredicted"); }
    void SetPredicted(bool value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_bPredicted", true, value); }
    std::vector<GSkeletonAnimCapture_t> GetFrames() const { CUtlVector<GSkeletonAnimCapture_t>* vec = GetSchemaValue<CUtlVector<GSkeletonAnimCapture_t>*>(m_ptr, "SkeletonAnimCapture_t", "m_Frames"); std::vector<GSkeletonAnimCapture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFrames(std::vector<GSkeletonAnimCapture_t> value) { SetSchemaValueCUtlVector<GSkeletonAnimCapture_t>(m_ptr, "SkeletonAnimCapture_t", "m_Frames", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif