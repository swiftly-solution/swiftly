class GCNmBoolValueNode;

#ifndef _gccnmboolvaluenode_h
#define _gccnmboolvaluenode_h

#include "../../../scripting.h"




class GCNmBoolValueNode
{
private:
    void *m_ptr;

public:
    GCNmBoolValueNode() {}
    GCNmBoolValueNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif