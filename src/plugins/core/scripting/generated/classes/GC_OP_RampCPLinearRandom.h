class GC_OP_RampCPLinearRandom;

#ifndef _gcc_op_rampcplinearrandom_h
#define _gcc_op_rampcplinearrandom_h

#include "../../../scripting.h"




class GC_OP_RampCPLinearRandom
{
private:
    void *m_ptr;

public:
    GC_OP_RampCPLinearRandom() {}
    GC_OP_RampCPLinearRandom(void *ptr) : m_ptr(ptr) {}

    int32_t GetOutControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RampCPLinearRandom", "m_nOutControlPointNumber"); }
    void SetOutControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RampCPLinearRandom", "m_nOutControlPointNumber", false, value); }
    Vector GetRateMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RampCPLinearRandom", "m_vecRateMin"); }
    void SetRateMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_RampCPLinearRandom", "m_vecRateMin", false, value); }
    Vector GetRateMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RampCPLinearRandom", "m_vecRateMax"); }
    void SetRateMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_RampCPLinearRandom", "m_vecRateMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif