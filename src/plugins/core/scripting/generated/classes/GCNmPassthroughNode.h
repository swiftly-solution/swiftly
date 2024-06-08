class GCNmPassthroughNode;

#ifndef _gccnmpassthroughnode_h
#define _gccnmpassthroughnode_h

#include "../../../scripting.h"




class GCNmPassthroughNode
{
private:
    void *m_ptr;

public:
    GCNmPassthroughNode() {}
    GCNmPassthroughNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetChildNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmPassthroughNode", "m_nChildNodeIdx"); }
    void SetChildNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmPassthroughNode", "m_nChildNodeIdx", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif