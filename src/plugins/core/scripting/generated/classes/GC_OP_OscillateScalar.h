class GC_OP_OscillateScalar;

#ifndef _gcc_op_oscillatescalar_h
#define _gcc_op_oscillatescalar_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_OscillateScalar
{
private:
    void *m_ptr;

public:
    GC_OP_OscillateScalar() {}
    GC_OP_OscillateScalar(void *ptr) : m_ptr(ptr) {}

    float GetRateMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalar", "m_RateMin"); }
    void SetRateMin(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_RateMin", false, value); }
    float GetRateMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalar", "m_RateMax"); }
    void SetRateMax(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_RateMax", false, value); }
    float GetFrequencyMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalar", "m_FrequencyMin"); }
    void SetFrequencyMin(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_FrequencyMin", false, value); }
    float GetFrequencyMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalar", "m_FrequencyMax"); }
    void SetFrequencyMax(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_FrequencyMax", false, value); }
    GParticleAttributeIndex_t GetField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_OscillateScalar", "m_nField"); }
    void SetField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_nField", false, value); }
    bool GetProportional() const { return GetSchemaValue<bool>(m_ptr, "C_OP_OscillateScalar", "m_bProportional"); }
    void SetProportional(bool value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_bProportional", false, value); }
    bool GetProportionalOp() const { return GetSchemaValue<bool>(m_ptr, "C_OP_OscillateScalar", "m_bProportionalOp"); }
    void SetProportionalOp(bool value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_bProportionalOp", false, value); }
    float GetStartTime_min() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalar", "m_flStartTime_min"); }
    void SetStartTime_min(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_flStartTime_min", false, value); }
    float GetStartTime_max() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalar", "m_flStartTime_max"); }
    void SetStartTime_max(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_flStartTime_max", false, value); }
    float GetEndTime_min() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalar", "m_flEndTime_min"); }
    void SetEndTime_min(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_flEndTime_min", false, value); }
    float GetEndTime_max() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalar", "m_flEndTime_max"); }
    void SetEndTime_max(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_flEndTime_max", false, value); }
    float GetOscMult() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalar", "m_flOscMult"); }
    void SetOscMult(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_flOscMult", false, value); }
    float GetOscAdd() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalar", "m_flOscAdd"); }
    void SetOscAdd(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalar", "m_flOscAdd", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif