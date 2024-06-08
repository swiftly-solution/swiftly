class GCSeqBoneMaskList;

#ifndef _gccseqbonemasklist_h
#define _gccseqbonemasklist_h

#include "../../../scripting.h"




class GCSeqBoneMaskList
{
private:
    void *m_ptr;

public:
    GCSeqBoneMaskList() {}
    GCSeqBoneMaskList(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CSeqBoneMaskList", "m_sName"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CSeqBoneMaskList", "m_sName", false, value); }
    std::vector<int16> GetLocalBoneArray() const { CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "CSeqBoneMaskList", "m_nLocalBoneArray"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalBoneArray(std::vector<int16> value) { SetSchemaValueCUtlVector<int16>(m_ptr, "CSeqBoneMaskList", "m_nLocalBoneArray", false, value); }
    std::vector<float32> GetBoneWeightArray() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CSeqBoneMaskList", "m_flBoneWeightArray"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneWeightArray(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CSeqBoneMaskList", "m_flBoneWeightArray", false, value); }
    float GetDefaultMorphCtrlWeight() const { return GetSchemaValue<float>(m_ptr, "CSeqBoneMaskList", "m_flDefaultMorphCtrlWeight"); }
    void SetDefaultMorphCtrlWeight(float value) { SetSchemaValue(m_ptr, "CSeqBoneMaskList", "m_flDefaultMorphCtrlWeight", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif