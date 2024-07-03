#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGlowSprite::GCGlowSprite(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGlowSprite::GCGlowSprite(void *ptr) {
    m_ptr = ptr;
}
Vector GCGlowSprite::GetColor() const {
    return GetSchemaValue<Vector>(m_ptr, "CGlowSprite", "m_vColor");
}
void GCGlowSprite::SetColor(Vector value) {
    SetSchemaValue(m_ptr, "CGlowSprite", "m_vColor", false, value);
}
float GCGlowSprite::GetHorzSize() const {
    return GetSchemaValue<float>(m_ptr, "CGlowSprite", "m_flHorzSize");
}
void GCGlowSprite::SetHorzSize(float value) {
    SetSchemaValue(m_ptr, "CGlowSprite", "m_flHorzSize", false, value);
}
float GCGlowSprite::GetVertSize() const {
    return GetSchemaValue<float>(m_ptr, "CGlowSprite", "m_flVertSize");
}
void GCGlowSprite::SetVertSize(float value) {
    SetSchemaValue(m_ptr, "CGlowSprite", "m_flVertSize", false, value);
}
std::string GCGlowSprite::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGlowSprite::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCGlowSprite(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGlowSprite>("CGlowSprite")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Color", &GCGlowSprite::GetColor, &GCGlowSprite::SetColor)
        .addProperty("HorzSize", &GCGlowSprite::GetHorzSize, &GCGlowSprite::SetHorzSize)
        .addProperty("VertSize", &GCGlowSprite::GetVertSize, &GCGlowSprite::SetVertSize)
        .addFunction("ToPtr", &GCGlowSprite::ToPtr)
        .addFunction("IsValid", &GCGlowSprite::IsValid)
        .endClass();
}