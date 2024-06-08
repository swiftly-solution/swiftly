class GCStateUpdateData;

#ifndef _gccstateupdatedata_h
#define _gccstateupdatedata_h

#include "../../../scripting.h"


#include "GAnimScriptHandle.h"
#include "GCStateActionUpdater.h"
#include "GAnimStateID.h"

class GCStateUpdateData
{
private:
    void *m_ptr;

public:
    GCStateUpdateData() {}
    GCStateUpdateData(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CStateUpdateData", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CStateUpdateData", "m_name", false, value); }
    GAnimScriptHandle GetScript() const { return GetSchemaValue<GAnimScriptHandle>(m_ptr, "CStateUpdateData", "m_hScript"); }
    void SetScript(GAnimScriptHandle value) { SetSchemaValue(m_ptr, "CStateUpdateData", "m_hScript", false, value); }
    std::vector<int32> GetTransitionIndices() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CStateUpdateData", "m_transitionIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTransitionIndices(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CStateUpdateData", "m_transitionIndices", false, value); }
    std::vector<GCStateActionUpdater> GetActions() const { CUtlVector<GCStateActionUpdater>* vec = GetSchemaValue<CUtlVector<GCStateActionUpdater>*>(m_ptr, "CStateUpdateData", "m_actions"); std::vector<GCStateActionUpdater> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetActions(std::vector<GCStateActionUpdater> value) { SetSchemaValueCUtlVector<GCStateActionUpdater>(m_ptr, "CStateUpdateData", "m_actions", false, value); }
    GAnimStateID GetStateID() const { return GetSchemaValue<GAnimStateID>(m_ptr, "CStateUpdateData", "m_stateID"); }
    void SetStateID(GAnimStateID value) { SetSchemaValue(m_ptr, "CStateUpdateData", "m_stateID", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif