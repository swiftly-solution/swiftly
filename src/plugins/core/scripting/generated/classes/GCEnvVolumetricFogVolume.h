class GCEnvVolumetricFogVolume;

#ifndef _gccenvvolumetricfogvolume_h
#define _gccenvvolumetricfogvolume_h

#include "../../../scripting.h"




class GCEnvVolumetricFogVolume
{
private:
    void *m_ptr;

public:
    GCEnvVolumetricFogVolume() {}
    GCEnvVolumetricFogVolume(void *ptr) : m_ptr(ptr) {}

    bool GetActive() const { return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogVolume", "m_bActive"); }
    void SetActive(bool value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_bActive", false, value); }
    Vector GetBoxMins() const { return GetSchemaValue<Vector>(m_ptr, "CEnvVolumetricFogVolume", "m_vBoxMins"); }
    void SetBoxMins(Vector value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_vBoxMins", false, value); }
    Vector GetBoxMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CEnvVolumetricFogVolume", "m_vBoxMaxs"); }
    void SetBoxMaxs(Vector value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_vBoxMaxs", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogVolume", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_bStartDisabled", false, value); }
    float GetStrength() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_flStrength"); }
    void SetStrength(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_flStrength", false, value); }
    int32_t GetFalloffShape() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvVolumetricFogVolume", "m_nFalloffShape"); }
    void SetFalloffShape(int32_t value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_nFalloffShape", false, value); }
    float GetFalloffExponent() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_flFalloffExponent"); }
    void SetFalloffExponent(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_flFalloffExponent", false, value); }
    float GetHeightFogDepth() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_flHeightFogDepth"); }
    void SetHeightFogDepth(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_flHeightFogDepth", false, value); }
    float GetHeightFogEdgeWidth() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_fHeightFogEdgeWidth"); }
    void SetHeightFogEdgeWidth(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_fHeightFogEdgeWidth", false, value); }
    float GetIndirectLightStrength() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_fIndirectLightStrength"); }
    void SetIndirectLightStrength(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_fIndirectLightStrength", false, value); }
    float GetSunLightStrength() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_fSunLightStrength"); }
    void SetSunLightStrength(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_fSunLightStrength", false, value); }
    float GetNoiseStrength() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_fNoiseStrength"); }
    void SetNoiseStrength(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_fNoiseStrength", false, value); }
    bool GetOverrideIndirectLightStrength() const { return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideIndirectLightStrength"); }
    void SetOverrideIndirectLightStrength(bool value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideIndirectLightStrength", false, value); }
    bool GetOverrideSunLightStrength() const { return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideSunLightStrength"); }
    void SetOverrideSunLightStrength(bool value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideSunLightStrength", false, value); }
    bool GetOverrideNoiseStrength() const { return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideNoiseStrength"); }
    void SetOverrideNoiseStrength(bool value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideNoiseStrength", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif