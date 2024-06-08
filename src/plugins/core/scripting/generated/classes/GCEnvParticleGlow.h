class GCEnvParticleGlow;

#ifndef _gccenvparticleglow_h
#define _gccenvparticleglow_h

#include "../../../scripting.h"




class GCEnvParticleGlow
{
private:
    void *m_ptr;

public:
    GCEnvParticleGlow() {}
    GCEnvParticleGlow(void *ptr) : m_ptr(ptr) {}

    float GetAlphaScale() const { return GetSchemaValue<float>(m_ptr, "CEnvParticleGlow", "m_flAlphaScale"); }
    void SetAlphaScale(float value) { SetSchemaValue(m_ptr, "CEnvParticleGlow", "m_flAlphaScale", false, value); }
    float GetRadiusScale() const { return GetSchemaValue<float>(m_ptr, "CEnvParticleGlow", "m_flRadiusScale"); }
    void SetRadiusScale(float value) { SetSchemaValue(m_ptr, "CEnvParticleGlow", "m_flRadiusScale", false, value); }
    float GetSelfIllumScale() const { return GetSchemaValue<float>(m_ptr, "CEnvParticleGlow", "m_flSelfIllumScale"); }
    void SetSelfIllumScale(float value) { SetSchemaValue(m_ptr, "CEnvParticleGlow", "m_flSelfIllumScale", false, value); }
    Color GetColorTint() const { return GetSchemaValue<Color>(m_ptr, "CEnvParticleGlow", "m_ColorTint"); }
    void SetColorTint(Color value) { SetSchemaValue(m_ptr, "CEnvParticleGlow", "m_ColorTint", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif