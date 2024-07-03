#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBombTarget::GCBombTarget(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBombTarget::GCBombTarget(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCBombTarget::GetOnBombExplode() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBombTarget", "m_OnBombExplode"));
    return value;
}
void GCBombTarget::SetOnBombExplode(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBombTarget", "m_OnBombExplode", false, value);
}
GCEntityIOOutput GCBombTarget::GetOnBombPlanted() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBombTarget", "m_OnBombPlanted"));
    return value;
}
void GCBombTarget::SetOnBombPlanted(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBombTarget", "m_OnBombPlanted", false, value);
}
GCEntityIOOutput GCBombTarget::GetOnBombDefused() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBombTarget", "m_OnBombDefused"));
    return value;
}
void GCBombTarget::SetOnBombDefused(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBombTarget", "m_OnBombDefused", false, value);
}
bool GCBombTarget::GetIsBombSiteB() const {
    return GetSchemaValue<bool>(m_ptr, "CBombTarget", "m_bIsBombSiteB");
}
void GCBombTarget::SetIsBombSiteB(bool value) {
    SetSchemaValue(m_ptr, "CBombTarget", "m_bIsBombSiteB", false, value);
}
bool GCBombTarget::GetIsHeistBombTarget() const {
    return GetSchemaValue<bool>(m_ptr, "CBombTarget", "m_bIsHeistBombTarget");
}
void GCBombTarget::SetIsHeistBombTarget(bool value) {
    SetSchemaValue(m_ptr, "CBombTarget", "m_bIsHeistBombTarget", false, value);
}
bool GCBombTarget::GetBombPlantedHere() const {
    return GetSchemaValue<bool>(m_ptr, "CBombTarget", "m_bBombPlantedHere");
}
void GCBombTarget::SetBombPlantedHere(bool value) {
    SetSchemaValue(m_ptr, "CBombTarget", "m_bBombPlantedHere", false, value);
}
std::string GCBombTarget::GetMountTarget() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBombTarget", "m_szMountTarget").String();
}
void GCBombTarget::SetMountTarget(std::string value) {
    SetSchemaValue(m_ptr, "CBombTarget", "m_szMountTarget", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCBombTarget::GetInstructorHint() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBombTarget", "m_hInstructorHint"));
    return value;
}
void GCBombTarget::SetInstructorHint(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'InstructorHint' is not possible.\n");
}
int32_t GCBombTarget::GetBombSiteDesignation() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBombTarget", "m_nBombSiteDesignation");
}
void GCBombTarget::SetBombSiteDesignation(int32_t value) {
    SetSchemaValue(m_ptr, "CBombTarget", "m_nBombSiteDesignation", false, value);
}
std::string GCBombTarget::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBombTarget::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCBombTarget::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCBombTarget::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBombTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBombTarget>("CBombTarget")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnBombExplode", &GCBombTarget::GetOnBombExplode, &GCBombTarget::SetOnBombExplode)
        .addProperty("OnBombPlanted", &GCBombTarget::GetOnBombPlanted, &GCBombTarget::SetOnBombPlanted)
        .addProperty("OnBombDefused", &GCBombTarget::GetOnBombDefused, &GCBombTarget::SetOnBombDefused)
        .addProperty("IsBombSiteB", &GCBombTarget::GetIsBombSiteB, &GCBombTarget::SetIsBombSiteB)
        .addProperty("IsHeistBombTarget", &GCBombTarget::GetIsHeistBombTarget, &GCBombTarget::SetIsHeistBombTarget)
        .addProperty("BombPlantedHere", &GCBombTarget::GetBombPlantedHere, &GCBombTarget::SetBombPlantedHere)
        .addProperty("MountTarget", &GCBombTarget::GetMountTarget, &GCBombTarget::SetMountTarget)
        .addProperty("InstructorHint", &GCBombTarget::GetInstructorHint, &GCBombTarget::SetInstructorHint)
        .addProperty("BombSiteDesignation", &GCBombTarget::GetBombSiteDesignation, &GCBombTarget::SetBombSiteDesignation)
        .addProperty("Parent", &GCBombTarget::GetParent, &GCBombTarget::SetParent)
        .addFunction("ToPtr", &GCBombTarget::ToPtr)
        .addFunction("IsValid", &GCBombTarget::IsValid)
        .endClass();
}