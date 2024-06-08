class GCGradientFog;

#ifndef _gccgradientfog_h
#define _gccgradientfog_h

#include "../../../scripting.h"




class GCGradientFog
{
private:
    void *m_ptr;

public:
    GCGradientFog() {}
    GCGradientFog(void *ptr) : m_ptr(ptr) {}

    float GetFogStartDistance() const { return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogStartDistance"); }
    void SetFogStartDistance(float value) { SetSchemaValue(m_ptr, "CGradientFog", "m_flFogStartDistance", false, value); }
    float GetFogEndDistance() const { return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogEndDistance"); }
    void SetFogEndDistance(float value) { SetSchemaValue(m_ptr, "CGradientFog", "m_flFogEndDistance", false, value); }
    bool GetHeightFogEnabled() const { return GetSchemaValue<bool>(m_ptr, "CGradientFog", "m_bHeightFogEnabled"); }
    void SetHeightFogEnabled(bool value) { SetSchemaValue(m_ptr, "CGradientFog", "m_bHeightFogEnabled", false, value); }
    float GetFogStartHeight() const { return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogStartHeight"); }
    void SetFogStartHeight(float value) { SetSchemaValue(m_ptr, "CGradientFog", "m_flFogStartHeight", false, value); }
    float GetFogEndHeight() const { return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogEndHeight"); }
    void SetFogEndHeight(float value) { SetSchemaValue(m_ptr, "CGradientFog", "m_flFogEndHeight", false, value); }
    float GetFarZ() const { return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFarZ"); }
    void SetFarZ(float value) { SetSchemaValue(m_ptr, "CGradientFog", "m_flFarZ", false, value); }
    float GetFogMaxOpacity() const { return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogMaxOpacity"); }
    void SetFogMaxOpacity(float value) { SetSchemaValue(m_ptr, "CGradientFog", "m_flFogMaxOpacity", false, value); }
    float GetFogFalloffExponent() const { return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogFalloffExponent"); }
    void SetFogFalloffExponent(float value) { SetSchemaValue(m_ptr, "CGradientFog", "m_flFogFalloffExponent", false, value); }
    float GetFogVerticalExponent() const { return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogVerticalExponent"); }
    void SetFogVerticalExponent(float value) { SetSchemaValue(m_ptr, "CGradientFog", "m_flFogVerticalExponent", false, value); }
    Color GetFogColor() const { return GetSchemaValue<Color>(m_ptr, "CGradientFog", "m_fogColor"); }
    void SetFogColor(Color value) { SetSchemaValue(m_ptr, "CGradientFog", "m_fogColor", false, value); }
    float GetFogStrength() const { return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogStrength"); }
    void SetFogStrength(float value) { SetSchemaValue(m_ptr, "CGradientFog", "m_flFogStrength", false, value); }
    float GetFadeTime() const { return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFadeTime"); }
    void SetFadeTime(float value) { SetSchemaValue(m_ptr, "CGradientFog", "m_flFadeTime", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CGradientFog", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CGradientFog", "m_bStartDisabled", false, value); }
    bool GetIsEnabled() const { return GetSchemaValue<bool>(m_ptr, "CGradientFog", "m_bIsEnabled"); }
    void SetIsEnabled(bool value) { SetSchemaValue(m_ptr, "CGradientFog", "m_bIsEnabled", false, value); }
    bool GetGradientFogNeedsTextures() const { return GetSchemaValue<bool>(m_ptr, "CGradientFog", "m_bGradientFogNeedsTextures"); }
    void SetGradientFogNeedsTextures(bool value) { SetSchemaValue(m_ptr, "CGradientFog", "m_bGradientFogNeedsTextures", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif