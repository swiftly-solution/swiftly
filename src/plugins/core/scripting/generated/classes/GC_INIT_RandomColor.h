class GC_INIT_RandomColor;

#ifndef _gcc_init_randomcolor_h
#define _gcc_init_randomcolor_h

#include "../../../scripting.h"

#include "../types/GParticleColorBlendMode_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_RandomColor
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomColor() {}
    GC_INIT_RandomColor(void *ptr) : m_ptr(ptr) {}

    Color GetColorMin() const { return GetSchemaValue<Color>(m_ptr, "C_INIT_RandomColor", "m_ColorMin"); }
    void SetColorMin(Color value) { SetSchemaValue(m_ptr, "C_INIT_RandomColor", "m_ColorMin", false, value); }
    Color GetColorMax() const { return GetSchemaValue<Color>(m_ptr, "C_INIT_RandomColor", "m_ColorMax"); }
    void SetColorMax(Color value) { SetSchemaValue(m_ptr, "C_INIT_RandomColor", "m_ColorMax", false, value); }
    Color GetTintMin() const { return GetSchemaValue<Color>(m_ptr, "C_INIT_RandomColor", "m_TintMin"); }
    void SetTintMin(Color value) { SetSchemaValue(m_ptr, "C_INIT_RandomColor", "m_TintMin", false, value); }
    Color GetTintMax() const { return GetSchemaValue<Color>(m_ptr, "C_INIT_RandomColor", "m_TintMax"); }
    void SetTintMax(Color value) { SetSchemaValue(m_ptr, "C_INIT_RandomColor", "m_TintMax", false, value); }
    float GetTintPerc() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomColor", "m_flTintPerc"); }
    void SetTintPerc(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomColor", "m_flTintPerc", false, value); }
    float GetUpdateThreshold() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomColor", "m_flUpdateThreshold"); }
    void SetUpdateThreshold(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomColor", "m_flUpdateThreshold", false, value); }
    int32_t GetTintCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RandomColor", "m_nTintCP"); }
    void SetTintCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomColor", "m_nTintCP", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RandomColor", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomColor", "m_nFieldOutput", false, value); }
    ParticleColorBlendMode_t GetTintBlendMode() const { return GetSchemaValue<ParticleColorBlendMode_t>(m_ptr, "C_INIT_RandomColor", "m_nTintBlendMode"); }
    void SetTintBlendMode(ParticleColorBlendMode_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomColor", "m_nTintBlendMode", false, value); }
    float GetLightAmplification() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomColor", "m_flLightAmplification"); }
    void SetLightAmplification(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomColor", "m_flLightAmplification", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif