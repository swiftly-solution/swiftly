class GCSequenceGroupData;

#ifndef _gccsequencegroupdata_h
#define _gccsequencegroupdata_h

#include "../../../scripting.h"


#include "GCSeqS1SeqDesc.h"
#include "GCSeqSynthAnimDesc.h"
#include "GCSeqCmdSeqDesc.h"
#include "GCSeqBoneMaskList.h"
#include "GCSeqScaleSet.h"
#include "GCSeqPoseParamDesc.h"
#include "GCSeqIKLock.h"

class GCSequenceGroupData
{
private:
    void *m_ptr;

public:
    GCSequenceGroupData() {}
    GCSequenceGroupData(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CSequenceGroupData", "m_sName"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CSequenceGroupData", "m_sName", false, value); }
    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "CSequenceGroupData", "m_nFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "CSequenceGroupData", "m_nFlags", false, value); }
    std::vector<CBufferString> GetLocalSequenceNameArray() const { CUtlVector<CBufferString>* vec = GetSchemaValue<CUtlVector<CBufferString>*>(m_ptr, "CSequenceGroupData", "m_localSequenceNameArray"); std::vector<CBufferString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalSequenceNameArray(std::vector<CBufferString> value) { SetSchemaValueCUtlVector<CBufferString>(m_ptr, "CSequenceGroupData", "m_localSequenceNameArray", false, value); }
    std::vector<GCSeqS1SeqDesc> GetLocalS1SeqDescArray() const { CUtlVector<GCSeqS1SeqDesc>* vec = GetSchemaValue<CUtlVector<GCSeqS1SeqDesc>*>(m_ptr, "CSequenceGroupData", "m_localS1SeqDescArray"); std::vector<GCSeqS1SeqDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalS1SeqDescArray(std::vector<GCSeqS1SeqDesc> value) { SetSchemaValueCUtlVector<GCSeqS1SeqDesc>(m_ptr, "CSequenceGroupData", "m_localS1SeqDescArray", false, value); }
    std::vector<GCSeqS1SeqDesc> GetLocalMultiSeqDescArray() const { CUtlVector<GCSeqS1SeqDesc>* vec = GetSchemaValue<CUtlVector<GCSeqS1SeqDesc>*>(m_ptr, "CSequenceGroupData", "m_localMultiSeqDescArray"); std::vector<GCSeqS1SeqDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalMultiSeqDescArray(std::vector<GCSeqS1SeqDesc> value) { SetSchemaValueCUtlVector<GCSeqS1SeqDesc>(m_ptr, "CSequenceGroupData", "m_localMultiSeqDescArray", false, value); }
    std::vector<GCSeqSynthAnimDesc> GetLocalSynthAnimDescArray() const { CUtlVector<GCSeqSynthAnimDesc>* vec = GetSchemaValue<CUtlVector<GCSeqSynthAnimDesc>*>(m_ptr, "CSequenceGroupData", "m_localSynthAnimDescArray"); std::vector<GCSeqSynthAnimDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalSynthAnimDescArray(std::vector<GCSeqSynthAnimDesc> value) { SetSchemaValueCUtlVector<GCSeqSynthAnimDesc>(m_ptr, "CSequenceGroupData", "m_localSynthAnimDescArray", false, value); }
    std::vector<GCSeqCmdSeqDesc> GetLocalCmdSeqDescArray() const { CUtlVector<GCSeqCmdSeqDesc>* vec = GetSchemaValue<CUtlVector<GCSeqCmdSeqDesc>*>(m_ptr, "CSequenceGroupData", "m_localCmdSeqDescArray"); std::vector<GCSeqCmdSeqDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalCmdSeqDescArray(std::vector<GCSeqCmdSeqDesc> value) { SetSchemaValueCUtlVector<GCSeqCmdSeqDesc>(m_ptr, "CSequenceGroupData", "m_localCmdSeqDescArray", false, value); }
    std::vector<GCSeqBoneMaskList> GetLocalBoneMaskArray() const { CUtlVector<GCSeqBoneMaskList>* vec = GetSchemaValue<CUtlVector<GCSeqBoneMaskList>*>(m_ptr, "CSequenceGroupData", "m_localBoneMaskArray"); std::vector<GCSeqBoneMaskList> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalBoneMaskArray(std::vector<GCSeqBoneMaskList> value) { SetSchemaValueCUtlVector<GCSeqBoneMaskList>(m_ptr, "CSequenceGroupData", "m_localBoneMaskArray", false, value); }
    std::vector<GCSeqScaleSet> GetLocalScaleSetArray() const { CUtlVector<GCSeqScaleSet>* vec = GetSchemaValue<CUtlVector<GCSeqScaleSet>*>(m_ptr, "CSequenceGroupData", "m_localScaleSetArray"); std::vector<GCSeqScaleSet> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalScaleSetArray(std::vector<GCSeqScaleSet> value) { SetSchemaValueCUtlVector<GCSeqScaleSet>(m_ptr, "CSequenceGroupData", "m_localScaleSetArray", false, value); }
    std::vector<CBufferString> GetLocalBoneNameArray() const { CUtlVector<CBufferString>* vec = GetSchemaValue<CUtlVector<CBufferString>*>(m_ptr, "CSequenceGroupData", "m_localBoneNameArray"); std::vector<CBufferString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalBoneNameArray(std::vector<CBufferString> value) { SetSchemaValueCUtlVector<CBufferString>(m_ptr, "CSequenceGroupData", "m_localBoneNameArray", false, value); }
    CBufferString GetLocalNodeName() const { return GetSchemaValue<CBufferString>(m_ptr, "CSequenceGroupData", "m_localNodeName"); }
    void SetLocalNodeName(CBufferString value) { SetSchemaValue(m_ptr, "CSequenceGroupData", "m_localNodeName", false, value); }
    std::vector<GCSeqPoseParamDesc> GetLocalPoseParamArray() const { CUtlVector<GCSeqPoseParamDesc>* vec = GetSchemaValue<CUtlVector<GCSeqPoseParamDesc>*>(m_ptr, "CSequenceGroupData", "m_localPoseParamArray"); std::vector<GCSeqPoseParamDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalPoseParamArray(std::vector<GCSeqPoseParamDesc> value) { SetSchemaValueCUtlVector<GCSeqPoseParamDesc>(m_ptr, "CSequenceGroupData", "m_localPoseParamArray", false, value); }
    std::vector<GCSeqIKLock> GetLocalIKAutoplayLockArray() const { CUtlVector<GCSeqIKLock>* vec = GetSchemaValue<CUtlVector<GCSeqIKLock>*>(m_ptr, "CSequenceGroupData", "m_localIKAutoplayLockArray"); std::vector<GCSeqIKLock> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalIKAutoplayLockArray(std::vector<GCSeqIKLock> value) { SetSchemaValueCUtlVector<GCSeqIKLock>(m_ptr, "CSequenceGroupData", "m_localIKAutoplayLockArray", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif