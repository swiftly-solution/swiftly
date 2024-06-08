class GCNmStateMachineNode;

#ifndef _gccnmstatemachinenode_h
#define _gccnmstatemachinenode_h

#include "../../../scripting.h"




class GCNmStateMachineNode
{
private:
    void *m_ptr;

public:
    GCNmStateMachineNode() {}
    GCNmStateMachineNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetDefaultStateIndex() const { return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode", "m_nDefaultStateIndex"); }
    void SetDefaultStateIndex(int16_t value) { SetSchemaValue(m_ptr, "CNmStateMachineNode", "m_nDefaultStateIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif