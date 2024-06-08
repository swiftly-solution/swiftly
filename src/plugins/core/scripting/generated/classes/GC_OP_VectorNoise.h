class GC_OP_VectorNoise;

#ifndef _gcc_op_vectornoise_h
#define _gcc_op_vectornoise_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_VectorNoise
{
private:
    void *m_ptr;

public:
    GC_OP_VectorNoise() {}
    GC_OP_VectorNoise(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_VectorNoise", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_VectorNoise", "m_nFieldOutput", false, value); }
    Vector GetOutputMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_VectorNoise", "m_vecOutputMin"); }
    void SetOutputMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_VectorNoise", "m_vecOutputMin", false, value); }
    Vector GetOutputMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_VectorNoise", "m_vecOutputMax"); }
    void SetOutputMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_VectorNoise", "m_vecOutputMax", false, value); }
    float Get4NoiseScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_VectorNoise", "m_fl4NoiseScale"); }
    void Set4NoiseScale(float value) { SetSchemaValue(m_ptr, "C_OP_VectorNoise", "m_fl4NoiseScale", false, value); }
    bool GetAdditive() const { return GetSchemaValue<bool>(m_ptr, "C_OP_VectorNoise", "m_bAdditive"); }
    void SetAdditive(bool value) { SetSchemaValue(m_ptr, "C_OP_VectorNoise", "m_bAdditive", false, value); }
    bool GetOffset() const { return GetSchemaValue<bool>(m_ptr, "C_OP_VectorNoise", "m_bOffset"); }
    void SetOffset(bool value) { SetSchemaValue(m_ptr, "C_OP_VectorNoise", "m_bOffset", false, value); }
    float GetNoiseAnimationTimeScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_VectorNoise", "m_flNoiseAnimationTimeScale"); }
    void SetNoiseAnimationTimeScale(float value) { SetSchemaValue(m_ptr, "C_OP_VectorNoise", "m_flNoiseAnimationTimeScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif