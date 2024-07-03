#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEntityDissolve::GCEntityDissolve(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEntityDissolve::GCEntityDissolve(void *ptr) {
    m_ptr = ptr;
}
float GCEntityDissolve::GetFadeInStart() const {
    return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeInStart");
}
void GCEntityDissolve::SetFadeInStart(float value) {
    SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeInStart", false, value);
}
float GCEntityDissolve::GetFadeInLength() const {
    return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeInLength");
}
void GCEntityDissolve::SetFadeInLength(float value) {
    SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeInLength", false, value);
}
float GCEntityDissolve::GetFadeOutModelStart() const {
    return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeOutModelStart");
}
void GCEntityDissolve::SetFadeOutModelStart(float value) {
    SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeOutModelStart", false, value);
}
float GCEntityDissolve::GetFadeOutModelLength() const {
    return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeOutModelLength");
}
void GCEntityDissolve::SetFadeOutModelLength(float value) {
    SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeOutModelLength", false, value);
}
float GCEntityDissolve::GetFadeOutStart() const {
    return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeOutStart");
}
void GCEntityDissolve::SetFadeOutStart(float value) {
    SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeOutStart", false, value);
}
float GCEntityDissolve::GetFadeOutLength() const {
    return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeOutLength");
}
void GCEntityDissolve::SetFadeOutLength(float value) {
    SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeOutLength", false, value);
}
float GCEntityDissolve::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flStartTime");
}
void GCEntityDissolve::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CEntityDissolve", "m_flStartTime", false, value);
}
uint64_t GCEntityDissolve::GetDissolveType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CEntityDissolve", "m_nDissolveType");
}
void GCEntityDissolve::SetDissolveType(uint64_t value) {
    SetSchemaValue(m_ptr, "CEntityDissolve", "m_nDissolveType", false, value);
}
Vector GCEntityDissolve::GetDissolverOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CEntityDissolve", "m_vDissolverOrigin");
}
void GCEntityDissolve::SetDissolverOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CEntityDissolve", "m_vDissolverOrigin", false, value);
}
uint32_t GCEntityDissolve::GetMagnitude() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEntityDissolve", "m_nMagnitude");
}
void GCEntityDissolve::SetMagnitude(uint32_t value) {
    SetSchemaValue(m_ptr, "CEntityDissolve", "m_nMagnitude", false, value);
}
std::string GCEntityDissolve::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEntityDissolve::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCEntityDissolve::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCEntityDissolve::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEntityDissolve(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityDissolve>("CEntityDissolve")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FadeInStart", &GCEntityDissolve::GetFadeInStart, &GCEntityDissolve::SetFadeInStart)
        .addProperty("FadeInLength", &GCEntityDissolve::GetFadeInLength, &GCEntityDissolve::SetFadeInLength)
        .addProperty("FadeOutModelStart", &GCEntityDissolve::GetFadeOutModelStart, &GCEntityDissolve::SetFadeOutModelStart)
        .addProperty("FadeOutModelLength", &GCEntityDissolve::GetFadeOutModelLength, &GCEntityDissolve::SetFadeOutModelLength)
        .addProperty("FadeOutStart", &GCEntityDissolve::GetFadeOutStart, &GCEntityDissolve::SetFadeOutStart)
        .addProperty("FadeOutLength", &GCEntityDissolve::GetFadeOutLength, &GCEntityDissolve::SetFadeOutLength)
        .addProperty("StartTime", &GCEntityDissolve::GetStartTime, &GCEntityDissolve::SetStartTime)
        .addProperty("DissolveType", &GCEntityDissolve::GetDissolveType, &GCEntityDissolve::SetDissolveType)
        .addProperty("DissolverOrigin", &GCEntityDissolve::GetDissolverOrigin, &GCEntityDissolve::SetDissolverOrigin)
        .addProperty("Magnitude", &GCEntityDissolve::GetMagnitude, &GCEntityDissolve::SetMagnitude)
        .addProperty("Parent", &GCEntityDissolve::GetParent, &GCEntityDissolve::SetParent)
        .addFunction("ToPtr", &GCEntityDissolve::ToPtr)
        .addFunction("IsValid", &GCEntityDissolve::IsValid)
        .endClass();
}