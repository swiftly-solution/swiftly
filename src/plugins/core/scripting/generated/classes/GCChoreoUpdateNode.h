class GCChoreoUpdateNode;

#ifndef _gccchoreoupdatenode_h
#define _gccchoreoupdatenode_h

#include "../../../scripting.h"




class GCChoreoUpdateNode
{
private:
    void *m_ptr;

public:
    GCChoreoUpdateNode() {}
    GCChoreoUpdateNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif