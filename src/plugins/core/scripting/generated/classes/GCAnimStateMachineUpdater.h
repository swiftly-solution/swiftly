class GCAnimStateMachineUpdater;

#ifndef _gccanimstatemachineupdater_h
#define _gccanimstatemachineupdater_h

#include "../../../scripting.h"


#include "GCStateUpdateData.h"
#include "GCTransitionUpdateData.h"

class GCAnimStateMachineUpdater
{
private:
    void *m_ptr;

public:
    GCAnimStateMachineUpdater() {}
    GCAnimStateMachineUpdater(void *ptr) : m_ptr(ptr) {}

    std::vector<GCStateUpdateData> GetStates() const { CUtlVector<GCStateUpdateData>* vec = GetSchemaValue<CUtlVector<GCStateUpdateData>*>(m_ptr, "CAnimStateMachineUpdater", "m_states"); std::vector<GCStateUpdateData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetStates(std::vector<GCStateUpdateData> value) { SetSchemaValueCUtlVector<GCStateUpdateData>(m_ptr, "CAnimStateMachineUpdater", "m_states", false, value); }
    std::vector<GCTransitionUpdateData> GetTransitions() const { CUtlVector<GCTransitionUpdateData>* vec = GetSchemaValue<CUtlVector<GCTransitionUpdateData>*>(m_ptr, "CAnimStateMachineUpdater", "m_transitions"); std::vector<GCTransitionUpdateData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTransitions(std::vector<GCTransitionUpdateData> value) { SetSchemaValueCUtlVector<GCTransitionUpdateData>(m_ptr, "CAnimStateMachineUpdater", "m_transitions", false, value); }
    int32_t GetStartStateIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimStateMachineUpdater", "m_startStateIndex"); }
    void SetStartStateIndex(int32_t value) { SetSchemaValue(m_ptr, "CAnimStateMachineUpdater", "m_startStateIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif