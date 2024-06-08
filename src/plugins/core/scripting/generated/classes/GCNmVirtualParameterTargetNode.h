class GCNmVirtualParameterTargetNode;

#ifndef _gccnmvirtualparametertargetnode_h
#define _gccnmvirtualparametertargetnode_h

#include "../../../scripting.h"




class GCNmVirtualParameterTargetNode
{
private:
    void *m_ptr;

public:
    GCNmVirtualParameterTargetNode() {}
    GCNmVirtualParameterTargetNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetChildNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterTargetNode", "m_nChildNodeIdx"); }
    void SetChildNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmVirtualParameterTargetNode", "m_nChildNodeIdx", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif