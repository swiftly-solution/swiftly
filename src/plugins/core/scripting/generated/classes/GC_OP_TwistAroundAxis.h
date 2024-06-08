class GC_OP_TwistAroundAxis;

#ifndef _gcc_op_twistaroundaxis_h
#define _gcc_op_twistaroundaxis_h

#include "../../../scripting.h"




class GC_OP_TwistAroundAxis
{
private:
    void *m_ptr;

public:
    GC_OP_TwistAroundAxis() {}
    GC_OP_TwistAroundAxis(void *ptr) : m_ptr(ptr) {}

    float GetForceAmount() const { return GetSchemaValue<float>(m_ptr, "C_OP_TwistAroundAxis", "m_fForceAmount"); }
    void SetForceAmount(float value) { SetSchemaValue(m_ptr, "C_OP_TwistAroundAxis", "m_fForceAmount", false, value); }
    Vector GetTwistAxis() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_TwistAroundAxis", "m_TwistAxis"); }
    void SetTwistAxis(Vector value) { SetSchemaValue(m_ptr, "C_OP_TwistAroundAxis", "m_TwistAxis", false, value); }
    bool GetLocalSpace() const { return GetSchemaValue<bool>(m_ptr, "C_OP_TwistAroundAxis", "m_bLocalSpace"); }
    void SetLocalSpace(bool value) { SetSchemaValue(m_ptr, "C_OP_TwistAroundAxis", "m_bLocalSpace", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_TwistAroundAxis", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_TwistAroundAxis", "m_nControlPointNumber", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif