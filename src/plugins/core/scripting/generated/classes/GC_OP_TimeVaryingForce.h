class GC_OP_TimeVaryingForce;

#ifndef _gcc_op_timevaryingforce_h
#define _gcc_op_timevaryingforce_h

#include "../../../scripting.h"




class GC_OP_TimeVaryingForce
{
private:
    void *m_ptr;

public:
    GC_OP_TimeVaryingForce() {}
    GC_OP_TimeVaryingForce(void *ptr) : m_ptr(ptr) {}

    float GetStartLerpTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_TimeVaryingForce", "m_flStartLerpTime"); }
    void SetStartLerpTime(float value) { SetSchemaValue(m_ptr, "C_OP_TimeVaryingForce", "m_flStartLerpTime", false, value); }
    Vector GetStartingForce() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_TimeVaryingForce", "m_StartingForce"); }
    void SetStartingForce(Vector value) { SetSchemaValue(m_ptr, "C_OP_TimeVaryingForce", "m_StartingForce", false, value); }
    float GetEndLerpTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_TimeVaryingForce", "m_flEndLerpTime"); }
    void SetEndLerpTime(float value) { SetSchemaValue(m_ptr, "C_OP_TimeVaryingForce", "m_flEndLerpTime", false, value); }
    Vector GetEndingForce() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_TimeVaryingForce", "m_EndingForce"); }
    void SetEndingForce(Vector value) { SetSchemaValue(m_ptr, "C_OP_TimeVaryingForce", "m_EndingForce", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif