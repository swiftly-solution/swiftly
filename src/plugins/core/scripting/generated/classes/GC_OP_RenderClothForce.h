class GC_OP_RenderClothForce;

#ifndef _gcc_op_renderclothforce_h
#define _gcc_op_renderclothforce_h

#include "../../../scripting.h"




class GC_OP_RenderClothForce
{
private:
    void *m_ptr;

public:
    GC_OP_RenderClothForce() {}
    GC_OP_RenderClothForce(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif