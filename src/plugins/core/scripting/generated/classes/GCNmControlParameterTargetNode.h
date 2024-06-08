class GCNmControlParameterTargetNode;

#ifndef _gccnmcontrolparametertargetnode_h
#define _gccnmcontrolparametertargetnode_h

#include "../../../scripting.h"




class GCNmControlParameterTargetNode
{
private:
    void *m_ptr;

public:
    GCNmControlParameterTargetNode() {}
    GCNmControlParameterTargetNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif