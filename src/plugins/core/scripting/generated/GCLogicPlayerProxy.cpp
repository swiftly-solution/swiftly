#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicPlayerProxy::GCLogicPlayerProxy(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicPlayerProxy::GCLogicPlayerProxy(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCLogicPlayerProxy::GetPlayer() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CLogicPlayerProxy", "m_hPlayer"));
    return value;
}
void GCLogicPlayerProxy::SetPlayer(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Player' is not possible.\n");
}
GCEntityIOOutput GCLogicPlayerProxy::GetPlayerHasAmmo() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicPlayerProxy", "m_PlayerHasAmmo"));
    return value;
}
void GCLogicPlayerProxy::SetPlayerHasAmmo(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicPlayerProxy", "m_PlayerHasAmmo", false, value);
}
GCEntityIOOutput GCLogicPlayerProxy::GetPlayerHasNoAmmo() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicPlayerProxy", "m_PlayerHasNoAmmo"));
    return value;
}
void GCLogicPlayerProxy::SetPlayerHasNoAmmo(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicPlayerProxy", "m_PlayerHasNoAmmo", false, value);
}
GCEntityIOOutput GCLogicPlayerProxy::GetPlayerDied() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicPlayerProxy", "m_PlayerDied"));
    return value;
}
void GCLogicPlayerProxy::SetPlayerDied(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicPlayerProxy", "m_PlayerDied", false, value);
}
std::string GCLogicPlayerProxy::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicPlayerProxy::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicPlayerProxy::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicPlayerProxy::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicPlayerProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicPlayerProxy>("CLogicPlayerProxy")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Player", &GCLogicPlayerProxy::GetPlayer, &GCLogicPlayerProxy::SetPlayer)
        .addProperty("PlayerHasAmmo", &GCLogicPlayerProxy::GetPlayerHasAmmo, &GCLogicPlayerProxy::SetPlayerHasAmmo)
        .addProperty("PlayerHasNoAmmo", &GCLogicPlayerProxy::GetPlayerHasNoAmmo, &GCLogicPlayerProxy::SetPlayerHasNoAmmo)
        .addProperty("PlayerDied", &GCLogicPlayerProxy::GetPlayerDied, &GCLogicPlayerProxy::SetPlayerDied)
        .addProperty("Parent", &GCLogicPlayerProxy::GetParent, &GCLogicPlayerProxy::SetParent)
        .addFunction("ToPtr", &GCLogicPlayerProxy::ToPtr)
        .addFunction("IsValid", &GCLogicPlayerProxy::IsValid)
        .endClass();
}