class GCNmControlParameterIDNode;

#ifndef _gccnmcontrolparameteridnode_h
#define _gccnmcontrolparameteridnode_h

#include "../../../scripting.h"




class GCNmControlParameterIDNode
{
private:
    void *m_ptr;

public:
    GCNmControlParameterIDNode() {}
    GCNmControlParameterIDNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif