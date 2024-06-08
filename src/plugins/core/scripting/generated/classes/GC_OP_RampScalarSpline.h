class GC_OP_RampScalarSpline;

#ifndef _gcc_op_rampscalarspline_h
#define _gcc_op_rampscalarspline_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RampScalarSpline
{
private:
    void *m_ptr;

public:
    GC_OP_RampScalarSpline() {}
    GC_OP_RampScalarSpline(void *ptr) : m_ptr(ptr) {}

    float GetRateMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarSpline", "m_RateMin"); }
    void SetRateMin(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSpline", "m_RateMin", false, value); }
    float GetRateMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarSpline", "m_RateMax"); }
    void SetRateMax(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSpline", "m_RateMax", false, value); }
    float GetStartTime_min() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarSpline", "m_flStartTime_min"); }
    void SetStartTime_min(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSpline", "m_flStartTime_min", false, value); }
    float GetStartTime_max() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarSpline", "m_flStartTime_max"); }
    void SetStartTime_max(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSpline", "m_flStartTime_max", false, value); }
    float GetEndTime_min() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarSpline", "m_flEndTime_min"); }
    void SetEndTime_min(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSpline", "m_flEndTime_min", false, value); }
    float GetEndTime_max() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarSpline", "m_flEndTime_max"); }
    void SetEndTime_max(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSpline", "m_flEndTime_max", false, value); }
    float GetBias() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarSpline", "m_flBias"); }
    void SetBias(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSpline", "m_flBias", false, value); }
    GParticleAttributeIndex_t GetField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RampScalarSpline", "m_nField"); }
    void SetField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSpline", "m_nField", false, value); }
    bool GetProportionalOp() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RampScalarSpline", "m_bProportionalOp"); }
    void SetProportionalOp(bool value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSpline", "m_bProportionalOp", false, value); }
    bool GetEaseOut() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RampScalarSpline", "m_bEaseOut"); }
    void SetEaseOut(bool value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSpline", "m_bEaseOut", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif