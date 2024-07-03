#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMultiLightProxy::GCMultiLightProxy(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMultiLightProxy::GCMultiLightProxy(void *ptr) {
    m_ptr = ptr;
}
std::string GCMultiLightProxy::GetLightNameFilter() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMultiLightProxy", "m_iszLightNameFilter").String();
}
void GCMultiLightProxy::SetLightNameFilter(std::string value) {
    SetSchemaValue(m_ptr, "CMultiLightProxy", "m_iszLightNameFilter", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCMultiLightProxy::GetLightClassFilter() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMultiLightProxy", "m_iszLightClassFilter").String();
}
void GCMultiLightProxy::SetLightClassFilter(std::string value) {
    SetSchemaValue(m_ptr, "CMultiLightProxy", "m_iszLightClassFilter", false, CUtlSymbolLarge(value.c_str()));
}
float GCMultiLightProxy::GetLightRadiusFilter() const {
    return GetSchemaValue<float>(m_ptr, "CMultiLightProxy", "m_flLightRadiusFilter");
}
void GCMultiLightProxy::SetLightRadiusFilter(float value) {
    SetSchemaValue(m_ptr, "CMultiLightProxy", "m_flLightRadiusFilter", false, value);
}
float GCMultiLightProxy::GetBrightnessDelta() const {
    return GetSchemaValue<float>(m_ptr, "CMultiLightProxy", "m_flBrightnessDelta");
}
void GCMultiLightProxy::SetBrightnessDelta(float value) {
    SetSchemaValue(m_ptr, "CMultiLightProxy", "m_flBrightnessDelta", false, value);
}
bool GCMultiLightProxy::GetPerformScreenFade() const {
    return GetSchemaValue<bool>(m_ptr, "CMultiLightProxy", "m_bPerformScreenFade");
}
void GCMultiLightProxy::SetPerformScreenFade(bool value) {
    SetSchemaValue(m_ptr, "CMultiLightProxy", "m_bPerformScreenFade", false, value);
}
float GCMultiLightProxy::GetTargetBrightnessMultiplier() const {
    return GetSchemaValue<float>(m_ptr, "CMultiLightProxy", "m_flTargetBrightnessMultiplier");
}
void GCMultiLightProxy::SetTargetBrightnessMultiplier(float value) {
    SetSchemaValue(m_ptr, "CMultiLightProxy", "m_flTargetBrightnessMultiplier", false, value);
}
float GCMultiLightProxy::GetCurrentBrightnessMultiplier() const {
    return GetSchemaValue<float>(m_ptr, "CMultiLightProxy", "m_flCurrentBrightnessMultiplier");
}
void GCMultiLightProxy::SetCurrentBrightnessMultiplier(float value) {
    SetSchemaValue(m_ptr, "CMultiLightProxy", "m_flCurrentBrightnessMultiplier", false, value);
}
std::string GCMultiLightProxy::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMultiLightProxy::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCMultiLightProxy::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCMultiLightProxy::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMultiLightProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMultiLightProxy>("CMultiLightProxy")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LightNameFilter", &GCMultiLightProxy::GetLightNameFilter, &GCMultiLightProxy::SetLightNameFilter)
        .addProperty("LightClassFilter", &GCMultiLightProxy::GetLightClassFilter, &GCMultiLightProxy::SetLightClassFilter)
        .addProperty("LightRadiusFilter", &GCMultiLightProxy::GetLightRadiusFilter, &GCMultiLightProxy::SetLightRadiusFilter)
        .addProperty("BrightnessDelta", &GCMultiLightProxy::GetBrightnessDelta, &GCMultiLightProxy::SetBrightnessDelta)
        .addProperty("PerformScreenFade", &GCMultiLightProxy::GetPerformScreenFade, &GCMultiLightProxy::SetPerformScreenFade)
        .addProperty("TargetBrightnessMultiplier", &GCMultiLightProxy::GetTargetBrightnessMultiplier, &GCMultiLightProxy::SetTargetBrightnessMultiplier)
        .addProperty("CurrentBrightnessMultiplier", &GCMultiLightProxy::GetCurrentBrightnessMultiplier, &GCMultiLightProxy::SetCurrentBrightnessMultiplier)
        .addProperty("Parent", &GCMultiLightProxy::GetParent, &GCMultiLightProxy::SetParent)
        .addFunction("ToPtr", &GCMultiLightProxy::ToPtr)
        .addFunction("IsValid", &GCMultiLightProxy::IsValid)
        .endClass();
}