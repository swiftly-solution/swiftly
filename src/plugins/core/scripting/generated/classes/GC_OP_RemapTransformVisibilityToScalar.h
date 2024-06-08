class GC_OP_RemapTransformVisibilityToScalar;

#ifndef _gcc_op_remaptransformvisibilitytoscalar_h
#define _gcc_op_remaptransformvisibilitytoscalar_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GCParticleTransformInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapTransformVisibilityToScalar
{
private:
    void *m_ptr;

public:
    GC_OP_RemapTransformVisibilityToScalar() {}
    GC_OP_RemapTransformVisibilityToScalar(void *ptr) : m_ptr(ptr) {}

    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_nSetMethod", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_TransformInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_flOutputMax", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformVisibilityToScalar", "m_flRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif