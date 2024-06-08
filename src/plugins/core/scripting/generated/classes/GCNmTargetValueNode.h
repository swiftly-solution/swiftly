class GCNmTargetValueNode;

#ifndef _gccnmtargetvaluenode_h
#define _gccnmtargetvaluenode_h

#include "../../../scripting.h"




class GCNmTargetValueNode
{
private:
    void *m_ptr;

public:
    GCNmTargetValueNode() {}
    GCNmTargetValueNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif