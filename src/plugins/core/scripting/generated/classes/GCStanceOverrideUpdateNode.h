class GCStanceOverrideUpdateNode;

#ifndef _gccstanceoverrideupdatenode_h
#define _gccstanceoverrideupdatenode_h

#include "../../../scripting.h"

#include "../types/GStanceOverrideMode.h"
#include "GStanceInfo_t.h"
#include "GCAnimUpdateNodeRef.h"
#include "GCAnimParamHandle.h"

class GCStanceOverrideUpdateNode
{
private:
    void *m_ptr;

public:
    GCStanceOverrideUpdateNode() {}
    GCStanceOverrideUpdateNode(void *ptr) : m_ptr(ptr) {}

    std::vector<GStanceInfo_t> GetFootStanceInfo() const { CUtlVector<GStanceInfo_t>* vec = GetSchemaValue<CUtlVector<GStanceInfo_t>*>(m_ptr, "CStanceOverrideUpdateNode", "m_footStanceInfo"); std::vector<GStanceInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFootStanceInfo(std::vector<GStanceInfo_t> value) { SetSchemaValueCUtlVector<GStanceInfo_t>(m_ptr, "CStanceOverrideUpdateNode", "m_footStanceInfo", false, value); }
    GCAnimUpdateNodeRef GetStanceSourceNode() const { return GetSchemaValue<GCAnimUpdateNodeRef>(m_ptr, "CStanceOverrideUpdateNode", "m_pStanceSourceNode"); }
    void SetStanceSourceNode(GCAnimUpdateNodeRef value) { SetSchemaValue(m_ptr, "CStanceOverrideUpdateNode", "m_pStanceSourceNode", false, value); }
    GCAnimParamHandle GetParameter() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CStanceOverrideUpdateNode", "m_hParameter"); }
    void SetParameter(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CStanceOverrideUpdateNode", "m_hParameter", false, value); }
    StanceOverrideMode GetMode() const { return GetSchemaValue<StanceOverrideMode>(m_ptr, "CStanceOverrideUpdateNode", "m_eMode"); }
    void SetMode(StanceOverrideMode value) { SetSchemaValue(m_ptr, "CStanceOverrideUpdateNode", "m_eMode", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif