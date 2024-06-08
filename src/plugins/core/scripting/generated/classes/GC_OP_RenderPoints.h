class GC_OP_RenderPoints;

#ifndef _gcc_op_renderpoints_h
#define _gcc_op_renderpoints_h

#include "../../../scripting.h"




class GC_OP_RenderPoints
{
private:
    void *m_ptr;

public:
    GC_OP_RenderPoints() {}
    GC_OP_RenderPoints(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif