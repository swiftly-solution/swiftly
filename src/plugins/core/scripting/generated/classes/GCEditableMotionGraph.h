class GCEditableMotionGraph;

#ifndef _gcceditablemotiongraph_h
#define _gcceditablemotiongraph_h

#include "../../../scripting.h"




class GCEditableMotionGraph
{
private:
    void *m_ptr;

public:
    GCEditableMotionGraph() {}
    GCEditableMotionGraph(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif