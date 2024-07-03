#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponTaser::GCWeaponTaser(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponTaser::GCWeaponTaser(void *ptr) {
    m_ptr = ptr;
}
float GCWeaponTaser::GetFireTime() const {
    return GetSchemaValue<float>(m_ptr, "CWeaponTaser", "m_fFireTime");
}
void GCWeaponTaser::SetFireTime(float value) {
    SetSchemaValue(m_ptr, "CWeaponTaser", "m_fFireTime", false, value);
}
int32_t GCWeaponTaser::GetLastAttackTick() const {
    return GetSchemaValue<int32_t>(m_ptr, "CWeaponTaser", "m_nLastAttackTick");
}
void GCWeaponTaser::SetLastAttackTick(int32_t value) {
    SetSchemaValue(m_ptr, "CWeaponTaser", "m_nLastAttackTick", false, value);
}
std::string GCWeaponTaser::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponTaser::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponTaser::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponTaser::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponTaser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponTaser>("CWeaponTaser")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FireTime", &GCWeaponTaser::GetFireTime, &GCWeaponTaser::SetFireTime)
        .addProperty("LastAttackTick", &GCWeaponTaser::GetLastAttackTick, &GCWeaponTaser::SetLastAttackTick)
        .addProperty("Parent", &GCWeaponTaser::GetParent, &GCWeaponTaser::SetParent)
        .addFunction("ToPtr", &GCWeaponTaser::ToPtr)
        .addFunction("IsValid", &GCWeaponTaser::IsValid)
        .endClass();
}