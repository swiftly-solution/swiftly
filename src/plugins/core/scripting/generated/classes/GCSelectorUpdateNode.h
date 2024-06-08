class GCSelectorUpdateNode;

#ifndef _gccselectorupdatenode_h
#define _gccselectorupdatenode_h

#include "../../../scripting.h"

#include "../types/GSelectorTagBehavior_t.h"
#include "GCAnimUpdateNodeRef.h"
#include "GCBlendCurve.h"
#include "GCAnimParamHandle.h"

class GCSelectorUpdateNode
{
private:
    void *m_ptr;

public:
    GCSelectorUpdateNode() {}
    GCSelectorUpdateNode(void *ptr) : m_ptr(ptr) {}

    std::vector<GCAnimUpdateNodeRef> GetChildren() const { CUtlVector<GCAnimUpdateNodeRef>* vec = GetSchemaValue<CUtlVector<GCAnimUpdateNodeRef>*>(m_ptr, "CSelectorUpdateNode", "m_children"); std::vector<GCAnimUpdateNodeRef> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetChildren(std::vector<GCAnimUpdateNodeRef> value) { SetSchemaValueCUtlVector<GCAnimUpdateNodeRef>(m_ptr, "CSelectorUpdateNode", "m_children", false, value); }
    std::vector<int8> GetTags() const { CUtlVector<int8>* vec = GetSchemaValue<CUtlVector<int8>*>(m_ptr, "CSelectorUpdateNode", "m_tags"); std::vector<int8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTags(std::vector<int8> value) { SetSchemaValueCUtlVector<int8>(m_ptr, "CSelectorUpdateNode", "m_tags", false, value); }
    GCBlendCurve GetBlendCurve() const { return GetSchemaValue<GCBlendCurve>(m_ptr, "CSelectorUpdateNode", "m_blendCurve"); }
    void SetBlendCurve(GCBlendCurve value) { SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_blendCurve", false, value); }
    GCAnimParamHandle GetParameter() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CSelectorUpdateNode", "m_hParameter"); }
    void SetParameter(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_hParameter", false, value); }
    int32_t GetTagIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CSelectorUpdateNode", "m_nTagIndex"); }
    void SetTagIndex(int32_t value) { SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_nTagIndex", false, value); }
    SelectorTagBehavior_t GetTagBehavior() const { return GetSchemaValue<SelectorTagBehavior_t>(m_ptr, "CSelectorUpdateNode", "m_eTagBehavior"); }
    void SetTagBehavior(SelectorTagBehavior_t value) { SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_eTagBehavior", false, value); }
    bool GetResetOnChange() const { return GetSchemaValue<bool>(m_ptr, "CSelectorUpdateNode", "m_bResetOnChange"); }
    void SetResetOnChange(bool value) { SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_bResetOnChange", false, value); }
    bool GetLockWhenWaning() const { return GetSchemaValue<bool>(m_ptr, "CSelectorUpdateNode", "m_bLockWhenWaning"); }
    void SetLockWhenWaning(bool value) { SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_bLockWhenWaning", false, value); }
    bool GetSyncCyclesOnChange() const { return GetSchemaValue<bool>(m_ptr, "CSelectorUpdateNode", "m_bSyncCyclesOnChange"); }
    void SetSyncCyclesOnChange(bool value) { SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_bSyncCyclesOnChange", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif