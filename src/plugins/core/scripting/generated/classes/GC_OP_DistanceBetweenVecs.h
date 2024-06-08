class GC_OP_DistanceBetweenVecs;

#ifndef _gcc_op_distancebetweenvecs_h
#define _gcc_op_distancebetweenvecs_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleVecInput.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_DistanceBetweenVecs
{
private:
    void *m_ptr;

public:
    GC_OP_DistanceBetweenVecs() {}
    GC_OP_DistanceBetweenVecs(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_DistanceBetweenVecs", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenVecs", "m_nFieldOutput", false, value); }
    GCPerParticleVecInput GetPoint1() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_DistanceBetweenVecs", "m_vecPoint1"); }
    void SetPoint1(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenVecs", "m_vecPoint1", false, value); }
    GCPerParticleVecInput GetPoint2() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_DistanceBetweenVecs", "m_vecPoint2"); }
    void SetPoint2(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenVecs", "m_vecPoint2", false, value); }
    GCPerParticleFloatInput GetInputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceBetweenVecs", "m_flInputMin"); }
    void SetInputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenVecs", "m_flInputMin", false, value); }
    GCPerParticleFloatInput GetInputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceBetweenVecs", "m_flInputMax"); }
    void SetInputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenVecs", "m_flInputMax", false, value); }
    GCPerParticleFloatInput GetOutputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceBetweenVecs", "m_flOutputMin"); }
    void SetOutputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenVecs", "m_flOutputMin", false, value); }
    GCPerParticleFloatInput GetOutputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_DistanceBetweenVecs", "m_flOutputMax"); }
    void SetOutputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenVecs", "m_flOutputMax", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_DistanceBetweenVecs", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenVecs", "m_nSetMethod", false, value); }
    bool GetDeltaTime() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DistanceBetweenVecs", "m_bDeltaTime"); }
    void SetDeltaTime(bool value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenVecs", "m_bDeltaTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif