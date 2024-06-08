class GCInputStreamUpdateNode;

#ifndef _gccinputstreamupdatenode_h
#define _gccinputstreamupdatenode_h

#include "../../../scripting.h"




class GCInputStreamUpdateNode
{
private:
    void *m_ptr;

public:
    GCInputStreamUpdateNode() {}
    GCInputStreamUpdateNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif