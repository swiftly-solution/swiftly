#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLightComponent::GCLightComponent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLightComponent::GCLightComponent(void *ptr) {
    m_ptr = ptr;
}
GCNetworkVarChainer GCLightComponent::Get__pChainEntity() const {
    GCNetworkVarChainer value(GetSchemaPtr(m_ptr, "CLightComponent", "__m_pChainEntity"));
    return value;
}
void GCLightComponent::Set__pChainEntity(GCNetworkVarChainer value) {
    SetSchemaValue(m_ptr, "CLightComponent", "__m_pChainEntity", false, value);
}
Color GCLightComponent::GetColor() const {
    return GetSchemaValue<Color>(m_ptr, "CLightComponent", "m_Color");
}
void GCLightComponent::SetColor(Color value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_Color", false, value);
}
Color GCLightComponent::GetSecondaryColor() const {
    return GetSchemaValue<Color>(m_ptr, "CLightComponent", "m_SecondaryColor");
}
void GCLightComponent::SetSecondaryColor(Color value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_SecondaryColor", false, value);
}
float GCLightComponent::GetBrightness() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flBrightness");
}
void GCLightComponent::SetBrightness(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flBrightness", false, value);
}
float GCLightComponent::GetBrightnessScale() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flBrightnessScale");
}
void GCLightComponent::SetBrightnessScale(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flBrightnessScale", false, value);
}
float GCLightComponent::GetBrightnessMult() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flBrightnessMult");
}
void GCLightComponent::SetBrightnessMult(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flBrightnessMult", false, value);
}
float GCLightComponent::GetRange() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flRange");
}
void GCLightComponent::SetRange(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flRange", false, value);
}
float GCLightComponent::GetFalloff() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flFalloff");
}
void GCLightComponent::SetFalloff(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flFalloff", false, value);
}
float GCLightComponent::GetAttenuation0() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flAttenuation0");
}
void GCLightComponent::SetAttenuation0(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flAttenuation0", false, value);
}
float GCLightComponent::GetAttenuation1() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flAttenuation1");
}
void GCLightComponent::SetAttenuation1(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flAttenuation1", false, value);
}
float GCLightComponent::GetAttenuation2() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flAttenuation2");
}
void GCLightComponent::SetAttenuation2(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flAttenuation2", false, value);
}
float GCLightComponent::GetTheta() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flTheta");
}
void GCLightComponent::SetTheta(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flTheta", false, value);
}
float GCLightComponent::GetPhi() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flPhi");
}
void GCLightComponent::SetPhi(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flPhi", false, value);
}
int32_t GCLightComponent::GetCascades() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nCascades");
}
void GCLightComponent::SetCascades(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nCascades", false, value);
}
int32_t GCLightComponent::GetCastShadows() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nCastShadows");
}
void GCLightComponent::SetCastShadows(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nCastShadows", false, value);
}
int32_t GCLightComponent::GetShadowWidth() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowWidth");
}
void GCLightComponent::SetShadowWidth(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowWidth", false, value);
}
int32_t GCLightComponent::GetShadowHeight() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowHeight");
}
void GCLightComponent::SetShadowHeight(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowHeight", false, value);
}
bool GCLightComponent::GetRenderDiffuse() const {
    return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bRenderDiffuse");
}
void GCLightComponent::SetRenderDiffuse(bool value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_bRenderDiffuse", false, value);
}
int32_t GCLightComponent::GetRenderSpecular() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nRenderSpecular");
}
void GCLightComponent::SetRenderSpecular(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nRenderSpecular", false, value);
}
bool GCLightComponent::GetRenderTransmissive() const {
    return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bRenderTransmissive");
}
void GCLightComponent::SetRenderTransmissive(bool value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_bRenderTransmissive", false, value);
}
float GCLightComponent::GetOrthoLightWidth() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flOrthoLightWidth");
}
void GCLightComponent::SetOrthoLightWidth(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flOrthoLightWidth", false, value);
}
float GCLightComponent::GetOrthoLightHeight() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flOrthoLightHeight");
}
void GCLightComponent::SetOrthoLightHeight(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flOrthoLightHeight", false, value);
}
int32_t GCLightComponent::GetStyle() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nStyle");
}
void GCLightComponent::SetStyle(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nStyle", false, value);
}
std::string GCLightComponent::GetPattern() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CLightComponent", "m_Pattern").Get();
}
void GCLightComponent::SetPattern(std::string value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_Pattern", false, CUtlString(value.c_str()));
}
int32_t GCLightComponent::GetCascadeRenderStaticObjects() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nCascadeRenderStaticObjects");
}
void GCLightComponent::SetCascadeRenderStaticObjects(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nCascadeRenderStaticObjects", false, value);
}
float GCLightComponent::GetShadowCascadeCrossFade() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeCrossFade");
}
void GCLightComponent::SetShadowCascadeCrossFade(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeCrossFade", false, value);
}
float GCLightComponent::GetShadowCascadeDistanceFade() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeDistanceFade");
}
void GCLightComponent::SetShadowCascadeDistanceFade(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeDistanceFade", false, value);
}
float GCLightComponent::GetShadowCascadeDistance0() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeDistance0");
}
void GCLightComponent::SetShadowCascadeDistance0(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeDistance0", false, value);
}
float GCLightComponent::GetShadowCascadeDistance1() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeDistance1");
}
void GCLightComponent::SetShadowCascadeDistance1(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeDistance1", false, value);
}
float GCLightComponent::GetShadowCascadeDistance2() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeDistance2");
}
void GCLightComponent::SetShadowCascadeDistance2(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeDistance2", false, value);
}
float GCLightComponent::GetShadowCascadeDistance3() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeDistance3");
}
void GCLightComponent::SetShadowCascadeDistance3(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeDistance3", false, value);
}
int32_t GCLightComponent::GetShadowCascadeResolution0() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowCascadeResolution0");
}
void GCLightComponent::SetShadowCascadeResolution0(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowCascadeResolution0", false, value);
}
int32_t GCLightComponent::GetShadowCascadeResolution1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowCascadeResolution1");
}
void GCLightComponent::SetShadowCascadeResolution1(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowCascadeResolution1", false, value);
}
int32_t GCLightComponent::GetShadowCascadeResolution2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowCascadeResolution2");
}
void GCLightComponent::SetShadowCascadeResolution2(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowCascadeResolution2", false, value);
}
int32_t GCLightComponent::GetShadowCascadeResolution3() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowCascadeResolution3");
}
void GCLightComponent::SetShadowCascadeResolution3(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowCascadeResolution3", false, value);
}
bool GCLightComponent::GetUsesBakedShadowing() const {
    return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bUsesBakedShadowing");
}
void GCLightComponent::SetUsesBakedShadowing(bool value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_bUsesBakedShadowing", false, value);
}
int32_t GCLightComponent::GetShadowPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowPriority");
}
void GCLightComponent::SetShadowPriority(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowPriority", false, value);
}
int32_t GCLightComponent::GetBakedShadowIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nBakedShadowIndex");
}
void GCLightComponent::SetBakedShadowIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nBakedShadowIndex", false, value);
}
bool GCLightComponent::GetRenderToCubemaps() const {
    return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bRenderToCubemaps");
}
void GCLightComponent::SetRenderToCubemaps(bool value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_bRenderToCubemaps", false, value);
}
int32_t GCLightComponent::GetDirectLight() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nDirectLight");
}
void GCLightComponent::SetDirectLight(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nDirectLight", false, value);
}
int32_t GCLightComponent::GetIndirectLight() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nIndirectLight");
}
void GCLightComponent::SetIndirectLight(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nIndirectLight", false, value);
}
float GCLightComponent::GetFadeMinDist() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flFadeMinDist");
}
void GCLightComponent::SetFadeMinDist(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flFadeMinDist", false, value);
}
float GCLightComponent::GetFadeMaxDist() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flFadeMaxDist");
}
void GCLightComponent::SetFadeMaxDist(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flFadeMaxDist", false, value);
}
float GCLightComponent::GetShadowFadeMinDist() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowFadeMinDist");
}
void GCLightComponent::SetShadowFadeMinDist(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowFadeMinDist", false, value);
}
float GCLightComponent::GetShadowFadeMaxDist() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowFadeMaxDist");
}
void GCLightComponent::SetShadowFadeMaxDist(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowFadeMaxDist", false, value);
}
bool GCLightComponent::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bEnabled");
}
void GCLightComponent::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_bEnabled", false, value);
}
bool GCLightComponent::GetFlicker() const {
    return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bFlicker");
}
void GCLightComponent::SetFlicker(bool value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_bFlicker", false, value);
}
bool GCLightComponent::GetPrecomputedFieldsValid() const {
    return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bPrecomputedFieldsValid");
}
void GCLightComponent::SetPrecomputedFieldsValid(bool value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_bPrecomputedFieldsValid", false, value);
}
Vector GCLightComponent::GetPrecomputedBoundsMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CLightComponent", "m_vPrecomputedBoundsMins");
}
void GCLightComponent::SetPrecomputedBoundsMins(Vector value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_vPrecomputedBoundsMins", false, value);
}
Vector GCLightComponent::GetPrecomputedBoundsMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CLightComponent", "m_vPrecomputedBoundsMaxs");
}
void GCLightComponent::SetPrecomputedBoundsMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_vPrecomputedBoundsMaxs", false, value);
}
Vector GCLightComponent::GetPrecomputedOBBOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CLightComponent", "m_vPrecomputedOBBOrigin");
}
void GCLightComponent::SetPrecomputedOBBOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_vPrecomputedOBBOrigin", false, value);
}
QAngle GCLightComponent::GetPrecomputedOBBAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CLightComponent", "m_vPrecomputedOBBAngles");
}
void GCLightComponent::SetPrecomputedOBBAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_vPrecomputedOBBAngles", false, value);
}
Vector GCLightComponent::GetPrecomputedOBBExtent() const {
    return GetSchemaValue<Vector>(m_ptr, "CLightComponent", "m_vPrecomputedOBBExtent");
}
void GCLightComponent::SetPrecomputedOBBExtent(Vector value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_vPrecomputedOBBExtent", false, value);
}
float GCLightComponent::GetPrecomputedMaxRange() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flPrecomputedMaxRange");
}
void GCLightComponent::SetPrecomputedMaxRange(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flPrecomputedMaxRange", false, value);
}
int32_t GCLightComponent::GetFogLightingMode() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nFogLightingMode");
}
void GCLightComponent::SetFogLightingMode(int32_t value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_nFogLightingMode", false, value);
}
float GCLightComponent::GetFogContributionStength() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flFogContributionStength");
}
void GCLightComponent::SetFogContributionStength(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flFogContributionStength", false, value);
}
float GCLightComponent::GetNearClipPlane() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flNearClipPlane");
}
void GCLightComponent::SetNearClipPlane(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flNearClipPlane", false, value);
}
Color GCLightComponent::GetSkyColor() const {
    return GetSchemaValue<Color>(m_ptr, "CLightComponent", "m_SkyColor");
}
void GCLightComponent::SetSkyColor(Color value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_SkyColor", false, value);
}
float GCLightComponent::GetSkyIntensity() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flSkyIntensity");
}
void GCLightComponent::SetSkyIntensity(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flSkyIntensity", false, value);
}
Color GCLightComponent::GetSkyAmbientBounce() const {
    return GetSchemaValue<Color>(m_ptr, "CLightComponent", "m_SkyAmbientBounce");
}
void GCLightComponent::SetSkyAmbientBounce(Color value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_SkyAmbientBounce", false, value);
}
bool GCLightComponent::GetUseSecondaryColor() const {
    return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bUseSecondaryColor");
}
void GCLightComponent::SetUseSecondaryColor(bool value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_bUseSecondaryColor", false, value);
}
bool GCLightComponent::GetMixedShadows() const {
    return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bMixedShadows");
}
void GCLightComponent::SetMixedShadows(bool value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_bMixedShadows", false, value);
}
float GCLightComponent::GetLightStyleStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flLightStyleStartTime");
}
void GCLightComponent::SetLightStyleStartTime(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flLightStyleStartTime", false, value);
}
float GCLightComponent::GetCapsuleLength() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flCapsuleLength");
}
void GCLightComponent::SetCapsuleLength(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flCapsuleLength", false, value);
}
float GCLightComponent::GetMinRoughness() const {
    return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flMinRoughness");
}
void GCLightComponent::SetMinRoughness(float value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_flMinRoughness", false, value);
}
bool GCLightComponent::GetPvsModifyEntity() const {
    return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bPvsModifyEntity");
}
void GCLightComponent::SetPvsModifyEntity(bool value) {
    SetSchemaValue(m_ptr, "CLightComponent", "m_bPvsModifyEntity", false, value);
}
std::string GCLightComponent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLightComponent::IsValid() {
    return (m_ptr != nullptr);
}
GCEntityComponent GCLightComponent::GetParent() const {
    GCEntityComponent value(m_ptr);
    return value;
}
void GCLightComponent::SetParent(GCEntityComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLightComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightComponent>("CLightComponent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("__pChainEntity", &GCLightComponent::Get__pChainEntity, &GCLightComponent::Set__pChainEntity)
        .addProperty("Color", &GCLightComponent::GetColor, &GCLightComponent::SetColor)
        .addProperty("SecondaryColor", &GCLightComponent::GetSecondaryColor, &GCLightComponent::SetSecondaryColor)
        .addProperty("Brightness", &GCLightComponent::GetBrightness, &GCLightComponent::SetBrightness)
        .addProperty("BrightnessScale", &GCLightComponent::GetBrightnessScale, &GCLightComponent::SetBrightnessScale)
        .addProperty("BrightnessMult", &GCLightComponent::GetBrightnessMult, &GCLightComponent::SetBrightnessMult)
        .addProperty("Range", &GCLightComponent::GetRange, &GCLightComponent::SetRange)
        .addProperty("Falloff", &GCLightComponent::GetFalloff, &GCLightComponent::SetFalloff)
        .addProperty("Attenuation0", &GCLightComponent::GetAttenuation0, &GCLightComponent::SetAttenuation0)
        .addProperty("Attenuation1", &GCLightComponent::GetAttenuation1, &GCLightComponent::SetAttenuation1)
        .addProperty("Attenuation2", &GCLightComponent::GetAttenuation2, &GCLightComponent::SetAttenuation2)
        .addProperty("Theta", &GCLightComponent::GetTheta, &GCLightComponent::SetTheta)
        .addProperty("Phi", &GCLightComponent::GetPhi, &GCLightComponent::SetPhi)
        .addProperty("Cascades", &GCLightComponent::GetCascades, &GCLightComponent::SetCascades)
        .addProperty("CastShadows", &GCLightComponent::GetCastShadows, &GCLightComponent::SetCastShadows)
        .addProperty("ShadowWidth", &GCLightComponent::GetShadowWidth, &GCLightComponent::SetShadowWidth)
        .addProperty("ShadowHeight", &GCLightComponent::GetShadowHeight, &GCLightComponent::SetShadowHeight)
        .addProperty("RenderDiffuse", &GCLightComponent::GetRenderDiffuse, &GCLightComponent::SetRenderDiffuse)
        .addProperty("RenderSpecular", &GCLightComponent::GetRenderSpecular, &GCLightComponent::SetRenderSpecular)
        .addProperty("RenderTransmissive", &GCLightComponent::GetRenderTransmissive, &GCLightComponent::SetRenderTransmissive)
        .addProperty("OrthoLightWidth", &GCLightComponent::GetOrthoLightWidth, &GCLightComponent::SetOrthoLightWidth)
        .addProperty("OrthoLightHeight", &GCLightComponent::GetOrthoLightHeight, &GCLightComponent::SetOrthoLightHeight)
        .addProperty("Style", &GCLightComponent::GetStyle, &GCLightComponent::SetStyle)
        .addProperty("Pattern", &GCLightComponent::GetPattern, &GCLightComponent::SetPattern)
        .addProperty("CascadeRenderStaticObjects", &GCLightComponent::GetCascadeRenderStaticObjects, &GCLightComponent::SetCascadeRenderStaticObjects)
        .addProperty("ShadowCascadeCrossFade", &GCLightComponent::GetShadowCascadeCrossFade, &GCLightComponent::SetShadowCascadeCrossFade)
        .addProperty("ShadowCascadeDistanceFade", &GCLightComponent::GetShadowCascadeDistanceFade, &GCLightComponent::SetShadowCascadeDistanceFade)
        .addProperty("ShadowCascadeDistance0", &GCLightComponent::GetShadowCascadeDistance0, &GCLightComponent::SetShadowCascadeDistance0)
        .addProperty("ShadowCascadeDistance1", &GCLightComponent::GetShadowCascadeDistance1, &GCLightComponent::SetShadowCascadeDistance1)
        .addProperty("ShadowCascadeDistance2", &GCLightComponent::GetShadowCascadeDistance2, &GCLightComponent::SetShadowCascadeDistance2)
        .addProperty("ShadowCascadeDistance3", &GCLightComponent::GetShadowCascadeDistance3, &GCLightComponent::SetShadowCascadeDistance3)
        .addProperty("ShadowCascadeResolution0", &GCLightComponent::GetShadowCascadeResolution0, &GCLightComponent::SetShadowCascadeResolution0)
        .addProperty("ShadowCascadeResolution1", &GCLightComponent::GetShadowCascadeResolution1, &GCLightComponent::SetShadowCascadeResolution1)
        .addProperty("ShadowCascadeResolution2", &GCLightComponent::GetShadowCascadeResolution2, &GCLightComponent::SetShadowCascadeResolution2)
        .addProperty("ShadowCascadeResolution3", &GCLightComponent::GetShadowCascadeResolution3, &GCLightComponent::SetShadowCascadeResolution3)
        .addProperty("UsesBakedShadowing", &GCLightComponent::GetUsesBakedShadowing, &GCLightComponent::SetUsesBakedShadowing)
        .addProperty("ShadowPriority", &GCLightComponent::GetShadowPriority, &GCLightComponent::SetShadowPriority)
        .addProperty("BakedShadowIndex", &GCLightComponent::GetBakedShadowIndex, &GCLightComponent::SetBakedShadowIndex)
        .addProperty("RenderToCubemaps", &GCLightComponent::GetRenderToCubemaps, &GCLightComponent::SetRenderToCubemaps)
        .addProperty("DirectLight", &GCLightComponent::GetDirectLight, &GCLightComponent::SetDirectLight)
        .addProperty("IndirectLight", &GCLightComponent::GetIndirectLight, &GCLightComponent::SetIndirectLight)
        .addProperty("FadeMinDist", &GCLightComponent::GetFadeMinDist, &GCLightComponent::SetFadeMinDist)
        .addProperty("FadeMaxDist", &GCLightComponent::GetFadeMaxDist, &GCLightComponent::SetFadeMaxDist)
        .addProperty("ShadowFadeMinDist", &GCLightComponent::GetShadowFadeMinDist, &GCLightComponent::SetShadowFadeMinDist)
        .addProperty("ShadowFadeMaxDist", &GCLightComponent::GetShadowFadeMaxDist, &GCLightComponent::SetShadowFadeMaxDist)
        .addProperty("Enabled", &GCLightComponent::GetEnabled, &GCLightComponent::SetEnabled)
        .addProperty("Flicker", &GCLightComponent::GetFlicker, &GCLightComponent::SetFlicker)
        .addProperty("PrecomputedFieldsValid", &GCLightComponent::GetPrecomputedFieldsValid, &GCLightComponent::SetPrecomputedFieldsValid)
        .addProperty("PrecomputedBoundsMins", &GCLightComponent::GetPrecomputedBoundsMins, &GCLightComponent::SetPrecomputedBoundsMins)
        .addProperty("PrecomputedBoundsMaxs", &GCLightComponent::GetPrecomputedBoundsMaxs, &GCLightComponent::SetPrecomputedBoundsMaxs)
        .addProperty("PrecomputedOBBOrigin", &GCLightComponent::GetPrecomputedOBBOrigin, &GCLightComponent::SetPrecomputedOBBOrigin)
        .addProperty("PrecomputedOBBAngles", &GCLightComponent::GetPrecomputedOBBAngles, &GCLightComponent::SetPrecomputedOBBAngles)
        .addProperty("PrecomputedOBBExtent", &GCLightComponent::GetPrecomputedOBBExtent, &GCLightComponent::SetPrecomputedOBBExtent)
        .addProperty("PrecomputedMaxRange", &GCLightComponent::GetPrecomputedMaxRange, &GCLightComponent::SetPrecomputedMaxRange)
        .addProperty("FogLightingMode", &GCLightComponent::GetFogLightingMode, &GCLightComponent::SetFogLightingMode)
        .addProperty("FogContributionStength", &GCLightComponent::GetFogContributionStength, &GCLightComponent::SetFogContributionStength)
        .addProperty("NearClipPlane", &GCLightComponent::GetNearClipPlane, &GCLightComponent::SetNearClipPlane)
        .addProperty("SkyColor", &GCLightComponent::GetSkyColor, &GCLightComponent::SetSkyColor)
        .addProperty("SkyIntensity", &GCLightComponent::GetSkyIntensity, &GCLightComponent::SetSkyIntensity)
        .addProperty("SkyAmbientBounce", &GCLightComponent::GetSkyAmbientBounce, &GCLightComponent::SetSkyAmbientBounce)
        .addProperty("UseSecondaryColor", &GCLightComponent::GetUseSecondaryColor, &GCLightComponent::SetUseSecondaryColor)
        .addProperty("MixedShadows", &GCLightComponent::GetMixedShadows, &GCLightComponent::SetMixedShadows)
        .addProperty("LightStyleStartTime", &GCLightComponent::GetLightStyleStartTime, &GCLightComponent::SetLightStyleStartTime)
        .addProperty("CapsuleLength", &GCLightComponent::GetCapsuleLength, &GCLightComponent::SetCapsuleLength)
        .addProperty("MinRoughness", &GCLightComponent::GetMinRoughness, &GCLightComponent::SetMinRoughness)
        .addProperty("PvsModifyEntity", &GCLightComponent::GetPvsModifyEntity, &GCLightComponent::SetPvsModifyEntity)
        .addProperty("Parent", &GCLightComponent::GetParent, &GCLightComponent::SetParent)
        .addFunction("ToPtr", &GCLightComponent::ToPtr)
        .addFunction("IsValid", &GCLightComponent::IsValid)
        .endClass();
}