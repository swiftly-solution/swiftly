class GC_INIT_ColorLitPerParticle;

#ifndef _gcc_init_colorlitperparticle_h
#define _gcc_init_colorlitperparticle_h

#include "../../../scripting.h"

#include "../types/GParticleColorBlendMode_t.h"


class GC_INIT_ColorLitPerParticle
{
private:
    void *m_ptr;

public:
    GC_INIT_ColorLitPerParticle() {}
    GC_INIT_ColorLitPerParticle(void *ptr) : m_ptr(ptr) {}

    Color GetColorMin() const { return GetSchemaValue<Color>(m_ptr, "C_INIT_ColorLitPerParticle", "m_ColorMin"); }
    void SetColorMin(Color value) { SetSchemaValue(m_ptr, "C_INIT_ColorLitPerParticle", "m_ColorMin", false, value); }
    Color GetColorMax() const { return GetSchemaValue<Color>(m_ptr, "C_INIT_ColorLitPerParticle", "m_ColorMax"); }
    void SetColorMax(Color value) { SetSchemaValue(m_ptr, "C_INIT_ColorLitPerParticle", "m_ColorMax", false, value); }
    Color GetTintMin() const { return GetSchemaValue<Color>(m_ptr, "C_INIT_ColorLitPerParticle", "m_TintMin"); }
    void SetTintMin(Color value) { SetSchemaValue(m_ptr, "C_INIT_ColorLitPerParticle", "m_TintMin", false, value); }
    Color GetTintMax() const { return GetSchemaValue<Color>(m_ptr, "C_INIT_ColorLitPerParticle", "m_TintMax"); }
    void SetTintMax(Color value) { SetSchemaValue(m_ptr, "C_INIT_ColorLitPerParticle", "m_TintMax", false, value); }
    float GetTintPerc() const { return GetSchemaValue<float>(m_ptr, "C_INIT_ColorLitPerParticle", "m_flTintPerc"); }
    void SetTintPerc(float value) { SetSchemaValue(m_ptr, "C_INIT_ColorLitPerParticle", "m_flTintPerc", false, value); }
    ParticleColorBlendMode_t GetTintBlendMode() const { return GetSchemaValue<ParticleColorBlendMode_t>(m_ptr, "C_INIT_ColorLitPerParticle", "m_nTintBlendMode"); }
    void SetTintBlendMode(ParticleColorBlendMode_t value) { SetSchemaValue(m_ptr, "C_INIT_ColorLitPerParticle", "m_nTintBlendMode", false, value); }
    float GetLightAmplification() const { return GetSchemaValue<float>(m_ptr, "C_INIT_ColorLitPerParticle", "m_flLightAmplification"); }
    void SetLightAmplification(float value) { SetSchemaValue(m_ptr, "C_INIT_ColorLitPerParticle", "m_flLightAmplification", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif