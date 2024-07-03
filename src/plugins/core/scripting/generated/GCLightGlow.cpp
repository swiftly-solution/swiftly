#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLightGlow::GCLightGlow(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLightGlow::GCLightGlow(void *ptr) {
    m_ptr = ptr;
}
uint32_t GCLightGlow::GetHorizontalSize() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CLightGlow", "m_nHorizontalSize");
}
void GCLightGlow::SetHorizontalSize(uint32_t value) {
    SetSchemaValue(m_ptr, "CLightGlow", "m_nHorizontalSize", false, value);
}
uint32_t GCLightGlow::GetVerticalSize() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CLightGlow", "m_nVerticalSize");
}
void GCLightGlow::SetVerticalSize(uint32_t value) {
    SetSchemaValue(m_ptr, "CLightGlow", "m_nVerticalSize", false, value);
}
uint32_t GCLightGlow::GetMinDist() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CLightGlow", "m_nMinDist");
}
void GCLightGlow::SetMinDist(uint32_t value) {
    SetSchemaValue(m_ptr, "CLightGlow", "m_nMinDist", false, value);
}
uint32_t GCLightGlow::GetMaxDist() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CLightGlow", "m_nMaxDist");
}
void GCLightGlow::SetMaxDist(uint32_t value) {
    SetSchemaValue(m_ptr, "CLightGlow", "m_nMaxDist", false, value);
}
uint32_t GCLightGlow::GetOuterMaxDist() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CLightGlow", "m_nOuterMaxDist");
}
void GCLightGlow::SetOuterMaxDist(uint32_t value) {
    SetSchemaValue(m_ptr, "CLightGlow", "m_nOuterMaxDist", false, value);
}
float GCLightGlow::GetGlowProxySize() const {
    return GetSchemaValue<float>(m_ptr, "CLightGlow", "m_flGlowProxySize");
}
void GCLightGlow::SetGlowProxySize(float value) {
    SetSchemaValue(m_ptr, "CLightGlow", "m_flGlowProxySize", false, value);
}
float GCLightGlow::GetHDRColorScale() const {
    return GetSchemaValue<float>(m_ptr, "CLightGlow", "m_flHDRColorScale");
}
void GCLightGlow::SetHDRColorScale(float value) {
    SetSchemaValue(m_ptr, "CLightGlow", "m_flHDRColorScale", false, value);
}
std::string GCLightGlow::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLightGlow::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCLightGlow::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCLightGlow::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLightGlow(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightGlow>("CLightGlow")
        .addConstructor<void (*)(std::string)>()
        .addProperty("HorizontalSize", &GCLightGlow::GetHorizontalSize, &GCLightGlow::SetHorizontalSize)
        .addProperty("VerticalSize", &GCLightGlow::GetVerticalSize, &GCLightGlow::SetVerticalSize)
        .addProperty("MinDist", &GCLightGlow::GetMinDist, &GCLightGlow::SetMinDist)
        .addProperty("MaxDist", &GCLightGlow::GetMaxDist, &GCLightGlow::SetMaxDist)
        .addProperty("OuterMaxDist", &GCLightGlow::GetOuterMaxDist, &GCLightGlow::SetOuterMaxDist)
        .addProperty("GlowProxySize", &GCLightGlow::GetGlowProxySize, &GCLightGlow::SetGlowProxySize)
        .addProperty("HDRColorScale", &GCLightGlow::GetHDRColorScale, &GCLightGlow::SetHDRColorScale)
        .addProperty("Parent", &GCLightGlow::GetParent, &GCLightGlow::SetParent)
        .addFunction("ToPtr", &GCLightGlow::ToPtr)
        .addFunction("IsValid", &GCLightGlow::IsValid)
        .endClass();
}