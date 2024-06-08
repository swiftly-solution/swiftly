class GC_OP_OscillateVector;

#ifndef _gcc_op_oscillatevector_h
#define _gcc_op_oscillatevector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_OscillateVector
{
private:
    void *m_ptr;

public:
    GC_OP_OscillateVector() {}
    GC_OP_OscillateVector(void *ptr) : m_ptr(ptr) {}

    Vector GetRateMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_OscillateVector", "m_RateMin"); }
    void SetRateMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_RateMin", false, value); }
    Vector GetRateMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_OscillateVector", "m_RateMax"); }
    void SetRateMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_RateMax", false, value); }
    Vector GetFrequencyMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_OscillateVector", "m_FrequencyMin"); }
    void SetFrequencyMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_FrequencyMin", false, value); }
    Vector GetFrequencyMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_OscillateVector", "m_FrequencyMax"); }
    void SetFrequencyMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_FrequencyMax", false, value); }
    GParticleAttributeIndex_t GetField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_OscillateVector", "m_nField"); }
    void SetField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_nField", false, value); }
    bool GetProportional() const { return GetSchemaValue<bool>(m_ptr, "C_OP_OscillateVector", "m_bProportional"); }
    void SetProportional(bool value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_bProportional", false, value); }
    bool GetProportionalOp() const { return GetSchemaValue<bool>(m_ptr, "C_OP_OscillateVector", "m_bProportionalOp"); }
    void SetProportionalOp(bool value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_bProportionalOp", false, value); }
    bool GetOffset() const { return GetSchemaValue<bool>(m_ptr, "C_OP_OscillateVector", "m_bOffset"); }
    void SetOffset(bool value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_bOffset", false, value); }
    float GetStartTime_min() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateVector", "m_flStartTime_min"); }
    void SetStartTime_min(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_flStartTime_min", false, value); }
    float GetStartTime_max() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateVector", "m_flStartTime_max"); }
    void SetStartTime_max(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_flStartTime_max", false, value); }
    float GetEndTime_min() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateVector", "m_flEndTime_min"); }
    void SetEndTime_min(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_flEndTime_min", false, value); }
    float GetEndTime_max() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateVector", "m_flEndTime_max"); }
    void SetEndTime_max(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_flEndTime_max", false, value); }
    GCPerParticleFloatInput GetOscMult() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_OscillateVector", "m_flOscMult"); }
    void SetOscMult(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_flOscMult", false, value); }
    GCPerParticleFloatInput GetOscAdd() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_OscillateVector", "m_flOscAdd"); }
    void SetOscAdd(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_flOscAdd", false, value); }
    GCPerParticleFloatInput GetRateScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_OscillateVector", "m_flRateScale"); }
    void SetRateScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_OscillateVector", "m_flRateScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif