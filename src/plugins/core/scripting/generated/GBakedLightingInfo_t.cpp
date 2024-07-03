#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GBakedLightingInfo_t::GBakedLightingInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GBakedLightingInfo_t::GBakedLightingInfo_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GBakedLightingInfo_t::GetLightmapVersionNumber() const {
    return GetSchemaValue<uint32_t>(m_ptr, "BakedLightingInfo_t", "m_nLightmapVersionNumber");
}
void GBakedLightingInfo_t::SetLightmapVersionNumber(uint32_t value) {
    SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_nLightmapVersionNumber", true, value);
}
uint32_t GBakedLightingInfo_t::GetLightmapGameVersionNumber() const {
    return GetSchemaValue<uint32_t>(m_ptr, "BakedLightingInfo_t", "m_nLightmapGameVersionNumber");
}
void GBakedLightingInfo_t::SetLightmapGameVersionNumber(uint32_t value) {
    SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_nLightmapGameVersionNumber", true, value);
}
Vector2D GBakedLightingInfo_t::GetLightmapUvScale() const {
    return GetSchemaValue<Vector2D>(m_ptr, "BakedLightingInfo_t", "m_vLightmapUvScale");
}
void GBakedLightingInfo_t::SetLightmapUvScale(Vector2D value) {
    SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_vLightmapUvScale", true, value);
}
bool GBakedLightingInfo_t::GetHasLightmaps() const {
    return GetSchemaValue<bool>(m_ptr, "BakedLightingInfo_t", "m_bHasLightmaps");
}
void GBakedLightingInfo_t::SetHasLightmaps(bool value) {
    SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_bHasLightmaps", true, value);
}
bool GBakedLightingInfo_t::GetBakedShadowsGamma20() const {
    return GetSchemaValue<bool>(m_ptr, "BakedLightingInfo_t", "m_bBakedShadowsGamma20");
}
void GBakedLightingInfo_t::SetBakedShadowsGamma20(bool value) {
    SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_bBakedShadowsGamma20", true, value);
}
bool GBakedLightingInfo_t::GetCompressionEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "BakedLightingInfo_t", "m_bCompressionEnabled");
}
void GBakedLightingInfo_t::SetCompressionEnabled(bool value) {
    SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_bCompressionEnabled", true, value);
}
uint8_t GBakedLightingInfo_t::GetChartPackIterations() const {
    return GetSchemaValue<uint8_t>(m_ptr, "BakedLightingInfo_t", "m_nChartPackIterations");
}
void GBakedLightingInfo_t::SetChartPackIterations(uint8_t value) {
    SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_nChartPackIterations", true, value);
}
uint8_t GBakedLightingInfo_t::GetVradQuality() const {
    return GetSchemaValue<uint8_t>(m_ptr, "BakedLightingInfo_t", "m_nVradQuality");
}
void GBakedLightingInfo_t::SetVradQuality(uint8_t value) {
    SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_nVradQuality", true, value);
}
std::string GBakedLightingInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GBakedLightingInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassBakedLightingInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GBakedLightingInfo_t>("BakedLightingInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LightmapVersionNumber", &GBakedLightingInfo_t::GetLightmapVersionNumber, &GBakedLightingInfo_t::SetLightmapVersionNumber)
        .addProperty("LightmapGameVersionNumber", &GBakedLightingInfo_t::GetLightmapGameVersionNumber, &GBakedLightingInfo_t::SetLightmapGameVersionNumber)
        .addProperty("LightmapUvScale", &GBakedLightingInfo_t::GetLightmapUvScale, &GBakedLightingInfo_t::SetLightmapUvScale)
        .addProperty("HasLightmaps", &GBakedLightingInfo_t::GetHasLightmaps, &GBakedLightingInfo_t::SetHasLightmaps)
        .addProperty("BakedShadowsGamma20", &GBakedLightingInfo_t::GetBakedShadowsGamma20, &GBakedLightingInfo_t::SetBakedShadowsGamma20)
        .addProperty("CompressionEnabled", &GBakedLightingInfo_t::GetCompressionEnabled, &GBakedLightingInfo_t::SetCompressionEnabled)
        .addProperty("ChartPackIterations", &GBakedLightingInfo_t::GetChartPackIterations, &GBakedLightingInfo_t::SetChartPackIterations)
        .addProperty("VradQuality", &GBakedLightingInfo_t::GetVradQuality, &GBakedLightingInfo_t::SetVradQuality)
        .addFunction("ToPtr", &GBakedLightingInfo_t::ToPtr)
        .addFunction("IsValid", &GBakedLightingInfo_t::IsValid)
        .endClass();
}