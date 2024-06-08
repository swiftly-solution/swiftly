class GC_OP_RemapDotProductToScalar;

#ifndef _gcc_op_remapdotproducttoscalar_h
#define _gcc_op_remapdotproducttoscalar_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapDotProductToScalar
{
private:
    void *m_ptr;

public:
    GC_OP_RemapDotProductToScalar() {}
    GC_OP_RemapDotProductToScalar(void *ptr) : m_ptr(ptr) {}

    int32_t GetInputCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapDotProductToScalar", "m_nInputCP1"); }
    void SetInputCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToScalar", "m_nInputCP1", false, value); }
    int32_t GetInputCP2() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapDotProductToScalar", "m_nInputCP2"); }
    void SetInputCP2(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToScalar", "m_nInputCP2", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapDotProductToScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToScalar", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDotProductToScalar", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToScalar", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDotProductToScalar", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToScalar", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDotProductToScalar", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToScalar", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDotProductToScalar", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToScalar", "m_flOutputMax", false, value); }
    bool GetUseParticleVelocity() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapDotProductToScalar", "m_bUseParticleVelocity"); }
    void SetUseParticleVelocity(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToScalar", "m_bUseParticleVelocity", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_RemapDotProductToScalar", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToScalar", "m_nSetMethod", false, value); }
    bool GetActiveRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapDotProductToScalar", "m_bActiveRange"); }
    void SetActiveRange(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToScalar", "m_bActiveRange", false, value); }
    bool GetUseParticleNormal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapDotProductToScalar", "m_bUseParticleNormal"); }
    void SetUseParticleNormal(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToScalar", "m_bUseParticleNormal", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif