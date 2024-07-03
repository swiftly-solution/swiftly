#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFire::GCFire(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFire::GCFire(void *ptr) {
    m_ptr = ptr;
}
GCBaseFire GCFire::GetEffect() const {
    GCBaseFire value(*GetSchemaValuePtr<void*>(m_ptr, "CFire", "m_hEffect"));
    return value;
}
void GCFire::SetEffect(GCBaseFire* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Effect' is not possible.\n");
}
GCBaseEntity GCFire::GetOwner() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CFire", "m_hOwner"));
    return value;
}
void GCFire::SetOwner(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n");
}
int32_t GCFire::GetFireType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFire", "m_nFireType");
}
void GCFire::SetFireType(int32_t value) {
    SetSchemaValue(m_ptr, "CFire", "m_nFireType", false, value);
}
float GCFire::GetFuel() const {
    return GetSchemaValue<float>(m_ptr, "CFire", "m_flFuel");
}
void GCFire::SetFuel(float value) {
    SetSchemaValue(m_ptr, "CFire", "m_flFuel", false, value);
}
float GCFire::GetDamageTime() const {
    return GetSchemaValue<float>(m_ptr, "CFire", "m_flDamageTime");
}
void GCFire::SetDamageTime(float value) {
    SetSchemaValue(m_ptr, "CFire", "m_flDamageTime", false, value);
}
float GCFire::GetLastDamage() const {
    return GetSchemaValue<float>(m_ptr, "CFire", "m_lastDamage");
}
void GCFire::SetLastDamage(float value) {
    SetSchemaValue(m_ptr, "CFire", "m_lastDamage", false, value);
}
float GCFire::GetFireSize() const {
    return GetSchemaValue<float>(m_ptr, "CFire", "m_flFireSize");
}
void GCFire::SetFireSize(float value) {
    SetSchemaValue(m_ptr, "CFire", "m_flFireSize", false, value);
}
float GCFire::GetLastNavUpdateTime() const {
    return GetSchemaValue<float>(m_ptr, "CFire", "m_flLastNavUpdateTime");
}
void GCFire::SetLastNavUpdateTime(float value) {
    SetSchemaValue(m_ptr, "CFire", "m_flLastNavUpdateTime", false, value);
}
float GCFire::GetHeatLevel() const {
    return GetSchemaValue<float>(m_ptr, "CFire", "m_flHeatLevel");
}
void GCFire::SetHeatLevel(float value) {
    SetSchemaValue(m_ptr, "CFire", "m_flHeatLevel", false, value);
}
float GCFire::GetHeatAbsorb() const {
    return GetSchemaValue<float>(m_ptr, "CFire", "m_flHeatAbsorb");
}
void GCFire::SetHeatAbsorb(float value) {
    SetSchemaValue(m_ptr, "CFire", "m_flHeatAbsorb", false, value);
}
float GCFire::GetDamageScale() const {
    return GetSchemaValue<float>(m_ptr, "CFire", "m_flDamageScale");
}
void GCFire::SetDamageScale(float value) {
    SetSchemaValue(m_ptr, "CFire", "m_flDamageScale", false, value);
}
float GCFire::GetMaxHeat() const {
    return GetSchemaValue<float>(m_ptr, "CFire", "m_flMaxHeat");
}
void GCFire::SetMaxHeat(float value) {
    SetSchemaValue(m_ptr, "CFire", "m_flMaxHeat", false, value);
}
float GCFire::GetLastHeatLevel() const {
    return GetSchemaValue<float>(m_ptr, "CFire", "m_flLastHeatLevel");
}
void GCFire::SetLastHeatLevel(float value) {
    SetSchemaValue(m_ptr, "CFire", "m_flLastHeatLevel", false, value);
}
float GCFire::GetAttackTime() const {
    return GetSchemaValue<float>(m_ptr, "CFire", "m_flAttackTime");
}
void GCFire::SetAttackTime(float value) {
    SetSchemaValue(m_ptr, "CFire", "m_flAttackTime", false, value);
}
bool GCFire::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CFire", "m_bEnabled");
}
void GCFire::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CFire", "m_bEnabled", false, value);
}
bool GCFire::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CFire", "m_bStartDisabled");
}
void GCFire::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CFire", "m_bStartDisabled", false, value);
}
bool GCFire::GetDidActivate() const {
    return GetSchemaValue<bool>(m_ptr, "CFire", "m_bDidActivate");
}
void GCFire::SetDidActivate(bool value) {
    SetSchemaValue(m_ptr, "CFire", "m_bDidActivate", false, value);
}
GCEntityIOOutput GCFire::GetOnIgnited() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFire", "m_OnIgnited"));
    return value;
}
void GCFire::SetOnIgnited(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFire", "m_OnIgnited", false, value);
}
GCEntityIOOutput GCFire::GetOnExtinguished() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFire", "m_OnExtinguished"));
    return value;
}
void GCFire::SetOnExtinguished(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFire", "m_OnExtinguished", false, value);
}
std::string GCFire::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFire::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFire::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFire::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFire>("CFire")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Effect", &GCFire::GetEffect, &GCFire::SetEffect)
        .addProperty("Owner", &GCFire::GetOwner, &GCFire::SetOwner)
        .addProperty("FireType", &GCFire::GetFireType, &GCFire::SetFireType)
        .addProperty("Fuel", &GCFire::GetFuel, &GCFire::SetFuel)
        .addProperty("DamageTime", &GCFire::GetDamageTime, &GCFire::SetDamageTime)
        .addProperty("LastDamage", &GCFire::GetLastDamage, &GCFire::SetLastDamage)
        .addProperty("FireSize", &GCFire::GetFireSize, &GCFire::SetFireSize)
        .addProperty("LastNavUpdateTime", &GCFire::GetLastNavUpdateTime, &GCFire::SetLastNavUpdateTime)
        .addProperty("HeatLevel", &GCFire::GetHeatLevel, &GCFire::SetHeatLevel)
        .addProperty("HeatAbsorb", &GCFire::GetHeatAbsorb, &GCFire::SetHeatAbsorb)
        .addProperty("DamageScale", &GCFire::GetDamageScale, &GCFire::SetDamageScale)
        .addProperty("MaxHeat", &GCFire::GetMaxHeat, &GCFire::SetMaxHeat)
        .addProperty("LastHeatLevel", &GCFire::GetLastHeatLevel, &GCFire::SetLastHeatLevel)
        .addProperty("AttackTime", &GCFire::GetAttackTime, &GCFire::SetAttackTime)
        .addProperty("Enabled", &GCFire::GetEnabled, &GCFire::SetEnabled)
        .addProperty("StartDisabled", &GCFire::GetStartDisabled, &GCFire::SetStartDisabled)
        .addProperty("DidActivate", &GCFire::GetDidActivate, &GCFire::SetDidActivate)
        .addProperty("OnIgnited", &GCFire::GetOnIgnited, &GCFire::SetOnIgnited)
        .addProperty("OnExtinguished", &GCFire::GetOnExtinguished, &GCFire::SetOnExtinguished)
        .addProperty("Parent", &GCFire::GetParent, &GCFire::SetParent)
        .addFunction("ToPtr", &GCFire::ToPtr)
        .addFunction("IsValid", &GCFire::IsValid)
        .endClass();
}