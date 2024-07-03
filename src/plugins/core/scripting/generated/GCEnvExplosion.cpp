#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvExplosion::GCEnvExplosion(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvExplosion::GCEnvExplosion(void *ptr) {
    m_ptr = ptr;
}
int32_t GCEnvExplosion::GetMagnitude() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvExplosion", "m_iMagnitude");
}
void GCEnvExplosion::SetMagnitude(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_iMagnitude", false, value);
}
float GCEnvExplosion::GetPlayerDamage() const {
    return GetSchemaValue<float>(m_ptr, "CEnvExplosion", "m_flPlayerDamage");
}
void GCEnvExplosion::SetPlayerDamage(float value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_flPlayerDamage", false, value);
}
int32_t GCEnvExplosion::GetRadiusOverride() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvExplosion", "m_iRadiusOverride");
}
void GCEnvExplosion::SetRadiusOverride(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_iRadiusOverride", false, value);
}
float GCEnvExplosion::GetInnerRadius() const {
    return GetSchemaValue<float>(m_ptr, "CEnvExplosion", "m_flInnerRadius");
}
void GCEnvExplosion::SetInnerRadius(float value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_flInnerRadius", false, value);
}
int32_t GCEnvExplosion::GetSpriteScale() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvExplosion", "m_spriteScale");
}
void GCEnvExplosion::SetSpriteScale(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_spriteScale", false, value);
}
float GCEnvExplosion::GetDamageForce() const {
    return GetSchemaValue<float>(m_ptr, "CEnvExplosion", "m_flDamageForce");
}
void GCEnvExplosion::SetDamageForce(float value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_flDamageForce", false, value);
}
GCBaseEntity GCEnvExplosion::GetInflictor() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CEnvExplosion", "m_hInflictor"));
    return value;
}
void GCEnvExplosion::SetInflictor(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Inflictor' is not possible.\n");
}
int32_t GCEnvExplosion::GetCustomDamageType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvExplosion", "m_iCustomDamageType");
}
void GCEnvExplosion::SetCustomDamageType(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_iCustomDamageType", false, value);
}
std::string GCEnvExplosion::GetExplosionType() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvExplosion", "m_iszExplosionType").String();
}
void GCEnvExplosion::SetExplosionType(std::string value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_iszExplosionType", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvExplosion::GetCustomEffectName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvExplosion", "m_iszCustomEffectName").String();
}
void GCEnvExplosion::SetCustomEffectName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_iszCustomEffectName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvExplosion::GetCustomSoundName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvExplosion", "m_iszCustomSoundName").String();
}
void GCEnvExplosion::SetCustomSoundName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_iszCustomSoundName", false, CUtlSymbolLarge(value.c_str()));
}
uint64_t GCEnvExplosion::GetClassIgnore() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CEnvExplosion", "m_iClassIgnore");
}
void GCEnvExplosion::SetClassIgnore(uint64_t value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_iClassIgnore", false, value);
}
uint64_t GCEnvExplosion::GetClassIgnore2() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CEnvExplosion", "m_iClassIgnore2");
}
void GCEnvExplosion::SetClassIgnore2(uint64_t value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_iClassIgnore2", false, value);
}
std::string GCEnvExplosion::GetEntityIgnoreName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvExplosion", "m_iszEntityIgnoreName").String();
}
void GCEnvExplosion::SetEntityIgnoreName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvExplosion", "m_iszEntityIgnoreName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCEnvExplosion::GetEntityIgnore() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CEnvExplosion", "m_hEntityIgnore"));
    return value;
}
void GCEnvExplosion::SetEntityIgnore(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'EntityIgnore' is not possible.\n");
}
std::string GCEnvExplosion::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvExplosion::IsValid() {
    return (m_ptr != nullptr);
}
GCModelPointEntity GCEnvExplosion::GetParent() const {
    GCModelPointEntity value(m_ptr);
    return value;
}
void GCEnvExplosion::SetParent(GCModelPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvExplosion(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvExplosion>("CEnvExplosion")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Magnitude", &GCEnvExplosion::GetMagnitude, &GCEnvExplosion::SetMagnitude)
        .addProperty("PlayerDamage", &GCEnvExplosion::GetPlayerDamage, &GCEnvExplosion::SetPlayerDamage)
        .addProperty("RadiusOverride", &GCEnvExplosion::GetRadiusOverride, &GCEnvExplosion::SetRadiusOverride)
        .addProperty("InnerRadius", &GCEnvExplosion::GetInnerRadius, &GCEnvExplosion::SetInnerRadius)
        .addProperty("SpriteScale", &GCEnvExplosion::GetSpriteScale, &GCEnvExplosion::SetSpriteScale)
        .addProperty("DamageForce", &GCEnvExplosion::GetDamageForce, &GCEnvExplosion::SetDamageForce)
        .addProperty("Inflictor", &GCEnvExplosion::GetInflictor, &GCEnvExplosion::SetInflictor)
        .addProperty("CustomDamageType", &GCEnvExplosion::GetCustomDamageType, &GCEnvExplosion::SetCustomDamageType)
        .addProperty("ExplosionType", &GCEnvExplosion::GetExplosionType, &GCEnvExplosion::SetExplosionType)
        .addProperty("CustomEffectName", &GCEnvExplosion::GetCustomEffectName, &GCEnvExplosion::SetCustomEffectName)
        .addProperty("CustomSoundName", &GCEnvExplosion::GetCustomSoundName, &GCEnvExplosion::SetCustomSoundName)
        .addProperty("ClassIgnore", &GCEnvExplosion::GetClassIgnore, &GCEnvExplosion::SetClassIgnore)
        .addProperty("ClassIgnore2", &GCEnvExplosion::GetClassIgnore2, &GCEnvExplosion::SetClassIgnore2)
        .addProperty("EntityIgnoreName", &GCEnvExplosion::GetEntityIgnoreName, &GCEnvExplosion::SetEntityIgnoreName)
        .addProperty("EntityIgnore", &GCEnvExplosion::GetEntityIgnore, &GCEnvExplosion::SetEntityIgnore)
        .addProperty("Parent", &GCEnvExplosion::GetParent, &GCEnvExplosion::SetParent)
        .addFunction("ToPtr", &GCEnvExplosion::ToPtr)
        .addFunction("IsValid", &GCEnvExplosion::IsValid)
        .endClass();
}