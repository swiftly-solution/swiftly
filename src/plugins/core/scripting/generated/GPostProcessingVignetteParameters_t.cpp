#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPostProcessingVignetteParameters_t::GPostProcessingVignetteParameters_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPostProcessingVignetteParameters_t::GPostProcessingVignetteParameters_t(void *ptr) {
    m_ptr = ptr;
}
float GPostProcessingVignetteParameters_t::GetVignetteStrength() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingVignetteParameters_t", "m_flVignetteStrength");
}
void GPostProcessingVignetteParameters_t::SetVignetteStrength(float value) {
    SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_flVignetteStrength", true, value);
}
Vector2D GPostProcessingVignetteParameters_t::GetCenter() const {
    return GetSchemaValue<Vector2D>(m_ptr, "PostProcessingVignetteParameters_t", "m_vCenter");
}
void GPostProcessingVignetteParameters_t::SetCenter(Vector2D value) {
    SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_vCenter", true, value);
}
float GPostProcessingVignetteParameters_t::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingVignetteParameters_t", "m_flRadius");
}
void GPostProcessingVignetteParameters_t::SetRadius(float value) {
    SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_flRadius", true, value);
}
float GPostProcessingVignetteParameters_t::GetRoundness() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingVignetteParameters_t", "m_flRoundness");
}
void GPostProcessingVignetteParameters_t::SetRoundness(float value) {
    SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_flRoundness", true, value);
}
float GPostProcessingVignetteParameters_t::GetFeather() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingVignetteParameters_t", "m_flFeather");
}
void GPostProcessingVignetteParameters_t::SetFeather(float value) {
    SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_flFeather", true, value);
}
Vector GPostProcessingVignetteParameters_t::GetColorTint() const {
    return GetSchemaValue<Vector>(m_ptr, "PostProcessingVignetteParameters_t", "m_vColorTint");
}
void GPostProcessingVignetteParameters_t::SetColorTint(Vector value) {
    SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_vColorTint", true, value);
}
std::string GPostProcessingVignetteParameters_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPostProcessingVignetteParameters_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPostProcessingVignetteParameters_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPostProcessingVignetteParameters_t>("PostProcessingVignetteParameters_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("VignetteStrength", &GPostProcessingVignetteParameters_t::GetVignetteStrength, &GPostProcessingVignetteParameters_t::SetVignetteStrength)
        .addProperty("Center", &GPostProcessingVignetteParameters_t::GetCenter, &GPostProcessingVignetteParameters_t::SetCenter)
        .addProperty("Radius", &GPostProcessingVignetteParameters_t::GetRadius, &GPostProcessingVignetteParameters_t::SetRadius)
        .addProperty("Roundness", &GPostProcessingVignetteParameters_t::GetRoundness, &GPostProcessingVignetteParameters_t::SetRoundness)
        .addProperty("Feather", &GPostProcessingVignetteParameters_t::GetFeather, &GPostProcessingVignetteParameters_t::SetFeather)
        .addProperty("ColorTint", &GPostProcessingVignetteParameters_t::GetColorTint, &GPostProcessingVignetteParameters_t::SetColorTint)
        .addFunction("ToPtr", &GPostProcessingVignetteParameters_t::ToPtr)
        .addFunction("IsValid", &GPostProcessingVignetteParameters_t::IsValid)
        .endClass();
}