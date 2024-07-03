#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBarnLight::GCBarnLight(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBarnLight::GCBarnLight(void *ptr) {
    m_ptr = ptr;
}
bool GCBarnLight::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CBarnLight", "m_bEnabled");
}
void GCBarnLight::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_bEnabled", false, value);
}
int32_t GCBarnLight::GetColorMode() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nColorMode");
}
void GCBarnLight::SetColorMode(int32_t value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_nColorMode", false, value);
}
Color GCBarnLight::GetColor() const {
    return GetSchemaValue<Color>(m_ptr, "CBarnLight", "m_Color");
}
void GCBarnLight::SetColor(Color value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_Color", false, value);
}
float GCBarnLight::GetColorTemperature() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flColorTemperature");
}
void GCBarnLight::SetColorTemperature(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flColorTemperature", false, value);
}
float GCBarnLight::GetBrightness() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flBrightness");
}
void GCBarnLight::SetBrightness(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flBrightness", false, value);
}
float GCBarnLight::GetBrightnessScale() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flBrightnessScale");
}
void GCBarnLight::SetBrightnessScale(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flBrightnessScale", false, value);
}
int32_t GCBarnLight::GetDirectLight() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nDirectLight");
}
void GCBarnLight::SetDirectLight(int32_t value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_nDirectLight", false, value);
}
int32_t GCBarnLight::GetBakedShadowIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nBakedShadowIndex");
}
void GCBarnLight::SetBakedShadowIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_nBakedShadowIndex", false, value);
}
int32_t GCBarnLight::GetLuminaireShape() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nLuminaireShape");
}
void GCBarnLight::SetLuminaireShape(int32_t value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_nLuminaireShape", false, value);
}
float GCBarnLight::GetLuminaireSize() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flLuminaireSize");
}
void GCBarnLight::SetLuminaireSize(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flLuminaireSize", false, value);
}
float GCBarnLight::GetLuminaireAnisotropy() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flLuminaireAnisotropy");
}
void GCBarnLight::SetLuminaireAnisotropy(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flLuminaireAnisotropy", false, value);
}
std::string GCBarnLight::GetLightStyleString() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBarnLight", "m_LightStyleString").Get();
}
void GCBarnLight::SetLightStyleString(std::string value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_LightStyleString", false, CUtlString(value.c_str()));
}
float GCBarnLight::GetLightStyleStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flLightStyleStartTime");
}
void GCBarnLight::SetLightStyleStartTime(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flLightStyleStartTime", false, value);
}
std::vector<CUtlString> GCBarnLight::GetQueuedLightStyleStrings() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CBarnLight", "m_QueuedLightStyleStrings"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBarnLight::SetQueuedLightStyleStrings(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CBarnLight", "m_QueuedLightStyleStrings", false, value);
}
std::vector<CUtlString> GCBarnLight::GetLightStyleEvents() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CBarnLight", "m_LightStyleEvents"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBarnLight::SetLightStyleEvents(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CBarnLight", "m_LightStyleEvents", false, value);
}
std::vector<GCBaseModelEntity*> GCBarnLight::GetLightStyleTargets() const {
    CUtlVector<GCBaseModelEntity*>* vec = GetSchemaValue<CUtlVector<GCBaseModelEntity*>*>(m_ptr, "CBarnLight", "m_LightStyleTargets"); std::vector<GCBaseModelEntity*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBarnLight::SetLightStyleTargets(std::vector<GCBaseModelEntity*> value) {
    SetSchemaValueCUtlVector<GCBaseModelEntity*>(m_ptr, "CBarnLight", "m_LightStyleTargets", false, value);
}
std::vector<GCEntityIOOutput> GCBarnLight::GetStyleEvent() const {
    GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CBarnLight", "m_StyleEvent"); std::vector<GCEntityIOOutput> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCBarnLight::SetStyleEvent(std::vector<GCEntityIOOutput> value) {
    GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CBarnLight", "m_StyleEvent"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CBarnLight", "m_StyleEvent", false, outValue);
}
float GCBarnLight::GetShape() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flShape");
}
void GCBarnLight::SetShape(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flShape", false, value);
}
float GCBarnLight::GetSoftX() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flSoftX");
}
void GCBarnLight::SetSoftX(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flSoftX", false, value);
}
float GCBarnLight::GetSoftY() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flSoftY");
}
void GCBarnLight::SetSoftY(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flSoftY", false, value);
}
float GCBarnLight::GetSkirt() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flSkirt");
}
void GCBarnLight::SetSkirt(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flSkirt", false, value);
}
float GCBarnLight::GetSkirtNear() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flSkirtNear");
}
void GCBarnLight::SetSkirtNear(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flSkirtNear", false, value);
}
Vector GCBarnLight::GetSizeParams() const {
    return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vSizeParams");
}
void GCBarnLight::SetSizeParams(Vector value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_vSizeParams", false, value);
}
float GCBarnLight::GetRange() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flRange");
}
void GCBarnLight::SetRange(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flRange", false, value);
}
Vector GCBarnLight::GetShear() const {
    return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vShear");
}
void GCBarnLight::SetShear(Vector value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_vShear", false, value);
}
int32_t GCBarnLight::GetBakeSpecularToCubemaps() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nBakeSpecularToCubemaps");
}
void GCBarnLight::SetBakeSpecularToCubemaps(int32_t value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_nBakeSpecularToCubemaps", false, value);
}
Vector GCBarnLight::GetBakeSpecularToCubemapsSize() const {
    return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vBakeSpecularToCubemapsSize");
}
void GCBarnLight::SetBakeSpecularToCubemapsSize(Vector value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_vBakeSpecularToCubemapsSize", false, value);
}
int32_t GCBarnLight::GetCastShadows() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nCastShadows");
}
void GCBarnLight::SetCastShadows(int32_t value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_nCastShadows", false, value);
}
int32_t GCBarnLight::GetShadowMapSize() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nShadowMapSize");
}
void GCBarnLight::SetShadowMapSize(int32_t value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_nShadowMapSize", false, value);
}
int32_t GCBarnLight::GetShadowPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nShadowPriority");
}
void GCBarnLight::SetShadowPriority(int32_t value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_nShadowPriority", false, value);
}
bool GCBarnLight::GetContactShadow() const {
    return GetSchemaValue<bool>(m_ptr, "CBarnLight", "m_bContactShadow");
}
void GCBarnLight::SetContactShadow(bool value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_bContactShadow", false, value);
}
int32_t GCBarnLight::GetBounceLight() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nBounceLight");
}
void GCBarnLight::SetBounceLight(int32_t value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_nBounceLight", false, value);
}
float GCBarnLight::GetBounceScale() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flBounceScale");
}
void GCBarnLight::SetBounceScale(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flBounceScale", false, value);
}
float GCBarnLight::GetMinRoughness() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flMinRoughness");
}
void GCBarnLight::SetMinRoughness(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flMinRoughness", false, value);
}
Vector GCBarnLight::GetAlternateColor() const {
    return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vAlternateColor");
}
void GCBarnLight::SetAlternateColor(Vector value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_vAlternateColor", false, value);
}
float GCBarnLight::GetAlternateColorBrightness() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_fAlternateColorBrightness");
}
void GCBarnLight::SetAlternateColorBrightness(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_fAlternateColorBrightness", false, value);
}
int32_t GCBarnLight::GetFog() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nFog");
}
void GCBarnLight::SetFog(int32_t value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_nFog", false, value);
}
float GCBarnLight::GetFogStrength() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flFogStrength");
}
void GCBarnLight::SetFogStrength(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flFogStrength", false, value);
}
int32_t GCBarnLight::GetFogShadows() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nFogShadows");
}
void GCBarnLight::SetFogShadows(int32_t value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_nFogShadows", false, value);
}
float GCBarnLight::GetFogScale() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flFogScale");
}
void GCBarnLight::SetFogScale(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flFogScale", false, value);
}
float GCBarnLight::GetFadeSizeStart() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flFadeSizeStart");
}
void GCBarnLight::SetFadeSizeStart(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flFadeSizeStart", false, value);
}
float GCBarnLight::GetFadeSizeEnd() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flFadeSizeEnd");
}
void GCBarnLight::SetFadeSizeEnd(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flFadeSizeEnd", false, value);
}
float GCBarnLight::GetShadowFadeSizeStart() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flShadowFadeSizeStart");
}
void GCBarnLight::SetShadowFadeSizeStart(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flShadowFadeSizeStart", false, value);
}
float GCBarnLight::GetShadowFadeSizeEnd() const {
    return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flShadowFadeSizeEnd");
}
void GCBarnLight::SetShadowFadeSizeEnd(float value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_flShadowFadeSizeEnd", false, value);
}
bool GCBarnLight::GetPrecomputedFieldsValid() const {
    return GetSchemaValue<bool>(m_ptr, "CBarnLight", "m_bPrecomputedFieldsValid");
}
void GCBarnLight::SetPrecomputedFieldsValid(bool value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_bPrecomputedFieldsValid", false, value);
}
Vector GCBarnLight::GetPrecomputedBoundsMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vPrecomputedBoundsMins");
}
void GCBarnLight::SetPrecomputedBoundsMins(Vector value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_vPrecomputedBoundsMins", false, value);
}
Vector GCBarnLight::GetPrecomputedBoundsMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vPrecomputedBoundsMaxs");
}
void GCBarnLight::SetPrecomputedBoundsMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_vPrecomputedBoundsMaxs", false, value);
}
Vector GCBarnLight::GetPrecomputedOBBOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vPrecomputedOBBOrigin");
}
void GCBarnLight::SetPrecomputedOBBOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_vPrecomputedOBBOrigin", false, value);
}
QAngle GCBarnLight::GetPrecomputedOBBAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBarnLight", "m_vPrecomputedOBBAngles");
}
void GCBarnLight::SetPrecomputedOBBAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_vPrecomputedOBBAngles", false, value);
}
Vector GCBarnLight::GetPrecomputedOBBExtent() const {
    return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vPrecomputedOBBExtent");
}
void GCBarnLight::SetPrecomputedOBBExtent(Vector value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_vPrecomputedOBBExtent", false, value);
}
bool GCBarnLight::GetPvsModifyEntity() const {
    return GetSchemaValue<bool>(m_ptr, "CBarnLight", "m_bPvsModifyEntity");
}
void GCBarnLight::SetPvsModifyEntity(bool value) {
    SetSchemaValue(m_ptr, "CBarnLight", "m_bPvsModifyEntity", false, value);
}
std::string GCBarnLight::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBarnLight::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCBarnLight::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCBarnLight::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBarnLight(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBarnLight>("CBarnLight")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Enabled", &GCBarnLight::GetEnabled, &GCBarnLight::SetEnabled)
        .addProperty("ColorMode", &GCBarnLight::GetColorMode, &GCBarnLight::SetColorMode)
        .addProperty("Color", &GCBarnLight::GetColor, &GCBarnLight::SetColor)
        .addProperty("ColorTemperature", &GCBarnLight::GetColorTemperature, &GCBarnLight::SetColorTemperature)
        .addProperty("Brightness", &GCBarnLight::GetBrightness, &GCBarnLight::SetBrightness)
        .addProperty("BrightnessScale", &GCBarnLight::GetBrightnessScale, &GCBarnLight::SetBrightnessScale)
        .addProperty("DirectLight", &GCBarnLight::GetDirectLight, &GCBarnLight::SetDirectLight)
        .addProperty("BakedShadowIndex", &GCBarnLight::GetBakedShadowIndex, &GCBarnLight::SetBakedShadowIndex)
        .addProperty("LuminaireShape", &GCBarnLight::GetLuminaireShape, &GCBarnLight::SetLuminaireShape)
        .addProperty("LuminaireSize", &GCBarnLight::GetLuminaireSize, &GCBarnLight::SetLuminaireSize)
        .addProperty("LuminaireAnisotropy", &GCBarnLight::GetLuminaireAnisotropy, &GCBarnLight::SetLuminaireAnisotropy)
        .addProperty("LightStyleString", &GCBarnLight::GetLightStyleString, &GCBarnLight::SetLightStyleString)
        .addProperty("LightStyleStartTime", &GCBarnLight::GetLightStyleStartTime, &GCBarnLight::SetLightStyleStartTime)
        .addProperty("QueuedLightStyleStrings", &GCBarnLight::GetQueuedLightStyleStrings, &GCBarnLight::SetQueuedLightStyleStrings)
        .addProperty("LightStyleEvents", &GCBarnLight::GetLightStyleEvents, &GCBarnLight::SetLightStyleEvents)
        .addProperty("LightStyleTargets", &GCBarnLight::GetLightStyleTargets, &GCBarnLight::SetLightStyleTargets)
        .addProperty("StyleEvent", &GCBarnLight::GetStyleEvent, &GCBarnLight::SetStyleEvent)
        .addProperty("Shape", &GCBarnLight::GetShape, &GCBarnLight::SetShape)
        .addProperty("SoftX", &GCBarnLight::GetSoftX, &GCBarnLight::SetSoftX)
        .addProperty("SoftY", &GCBarnLight::GetSoftY, &GCBarnLight::SetSoftY)
        .addProperty("Skirt", &GCBarnLight::GetSkirt, &GCBarnLight::SetSkirt)
        .addProperty("SkirtNear", &GCBarnLight::GetSkirtNear, &GCBarnLight::SetSkirtNear)
        .addProperty("SizeParams", &GCBarnLight::GetSizeParams, &GCBarnLight::SetSizeParams)
        .addProperty("Range", &GCBarnLight::GetRange, &GCBarnLight::SetRange)
        .addProperty("Shear", &GCBarnLight::GetShear, &GCBarnLight::SetShear)
        .addProperty("BakeSpecularToCubemaps", &GCBarnLight::GetBakeSpecularToCubemaps, &GCBarnLight::SetBakeSpecularToCubemaps)
        .addProperty("BakeSpecularToCubemapsSize", &GCBarnLight::GetBakeSpecularToCubemapsSize, &GCBarnLight::SetBakeSpecularToCubemapsSize)
        .addProperty("CastShadows", &GCBarnLight::GetCastShadows, &GCBarnLight::SetCastShadows)
        .addProperty("ShadowMapSize", &GCBarnLight::GetShadowMapSize, &GCBarnLight::SetShadowMapSize)
        .addProperty("ShadowPriority", &GCBarnLight::GetShadowPriority, &GCBarnLight::SetShadowPriority)
        .addProperty("ContactShadow", &GCBarnLight::GetContactShadow, &GCBarnLight::SetContactShadow)
        .addProperty("BounceLight", &GCBarnLight::GetBounceLight, &GCBarnLight::SetBounceLight)
        .addProperty("BounceScale", &GCBarnLight::GetBounceScale, &GCBarnLight::SetBounceScale)
        .addProperty("MinRoughness", &GCBarnLight::GetMinRoughness, &GCBarnLight::SetMinRoughness)
        .addProperty("AlternateColor", &GCBarnLight::GetAlternateColor, &GCBarnLight::SetAlternateColor)
        .addProperty("AlternateColorBrightness", &GCBarnLight::GetAlternateColorBrightness, &GCBarnLight::SetAlternateColorBrightness)
        .addProperty("Fog", &GCBarnLight::GetFog, &GCBarnLight::SetFog)
        .addProperty("FogStrength", &GCBarnLight::GetFogStrength, &GCBarnLight::SetFogStrength)
        .addProperty("FogShadows", &GCBarnLight::GetFogShadows, &GCBarnLight::SetFogShadows)
        .addProperty("FogScale", &GCBarnLight::GetFogScale, &GCBarnLight::SetFogScale)
        .addProperty("FadeSizeStart", &GCBarnLight::GetFadeSizeStart, &GCBarnLight::SetFadeSizeStart)
        .addProperty("FadeSizeEnd", &GCBarnLight::GetFadeSizeEnd, &GCBarnLight::SetFadeSizeEnd)
        .addProperty("ShadowFadeSizeStart", &GCBarnLight::GetShadowFadeSizeStart, &GCBarnLight::SetShadowFadeSizeStart)
        .addProperty("ShadowFadeSizeEnd", &GCBarnLight::GetShadowFadeSizeEnd, &GCBarnLight::SetShadowFadeSizeEnd)
        .addProperty("PrecomputedFieldsValid", &GCBarnLight::GetPrecomputedFieldsValid, &GCBarnLight::SetPrecomputedFieldsValid)
        .addProperty("PrecomputedBoundsMins", &GCBarnLight::GetPrecomputedBoundsMins, &GCBarnLight::SetPrecomputedBoundsMins)
        .addProperty("PrecomputedBoundsMaxs", &GCBarnLight::GetPrecomputedBoundsMaxs, &GCBarnLight::SetPrecomputedBoundsMaxs)
        .addProperty("PrecomputedOBBOrigin", &GCBarnLight::GetPrecomputedOBBOrigin, &GCBarnLight::SetPrecomputedOBBOrigin)
        .addProperty("PrecomputedOBBAngles", &GCBarnLight::GetPrecomputedOBBAngles, &GCBarnLight::SetPrecomputedOBBAngles)
        .addProperty("PrecomputedOBBExtent", &GCBarnLight::GetPrecomputedOBBExtent, &GCBarnLight::SetPrecomputedOBBExtent)
        .addProperty("PvsModifyEntity", &GCBarnLight::GetPvsModifyEntity, &GCBarnLight::SetPvsModifyEntity)
        .addProperty("Parent", &GCBarnLight::GetParent, &GCBarnLight::SetParent)
        .addFunction("ToPtr", &GCBarnLight::ToPtr)
        .addFunction("IsValid", &GCBarnLight::IsValid)
        .endClass();
}