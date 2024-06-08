class GCNmVirtualParameterVectorNode;

#ifndef _gccnmvirtualparametervectornode_h
#define _gccnmvirtualparametervectornode_h

#include "../../../scripting.h"




class GCNmVirtualParameterVectorNode
{
private:
    void *m_ptr;

public:
    GCNmVirtualParameterVectorNode() {}
    GCNmVirtualParameterVectorNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetChildNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterVectorNode", "m_nChildNodeIdx"); }
    void SetChildNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmVirtualParameterVectorNode", "m_nChildNodeIdx", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif