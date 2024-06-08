class GC_INIT_RemapParticleCountToScalar;

#ifndef _gcc_init_remapparticlecounttoscalar_h
#define _gcc_init_remapparticlecounttoscalar_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_RemapParticleCountToScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapParticleCountToScalar() {}
    GC_INIT_RemapParticleCountToScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nFieldOutput", false, value); }
    int32_t GetInputMin() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nInputMin"); }
    void SetInputMin(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nInputMin", false, value); }
    int32_t GetInputMax() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nInputMax"); }
    void SetInputMax(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nInputMax", false, value); }
    int32_t GetScaleControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nScaleControlPoint"); }
    void SetScaleControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nScaleControlPoint", false, value); }
    int32_t GetScaleControlPointField() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nScaleControlPointField"); }
    void SetScaleControlPointField(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nScaleControlPointField", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_flOutputMax", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_nSetMethod", false, value); }
    bool GetActiveRange() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_bActiveRange"); }
    void SetActiveRange(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_bActiveRange", false, value); }
    bool GetInvert() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_bInvert"); }
    void SetInvert(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_bInvert", false, value); }
    bool GetWrap() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_bWrap"); }
    void SetWrap(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_bWrap", false, value); }
    float GetRemapBias() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_flRemapBias"); }
    void SetRemapBias(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToScalar", "m_flRemapBias", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif