class GCSeqScaleSet;

#ifndef _gccseqscaleset_h
#define _gccseqscaleset_h

#include "../../../scripting.h"




class GCSeqScaleSet
{
private:
    void *m_ptr;

public:
    GCSeqScaleSet() {}
    GCSeqScaleSet(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CSeqScaleSet", "m_sName"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CSeqScaleSet", "m_sName", false, value); }
    bool GetRootOffset() const { return GetSchemaValue<bool>(m_ptr, "CSeqScaleSet", "m_bRootOffset"); }
    void SetRootOffset(bool value) { SetSchemaValue(m_ptr, "CSeqScaleSet", "m_bRootOffset", false, value); }
    Vector GetRootOffset1() const { return GetSchemaValue<Vector>(m_ptr, "CSeqScaleSet", "m_vRootOffset"); }
    void SetRootOffset1(Vector value) { SetSchemaValue(m_ptr, "CSeqScaleSet", "m_vRootOffset", false, value); }
    std::vector<int16> GetLocalBoneArray() const { CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "CSeqScaleSet", "m_nLocalBoneArray"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalBoneArray(std::vector<int16> value) { SetSchemaValueCUtlVector<int16>(m_ptr, "CSeqScaleSet", "m_nLocalBoneArray", false, value); }
    std::vector<float32> GetBoneScaleArray() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CSeqScaleSet", "m_flBoneScaleArray"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneScaleArray(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CSeqScaleSet", "m_flBoneScaleArray", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif