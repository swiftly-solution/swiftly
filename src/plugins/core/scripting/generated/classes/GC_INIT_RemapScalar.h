class GC_INIT_RemapScalar;

#ifndef _gcc_init_remapscalar_h
#define _gcc_init_remapscalar_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_RemapScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapScalar() {}
    GC_INIT_RemapScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapScalar", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalar", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalar", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalar", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalar", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalar", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalar", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalar", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalar", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalar", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalar", "m_flOutputMax", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalar", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalar", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalar", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalar", "m_flEndTime", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_INIT_RemapScalar", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalar", "m_nSetMethod", false, value); }
    bool GetActiveRange() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapScalar", "m_bActiveRange"); }
    void SetActiveRange(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalar", "m_bActiveRange", false, value); }
    float GetRemapBias() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalar", "m_flRemapBias"); }
    void SetRemapBias(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalar", "m_flRemapBias", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif