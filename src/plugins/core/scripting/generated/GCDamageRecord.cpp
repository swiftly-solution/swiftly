#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDamageRecord::GCDamageRecord(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDamageRecord::GCDamageRecord(void *ptr) {
    m_ptr = ptr;
}
GCCSPlayerPawn GCDamageRecord::GetPlayerDamager() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CDamageRecord", "m_PlayerDamager"));
    return value;
}
void GCDamageRecord::SetPlayerDamager(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerDamager' is not possible.\n");
}
GCCSPlayerPawn GCDamageRecord::GetPlayerRecipient() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CDamageRecord", "m_PlayerRecipient"));
    return value;
}
void GCDamageRecord::SetPlayerRecipient(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerRecipient' is not possible.\n");
}
GCCSPlayerController GCDamageRecord::GetPlayerControllerDamager() const {
    GCCSPlayerController value(*GetSchemaValuePtr<void*>(m_ptr, "CDamageRecord", "m_hPlayerControllerDamager"));
    return value;
}
void GCDamageRecord::SetPlayerControllerDamager(GCCSPlayerController* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerControllerDamager' is not possible.\n");
}
GCCSPlayerController GCDamageRecord::GetPlayerControllerRecipient() const {
    GCCSPlayerController value(*GetSchemaValuePtr<void*>(m_ptr, "CDamageRecord", "m_hPlayerControllerRecipient"));
    return value;
}
void GCDamageRecord::SetPlayerControllerRecipient(GCCSPlayerController* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerControllerRecipient' is not possible.\n");
}
std::string GCDamageRecord::GetPlayerDamagerName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CDamageRecord", "m_szPlayerDamagerName").Get();
}
void GCDamageRecord::SetPlayerDamagerName(std::string value) {
    SetSchemaValue(m_ptr, "CDamageRecord", "m_szPlayerDamagerName", false, CUtlString(value.c_str()));
}
std::string GCDamageRecord::GetPlayerRecipientName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CDamageRecord", "m_szPlayerRecipientName").Get();
}
void GCDamageRecord::SetPlayerRecipientName(std::string value) {
    SetSchemaValue(m_ptr, "CDamageRecord", "m_szPlayerRecipientName", false, CUtlString(value.c_str()));
}
uint64_t GCDamageRecord::GetDamagerXuid() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CDamageRecord", "m_DamagerXuid");
}
void GCDamageRecord::SetDamagerXuid(uint64_t value) {
    SetSchemaValue(m_ptr, "CDamageRecord", "m_DamagerXuid", false, value);
}
uint64_t GCDamageRecord::GetRecipientXuid() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CDamageRecord", "m_RecipientXuid");
}
void GCDamageRecord::SetRecipientXuid(uint64_t value) {
    SetSchemaValue(m_ptr, "CDamageRecord", "m_RecipientXuid", false, value);
}
int32_t GCDamageRecord::GetDamage() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDamageRecord", "m_iDamage");
}
void GCDamageRecord::SetDamage(int32_t value) {
    SetSchemaValue(m_ptr, "CDamageRecord", "m_iDamage", false, value);
}
int32_t GCDamageRecord::GetActualHealthRemoved() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDamageRecord", "m_iActualHealthRemoved");
}
void GCDamageRecord::SetActualHealthRemoved(int32_t value) {
    SetSchemaValue(m_ptr, "CDamageRecord", "m_iActualHealthRemoved", false, value);
}
int32_t GCDamageRecord::GetNumHits() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDamageRecord", "m_iNumHits");
}
void GCDamageRecord::SetNumHits(int32_t value) {
    SetSchemaValue(m_ptr, "CDamageRecord", "m_iNumHits", false, value);
}
int32_t GCDamageRecord::GetLastBulletUpdate() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDamageRecord", "m_iLastBulletUpdate");
}
void GCDamageRecord::SetLastBulletUpdate(int32_t value) {
    SetSchemaValue(m_ptr, "CDamageRecord", "m_iLastBulletUpdate", false, value);
}
bool GCDamageRecord::GetIsOtherEnemy() const {
    return GetSchemaValue<bool>(m_ptr, "CDamageRecord", "m_bIsOtherEnemy");
}
void GCDamageRecord::SetIsOtherEnemy(bool value) {
    SetSchemaValue(m_ptr, "CDamageRecord", "m_bIsOtherEnemy", false, value);
}
uint64_t GCDamageRecord::GetKillType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CDamageRecord", "m_killType");
}
void GCDamageRecord::SetKillType(uint64_t value) {
    SetSchemaValue(m_ptr, "CDamageRecord", "m_killType", false, value);
}
std::string GCDamageRecord::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDamageRecord::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCDamageRecord(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDamageRecord>("CDamageRecord")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PlayerDamager", &GCDamageRecord::GetPlayerDamager, &GCDamageRecord::SetPlayerDamager)
        .addProperty("PlayerRecipient", &GCDamageRecord::GetPlayerRecipient, &GCDamageRecord::SetPlayerRecipient)
        .addProperty("PlayerControllerDamager", &GCDamageRecord::GetPlayerControllerDamager, &GCDamageRecord::SetPlayerControllerDamager)
        .addProperty("PlayerControllerRecipient", &GCDamageRecord::GetPlayerControllerRecipient, &GCDamageRecord::SetPlayerControllerRecipient)
        .addProperty("PlayerDamagerName", &GCDamageRecord::GetPlayerDamagerName, &GCDamageRecord::SetPlayerDamagerName)
        .addProperty("PlayerRecipientName", &GCDamageRecord::GetPlayerRecipientName, &GCDamageRecord::SetPlayerRecipientName)
        .addProperty("DamagerXuid", &GCDamageRecord::GetDamagerXuid, &GCDamageRecord::SetDamagerXuid)
        .addProperty("RecipientXuid", &GCDamageRecord::GetRecipientXuid, &GCDamageRecord::SetRecipientXuid)
        .addProperty("Damage", &GCDamageRecord::GetDamage, &GCDamageRecord::SetDamage)
        .addProperty("ActualHealthRemoved", &GCDamageRecord::GetActualHealthRemoved, &GCDamageRecord::SetActualHealthRemoved)
        .addProperty("NumHits", &GCDamageRecord::GetNumHits, &GCDamageRecord::SetNumHits)
        .addProperty("LastBulletUpdate", &GCDamageRecord::GetLastBulletUpdate, &GCDamageRecord::SetLastBulletUpdate)
        .addProperty("IsOtherEnemy", &GCDamageRecord::GetIsOtherEnemy, &GCDamageRecord::SetIsOtherEnemy)
        .addProperty("KillType", &GCDamageRecord::GetKillType, &GCDamageRecord::SetKillType)
        .addFunction("ToPtr", &GCDamageRecord::ToPtr)
        .addFunction("IsValid", &GCDamageRecord::IsValid)
        .endClass();
}