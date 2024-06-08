class GC_OP_PercentageBetweenTransforms;

#ifndef _gcc_op_percentagebetweentransforms_h
#define _gcc_op_percentagebetweentransforms_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCParticleTransformInput.h"

class GC_OP_PercentageBetweenTransforms
{
private:
    void *m_ptr;

public:
    GC_OP_PercentageBetweenTransforms() {}
    GC_OP_PercentageBetweenTransforms(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_PercentageBetweenTransforms", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransforms", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_PercentageBetweenTransforms", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransforms", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_PercentageBetweenTransforms", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransforms", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_PercentageBetweenTransforms", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransforms", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_PercentageBetweenTransforms", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransforms", "m_flOutputMax", false, value); }
    GCParticleTransformInput GetTransformStart() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_PercentageBetweenTransforms", "m_TransformStart"); }
    void SetTransformStart(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransforms", "m_TransformStart", false, value); }
    GCParticleTransformInput GetTransformEnd() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_PercentageBetweenTransforms", "m_TransformEnd"); }
    void SetTransformEnd(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransforms", "m_TransformEnd", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_PercentageBetweenTransforms", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransforms", "m_nSetMethod", false, value); }
    bool GetActiveRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PercentageBetweenTransforms", "m_bActiveRange"); }
    void SetActiveRange(bool value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransforms", "m_bActiveRange", false, value); }
    bool GetRadialCheck() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PercentageBetweenTransforms", "m_bRadialCheck"); }
    void SetRadialCheck(bool value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransforms", "m_bRadialCheck", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif