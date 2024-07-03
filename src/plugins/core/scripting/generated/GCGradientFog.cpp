#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGradientFog::GCGradientFog(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGradientFog::GCGradientFog(void *ptr) {
    m_ptr = ptr;
}
float GCGradientFog::GetFogStartDistance() const {
    return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogStartDistance");
}
void GCGradientFog::SetFogStartDistance(float value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_flFogStartDistance", false, value);
}
float GCGradientFog::GetFogEndDistance() const {
    return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogEndDistance");
}
void GCGradientFog::SetFogEndDistance(float value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_flFogEndDistance", false, value);
}
bool GCGradientFog::GetHeightFogEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CGradientFog", "m_bHeightFogEnabled");
}
void GCGradientFog::SetHeightFogEnabled(bool value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_bHeightFogEnabled", false, value);
}
float GCGradientFog::GetFogStartHeight() const {
    return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogStartHeight");
}
void GCGradientFog::SetFogStartHeight(float value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_flFogStartHeight", false, value);
}
float GCGradientFog::GetFogEndHeight() const {
    return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogEndHeight");
}
void GCGradientFog::SetFogEndHeight(float value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_flFogEndHeight", false, value);
}
float GCGradientFog::GetFarZ() const {
    return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFarZ");
}
void GCGradientFog::SetFarZ(float value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_flFarZ", false, value);
}
float GCGradientFog::GetFogMaxOpacity() const {
    return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogMaxOpacity");
}
void GCGradientFog::SetFogMaxOpacity(float value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_flFogMaxOpacity", false, value);
}
float GCGradientFog::GetFogFalloffExponent() const {
    return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogFalloffExponent");
}
void GCGradientFog::SetFogFalloffExponent(float value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_flFogFalloffExponent", false, value);
}
float GCGradientFog::GetFogVerticalExponent() const {
    return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogVerticalExponent");
}
void GCGradientFog::SetFogVerticalExponent(float value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_flFogVerticalExponent", false, value);
}
Color GCGradientFog::GetFogColor() const {
    return GetSchemaValue<Color>(m_ptr, "CGradientFog", "m_fogColor");
}
void GCGradientFog::SetFogColor(Color value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_fogColor", false, value);
}
float GCGradientFog::GetFogStrength() const {
    return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFogStrength");
}
void GCGradientFog::SetFogStrength(float value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_flFogStrength", false, value);
}
float GCGradientFog::GetFadeTime() const {
    return GetSchemaValue<float>(m_ptr, "CGradientFog", "m_flFadeTime");
}
void GCGradientFog::SetFadeTime(float value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_flFadeTime", false, value);
}
bool GCGradientFog::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CGradientFog", "m_bStartDisabled");
}
void GCGradientFog::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_bStartDisabled", false, value);
}
bool GCGradientFog::GetIsEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CGradientFog", "m_bIsEnabled");
}
void GCGradientFog::SetIsEnabled(bool value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_bIsEnabled", false, value);
}
bool GCGradientFog::GetGradientFogNeedsTextures() const {
    return GetSchemaValue<bool>(m_ptr, "CGradientFog", "m_bGradientFogNeedsTextures");
}
void GCGradientFog::SetGradientFogNeedsTextures(bool value) {
    SetSchemaValue(m_ptr, "CGradientFog", "m_bGradientFogNeedsTextures", false, value);
}
std::string GCGradientFog::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGradientFog::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCGradientFog::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCGradientFog::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGradientFog(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGradientFog>("CGradientFog")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FogStartDistance", &GCGradientFog::GetFogStartDistance, &GCGradientFog::SetFogStartDistance)
        .addProperty("FogEndDistance", &GCGradientFog::GetFogEndDistance, &GCGradientFog::SetFogEndDistance)
        .addProperty("HeightFogEnabled", &GCGradientFog::GetHeightFogEnabled, &GCGradientFog::SetHeightFogEnabled)
        .addProperty("FogStartHeight", &GCGradientFog::GetFogStartHeight, &GCGradientFog::SetFogStartHeight)
        .addProperty("FogEndHeight", &GCGradientFog::GetFogEndHeight, &GCGradientFog::SetFogEndHeight)
        .addProperty("FarZ", &GCGradientFog::GetFarZ, &GCGradientFog::SetFarZ)
        .addProperty("FogMaxOpacity", &GCGradientFog::GetFogMaxOpacity, &GCGradientFog::SetFogMaxOpacity)
        .addProperty("FogFalloffExponent", &GCGradientFog::GetFogFalloffExponent, &GCGradientFog::SetFogFalloffExponent)
        .addProperty("FogVerticalExponent", &GCGradientFog::GetFogVerticalExponent, &GCGradientFog::SetFogVerticalExponent)
        .addProperty("FogColor", &GCGradientFog::GetFogColor, &GCGradientFog::SetFogColor)
        .addProperty("FogStrength", &GCGradientFog::GetFogStrength, &GCGradientFog::SetFogStrength)
        .addProperty("FadeTime", &GCGradientFog::GetFadeTime, &GCGradientFog::SetFadeTime)
        .addProperty("StartDisabled", &GCGradientFog::GetStartDisabled, &GCGradientFog::SetStartDisabled)
        .addProperty("IsEnabled", &GCGradientFog::GetIsEnabled, &GCGradientFog::SetIsEnabled)
        .addProperty("GradientFogNeedsTextures", &GCGradientFog::GetGradientFogNeedsTextures, &GCGradientFog::SetGradientFogNeedsTextures)
        .addProperty("Parent", &GCGradientFog::GetParent, &GCGradientFog::SetParent)
        .addFunction("ToPtr", &GCGradientFog::ToPtr)
        .addFunction("IsValid", &GCGradientFog::IsValid)
        .endClass();
}