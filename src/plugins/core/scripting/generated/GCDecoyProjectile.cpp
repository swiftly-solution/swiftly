#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDecoyProjectile::GCDecoyProjectile(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDecoyProjectile::GCDecoyProjectile(void *ptr) {
    m_ptr = ptr;
}
int32_t GCDecoyProjectile::GetDecoyShotTick() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDecoyProjectile", "m_nDecoyShotTick");
}
void GCDecoyProjectile::SetDecoyShotTick(int32_t value) {
    SetSchemaValue(m_ptr, "CDecoyProjectile", "m_nDecoyShotTick", false, value);
}
int32_t GCDecoyProjectile::GetShotsRemaining() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDecoyProjectile", "m_shotsRemaining");
}
void GCDecoyProjectile::SetShotsRemaining(int32_t value) {
    SetSchemaValue(m_ptr, "CDecoyProjectile", "m_shotsRemaining", false, value);
}
float GCDecoyProjectile::GetExpireTime() const {
    return GetSchemaValue<float>(m_ptr, "CDecoyProjectile", "m_fExpireTime");
}
void GCDecoyProjectile::SetExpireTime(float value) {
    SetSchemaValue(m_ptr, "CDecoyProjectile", "m_fExpireTime", false, value);
}
uint16_t GCDecoyProjectile::GetDecoyWeaponDefIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CDecoyProjectile", "m_decoyWeaponDefIndex");
}
void GCDecoyProjectile::SetDecoyWeaponDefIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "CDecoyProjectile", "m_decoyWeaponDefIndex", false, value);
}
std::string GCDecoyProjectile::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDecoyProjectile::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenadeProjectile GCDecoyProjectile::GetParent() const {
    GCBaseCSGrenadeProjectile value(m_ptr);
    return value;
}
void GCDecoyProjectile::SetParent(GCBaseCSGrenadeProjectile value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDecoyProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDecoyProjectile>("CDecoyProjectile")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DecoyShotTick", &GCDecoyProjectile::GetDecoyShotTick, &GCDecoyProjectile::SetDecoyShotTick)
        .addProperty("ShotsRemaining", &GCDecoyProjectile::GetShotsRemaining, &GCDecoyProjectile::SetShotsRemaining)
        .addProperty("ExpireTime", &GCDecoyProjectile::GetExpireTime, &GCDecoyProjectile::SetExpireTime)
        .addProperty("DecoyWeaponDefIndex", &GCDecoyProjectile::GetDecoyWeaponDefIndex, &GCDecoyProjectile::SetDecoyWeaponDefIndex)
        .addProperty("Parent", &GCDecoyProjectile::GetParent, &GCDecoyProjectile::SetParent)
        .addFunction("ToPtr", &GCDecoyProjectile::ToPtr)
        .addFunction("IsValid", &GCDecoyProjectile::IsValid)
        .endClass();
}