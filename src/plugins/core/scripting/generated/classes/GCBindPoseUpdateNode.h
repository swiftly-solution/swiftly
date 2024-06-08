class GCBindPoseUpdateNode;

#ifndef _gccbindposeupdatenode_h
#define _gccbindposeupdatenode_h

#include "../../../scripting.h"




class GCBindPoseUpdateNode
{
private:
    void *m_ptr;

public:
    GCBindPoseUpdateNode() {}
    GCBindPoseUpdateNode(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif