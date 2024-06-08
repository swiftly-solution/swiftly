class GC_OP_PercentageBetweenTransformLerpCPs;

#ifndef _gcc_op_percentagebetweentransformlerpcps_h
#define _gcc_op_percentagebetweentransformlerpcps_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCParticleTransformInput.h"

class GC_OP_PercentageBetweenTransformLerpCPs
{
private:
    void *m_ptr;

public:
    GC_OP_PercentageBetweenTransformLerpCPs() {}
    GC_OP_PercentageBetweenTransformLerpCPs(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_flInputMax", false, value); }
    GCParticleTransformInput GetTransformStart() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_TransformStart"); }
    void SetTransformStart(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_TransformStart", false, value); }
    GCParticleTransformInput GetTransformEnd() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_TransformEnd"); }
    void SetTransformEnd(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_TransformEnd", false, value); }
    int32_t GetOutputStartCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nOutputStartCP"); }
    void SetOutputStartCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nOutputStartCP", false, value); }
    int32_t GetOutputStartField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nOutputStartField"); }
    void SetOutputStartField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nOutputStartField", false, value); }
    int32_t GetOutputEndCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nOutputEndCP"); }
    void SetOutputEndCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nOutputEndCP", false, value); }
    int32_t GetOutputEndField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nOutputEndField"); }
    void SetOutputEndField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nOutputEndField", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_nSetMethod", false, value); }
    bool GetActiveRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_bActiveRange"); }
    void SetActiveRange(bool value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_bActiveRange", false, value); }
    bool GetRadialCheck() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_bRadialCheck"); }
    void SetRadialCheck(bool value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformLerpCPs", "m_bRadialCheck", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif