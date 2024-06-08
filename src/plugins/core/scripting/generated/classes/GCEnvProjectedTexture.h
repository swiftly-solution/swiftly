class GCEnvProjectedTexture;

#ifndef _gccenvprojectedtexture_h
#define _gccenvprojectedtexture_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCEnvProjectedTexture
{
private:
    void *m_ptr;

public:
    GCEnvProjectedTexture() {}
    GCEnvProjectedTexture(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetTargetEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CEnvProjectedTexture", "m_hTargetEntity"); }
    void SetTargetEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n"); }
    bool GetState() const { return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bState"); }
    void SetState(bool value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bState", false, value); }
    bool GetAlwaysUpdate() const { return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bAlwaysUpdate"); }
    void SetAlwaysUpdate(bool value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bAlwaysUpdate", false, value); }
    float GetLightFOV() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flLightFOV"); }
    void SetLightFOV(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flLightFOV", false, value); }
    bool GetEnableShadows() const { return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bEnableShadows"); }
    void SetEnableShadows(bool value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bEnableShadows", false, value); }
    bool GetSimpleProjection() const { return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bSimpleProjection"); }
    void SetSimpleProjection(bool value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bSimpleProjection", false, value); }
    bool GetLightOnlyTarget() const { return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bLightOnlyTarget"); }
    void SetLightOnlyTarget(bool value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bLightOnlyTarget", false, value); }
    bool GetLightWorld() const { return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bLightWorld"); }
    void SetLightWorld(bool value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bLightWorld", false, value); }
    bool GetCameraSpace() const { return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bCameraSpace"); }
    void SetCameraSpace(bool value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bCameraSpace", false, value); }
    float GetBrightnessScale() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flBrightnessScale"); }
    void SetBrightnessScale(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flBrightnessScale", false, value); }
    Color GetLightColor() const { return GetSchemaValue<Color>(m_ptr, "CEnvProjectedTexture", "m_LightColor"); }
    void SetLightColor(Color value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_LightColor", false, value); }
    float GetIntensity() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flIntensity"); }
    void SetIntensity(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flIntensity", false, value); }
    float GetLinearAttenuation() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flLinearAttenuation"); }
    void SetLinearAttenuation(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flLinearAttenuation", false, value); }
    float GetQuadraticAttenuation() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flQuadraticAttenuation"); }
    void SetQuadraticAttenuation(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flQuadraticAttenuation", false, value); }
    bool GetVolumetric() const { return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bVolumetric"); }
    void SetVolumetric(bool value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bVolumetric", false, value); }
    float GetNoiseStrength() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flNoiseStrength"); }
    void SetNoiseStrength(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flNoiseStrength", false, value); }
    float GetFlashlightTime() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flFlashlightTime"); }
    void SetFlashlightTime(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flFlashlightTime", false, value); }
    uint32_t GetNumPlanes() const { return GetSchemaValue<uint32_t>(m_ptr, "CEnvProjectedTexture", "m_nNumPlanes"); }
    void SetNumPlanes(uint32_t value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_nNumPlanes", false, value); }
    float GetPlaneOffset() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flPlaneOffset"); }
    void SetPlaneOffset(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flPlaneOffset", false, value); }
    float GetVolumetricIntensity() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flVolumetricIntensity"); }
    void SetVolumetricIntensity(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flVolumetricIntensity", false, value); }
    float GetColorTransitionTime() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flColorTransitionTime"); }
    void SetColorTransitionTime(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flColorTransitionTime", false, value); }
    float GetAmbient() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flAmbient"); }
    void SetAmbient(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flAmbient", false, value); }
    std::string GetSpotlightTextureName() const { return GetSchemaValue<char*>(m_ptr, "CEnvProjectedTexture", "m_SpotlightTextureName"); }
    void SetSpotlightTextureName(std::string value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_SpotlightTextureName", false, value); }
    int32_t GetSpotlightTextureFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvProjectedTexture", "m_nSpotlightTextureFrame"); }
    void SetSpotlightTextureFrame(int32_t value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_nSpotlightTextureFrame", false, value); }
    uint32_t GetShadowQuality() const { return GetSchemaValue<uint32_t>(m_ptr, "CEnvProjectedTexture", "m_nShadowQuality"); }
    void SetShadowQuality(uint32_t value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_nShadowQuality", false, value); }
    float GetNearZ() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flNearZ"); }
    void SetNearZ(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flNearZ", false, value); }
    float GetFarZ() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flFarZ"); }
    void SetFarZ(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flFarZ", false, value); }
    float GetProjectionSize() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flProjectionSize"); }
    void SetProjectionSize(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flProjectionSize", false, value); }
    float GetRotation() const { return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flRotation"); }
    void SetRotation(float value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flRotation", false, value); }
    bool GetFlipHorizontal() const { return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bFlipHorizontal"); }
    void SetFlipHorizontal(bool value) { SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bFlipHorizontal", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif