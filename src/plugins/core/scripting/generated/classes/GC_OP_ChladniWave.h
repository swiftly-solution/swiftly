class GC_OP_ChladniWave;

#ifndef _gcc_op_chladniwave_h
#define _gcc_op_chladniwave_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"
#include "GCPerParticleVecInput.h"

class GC_OP_ChladniWave
{
private:
    void *m_ptr;

public:
    GC_OP_ChladniWave() {}
    GC_OP_ChladniWave(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_ChladniWave", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_ChladniWave", "m_nFieldOutput", false, value); }
    GCPerParticleFloatInput GetInputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ChladniWave", "m_flInputMin"); }
    void SetInputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ChladniWave", "m_flInputMin", false, value); }
    GCPerParticleFloatInput GetInputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ChladniWave", "m_flInputMax"); }
    void SetInputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ChladniWave", "m_flInputMax", false, value); }
    GCPerParticleFloatInput GetOutputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ChladniWave", "m_flOutputMin"); }
    void SetOutputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ChladniWave", "m_flOutputMin", false, value); }
    GCPerParticleFloatInput GetOutputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ChladniWave", "m_flOutputMax"); }
    void SetOutputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ChladniWave", "m_flOutputMax", false, value); }
    GCPerParticleVecInput GetWaveLength() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_ChladniWave", "m_vecWaveLength"); }
    void SetWaveLength(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_ChladniWave", "m_vecWaveLength", false, value); }
    GCPerParticleVecInput GetHarmonics() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_ChladniWave", "m_vecHarmonics"); }
    void SetHarmonics(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_ChladniWave", "m_vecHarmonics", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_ChladniWave", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_ChladniWave", "m_nSetMethod", false, value); }
    int32_t GetLocalSpaceControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ChladniWave", "m_nLocalSpaceControlPoint"); }
    void SetLocalSpaceControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ChladniWave", "m_nLocalSpaceControlPoint", false, value); }
    bool Get3D() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ChladniWave", "m_b3D"); }
    void Set3D(bool value) { SetSchemaValue(m_ptr, "C_OP_ChladniWave", "m_b3D", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif