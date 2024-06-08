class GC_OP_NoiseEmitter;

#ifndef _gcc_op_noiseemitter_h
#define _gcc_op_noiseemitter_h

#include "../../../scripting.h"




class GC_OP_NoiseEmitter
{
private:
    void *m_ptr;

public:
    GC_OP_NoiseEmitter() {}
    GC_OP_NoiseEmitter(void *ptr) : m_ptr(ptr) {}

    float GetEmissionDuration() const { return GetSchemaValue<float>(m_ptr, "C_OP_NoiseEmitter", "m_flEmissionDuration"); }
    void SetEmissionDuration(float value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_flEmissionDuration", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_NoiseEmitter", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_flStartTime", false, value); }
    float GetEmissionScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_NoiseEmitter", "m_flEmissionScale"); }
    void SetEmissionScale(float value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_flEmissionScale", false, value); }
    int32_t GetScaleControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_NoiseEmitter", "m_nScaleControlPoint"); }
    void SetScaleControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_nScaleControlPoint", false, value); }
    int32_t GetScaleControlPointField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_NoiseEmitter", "m_nScaleControlPointField"); }
    void SetScaleControlPointField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_nScaleControlPointField", false, value); }
    int32_t GetWorldNoisePoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_NoiseEmitter", "m_nWorldNoisePoint"); }
    void SetWorldNoisePoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_nWorldNoisePoint", false, value); }
    bool GetAbsVal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_NoiseEmitter", "m_bAbsVal"); }
    void SetAbsVal(bool value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_bAbsVal", false, value); }
    bool GetAbsValInv() const { return GetSchemaValue<bool>(m_ptr, "C_OP_NoiseEmitter", "m_bAbsValInv"); }
    void SetAbsValInv(bool value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_bAbsValInv", false, value); }
    float GetOffset() const { return GetSchemaValue<float>(m_ptr, "C_OP_NoiseEmitter", "m_flOffset"); }
    void SetOffset(float value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_flOffset", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_NoiseEmitter", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_NoiseEmitter", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_flOutputMax", false, value); }
    float GetNoiseScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_NoiseEmitter", "m_flNoiseScale"); }
    void SetNoiseScale(float value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_flNoiseScale", false, value); }
    float GetWorldNoiseScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_NoiseEmitter", "m_flWorldNoiseScale"); }
    void SetWorldNoiseScale(float value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_flWorldNoiseScale", false, value); }
    Vector GetOffsetLoc() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_NoiseEmitter", "m_vecOffsetLoc"); }
    void SetOffsetLoc(Vector value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_vecOffsetLoc", false, value); }
    float GetWorldTimeScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_NoiseEmitter", "m_flWorldTimeScale"); }
    void SetWorldTimeScale(float value) { SetSchemaValue(m_ptr, "C_OP_NoiseEmitter", "m_flWorldTimeScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif