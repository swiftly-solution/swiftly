class GC_INIT_RemapSpeedToScalar;

#ifndef _gcc_init_remapspeedtoscalar_h
#define _gcc_init_remapspeedtoscalar_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_RemapSpeedToScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapSpeedToScalar() {}
    GC_INIT_RemapSpeedToScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapSpeedToScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapSpeedToScalar", "m_nFieldOutput", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RemapSpeedToScalar", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapSpeedToScalar", "m_nControlPointNumber", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flEndTime", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapSpeedToScalar", "m_flOutputMax", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_INIT_RemapSpeedToScalar", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapSpeedToScalar", "m_nSetMethod", false, value); }
    bool GetPerParticle() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapSpeedToScalar", "m_bPerParticle"); }
    void SetPerParticle(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapSpeedToScalar", "m_bPerParticle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif