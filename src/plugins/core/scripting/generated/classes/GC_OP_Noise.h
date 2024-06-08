class GC_OP_Noise;

#ifndef _gcc_op_noise_h
#define _gcc_op_noise_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_Noise
{
private:
    void *m_ptr;

public:
    GC_OP_Noise() {}
    GC_OP_Noise(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_Noise", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_Noise", "m_nFieldOutput", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_Noise", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_Noise", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_Noise", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_Noise", "m_flOutputMax", false, value); }
    float Get4NoiseScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_Noise", "m_fl4NoiseScale"); }
    void Set4NoiseScale(float value) { SetSchemaValue(m_ptr, "C_OP_Noise", "m_fl4NoiseScale", false, value); }
    bool GetAdditive() const { return GetSchemaValue<bool>(m_ptr, "C_OP_Noise", "m_bAdditive"); }
    void SetAdditive(bool value) { SetSchemaValue(m_ptr, "C_OP_Noise", "m_bAdditive", false, value); }
    float GetNoiseAnimationTimeScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_Noise", "m_flNoiseAnimationTimeScale"); }
    void SetNoiseAnimationTimeScale(float value) { SetSchemaValue(m_ptr, "C_OP_Noise", "m_flNoiseAnimationTimeScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif