class GC_INIT_RemapTransformToVector;

#ifndef _gcc_init_remaptransformtovector_h
#define _gcc_init_remaptransformtovector_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCParticleTransformInput.h"

class GC_INIT_RemapTransformToVector
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapTransformToVector() {}
    GC_INIT_RemapTransformToVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapTransformToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_nFieldOutput", false, value); }
    Vector GetInputMin() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RemapTransformToVector", "m_vInputMin"); }
    void SetInputMin(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_vInputMin", false, value); }
    Vector GetInputMax() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RemapTransformToVector", "m_vInputMax"); }
    void SetInputMax(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_vInputMax", false, value); }
    Vector GetOutputMin() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RemapTransformToVector", "m_vOutputMin"); }
    void SetOutputMin(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_vOutputMin", false, value); }
    Vector GetOutputMax() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RemapTransformToVector", "m_vOutputMax"); }
    void SetOutputMax(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_vOutputMax", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_RemapTransformToVector", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_TransformInput", false, value); }
    GCParticleTransformInput GetLocalSpaceTransform() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_RemapTransformToVector", "m_LocalSpaceTransform"); }
    void SetLocalSpaceTransform(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_LocalSpaceTransform", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapTransformToVector", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapTransformToVector", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_flEndTime", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_INIT_RemapTransformToVector", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_nSetMethod", false, value); }
    bool GetOffset() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapTransformToVector", "m_bOffset"); }
    void SetOffset(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_bOffset", false, value); }
    bool GetAccelerate() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapTransformToVector", "m_bAccelerate"); }
    void SetAccelerate(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_bAccelerate", false, value); }
    float GetRemapBias() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapTransformToVector", "m_flRemapBias"); }
    void SetRemapBias(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformToVector", "m_flRemapBias", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif