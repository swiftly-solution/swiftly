#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCItem::GCItem(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCItem::GCItem(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCItem::GetOnPlayerTouch() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CItem", "m_OnPlayerTouch"));
    return value;
}
void GCItem::SetOnPlayerTouch(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CItem", "m_OnPlayerTouch", false, value);
}
GCEntityIOOutput GCItem::GetOnPlayerPickup() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CItem", "m_OnPlayerPickup"));
    return value;
}
void GCItem::SetOnPlayerPickup(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CItem", "m_OnPlayerPickup", false, value);
}
bool GCItem::GetActivateWhenAtRest() const {
    return GetSchemaValue<bool>(m_ptr, "CItem", "m_bActivateWhenAtRest");
}
void GCItem::SetActivateWhenAtRest(bool value) {
    SetSchemaValue(m_ptr, "CItem", "m_bActivateWhenAtRest", false, value);
}
GCEntityIOOutput GCItem::GetOnCacheInteraction() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CItem", "m_OnCacheInteraction"));
    return value;
}
void GCItem::SetOnCacheInteraction(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CItem", "m_OnCacheInteraction", false, value);
}
GCEntityIOOutput GCItem::GetOnGlovePulled() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CItem", "m_OnGlovePulled"));
    return value;
}
void GCItem::SetOnGlovePulled(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CItem", "m_OnGlovePulled", false, value);
}
Vector GCItem::GetOriginalSpawnOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CItem", "m_vOriginalSpawnOrigin");
}
void GCItem::SetOriginalSpawnOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CItem", "m_vOriginalSpawnOrigin", false, value);
}
QAngle GCItem::GetOriginalSpawnAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CItem", "m_vOriginalSpawnAngles");
}
void GCItem::SetOriginalSpawnAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CItem", "m_vOriginalSpawnAngles", false, value);
}
bool GCItem::GetPhysStartAsleep() const {
    return GetSchemaValue<bool>(m_ptr, "CItem", "m_bPhysStartAsleep");
}
void GCItem::SetPhysStartAsleep(bool value) {
    SetSchemaValue(m_ptr, "CItem", "m_bPhysStartAsleep", false, value);
}
std::string GCItem::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCItem::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCItem::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCItem::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCItem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItem>("CItem")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnPlayerTouch", &GCItem::GetOnPlayerTouch, &GCItem::SetOnPlayerTouch)
        .addProperty("OnPlayerPickup", &GCItem::GetOnPlayerPickup, &GCItem::SetOnPlayerPickup)
        .addProperty("ActivateWhenAtRest", &GCItem::GetActivateWhenAtRest, &GCItem::SetActivateWhenAtRest)
        .addProperty("OnCacheInteraction", &GCItem::GetOnCacheInteraction, &GCItem::SetOnCacheInteraction)
        .addProperty("OnGlovePulled", &GCItem::GetOnGlovePulled, &GCItem::SetOnGlovePulled)
        .addProperty("OriginalSpawnOrigin", &GCItem::GetOriginalSpawnOrigin, &GCItem::SetOriginalSpawnOrigin)
        .addProperty("OriginalSpawnAngles", &GCItem::GetOriginalSpawnAngles, &GCItem::SetOriginalSpawnAngles)
        .addProperty("PhysStartAsleep", &GCItem::GetPhysStartAsleep, &GCItem::SetPhysStartAsleep)
        .addProperty("Parent", &GCItem::GetParent, &GCItem::SetParent)
        .addFunction("ToPtr", &GCItem::ToPtr)
        .addFunction("IsValid", &GCItem::IsValid)
        .endClass();
}