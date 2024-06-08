class GC_OP_PercentageBetweenTransformsVector;

#ifndef _gcc_op_percentagebetweentransformsvector_h
#define _gcc_op_percentagebetweentransformsvector_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCParticleTransformInput.h"

class GC_OP_PercentageBetweenTransformsVector
{
private:
    void *m_ptr;

public:
    GC_OP_PercentageBetweenTransformsVector() {}
    GC_OP_PercentageBetweenTransformsVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_flInputMax", false, value); }
    Vector GetOutputMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_vecOutputMin"); }
    void SetOutputMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_vecOutputMin", false, value); }
    Vector GetOutputMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_vecOutputMax"); }
    void SetOutputMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_vecOutputMax", false, value); }
    GCParticleTransformInput GetTransformStart() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_TransformStart"); }
    void SetTransformStart(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_TransformStart", false, value); }
    GCParticleTransformInput GetTransformEnd() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_TransformEnd"); }
    void SetTransformEnd(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_TransformEnd", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_nSetMethod", false, value); }
    bool GetActiveRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_bActiveRange"); }
    void SetActiveRange(bool value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_bActiveRange", false, value); }
    bool GetRadialCheck() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_bRadialCheck"); }
    void SetRadialCheck(bool value) { SetSchemaValue(m_ptr, "C_OP_PercentageBetweenTransformsVector", "m_bRadialCheck", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif