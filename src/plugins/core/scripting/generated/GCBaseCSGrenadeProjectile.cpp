#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseCSGrenadeProjectile::GCBaseCSGrenadeProjectile(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseCSGrenadeProjectile::GCBaseCSGrenadeProjectile(void *ptr) {
    m_ptr = ptr;
}
Vector GCBaseCSGrenadeProjectile::GetInitialPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vInitialPosition");
}
void GCBaseCSGrenadeProjectile::SetInitialPosition(Vector value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vInitialPosition", false, value);
}
Vector GCBaseCSGrenadeProjectile::GetInitialVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vInitialVelocity");
}
void GCBaseCSGrenadeProjectile::SetInitialVelocity(Vector value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vInitialVelocity", false, value);
}
int32_t GCBaseCSGrenadeProjectile::GetBounces() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseCSGrenadeProjectile", "m_nBounces");
}
void GCBaseCSGrenadeProjectile::SetBounces(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_nBounces", false, value);
}
int32_t GCBaseCSGrenadeProjectile::GetExplodeEffectTickBegin() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseCSGrenadeProjectile", "m_nExplodeEffectTickBegin");
}
void GCBaseCSGrenadeProjectile::SetExplodeEffectTickBegin(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_nExplodeEffectTickBegin", false, value);
}
Vector GCBaseCSGrenadeProjectile::GetExplodeEffectOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vecExplodeEffectOrigin");
}
void GCBaseCSGrenadeProjectile::SetExplodeEffectOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vecExplodeEffectOrigin", false, value);
}
float GCBaseCSGrenadeProjectile::GetSpawnTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseCSGrenadeProjectile", "m_flSpawnTime");
}
void GCBaseCSGrenadeProjectile::SetSpawnTime(float value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_flSpawnTime", false, value);
}
uint8_t GCBaseCSGrenadeProjectile::GetOGSExtraFlags() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CBaseCSGrenadeProjectile", "m_unOGSExtraFlags");
}
void GCBaseCSGrenadeProjectile::SetOGSExtraFlags(uint8_t value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_unOGSExtraFlags", false, value);
}
bool GCBaseCSGrenadeProjectile::GetDetonationRecorded() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenadeProjectile", "m_bDetonationRecorded");
}
void GCBaseCSGrenadeProjectile::SetDetonationRecorded(bool value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_bDetonationRecorded", false, value);
}
uint16_t GCBaseCSGrenadeProjectile::GetItemIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CBaseCSGrenadeProjectile", "m_nItemIndex");
}
void GCBaseCSGrenadeProjectile::SetItemIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_nItemIndex", false, value);
}
Vector GCBaseCSGrenadeProjectile::GetOriginalSpawnLocation() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vecOriginalSpawnLocation");
}
void GCBaseCSGrenadeProjectile::SetOriginalSpawnLocation(Vector value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vecOriginalSpawnLocation", false, value);
}
float GCBaseCSGrenadeProjectile::GetLastBounceSoundTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseCSGrenadeProjectile", "m_flLastBounceSoundTime");
}
void GCBaseCSGrenadeProjectile::SetLastBounceSoundTime(float value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_flLastBounceSoundTime", false, value);
}
Vector GCBaseCSGrenadeProjectile::GetGrenadeSpin() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vecGrenadeSpin");
}
void GCBaseCSGrenadeProjectile::SetGrenadeSpin(Vector value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vecGrenadeSpin", false, value);
}
Vector GCBaseCSGrenadeProjectile::GetLastHitSurfaceNormal() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vecLastHitSurfaceNormal");
}
void GCBaseCSGrenadeProjectile::SetLastHitSurfaceNormal(Vector value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vecLastHitSurfaceNormal", false, value);
}
int32_t GCBaseCSGrenadeProjectile::GetTicksAtZeroVelocity() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseCSGrenadeProjectile", "m_nTicksAtZeroVelocity");
}
void GCBaseCSGrenadeProjectile::SetTicksAtZeroVelocity(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_nTicksAtZeroVelocity", false, value);
}
bool GCBaseCSGrenadeProjectile::GetHasEverHitPlayer() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenadeProjectile", "m_bHasEverHitPlayer");
}
void GCBaseCSGrenadeProjectile::SetHasEverHitPlayer(bool value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_bHasEverHitPlayer", false, value);
}
bool GCBaseCSGrenadeProjectile::GetClearFromPlayers() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenadeProjectile", "m_bClearFromPlayers");
}
void GCBaseCSGrenadeProjectile::SetClearFromPlayers(bool value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_bClearFromPlayers", false, value);
}
std::string GCBaseCSGrenadeProjectile::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseCSGrenadeProjectile::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseGrenade GCBaseCSGrenadeProjectile::GetParent() const {
    GCBaseGrenade value(m_ptr);
    return value;
}
void GCBaseCSGrenadeProjectile::SetParent(GCBaseGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseCSGrenadeProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseCSGrenadeProjectile>("CBaseCSGrenadeProjectile")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InitialPosition", &GCBaseCSGrenadeProjectile::GetInitialPosition, &GCBaseCSGrenadeProjectile::SetInitialPosition)
        .addProperty("InitialVelocity", &GCBaseCSGrenadeProjectile::GetInitialVelocity, &GCBaseCSGrenadeProjectile::SetInitialVelocity)
        .addProperty("Bounces", &GCBaseCSGrenadeProjectile::GetBounces, &GCBaseCSGrenadeProjectile::SetBounces)
        .addProperty("ExplodeEffectTickBegin", &GCBaseCSGrenadeProjectile::GetExplodeEffectTickBegin, &GCBaseCSGrenadeProjectile::SetExplodeEffectTickBegin)
        .addProperty("ExplodeEffectOrigin", &GCBaseCSGrenadeProjectile::GetExplodeEffectOrigin, &GCBaseCSGrenadeProjectile::SetExplodeEffectOrigin)
        .addProperty("SpawnTime", &GCBaseCSGrenadeProjectile::GetSpawnTime, &GCBaseCSGrenadeProjectile::SetSpawnTime)
        .addProperty("OGSExtraFlags", &GCBaseCSGrenadeProjectile::GetOGSExtraFlags, &GCBaseCSGrenadeProjectile::SetOGSExtraFlags)
        .addProperty("DetonationRecorded", &GCBaseCSGrenadeProjectile::GetDetonationRecorded, &GCBaseCSGrenadeProjectile::SetDetonationRecorded)
        .addProperty("ItemIndex", &GCBaseCSGrenadeProjectile::GetItemIndex, &GCBaseCSGrenadeProjectile::SetItemIndex)
        .addProperty("OriginalSpawnLocation", &GCBaseCSGrenadeProjectile::GetOriginalSpawnLocation, &GCBaseCSGrenadeProjectile::SetOriginalSpawnLocation)
        .addProperty("LastBounceSoundTime", &GCBaseCSGrenadeProjectile::GetLastBounceSoundTime, &GCBaseCSGrenadeProjectile::SetLastBounceSoundTime)
        .addProperty("GrenadeSpin", &GCBaseCSGrenadeProjectile::GetGrenadeSpin, &GCBaseCSGrenadeProjectile::SetGrenadeSpin)
        .addProperty("LastHitSurfaceNormal", &GCBaseCSGrenadeProjectile::GetLastHitSurfaceNormal, &GCBaseCSGrenadeProjectile::SetLastHitSurfaceNormal)
        .addProperty("TicksAtZeroVelocity", &GCBaseCSGrenadeProjectile::GetTicksAtZeroVelocity, &GCBaseCSGrenadeProjectile::SetTicksAtZeroVelocity)
        .addProperty("HasEverHitPlayer", &GCBaseCSGrenadeProjectile::GetHasEverHitPlayer, &GCBaseCSGrenadeProjectile::SetHasEverHitPlayer)
        .addProperty("ClearFromPlayers", &GCBaseCSGrenadeProjectile::GetClearFromPlayers, &GCBaseCSGrenadeProjectile::SetClearFromPlayers)
        .addProperty("Parent", &GCBaseCSGrenadeProjectile::GetParent, &GCBaseCSGrenadeProjectile::SetParent)
        .addFunction("ToPtr", &GCBaseCSGrenadeProjectile::ToPtr)
        .addFunction("IsValid", &GCBaseCSGrenadeProjectile::IsValid)
        .endClass();
}