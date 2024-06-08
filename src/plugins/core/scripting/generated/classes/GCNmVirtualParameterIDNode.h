class GCNmVirtualParameterIDNode;

#ifndef _gccnmvirtualparameteridnode_h
#define _gccnmvirtualparameteridnode_h

#include "../../../scripting.h"




class GCNmVirtualParameterIDNode
{
private:
    void *m_ptr;

public:
    GCNmVirtualParameterIDNode() {}
    GCNmVirtualParameterIDNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetChildNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterIDNode", "m_nChildNodeIdx"); }
    void SetChildNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmVirtualParameterIDNode", "m_nChildNodeIdx", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif