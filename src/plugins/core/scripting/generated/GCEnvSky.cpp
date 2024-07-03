#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvSky::GCEnvSky(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvSky::GCEnvSky(void *ptr) {
    m_ptr = ptr;
}
bool GCEnvSky::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvSky", "m_bStartDisabled");
}
void GCEnvSky::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvSky", "m_bStartDisabled", false, value);
}
Color GCEnvSky::GetTintColor() const {
    return GetSchemaValue<Color>(m_ptr, "CEnvSky", "m_vTintColor");
}
void GCEnvSky::SetTintColor(Color value) {
    SetSchemaValue(m_ptr, "CEnvSky", "m_vTintColor", false, value);
}
Color GCEnvSky::GetTintColorLightingOnly() const {
    return GetSchemaValue<Color>(m_ptr, "CEnvSky", "m_vTintColorLightingOnly");
}
void GCEnvSky::SetTintColorLightingOnly(Color value) {
    SetSchemaValue(m_ptr, "CEnvSky", "m_vTintColorLightingOnly", false, value);
}
float GCEnvSky::GetBrightnessScale() const {
    return GetSchemaValue<float>(m_ptr, "CEnvSky", "m_flBrightnessScale");
}
void GCEnvSky::SetBrightnessScale(float value) {
    SetSchemaValue(m_ptr, "CEnvSky", "m_flBrightnessScale", false, value);
}
int32_t GCEnvSky::GetFogType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvSky", "m_nFogType");
}
void GCEnvSky::SetFogType(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvSky", "m_nFogType", false, value);
}
float GCEnvSky::GetFogMinStart() const {
    return GetSchemaValue<float>(m_ptr, "CEnvSky", "m_flFogMinStart");
}
void GCEnvSky::SetFogMinStart(float value) {
    SetSchemaValue(m_ptr, "CEnvSky", "m_flFogMinStart", false, value);
}
float GCEnvSky::GetFogMinEnd() const {
    return GetSchemaValue<float>(m_ptr, "CEnvSky", "m_flFogMinEnd");
}
void GCEnvSky::SetFogMinEnd(float value) {
    SetSchemaValue(m_ptr, "CEnvSky", "m_flFogMinEnd", false, value);
}
float GCEnvSky::GetFogMaxStart() const {
    return GetSchemaValue<float>(m_ptr, "CEnvSky", "m_flFogMaxStart");
}
void GCEnvSky::SetFogMaxStart(float value) {
    SetSchemaValue(m_ptr, "CEnvSky", "m_flFogMaxStart", false, value);
}
float GCEnvSky::GetFogMaxEnd() const {
    return GetSchemaValue<float>(m_ptr, "CEnvSky", "m_flFogMaxEnd");
}
void GCEnvSky::SetFogMaxEnd(float value) {
    SetSchemaValue(m_ptr, "CEnvSky", "m_flFogMaxEnd", false, value);
}
bool GCEnvSky::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvSky", "m_bEnabled");
}
void GCEnvSky::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvSky", "m_bEnabled", false, value);
}
std::string GCEnvSky::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvSky::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCEnvSky::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCEnvSky::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvSky(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSky>("CEnvSky")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartDisabled", &GCEnvSky::GetStartDisabled, &GCEnvSky::SetStartDisabled)
        .addProperty("TintColor", &GCEnvSky::GetTintColor, &GCEnvSky::SetTintColor)
        .addProperty("TintColorLightingOnly", &GCEnvSky::GetTintColorLightingOnly, &GCEnvSky::SetTintColorLightingOnly)
        .addProperty("BrightnessScale", &GCEnvSky::GetBrightnessScale, &GCEnvSky::SetBrightnessScale)
        .addProperty("FogType", &GCEnvSky::GetFogType, &GCEnvSky::SetFogType)
        .addProperty("FogMinStart", &GCEnvSky::GetFogMinStart, &GCEnvSky::SetFogMinStart)
        .addProperty("FogMinEnd", &GCEnvSky::GetFogMinEnd, &GCEnvSky::SetFogMinEnd)
        .addProperty("FogMaxStart", &GCEnvSky::GetFogMaxStart, &GCEnvSky::SetFogMaxStart)
        .addProperty("FogMaxEnd", &GCEnvSky::GetFogMaxEnd, &GCEnvSky::SetFogMaxEnd)
        .addProperty("Enabled", &GCEnvSky::GetEnabled, &GCEnvSky::SetEnabled)
        .addProperty("Parent", &GCEnvSky::GetParent, &GCEnvSky::SetParent)
        .addFunction("ToPtr", &GCEnvSky::ToPtr)
        .addFunction("IsValid", &GCEnvSky::IsValid)
        .endClass();
}