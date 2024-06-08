class GC_OP_MaxVelocity;

#ifndef _gcc_op_maxvelocity_h
#define _gcc_op_maxvelocity_h

#include "../../../scripting.h"




class GC_OP_MaxVelocity
{
private:
    void *m_ptr;

public:
    GC_OP_MaxVelocity() {}
    GC_OP_MaxVelocity(void *ptr) : m_ptr(ptr) {}

    float GetMaxVelocity() const { return GetSchemaValue<float>(m_ptr, "C_OP_MaxVelocity", "m_flMaxVelocity"); }
    void SetMaxVelocity(float value) { SetSchemaValue(m_ptr, "C_OP_MaxVelocity", "m_flMaxVelocity", false, value); }
    float GetMinVelocity() const { return GetSchemaValue<float>(m_ptr, "C_OP_MaxVelocity", "m_flMinVelocity"); }
    void SetMinVelocity(float value) { SetSchemaValue(m_ptr, "C_OP_MaxVelocity", "m_flMinVelocity", false, value); }
    int32_t GetOverrideCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MaxVelocity", "m_nOverrideCP"); }
    void SetOverrideCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MaxVelocity", "m_nOverrideCP", false, value); }
    int32_t GetOverrideCPField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MaxVelocity", "m_nOverrideCPField"); }
    void SetOverrideCPField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MaxVelocity", "m_nOverrideCPField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif