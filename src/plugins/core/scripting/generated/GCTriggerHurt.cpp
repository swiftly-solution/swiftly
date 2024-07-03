#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerHurt::GCTriggerHurt(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerHurt::GCTriggerHurt(void *ptr) {
    m_ptr = ptr;
}
float GCTriggerHurt::GetOriginalDamage() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerHurt", "m_flOriginalDamage");
}
void GCTriggerHurt::SetOriginalDamage(float value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_flOriginalDamage", false, value);
}
float GCTriggerHurt::GetDamage() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerHurt", "m_flDamage");
}
void GCTriggerHurt::SetDamage(float value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_flDamage", false, value);
}
float GCTriggerHurt::GetDamageCap() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerHurt", "m_flDamageCap");
}
void GCTriggerHurt::SetDamageCap(float value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_flDamageCap", false, value);
}
float GCTriggerHurt::GetLastDmgTime() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerHurt", "m_flLastDmgTime");
}
void GCTriggerHurt::SetLastDmgTime(float value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_flLastDmgTime", false, value);
}
float GCTriggerHurt::GetForgivenessDelay() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerHurt", "m_flForgivenessDelay");
}
void GCTriggerHurt::SetForgivenessDelay(float value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_flForgivenessDelay", false, value);
}
int32_t GCTriggerHurt::GetBitsDamageInflict() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTriggerHurt", "m_bitsDamageInflict");
}
void GCTriggerHurt::SetBitsDamageInflict(int32_t value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_bitsDamageInflict", false, value);
}
int32_t GCTriggerHurt::GetDamageModel() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTriggerHurt", "m_damageModel");
}
void GCTriggerHurt::SetDamageModel(int32_t value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_damageModel", false, value);
}
bool GCTriggerHurt::GetNoDmgForce() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerHurt", "m_bNoDmgForce");
}
void GCTriggerHurt::SetNoDmgForce(bool value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_bNoDmgForce", false, value);
}
Vector GCTriggerHurt::GetDamageForce() const {
    return GetSchemaValue<Vector>(m_ptr, "CTriggerHurt", "m_vDamageForce");
}
void GCTriggerHurt::SetDamageForce(Vector value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_vDamageForce", false, value);
}
bool GCTriggerHurt::GetThinkAlways() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerHurt", "m_thinkAlways");
}
void GCTriggerHurt::SetThinkAlways(bool value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_thinkAlways", false, value);
}
float GCTriggerHurt::GetHurtThinkPeriod() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerHurt", "m_hurtThinkPeriod");
}
void GCTriggerHurt::SetHurtThinkPeriod(float value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_hurtThinkPeriod", false, value);
}
GCEntityIOOutput GCTriggerHurt::GetOnHurt() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerHurt", "m_OnHurt"));
    return value;
}
void GCTriggerHurt::SetOnHurt(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_OnHurt", false, value);
}
GCEntityIOOutput GCTriggerHurt::GetOnHurtPlayer() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerHurt", "m_OnHurtPlayer"));
    return value;
}
void GCTriggerHurt::SetOnHurtPlayer(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerHurt", "m_OnHurtPlayer", false, value);
}
std::string GCTriggerHurt::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerHurt::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerHurt::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerHurt::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerHurt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerHurt>("CTriggerHurt")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OriginalDamage", &GCTriggerHurt::GetOriginalDamage, &GCTriggerHurt::SetOriginalDamage)
        .addProperty("Damage", &GCTriggerHurt::GetDamage, &GCTriggerHurt::SetDamage)
        .addProperty("DamageCap", &GCTriggerHurt::GetDamageCap, &GCTriggerHurt::SetDamageCap)
        .addProperty("LastDmgTime", &GCTriggerHurt::GetLastDmgTime, &GCTriggerHurt::SetLastDmgTime)
        .addProperty("ForgivenessDelay", &GCTriggerHurt::GetForgivenessDelay, &GCTriggerHurt::SetForgivenessDelay)
        .addProperty("BitsDamageInflict", &GCTriggerHurt::GetBitsDamageInflict, &GCTriggerHurt::SetBitsDamageInflict)
        .addProperty("DamageModel", &GCTriggerHurt::GetDamageModel, &GCTriggerHurt::SetDamageModel)
        .addProperty("NoDmgForce", &GCTriggerHurt::GetNoDmgForce, &GCTriggerHurt::SetNoDmgForce)
        .addProperty("DamageForce", &GCTriggerHurt::GetDamageForce, &GCTriggerHurt::SetDamageForce)
        .addProperty("ThinkAlways", &GCTriggerHurt::GetThinkAlways, &GCTriggerHurt::SetThinkAlways)
        .addProperty("HurtThinkPeriod", &GCTriggerHurt::GetHurtThinkPeriod, &GCTriggerHurt::SetHurtThinkPeriod)
        .addProperty("OnHurt", &GCTriggerHurt::GetOnHurt, &GCTriggerHurt::SetOnHurt)
        .addProperty("OnHurtPlayer", &GCTriggerHurt::GetOnHurtPlayer, &GCTriggerHurt::SetOnHurtPlayer)
        .addProperty("Parent", &GCTriggerHurt::GetParent, &GCTriggerHurt::SetParent)
        .addFunction("ToPtr", &GCTriggerHurt::ToPtr)
        .addFunction("IsValid", &GCTriggerHurt::IsValid)
        .endClass();
}