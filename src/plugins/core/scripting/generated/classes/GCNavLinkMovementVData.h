class GCNavLinkMovementVData;

#ifndef _gccnavlinkmovementvdata_h
#define _gccnavlinkmovementvdata_h

#include "../../../scripting.h"


#include "GCNavLinkAnimgraphVar.h"

class GCNavLinkMovementVData
{
private:
    void *m_ptr;

public:
    GCNavLinkMovementVData() {}
    GCNavLinkMovementVData(void *ptr) : m_ptr(ptr) {}

    bool GetIsInterpolated() const { return GetSchemaValue<bool>(m_ptr, "CNavLinkMovementVData", "m_bIsInterpolated"); }
    void SetIsInterpolated(bool value) { SetSchemaValue(m_ptr, "CNavLinkMovementVData", "m_bIsInterpolated", false, value); }
    uint32_t GetRecommendedDistance() const { return GetSchemaValue<uint32_t>(m_ptr, "CNavLinkMovementVData", "m_unRecommendedDistance"); }
    void SetRecommendedDistance(uint32_t value) { SetSchemaValue(m_ptr, "CNavLinkMovementVData", "m_unRecommendedDistance", false, value); }
    std::vector<GCNavLinkAnimgraphVar> GetAnimgraphVars() const { CUtlVector<GCNavLinkAnimgraphVar>* vec = GetSchemaValue<CUtlVector<GCNavLinkAnimgraphVar>*>(m_ptr, "CNavLinkMovementVData", "m_vecAnimgraphVars"); std::vector<GCNavLinkAnimgraphVar> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAnimgraphVars(std::vector<GCNavLinkAnimgraphVar> value) { SetSchemaValueCUtlVector<GCNavLinkAnimgraphVar>(m_ptr, "CNavLinkMovementVData", "m_vecAnimgraphVars", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif