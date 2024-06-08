class GCSeqMultiFetch;

#ifndef _gccseqmultifetch_h
#define _gccseqmultifetch_h

#include "../../../scripting.h"


#include "GCSeqMultiFetchFlag.h"
#include "GCSeqMultiFetch.h"

class GCSeqMultiFetch
{
private:
    void *m_ptr;

public:
    GCSeqMultiFetch() {}
    GCSeqMultiFetch(void *ptr) : m_ptr(ptr) {}

    GCSeqMultiFetchFlag GetFlags() const { return GetSchemaValue<GCSeqMultiFetchFlag>(m_ptr, "CSeqMultiFetch", "m_flags"); }
    void SetFlags(GCSeqMultiFetchFlag value) { SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_flags", false, value); }
    std::vector<int16> GetLocalReferenceArray() const { CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "CSeqMultiFetch", "m_localReferenceArray"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalReferenceArray(std::vector<int16> value) { SetSchemaValueCUtlVector<int16>(m_ptr, "CSeqMultiFetch", "m_localReferenceArray", false, value); }
    std::vector<int32_t> GetGroupSize() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSeqMultiFetch", "m_nGroupSize"); std::vector<int32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetGroupSize(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSeqMultiFetch", "m_nGroupSize"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_nGroupSize", false, outValue); }
    std::vector<int32_t> GetLocalPose() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSeqMultiFetch", "m_nLocalPose"); std::vector<int32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetLocalPose(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSeqMultiFetch", "m_nLocalPose"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_nLocalPose", false, outValue); }
    std::vector<float32> GetPoseKeyArray0() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CSeqMultiFetch", "m_poseKeyArray0"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPoseKeyArray0(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CSeqMultiFetch", "m_poseKeyArray0", false, value); }
    std::vector<float32> GetPoseKeyArray1() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CSeqMultiFetch", "m_poseKeyArray1"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPoseKeyArray1(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CSeqMultiFetch", "m_poseKeyArray1", false, value); }
    int32_t GetLocalCyclePoseParameter() const { return GetSchemaValue<int32_t>(m_ptr, "CSeqMultiFetch", "m_nLocalCyclePoseParameter"); }
    void SetLocalCyclePoseParameter(int32_t value) { SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_nLocalCyclePoseParameter", false, value); }
    bool GetCalculatePoseParameters() const { return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetch", "m_bCalculatePoseParameters"); }
    void SetCalculatePoseParameters(bool value) { SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_bCalculatePoseParameters", false, value); }
    bool GetFixedBlendWeight() const { return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetch", "m_bFixedBlendWeight"); }
    void SetFixedBlendWeight(bool value) { SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_bFixedBlendWeight", false, value); }
    std::vector<float> GetFixedBlendWeightVals() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CSeqMultiFetch", "m_flFixedBlendWeightVals"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetFixedBlendWeightVals(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CSeqMultiFetch", "m_flFixedBlendWeightVals"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_flFixedBlendWeightVals", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif