class GCMotionGraphUpdateNode;

#ifndef _gccmotiongraphupdatenode_h
#define _gccmotiongraphupdatenode_h

#include "../../../scripting.h"




class GCMotionGraphUpdateNode
{
private:
    void *m_ptr;

public:
    GCMotionGraphUpdateNode() {}
    GCMotionGraphUpdateNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif