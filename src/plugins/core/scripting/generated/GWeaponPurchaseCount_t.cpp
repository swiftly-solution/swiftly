#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GWeaponPurchaseCount_t::GWeaponPurchaseCount_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GWeaponPurchaseCount_t::GWeaponPurchaseCount_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GWeaponPurchaseCount_t::GetItemDefIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "WeaponPurchaseCount_t", "m_nItemDefIndex");
}
void GWeaponPurchaseCount_t::SetItemDefIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "WeaponPurchaseCount_t", "m_nItemDefIndex", true, value);
}
uint16_t GWeaponPurchaseCount_t::GetCount() const {
    return GetSchemaValue<uint16_t>(m_ptr, "WeaponPurchaseCount_t", "m_nCount");
}
void GWeaponPurchaseCount_t::SetCount(uint16_t value) {
    SetSchemaValue(m_ptr, "WeaponPurchaseCount_t", "m_nCount", true, value);
}
std::string GWeaponPurchaseCount_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GWeaponPurchaseCount_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassWeaponPurchaseCount_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWeaponPurchaseCount_t>("WeaponPurchaseCount_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ItemDefIndex", &GWeaponPurchaseCount_t::GetItemDefIndex, &GWeaponPurchaseCount_t::SetItemDefIndex)
        .addProperty("Count", &GWeaponPurchaseCount_t::GetCount, &GWeaponPurchaseCount_t::SetCount)
        .addFunction("ToPtr", &GWeaponPurchaseCount_t::ToPtr)
        .addFunction("IsValid", &GWeaponPurchaseCount_t::IsValid)
        .endClass();
}