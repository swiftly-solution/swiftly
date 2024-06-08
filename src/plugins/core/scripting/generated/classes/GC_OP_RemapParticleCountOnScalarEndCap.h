class GC_OP_RemapParticleCountOnScalarEndCap;

#ifndef _gcc_op_remapparticlecountonscalarendcap_h
#define _gcc_op_remapparticlecountonscalarendcap_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapParticleCountOnScalarEndCap
{
private:
    void *m_ptr;

public:
    GC_OP_RemapParticleCountOnScalarEndCap() {}
    GC_OP_RemapParticleCountOnScalarEndCap(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_nFieldOutput", false, value); }
    int32_t GetInputMin() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_nInputMin"); }
    void SetInputMin(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_nInputMin", false, value); }
    int32_t GetInputMax() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_nInputMax"); }
    void SetInputMax(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_nInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_flOutputMax", false, value); }
    bool GetBackwards() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_bBackwards"); }
    void SetBackwards(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_bBackwards", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_RemapParticleCountOnScalarEndCap", "m_nSetMethod", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif