class GC_OP_DampenToCP;

#ifndef _gcc_op_dampentocp_h
#define _gcc_op_dampentocp_h

#include "../../../scripting.h"




class GC_OP_DampenToCP
{
private:
    void *m_ptr;

public:
    GC_OP_DampenToCP() {}
    GC_OP_DampenToCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_DampenToCP", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_DampenToCP", "m_nControlPointNumber", false, value); }
    float GetRange() const { return GetSchemaValue<float>(m_ptr, "C_OP_DampenToCP", "m_flRange"); }
    void SetRange(float value) { SetSchemaValue(m_ptr, "C_OP_DampenToCP", "m_flRange", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_DampenToCP", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_OP_DampenToCP", "m_flScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif