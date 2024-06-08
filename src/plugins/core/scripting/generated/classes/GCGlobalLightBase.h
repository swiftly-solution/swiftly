class GCGlobalLightBase;

#ifndef _gccgloballightbase_h
#define _gccgloballightbase_h

#include "../../../scripting.h"




class GCGlobalLightBase
{
private:
    void *m_ptr;

public:
    GCGlobalLightBase() {}
    GCGlobalLightBase(void *ptr) : m_ptr(ptr) {}

    bool GetSpotLight() const { return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bSpotLight"); }
    void SetSpotLight(bool value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bSpotLight", false, value); }
    Vector GetSpotLightOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_SpotLightOrigin"); }
    void SetSpotLightOrigin(Vector value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_SpotLightOrigin", false, value); }
    QAngle GetSpotLightAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CGlobalLightBase", "m_SpotLightAngles"); }
    void SetSpotLightAngles(QAngle value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_SpotLightAngles", false, value); }
    Vector GetShadowDirection() const { return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_ShadowDirection"); }
    void SetShadowDirection(Vector value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_ShadowDirection", false, value); }
    Vector GetAmbientDirection() const { return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_AmbientDirection"); }
    void SetAmbientDirection(Vector value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_AmbientDirection", false, value); }
    Vector GetSpecularDirection() const { return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_SpecularDirection"); }
    void SetSpecularDirection(Vector value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_SpecularDirection", false, value); }
    Vector GetInspectorSpecularDirection() const { return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_InspectorSpecularDirection"); }
    void SetInspectorSpecularDirection(Vector value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_InspectorSpecularDirection", false, value); }
    float GetSpecularPower() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flSpecularPower"); }
    void SetSpecularPower(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flSpecularPower", false, value); }
    float GetSpecularIndependence() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flSpecularIndependence"); }
    void SetSpecularIndependence(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flSpecularIndependence", false, value); }
    Color GetSpecularColor() const { return GetSchemaValue<Color>(m_ptr, "CGlobalLightBase", "m_SpecularColor"); }
    void SetSpecularColor(Color value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_SpecularColor", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bStartDisabled", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bEnabled", false, value); }
    Color GetLightColor() const { return GetSchemaValue<Color>(m_ptr, "CGlobalLightBase", "m_LightColor"); }
    void SetLightColor(Color value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_LightColor", false, value); }
    Color GetAmbientColor1() const { return GetSchemaValue<Color>(m_ptr, "CGlobalLightBase", "m_AmbientColor1"); }
    void SetAmbientColor1(Color value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_AmbientColor1", false, value); }
    Color GetAmbientColor2() const { return GetSchemaValue<Color>(m_ptr, "CGlobalLightBase", "m_AmbientColor2"); }
    void SetAmbientColor2(Color value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_AmbientColor2", false, value); }
    Color GetAmbientColor3() const { return GetSchemaValue<Color>(m_ptr, "CGlobalLightBase", "m_AmbientColor3"); }
    void SetAmbientColor3(Color value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_AmbientColor3", false, value); }
    float GetSunDistance() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flSunDistance"); }
    void SetSunDistance(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flSunDistance", false, value); }
    float GetFOV() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flFOV"); }
    void SetFOV(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flFOV", false, value); }
    float GetNearZ() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flNearZ"); }
    void SetNearZ(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flNearZ", false, value); }
    float GetFarZ() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flFarZ"); }
    void SetFarZ(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flFarZ", false, value); }
    bool GetEnableShadows() const { return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bEnableShadows"); }
    void SetEnableShadows(bool value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bEnableShadows", false, value); }
    bool GetOldEnableShadows() const { return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bOldEnableShadows"); }
    void SetOldEnableShadows(bool value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bOldEnableShadows", false, value); }
    bool GetBackgroundClearNotRequired() const { return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bBackgroundClearNotRequired"); }
    void SetBackgroundClearNotRequired(bool value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bBackgroundClearNotRequired", false, value); }
    float GetCloudScale() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flCloudScale"); }
    void SetCloudScale(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flCloudScale", false, value); }
    float GetCloud1Speed() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flCloud1Speed"); }
    void SetCloud1Speed(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flCloud1Speed", false, value); }
    float GetCloud1Direction() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flCloud1Direction"); }
    void SetCloud1Direction(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flCloud1Direction", false, value); }
    float GetCloud2Speed() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flCloud2Speed"); }
    void SetCloud2Speed(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flCloud2Speed", false, value); }
    float GetCloud2Direction() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flCloud2Direction"); }
    void SetCloud2Direction(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flCloud2Direction", false, value); }
    float GetAmbientScale1() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flAmbientScale1"); }
    void SetAmbientScale1(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flAmbientScale1", false, value); }
    float GetAmbientScale2() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flAmbientScale2"); }
    void SetAmbientScale2(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flAmbientScale2", false, value); }
    float GetGroundScale() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flGroundScale"); }
    void SetGroundScale(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flGroundScale", false, value); }
    float GetLightScale() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flLightScale"); }
    void SetLightScale(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flLightScale", false, value); }
    float GetFoWDarkness() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flFoWDarkness"); }
    void SetFoWDarkness(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flFoWDarkness", false, value); }
    bool GetEnableSeparateSkyboxFog() const { return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bEnableSeparateSkyboxFog"); }
    void SetEnableSeparateSkyboxFog(bool value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bEnableSeparateSkyboxFog", false, value); }
    Vector GetFowColor() const { return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_vFowColor"); }
    void SetFowColor(Vector value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_vFowColor", false, value); }
    Vector GetViewOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_ViewOrigin"); }
    void SetViewOrigin(Vector value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_ViewOrigin", false, value); }
    QAngle GetViewAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CGlobalLightBase", "m_ViewAngles"); }
    void SetViewAngles(QAngle value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_ViewAngles", false, value); }
    float GetViewFoV() const { return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flViewFoV"); }
    void SetViewFoV(float value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flViewFoV", false, value); }
    std::vector<Vector> GetWorldPoints() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CGlobalLightBase", "m_WorldPoints"); std::vector<Vector> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetWorldPoints(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CGlobalLightBase", "m_WorldPoints"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CGlobalLightBase", "m_WorldPoints", false, outValue); }
    Vector2D GetFogOffsetLayer0() const { return GetSchemaValue<Vector2D>(m_ptr, "CGlobalLightBase", "m_vFogOffsetLayer0"); }
    void SetFogOffsetLayer0(Vector2D value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_vFogOffsetLayer0", false, value); }
    Vector2D GetFogOffsetLayer1() const { return GetSchemaValue<Vector2D>(m_ptr, "CGlobalLightBase", "m_vFogOffsetLayer1"); }
    void SetFogOffsetLayer1(Vector2D value) { SetSchemaValue(m_ptr, "CGlobalLightBase", "m_vFogOffsetLayer1", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif