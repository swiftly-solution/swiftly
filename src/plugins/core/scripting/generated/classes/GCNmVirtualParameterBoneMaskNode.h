class GCNmVirtualParameterBoneMaskNode;

#ifndef _gccnmvirtualparameterbonemasknode_h
#define _gccnmvirtualparameterbonemasknode_h

#include "../../../scripting.h"




class GCNmVirtualParameterBoneMaskNode
{
private:
    void *m_ptr;

public:
    GCNmVirtualParameterBoneMaskNode() {}
    GCNmVirtualParameterBoneMaskNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetChildNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterBoneMaskNode", "m_nChildNodeIdx"); }
    void SetChildNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmVirtualParameterBoneMaskNode", "m_nChildNodeIdx", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif