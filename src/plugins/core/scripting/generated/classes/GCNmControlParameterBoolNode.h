class GCNmControlParameterBoolNode;

#ifndef _gccnmcontrolparameterboolnode_h
#define _gccnmcontrolparameterboolnode_h

#include "../../../scripting.h"




class GCNmControlParameterBoolNode
{
private:
    void *m_ptr;

public:
    GCNmControlParameterBoolNode() {}
    GCNmControlParameterBoolNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif