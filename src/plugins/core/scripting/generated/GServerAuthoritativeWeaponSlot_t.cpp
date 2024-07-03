#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GServerAuthoritativeWeaponSlot_t::GServerAuthoritativeWeaponSlot_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GServerAuthoritativeWeaponSlot_t::GServerAuthoritativeWeaponSlot_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GServerAuthoritativeWeaponSlot_t::GetClass() const {
    return GetSchemaValue<uint16_t>(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unClass");
}
void GServerAuthoritativeWeaponSlot_t::SetClass(uint16_t value) {
    SetSchemaValue(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unClass", true, value);
}
uint16_t GServerAuthoritativeWeaponSlot_t::GetSlot() const {
    return GetSchemaValue<uint16_t>(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unSlot");
}
void GServerAuthoritativeWeaponSlot_t::SetSlot(uint16_t value) {
    SetSchemaValue(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unSlot", true, value);
}
uint16_t GServerAuthoritativeWeaponSlot_t::GetItemDefIdx() const {
    return GetSchemaValue<uint16_t>(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unItemDefIdx");
}
void GServerAuthoritativeWeaponSlot_t::SetItemDefIdx(uint16_t value) {
    SetSchemaValue(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unItemDefIdx", true, value);
}
std::string GServerAuthoritativeWeaponSlot_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GServerAuthoritativeWeaponSlot_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassServerAuthoritativeWeaponSlot_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GServerAuthoritativeWeaponSlot_t>("ServerAuthoritativeWeaponSlot_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Class", &GServerAuthoritativeWeaponSlot_t::GetClass, &GServerAuthoritativeWeaponSlot_t::SetClass)
        .addProperty("Slot", &GServerAuthoritativeWeaponSlot_t::GetSlot, &GServerAuthoritativeWeaponSlot_t::SetSlot)
        .addProperty("ItemDefIdx", &GServerAuthoritativeWeaponSlot_t::GetItemDefIdx, &GServerAuthoritativeWeaponSlot_t::SetItemDefIdx)
        .addFunction("ToPtr", &GServerAuthoritativeWeaponSlot_t::ToPtr)
        .addFunction("IsValid", &GServerAuthoritativeWeaponSlot_t::IsValid)
        .endClass();
}