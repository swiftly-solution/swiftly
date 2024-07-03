#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_WeaponServices::GCCSPlayer_WeaponServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_WeaponServices::GCCSPlayer_WeaponServices(void *ptr) {
    m_ptr = ptr;
}
float GCCSPlayer_WeaponServices::GetNextAttack() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_WeaponServices", "m_flNextAttack");
}
void GCCSPlayer_WeaponServices::SetNextAttack(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_flNextAttack", false, value);
}
bool GCCSPlayer_WeaponServices::GetIsLookingAtWeapon() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bIsLookingAtWeapon");
}
void GCCSPlayer_WeaponServices::SetIsLookingAtWeapon(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bIsLookingAtWeapon", false, value);
}
bool GCCSPlayer_WeaponServices::GetIsHoldingLookAtWeapon() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bIsHoldingLookAtWeapon");
}
void GCCSPlayer_WeaponServices::SetIsHoldingLookAtWeapon(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bIsHoldingLookAtWeapon", false, value);
}
GCBasePlayerWeapon GCCSPlayer_WeaponServices::GetSavedWeapon() const {
    GCBasePlayerWeapon value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayer_WeaponServices", "m_hSavedWeapon"));
    return value;
}
void GCCSPlayer_WeaponServices::SetSavedWeapon(GCBasePlayerWeapon* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'SavedWeapon' is not possible.\n");
}
int32_t GCCSPlayer_WeaponServices::GetTimeToMelee() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToMelee");
}
void GCCSPlayer_WeaponServices::SetTimeToMelee(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToMelee", false, value);
}
int32_t GCCSPlayer_WeaponServices::GetTimeToSecondary() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToSecondary");
}
void GCCSPlayer_WeaponServices::SetTimeToSecondary(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToSecondary", false, value);
}
int32_t GCCSPlayer_WeaponServices::GetTimeToPrimary() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToPrimary");
}
void GCCSPlayer_WeaponServices::SetTimeToPrimary(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToPrimary", false, value);
}
int32_t GCCSPlayer_WeaponServices::GetTimeToSniperRifle() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToSniperRifle");
}
void GCCSPlayer_WeaponServices::SetTimeToSniperRifle(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToSniperRifle", false, value);
}
bool GCCSPlayer_WeaponServices::GetIsBeingGivenItem() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bIsBeingGivenItem");
}
void GCCSPlayer_WeaponServices::SetIsBeingGivenItem(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bIsBeingGivenItem", false, value);
}
bool GCCSPlayer_WeaponServices::GetIsPickingUpItemWithUse() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bIsPickingUpItemWithUse");
}
void GCCSPlayer_WeaponServices::SetIsPickingUpItemWithUse(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bIsPickingUpItemWithUse", false, value);
}
bool GCCSPlayer_WeaponServices::GetPickedUpWeapon() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bPickedUpWeapon");
}
void GCCSPlayer_WeaponServices::SetPickedUpWeapon(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bPickedUpWeapon", false, value);
}
bool GCCSPlayer_WeaponServices::GetDisableAutoDeploy() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bDisableAutoDeploy");
}
void GCCSPlayer_WeaponServices::SetDisableAutoDeploy(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bDisableAutoDeploy", false, value);
}
bool GCCSPlayer_WeaponServices::GetIsPickingUpGroundWeapon() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bIsPickingUpGroundWeapon");
}
void GCCSPlayer_WeaponServices::SetIsPickingUpGroundWeapon(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bIsPickingUpGroundWeapon", false, value);
}
uint32_t GCCSPlayer_WeaponServices::GetOldShootPositionHistoryCount() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nOldShootPositionHistoryCount");
}
void GCCSPlayer_WeaponServices::SetOldShootPositionHistoryCount(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nOldShootPositionHistoryCount", false, value);
}
uint32_t GCCSPlayer_WeaponServices::GetOldInputHistoryCount() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nOldInputHistoryCount");
}
void GCCSPlayer_WeaponServices::SetOldInputHistoryCount(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nOldInputHistoryCount", false, value);
}
std::string GCCSPlayer_WeaponServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_WeaponServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_WeaponServices GCCSPlayer_WeaponServices::GetParent() const {
    GCPlayer_WeaponServices value(m_ptr);
    return value;
}
void GCCSPlayer_WeaponServices::SetParent(GCPlayer_WeaponServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_WeaponServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_WeaponServices>("CCSPlayer_WeaponServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NextAttack", &GCCSPlayer_WeaponServices::GetNextAttack, &GCCSPlayer_WeaponServices::SetNextAttack)
        .addProperty("IsLookingAtWeapon", &GCCSPlayer_WeaponServices::GetIsLookingAtWeapon, &GCCSPlayer_WeaponServices::SetIsLookingAtWeapon)
        .addProperty("IsHoldingLookAtWeapon", &GCCSPlayer_WeaponServices::GetIsHoldingLookAtWeapon, &GCCSPlayer_WeaponServices::SetIsHoldingLookAtWeapon)
        .addProperty("SavedWeapon", &GCCSPlayer_WeaponServices::GetSavedWeapon, &GCCSPlayer_WeaponServices::SetSavedWeapon)
        .addProperty("TimeToMelee", &GCCSPlayer_WeaponServices::GetTimeToMelee, &GCCSPlayer_WeaponServices::SetTimeToMelee)
        .addProperty("TimeToSecondary", &GCCSPlayer_WeaponServices::GetTimeToSecondary, &GCCSPlayer_WeaponServices::SetTimeToSecondary)
        .addProperty("TimeToPrimary", &GCCSPlayer_WeaponServices::GetTimeToPrimary, &GCCSPlayer_WeaponServices::SetTimeToPrimary)
        .addProperty("TimeToSniperRifle", &GCCSPlayer_WeaponServices::GetTimeToSniperRifle, &GCCSPlayer_WeaponServices::SetTimeToSniperRifle)
        .addProperty("IsBeingGivenItem", &GCCSPlayer_WeaponServices::GetIsBeingGivenItem, &GCCSPlayer_WeaponServices::SetIsBeingGivenItem)
        .addProperty("IsPickingUpItemWithUse", &GCCSPlayer_WeaponServices::GetIsPickingUpItemWithUse, &GCCSPlayer_WeaponServices::SetIsPickingUpItemWithUse)
        .addProperty("PickedUpWeapon", &GCCSPlayer_WeaponServices::GetPickedUpWeapon, &GCCSPlayer_WeaponServices::SetPickedUpWeapon)
        .addProperty("DisableAutoDeploy", &GCCSPlayer_WeaponServices::GetDisableAutoDeploy, &GCCSPlayer_WeaponServices::SetDisableAutoDeploy)
        .addProperty("IsPickingUpGroundWeapon", &GCCSPlayer_WeaponServices::GetIsPickingUpGroundWeapon, &GCCSPlayer_WeaponServices::SetIsPickingUpGroundWeapon)
        .addProperty("OldShootPositionHistoryCount", &GCCSPlayer_WeaponServices::GetOldShootPositionHistoryCount, &GCCSPlayer_WeaponServices::SetOldShootPositionHistoryCount)
        .addProperty("OldInputHistoryCount", &GCCSPlayer_WeaponServices::GetOldInputHistoryCount, &GCCSPlayer_WeaponServices::SetOldInputHistoryCount)
        .addProperty("Parent", &GCCSPlayer_WeaponServices::GetParent, &GCCSPlayer_WeaponServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_WeaponServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_WeaponServices::IsValid)
        .endClass();
}