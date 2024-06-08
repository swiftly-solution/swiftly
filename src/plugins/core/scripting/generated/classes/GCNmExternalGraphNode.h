class GCNmExternalGraphNode;

#ifndef _gccnmexternalgraphnode_h
#define _gccnmexternalgraphnode_h

#include "../../../scripting.h"




class GCNmExternalGraphNode
{
private:
    void *m_ptr;

public:
    GCNmExternalGraphNode() {}
    GCNmExternalGraphNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif