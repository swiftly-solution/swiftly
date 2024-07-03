#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_ActionTrackingServices::GCCSPlayer_ActionTrackingServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_ActionTrackingServices::GCCSPlayer_ActionTrackingServices(void *ptr) {
    m_ptr = ptr;
}
GCBasePlayerWeapon GCCSPlayer_ActionTrackingServices::GetLastWeaponBeforeC4AutoSwitch() const {
    GCBasePlayerWeapon value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayer_ActionTrackingServices", "m_hLastWeaponBeforeC4AutoSwitch"));
    return value;
}
void GCCSPlayer_ActionTrackingServices::SetLastWeaponBeforeC4AutoSwitch(GCBasePlayerWeapon* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastWeaponBeforeC4AutoSwitch' is not possible.\n");
}
bool GCCSPlayer_ActionTrackingServices::GetIsRescuing() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_ActionTrackingServices", "m_bIsRescuing");
}
void GCCSPlayer_ActionTrackingServices::SetIsRescuing(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_ActionTrackingServices", "m_bIsRescuing", false, value);
}
GWeaponPurchaseTracker_t GCCSPlayer_ActionTrackingServices::GetWeaponPurchasesThisMatch() const {
    GWeaponPurchaseTracker_t value(GetSchemaPtr(m_ptr, "CCSPlayer_ActionTrackingServices", "m_weaponPurchasesThisMatch"));
    return value;
}
void GCCSPlayer_ActionTrackingServices::SetWeaponPurchasesThisMatch(GWeaponPurchaseTracker_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_ActionTrackingServices", "m_weaponPurchasesThisMatch", false, value);
}
GWeaponPurchaseTracker_t GCCSPlayer_ActionTrackingServices::GetWeaponPurchasesThisRound() const {
    GWeaponPurchaseTracker_t value(GetSchemaPtr(m_ptr, "CCSPlayer_ActionTrackingServices", "m_weaponPurchasesThisRound"));
    return value;
}
void GCCSPlayer_ActionTrackingServices::SetWeaponPurchasesThisRound(GWeaponPurchaseTracker_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_ActionTrackingServices", "m_weaponPurchasesThisRound", false, value);
}
std::string GCCSPlayer_ActionTrackingServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_ActionTrackingServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCCSPlayer_ActionTrackingServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCCSPlayer_ActionTrackingServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_ActionTrackingServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_ActionTrackingServices>("CCSPlayer_ActionTrackingServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LastWeaponBeforeC4AutoSwitch", &GCCSPlayer_ActionTrackingServices::GetLastWeaponBeforeC4AutoSwitch, &GCCSPlayer_ActionTrackingServices::SetLastWeaponBeforeC4AutoSwitch)
        .addProperty("IsRescuing", &GCCSPlayer_ActionTrackingServices::GetIsRescuing, &GCCSPlayer_ActionTrackingServices::SetIsRescuing)
        .addProperty("WeaponPurchasesThisMatch", &GCCSPlayer_ActionTrackingServices::GetWeaponPurchasesThisMatch, &GCCSPlayer_ActionTrackingServices::SetWeaponPurchasesThisMatch)
        .addProperty("WeaponPurchasesThisRound", &GCCSPlayer_ActionTrackingServices::GetWeaponPurchasesThisRound, &GCCSPlayer_ActionTrackingServices::SetWeaponPurchasesThisRound)
        .addProperty("Parent", &GCCSPlayer_ActionTrackingServices::GetParent, &GCCSPlayer_ActionTrackingServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_ActionTrackingServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_ActionTrackingServices::IsValid)
        .endClass();
}