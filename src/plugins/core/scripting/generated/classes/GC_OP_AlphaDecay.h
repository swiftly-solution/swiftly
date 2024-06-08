class GC_OP_AlphaDecay;

#ifndef _gcc_op_alphadecay_h
#define _gcc_op_alphadecay_h

#include "../../../scripting.h"




class GC_OP_AlphaDecay
{
private:
    void *m_ptr;

public:
    GC_OP_AlphaDecay() {}
    GC_OP_AlphaDecay(void *ptr) : m_ptr(ptr) {}

    float GetMinAlpha() const { return GetSchemaValue<float>(m_ptr, "C_OP_AlphaDecay", "m_flMinAlpha"); }
    void SetMinAlpha(float value) { SetSchemaValue(m_ptr, "C_OP_AlphaDecay", "m_flMinAlpha", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif