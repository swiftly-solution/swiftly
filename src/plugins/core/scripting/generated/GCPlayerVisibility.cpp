#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayerVisibility::GCPlayerVisibility(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayerVisibility::GCPlayerVisibility(void *ptr) {
    m_ptr = ptr;
}
float GCPlayerVisibility::GetVisibilityStrength() const {
    return GetSchemaValue<float>(m_ptr, "CPlayerVisibility", "m_flVisibilityStrength");
}
void GCPlayerVisibility::SetVisibilityStrength(float value) {
    SetSchemaValue(m_ptr, "CPlayerVisibility", "m_flVisibilityStrength", false, value);
}
float GCPlayerVisibility::GetFogDistanceMultiplier() const {
    return GetSchemaValue<float>(m_ptr, "CPlayerVisibility", "m_flFogDistanceMultiplier");
}
void GCPlayerVisibility::SetFogDistanceMultiplier(float value) {
    SetSchemaValue(m_ptr, "CPlayerVisibility", "m_flFogDistanceMultiplier", false, value);
}
float GCPlayerVisibility::GetFogMaxDensityMultiplier() const {
    return GetSchemaValue<float>(m_ptr, "CPlayerVisibility", "m_flFogMaxDensityMultiplier");
}
void GCPlayerVisibility::SetFogMaxDensityMultiplier(float value) {
    SetSchemaValue(m_ptr, "CPlayerVisibility", "m_flFogMaxDensityMultiplier", false, value);
}
float GCPlayerVisibility::GetFadeTime() const {
    return GetSchemaValue<float>(m_ptr, "CPlayerVisibility", "m_flFadeTime");
}
void GCPlayerVisibility::SetFadeTime(float value) {
    SetSchemaValue(m_ptr, "CPlayerVisibility", "m_flFadeTime", false, value);
}
bool GCPlayerVisibility::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPlayerVisibility", "m_bStartDisabled");
}
void GCPlayerVisibility::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CPlayerVisibility", "m_bStartDisabled", false, value);
}
bool GCPlayerVisibility::GetIsEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPlayerVisibility", "m_bIsEnabled");
}
void GCPlayerVisibility::SetIsEnabled(bool value) {
    SetSchemaValue(m_ptr, "CPlayerVisibility", "m_bIsEnabled", false, value);
}
std::string GCPlayerVisibility::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayerVisibility::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCPlayerVisibility::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCPlayerVisibility::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayerVisibility(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerVisibility>("CPlayerVisibility")
        .addConstructor<void (*)(std::string)>()
        .addProperty("VisibilityStrength", &GCPlayerVisibility::GetVisibilityStrength, &GCPlayerVisibility::SetVisibilityStrength)
        .addProperty("FogDistanceMultiplier", &GCPlayerVisibility::GetFogDistanceMultiplier, &GCPlayerVisibility::SetFogDistanceMultiplier)
        .addProperty("FogMaxDensityMultiplier", &GCPlayerVisibility::GetFogMaxDensityMultiplier, &GCPlayerVisibility::SetFogMaxDensityMultiplier)
        .addProperty("FadeTime", &GCPlayerVisibility::GetFadeTime, &GCPlayerVisibility::SetFadeTime)
        .addProperty("StartDisabled", &GCPlayerVisibility::GetStartDisabled, &GCPlayerVisibility::SetStartDisabled)
        .addProperty("IsEnabled", &GCPlayerVisibility::GetIsEnabled, &GCPlayerVisibility::SetIsEnabled)
        .addProperty("Parent", &GCPlayerVisibility::GetParent, &GCPlayerVisibility::SetParent)
        .addFunction("ToPtr", &GCPlayerVisibility::ToPtr)
        .addFunction("IsValid", &GCPlayerVisibility::IsValid)
        .endClass();
}