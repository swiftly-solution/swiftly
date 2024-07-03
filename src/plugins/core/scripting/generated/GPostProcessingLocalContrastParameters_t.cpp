#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPostProcessingLocalContrastParameters_t::GPostProcessingLocalContrastParameters_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPostProcessingLocalContrastParameters_t::GPostProcessingLocalContrastParameters_t(void *ptr) {
    m_ptr = ptr;
}
float GPostProcessingLocalContrastParameters_t::GetLocalContrastStrength() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastStrength");
}
void GPostProcessingLocalContrastParameters_t::SetLocalContrastStrength(float value) {
    SetSchemaValue(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastStrength", true, value);
}
float GPostProcessingLocalContrastParameters_t::GetLocalContrastEdgeStrength() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastEdgeStrength");
}
void GPostProcessingLocalContrastParameters_t::SetLocalContrastEdgeStrength(float value) {
    SetSchemaValue(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastEdgeStrength", true, value);
}
float GPostProcessingLocalContrastParameters_t::GetLocalContrastVignetteStart() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteStart");
}
void GPostProcessingLocalContrastParameters_t::SetLocalContrastVignetteStart(float value) {
    SetSchemaValue(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteStart", true, value);
}
float GPostProcessingLocalContrastParameters_t::GetLocalContrastVignetteEnd() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteEnd");
}
void GPostProcessingLocalContrastParameters_t::SetLocalContrastVignetteEnd(float value) {
    SetSchemaValue(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteEnd", true, value);
}
float GPostProcessingLocalContrastParameters_t::GetLocalContrastVignetteBlur() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteBlur");
}
void GPostProcessingLocalContrastParameters_t::SetLocalContrastVignetteBlur(float value) {
    SetSchemaValue(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteBlur", true, value);
}
std::string GPostProcessingLocalContrastParameters_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPostProcessingLocalContrastParameters_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPostProcessingLocalContrastParameters_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPostProcessingLocalContrastParameters_t>("PostProcessingLocalContrastParameters_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LocalContrastStrength", &GPostProcessingLocalContrastParameters_t::GetLocalContrastStrength, &GPostProcessingLocalContrastParameters_t::SetLocalContrastStrength)
        .addProperty("LocalContrastEdgeStrength", &GPostProcessingLocalContrastParameters_t::GetLocalContrastEdgeStrength, &GPostProcessingLocalContrastParameters_t::SetLocalContrastEdgeStrength)
        .addProperty("LocalContrastVignetteStart", &GPostProcessingLocalContrastParameters_t::GetLocalContrastVignetteStart, &GPostProcessingLocalContrastParameters_t::SetLocalContrastVignetteStart)
        .addProperty("LocalContrastVignetteEnd", &GPostProcessingLocalContrastParameters_t::GetLocalContrastVignetteEnd, &GPostProcessingLocalContrastParameters_t::SetLocalContrastVignetteEnd)
        .addProperty("LocalContrastVignetteBlur", &GPostProcessingLocalContrastParameters_t::GetLocalContrastVignetteBlur, &GPostProcessingLocalContrastParameters_t::SetLocalContrastVignetteBlur)
        .addFunction("ToPtr", &GPostProcessingLocalContrastParameters_t::ToPtr)
        .addFunction("IsValid", &GPostProcessingLocalContrastParameters_t::IsValid)
        .endClass();
}