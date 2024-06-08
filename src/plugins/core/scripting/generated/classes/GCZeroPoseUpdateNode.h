class GCZeroPoseUpdateNode;

#ifndef _gcczeroposeupdatenode_h
#define _gcczeroposeupdatenode_h

#include "../../../scripting.h"




class GCZeroPoseUpdateNode
{
private:
    void *m_ptr;

public:
    GCZeroPoseUpdateNode() {}
    GCZeroPoseUpdateNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif