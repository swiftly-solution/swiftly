class GCNmValueNode;

#ifndef _gccnmvaluenode_h
#define _gccnmvaluenode_h

#include "../../../scripting.h"




class GCNmValueNode
{
private:
    void *m_ptr;

public:
    GCNmValueNode() {}
    GCNmValueNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif