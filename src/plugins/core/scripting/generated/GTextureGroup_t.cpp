#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GTextureGroup_t::GTextureGroup_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GTextureGroup_t::GTextureGroup_t(void *ptr) {
    m_ptr = ptr;
}
bool GTextureGroup_t::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "TextureGroup_t", "m_bEnabled");
}
void GTextureGroup_t::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "TextureGroup_t", "m_bEnabled", true, value);
}
bool GTextureGroup_t::GetReplaceTextureWithGradient() const {
    return GetSchemaValue<bool>(m_ptr, "TextureGroup_t", "m_bReplaceTextureWithGradient");
}
void GTextureGroup_t::SetReplaceTextureWithGradient(bool value) {
    SetSchemaValue(m_ptr, "TextureGroup_t", "m_bReplaceTextureWithGradient", true, value);
}
uint64_t GTextureGroup_t::GetTextureType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TextureGroup_t", "m_nTextureType");
}
void GTextureGroup_t::SetTextureType(uint64_t value) {
    SetSchemaValue(m_ptr, "TextureGroup_t", "m_nTextureType", true, value);
}
uint64_t GTextureGroup_t::GetTextureChannels() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TextureGroup_t", "m_nTextureChannels");
}
void GTextureGroup_t::SetTextureChannels(uint64_t value) {
    SetSchemaValue(m_ptr, "TextureGroup_t", "m_nTextureChannels", true, value);
}
uint64_t GTextureGroup_t::GetTextureBlendMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TextureGroup_t", "m_nTextureBlendMode");
}
void GTextureGroup_t::SetTextureBlendMode(uint64_t value) {
    SetSchemaValue(m_ptr, "TextureGroup_t", "m_nTextureBlendMode", true, value);
}
GCParticleCollectionRendererFloatInput GTextureGroup_t::GetTextureBlend() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "TextureGroup_t", "m_flTextureBlend"));
    return value;
}
void GTextureGroup_t::SetTextureBlend(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "TextureGroup_t", "m_flTextureBlend", true, value);
}
GTextureControls_t GTextureGroup_t::GetTextureControls() const {
    GTextureControls_t value(GetSchemaPtr(m_ptr, "TextureGroup_t", "m_TextureControls"));
    return value;
}
void GTextureGroup_t::SetTextureControls(GTextureControls_t value) {
    SetSchemaValue(m_ptr, "TextureGroup_t", "m_TextureControls", true, value);
}
std::string GTextureGroup_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GTextureGroup_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassTextureGroup_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTextureGroup_t>("TextureGroup_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Enabled", &GTextureGroup_t::GetEnabled, &GTextureGroup_t::SetEnabled)
        .addProperty("ReplaceTextureWithGradient", &GTextureGroup_t::GetReplaceTextureWithGradient, &GTextureGroup_t::SetReplaceTextureWithGradient)
        .addProperty("TextureType", &GTextureGroup_t::GetTextureType, &GTextureGroup_t::SetTextureType)
        .addProperty("TextureChannels", &GTextureGroup_t::GetTextureChannels, &GTextureGroup_t::SetTextureChannels)
        .addProperty("TextureBlendMode", &GTextureGroup_t::GetTextureBlendMode, &GTextureGroup_t::SetTextureBlendMode)
        .addProperty("TextureBlend", &GTextureGroup_t::GetTextureBlend, &GTextureGroup_t::SetTextureBlend)
        .addProperty("TextureControls", &GTextureGroup_t::GetTextureControls, &GTextureGroup_t::SetTextureControls)
        .addFunction("ToPtr", &GTextureGroup_t::ToPtr)
        .addFunction("IsValid", &GTextureGroup_t::IsValid)
        .endClass();
}