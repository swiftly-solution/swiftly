class Gfogparams_t;

#ifndef _gcfogparams_t_h
#define _gcfogparams_t_h

#include "../../../scripting.h"




class Gfogparams_t
{
private:
    void *m_ptr;

public:
    Gfogparams_t() {}
    Gfogparams_t(void *ptr) : m_ptr(ptr) {}

    Vector GetDirPrimary() const { return GetSchemaValue<Vector>(m_ptr, "fogparams_t", "dirPrimary"); }
    void SetDirPrimary(Vector value) { SetSchemaValue(m_ptr, "fogparams_t", "dirPrimary", true, value); }
    Color GetColorPrimary() const { return GetSchemaValue<Color>(m_ptr, "fogparams_t", "colorPrimary"); }
    void SetColorPrimary(Color value) { SetSchemaValue(m_ptr, "fogparams_t", "colorPrimary", true, value); }
    Color GetColorSecondary() const { return GetSchemaValue<Color>(m_ptr, "fogparams_t", "colorSecondary"); }
    void SetColorSecondary(Color value) { SetSchemaValue(m_ptr, "fogparams_t", "colorSecondary", true, value); }
    Color GetColorPrimaryLerpTo() const { return GetSchemaValue<Color>(m_ptr, "fogparams_t", "colorPrimaryLerpTo"); }
    void SetColorPrimaryLerpTo(Color value) { SetSchemaValue(m_ptr, "fogparams_t", "colorPrimaryLerpTo", true, value); }
    Color GetColorSecondaryLerpTo() const { return GetSchemaValue<Color>(m_ptr, "fogparams_t", "colorSecondaryLerpTo"); }
    void SetColorSecondaryLerpTo(Color value) { SetSchemaValue(m_ptr, "fogparams_t", "colorSecondaryLerpTo", true, value); }
    float GetStart() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "start"); }
    void SetStart(float value) { SetSchemaValue(m_ptr, "fogparams_t", "start", true, value); }
    float GetEnd() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "end"); }
    void SetEnd(float value) { SetSchemaValue(m_ptr, "fogparams_t", "end", true, value); }
    float GetFarz() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "farz"); }
    void SetFarz(float value) { SetSchemaValue(m_ptr, "fogparams_t", "farz", true, value); }
    float GetMaxdensity() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "maxdensity"); }
    void SetMaxdensity(float value) { SetSchemaValue(m_ptr, "fogparams_t", "maxdensity", true, value); }
    float GetExponent() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "exponent"); }
    void SetExponent(float value) { SetSchemaValue(m_ptr, "fogparams_t", "exponent", true, value); }
    float GetHDRColorScale() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "HDRColorScale"); }
    void SetHDRColorScale(float value) { SetSchemaValue(m_ptr, "fogparams_t", "HDRColorScale", true, value); }
    float GetSkyboxFogFactor() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "skyboxFogFactor"); }
    void SetSkyboxFogFactor(float value) { SetSchemaValue(m_ptr, "fogparams_t", "skyboxFogFactor", true, value); }
    float GetSkyboxFogFactorLerpTo() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "skyboxFogFactorLerpTo"); }
    void SetSkyboxFogFactorLerpTo(float value) { SetSchemaValue(m_ptr, "fogparams_t", "skyboxFogFactorLerpTo", true, value); }
    float GetStartLerpTo() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "startLerpTo"); }
    void SetStartLerpTo(float value) { SetSchemaValue(m_ptr, "fogparams_t", "startLerpTo", true, value); }
    float GetEndLerpTo() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "endLerpTo"); }
    void SetEndLerpTo(float value) { SetSchemaValue(m_ptr, "fogparams_t", "endLerpTo", true, value); }
    float GetMaxdensityLerpTo() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "maxdensityLerpTo"); }
    void SetMaxdensityLerpTo(float value) { SetSchemaValue(m_ptr, "fogparams_t", "maxdensityLerpTo", true, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "duration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "fogparams_t", "duration", true, value); }
    float GetBlendtobackground() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "blendtobackground"); }
    void SetBlendtobackground(float value) { SetSchemaValue(m_ptr, "fogparams_t", "blendtobackground", true, value); }
    float GetScattering() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "scattering"); }
    void SetScattering(float value) { SetSchemaValue(m_ptr, "fogparams_t", "scattering", true, value); }
    float GetLocallightscale() const { return GetSchemaValue<float>(m_ptr, "fogparams_t", "locallightscale"); }
    void SetLocallightscale(float value) { SetSchemaValue(m_ptr, "fogparams_t", "locallightscale", true, value); }
    bool GetEnable() const { return GetSchemaValue<bool>(m_ptr, "fogparams_t", "enable"); }
    void SetEnable(bool value) { SetSchemaValue(m_ptr, "fogparams_t", "enable", true, value); }
    bool GetBlend() const { return GetSchemaValue<bool>(m_ptr, "fogparams_t", "blend"); }
    void SetBlend(bool value) { SetSchemaValue(m_ptr, "fogparams_t", "blend", true, value); }
    bool GetNoReflectionFog() const { return GetSchemaValue<bool>(m_ptr, "fogparams_t", "m_bNoReflectionFog"); }
    void SetNoReflectionFog(bool value) { SetSchemaValue(m_ptr, "fogparams_t", "m_bNoReflectionFog", true, value); }
    bool GetPadding() const { return GetSchemaValue<bool>(m_ptr, "fogparams_t", "m_bPadding"); }
    void SetPadding(bool value) { SetSchemaValue(m_ptr, "fogparams_t", "m_bPadding", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif