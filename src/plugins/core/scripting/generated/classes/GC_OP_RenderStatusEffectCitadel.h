class GC_OP_RenderStatusEffectCitadel;

#ifndef _gcc_op_renderstatuseffectcitadel_h
#define _gcc_op_renderstatuseffectcitadel_h

#include "../../../scripting.h"




class GC_OP_RenderStatusEffectCitadel
{
private:
    void *m_ptr;

public:
    GC_OP_RenderStatusEffectCitadel() {}
    GC_OP_RenderStatusEffectCitadel(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif