#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Ghudtextparms_t::Ghudtextparms_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Ghudtextparms_t::Ghudtextparms_t(void *ptr) {
    m_ptr = ptr;
}
Color Ghudtextparms_t::GetColor1() const {
    return GetSchemaValue<Color>(m_ptr, "hudtextparms_t", "color1");
}
void Ghudtextparms_t::SetColor1(Color value) {
    SetSchemaValue(m_ptr, "hudtextparms_t", "color1", true, value);
}
Color Ghudtextparms_t::GetColor2() const {
    return GetSchemaValue<Color>(m_ptr, "hudtextparms_t", "color2");
}
void Ghudtextparms_t::SetColor2(Color value) {
    SetSchemaValue(m_ptr, "hudtextparms_t", "color2", true, value);
}
uint8_t Ghudtextparms_t::GetEffect() const {
    return GetSchemaValue<uint8_t>(m_ptr, "hudtextparms_t", "effect");
}
void Ghudtextparms_t::SetEffect(uint8_t value) {
    SetSchemaValue(m_ptr, "hudtextparms_t", "effect", true, value);
}
uint8_t Ghudtextparms_t::GetChannel() const {
    return GetSchemaValue<uint8_t>(m_ptr, "hudtextparms_t", "channel");
}
void Ghudtextparms_t::SetChannel(uint8_t value) {
    SetSchemaValue(m_ptr, "hudtextparms_t", "channel", true, value);
}
float Ghudtextparms_t::GetX() const {
    return GetSchemaValue<float>(m_ptr, "hudtextparms_t", "x");
}
void Ghudtextparms_t::SetX(float value) {
    SetSchemaValue(m_ptr, "hudtextparms_t", "x", true, value);
}
float Ghudtextparms_t::GetY() const {
    return GetSchemaValue<float>(m_ptr, "hudtextparms_t", "y");
}
void Ghudtextparms_t::SetY(float value) {
    SetSchemaValue(m_ptr, "hudtextparms_t", "y", true, value);
}
std::string Ghudtextparms_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Ghudtextparms_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClasshudtextparms_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Ghudtextparms_t>("hudtextparms_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Color1", &Ghudtextparms_t::GetColor1, &Ghudtextparms_t::SetColor1)
        .addProperty("Color2", &Ghudtextparms_t::GetColor2, &Ghudtextparms_t::SetColor2)
        .addProperty("Effect", &Ghudtextparms_t::GetEffect, &Ghudtextparms_t::SetEffect)
        .addProperty("Channel", &Ghudtextparms_t::GetChannel, &Ghudtextparms_t::SetChannel)
        .addProperty("X", &Ghudtextparms_t::GetX, &Ghudtextparms_t::SetX)
        .addProperty("Y", &Ghudtextparms_t::GetY, &Ghudtextparms_t::SetY)
        .addFunction("ToPtr", &Ghudtextparms_t::ToPtr)
        .addFunction("IsValid", &Ghudtextparms_t::IsValid)
        .endClass();
}