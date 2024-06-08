class GCNmVirtualParameterBoolNode;

#ifndef _gccnmvirtualparameterboolnode_h
#define _gccnmvirtualparameterboolnode_h

#include "../../../scripting.h"




class GCNmVirtualParameterBoolNode
{
private:
    void *m_ptr;

public:
    GCNmVirtualParameterBoolNode() {}
    GCNmVirtualParameterBoolNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetChildNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterBoolNode", "m_nChildNodeIdx"); }
    void SetChildNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmVirtualParameterBoolNode", "m_nChildNodeIdx", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif