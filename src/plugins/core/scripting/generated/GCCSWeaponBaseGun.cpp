#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSWeaponBaseGun::GCCSWeaponBaseGun(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSWeaponBaseGun::GCCSWeaponBaseGun(void *ptr) {
    m_ptr = ptr;
}
int32_t GCCSWeaponBaseGun::GetZoomLevel() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseGun", "m_zoomLevel");
}
void GCCSWeaponBaseGun::SetZoomLevel(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_zoomLevel", false, value);
}
int32_t GCCSWeaponBaseGun::GetBurstShotsRemaining() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseGun", "m_iBurstShotsRemaining");
}
void GCCSWeaponBaseGun::SetBurstShotsRemaining(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_iBurstShotsRemaining", false, value);
}
int32_t GCCSWeaponBaseGun::GetSilencedModelIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseGun", "m_silencedModelIndex");
}
void GCCSWeaponBaseGun::SetSilencedModelIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_silencedModelIndex", false, value);
}
bool GCCSWeaponBaseGun::GetInPrecache() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_inPrecache");
}
void GCCSWeaponBaseGun::SetInPrecache(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_inPrecache", false, value);
}
bool GCCSWeaponBaseGun::GetNeedsBoltAction() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_bNeedsBoltAction");
}
void GCCSWeaponBaseGun::SetNeedsBoltAction(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_bNeedsBoltAction", false, value);
}
bool GCCSWeaponBaseGun::GetSkillReloadAvailable() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_bSkillReloadAvailable");
}
void GCCSWeaponBaseGun::SetSkillReloadAvailable(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_bSkillReloadAvailable", false, value);
}
bool GCCSWeaponBaseGun::GetSkillReloadLiftedReloadKey() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_bSkillReloadLiftedReloadKey");
}
void GCCSWeaponBaseGun::SetSkillReloadLiftedReloadKey(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_bSkillReloadLiftedReloadKey", false, value);
}
bool GCCSWeaponBaseGun::GetSkillBoltInterruptAvailable() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_bSkillBoltInterruptAvailable");
}
void GCCSWeaponBaseGun::SetSkillBoltInterruptAvailable(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_bSkillBoltInterruptAvailable", false, value);
}
bool GCCSWeaponBaseGun::GetSkillBoltLiftedFireKey() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_bSkillBoltLiftedFireKey");
}
void GCCSWeaponBaseGun::SetSkillBoltLiftedFireKey(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_bSkillBoltLiftedFireKey", false, value);
}
std::string GCCSWeaponBaseGun::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSWeaponBaseGun::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCCSWeaponBaseGun::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCCSWeaponBaseGun::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSWeaponBaseGun(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSWeaponBaseGun>("CCSWeaponBaseGun")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ZoomLevel", &GCCSWeaponBaseGun::GetZoomLevel, &GCCSWeaponBaseGun::SetZoomLevel)
        .addProperty("BurstShotsRemaining", &GCCSWeaponBaseGun::GetBurstShotsRemaining, &GCCSWeaponBaseGun::SetBurstShotsRemaining)
        .addProperty("SilencedModelIndex", &GCCSWeaponBaseGun::GetSilencedModelIndex, &GCCSWeaponBaseGun::SetSilencedModelIndex)
        .addProperty("InPrecache", &GCCSWeaponBaseGun::GetInPrecache, &GCCSWeaponBaseGun::SetInPrecache)
        .addProperty("NeedsBoltAction", &GCCSWeaponBaseGun::GetNeedsBoltAction, &GCCSWeaponBaseGun::SetNeedsBoltAction)
        .addProperty("SkillReloadAvailable", &GCCSWeaponBaseGun::GetSkillReloadAvailable, &GCCSWeaponBaseGun::SetSkillReloadAvailable)
        .addProperty("SkillReloadLiftedReloadKey", &GCCSWeaponBaseGun::GetSkillReloadLiftedReloadKey, &GCCSWeaponBaseGun::SetSkillReloadLiftedReloadKey)
        .addProperty("SkillBoltInterruptAvailable", &GCCSWeaponBaseGun::GetSkillBoltInterruptAvailable, &GCCSWeaponBaseGun::SetSkillBoltInterruptAvailable)
        .addProperty("SkillBoltLiftedFireKey", &GCCSWeaponBaseGun::GetSkillBoltLiftedFireKey, &GCCSWeaponBaseGun::SetSkillBoltLiftedFireKey)
        .addProperty("Parent", &GCCSWeaponBaseGun::GetParent, &GCCSWeaponBaseGun::SetParent)
        .addFunction("ToPtr", &GCCSWeaponBaseGun::ToPtr)
        .addFunction("IsValid", &GCCSWeaponBaseGun::IsValid)
        .endClass();
}