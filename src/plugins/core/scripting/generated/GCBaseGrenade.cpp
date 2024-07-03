#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseGrenade::GCBaseGrenade(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseGrenade::GCBaseGrenade(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCBaseGrenade::GetOnPlayerPickup() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseGrenade", "m_OnPlayerPickup"));
    return value;
}
void GCBaseGrenade::SetOnPlayerPickup(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_OnPlayerPickup", false, value);
}
GCEntityIOOutput GCBaseGrenade::GetOnExplode() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseGrenade", "m_OnExplode"));
    return value;
}
void GCBaseGrenade::SetOnExplode(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_OnExplode", false, value);
}
bool GCBaseGrenade::GetHasWarnedAI() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseGrenade", "m_bHasWarnedAI");
}
void GCBaseGrenade::SetHasWarnedAI(bool value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_bHasWarnedAI", false, value);
}
bool GCBaseGrenade::GetIsSmokeGrenade() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseGrenade", "m_bIsSmokeGrenade");
}
void GCBaseGrenade::SetIsSmokeGrenade(bool value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_bIsSmokeGrenade", false, value);
}
bool GCBaseGrenade::GetIsLive() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseGrenade", "m_bIsLive");
}
void GCBaseGrenade::SetIsLive(bool value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_bIsLive", false, value);
}
float GCBaseGrenade::GetDmgRadius() const {
    return GetSchemaValue<float>(m_ptr, "CBaseGrenade", "m_DmgRadius");
}
void GCBaseGrenade::SetDmgRadius(float value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_DmgRadius", false, value);
}
float GCBaseGrenade::GetDetonateTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseGrenade", "m_flDetonateTime");
}
void GCBaseGrenade::SetDetonateTime(float value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_flDetonateTime", false, value);
}
float GCBaseGrenade::GetWarnAITime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseGrenade", "m_flWarnAITime");
}
void GCBaseGrenade::SetWarnAITime(float value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_flWarnAITime", false, value);
}
float GCBaseGrenade::GetDamage() const {
    return GetSchemaValue<float>(m_ptr, "CBaseGrenade", "m_flDamage");
}
void GCBaseGrenade::SetDamage(float value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_flDamage", false, value);
}
std::string GCBaseGrenade::GetBounceSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseGrenade", "m_iszBounceSound").String();
}
void GCBaseGrenade::SetBounceSound(std::string value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_iszBounceSound", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseGrenade::GetExplosionSound() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBaseGrenade", "m_ExplosionSound").Get();
}
void GCBaseGrenade::SetExplosionSound(std::string value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_ExplosionSound", false, CUtlString(value.c_str()));
}
GCCSPlayerPawn GCBaseGrenade::GetThrower() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseGrenade", "m_hThrower"));
    return value;
}
void GCBaseGrenade::SetThrower(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Thrower' is not possible.\n");
}
float GCBaseGrenade::GetNextAttack() const {
    return GetSchemaValue<float>(m_ptr, "CBaseGrenade", "m_flNextAttack");
}
void GCBaseGrenade::SetNextAttack(float value) {
    SetSchemaValue(m_ptr, "CBaseGrenade", "m_flNextAttack", false, value);
}
GCCSPlayerPawn GCBaseGrenade::GetOriginalThrower() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseGrenade", "m_hOriginalThrower"));
    return value;
}
void GCBaseGrenade::SetOriginalThrower(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'OriginalThrower' is not possible.\n");
}
std::string GCBaseGrenade::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseGrenade::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFlex GCBaseGrenade::GetParent() const {
    GCBaseFlex value(m_ptr);
    return value;
}
void GCBaseGrenade::SetParent(GCBaseFlex value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseGrenade>("CBaseGrenade")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnPlayerPickup", &GCBaseGrenade::GetOnPlayerPickup, &GCBaseGrenade::SetOnPlayerPickup)
        .addProperty("OnExplode", &GCBaseGrenade::GetOnExplode, &GCBaseGrenade::SetOnExplode)
        .addProperty("HasWarnedAI", &GCBaseGrenade::GetHasWarnedAI, &GCBaseGrenade::SetHasWarnedAI)
        .addProperty("IsSmokeGrenade", &GCBaseGrenade::GetIsSmokeGrenade, &GCBaseGrenade::SetIsSmokeGrenade)
        .addProperty("IsLive", &GCBaseGrenade::GetIsLive, &GCBaseGrenade::SetIsLive)
        .addProperty("DmgRadius", &GCBaseGrenade::GetDmgRadius, &GCBaseGrenade::SetDmgRadius)
        .addProperty("DetonateTime", &GCBaseGrenade::GetDetonateTime, &GCBaseGrenade::SetDetonateTime)
        .addProperty("WarnAITime", &GCBaseGrenade::GetWarnAITime, &GCBaseGrenade::SetWarnAITime)
        .addProperty("Damage", &GCBaseGrenade::GetDamage, &GCBaseGrenade::SetDamage)
        .addProperty("BounceSound", &GCBaseGrenade::GetBounceSound, &GCBaseGrenade::SetBounceSound)
        .addProperty("ExplosionSound", &GCBaseGrenade::GetExplosionSound, &GCBaseGrenade::SetExplosionSound)
        .addProperty("Thrower", &GCBaseGrenade::GetThrower, &GCBaseGrenade::SetThrower)
        .addProperty("NextAttack", &GCBaseGrenade::GetNextAttack, &GCBaseGrenade::SetNextAttack)
        .addProperty("OriginalThrower", &GCBaseGrenade::GetOriginalThrower, &GCBaseGrenade::SetOriginalThrower)
        .addProperty("Parent", &GCBaseGrenade::GetParent, &GCBaseGrenade::SetParent)
        .addFunction("ToPtr", &GCBaseGrenade::ToPtr)
        .addFunction("IsValid", &GCBaseGrenade::IsValid)
        .endClass();
}