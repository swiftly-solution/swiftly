class GCNmPoseNode;

#ifndef _gccnmposenode_h
#define _gccnmposenode_h

#include "../../../scripting.h"




class GCNmPoseNode
{
private:
    void *m_ptr;

public:
    GCNmPoseNode() {}
    GCNmPoseNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif