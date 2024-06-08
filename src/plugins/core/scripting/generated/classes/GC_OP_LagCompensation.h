class GC_OP_LagCompensation;

#ifndef _gcc_op_lagcompensation_h
#define _gcc_op_lagcompensation_h

#include "../../../scripting.h"




class GC_OP_LagCompensation
{
private:
    void *m_ptr;

public:
    GC_OP_LagCompensation() {}
    GC_OP_LagCompensation(void *ptr) : m_ptr(ptr) {}

    int32_t GetDesiredVelocityCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LagCompensation", "m_nDesiredVelocityCP"); }
    void SetDesiredVelocityCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LagCompensation", "m_nDesiredVelocityCP", false, value); }
    int32_t GetLatencyCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LagCompensation", "m_nLatencyCP"); }
    void SetLatencyCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LagCompensation", "m_nLatencyCP", false, value); }
    int32_t GetLatencyCPField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LagCompensation", "m_nLatencyCPField"); }
    void SetLatencyCPField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LagCompensation", "m_nLatencyCPField", false, value); }
    int32_t GetDesiredVelocityCPField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LagCompensation", "m_nDesiredVelocityCPField"); }
    void SetDesiredVelocityCPField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LagCompensation", "m_nDesiredVelocityCPField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif