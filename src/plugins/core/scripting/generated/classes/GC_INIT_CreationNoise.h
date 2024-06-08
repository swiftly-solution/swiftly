class GC_INIT_CreationNoise;

#ifndef _gcc_init_creationnoise_h
#define _gcc_init_creationnoise_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_INIT_CreationNoise
{
private:
    void *m_ptr;

public:
    GC_INIT_CreationNoise() {}
    GC_INIT_CreationNoise(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_CreationNoise", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_CreationNoise", "m_nFieldOutput", false, value); }
    bool GetAbsVal() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreationNoise", "m_bAbsVal"); }
    void SetAbsVal(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreationNoise", "m_bAbsVal", false, value); }
    bool GetAbsValInv() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreationNoise", "m_bAbsValInv"); }
    void SetAbsValInv(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreationNoise", "m_bAbsValInv", false, value); }
    float GetOffset() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreationNoise", "m_flOffset"); }
    void SetOffset(float value) { SetSchemaValue(m_ptr, "C_INIT_CreationNoise", "m_flOffset", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreationNoise", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_INIT_CreationNoise", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreationNoise", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_INIT_CreationNoise", "m_flOutputMax", false, value); }
    float GetNoiseScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreationNoise", "m_flNoiseScale"); }
    void SetNoiseScale(float value) { SetSchemaValue(m_ptr, "C_INIT_CreationNoise", "m_flNoiseScale", false, value); }
    float GetNoiseScaleLoc() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreationNoise", "m_flNoiseScaleLoc"); }
    void SetNoiseScaleLoc(float value) { SetSchemaValue(m_ptr, "C_INIT_CreationNoise", "m_flNoiseScaleLoc", false, value); }
    Vector GetOffsetLoc() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_CreationNoise", "m_vecOffsetLoc"); }
    void SetOffsetLoc(Vector value) { SetSchemaValue(m_ptr, "C_INIT_CreationNoise", "m_vecOffsetLoc", false, value); }
    float GetWorldTimeScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreationNoise", "m_flWorldTimeScale"); }
    void SetWorldTimeScale(float value) { SetSchemaValue(m_ptr, "C_INIT_CreationNoise", "m_flWorldTimeScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif