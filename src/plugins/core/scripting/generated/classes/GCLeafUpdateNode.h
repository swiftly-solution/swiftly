class GCLeafUpdateNode;

#ifndef _gccleafupdatenode_h
#define _gccleafupdatenode_h

#include "../../../scripting.h"




class GCLeafUpdateNode
{
private:
    void *m_ptr;

public:
    GCLeafUpdateNode() {}
    GCLeafUpdateNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif