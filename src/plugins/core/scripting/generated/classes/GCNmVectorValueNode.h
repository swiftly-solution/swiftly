class GCNmVectorValueNode;

#ifndef _gccnmvectorvaluenode_h
#define _gccnmvectorvaluenode_h

#include "../../../scripting.h"




class GCNmVectorValueNode
{
private:
    void *m_ptr;

public:
    GCNmVectorValueNode() {}
    GCNmVectorValueNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif