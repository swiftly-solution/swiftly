class GCNmControlParameterVectorNode;

#ifndef _gccnmcontrolparametervectornode_h
#define _gccnmcontrolparametervectornode_h

#include "../../../scripting.h"




class GCNmControlParameterVectorNode
{
private:
    void *m_ptr;

public:
    GCNmControlParameterVectorNode() {}
    GCNmControlParameterVectorNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif