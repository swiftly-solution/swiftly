#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGlobalLightBase::GCGlobalLightBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGlobalLightBase::GCGlobalLightBase(void *ptr) {
    m_ptr = ptr;
}
bool GCGlobalLightBase::GetSpotLight() const {
    return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bSpotLight");
}
void GCGlobalLightBase::SetSpotLight(bool value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bSpotLight", false, value);
}
Vector GCGlobalLightBase::GetSpotLightOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_SpotLightOrigin");
}
void GCGlobalLightBase::SetSpotLightOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_SpotLightOrigin", false, value);
}
QAngle GCGlobalLightBase::GetSpotLightAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CGlobalLightBase", "m_SpotLightAngles");
}
void GCGlobalLightBase::SetSpotLightAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_SpotLightAngles", false, value);
}
Vector GCGlobalLightBase::GetShadowDirection() const {
    return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_ShadowDirection");
}
void GCGlobalLightBase::SetShadowDirection(Vector value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_ShadowDirection", false, value);
}
Vector GCGlobalLightBase::GetAmbientDirection() const {
    return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_AmbientDirection");
}
void GCGlobalLightBase::SetAmbientDirection(Vector value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_AmbientDirection", false, value);
}
Vector GCGlobalLightBase::GetSpecularDirection() const {
    return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_SpecularDirection");
}
void GCGlobalLightBase::SetSpecularDirection(Vector value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_SpecularDirection", false, value);
}
Vector GCGlobalLightBase::GetInspectorSpecularDirection() const {
    return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_InspectorSpecularDirection");
}
void GCGlobalLightBase::SetInspectorSpecularDirection(Vector value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_InspectorSpecularDirection", false, value);
}
float GCGlobalLightBase::GetSpecularPower() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flSpecularPower");
}
void GCGlobalLightBase::SetSpecularPower(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flSpecularPower", false, value);
}
float GCGlobalLightBase::GetSpecularIndependence() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flSpecularIndependence");
}
void GCGlobalLightBase::SetSpecularIndependence(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flSpecularIndependence", false, value);
}
Color GCGlobalLightBase::GetSpecularColor() const {
    return GetSchemaValue<Color>(m_ptr, "CGlobalLightBase", "m_SpecularColor");
}
void GCGlobalLightBase::SetSpecularColor(Color value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_SpecularColor", false, value);
}
bool GCGlobalLightBase::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bStartDisabled");
}
void GCGlobalLightBase::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bStartDisabled", false, value);
}
bool GCGlobalLightBase::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bEnabled");
}
void GCGlobalLightBase::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bEnabled", false, value);
}
Color GCGlobalLightBase::GetLightColor() const {
    return GetSchemaValue<Color>(m_ptr, "CGlobalLightBase", "m_LightColor");
}
void GCGlobalLightBase::SetLightColor(Color value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_LightColor", false, value);
}
Color GCGlobalLightBase::GetAmbientColor1() const {
    return GetSchemaValue<Color>(m_ptr, "CGlobalLightBase", "m_AmbientColor1");
}
void GCGlobalLightBase::SetAmbientColor1(Color value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_AmbientColor1", false, value);
}
Color GCGlobalLightBase::GetAmbientColor2() const {
    return GetSchemaValue<Color>(m_ptr, "CGlobalLightBase", "m_AmbientColor2");
}
void GCGlobalLightBase::SetAmbientColor2(Color value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_AmbientColor2", false, value);
}
Color GCGlobalLightBase::GetAmbientColor3() const {
    return GetSchemaValue<Color>(m_ptr, "CGlobalLightBase", "m_AmbientColor3");
}
void GCGlobalLightBase::SetAmbientColor3(Color value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_AmbientColor3", false, value);
}
float GCGlobalLightBase::GetSunDistance() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flSunDistance");
}
void GCGlobalLightBase::SetSunDistance(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flSunDistance", false, value);
}
float GCGlobalLightBase::GetFOV() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flFOV");
}
void GCGlobalLightBase::SetFOV(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flFOV", false, value);
}
float GCGlobalLightBase::GetNearZ() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flNearZ");
}
void GCGlobalLightBase::SetNearZ(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flNearZ", false, value);
}
float GCGlobalLightBase::GetFarZ() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flFarZ");
}
void GCGlobalLightBase::SetFarZ(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flFarZ", false, value);
}
bool GCGlobalLightBase::GetEnableShadows() const {
    return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bEnableShadows");
}
void GCGlobalLightBase::SetEnableShadows(bool value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bEnableShadows", false, value);
}
bool GCGlobalLightBase::GetOldEnableShadows() const {
    return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bOldEnableShadows");
}
void GCGlobalLightBase::SetOldEnableShadows(bool value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bOldEnableShadows", false, value);
}
bool GCGlobalLightBase::GetBackgroundClearNotRequired() const {
    return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bBackgroundClearNotRequired");
}
void GCGlobalLightBase::SetBackgroundClearNotRequired(bool value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bBackgroundClearNotRequired", false, value);
}
float GCGlobalLightBase::GetCloudScale() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flCloudScale");
}
void GCGlobalLightBase::SetCloudScale(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flCloudScale", false, value);
}
float GCGlobalLightBase::GetCloud1Speed() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flCloud1Speed");
}
void GCGlobalLightBase::SetCloud1Speed(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flCloud1Speed", false, value);
}
float GCGlobalLightBase::GetCloud1Direction() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flCloud1Direction");
}
void GCGlobalLightBase::SetCloud1Direction(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flCloud1Direction", false, value);
}
float GCGlobalLightBase::GetCloud2Speed() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flCloud2Speed");
}
void GCGlobalLightBase::SetCloud2Speed(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flCloud2Speed", false, value);
}
float GCGlobalLightBase::GetCloud2Direction() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flCloud2Direction");
}
void GCGlobalLightBase::SetCloud2Direction(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flCloud2Direction", false, value);
}
float GCGlobalLightBase::GetAmbientScale1() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flAmbientScale1");
}
void GCGlobalLightBase::SetAmbientScale1(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flAmbientScale1", false, value);
}
float GCGlobalLightBase::GetAmbientScale2() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flAmbientScale2");
}
void GCGlobalLightBase::SetAmbientScale2(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flAmbientScale2", false, value);
}
float GCGlobalLightBase::GetGroundScale() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flGroundScale");
}
void GCGlobalLightBase::SetGroundScale(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flGroundScale", false, value);
}
float GCGlobalLightBase::GetLightScale() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flLightScale");
}
void GCGlobalLightBase::SetLightScale(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flLightScale", false, value);
}
float GCGlobalLightBase::GetFoWDarkness() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flFoWDarkness");
}
void GCGlobalLightBase::SetFoWDarkness(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flFoWDarkness", false, value);
}
bool GCGlobalLightBase::GetEnableSeparateSkyboxFog() const {
    return GetSchemaValue<bool>(m_ptr, "CGlobalLightBase", "m_bEnableSeparateSkyboxFog");
}
void GCGlobalLightBase::SetEnableSeparateSkyboxFog(bool value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_bEnableSeparateSkyboxFog", false, value);
}
Vector GCGlobalLightBase::GetFowColor() const {
    return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_vFowColor");
}
void GCGlobalLightBase::SetFowColor(Vector value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_vFowColor", false, value);
}
Vector GCGlobalLightBase::GetViewOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CGlobalLightBase", "m_ViewOrigin");
}
void GCGlobalLightBase::SetViewOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_ViewOrigin", false, value);
}
QAngle GCGlobalLightBase::GetViewAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CGlobalLightBase", "m_ViewAngles");
}
void GCGlobalLightBase::SetViewAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_ViewAngles", false, value);
}
float GCGlobalLightBase::GetViewFoV() const {
    return GetSchemaValue<float>(m_ptr, "CGlobalLightBase", "m_flViewFoV");
}
void GCGlobalLightBase::SetViewFoV(float value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_flViewFoV", false, value);
}
std::vector<Vector> GCGlobalLightBase::GetWorldPoints() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CGlobalLightBase", "m_WorldPoints"); std::vector<Vector> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCGlobalLightBase::SetWorldPoints(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CGlobalLightBase", "m_WorldPoints"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CGlobalLightBase", "m_WorldPoints", false, outValue);
}
Vector2D GCGlobalLightBase::GetFogOffsetLayer0() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CGlobalLightBase", "m_vFogOffsetLayer0");
}
void GCGlobalLightBase::SetFogOffsetLayer0(Vector2D value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_vFogOffsetLayer0", false, value);
}
Vector2D GCGlobalLightBase::GetFogOffsetLayer1() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CGlobalLightBase", "m_vFogOffsetLayer1");
}
void GCGlobalLightBase::SetFogOffsetLayer1(Vector2D value) {
    SetSchemaValue(m_ptr, "CGlobalLightBase", "m_vFogOffsetLayer1", false, value);
}
std::string GCGlobalLightBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGlobalLightBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCGlobalLightBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGlobalLightBase>("CGlobalLightBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SpotLight", &GCGlobalLightBase::GetSpotLight, &GCGlobalLightBase::SetSpotLight)
        .addProperty("SpotLightOrigin", &GCGlobalLightBase::GetSpotLightOrigin, &GCGlobalLightBase::SetSpotLightOrigin)
        .addProperty("SpotLightAngles", &GCGlobalLightBase::GetSpotLightAngles, &GCGlobalLightBase::SetSpotLightAngles)
        .addProperty("ShadowDirection", &GCGlobalLightBase::GetShadowDirection, &GCGlobalLightBase::SetShadowDirection)
        .addProperty("AmbientDirection", &GCGlobalLightBase::GetAmbientDirection, &GCGlobalLightBase::SetAmbientDirection)
        .addProperty("SpecularDirection", &GCGlobalLightBase::GetSpecularDirection, &GCGlobalLightBase::SetSpecularDirection)
        .addProperty("InspectorSpecularDirection", &GCGlobalLightBase::GetInspectorSpecularDirection, &GCGlobalLightBase::SetInspectorSpecularDirection)
        .addProperty("SpecularPower", &GCGlobalLightBase::GetSpecularPower, &GCGlobalLightBase::SetSpecularPower)
        .addProperty("SpecularIndependence", &GCGlobalLightBase::GetSpecularIndependence, &GCGlobalLightBase::SetSpecularIndependence)
        .addProperty("SpecularColor", &GCGlobalLightBase::GetSpecularColor, &GCGlobalLightBase::SetSpecularColor)
        .addProperty("StartDisabled", &GCGlobalLightBase::GetStartDisabled, &GCGlobalLightBase::SetStartDisabled)
        .addProperty("Enabled", &GCGlobalLightBase::GetEnabled, &GCGlobalLightBase::SetEnabled)
        .addProperty("LightColor", &GCGlobalLightBase::GetLightColor, &GCGlobalLightBase::SetLightColor)
        .addProperty("AmbientColor1", &GCGlobalLightBase::GetAmbientColor1, &GCGlobalLightBase::SetAmbientColor1)
        .addProperty("AmbientColor2", &GCGlobalLightBase::GetAmbientColor2, &GCGlobalLightBase::SetAmbientColor2)
        .addProperty("AmbientColor3", &GCGlobalLightBase::GetAmbientColor3, &GCGlobalLightBase::SetAmbientColor3)
        .addProperty("SunDistance", &GCGlobalLightBase::GetSunDistance, &GCGlobalLightBase::SetSunDistance)
        .addProperty("FOV", &GCGlobalLightBase::GetFOV, &GCGlobalLightBase::SetFOV)
        .addProperty("NearZ", &GCGlobalLightBase::GetNearZ, &GCGlobalLightBase::SetNearZ)
        .addProperty("FarZ", &GCGlobalLightBase::GetFarZ, &GCGlobalLightBase::SetFarZ)
        .addProperty("EnableShadows", &GCGlobalLightBase::GetEnableShadows, &GCGlobalLightBase::SetEnableShadows)
        .addProperty("OldEnableShadows", &GCGlobalLightBase::GetOldEnableShadows, &GCGlobalLightBase::SetOldEnableShadows)
        .addProperty("BackgroundClearNotRequired", &GCGlobalLightBase::GetBackgroundClearNotRequired, &GCGlobalLightBase::SetBackgroundClearNotRequired)
        .addProperty("CloudScale", &GCGlobalLightBase::GetCloudScale, &GCGlobalLightBase::SetCloudScale)
        .addProperty("Cloud1Speed", &GCGlobalLightBase::GetCloud1Speed, &GCGlobalLightBase::SetCloud1Speed)
        .addProperty("Cloud1Direction", &GCGlobalLightBase::GetCloud1Direction, &GCGlobalLightBase::SetCloud1Direction)
        .addProperty("Cloud2Speed", &GCGlobalLightBase::GetCloud2Speed, &GCGlobalLightBase::SetCloud2Speed)
        .addProperty("Cloud2Direction", &GCGlobalLightBase::GetCloud2Direction, &GCGlobalLightBase::SetCloud2Direction)
        .addProperty("AmbientScale1", &GCGlobalLightBase::GetAmbientScale1, &GCGlobalLightBase::SetAmbientScale1)
        .addProperty("AmbientScale2", &GCGlobalLightBase::GetAmbientScale2, &GCGlobalLightBase::SetAmbientScale2)
        .addProperty("GroundScale", &GCGlobalLightBase::GetGroundScale, &GCGlobalLightBase::SetGroundScale)
        .addProperty("LightScale", &GCGlobalLightBase::GetLightScale, &GCGlobalLightBase::SetLightScale)
        .addProperty("FoWDarkness", &GCGlobalLightBase::GetFoWDarkness, &GCGlobalLightBase::SetFoWDarkness)
        .addProperty("EnableSeparateSkyboxFog", &GCGlobalLightBase::GetEnableSeparateSkyboxFog, &GCGlobalLightBase::SetEnableSeparateSkyboxFog)
        .addProperty("FowColor", &GCGlobalLightBase::GetFowColor, &GCGlobalLightBase::SetFowColor)
        .addProperty("ViewOrigin", &GCGlobalLightBase::GetViewOrigin, &GCGlobalLightBase::SetViewOrigin)
        .addProperty("ViewAngles", &GCGlobalLightBase::GetViewAngles, &GCGlobalLightBase::SetViewAngles)
        .addProperty("ViewFoV", &GCGlobalLightBase::GetViewFoV, &GCGlobalLightBase::SetViewFoV)
        .addProperty("WorldPoints", &GCGlobalLightBase::GetWorldPoints, &GCGlobalLightBase::SetWorldPoints)
        .addProperty("FogOffsetLayer0", &GCGlobalLightBase::GetFogOffsetLayer0, &GCGlobalLightBase::SetFogOffsetLayer0)
        .addProperty("FogOffsetLayer1", &GCGlobalLightBase::GetFogOffsetLayer1, &GCGlobalLightBase::SetFogOffsetLayer1)
        .addFunction("ToPtr", &GCGlobalLightBase::ToPtr)
        .addFunction("IsValid", &GCGlobalLightBase::IsValid)
        .endClass();
}