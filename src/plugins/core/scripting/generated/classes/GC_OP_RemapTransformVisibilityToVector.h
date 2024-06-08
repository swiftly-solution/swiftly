class GC_OP_RemapTransformVisibilityToVector;

#ifndef _gcc_op_remaptransformvisibilitytovector_h
#define _gcc_op_remaptransformvisibilitytovector_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GCParticleTransformInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapTransformVisibilityToVector
{
private:
    void *m_ptr;

public:
    GC_OP_RemapTransformVisibilityToVector() {}
    GC_OP_RemapTransformVisibilityToVector(void *ptr) : m_ptr(ptr) {}

    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_nSetMethod", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_TransformInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_flInputMax", false, value); }
    Vector GetOutputMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_vecOutputMin"); }
    void SetOutputMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_vecOutputMin", false, value); }
    Vector GetOutputMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_vecOutputMax"); }
    void SetOutputMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_vecOutputMax", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToVector", "m_flRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif