#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysSurfacePropertiesSoundNames::GCPhysSurfacePropertiesSoundNames(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysSurfacePropertiesSoundNames::GCPhysSurfacePropertiesSoundNames(void *ptr) {
    m_ptr = ptr;
}
std::string GCPhysSurfacePropertiesSoundNames::GetImpactSoft() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_impactSoft").Get();
}
void GCPhysSurfacePropertiesSoundNames::SetImpactSoft(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_impactSoft", false, CUtlString(value.c_str()));
}
std::string GCPhysSurfacePropertiesSoundNames::GetImpactHard() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_impactHard").Get();
}
void GCPhysSurfacePropertiesSoundNames::SetImpactHard(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_impactHard", false, CUtlString(value.c_str()));
}
std::string GCPhysSurfacePropertiesSoundNames::GetScrapeSmooth() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_scrapeSmooth").Get();
}
void GCPhysSurfacePropertiesSoundNames::SetScrapeSmooth(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_scrapeSmooth", false, CUtlString(value.c_str()));
}
std::string GCPhysSurfacePropertiesSoundNames::GetScrapeRough() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_scrapeRough").Get();
}
void GCPhysSurfacePropertiesSoundNames::SetScrapeRough(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_scrapeRough", false, CUtlString(value.c_str()));
}
std::string GCPhysSurfacePropertiesSoundNames::GetBulletImpact() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_bulletImpact").Get();
}
void GCPhysSurfacePropertiesSoundNames::SetBulletImpact(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_bulletImpact", false, CUtlString(value.c_str()));
}
std::string GCPhysSurfacePropertiesSoundNames::GetRolling() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_rolling").Get();
}
void GCPhysSurfacePropertiesSoundNames::SetRolling(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_rolling", false, CUtlString(value.c_str()));
}
std::string GCPhysSurfacePropertiesSoundNames::GetBreak() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_break").Get();
}
void GCPhysSurfacePropertiesSoundNames::SetBreak(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_break", false, CUtlString(value.c_str()));
}
std::string GCPhysSurfacePropertiesSoundNames::GetStrain() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_strain").Get();
}
void GCPhysSurfacePropertiesSoundNames::SetStrain(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_strain", false, CUtlString(value.c_str()));
}
std::string GCPhysSurfacePropertiesSoundNames::GetMeleeImpact() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_meleeImpact").Get();
}
void GCPhysSurfacePropertiesSoundNames::SetMeleeImpact(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_meleeImpact", false, CUtlString(value.c_str()));
}
std::string GCPhysSurfacePropertiesSoundNames::GetPushOff() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_pushOff").Get();
}
void GCPhysSurfacePropertiesSoundNames::SetPushOff(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_pushOff", false, CUtlString(value.c_str()));
}
std::string GCPhysSurfacePropertiesSoundNames::GetSkidStop() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_skidStop").Get();
}
void GCPhysSurfacePropertiesSoundNames::SetSkidStop(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_skidStop", false, CUtlString(value.c_str()));
}
std::string GCPhysSurfacePropertiesSoundNames::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysSurfacePropertiesSoundNames::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCPhysSurfacePropertiesSoundNames(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysSurfacePropertiesSoundNames>("CPhysSurfacePropertiesSoundNames")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ImpactSoft", &GCPhysSurfacePropertiesSoundNames::GetImpactSoft, &GCPhysSurfacePropertiesSoundNames::SetImpactSoft)
        .addProperty("ImpactHard", &GCPhysSurfacePropertiesSoundNames::GetImpactHard, &GCPhysSurfacePropertiesSoundNames::SetImpactHard)
        .addProperty("ScrapeSmooth", &GCPhysSurfacePropertiesSoundNames::GetScrapeSmooth, &GCPhysSurfacePropertiesSoundNames::SetScrapeSmooth)
        .addProperty("ScrapeRough", &GCPhysSurfacePropertiesSoundNames::GetScrapeRough, &GCPhysSurfacePropertiesSoundNames::SetScrapeRough)
        .addProperty("BulletImpact", &GCPhysSurfacePropertiesSoundNames::GetBulletImpact, &GCPhysSurfacePropertiesSoundNames::SetBulletImpact)
        .addProperty("Rolling", &GCPhysSurfacePropertiesSoundNames::GetRolling, &GCPhysSurfacePropertiesSoundNames::SetRolling)
        .addProperty("Break", &GCPhysSurfacePropertiesSoundNames::GetBreak, &GCPhysSurfacePropertiesSoundNames::SetBreak)
        .addProperty("Strain", &GCPhysSurfacePropertiesSoundNames::GetStrain, &GCPhysSurfacePropertiesSoundNames::SetStrain)
        .addProperty("MeleeImpact", &GCPhysSurfacePropertiesSoundNames::GetMeleeImpact, &GCPhysSurfacePropertiesSoundNames::SetMeleeImpact)
        .addProperty("PushOff", &GCPhysSurfacePropertiesSoundNames::GetPushOff, &GCPhysSurfacePropertiesSoundNames::SetPushOff)
        .addProperty("SkidStop", &GCPhysSurfacePropertiesSoundNames::GetSkidStop, &GCPhysSurfacePropertiesSoundNames::SetSkidStop)
        .addFunction("ToPtr", &GCPhysSurfacePropertiesSoundNames::ToPtr)
        .addFunction("IsValid", &GCPhysSurfacePropertiesSoundNames::IsValid)
        .endClass();
}