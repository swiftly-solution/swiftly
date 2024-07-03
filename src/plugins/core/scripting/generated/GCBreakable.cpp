#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBreakable::GCBreakable(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBreakable::GCBreakable(void *ptr) {
    m_ptr = ptr;
}
GCPropDataComponent GCBreakable::GetCPropDataComponent() const {
    GCPropDataComponent value(GetSchemaPtr(m_ptr, "CBreakable", "m_CPropDataComponent"));
    return value;
}
void GCBreakable::SetCPropDataComponent(GCPropDataComponent value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_CPropDataComponent", false, value);
}
uint64_t GCBreakable::GetMaterial() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBreakable", "m_Material");
}
void GCBreakable::SetMaterial(uint64_t value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_Material", false, value);
}
GCBaseEntity GCBreakable::GetBreaker() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBreakable", "m_hBreaker"));
    return value;
}
void GCBreakable::SetBreaker(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Breaker' is not possible.\n");
}
uint64_t GCBreakable::GetExplosion() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBreakable", "m_Explosion");
}
void GCBreakable::SetExplosion(uint64_t value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_Explosion", false, value);
}
std::string GCBreakable::GetSpawnObject() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakable", "m_iszSpawnObject").String();
}
void GCBreakable::SetSpawnObject(std::string value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_iszSpawnObject", false, CUtlSymbolLarge(value.c_str()));
}
float GCBreakable::GetPressureDelay() const {
    return GetSchemaValue<float>(m_ptr, "CBreakable", "m_flPressureDelay");
}
void GCBreakable::SetPressureDelay(float value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_flPressureDelay", false, value);
}
int32_t GCBreakable::GetMinHealthDmg() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBreakable", "m_iMinHealthDmg");
}
void GCBreakable::SetMinHealthDmg(int32_t value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_iMinHealthDmg", false, value);
}
std::string GCBreakable::GetPropData() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakable", "m_iszPropData").String();
}
void GCBreakable::SetPropData(std::string value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_iszPropData", false, CUtlSymbolLarge(value.c_str()));
}
float GCBreakable::GetImpactEnergyScale() const {
    return GetSchemaValue<float>(m_ptr, "CBreakable", "m_impactEnergyScale");
}
void GCBreakable::SetImpactEnergyScale(float value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_impactEnergyScale", false, value);
}
uint64_t GCBreakable::GetOverrideBlockLOS() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBreakable", "m_nOverrideBlockLOS");
}
void GCBreakable::SetOverrideBlockLOS(uint64_t value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_nOverrideBlockLOS", false, value);
}
GCEntityIOOutput GCBreakable::GetOnBreak() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBreakable", "m_OnBreak"));
    return value;
}
void GCBreakable::SetOnBreak(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_OnBreak", false, value);
}
uint64_t GCBreakable::GetPerformanceMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBreakable", "m_PerformanceMode");
}
void GCBreakable::SetPerformanceMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_PerformanceMode", false, value);
}
GCBasePlayerPawn GCBreakable::GetPhysicsAttacker() const {
    GCBasePlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CBreakable", "m_hPhysicsAttacker"));
    return value;
}
void GCBreakable::SetPhysicsAttacker(GCBasePlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PhysicsAttacker' is not possible.\n");
}
float GCBreakable::GetLastPhysicsInfluenceTime() const {
    return GetSchemaValue<float>(m_ptr, "CBreakable", "m_flLastPhysicsInfluenceTime");
}
void GCBreakable::SetLastPhysicsInfluenceTime(float value) {
    SetSchemaValue(m_ptr, "CBreakable", "m_flLastPhysicsInfluenceTime", false, value);
}
std::string GCBreakable::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBreakable::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCBreakable::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCBreakable::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBreakable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBreakable>("CBreakable")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CPropDataComponent", &GCBreakable::GetCPropDataComponent, &GCBreakable::SetCPropDataComponent)
        .addProperty("Material", &GCBreakable::GetMaterial, &GCBreakable::SetMaterial)
        .addProperty("Breaker", &GCBreakable::GetBreaker, &GCBreakable::SetBreaker)
        .addProperty("Explosion", &GCBreakable::GetExplosion, &GCBreakable::SetExplosion)
        .addProperty("SpawnObject", &GCBreakable::GetSpawnObject, &GCBreakable::SetSpawnObject)
        .addProperty("PressureDelay", &GCBreakable::GetPressureDelay, &GCBreakable::SetPressureDelay)
        .addProperty("MinHealthDmg", &GCBreakable::GetMinHealthDmg, &GCBreakable::SetMinHealthDmg)
        .addProperty("PropData", &GCBreakable::GetPropData, &GCBreakable::SetPropData)
        .addProperty("ImpactEnergyScale", &GCBreakable::GetImpactEnergyScale, &GCBreakable::SetImpactEnergyScale)
        .addProperty("OverrideBlockLOS", &GCBreakable::GetOverrideBlockLOS, &GCBreakable::SetOverrideBlockLOS)
        .addProperty("OnBreak", &GCBreakable::GetOnBreak, &GCBreakable::SetOnBreak)
        .addProperty("PerformanceMode", &GCBreakable::GetPerformanceMode, &GCBreakable::SetPerformanceMode)
        .addProperty("PhysicsAttacker", &GCBreakable::GetPhysicsAttacker, &GCBreakable::SetPhysicsAttacker)
        .addProperty("LastPhysicsInfluenceTime", &GCBreakable::GetLastPhysicsInfluenceTime, &GCBreakable::SetLastPhysicsInfluenceTime)
        .addProperty("Parent", &GCBreakable::GetParent, &GCBreakable::SetParent)
        .addFunction("ToPtr", &GCBreakable::ToPtr)
        .addFunction("IsValid", &GCBreakable::IsValid)
        .endClass();
}