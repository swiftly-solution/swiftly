#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEntityFlame::GCEntityFlame(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEntityFlame::GCEntityFlame(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCEntityFlame::GetEntAttached() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CEntityFlame", "m_hEntAttached"));
    return value;
}
void GCEntityFlame::SetEntAttached(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'EntAttached' is not possible.\n");
}
bool GCEntityFlame::GetCheapEffect() const {
    return GetSchemaValue<bool>(m_ptr, "CEntityFlame", "m_bCheapEffect");
}
void GCEntityFlame::SetCheapEffect(bool value) {
    SetSchemaValue(m_ptr, "CEntityFlame", "m_bCheapEffect", false, value);
}
float GCEntityFlame::GetSize() const {
    return GetSchemaValue<float>(m_ptr, "CEntityFlame", "m_flSize");
}
void GCEntityFlame::SetSize(float value) {
    SetSchemaValue(m_ptr, "CEntityFlame", "m_flSize", false, value);
}
bool GCEntityFlame::GetUseHitboxes() const {
    return GetSchemaValue<bool>(m_ptr, "CEntityFlame", "m_bUseHitboxes");
}
void GCEntityFlame::SetUseHitboxes(bool value) {
    SetSchemaValue(m_ptr, "CEntityFlame", "m_bUseHitboxes", false, value);
}
int32_t GCEntityFlame::GetNumHitboxFires() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEntityFlame", "m_iNumHitboxFires");
}
void GCEntityFlame::SetNumHitboxFires(int32_t value) {
    SetSchemaValue(m_ptr, "CEntityFlame", "m_iNumHitboxFires", false, value);
}
float GCEntityFlame::GetHitboxFireScale() const {
    return GetSchemaValue<float>(m_ptr, "CEntityFlame", "m_flHitboxFireScale");
}
void GCEntityFlame::SetHitboxFireScale(float value) {
    SetSchemaValue(m_ptr, "CEntityFlame", "m_flHitboxFireScale", false, value);
}
float GCEntityFlame::GetLifetime() const {
    return GetSchemaValue<float>(m_ptr, "CEntityFlame", "m_flLifetime");
}
void GCEntityFlame::SetLifetime(float value) {
    SetSchemaValue(m_ptr, "CEntityFlame", "m_flLifetime", false, value);
}
GCBaseEntity GCEntityFlame::GetAttacker() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CEntityFlame", "m_hAttacker"));
    return value;
}
void GCEntityFlame::SetAttacker(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Attacker' is not possible.\n");
}
int32_t GCEntityFlame::GetDangerSound() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEntityFlame", "m_iDangerSound");
}
void GCEntityFlame::SetDangerSound(int32_t value) {
    SetSchemaValue(m_ptr, "CEntityFlame", "m_iDangerSound", false, value);
}
float GCEntityFlame::GetDirectDamagePerSecond() const {
    return GetSchemaValue<float>(m_ptr, "CEntityFlame", "m_flDirectDamagePerSecond");
}
void GCEntityFlame::SetDirectDamagePerSecond(float value) {
    SetSchemaValue(m_ptr, "CEntityFlame", "m_flDirectDamagePerSecond", false, value);
}
int32_t GCEntityFlame::GetCustomDamageType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEntityFlame", "m_iCustomDamageType");
}
void GCEntityFlame::SetCustomDamageType(int32_t value) {
    SetSchemaValue(m_ptr, "CEntityFlame", "m_iCustomDamageType", false, value);
}
std::string GCEntityFlame::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEntityFlame::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEntityFlame::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEntityFlame::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEntityFlame(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityFlame>("CEntityFlame")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EntAttached", &GCEntityFlame::GetEntAttached, &GCEntityFlame::SetEntAttached)
        .addProperty("CheapEffect", &GCEntityFlame::GetCheapEffect, &GCEntityFlame::SetCheapEffect)
        .addProperty("Size", &GCEntityFlame::GetSize, &GCEntityFlame::SetSize)
        .addProperty("UseHitboxes", &GCEntityFlame::GetUseHitboxes, &GCEntityFlame::SetUseHitboxes)
        .addProperty("NumHitboxFires", &GCEntityFlame::GetNumHitboxFires, &GCEntityFlame::SetNumHitboxFires)
        .addProperty("HitboxFireScale", &GCEntityFlame::GetHitboxFireScale, &GCEntityFlame::SetHitboxFireScale)
        .addProperty("Lifetime", &GCEntityFlame::GetLifetime, &GCEntityFlame::SetLifetime)
        .addProperty("Attacker", &GCEntityFlame::GetAttacker, &GCEntityFlame::SetAttacker)
        .addProperty("DangerSound", &GCEntityFlame::GetDangerSound, &GCEntityFlame::SetDangerSound)
        .addProperty("DirectDamagePerSecond", &GCEntityFlame::GetDirectDamagePerSecond, &GCEntityFlame::SetDirectDamagePerSecond)
        .addProperty("CustomDamageType", &GCEntityFlame::GetCustomDamageType, &GCEntityFlame::SetCustomDamageType)
        .addProperty("Parent", &GCEntityFlame::GetParent, &GCEntityFlame::SetParent)
        .addFunction("ToPtr", &GCEntityFlame::ToPtr)
        .addFunction("IsValid", &GCEntityFlame::IsValid)
        .endClass();
}