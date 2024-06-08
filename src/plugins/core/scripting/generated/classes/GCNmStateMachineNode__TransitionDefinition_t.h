class GCNmStateMachineNode__TransitionDefinition_t;

#ifndef _gccnmstatemachinenode__transitiondefinition_t_h
#define _gccnmstatemachinenode__transitiondefinition_t_h

#include "../../../scripting.h"




class GCNmStateMachineNode__TransitionDefinition_t
{
private:
    void *m_ptr;

public:
    GCNmStateMachineNode__TransitionDefinition_t() {}
    GCNmStateMachineNode__TransitionDefinition_t(void *ptr) : m_ptr(ptr) {}

    int16_t GetTargetStateIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nTargetStateIdx"); }
    void SetTargetStateIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nTargetStateIdx", true, value); }
    int16_t GetConditionNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nConditionNodeIdx"); }
    void SetConditionNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nConditionNodeIdx", true, value); }
    int16_t GetTransitionNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nTransitionNodeIdx"); }
    void SetTransitionNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nTransitionNodeIdx", true, value); }
    bool GetCanBeForced() const { return GetSchemaValue<bool>(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_bCanBeForced"); }
    void SetCanBeForced(bool value) { SetSchemaValue(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_bCanBeForced", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif