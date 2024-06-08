class GCNmControlParameterFloatNode;

#ifndef _gccnmcontrolparameterfloatnode_h
#define _gccnmcontrolparameterfloatnode_h

#include "../../../scripting.h"




class GCNmControlParameterFloatNode
{
private:
    void *m_ptr;

public:
    GCNmControlParameterFloatNode() {}
    GCNmControlParameterFloatNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif