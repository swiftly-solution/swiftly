class GCNmIDValueNode;

#ifndef _gccnmidvaluenode_h
#define _gccnmidvaluenode_h

#include "../../../scripting.h"




class GCNmIDValueNode
{
private:
    void *m_ptr;

public:
    GCNmIDValueNode() {}
    GCNmIDValueNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif