#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvDecal::GCEnvDecal(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvDecal::GCEnvDecal(void *ptr) {
    m_ptr = ptr;
}
float GCEnvDecal::GetWidth() const {
    return GetSchemaValue<float>(m_ptr, "CEnvDecal", "m_flWidth");
}
void GCEnvDecal::SetWidth(float value) {
    SetSchemaValue(m_ptr, "CEnvDecal", "m_flWidth", false, value);
}
float GCEnvDecal::GetHeight() const {
    return GetSchemaValue<float>(m_ptr, "CEnvDecal", "m_flHeight");
}
void GCEnvDecal::SetHeight(float value) {
    SetSchemaValue(m_ptr, "CEnvDecal", "m_flHeight", false, value);
}
float GCEnvDecal::GetDepth() const {
    return GetSchemaValue<float>(m_ptr, "CEnvDecal", "m_flDepth");
}
void GCEnvDecal::SetDepth(float value) {
    SetSchemaValue(m_ptr, "CEnvDecal", "m_flDepth", false, value);
}
uint32_t GCEnvDecal::GetRenderOrder() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEnvDecal", "m_nRenderOrder");
}
void GCEnvDecal::SetRenderOrder(uint32_t value) {
    SetSchemaValue(m_ptr, "CEnvDecal", "m_nRenderOrder", false, value);
}
bool GCEnvDecal::GetProjectOnWorld() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvDecal", "m_bProjectOnWorld");
}
void GCEnvDecal::SetProjectOnWorld(bool value) {
    SetSchemaValue(m_ptr, "CEnvDecal", "m_bProjectOnWorld", false, value);
}
bool GCEnvDecal::GetProjectOnCharacters() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvDecal", "m_bProjectOnCharacters");
}
void GCEnvDecal::SetProjectOnCharacters(bool value) {
    SetSchemaValue(m_ptr, "CEnvDecal", "m_bProjectOnCharacters", false, value);
}
bool GCEnvDecal::GetProjectOnWater() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvDecal", "m_bProjectOnWater");
}
void GCEnvDecal::SetProjectOnWater(bool value) {
    SetSchemaValue(m_ptr, "CEnvDecal", "m_bProjectOnWater", false, value);
}
float GCEnvDecal::GetDepthSortBias() const {
    return GetSchemaValue<float>(m_ptr, "CEnvDecal", "m_flDepthSortBias");
}
void GCEnvDecal::SetDepthSortBias(float value) {
    SetSchemaValue(m_ptr, "CEnvDecal", "m_flDepthSortBias", false, value);
}
std::string GCEnvDecal::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvDecal::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCEnvDecal::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCEnvDecal::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvDecal(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvDecal>("CEnvDecal")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Width", &GCEnvDecal::GetWidth, &GCEnvDecal::SetWidth)
        .addProperty("Height", &GCEnvDecal::GetHeight, &GCEnvDecal::SetHeight)
        .addProperty("Depth", &GCEnvDecal::GetDepth, &GCEnvDecal::SetDepth)
        .addProperty("RenderOrder", &GCEnvDecal::GetRenderOrder, &GCEnvDecal::SetRenderOrder)
        .addProperty("ProjectOnWorld", &GCEnvDecal::GetProjectOnWorld, &GCEnvDecal::SetProjectOnWorld)
        .addProperty("ProjectOnCharacters", &GCEnvDecal::GetProjectOnCharacters, &GCEnvDecal::SetProjectOnCharacters)
        .addProperty("ProjectOnWater", &GCEnvDecal::GetProjectOnWater, &GCEnvDecal::SetProjectOnWater)
        .addProperty("DepthSortBias", &GCEnvDecal::GetDepthSortBias, &GCEnvDecal::SetDepthSortBias)
        .addProperty("Parent", &GCEnvDecal::GetParent, &GCEnvDecal::SetParent)
        .addFunction("ToPtr", &GCEnvDecal::ToPtr)
        .addFunction("IsValid", &GCEnvDecal::IsValid)
        .endClass();
}