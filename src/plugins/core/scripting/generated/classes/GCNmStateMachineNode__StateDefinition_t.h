class GCNmStateMachineNode__StateDefinition_t;

#ifndef _gccnmstatemachinenode__statedefinition_t_h
#define _gccnmstatemachinenode__statedefinition_t_h

#include "../../../scripting.h"




class GCNmStateMachineNode__StateDefinition_t
{
private:
    void *m_ptr;

public:
    GCNmStateMachineNode__StateDefinition_t() {}
    GCNmStateMachineNode__StateDefinition_t(void *ptr) : m_ptr(ptr) {}

    int16_t GetStateNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode__StateDefinition_t", "m_nStateNodeIdx"); }
    void SetStateNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmStateMachineNode__StateDefinition_t", "m_nStateNodeIdx", true, value); }
    int16_t GetEntryConditionNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode__StateDefinition_t", "m_entryConditionNodeIdx"); }
    void SetEntryConditionNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmStateMachineNode__StateDefinition_t", "m_entryConditionNodeIdx", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif