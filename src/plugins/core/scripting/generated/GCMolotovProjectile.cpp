#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMolotovProjectile::GCMolotovProjectile(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMolotovProjectile::GCMolotovProjectile(void *ptr) {
    m_ptr = ptr;
}
bool GCMolotovProjectile::GetIsIncGrenade() const {
    return GetSchemaValue<bool>(m_ptr, "CMolotovProjectile", "m_bIsIncGrenade");
}
void GCMolotovProjectile::SetIsIncGrenade(bool value) {
    SetSchemaValue(m_ptr, "CMolotovProjectile", "m_bIsIncGrenade", false, value);
}
bool GCMolotovProjectile::GetDetonated() const {
    return GetSchemaValue<bool>(m_ptr, "CMolotovProjectile", "m_bDetonated");
}
void GCMolotovProjectile::SetDetonated(bool value) {
    SetSchemaValue(m_ptr, "CMolotovProjectile", "m_bDetonated", false, value);
}
GIntervalTimer GCMolotovProjectile::GetStillTimer() const {
    GIntervalTimer value(GetSchemaPtr(m_ptr, "CMolotovProjectile", "m_stillTimer"));
    return value;
}
void GCMolotovProjectile::SetStillTimer(GIntervalTimer value) {
    SetSchemaValue(m_ptr, "CMolotovProjectile", "m_stillTimer", false, value);
}
bool GCMolotovProjectile::GetHasBouncedOffPlayer() const {
    return GetSchemaValue<bool>(m_ptr, "CMolotovProjectile", "m_bHasBouncedOffPlayer");
}
void GCMolotovProjectile::SetHasBouncedOffPlayer(bool value) {
    SetSchemaValue(m_ptr, "CMolotovProjectile", "m_bHasBouncedOffPlayer", false, value);
}
std::string GCMolotovProjectile::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMolotovProjectile::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenadeProjectile GCMolotovProjectile::GetParent() const {
    GCBaseCSGrenadeProjectile value(m_ptr);
    return value;
}
void GCMolotovProjectile::SetParent(GCBaseCSGrenadeProjectile value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMolotovProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMolotovProjectile>("CMolotovProjectile")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IsIncGrenade", &GCMolotovProjectile::GetIsIncGrenade, &GCMolotovProjectile::SetIsIncGrenade)
        .addProperty("Detonated", &GCMolotovProjectile::GetDetonated, &GCMolotovProjectile::SetDetonated)
        .addProperty("StillTimer", &GCMolotovProjectile::GetStillTimer, &GCMolotovProjectile::SetStillTimer)
        .addProperty("HasBouncedOffPlayer", &GCMolotovProjectile::GetHasBouncedOffPlayer, &GCMolotovProjectile::SetHasBouncedOffPlayer)
        .addProperty("Parent", &GCMolotovProjectile::GetParent, &GCMolotovProjectile::SetParent)
        .addFunction("ToPtr", &GCMolotovProjectile::ToPtr)
        .addFunction("IsValid", &GCMolotovProjectile::IsValid)
        .endClass();
}