class GC_OP_VelocityMatchingForce;

#ifndef _gcc_op_velocitymatchingforce_h
#define _gcc_op_velocitymatchingforce_h

#include "../../../scripting.h"




class GC_OP_VelocityMatchingForce
{
private:
    void *m_ptr;

public:
    GC_OP_VelocityMatchingForce() {}
    GC_OP_VelocityMatchingForce(void *ptr) : m_ptr(ptr) {}

    float GetDirScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_VelocityMatchingForce", "m_flDirScale"); }
    void SetDirScale(float value) { SetSchemaValue(m_ptr, "C_OP_VelocityMatchingForce", "m_flDirScale", false, value); }
    float GetSpdScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_VelocityMatchingForce", "m_flSpdScale"); }
    void SetSpdScale(float value) { SetSchemaValue(m_ptr, "C_OP_VelocityMatchingForce", "m_flSpdScale", false, value); }
    int32_t GetCPBroadcast() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_VelocityMatchingForce", "m_nCPBroadcast"); }
    void SetCPBroadcast(int32_t value) { SetSchemaValue(m_ptr, "C_OP_VelocityMatchingForce", "m_nCPBroadcast", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif