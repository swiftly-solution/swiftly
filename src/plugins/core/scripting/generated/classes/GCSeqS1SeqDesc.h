class GCSeqS1SeqDesc;

#ifndef _gccseqs1seqdesc_h
#define _gccseqs1seqdesc_h

#include "../../../scripting.h"


#include "GCSeqSeqDescFlag.h"
#include "GCSeqMultiFetch.h"
#include "GCSeqAutoLayer.h"
#include "GCSeqIKLock.h"
#include "GCSeqTransition.h"
#include "GCAnimActivity.h"
#include "GCFootMotion.h"

class GCSeqS1SeqDesc
{
private:
    void *m_ptr;

public:
    GCSeqS1SeqDesc() {}
    GCSeqS1SeqDesc(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CSeqS1SeqDesc", "m_sName"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_sName", false, value); }
    GCSeqSeqDescFlag GetFlags() const { return GetSchemaValue<GCSeqSeqDescFlag>(m_ptr, "CSeqS1SeqDesc", "m_flags"); }
    void SetFlags(GCSeqSeqDescFlag value) { SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_flags", false, value); }
    GCSeqMultiFetch GetFetch() const { return GetSchemaValue<GCSeqMultiFetch>(m_ptr, "CSeqS1SeqDesc", "m_fetch"); }
    void SetFetch(GCSeqMultiFetch value) { SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_fetch", false, value); }
    int32_t GetLocalWeightlist() const { return GetSchemaValue<int32_t>(m_ptr, "CSeqS1SeqDesc", "m_nLocalWeightlist"); }
    void SetLocalWeightlist(int32_t value) { SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_nLocalWeightlist", false, value); }
    std::vector<GCSeqAutoLayer> GetAutoLayerArray() const { CUtlVector<GCSeqAutoLayer>* vec = GetSchemaValue<CUtlVector<GCSeqAutoLayer>*>(m_ptr, "CSeqS1SeqDesc", "m_autoLayerArray"); std::vector<GCSeqAutoLayer> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAutoLayerArray(std::vector<GCSeqAutoLayer> value) { SetSchemaValueCUtlVector<GCSeqAutoLayer>(m_ptr, "CSeqS1SeqDesc", "m_autoLayerArray", false, value); }
    std::vector<GCSeqIKLock> GetIKLockArray() const { CUtlVector<GCSeqIKLock>* vec = GetSchemaValue<CUtlVector<GCSeqIKLock>*>(m_ptr, "CSeqS1SeqDesc", "m_IKLockArray"); std::vector<GCSeqIKLock> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetIKLockArray(std::vector<GCSeqIKLock> value) { SetSchemaValueCUtlVector<GCSeqIKLock>(m_ptr, "CSeqS1SeqDesc", "m_IKLockArray", false, value); }
    GCSeqTransition GetTransition() const { return GetSchemaValue<GCSeqTransition>(m_ptr, "CSeqS1SeqDesc", "m_transition"); }
    void SetTransition(GCSeqTransition value) { SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_transition", false, value); }
    CBufferString GetLegacyKeyValueText() const { return GetSchemaValue<CBufferString>(m_ptr, "CSeqS1SeqDesc", "m_LegacyKeyValueText"); }
    void SetLegacyKeyValueText(CBufferString value) { SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_LegacyKeyValueText", false, value); }
    std::vector<GCAnimActivity> GetActivityArray() const { CUtlVector<GCAnimActivity>* vec = GetSchemaValue<CUtlVector<GCAnimActivity>*>(m_ptr, "CSeqS1SeqDesc", "m_activityArray"); std::vector<GCAnimActivity> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetActivityArray(std::vector<GCAnimActivity> value) { SetSchemaValueCUtlVector<GCAnimActivity>(m_ptr, "CSeqS1SeqDesc", "m_activityArray", false, value); }
    std::vector<GCFootMotion> GetFootMotion() const { CUtlVector<GCFootMotion>* vec = GetSchemaValue<CUtlVector<GCFootMotion>*>(m_ptr, "CSeqS1SeqDesc", "m_footMotion"); std::vector<GCFootMotion> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFootMotion(std::vector<GCFootMotion> value) { SetSchemaValueCUtlVector<GCFootMotion>(m_ptr, "CSeqS1SeqDesc", "m_footMotion", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif