#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysExplosion::GCPhysExplosion(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysExplosion::GCPhysExplosion(void *ptr) {
    m_ptr = ptr;
}
bool GCPhysExplosion::GetExplodeOnSpawn() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysExplosion", "m_bExplodeOnSpawn");
}
void GCPhysExplosion::SetExplodeOnSpawn(bool value) {
    SetSchemaValue(m_ptr, "CPhysExplosion", "m_bExplodeOnSpawn", false, value);
}
float GCPhysExplosion::GetMagnitude() const {
    return GetSchemaValue<float>(m_ptr, "CPhysExplosion", "m_flMagnitude");
}
void GCPhysExplosion::SetMagnitude(float value) {
    SetSchemaValue(m_ptr, "CPhysExplosion", "m_flMagnitude", false, value);
}
float GCPhysExplosion::GetDamage() const {
    return GetSchemaValue<float>(m_ptr, "CPhysExplosion", "m_flDamage");
}
void GCPhysExplosion::SetDamage(float value) {
    SetSchemaValue(m_ptr, "CPhysExplosion", "m_flDamage", false, value);
}
float GCPhysExplosion::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CPhysExplosion", "m_radius");
}
void GCPhysExplosion::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CPhysExplosion", "m_radius", false, value);
}
std::string GCPhysExplosion::GetTargetEntityName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysExplosion", "m_targetEntityName").String();
}
void GCPhysExplosion::SetTargetEntityName(std::string value) {
    SetSchemaValue(m_ptr, "CPhysExplosion", "m_targetEntityName", false, CUtlSymbolLarge(value.c_str()));
}
float GCPhysExplosion::GetInnerRadius() const {
    return GetSchemaValue<float>(m_ptr, "CPhysExplosion", "m_flInnerRadius");
}
void GCPhysExplosion::SetInnerRadius(float value) {
    SetSchemaValue(m_ptr, "CPhysExplosion", "m_flInnerRadius", false, value);
}
float GCPhysExplosion::GetPushScale() const {
    return GetSchemaValue<float>(m_ptr, "CPhysExplosion", "m_flPushScale");
}
void GCPhysExplosion::SetPushScale(float value) {
    SetSchemaValue(m_ptr, "CPhysExplosion", "m_flPushScale", false, value);
}
bool GCPhysExplosion::GetConvertToDebrisWhenPossible() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysExplosion", "m_bConvertToDebrisWhenPossible");
}
void GCPhysExplosion::SetConvertToDebrisWhenPossible(bool value) {
    SetSchemaValue(m_ptr, "CPhysExplosion", "m_bConvertToDebrisWhenPossible", false, value);
}
GCEntityIOOutput GCPhysExplosion::GetOnPushedPlayer() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysExplosion", "m_OnPushedPlayer"));
    return value;
}
void GCPhysExplosion::SetOnPushedPlayer(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysExplosion", "m_OnPushedPlayer", false, value);
}
std::string GCPhysExplosion::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysExplosion::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPhysExplosion::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPhysExplosion::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysExplosion(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysExplosion>("CPhysExplosion")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ExplodeOnSpawn", &GCPhysExplosion::GetExplodeOnSpawn, &GCPhysExplosion::SetExplodeOnSpawn)
        .addProperty("Magnitude", &GCPhysExplosion::GetMagnitude, &GCPhysExplosion::SetMagnitude)
        .addProperty("Damage", &GCPhysExplosion::GetDamage, &GCPhysExplosion::SetDamage)
        .addProperty("Radius", &GCPhysExplosion::GetRadius, &GCPhysExplosion::SetRadius)
        .addProperty("TargetEntityName", &GCPhysExplosion::GetTargetEntityName, &GCPhysExplosion::SetTargetEntityName)
        .addProperty("InnerRadius", &GCPhysExplosion::GetInnerRadius, &GCPhysExplosion::SetInnerRadius)
        .addProperty("PushScale", &GCPhysExplosion::GetPushScale, &GCPhysExplosion::SetPushScale)
        .addProperty("ConvertToDebrisWhenPossible", &GCPhysExplosion::GetConvertToDebrisWhenPossible, &GCPhysExplosion::SetConvertToDebrisWhenPossible)
        .addProperty("OnPushedPlayer", &GCPhysExplosion::GetOnPushedPlayer, &GCPhysExplosion::SetOnPushedPlayer)
        .addProperty("Parent", &GCPhysExplosion::GetParent, &GCPhysExplosion::SetParent)
        .addFunction("ToPtr", &GCPhysExplosion::ToPtr)
        .addFunction("IsValid", &GCPhysExplosion::IsValid)
        .endClass();
}