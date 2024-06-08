class GCAnimKeyData;

#ifndef _gccanimkeydata_h
#define _gccanimkeydata_h

#include "../../../scripting.h"


#include "GCAnimBone.h"
#include "GCAnimUser.h"
#include "GCAnimDataChannelDesc.h"
#include "GCAnimData.h"

class GCAnimKeyData
{
private:
    void *m_ptr;

public:
    GCAnimKeyData() {}
    GCAnimKeyData(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimKeyData", "m_name"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimKeyData", "m_name", false, value); }
    std::vector<GCAnimBone> GetBoneArray() const { CUtlVector<GCAnimBone>* vec = GetSchemaValue<CUtlVector<GCAnimBone>*>(m_ptr, "CAnimKeyData", "m_boneArray"); std::vector<GCAnimBone> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneArray(std::vector<GCAnimBone> value) { SetSchemaValueCUtlVector<GCAnimBone>(m_ptr, "CAnimKeyData", "m_boneArray", false, value); }
    std::vector<GCAnimUser> GetUserArray() const { CUtlVector<GCAnimUser>* vec = GetSchemaValue<CUtlVector<GCAnimUser>*>(m_ptr, "CAnimKeyData", "m_userArray"); std::vector<GCAnimUser> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetUserArray(std::vector<GCAnimUser> value) { SetSchemaValueCUtlVector<GCAnimUser>(m_ptr, "CAnimKeyData", "m_userArray", false, value); }
    std::vector<CBufferString> GetMorphArray() const { CUtlVector<CBufferString>* vec = GetSchemaValue<CUtlVector<CBufferString>*>(m_ptr, "CAnimKeyData", "m_morphArray"); std::vector<CBufferString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMorphArray(std::vector<CBufferString> value) { SetSchemaValueCUtlVector<CBufferString>(m_ptr, "CAnimKeyData", "m_morphArray", false, value); }
    int32_t GetChannelElements() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimKeyData", "m_nChannelElements"); }
    void SetChannelElements(int32_t value) { SetSchemaValue(m_ptr, "CAnimKeyData", "m_nChannelElements", false, value); }
    std::vector<GCAnimDataChannelDesc> GetDataChannelArray() const { CUtlVector<GCAnimDataChannelDesc>* vec = GetSchemaValue<CUtlVector<GCAnimDataChannelDesc>*>(m_ptr, "CAnimKeyData", "m_dataChannelArray"); std::vector<GCAnimDataChannelDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDataChannelArray(std::vector<GCAnimDataChannelDesc> value) { SetSchemaValueCUtlVector<GCAnimDataChannelDesc>(m_ptr, "CAnimKeyData", "m_dataChannelArray", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif