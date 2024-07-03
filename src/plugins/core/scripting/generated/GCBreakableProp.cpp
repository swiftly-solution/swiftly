#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBreakableProp::GCBreakableProp(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBreakableProp::GCBreakableProp(void *ptr) {
    m_ptr = ptr;
}
GCPropDataComponent GCBreakableProp::GetCPropDataComponent() const {
    GCPropDataComponent value(GetSchemaPtr(m_ptr, "CBreakableProp", "m_CPropDataComponent"));
    return value;
}
void GCBreakableProp::SetCPropDataComponent(GCPropDataComponent value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_CPropDataComponent", false, value);
}
GCEntityIOOutput GCBreakableProp::GetOnBreak() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBreakableProp", "m_OnBreak"));
    return value;
}
void GCBreakableProp::SetOnBreak(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_OnBreak", false, value);
}
GCEntityIOOutput GCBreakableProp::GetOnTakeDamage() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBreakableProp", "m_OnTakeDamage"));
    return value;
}
void GCBreakableProp::SetOnTakeDamage(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_OnTakeDamage", false, value);
}
float GCBreakableProp::GetImpactEnergyScale() const {
    return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_impactEnergyScale");
}
void GCBreakableProp::SetImpactEnergyScale(float value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_impactEnergyScale", false, value);
}
int32_t GCBreakableProp::GetMinHealthDmg() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBreakableProp", "m_iMinHealthDmg");
}
void GCBreakableProp::SetMinHealthDmg(int32_t value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_iMinHealthDmg", false, value);
}
QAngle GCBreakableProp::GetPreferredCarryAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBreakableProp", "m_preferredCarryAngles");
}
void GCBreakableProp::SetPreferredCarryAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_preferredCarryAngles", false, value);
}
float GCBreakableProp::GetPressureDelay() const {
    return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_flPressureDelay");
}
void GCBreakableProp::SetPressureDelay(float value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_flPressureDelay", false, value);
}
float GCBreakableProp::GetDefBurstScale() const {
    return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_flDefBurstScale");
}
void GCBreakableProp::SetDefBurstScale(float value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_flDefBurstScale", false, value);
}
Vector GCBreakableProp::GetDefBurstOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CBreakableProp", "m_vDefBurstOffset");
}
void GCBreakableProp::SetDefBurstOffset(Vector value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_vDefBurstOffset", false, value);
}
GCBaseEntity GCBreakableProp::GetBreaker() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBreakableProp", "m_hBreaker"));
    return value;
}
void GCBreakableProp::SetBreaker(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Breaker' is not possible.\n");
}
uint64_t GCBreakableProp::GetPerformanceMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBreakableProp", "m_PerformanceMode");
}
void GCBreakableProp::SetPerformanceMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_PerformanceMode", false, value);
}
float GCBreakableProp::GetPreventDamageBeforeTime() const {
    return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_flPreventDamageBeforeTime");
}
void GCBreakableProp::SetPreventDamageBeforeTime(float value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_flPreventDamageBeforeTime", false, value);
}
bool GCBreakableProp::GetHasBreakPiecesOrCommands() const {
    return GetSchemaValue<bool>(m_ptr, "CBreakableProp", "m_bHasBreakPiecesOrCommands");
}
void GCBreakableProp::SetHasBreakPiecesOrCommands(bool value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_bHasBreakPiecesOrCommands", false, value);
}
float GCBreakableProp::GetExplodeDamage() const {
    return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_explodeDamage");
}
void GCBreakableProp::SetExplodeDamage(float value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_explodeDamage", false, value);
}
float GCBreakableProp::GetExplodeRadius() const {
    return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_explodeRadius");
}
void GCBreakableProp::SetExplodeRadius(float value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_explodeRadius", false, value);
}
float GCBreakableProp::GetExplosionDelay() const {
    return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_explosionDelay");
}
void GCBreakableProp::SetExplosionDelay(float value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_explosionDelay", false, value);
}
std::string GCBreakableProp::GetExplosionBuildupSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakableProp", "m_explosionBuildupSound").String();
}
void GCBreakableProp::SetExplosionBuildupSound(std::string value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_explosionBuildupSound", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBreakableProp::GetExplosionCustomEffect() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakableProp", "m_explosionCustomEffect").String();
}
void GCBreakableProp::SetExplosionCustomEffect(std::string value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_explosionCustomEffect", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBreakableProp::GetExplosionCustomSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakableProp", "m_explosionCustomSound").String();
}
void GCBreakableProp::SetExplosionCustomSound(std::string value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_explosionCustomSound", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBreakableProp::GetExplosionModifier() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakableProp", "m_explosionModifier").String();
}
void GCBreakableProp::SetExplosionModifier(std::string value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_explosionModifier", false, CUtlSymbolLarge(value.c_str()));
}
GCBasePlayerPawn GCBreakableProp::GetPhysicsAttacker() const {
    GCBasePlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CBreakableProp", "m_hPhysicsAttacker"));
    return value;
}
void GCBreakableProp::SetPhysicsAttacker(GCBasePlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PhysicsAttacker' is not possible.\n");
}
float GCBreakableProp::GetLastPhysicsInfluenceTime() const {
    return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_flLastPhysicsInfluenceTime");
}
void GCBreakableProp::SetLastPhysicsInfluenceTime(float value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_flLastPhysicsInfluenceTime", false, value);
}
bool GCBreakableProp::GetOriginalBlockLOS() const {
    return GetSchemaValue<bool>(m_ptr, "CBreakableProp", "m_bOriginalBlockLOS");
}
void GCBreakableProp::SetOriginalBlockLOS(bool value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_bOriginalBlockLOS", false, value);
}
float GCBreakableProp::GetDefaultFadeScale() const {
    return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_flDefaultFadeScale");
}
void GCBreakableProp::SetDefaultFadeScale(float value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_flDefaultFadeScale", false, value);
}
GCBaseEntity GCBreakableProp::GetLastAttacker() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBreakableProp", "m_hLastAttacker"));
    return value;
}
void GCBreakableProp::SetLastAttacker(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastAttacker' is not possible.\n");
}
GCBaseEntity GCBreakableProp::GetFlareEnt() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBreakableProp", "m_hFlareEnt"));
    return value;
}
void GCBreakableProp::SetFlareEnt(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'FlareEnt' is not possible.\n");
}
bool GCBreakableProp::GetUsePuntSound() const {
    return GetSchemaValue<bool>(m_ptr, "CBreakableProp", "m_bUsePuntSound");
}
void GCBreakableProp::SetUsePuntSound(bool value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_bUsePuntSound", false, value);
}
std::string GCBreakableProp::GetPuntSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakableProp", "m_iszPuntSound").String();
}
void GCBreakableProp::SetPuntSound(std::string value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_iszPuntSound", false, CUtlSymbolLarge(value.c_str()));
}
bool GCBreakableProp::GetNoGhostCollision() const {
    return GetSchemaValue<bool>(m_ptr, "CBreakableProp", "m_noGhostCollision");
}
void GCBreakableProp::SetNoGhostCollision(bool value) {
    SetSchemaValue(m_ptr, "CBreakableProp", "m_noGhostCollision", false, value);
}
std::string GCBreakableProp::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBreakableProp::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseProp GCBreakableProp::GetParent() const {
    GCBaseProp value(m_ptr);
    return value;
}
void GCBreakableProp::SetParent(GCBaseProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBreakableProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBreakableProp>("CBreakableProp")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CPropDataComponent", &GCBreakableProp::GetCPropDataComponent, &GCBreakableProp::SetCPropDataComponent)
        .addProperty("OnBreak", &GCBreakableProp::GetOnBreak, &GCBreakableProp::SetOnBreak)
        .addProperty("OnTakeDamage", &GCBreakableProp::GetOnTakeDamage, &GCBreakableProp::SetOnTakeDamage)
        .addProperty("ImpactEnergyScale", &GCBreakableProp::GetImpactEnergyScale, &GCBreakableProp::SetImpactEnergyScale)
        .addProperty("MinHealthDmg", &GCBreakableProp::GetMinHealthDmg, &GCBreakableProp::SetMinHealthDmg)
        .addProperty("PreferredCarryAngles", &GCBreakableProp::GetPreferredCarryAngles, &GCBreakableProp::SetPreferredCarryAngles)
        .addProperty("PressureDelay", &GCBreakableProp::GetPressureDelay, &GCBreakableProp::SetPressureDelay)
        .addProperty("DefBurstScale", &GCBreakableProp::GetDefBurstScale, &GCBreakableProp::SetDefBurstScale)
        .addProperty("DefBurstOffset", &GCBreakableProp::GetDefBurstOffset, &GCBreakableProp::SetDefBurstOffset)
        .addProperty("Breaker", &GCBreakableProp::GetBreaker, &GCBreakableProp::SetBreaker)
        .addProperty("PerformanceMode", &GCBreakableProp::GetPerformanceMode, &GCBreakableProp::SetPerformanceMode)
        .addProperty("PreventDamageBeforeTime", &GCBreakableProp::GetPreventDamageBeforeTime, &GCBreakableProp::SetPreventDamageBeforeTime)
        .addProperty("HasBreakPiecesOrCommands", &GCBreakableProp::GetHasBreakPiecesOrCommands, &GCBreakableProp::SetHasBreakPiecesOrCommands)
        .addProperty("ExplodeDamage", &GCBreakableProp::GetExplodeDamage, &GCBreakableProp::SetExplodeDamage)
        .addProperty("ExplodeRadius", &GCBreakableProp::GetExplodeRadius, &GCBreakableProp::SetExplodeRadius)
        .addProperty("ExplosionDelay", &GCBreakableProp::GetExplosionDelay, &GCBreakableProp::SetExplosionDelay)
        .addProperty("ExplosionBuildupSound", &GCBreakableProp::GetExplosionBuildupSound, &GCBreakableProp::SetExplosionBuildupSound)
        .addProperty("ExplosionCustomEffect", &GCBreakableProp::GetExplosionCustomEffect, &GCBreakableProp::SetExplosionCustomEffect)
        .addProperty("ExplosionCustomSound", &GCBreakableProp::GetExplosionCustomSound, &GCBreakableProp::SetExplosionCustomSound)
        .addProperty("ExplosionModifier", &GCBreakableProp::GetExplosionModifier, &GCBreakableProp::SetExplosionModifier)
        .addProperty("PhysicsAttacker", &GCBreakableProp::GetPhysicsAttacker, &GCBreakableProp::SetPhysicsAttacker)
        .addProperty("LastPhysicsInfluenceTime", &GCBreakableProp::GetLastPhysicsInfluenceTime, &GCBreakableProp::SetLastPhysicsInfluenceTime)
        .addProperty("OriginalBlockLOS", &GCBreakableProp::GetOriginalBlockLOS, &GCBreakableProp::SetOriginalBlockLOS)
        .addProperty("DefaultFadeScale", &GCBreakableProp::GetDefaultFadeScale, &GCBreakableProp::SetDefaultFadeScale)
        .addProperty("LastAttacker", &GCBreakableProp::GetLastAttacker, &GCBreakableProp::SetLastAttacker)
        .addProperty("FlareEnt", &GCBreakableProp::GetFlareEnt, &GCBreakableProp::SetFlareEnt)
        .addProperty("UsePuntSound", &GCBreakableProp::GetUsePuntSound, &GCBreakableProp::SetUsePuntSound)
        .addProperty("PuntSound", &GCBreakableProp::GetPuntSound, &GCBreakableProp::SetPuntSound)
        .addProperty("NoGhostCollision", &GCBreakableProp::GetNoGhostCollision, &GCBreakableProp::SetNoGhostCollision)
        .addProperty("Parent", &GCBreakableProp::GetParent, &GCBreakableProp::SetParent)
        .addFunction("ToPtr", &GCBreakableProp::ToPtr)
        .addFunction("IsValid", &GCBreakableProp::IsValid)
        .endClass();
}