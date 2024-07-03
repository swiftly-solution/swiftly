#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPropDataComponent::GCPropDataComponent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPropDataComponent::GCPropDataComponent(void *ptr) {
    m_ptr = ptr;
}
float GCPropDataComponent::GetDmgModBullet() const {
    return GetSchemaValue<float>(m_ptr, "CPropDataComponent", "m_flDmgModBullet");
}
void GCPropDataComponent::SetDmgModBullet(float value) {
    SetSchemaValue(m_ptr, "CPropDataComponent", "m_flDmgModBullet", false, value);
}
float GCPropDataComponent::GetDmgModClub() const {
    return GetSchemaValue<float>(m_ptr, "CPropDataComponent", "m_flDmgModClub");
}
void GCPropDataComponent::SetDmgModClub(float value) {
    SetSchemaValue(m_ptr, "CPropDataComponent", "m_flDmgModClub", false, value);
}
float GCPropDataComponent::GetDmgModExplosive() const {
    return GetSchemaValue<float>(m_ptr, "CPropDataComponent", "m_flDmgModExplosive");
}
void GCPropDataComponent::SetDmgModExplosive(float value) {
    SetSchemaValue(m_ptr, "CPropDataComponent", "m_flDmgModExplosive", false, value);
}
float GCPropDataComponent::GetDmgModFire() const {
    return GetSchemaValue<float>(m_ptr, "CPropDataComponent", "m_flDmgModFire");
}
void GCPropDataComponent::SetDmgModFire(float value) {
    SetSchemaValue(m_ptr, "CPropDataComponent", "m_flDmgModFire", false, value);
}
std::string GCPropDataComponent::GetPhysicsDamageTableName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPropDataComponent", "m_iszPhysicsDamageTableName").String();
}
void GCPropDataComponent::SetPhysicsDamageTableName(std::string value) {
    SetSchemaValue(m_ptr, "CPropDataComponent", "m_iszPhysicsDamageTableName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPropDataComponent::GetBasePropData() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPropDataComponent", "m_iszBasePropData").String();
}
void GCPropDataComponent::SetBasePropData(std::string value) {
    SetSchemaValue(m_ptr, "CPropDataComponent", "m_iszBasePropData", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCPropDataComponent::GetInteractions() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPropDataComponent", "m_nInteractions");
}
void GCPropDataComponent::SetInteractions(int32_t value) {
    SetSchemaValue(m_ptr, "CPropDataComponent", "m_nInteractions", false, value);
}
bool GCPropDataComponent::GetSpawnMotionDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPropDataComponent", "m_bSpawnMotionDisabled");
}
void GCPropDataComponent::SetSpawnMotionDisabled(bool value) {
    SetSchemaValue(m_ptr, "CPropDataComponent", "m_bSpawnMotionDisabled", false, value);
}
int32_t GCPropDataComponent::GetDisableTakePhysicsDamageSpawnFlag() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPropDataComponent", "m_nDisableTakePhysicsDamageSpawnFlag");
}
void GCPropDataComponent::SetDisableTakePhysicsDamageSpawnFlag(int32_t value) {
    SetSchemaValue(m_ptr, "CPropDataComponent", "m_nDisableTakePhysicsDamageSpawnFlag", false, value);
}
int32_t GCPropDataComponent::GetMotionDisabledSpawnFlag() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPropDataComponent", "m_nMotionDisabledSpawnFlag");
}
void GCPropDataComponent::SetMotionDisabledSpawnFlag(int32_t value) {
    SetSchemaValue(m_ptr, "CPropDataComponent", "m_nMotionDisabledSpawnFlag", false, value);
}
std::string GCPropDataComponent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPropDataComponent::IsValid() {
    return (m_ptr != nullptr);
}
GCEntityComponent GCPropDataComponent::GetParent() const {
    GCEntityComponent value(m_ptr);
    return value;
}
void GCPropDataComponent::SetParent(GCEntityComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPropDataComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPropDataComponent>("CPropDataComponent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DmgModBullet", &GCPropDataComponent::GetDmgModBullet, &GCPropDataComponent::SetDmgModBullet)
        .addProperty("DmgModClub", &GCPropDataComponent::GetDmgModClub, &GCPropDataComponent::SetDmgModClub)
        .addProperty("DmgModExplosive", &GCPropDataComponent::GetDmgModExplosive, &GCPropDataComponent::SetDmgModExplosive)
        .addProperty("DmgModFire", &GCPropDataComponent::GetDmgModFire, &GCPropDataComponent::SetDmgModFire)
        .addProperty("PhysicsDamageTableName", &GCPropDataComponent::GetPhysicsDamageTableName, &GCPropDataComponent::SetPhysicsDamageTableName)
        .addProperty("BasePropData", &GCPropDataComponent::GetBasePropData, &GCPropDataComponent::SetBasePropData)
        .addProperty("Interactions", &GCPropDataComponent::GetInteractions, &GCPropDataComponent::SetInteractions)
        .addProperty("SpawnMotionDisabled", &GCPropDataComponent::GetSpawnMotionDisabled, &GCPropDataComponent::SetSpawnMotionDisabled)
        .addProperty("DisableTakePhysicsDamageSpawnFlag", &GCPropDataComponent::GetDisableTakePhysicsDamageSpawnFlag, &GCPropDataComponent::SetDisableTakePhysicsDamageSpawnFlag)
        .addProperty("MotionDisabledSpawnFlag", &GCPropDataComponent::GetMotionDisabledSpawnFlag, &GCPropDataComponent::SetMotionDisabledSpawnFlag)
        .addProperty("Parent", &GCPropDataComponent::GetParent, &GCPropDataComponent::SetParent)
        .addFunction("ToPtr", &GCPropDataComponent::ToPtr)
        .addFunction("IsValid", &GCPropDataComponent::IsValid)
        .endClass();
}