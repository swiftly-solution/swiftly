#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSensorGrenadeProjectile::GCSensorGrenadeProjectile(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSensorGrenadeProjectile::GCSensorGrenadeProjectile(void *ptr) {
    m_ptr = ptr;
}
float GCSensorGrenadeProjectile::GetExpireTime() const {
    return GetSchemaValue<float>(m_ptr, "CSensorGrenadeProjectile", "m_fExpireTime");
}
void GCSensorGrenadeProjectile::SetExpireTime(float value) {
    SetSchemaValue(m_ptr, "CSensorGrenadeProjectile", "m_fExpireTime", false, value);
}
float GCSensorGrenadeProjectile::GetNextDetectPlayerSound() const {
    return GetSchemaValue<float>(m_ptr, "CSensorGrenadeProjectile", "m_fNextDetectPlayerSound");
}
void GCSensorGrenadeProjectile::SetNextDetectPlayerSound(float value) {
    SetSchemaValue(m_ptr, "CSensorGrenadeProjectile", "m_fNextDetectPlayerSound", false, value);
}
GCBaseEntity GCSensorGrenadeProjectile::GetDisplayGrenade() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSensorGrenadeProjectile", "m_hDisplayGrenade"));
    return value;
}
void GCSensorGrenadeProjectile::SetDisplayGrenade(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'DisplayGrenade' is not possible.\n");
}
std::string GCSensorGrenadeProjectile::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSensorGrenadeProjectile::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenadeProjectile GCSensorGrenadeProjectile::GetParent() const {
    GCBaseCSGrenadeProjectile value(m_ptr);
    return value;
}
void GCSensorGrenadeProjectile::SetParent(GCBaseCSGrenadeProjectile value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSensorGrenadeProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSensorGrenadeProjectile>("CSensorGrenadeProjectile")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ExpireTime", &GCSensorGrenadeProjectile::GetExpireTime, &GCSensorGrenadeProjectile::SetExpireTime)
        .addProperty("NextDetectPlayerSound", &GCSensorGrenadeProjectile::GetNextDetectPlayerSound, &GCSensorGrenadeProjectile::SetNextDetectPlayerSound)
        .addProperty("DisplayGrenade", &GCSensorGrenadeProjectile::GetDisplayGrenade, &GCSensorGrenadeProjectile::SetDisplayGrenade)
        .addProperty("Parent", &GCSensorGrenadeProjectile::GetParent, &GCSensorGrenadeProjectile::SetParent)
        .addFunction("ToPtr", &GCSensorGrenadeProjectile::ToPtr)
        .addFunction("IsValid", &GCSensorGrenadeProjectile::IsValid)
        .endClass();
}