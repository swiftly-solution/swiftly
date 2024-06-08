class GC_OP_RadiusDecay;

#ifndef _gcc_op_radiusdecay_h
#define _gcc_op_radiusdecay_h

#include "../../../scripting.h"




class GC_OP_RadiusDecay
{
private:
    void *m_ptr;

public:
    GC_OP_RadiusDecay() {}
    GC_OP_RadiusDecay(void *ptr) : m_ptr(ptr) {}

    float GetMinRadius() const { return GetSchemaValue<float>(m_ptr, "C_OP_RadiusDecay", "m_flMinRadius"); }
    void SetMinRadius(float value) { SetSchemaValue(m_ptr, "C_OP_RadiusDecay", "m_flMinRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif