class GCNmChildGraphNode;

#ifndef _gccnmchildgraphnode_h
#define _gccnmchildgraphnode_h

#include "../../../scripting.h"




class GCNmChildGraphNode
{
private:
    void *m_ptr;

public:
    GCNmChildGraphNode() {}
    GCNmChildGraphNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetChildGraphIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmChildGraphNode", "m_nChildGraphIdx"); }
    void SetChildGraphIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmChildGraphNode", "m_nChildGraphIdx", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif