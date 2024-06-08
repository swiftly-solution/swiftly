class GC_OP_VelocityDecay;

#ifndef _gcc_op_velocitydecay_h
#define _gcc_op_velocitydecay_h

#include "../../../scripting.h"




class GC_OP_VelocityDecay
{
private:
    void *m_ptr;

public:
    GC_OP_VelocityDecay() {}
    GC_OP_VelocityDecay(void *ptr) : m_ptr(ptr) {}

    float GetMinVelocity() const { return GetSchemaValue<float>(m_ptr, "C_OP_VelocityDecay", "m_flMinVelocity"); }
    void SetMinVelocity(float value) { SetSchemaValue(m_ptr, "C_OP_VelocityDecay", "m_flMinVelocity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif