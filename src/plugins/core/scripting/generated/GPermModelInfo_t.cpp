#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPermModelInfo_t::GPermModelInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPermModelInfo_t::GPermModelInfo_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GPermModelInfo_t::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "PermModelInfo_t", "m_nFlags");
}
void GPermModelInfo_t::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "PermModelInfo_t", "m_nFlags", true, value);
}
Vector GPermModelInfo_t::GetHullMin() const {
    return GetSchemaValue<Vector>(m_ptr, "PermModelInfo_t", "m_vHullMin");
}
void GPermModelInfo_t::SetHullMin(Vector value) {
    SetSchemaValue(m_ptr, "PermModelInfo_t", "m_vHullMin", true, value);
}
Vector GPermModelInfo_t::GetHullMax() const {
    return GetSchemaValue<Vector>(m_ptr, "PermModelInfo_t", "m_vHullMax");
}
void GPermModelInfo_t::SetHullMax(Vector value) {
    SetSchemaValue(m_ptr, "PermModelInfo_t", "m_vHullMax", true, value);
}
Vector GPermModelInfo_t::GetViewMin() const {
    return GetSchemaValue<Vector>(m_ptr, "PermModelInfo_t", "m_vViewMin");
}
void GPermModelInfo_t::SetViewMin(Vector value) {
    SetSchemaValue(m_ptr, "PermModelInfo_t", "m_vViewMin", true, value);
}
Vector GPermModelInfo_t::GetViewMax() const {
    return GetSchemaValue<Vector>(m_ptr, "PermModelInfo_t", "m_vViewMax");
}
void GPermModelInfo_t::SetViewMax(Vector value) {
    SetSchemaValue(m_ptr, "PermModelInfo_t", "m_vViewMax", true, value);
}
float GPermModelInfo_t::GetMass() const {
    return GetSchemaValue<float>(m_ptr, "PermModelInfo_t", "m_flMass");
}
void GPermModelInfo_t::SetMass(float value) {
    SetSchemaValue(m_ptr, "PermModelInfo_t", "m_flMass", true, value);
}
Vector GPermModelInfo_t::GetEyePosition() const {
    return GetSchemaValue<Vector>(m_ptr, "PermModelInfo_t", "m_vEyePosition");
}
void GPermModelInfo_t::SetEyePosition(Vector value) {
    SetSchemaValue(m_ptr, "PermModelInfo_t", "m_vEyePosition", true, value);
}
float GPermModelInfo_t::GetMaxEyeDeflection() const {
    return GetSchemaValue<float>(m_ptr, "PermModelInfo_t", "m_flMaxEyeDeflection");
}
void GPermModelInfo_t::SetMaxEyeDeflection(float value) {
    SetSchemaValue(m_ptr, "PermModelInfo_t", "m_flMaxEyeDeflection", true, value);
}
std::string GPermModelInfo_t::GetSurfaceProperty() const {
    return GetSchemaValue<CUtlString>(m_ptr, "PermModelInfo_t", "m_sSurfaceProperty").Get();
}
void GPermModelInfo_t::SetSurfaceProperty(std::string value) {
    SetSchemaValue(m_ptr, "PermModelInfo_t", "m_sSurfaceProperty", true, CUtlString(value.c_str()));
}
std::string GPermModelInfo_t::GetKeyValueText() const {
    return GetSchemaValue<CUtlString>(m_ptr, "PermModelInfo_t", "m_keyValueText").Get();
}
void GPermModelInfo_t::SetKeyValueText(std::string value) {
    SetSchemaValue(m_ptr, "PermModelInfo_t", "m_keyValueText", true, CUtlString(value.c_str()));
}
std::string GPermModelInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPermModelInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPermModelInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPermModelInfo_t>("PermModelInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Flags", &GPermModelInfo_t::GetFlags, &GPermModelInfo_t::SetFlags)
        .addProperty("HullMin", &GPermModelInfo_t::GetHullMin, &GPermModelInfo_t::SetHullMin)
        .addProperty("HullMax", &GPermModelInfo_t::GetHullMax, &GPermModelInfo_t::SetHullMax)
        .addProperty("ViewMin", &GPermModelInfo_t::GetViewMin, &GPermModelInfo_t::SetViewMin)
        .addProperty("ViewMax", &GPermModelInfo_t::GetViewMax, &GPermModelInfo_t::SetViewMax)
        .addProperty("Mass", &GPermModelInfo_t::GetMass, &GPermModelInfo_t::SetMass)
        .addProperty("EyePosition", &GPermModelInfo_t::GetEyePosition, &GPermModelInfo_t::SetEyePosition)
        .addProperty("MaxEyeDeflection", &GPermModelInfo_t::GetMaxEyeDeflection, &GPermModelInfo_t::SetMaxEyeDeflection)
        .addProperty("SurfaceProperty", &GPermModelInfo_t::GetSurfaceProperty, &GPermModelInfo_t::SetSurfaceProperty)
        .addProperty("KeyValueText", &GPermModelInfo_t::GetKeyValueText, &GPermModelInfo_t::SetKeyValueText)
        .addFunction("ToPtr", &GPermModelInfo_t::ToPtr)
        .addFunction("IsValid", &GPermModelInfo_t::IsValid)
        .endClass();
}