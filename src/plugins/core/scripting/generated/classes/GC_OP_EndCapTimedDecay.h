class GC_OP_EndCapTimedDecay;

#ifndef _gcc_op_endcaptimeddecay_h
#define _gcc_op_endcaptimeddecay_h

#include "../../../scripting.h"




class GC_OP_EndCapTimedDecay
{
private:
    void *m_ptr;

public:
    GC_OP_EndCapTimedDecay() {}
    GC_OP_EndCapTimedDecay(void *ptr) : m_ptr(ptr) {}

    float GetDecayTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_EndCapTimedDecay", "m_flDecayTime"); }
    void SetDecayTime(float value) { SetSchemaValue(m_ptr, "C_OP_EndCapTimedDecay", "m_flDecayTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif