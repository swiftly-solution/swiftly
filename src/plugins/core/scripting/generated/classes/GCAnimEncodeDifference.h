class GCAnimEncodeDifference;

#ifndef _gccanimencodedifference_h
#define _gccanimencodedifference_h

#include "../../../scripting.h"


#include "GCAnimBoneDifference.h"
#include "GCAnimBone.h"
#include "GCAnimMorphDifference.h"
#include "GCAnimUserDifference.h"
#include "GCAnimUser.h"

class GCAnimEncodeDifference
{
private:
    void *m_ptr;

public:
    GCAnimEncodeDifference() {}
    GCAnimEncodeDifference(void *ptr) : m_ptr(ptr) {}

    std::vector<GCAnimBoneDifference> GetBoneArray() const { CUtlVector<GCAnimBoneDifference>* vec = GetSchemaValue<CUtlVector<GCAnimBoneDifference>*>(m_ptr, "CAnimEncodeDifference", "m_boneArray"); std::vector<GCAnimBoneDifference> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneArray(std::vector<GCAnimBoneDifference> value) { SetSchemaValueCUtlVector<GCAnimBoneDifference>(m_ptr, "CAnimEncodeDifference", "m_boneArray", false, value); }
    std::vector<GCAnimMorphDifference> GetMorphArray() const { CUtlVector<GCAnimMorphDifference>* vec = GetSchemaValue<CUtlVector<GCAnimMorphDifference>*>(m_ptr, "CAnimEncodeDifference", "m_morphArray"); std::vector<GCAnimMorphDifference> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMorphArray(std::vector<GCAnimMorphDifference> value) { SetSchemaValueCUtlVector<GCAnimMorphDifference>(m_ptr, "CAnimEncodeDifference", "m_morphArray", false, value); }
    std::vector<GCAnimUserDifference> GetUserArray() const { CUtlVector<GCAnimUserDifference>* vec = GetSchemaValue<CUtlVector<GCAnimUserDifference>*>(m_ptr, "CAnimEncodeDifference", "m_userArray"); std::vector<GCAnimUserDifference> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetUserArray(std::vector<GCAnimUserDifference> value) { SetSchemaValueCUtlVector<GCAnimUserDifference>(m_ptr, "CAnimEncodeDifference", "m_userArray", false, value); }
    std::vector<uint8> GetHasRotationBitArray() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimEncodeDifference", "m_bHasRotationBitArray"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetHasRotationBitArray(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimEncodeDifference", "m_bHasRotationBitArray", false, value); }
    std::vector<uint8> GetHasMovementBitArray() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimEncodeDifference", "m_bHasMovementBitArray"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetHasMovementBitArray(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimEncodeDifference", "m_bHasMovementBitArray", false, value); }
    std::vector<uint8> GetHasMorphBitArray() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimEncodeDifference", "m_bHasMorphBitArray"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetHasMorphBitArray(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimEncodeDifference", "m_bHasMorphBitArray", false, value); }
    std::vector<uint8> GetHasUserBitArray() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimEncodeDifference", "m_bHasUserBitArray"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetHasUserBitArray(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimEncodeDifference", "m_bHasUserBitArray", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif