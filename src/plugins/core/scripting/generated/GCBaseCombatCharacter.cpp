#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseCombatCharacter::GCBaseCombatCharacter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseCombatCharacter::GCBaseCombatCharacter(void *ptr) {
    m_ptr = ptr;
}
bool GCBaseCombatCharacter::GetForceServerRagdoll() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseCombatCharacter", "m_bForceServerRagdoll");
}
void GCBaseCombatCharacter::SetForceServerRagdoll(bool value) {
    SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_bForceServerRagdoll", false, value);
}
std::vector<GCEconWearable*> GCBaseCombatCharacter::GetMyWearables() const {
    CUtlVector<GCEconWearable*>* vec = GetSchemaValue<CUtlVector<GCEconWearable*>*>(m_ptr, "CBaseCombatCharacter", "m_hMyWearables"); std::vector<GCEconWearable*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBaseCombatCharacter::SetMyWearables(std::vector<GCEconWearable*> value) {
    SetSchemaValueCUtlVector<GCEconWearable*>(m_ptr, "CBaseCombatCharacter", "m_hMyWearables", false, value);
}
float GCBaseCombatCharacter::GetFieldOfView() const {
    return GetSchemaValue<float>(m_ptr, "CBaseCombatCharacter", "m_flFieldOfView");
}
void GCBaseCombatCharacter::SetFieldOfView(float value) {
    SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_flFieldOfView", false, value);
}
float GCBaseCombatCharacter::GetImpactEnergyScale() const {
    return GetSchemaValue<float>(m_ptr, "CBaseCombatCharacter", "m_impactEnergyScale");
}
void GCBaseCombatCharacter::SetImpactEnergyScale(float value) {
    SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_impactEnergyScale", false, value);
}
uint64_t GCBaseCombatCharacter::GetLastHitGroup() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseCombatCharacter", "m_LastHitGroup");
}
void GCBaseCombatCharacter::SetLastHitGroup(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_LastHitGroup", false, value);
}
bool GCBaseCombatCharacter::GetApplyStressDamage() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseCombatCharacter", "m_bApplyStressDamage");
}
void GCBaseCombatCharacter::SetApplyStressDamage(bool value) {
    SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_bApplyStressDamage", false, value);
}
int32_t GCBaseCombatCharacter::GetDamageCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseCombatCharacter", "m_iDamageCount");
}
void GCBaseCombatCharacter::SetDamageCount(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_iDamageCount", false, value);
}
std::string GCBaseCombatCharacter::GetStrRelationships() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseCombatCharacter", "m_strRelationships").String();
}
void GCBaseCombatCharacter::SetStrRelationships(std::string value) {
    SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_strRelationships", false, CUtlSymbolLarge(value.c_str()));
}
uint64_t GCBaseCombatCharacter::GetHull() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseCombatCharacter", "m_eHull");
}
void GCBaseCombatCharacter::SetHull(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_eHull", false, value);
}
uint32_t GCBaseCombatCharacter::GetNavHullIdx() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBaseCombatCharacter", "m_nNavHullIdx");
}
void GCBaseCombatCharacter::SetNavHullIdx(uint32_t value) {
    SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_nNavHullIdx", false, value);
}
std::string GCBaseCombatCharacter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseCombatCharacter::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFlex GCBaseCombatCharacter::GetParent() const {
    GCBaseFlex value(m_ptr);
    return value;
}
void GCBaseCombatCharacter::SetParent(GCBaseFlex value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseCombatCharacter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseCombatCharacter>("CBaseCombatCharacter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ForceServerRagdoll", &GCBaseCombatCharacter::GetForceServerRagdoll, &GCBaseCombatCharacter::SetForceServerRagdoll)
        .addProperty("MyWearables", &GCBaseCombatCharacter::GetMyWearables, &GCBaseCombatCharacter::SetMyWearables)
        .addProperty("FieldOfView", &GCBaseCombatCharacter::GetFieldOfView, &GCBaseCombatCharacter::SetFieldOfView)
        .addProperty("ImpactEnergyScale", &GCBaseCombatCharacter::GetImpactEnergyScale, &GCBaseCombatCharacter::SetImpactEnergyScale)
        .addProperty("LastHitGroup", &GCBaseCombatCharacter::GetLastHitGroup, &GCBaseCombatCharacter::SetLastHitGroup)
        .addProperty("ApplyStressDamage", &GCBaseCombatCharacter::GetApplyStressDamage, &GCBaseCombatCharacter::SetApplyStressDamage)
        .addProperty("DamageCount", &GCBaseCombatCharacter::GetDamageCount, &GCBaseCombatCharacter::SetDamageCount)
        .addProperty("StrRelationships", &GCBaseCombatCharacter::GetStrRelationships, &GCBaseCombatCharacter::SetStrRelationships)
        .addProperty("Hull", &GCBaseCombatCharacter::GetHull, &GCBaseCombatCharacter::SetHull)
        .addProperty("NavHullIdx", &GCBaseCombatCharacter::GetNavHullIdx, &GCBaseCombatCharacter::SetNavHullIdx)
        .addProperty("Parent", &GCBaseCombatCharacter::GetParent, &GCBaseCombatCharacter::SetParent)
        .addFunction("ToPtr", &GCBaseCombatCharacter::ToPtr)
        .addFunction("IsValid", &GCBaseCombatCharacter::IsValid)
        .endClass();
}