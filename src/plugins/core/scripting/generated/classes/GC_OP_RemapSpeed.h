class GC_OP_RemapSpeed;

#ifndef _gcc_op_remapspeed_h
#define _gcc_op_remapspeed_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapSpeed
{
private:
    void *m_ptr;

public:
    GC_OP_RemapSpeed() {}
    GC_OP_RemapSpeed(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapSpeed", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeed", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapSpeed", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeed", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapSpeed", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeed", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapSpeed", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeed", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapSpeed", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeed", "m_flOutputMax", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_RemapSpeed", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeed", "m_nSetMethod", false, value); }
    bool GetIgnoreDelta() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapSpeed", "m_bIgnoreDelta"); }
    void SetIgnoreDelta(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeed", "m_bIgnoreDelta", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif