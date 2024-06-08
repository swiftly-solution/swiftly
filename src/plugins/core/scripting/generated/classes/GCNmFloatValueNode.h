class GCNmFloatValueNode;

#ifndef _gccnmfloatvaluenode_h
#define _gccnmfloatvaluenode_h

#include "../../../scripting.h"




class GCNmFloatValueNode
{
private:
    void *m_ptr;

public:
    GCNmFloatValueNode() {}
    GCNmFloatValueNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif