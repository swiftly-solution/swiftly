class GCLogicBranchList;

#ifndef _gcclogicbranchlist_h
#define _gcclogicbranchlist_h

#include "../../../scripting.h"


#include "GCLogicBranchList.h"
#include "GCLogicBranch.h"
#include "GCEntityIOOutput.h"

class GCLogicBranchList
{
private:
    void *m_ptr;

public:
    GCLogicBranchList() {}
    GCLogicBranchList(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlSymbolLarge> GetLogicBranchNames() const { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CLogicBranchList", "m_nLogicBranchNames"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 16; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetLogicBranchNames(std::vector<CUtlSymbolLarge> value) { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CLogicBranchList", "m_nLogicBranchNames"); for(int i = 0; i < 16; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CLogicBranchList", "m_nLogicBranchNames", false, outValue); }
    GCLogicBranchList GetLastState() const { return GetSchemaValue<GCLogicBranchList>(m_ptr, "CLogicBranchList", "m_eLastState"); }
    void SetLastState(GCLogicBranchList value) { SetSchemaValue(m_ptr, "CLogicBranchList", "m_eLastState", false, value); }
    GCEntityIOOutput GetOnAllTrue() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicBranchList", "m_OnAllTrue"); }
    void SetOnAllTrue(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicBranchList", "m_OnAllTrue", false, value); }
    GCEntityIOOutput GetOnAllFalse() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicBranchList", "m_OnAllFalse"); }
    void SetOnAllFalse(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicBranchList", "m_OnAllFalse", false, value); }
    GCEntityIOOutput GetOnMixed() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicBranchList", "m_OnMixed"); }
    void SetOnMixed(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicBranchList", "m_OnMixed", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif