#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvCubemapFog::GCEnvCubemapFog(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvCubemapFog::GCEnvCubemapFog(void *ptr) {
    m_ptr = ptr;
}
float GCEnvCubemapFog::GetEndDistance() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flEndDistance");
}
void GCEnvCubemapFog::SetEndDistance(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flEndDistance", false, value);
}
float GCEnvCubemapFog::GetStartDistance() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flStartDistance");
}
void GCEnvCubemapFog::SetStartDistance(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flStartDistance", false, value);
}
float GCEnvCubemapFog::GetFogFalloffExponent() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogFalloffExponent");
}
void GCEnvCubemapFog::SetFogFalloffExponent(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogFalloffExponent", false, value);
}
bool GCEnvCubemapFog::GetHeightFogEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemapFog", "m_bHeightFogEnabled");
}
void GCEnvCubemapFog::SetHeightFogEnabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_bHeightFogEnabled", false, value);
}
float GCEnvCubemapFog::GetFogHeightWidth() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogHeightWidth");
}
void GCEnvCubemapFog::SetFogHeightWidth(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogHeightWidth", false, value);
}
float GCEnvCubemapFog::GetFogHeightEnd() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogHeightEnd");
}
void GCEnvCubemapFog::SetFogHeightEnd(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogHeightEnd", false, value);
}
float GCEnvCubemapFog::GetFogHeightStart() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogHeightStart");
}
void GCEnvCubemapFog::SetFogHeightStart(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogHeightStart", false, value);
}
float GCEnvCubemapFog::GetFogHeightExponent() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogHeightExponent");
}
void GCEnvCubemapFog::SetFogHeightExponent(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogHeightExponent", false, value);
}
float GCEnvCubemapFog::GetLODBias() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flLODBias");
}
void GCEnvCubemapFog::SetLODBias(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flLODBias", false, value);
}
bool GCEnvCubemapFog::GetActive() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemapFog", "m_bActive");
}
void GCEnvCubemapFog::SetActive(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_bActive", false, value);
}
bool GCEnvCubemapFog::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemapFog", "m_bStartDisabled");
}
void GCEnvCubemapFog::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_bStartDisabled", false, value);
}
float GCEnvCubemapFog::GetFogMaxOpacity() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogMaxOpacity");
}
void GCEnvCubemapFog::SetFogMaxOpacity(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogMaxOpacity", false, value);
}
int32_t GCEnvCubemapFog::GetCubemapSourceType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCubemapFog", "m_nCubemapSourceType");
}
void GCEnvCubemapFog::SetCubemapSourceType(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_nCubemapSourceType", false, value);
}
std::string GCEnvCubemapFog::GetSkyEntity() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvCubemapFog", "m_iszSkyEntity").String();
}
void GCEnvCubemapFog::SetSkyEntity(std::string value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_iszSkyEntity", false, CUtlSymbolLarge(value.c_str()));
}
bool GCEnvCubemapFog::GetHasHeightFogEnd() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemapFog", "m_bHasHeightFogEnd");
}
void GCEnvCubemapFog::SetHasHeightFogEnd(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_bHasHeightFogEnd", false, value);
}
bool GCEnvCubemapFog::GetFirstTime() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemapFog", "m_bFirstTime");
}
void GCEnvCubemapFog::SetFirstTime(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_bFirstTime", false, value);
}
std::string GCEnvCubemapFog::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvCubemapFog::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvCubemapFog::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvCubemapFog::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvCubemapFog(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvCubemapFog>("CEnvCubemapFog")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EndDistance", &GCEnvCubemapFog::GetEndDistance, &GCEnvCubemapFog::SetEndDistance)
        .addProperty("StartDistance", &GCEnvCubemapFog::GetStartDistance, &GCEnvCubemapFog::SetStartDistance)
        .addProperty("FogFalloffExponent", &GCEnvCubemapFog::GetFogFalloffExponent, &GCEnvCubemapFog::SetFogFalloffExponent)
        .addProperty("HeightFogEnabled", &GCEnvCubemapFog::GetHeightFogEnabled, &GCEnvCubemapFog::SetHeightFogEnabled)
        .addProperty("FogHeightWidth", &GCEnvCubemapFog::GetFogHeightWidth, &GCEnvCubemapFog::SetFogHeightWidth)
        .addProperty("FogHeightEnd", &GCEnvCubemapFog::GetFogHeightEnd, &GCEnvCubemapFog::SetFogHeightEnd)
        .addProperty("FogHeightStart", &GCEnvCubemapFog::GetFogHeightStart, &GCEnvCubemapFog::SetFogHeightStart)
        .addProperty("FogHeightExponent", &GCEnvCubemapFog::GetFogHeightExponent, &GCEnvCubemapFog::SetFogHeightExponent)
        .addProperty("LODBias", &GCEnvCubemapFog::GetLODBias, &GCEnvCubemapFog::SetLODBias)
        .addProperty("Active", &GCEnvCubemapFog::GetActive, &GCEnvCubemapFog::SetActive)
        .addProperty("StartDisabled", &GCEnvCubemapFog::GetStartDisabled, &GCEnvCubemapFog::SetStartDisabled)
        .addProperty("FogMaxOpacity", &GCEnvCubemapFog::GetFogMaxOpacity, &GCEnvCubemapFog::SetFogMaxOpacity)
        .addProperty("CubemapSourceType", &GCEnvCubemapFog::GetCubemapSourceType, &GCEnvCubemapFog::SetCubemapSourceType)
        .addProperty("SkyEntity", &GCEnvCubemapFog::GetSkyEntity, &GCEnvCubemapFog::SetSkyEntity)
        .addProperty("HasHeightFogEnd", &GCEnvCubemapFog::GetHasHeightFogEnd, &GCEnvCubemapFog::SetHasHeightFogEnd)
        .addProperty("FirstTime", &GCEnvCubemapFog::GetFirstTime, &GCEnvCubemapFog::SetFirstTime)
        .addProperty("Parent", &GCEnvCubemapFog::GetParent, &GCEnvCubemapFog::SetParent)
        .addFunction("ToPtr", &GCEnvCubemapFog::ToPtr)
        .addFunction("IsValid", &GCEnvCubemapFog::IsValid)
        .endClass();
}