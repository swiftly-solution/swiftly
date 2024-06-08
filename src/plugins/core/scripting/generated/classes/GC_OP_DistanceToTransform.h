class GC_OP_DistanceToTransform;

#ifndef _gcc_op_distancetotransform_h
#define _gcc_op_distancetotransform_h

#include "../../../scripting.h"

#include "../types/GParticleTraceSet_t.h"
#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"
#include "GCParticleTransformInput.h"
#include "GCPerParticleVecInput.h"

class GC_OP_DistanceToTransform
{
private:
    void *m_ptr;

public:
    GC_OP_DistanceToTransform() {}
    GC_OP_DistanceToTransform(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_DistanceToTransform", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_nFieldOutput", false, value); }
    GCPerParticleFloatInput GetInputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceToTransform", "m_flInputMin"); }
    void SetInputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_flInputMin", false, value); }
    GCPerParticleFloatInput GetInputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceToTransform", "m_flInputMax"); }
    void SetInputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_flInputMax", false, value); }
    GCPerParticleFloatInput GetOutputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceToTransform", "m_flOutputMin"); }
    void SetOutputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_flOutputMin", false, value); }
    GCPerParticleFloatInput GetOutputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceToTransform", "m_flOutputMax"); }
    void SetOutputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_flOutputMax", false, value); }
    GCParticleTransformInput GetTransformStart() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_DistanceToTransform", "m_TransformStart"); }
    void SetTransformStart(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_TransformStart", false, value); }
    bool GetLOS() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DistanceToTransform", "m_bLOS"); }
    void SetLOS(bool value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_bLOS", false, value); }
    std::string GetCollisionGroupName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_DistanceToTransform", "m_CollisionGroupName"); }
    void SetCollisionGroupName(std::string value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_CollisionGroupName", false, value); }
    ParticleTraceSet_t GetTraceSet() const { return GetSchemaValue<ParticleTraceSet_t>(m_ptr, "C_OP_DistanceToTransform", "m_nTraceSet"); }
    void SetTraceSet(ParticleTraceSet_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_nTraceSet", false, value); }
    float GetMaxTraceLength() const { return GetSchemaValue<float>(m_ptr, "C_OP_DistanceToTransform", "m_flMaxTraceLength"); }
    void SetMaxTraceLength(float value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_flMaxTraceLength", false, value); }
    float GetLOSScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_DistanceToTransform", "m_flLOSScale"); }
    void SetLOSScale(float value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_flLOSScale", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_DistanceToTransform", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_nSetMethod", false, value); }
    bool GetActiveRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DistanceToTransform", "m_bActiveRange"); }
    void SetActiveRange(bool value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_bActiveRange", false, value); }
    bool GetAdditive() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DistanceToTransform", "m_bAdditive"); }
    void SetAdditive(bool value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_bAdditive", false, value); }
    GCPerParticleVecInput GetComponentScale() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_DistanceToTransform", "m_vecComponentScale"); }
    void SetComponentScale(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceToTransform", "m_vecComponentScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif