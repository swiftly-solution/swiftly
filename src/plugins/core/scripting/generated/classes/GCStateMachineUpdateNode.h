class GCStateMachineUpdateNode;

#ifndef _gccstatemachineupdatenode_h
#define _gccstatemachineupdatenode_h

#include "../../../scripting.h"


#include "GCAnimStateMachineUpdater.h"
#include "GCStateNodeStateData.h"
#include "GCStateNodeTransitionData.h"

class GCStateMachineUpdateNode
{
private:
    void *m_ptr;

public:
    GCStateMachineUpdateNode() {}
    GCStateMachineUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCAnimStateMachineUpdater GetStateMachine() const { return GetSchemaValue<GCAnimStateMachineUpdater>(m_ptr, "CStateMachineUpdateNode", "m_stateMachine"); }
    void SetStateMachine(GCAnimStateMachineUpdater value) { SetSchemaValue(m_ptr, "CStateMachineUpdateNode", "m_stateMachine", false, value); }
    std::vector<GCStateNodeStateData> GetStateData() const { CUtlVector<GCStateNodeStateData>* vec = GetSchemaValue<CUtlVector<GCStateNodeStateData>*>(m_ptr, "CStateMachineUpdateNode", "m_stateData"); std::vector<GCStateNodeStateData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetStateData(std::vector<GCStateNodeStateData> value) { SetSchemaValueCUtlVector<GCStateNodeStateData>(m_ptr, "CStateMachineUpdateNode", "m_stateData", false, value); }
    std::vector<GCStateNodeTransitionData> GetTransitionData() const { CUtlVector<GCStateNodeTransitionData>* vec = GetSchemaValue<CUtlVector<GCStateNodeTransitionData>*>(m_ptr, "CStateMachineUpdateNode", "m_transitionData"); std::vector<GCStateNodeTransitionData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTransitionData(std::vector<GCStateNodeTransitionData> value) { SetSchemaValueCUtlVector<GCStateNodeTransitionData>(m_ptr, "CStateMachineUpdateNode", "m_transitionData", false, value); }
    bool GetBlockWaningTags() const { return GetSchemaValue<bool>(m_ptr, "CStateMachineUpdateNode", "m_bBlockWaningTags"); }
    void SetBlockWaningTags(bool value) { SetSchemaValue(m_ptr, "CStateMachineUpdateNode", "m_bBlockWaningTags", false, value); }
    bool GetLockStateWhenWaning() const { return GetSchemaValue<bool>(m_ptr, "CStateMachineUpdateNode", "m_bLockStateWhenWaning"); }
    void SetLockStateWhenWaning(bool value) { SetSchemaValue(m_ptr, "CStateMachineUpdateNode", "m_bLockStateWhenWaning", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif