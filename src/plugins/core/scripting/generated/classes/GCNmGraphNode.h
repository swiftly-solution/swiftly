class GCNmGraphNode;

#ifndef _gccnmgraphnode_h
#define _gccnmgraphnode_h

#include "../../../scripting.h"




class GCNmGraphNode
{
private:
    void *m_ptr;

public:
    GCNmGraphNode() {}
    GCNmGraphNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmGraphNode", "m_nNodeIdx"); }
    void SetNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmGraphNode", "m_nNodeIdx", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif