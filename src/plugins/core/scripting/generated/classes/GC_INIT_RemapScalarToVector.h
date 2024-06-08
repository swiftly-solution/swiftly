class GC_INIT_RemapScalarToVector;

#ifndef _gcc_init_remapscalartovector_h
#define _gcc_init_remapscalartovector_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_RemapScalarToVector
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapScalarToVector() {}
    GC_INIT_RemapScalarToVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapScalarToVector", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapScalarToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalarToVector", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalarToVector", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_flInputMax", false, value); }
    Vector GetOutputMin() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RemapScalarToVector", "m_vecOutputMin"); }
    void SetOutputMin(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_vecOutputMin", false, value); }
    Vector GetOutputMax() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RemapScalarToVector", "m_vecOutputMax"); }
    void SetOutputMax(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_vecOutputMax", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalarToVector", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalarToVector", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_flEndTime", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_INIT_RemapScalarToVector", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_nSetMethod", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RemapScalarToVector", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_nControlPointNumber", false, value); }
    bool GetLocalCoords() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapScalarToVector", "m_bLocalCoords"); }
    void SetLocalCoords(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_bLocalCoords", false, value); }
    float GetRemapBias() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapScalarToVector", "m_flRemapBias"); }
    void SetRemapBias(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapScalarToVector", "m_flRemapBias", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif