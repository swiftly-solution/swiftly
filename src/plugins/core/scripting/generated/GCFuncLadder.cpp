#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncLadder::GCFuncLadder(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncLadder::GCFuncLadder(void *ptr) {
    m_ptr = ptr;
}
Vector GCFuncLadder::GetLadderDir() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncLadder", "m_vecLadderDir");
}
void GCFuncLadder::SetLadderDir(Vector value) {
    SetSchemaValue(m_ptr, "CFuncLadder", "m_vecLadderDir", false, value);
}
Vector GCFuncLadder::GetLocalTop() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncLadder", "m_vecLocalTop");
}
void GCFuncLadder::SetLocalTop(Vector value) {
    SetSchemaValue(m_ptr, "CFuncLadder", "m_vecLocalTop", false, value);
}
Vector GCFuncLadder::GetPlayerMountPositionTop() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncLadder", "m_vecPlayerMountPositionTop");
}
void GCFuncLadder::SetPlayerMountPositionTop(Vector value) {
    SetSchemaValue(m_ptr, "CFuncLadder", "m_vecPlayerMountPositionTop", false, value);
}
Vector GCFuncLadder::GetPlayerMountPositionBottom() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncLadder", "m_vecPlayerMountPositionBottom");
}
void GCFuncLadder::SetPlayerMountPositionBottom(Vector value) {
    SetSchemaValue(m_ptr, "CFuncLadder", "m_vecPlayerMountPositionBottom", false, value);
}
float GCFuncLadder::GetAutoRideSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncLadder", "m_flAutoRideSpeed");
}
void GCFuncLadder::SetAutoRideSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncLadder", "m_flAutoRideSpeed", false, value);
}
bool GCFuncLadder::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncLadder", "m_bDisabled");
}
void GCFuncLadder::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CFuncLadder", "m_bDisabled", false, value);
}
bool GCFuncLadder::GetFakeLadder() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncLadder", "m_bFakeLadder");
}
void GCFuncLadder::SetFakeLadder(bool value) {
    SetSchemaValue(m_ptr, "CFuncLadder", "m_bFakeLadder", false, value);
}
bool GCFuncLadder::GetHasSlack() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncLadder", "m_bHasSlack");
}
void GCFuncLadder::SetHasSlack(bool value) {
    SetSchemaValue(m_ptr, "CFuncLadder", "m_bHasSlack", false, value);
}
std::string GCFuncLadder::GetSurfacePropName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncLadder", "m_surfacePropName").String();
}
void GCFuncLadder::SetSurfacePropName(std::string value) {
    SetSchemaValue(m_ptr, "CFuncLadder", "m_surfacePropName", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityIOOutput GCFuncLadder::GetOnPlayerGotOnLadder() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncLadder", "m_OnPlayerGotOnLadder"));
    return value;
}
void GCFuncLadder::SetOnPlayerGotOnLadder(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncLadder", "m_OnPlayerGotOnLadder", false, value);
}
GCEntityIOOutput GCFuncLadder::GetOnPlayerGotOffLadder() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncLadder", "m_OnPlayerGotOffLadder"));
    return value;
}
void GCFuncLadder::SetOnPlayerGotOffLadder(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncLadder", "m_OnPlayerGotOffLadder", false, value);
}
std::string GCFuncLadder::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncLadder::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncLadder::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncLadder::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncLadder(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncLadder>("CFuncLadder")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LadderDir", &GCFuncLadder::GetLadderDir, &GCFuncLadder::SetLadderDir)
        .addProperty("LocalTop", &GCFuncLadder::GetLocalTop, &GCFuncLadder::SetLocalTop)
        .addProperty("PlayerMountPositionTop", &GCFuncLadder::GetPlayerMountPositionTop, &GCFuncLadder::SetPlayerMountPositionTop)
        .addProperty("PlayerMountPositionBottom", &GCFuncLadder::GetPlayerMountPositionBottom, &GCFuncLadder::SetPlayerMountPositionBottom)
        .addProperty("AutoRideSpeed", &GCFuncLadder::GetAutoRideSpeed, &GCFuncLadder::SetAutoRideSpeed)
        .addProperty("Disabled", &GCFuncLadder::GetDisabled, &GCFuncLadder::SetDisabled)
        .addProperty("FakeLadder", &GCFuncLadder::GetFakeLadder, &GCFuncLadder::SetFakeLadder)
        .addProperty("HasSlack", &GCFuncLadder::GetHasSlack, &GCFuncLadder::SetHasSlack)
        .addProperty("SurfacePropName", &GCFuncLadder::GetSurfacePropName, &GCFuncLadder::SetSurfacePropName)
        .addProperty("OnPlayerGotOnLadder", &GCFuncLadder::GetOnPlayerGotOnLadder, &GCFuncLadder::SetOnPlayerGotOnLadder)
        .addProperty("OnPlayerGotOffLadder", &GCFuncLadder::GetOnPlayerGotOffLadder, &GCFuncLadder::SetOnPlayerGotOffLadder)
        .addProperty("Parent", &GCFuncLadder::GetParent, &GCFuncLadder::SetParent)
        .addFunction("ToPtr", &GCFuncLadder::ToPtr)
        .addFunction("IsValid", &GCFuncLadder::IsValid)
        .endClass();
}