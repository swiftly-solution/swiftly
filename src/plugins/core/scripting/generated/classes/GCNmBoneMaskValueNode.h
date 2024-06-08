class GCNmBoneMaskValueNode;

#ifndef _gccnmbonemaskvaluenode_h
#define _gccnmbonemaskvaluenode_h

#include "../../../scripting.h"




class GCNmBoneMaskValueNode
{
private:
    void *m_ptr;

public:
    GCNmBoneMaskValueNode() {}
    GCNmBoneMaskValueNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif