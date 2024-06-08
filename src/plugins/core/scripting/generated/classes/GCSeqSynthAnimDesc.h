class GCSeqSynthAnimDesc;

#ifndef _gccseqsynthanimdesc_h
#define _gccseqsynthanimdesc_h

#include "../../../scripting.h"


#include "GCSeqSeqDescFlag.h"
#include "GCSeqTransition.h"
#include "GCAnimActivity.h"

class GCSeqSynthAnimDesc
{
private:
    void *m_ptr;

public:
    GCSeqSynthAnimDesc() {}
    GCSeqSynthAnimDesc(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CSeqSynthAnimDesc", "m_sName"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CSeqSynthAnimDesc", "m_sName", false, value); }
    GCSeqSeqDescFlag GetFlags() const { return GetSchemaValue<GCSeqSeqDescFlag>(m_ptr, "CSeqSynthAnimDesc", "m_flags"); }
    void SetFlags(GCSeqSeqDescFlag value) { SetSchemaValue(m_ptr, "CSeqSynthAnimDesc", "m_flags", false, value); }
    GCSeqTransition GetTransition() const { return GetSchemaValue<GCSeqTransition>(m_ptr, "CSeqSynthAnimDesc", "m_transition"); }
    void SetTransition(GCSeqTransition value) { SetSchemaValue(m_ptr, "CSeqSynthAnimDesc", "m_transition", false, value); }
    int16_t GetLocalBaseReference() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqSynthAnimDesc", "m_nLocalBaseReference"); }
    void SetLocalBaseReference(int16_t value) { SetSchemaValue(m_ptr, "CSeqSynthAnimDesc", "m_nLocalBaseReference", false, value); }
    int16_t GetLocalBoneMask() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqSynthAnimDesc", "m_nLocalBoneMask"); }
    void SetLocalBoneMask(int16_t value) { SetSchemaValue(m_ptr, "CSeqSynthAnimDesc", "m_nLocalBoneMask", false, value); }
    std::vector<GCAnimActivity> GetActivityArray() const { CUtlVector<GCAnimActivity>* vec = GetSchemaValue<CUtlVector<GCAnimActivity>*>(m_ptr, "CSeqSynthAnimDesc", "m_activityArray"); std::vector<GCAnimActivity> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetActivityArray(std::vector<GCAnimActivity> value) { SetSchemaValueCUtlVector<GCAnimActivity>(m_ptr, "CSeqSynthAnimDesc", "m_activityArray", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif