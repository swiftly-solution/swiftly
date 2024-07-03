#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponShield::GCWeaponShield(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponShield::GCWeaponShield(void *ptr) {
    m_ptr = ptr;
}
float GCWeaponShield::GetBulletDamageAbsorbed() const {
    return GetSchemaValue<float>(m_ptr, "CWeaponShield", "m_flBulletDamageAbsorbed");
}
void GCWeaponShield::SetBulletDamageAbsorbed(float value) {
    SetSchemaValue(m_ptr, "CWeaponShield", "m_flBulletDamageAbsorbed", false, value);
}
float GCWeaponShield::GetLastBulletHitSoundTime() const {
    return GetSchemaValue<float>(m_ptr, "CWeaponShield", "m_flLastBulletHitSoundTime");
}
void GCWeaponShield::SetLastBulletHitSoundTime(float value) {
    SetSchemaValue(m_ptr, "CWeaponShield", "m_flLastBulletHitSoundTime", false, value);
}
float GCWeaponShield::GetDisplayHealth() const {
    return GetSchemaValue<float>(m_ptr, "CWeaponShield", "m_flDisplayHealth");
}
void GCWeaponShield::SetDisplayHealth(float value) {
    SetSchemaValue(m_ptr, "CWeaponShield", "m_flDisplayHealth", false, value);
}
std::string GCWeaponShield::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponShield::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponShield::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponShield::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponShield(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponShield>("CWeaponShield")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BulletDamageAbsorbed", &GCWeaponShield::GetBulletDamageAbsorbed, &GCWeaponShield::SetBulletDamageAbsorbed)
        .addProperty("LastBulletHitSoundTime", &GCWeaponShield::GetLastBulletHitSoundTime, &GCWeaponShield::SetLastBulletHitSoundTime)
        .addProperty("DisplayHealth", &GCWeaponShield::GetDisplayHealth, &GCWeaponShield::SetDisplayHealth)
        .addProperty("Parent", &GCWeaponShield::GetParent, &GCWeaponShield::SetParent)
        .addFunction("ToPtr", &GCWeaponShield::ToPtr)
        .addFunction("IsValid", &GCWeaponShield::IsValid)
        .endClass();
}