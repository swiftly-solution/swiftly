class GC_OP_DistanceBetweenTransforms;

#ifndef _gcc_op_distancebetweentransforms_h
#define _gcc_op_distancebetweentransforms_h

#include "../../../scripting.h"

#include "../types/GParticleTraceSet_t.h"
#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCParticleTransformInput.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_DistanceBetweenTransforms
{
private:
    void *m_ptr;

public:
    GC_OP_DistanceBetweenTransforms() {}
    GC_OP_DistanceBetweenTransforms(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_nFieldOutput", false, value); }
    GCParticleTransformInput GetTransformStart() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_TransformStart"); }
    void SetTransformStart(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_TransformStart", false, value); }
    GCParticleTransformInput GetTransformEnd() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_TransformEnd"); }
    void SetTransformEnd(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_TransformEnd", false, value); }
    GCPerParticleFloatInput GetInputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flInputMin"); }
    void SetInputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flInputMin", false, value); }
    GCPerParticleFloatInput GetInputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flInputMax"); }
    void SetInputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flInputMax", false, value); }
    GCPerParticleFloatInput GetOutputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flOutputMin"); }
    void SetOutputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flOutputMin", false, value); }
    GCPerParticleFloatInput GetOutputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flOutputMax"); }
    void SetOutputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flOutputMax", false, value); }
    float GetMaxTraceLength() const { return GetSchemaValue<float>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flMaxTraceLength"); }
    void SetMaxTraceLength(float value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flMaxTraceLength", false, value); }
    float GetLOSScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flLOSScale"); }
    void SetLOSScale(float value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_flLOSScale", false, value); }
    std::string GetCollisionGroupName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_CollisionGroupName"); }
    void SetCollisionGroupName(std::string value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_CollisionGroupName", false, value); }
    ParticleTraceSet_t GetTraceSet() const { return GetSchemaValue<ParticleTraceSet_t>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_nTraceSet"); }
    void SetTraceSet(ParticleTraceSet_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_nTraceSet", false, value); }
    bool GetLOS() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_bLOS"); }
    void SetLOS(bool value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_bLOS", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_DistanceBetweenTransforms", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenTransforms", "m_nSetMethod", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif