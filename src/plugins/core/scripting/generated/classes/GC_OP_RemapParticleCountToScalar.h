class GC_OP_RemapParticleCountToScalar;

#ifndef _gcc_op_remapparticlecounttoscalar_h
#define _gcc_op_remapparticlecounttoscalar_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_RemapParticleCountToScalar
{
private:
    void *m_ptr;

public:
    GC_OP_RemapParticleCountToScalar() {}
    GC_OP_RemapParticleCountToScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapParticleCountToScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountToScalar", "m_nFieldOutput", false, value); }
    GCParticleCollectionFloatInput GetInputMin() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapParticleCountToScalar", "m_nInputMin"); }
    void SetInputMin(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountToScalar", "m_nInputMin", false, value); }
    GCParticleCollectionFloatInput GetInputMax() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapParticleCountToScalar", "m_nInputMax"); }
    void SetInputMax(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountToScalar", "m_nInputMax", false, value); }
    GCParticleCollectionFloatInput GetOutputMin() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapParticleCountToScalar", "m_flOutputMin"); }
    void SetOutputMin(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountToScalar", "m_flOutputMin", false, value); }
    GCParticleCollectionFloatInput GetOutputMax() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapParticleCountToScalar", "m_flOutputMax"); }
    void SetOutputMax(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountToScalar", "m_flOutputMax", false, value); }
    bool GetActiveRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapParticleCountToScalar", "m_bActiveRange"); }
    void SetActiveRange(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountToScalar", "m_bActiveRange", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_RemapParticleCountToScalar", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountToScalar", "m_nSetMethod", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif