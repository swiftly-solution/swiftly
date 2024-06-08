class GCBtNode;

#ifndef _gccbtnode_h
#define _gccbtnode_h

#include "../../../scripting.h"




class GCBtNode
{
private:
    void *m_ptr;

public:
    GCBtNode() {}
    GCBtNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif