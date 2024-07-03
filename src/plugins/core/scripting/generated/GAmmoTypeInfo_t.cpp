#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAmmoTypeInfo_t::GAmmoTypeInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAmmoTypeInfo_t::GAmmoTypeInfo_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GAmmoTypeInfo_t::GetMaxCarry() const {
    return GetSchemaValue<int32_t>(m_ptr, "AmmoTypeInfo_t", "m_nMaxCarry");
}
void GAmmoTypeInfo_t::SetMaxCarry(int32_t value) {
    SetSchemaValue(m_ptr, "AmmoTypeInfo_t", "m_nMaxCarry", true, value);
}
GCRangeInt GAmmoTypeInfo_t::GetSplashSize() const {
    GCRangeInt value(GetSchemaPtr(m_ptr, "AmmoTypeInfo_t", "m_nSplashSize"));
    return value;
}
void GAmmoTypeInfo_t::SetSplashSize(GCRangeInt value) {
    SetSchemaValue(m_ptr, "AmmoTypeInfo_t", "m_nSplashSize", true, value);
}
uint64_t GAmmoTypeInfo_t::GetFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "AmmoTypeInfo_t", "m_nFlags");
}
void GAmmoTypeInfo_t::SetFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "AmmoTypeInfo_t", "m_nFlags", true, value);
}
float GAmmoTypeInfo_t::GetMass() const {
    return GetSchemaValue<float>(m_ptr, "AmmoTypeInfo_t", "m_flMass");
}
void GAmmoTypeInfo_t::SetMass(float value) {
    SetSchemaValue(m_ptr, "AmmoTypeInfo_t", "m_flMass", true, value);
}
GCRangeFloat GAmmoTypeInfo_t::GetSpeed() const {
    GCRangeFloat value(GetSchemaPtr(m_ptr, "AmmoTypeInfo_t", "m_flSpeed"));
    return value;
}
void GAmmoTypeInfo_t::SetSpeed(GCRangeFloat value) {
    SetSchemaValue(m_ptr, "AmmoTypeInfo_t", "m_flSpeed", true, value);
}
std::string GAmmoTypeInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAmmoTypeInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAmmoTypeInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAmmoTypeInfo_t>("AmmoTypeInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaxCarry", &GAmmoTypeInfo_t::GetMaxCarry, &GAmmoTypeInfo_t::SetMaxCarry)
        .addProperty("SplashSize", &GAmmoTypeInfo_t::GetSplashSize, &GAmmoTypeInfo_t::SetSplashSize)
        .addProperty("Flags", &GAmmoTypeInfo_t::GetFlags, &GAmmoTypeInfo_t::SetFlags)
        .addProperty("Mass", &GAmmoTypeInfo_t::GetMass, &GAmmoTypeInfo_t::SetMass)
        .addProperty("Speed", &GAmmoTypeInfo_t::GetSpeed, &GAmmoTypeInfo_t::SetSpeed)
        .addFunction("ToPtr", &GAmmoTypeInfo_t::ToPtr)
        .addFunction("IsValid", &GAmmoTypeInfo_t::IsValid)
        .endClass();
}