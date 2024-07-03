#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GHullFlags_t::GHullFlags_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GHullFlags_t::GHullFlags_t(void *ptr) {
    m_ptr = ptr;
}
bool GHullFlags_t::GetHull_Human() const {
    return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_Human");
}
void GHullFlags_t::SetHull_Human(bool value) {
    SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_Human", true, value);
}
bool GHullFlags_t::GetHull_SmallCentered() const {
    return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_SmallCentered");
}
void GHullFlags_t::SetHull_SmallCentered(bool value) {
    SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_SmallCentered", true, value);
}
bool GHullFlags_t::GetHull_WideHuman() const {
    return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_WideHuman");
}
void GHullFlags_t::SetHull_WideHuman(bool value) {
    SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_WideHuman", true, value);
}
bool GHullFlags_t::GetHull_Tiny() const {
    return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_Tiny");
}
void GHullFlags_t::SetHull_Tiny(bool value) {
    SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_Tiny", true, value);
}
bool GHullFlags_t::GetHull_Medium() const {
    return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_Medium");
}
void GHullFlags_t::SetHull_Medium(bool value) {
    SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_Medium", true, value);
}
bool GHullFlags_t::GetHull_TinyCentered() const {
    return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_TinyCentered");
}
void GHullFlags_t::SetHull_TinyCentered(bool value) {
    SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_TinyCentered", true, value);
}
bool GHullFlags_t::GetHull_Large() const {
    return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_Large");
}
void GHullFlags_t::SetHull_Large(bool value) {
    SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_Large", true, value);
}
bool GHullFlags_t::GetHull_LargeCentered() const {
    return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_LargeCentered");
}
void GHullFlags_t::SetHull_LargeCentered(bool value) {
    SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_LargeCentered", true, value);
}
bool GHullFlags_t::GetHull_MediumTall() const {
    return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_MediumTall");
}
void GHullFlags_t::SetHull_MediumTall(bool value) {
    SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_MediumTall", true, value);
}
bool GHullFlags_t::GetHull_Small() const {
    return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_Small");
}
void GHullFlags_t::SetHull_Small(bool value) {
    SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_Small", true, value);
}
std::string GHullFlags_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GHullFlags_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassHullFlags_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GHullFlags_t>("HullFlags_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Hull_Human", &GHullFlags_t::GetHull_Human, &GHullFlags_t::SetHull_Human)
        .addProperty("Hull_SmallCentered", &GHullFlags_t::GetHull_SmallCentered, &GHullFlags_t::SetHull_SmallCentered)
        .addProperty("Hull_WideHuman", &GHullFlags_t::GetHull_WideHuman, &GHullFlags_t::SetHull_WideHuman)
        .addProperty("Hull_Tiny", &GHullFlags_t::GetHull_Tiny, &GHullFlags_t::SetHull_Tiny)
        .addProperty("Hull_Medium", &GHullFlags_t::GetHull_Medium, &GHullFlags_t::SetHull_Medium)
        .addProperty("Hull_TinyCentered", &GHullFlags_t::GetHull_TinyCentered, &GHullFlags_t::SetHull_TinyCentered)
        .addProperty("Hull_Large", &GHullFlags_t::GetHull_Large, &GHullFlags_t::SetHull_Large)
        .addProperty("Hull_LargeCentered", &GHullFlags_t::GetHull_LargeCentered, &GHullFlags_t::SetHull_LargeCentered)
        .addProperty("Hull_MediumTall", &GHullFlags_t::GetHull_MediumTall, &GHullFlags_t::SetHull_MediumTall)
        .addProperty("Hull_Small", &GHullFlags_t::GetHull_Small, &GHullFlags_t::SetHull_Small)
        .addFunction("ToPtr", &GHullFlags_t::ToPtr)
        .addFunction("IsValid", &GHullFlags_t::IsValid)
        .endClass();
}