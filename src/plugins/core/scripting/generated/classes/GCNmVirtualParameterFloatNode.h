class GCNmVirtualParameterFloatNode;

#ifndef _gccnmvirtualparameterfloatnode_h
#define _gccnmvirtualparameterfloatnode_h

#include "../../../scripting.h"




class GCNmVirtualParameterFloatNode
{
private:
    void *m_ptr;

public:
    GCNmVirtualParameterFloatNode() {}
    GCNmVirtualParameterFloatNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetChildNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterFloatNode", "m_nChildNodeIdx"); }
    void SetChildNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmVirtualParameterFloatNode", "m_nChildNodeIdx", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif