class GC_INIT_InheritVelocity;

#ifndef _gcc_init_inheritvelocity_h
#define _gcc_init_inheritvelocity_h

#include "../../../scripting.h"




class GC_INIT_InheritVelocity
{
private:
    void *m_ptr;

public:
    GC_INIT_InheritVelocity() {}
    GC_INIT_InheritVelocity(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InheritVelocity", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InheritVelocity", "m_nControlPointNumber", false, value); }
    float GetVelocityScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InheritVelocity", "m_flVelocityScale"); }
    void SetVelocityScale(float value) { SetSchemaValue(m_ptr, "C_INIT_InheritVelocity", "m_flVelocityScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif