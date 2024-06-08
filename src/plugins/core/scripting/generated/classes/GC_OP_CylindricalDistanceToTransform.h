class GC_OP_CylindricalDistanceToTransform;

#ifndef _gcc_op_cylindricaldistancetotransform_h
#define _gcc_op_cylindricaldistancetotransform_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"
#include "GCParticleTransformInput.h"

class GC_OP_CylindricalDistanceToTransform
{
private:
    void *m_ptr;

public:
    GC_OP_CylindricalDistanceToTransform() {}
    GC_OP_CylindricalDistanceToTransform(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_nFieldOutput", false, value); }
    GCPerParticleFloatInput GetInputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_flInputMin"); }
    void SetInputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_flInputMin", false, value); }
    GCPerParticleFloatInput GetInputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_flInputMax"); }
    void SetInputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_flInputMax", false, value); }
    GCPerParticleFloatInput GetOutputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_flOutputMin"); }
    void SetOutputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_flOutputMin", false, value); }
    GCPerParticleFloatInput GetOutputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_flOutputMax"); }
    void SetOutputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_flOutputMax", false, value); }
    GCParticleTransformInput GetTransformStart() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_TransformStart"); }
    void SetTransformStart(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_TransformStart", false, value); }
    GCParticleTransformInput GetTransformEnd() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_TransformEnd"); }
    void SetTransformEnd(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_TransformEnd", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_nSetMethod", false, value); }
    bool GetActiveRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_bActiveRange"); }
    void SetActiveRange(bool value) { SetSchemaValue(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_bActiveRange", false, value); }
    bool GetAdditive() const { return GetSchemaValue<bool>(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_bAdditive"); }
    void SetAdditive(bool value) { SetSchemaValue(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_bAdditive", false, value); }
    bool GetCapsule() const { return GetSchemaValue<bool>(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_bCapsule"); }
    void SetCapsule(bool value) { SetSchemaValue(m_ptr, "C_OP_CylindricalDistanceToTransform", "m_bCapsule", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif