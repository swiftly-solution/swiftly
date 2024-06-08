class GC_OP_InterpolateRadius;

#ifndef _gcc_op_interpolateradius_h
#define _gcc_op_interpolateradius_h

#include "../../../scripting.h"




class GC_OP_InterpolateRadius
{
private:
    void *m_ptr;

public:
    GC_OP_InterpolateRadius() {}
    GC_OP_InterpolateRadius(void *ptr) : m_ptr(ptr) {}

    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_InterpolateRadius", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_OP_InterpolateRadius", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_InterpolateRadius", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "C_OP_InterpolateRadius", "m_flEndTime", false, value); }
    float GetStartScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_InterpolateRadius", "m_flStartScale"); }
    void SetStartScale(float value) { SetSchemaValue(m_ptr, "C_OP_InterpolateRadius", "m_flStartScale", false, value); }
    float GetEndScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_InterpolateRadius", "m_flEndScale"); }
    void SetEndScale(float value) { SetSchemaValue(m_ptr, "C_OP_InterpolateRadius", "m_flEndScale", false, value); }
    bool GetEaseInAndOut() const { return GetSchemaValue<bool>(m_ptr, "C_OP_InterpolateRadius", "m_bEaseInAndOut"); }
    void SetEaseInAndOut(bool value) { SetSchemaValue(m_ptr, "C_OP_InterpolateRadius", "m_bEaseInAndOut", false, value); }
    float GetBias() const { return GetSchemaValue<float>(m_ptr, "C_OP_InterpolateRadius", "m_flBias"); }
    void SetBias(float value) { SetSchemaValue(m_ptr, "C_OP_InterpolateRadius", "m_flBias", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif