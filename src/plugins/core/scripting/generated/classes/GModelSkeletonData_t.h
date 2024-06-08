class GModelSkeletonData_t;

#ifndef _gcmodelskeletondata_t_h
#define _gcmodelskeletondata_t_h

#include "../../../scripting.h"




class GModelSkeletonData_t
{
private:
    void *m_ptr;

public:
    GModelSkeletonData_t() {}
    GModelSkeletonData_t(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlString> GetBoneName() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "ModelSkeletonData_t", "m_boneName"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneName(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "ModelSkeletonData_t", "m_boneName", true, value); }
    std::vector<int16> GetParent() const { CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "ModelSkeletonData_t", "m_nParent"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetParent(std::vector<int16> value) { SetSchemaValueCUtlVector<int16>(m_ptr, "ModelSkeletonData_t", "m_nParent", true, value); }
    std::vector<float32> GetBoneSphere() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "ModelSkeletonData_t", "m_boneSphere"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneSphere(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "ModelSkeletonData_t", "m_boneSphere", true, value); }
    std::vector<uint32> GetFlag() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "ModelSkeletonData_t", "m_nFlag"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFlag(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "ModelSkeletonData_t", "m_nFlag", true, value); }
    std::vector<Vector> GetBonePosParent() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "ModelSkeletonData_t", "m_bonePosParent"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBonePosParent(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "ModelSkeletonData_t", "m_bonePosParent", true, value); }
    std::vector<float32> GetBoneScaleParent() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "ModelSkeletonData_t", "m_boneScaleParent"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneScaleParent(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "ModelSkeletonData_t", "m_boneScaleParent", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif