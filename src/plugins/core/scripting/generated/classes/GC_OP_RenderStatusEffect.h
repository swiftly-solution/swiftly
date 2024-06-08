class GC_OP_RenderStatusEffect;

#ifndef _gcc_op_renderstatuseffect_h
#define _gcc_op_renderstatuseffect_h

#include "../../../scripting.h"




class GC_OP_RenderStatusEffect
{
private:
    void *m_ptr;

public:
    GC_OP_RenderStatusEffect() {}
    GC_OP_RenderStatusEffect(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif