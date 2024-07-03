#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvParticleGlow::GCEnvParticleGlow(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvParticleGlow::GCEnvParticleGlow(void *ptr) {
    m_ptr = ptr;
}
float GCEnvParticleGlow::GetAlphaScale() const {
    return GetSchemaValue<float>(m_ptr, "CEnvParticleGlow", "m_flAlphaScale");
}
void GCEnvParticleGlow::SetAlphaScale(float value) {
    SetSchemaValue(m_ptr, "CEnvParticleGlow", "m_flAlphaScale", false, value);
}
float GCEnvParticleGlow::GetRadiusScale() const {
    return GetSchemaValue<float>(m_ptr, "CEnvParticleGlow", "m_flRadiusScale");
}
void GCEnvParticleGlow::SetRadiusScale(float value) {
    SetSchemaValue(m_ptr, "CEnvParticleGlow", "m_flRadiusScale", false, value);
}
float GCEnvParticleGlow::GetSelfIllumScale() const {
    return GetSchemaValue<float>(m_ptr, "CEnvParticleGlow", "m_flSelfIllumScale");
}
void GCEnvParticleGlow::SetSelfIllumScale(float value) {
    SetSchemaValue(m_ptr, "CEnvParticleGlow", "m_flSelfIllumScale", false, value);
}
Color GCEnvParticleGlow::GetColorTint() const {
    return GetSchemaValue<Color>(m_ptr, "CEnvParticleGlow", "m_ColorTint");
}
void GCEnvParticleGlow::SetColorTint(Color value) {
    SetSchemaValue(m_ptr, "CEnvParticleGlow", "m_ColorTint", false, value);
}
std::string GCEnvParticleGlow::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvParticleGlow::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleSystem GCEnvParticleGlow::GetParent() const {
    GCParticleSystem value(m_ptr);
    return value;
}
void GCEnvParticleGlow::SetParent(GCParticleSystem value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvParticleGlow(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvParticleGlow>("CEnvParticleGlow")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AlphaScale", &GCEnvParticleGlow::GetAlphaScale, &GCEnvParticleGlow::SetAlphaScale)
        .addProperty("RadiusScale", &GCEnvParticleGlow::GetRadiusScale, &GCEnvParticleGlow::SetRadiusScale)
        .addProperty("SelfIllumScale", &GCEnvParticleGlow::GetSelfIllumScale, &GCEnvParticleGlow::SetSelfIllumScale)
        .addProperty("ColorTint", &GCEnvParticleGlow::GetColorTint, &GCEnvParticleGlow::SetColorTint)
        .addProperty("Parent", &GCEnvParticleGlow::GetParent, &GCEnvParticleGlow::SetParent)
        .addFunction("ToPtr", &GCEnvParticleGlow::ToPtr)
        .addFunction("IsValid", &GCEnvParticleGlow::IsValid)
        .endClass();
}