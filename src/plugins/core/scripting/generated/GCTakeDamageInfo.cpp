#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTakeDamageInfo::GCTakeDamageInfo(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTakeDamageInfo::GCTakeDamageInfo(void *ptr) {
    m_ptr = ptr;
}
Vector GCTakeDamageInfo::GetDamageForce() const {
    return GetSchemaValue<Vector>(m_ptr, "CTakeDamageInfo", "m_vecDamageForce");
}
void GCTakeDamageInfo::SetDamageForce(Vector value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_vecDamageForce", false, value);
}
Vector GCTakeDamageInfo::GetDamagePosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CTakeDamageInfo", "m_vecDamagePosition");
}
void GCTakeDamageInfo::SetDamagePosition(Vector value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_vecDamagePosition", false, value);
}
Vector GCTakeDamageInfo::GetReportedPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CTakeDamageInfo", "m_vecReportedPosition");
}
void GCTakeDamageInfo::SetReportedPosition(Vector value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_vecReportedPosition", false, value);
}
Vector GCTakeDamageInfo::GetDamageDirection() const {
    return GetSchemaValue<Vector>(m_ptr, "CTakeDamageInfo", "m_vecDamageDirection");
}
void GCTakeDamageInfo::SetDamageDirection(Vector value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_vecDamageDirection", false, value);
}
GCBaseEntity GCTakeDamageInfo::GetInflictor() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CTakeDamageInfo", "m_hInflictor"));
    return value;
}
void GCTakeDamageInfo::SetInflictor(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Inflictor' is not possible.\n");
}
GCBaseEntity GCTakeDamageInfo::GetAttacker() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CTakeDamageInfo", "m_hAttacker"));
    return value;
}
void GCTakeDamageInfo::SetAttacker(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Attacker' is not possible.\n");
}
GCBaseEntity GCTakeDamageInfo::GetAbility() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CTakeDamageInfo", "m_hAbility"));
    return value;
}
void GCTakeDamageInfo::SetAbility(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Ability' is not possible.\n");
}
float GCTakeDamageInfo::GetDamage() const {
    return GetSchemaValue<float>(m_ptr, "CTakeDamageInfo", "m_flDamage");
}
void GCTakeDamageInfo::SetDamage(float value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_flDamage", false, value);
}
float GCTakeDamageInfo::GetTotalledDamage() const {
    return GetSchemaValue<float>(m_ptr, "CTakeDamageInfo", "m_flTotalledDamage");
}
void GCTakeDamageInfo::SetTotalledDamage(float value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_flTotalledDamage", false, value);
}
int32_t GCTakeDamageInfo::GetBitsDamageType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageInfo", "m_bitsDamageType");
}
void GCTakeDamageInfo::SetBitsDamageType(int32_t value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_bitsDamageType", false, value);
}
int32_t GCTakeDamageInfo::GetDamageCustom() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageInfo", "m_iDamageCustom");
}
void GCTakeDamageInfo::SetDamageCustom(int32_t value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_iDamageCustom", false, value);
}
uint8_t GCTakeDamageInfo::GetAmmoType() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CTakeDamageInfo", "m_iAmmoType");
}
void GCTakeDamageInfo::SetAmmoType(uint8_t value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_iAmmoType", false, value);
}
float GCTakeDamageInfo::GetOriginalDamage() const {
    return GetSchemaValue<float>(m_ptr, "CTakeDamageInfo", "m_flOriginalDamage");
}
void GCTakeDamageInfo::SetOriginalDamage(float value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_flOriginalDamage", false, value);
}
bool GCTakeDamageInfo::GetShouldBleed() const {
    return GetSchemaValue<bool>(m_ptr, "CTakeDamageInfo", "m_bShouldBleed");
}
void GCTakeDamageInfo::SetShouldBleed(bool value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_bShouldBleed", false, value);
}
bool GCTakeDamageInfo::GetShouldSpark() const {
    return GetSchemaValue<bool>(m_ptr, "CTakeDamageInfo", "m_bShouldSpark");
}
void GCTakeDamageInfo::SetShouldSpark(bool value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_bShouldSpark", false, value);
}
uint64_t GCTakeDamageInfo::GetDamageFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CTakeDamageInfo", "m_nDamageFlags");
}
void GCTakeDamageInfo::SetDamageFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_nDamageFlags", false, value);
}
int32_t GCTakeDamageInfo::GetNumObjectsPenetrated() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageInfo", "m_nNumObjectsPenetrated");
}
void GCTakeDamageInfo::SetNumObjectsPenetrated(int32_t value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_nNumObjectsPenetrated", false, value);
}
bool GCTakeDamageInfo::GetInTakeDamageFlow() const {
    return GetSchemaValue<bool>(m_ptr, "CTakeDamageInfo", "m_bInTakeDamageFlow");
}
void GCTakeDamageInfo::SetInTakeDamageFlow(bool value) {
    SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_bInTakeDamageFlow", false, value);
}
std::string GCTakeDamageInfo::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTakeDamageInfo::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCTakeDamageInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTakeDamageInfo>("CTakeDamageInfo")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DamageForce", &GCTakeDamageInfo::GetDamageForce, &GCTakeDamageInfo::SetDamageForce)
        .addProperty("DamagePosition", &GCTakeDamageInfo::GetDamagePosition, &GCTakeDamageInfo::SetDamagePosition)
        .addProperty("ReportedPosition", &GCTakeDamageInfo::GetReportedPosition, &GCTakeDamageInfo::SetReportedPosition)
        .addProperty("DamageDirection", &GCTakeDamageInfo::GetDamageDirection, &GCTakeDamageInfo::SetDamageDirection)
        .addProperty("Inflictor", &GCTakeDamageInfo::GetInflictor, &GCTakeDamageInfo::SetInflictor)
        .addProperty("Attacker", &GCTakeDamageInfo::GetAttacker, &GCTakeDamageInfo::SetAttacker)
        .addProperty("Ability", &GCTakeDamageInfo::GetAbility, &GCTakeDamageInfo::SetAbility)
        .addProperty("Damage", &GCTakeDamageInfo::GetDamage, &GCTakeDamageInfo::SetDamage)
        .addProperty("TotalledDamage", &GCTakeDamageInfo::GetTotalledDamage, &GCTakeDamageInfo::SetTotalledDamage)
        .addProperty("BitsDamageType", &GCTakeDamageInfo::GetBitsDamageType, &GCTakeDamageInfo::SetBitsDamageType)
        .addProperty("DamageCustom", &GCTakeDamageInfo::GetDamageCustom, &GCTakeDamageInfo::SetDamageCustom)
        .addProperty("AmmoType", &GCTakeDamageInfo::GetAmmoType, &GCTakeDamageInfo::SetAmmoType)
        .addProperty("OriginalDamage", &GCTakeDamageInfo::GetOriginalDamage, &GCTakeDamageInfo::SetOriginalDamage)
        .addProperty("ShouldBleed", &GCTakeDamageInfo::GetShouldBleed, &GCTakeDamageInfo::SetShouldBleed)
        .addProperty("ShouldSpark", &GCTakeDamageInfo::GetShouldSpark, &GCTakeDamageInfo::SetShouldSpark)
        .addProperty("DamageFlags", &GCTakeDamageInfo::GetDamageFlags, &GCTakeDamageInfo::SetDamageFlags)
        .addProperty("NumObjectsPenetrated", &GCTakeDamageInfo::GetNumObjectsPenetrated, &GCTakeDamageInfo::SetNumObjectsPenetrated)
        .addProperty("InTakeDamageFlow", &GCTakeDamageInfo::GetInTakeDamageFlow, &GCTakeDamageInfo::SetInTakeDamageFlow)
        .addFunction("ToPtr", &GCTakeDamageInfo::ToPtr)
        .addFunction("IsValid", &GCTakeDamageInfo::IsValid)
        .endClass();
}