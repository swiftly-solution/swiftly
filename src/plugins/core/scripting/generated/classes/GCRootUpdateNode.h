class GCRootUpdateNode;

#ifndef _gccrootupdatenode_h
#define _gccrootupdatenode_h

#include "../../../scripting.h"




class GCRootUpdateNode
{
private:
    void *m_ptr;

public:
    GCRootUpdateNode() {}
    GCRootUpdateNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif