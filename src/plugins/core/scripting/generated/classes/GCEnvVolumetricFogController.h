class GCEnvVolumetricFogController;

#ifndef _gccenvvolumetricfogcontroller_h
#define _gccenvvolumetricfogcontroller_h

#include "../../../scripting.h"




class GCEnvVolumetricFogController
{
private:
    void *m_ptr;

public:
    GCEnvVolumetricFogController() {}
    GCEnvVolumetricFogController(void *ptr) : m_ptr(ptr) {}

    float GetScattering() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flScattering"); }
    void SetScattering(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flScattering", false, value); }
    float GetAnisotropy() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flAnisotropy"); }
    void SetAnisotropy(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flAnisotropy", false, value); }
    float GetFadeSpeed() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flFadeSpeed"); }
    void SetFadeSpeed(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flFadeSpeed", false, value); }
    float GetDrawDistance() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flDrawDistance"); }
    void SetDrawDistance(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flDrawDistance", false, value); }
    float GetFadeInStart() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flFadeInStart"); }
    void SetFadeInStart(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flFadeInStart", false, value); }
    float GetFadeInEnd() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flFadeInEnd"); }
    void SetFadeInEnd(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flFadeInEnd", false, value); }
    float GetIndirectStrength() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flIndirectStrength"); }
    void SetIndirectStrength(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flIndirectStrength", false, value); }
    int32_t GetIndirectTextureDimX() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimX"); }
    void SetIndirectTextureDimX(int32_t value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimX", false, value); }
    int32_t GetIndirectTextureDimY() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimY"); }
    void SetIndirectTextureDimY(int32_t value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimY", false, value); }
    int32_t GetIndirectTextureDimZ() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimZ"); }
    void SetIndirectTextureDimZ(int32_t value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimZ", false, value); }
    Vector GetBoxMins() const { return GetSchemaValue<Vector>(m_ptr, "CEnvVolumetricFogController", "m_vBoxMins"); }
    void SetBoxMins(Vector value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_vBoxMins", false, value); }
    Vector GetBoxMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CEnvVolumetricFogController", "m_vBoxMaxs"); }
    void SetBoxMaxs(Vector value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_vBoxMaxs", false, value); }
    bool GetActive() const { return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bActive"); }
    void SetActive(bool value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bActive", false, value); }
    float GetStartAnisotropy() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flStartAnisotropy"); }
    void SetStartAnisotropy(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flStartAnisotropy", false, value); }
    float GetStartScattering() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flStartScattering"); }
    void SetStartScattering(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flStartScattering", false, value); }
    float GetStartDrawDistance() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flStartDrawDistance"); }
    void SetStartDrawDistance(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flStartDrawDistance", false, value); }
    float GetDefaultAnisotropy() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flDefaultAnisotropy"); }
    void SetDefaultAnisotropy(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flDefaultAnisotropy", false, value); }
    float GetDefaultScattering() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flDefaultScattering"); }
    void SetDefaultScattering(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flDefaultScattering", false, value); }
    float GetDefaultDrawDistance() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flDefaultDrawDistance"); }
    void SetDefaultDrawDistance(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flDefaultDrawDistance", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bStartDisabled", false, value); }
    bool GetEnableIndirect() const { return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bEnableIndirect"); }
    void SetEnableIndirect(bool value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bEnableIndirect", false, value); }
    bool GetIndirectUseLPVs() const { return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bIndirectUseLPVs"); }
    void SetIndirectUseLPVs(bool value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bIndirectUseLPVs", false, value); }
    bool GetIsMaster() const { return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bIsMaster"); }
    void SetIsMaster(bool value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bIsMaster", false, value); }
    int32_t GetForceRefreshCount() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvVolumetricFogController", "m_nForceRefreshCount"); }
    void SetForceRefreshCount(int32_t value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_nForceRefreshCount", false, value); }
    float GetNoiseSpeed() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_fNoiseSpeed"); }
    void SetNoiseSpeed(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_fNoiseSpeed", false, value); }
    float GetNoiseStrength() const { return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_fNoiseStrength"); }
    void SetNoiseStrength(float value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_fNoiseStrength", false, value); }
    Vector GetNoiseScale() const { return GetSchemaValue<Vector>(m_ptr, "CEnvVolumetricFogController", "m_vNoiseScale"); }
    void SetNoiseScale(Vector value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_vNoiseScale", false, value); }
    bool GetFirstTime() const { return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bFirstTime"); }
    void SetFirstTime(bool value) { SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bFirstTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif