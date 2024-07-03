#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseDoor::GCBaseDoor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseDoor::GCBaseDoor(void *ptr) {
    m_ptr = ptr;
}
QAngle GCBaseDoor::GetMoveEntitySpace() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBaseDoor", "m_angMoveEntitySpace");
}
void GCBaseDoor::SetMoveEntitySpace(QAngle value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_angMoveEntitySpace", false, value);
}
Vector GCBaseDoor::GetMoveDirParentSpace() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseDoor", "m_vecMoveDirParentSpace");
}
void GCBaseDoor::SetMoveDirParentSpace(Vector value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_vecMoveDirParentSpace", false, value);
}
Glocksound_t GCBaseDoor::GetLs() const {
    Glocksound_t value(GetSchemaPtr(m_ptr, "CBaseDoor", "m_ls"));
    return value;
}
void GCBaseDoor::SetLs(Glocksound_t value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_ls", false, value);
}
bool GCBaseDoor::GetForceClosed() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bForceClosed");
}
void GCBaseDoor::SetForceClosed(bool value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_bForceClosed", false, value);
}
bool GCBaseDoor::GetDoorGroup() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bDoorGroup");
}
void GCBaseDoor::SetDoorGroup(bool value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_bDoorGroup", false, value);
}
bool GCBaseDoor::GetLocked() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bLocked");
}
void GCBaseDoor::SetLocked(bool value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_bLocked", false, value);
}
bool GCBaseDoor::GetIgnoreDebris() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bIgnoreDebris");
}
void GCBaseDoor::SetIgnoreDebris(bool value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_bIgnoreDebris", false, value);
}
uint64_t GCBaseDoor::GetSpawnPosition() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseDoor", "m_eSpawnPosition");
}
void GCBaseDoor::SetSpawnPosition(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_eSpawnPosition", false, value);
}
float GCBaseDoor::GetBlockDamage() const {
    return GetSchemaValue<float>(m_ptr, "CBaseDoor", "m_flBlockDamage");
}
void GCBaseDoor::SetBlockDamage(float value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_flBlockDamage", false, value);
}
std::string GCBaseDoor::GetNoiseMoving() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDoor", "m_NoiseMoving").String();
}
void GCBaseDoor::SetNoiseMoving(std::string value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_NoiseMoving", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseDoor::GetNoiseArrived() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDoor", "m_NoiseArrived").String();
}
void GCBaseDoor::SetNoiseArrived(std::string value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_NoiseArrived", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseDoor::GetNoiseMovingClosed() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDoor", "m_NoiseMovingClosed").String();
}
void GCBaseDoor::SetNoiseMovingClosed(std::string value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_NoiseMovingClosed", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseDoor::GetNoiseArrivedClosed() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDoor", "m_NoiseArrivedClosed").String();
}
void GCBaseDoor::SetNoiseArrivedClosed(std::string value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_NoiseArrivedClosed", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseDoor::GetChainTarget() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDoor", "m_ChainTarget").String();
}
void GCBaseDoor::SetChainTarget(std::string value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_ChainTarget", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityIOOutput GCBaseDoor::GetOnBlockedClosing() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseDoor", "m_OnBlockedClosing"));
    return value;
}
void GCBaseDoor::SetOnBlockedClosing(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_OnBlockedClosing", false, value);
}
GCEntityIOOutput GCBaseDoor::GetOnBlockedOpening() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseDoor", "m_OnBlockedOpening"));
    return value;
}
void GCBaseDoor::SetOnBlockedOpening(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_OnBlockedOpening", false, value);
}
GCEntityIOOutput GCBaseDoor::GetOnUnblockedClosing() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseDoor", "m_OnUnblockedClosing"));
    return value;
}
void GCBaseDoor::SetOnUnblockedClosing(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_OnUnblockedClosing", false, value);
}
GCEntityIOOutput GCBaseDoor::GetOnUnblockedOpening() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseDoor", "m_OnUnblockedOpening"));
    return value;
}
void GCBaseDoor::SetOnUnblockedOpening(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_OnUnblockedOpening", false, value);
}
GCEntityIOOutput GCBaseDoor::GetOnFullyClosed() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseDoor", "m_OnFullyClosed"));
    return value;
}
void GCBaseDoor::SetOnFullyClosed(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_OnFullyClosed", false, value);
}
GCEntityIOOutput GCBaseDoor::GetOnFullyOpen() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseDoor", "m_OnFullyOpen"));
    return value;
}
void GCBaseDoor::SetOnFullyOpen(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_OnFullyOpen", false, value);
}
GCEntityIOOutput GCBaseDoor::GetOnClose() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseDoor", "m_OnClose"));
    return value;
}
void GCBaseDoor::SetOnClose(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_OnClose", false, value);
}
GCEntityIOOutput GCBaseDoor::GetOnOpen() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseDoor", "m_OnOpen"));
    return value;
}
void GCBaseDoor::SetOnOpen(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_OnOpen", false, value);
}
GCEntityIOOutput GCBaseDoor::GetOnLockedUse() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseDoor", "m_OnLockedUse"));
    return value;
}
void GCBaseDoor::SetOnLockedUse(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_OnLockedUse", false, value);
}
bool GCBaseDoor::GetLoopMoveSound() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bLoopMoveSound");
}
void GCBaseDoor::SetLoopMoveSound(bool value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_bLoopMoveSound", false, value);
}
bool GCBaseDoor::GetCreateNavObstacle() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bCreateNavObstacle");
}
void GCBaseDoor::SetCreateNavObstacle(bool value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_bCreateNavObstacle", false, value);
}
bool GCBaseDoor::GetIsChaining() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_isChaining");
}
void GCBaseDoor::SetIsChaining(bool value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_isChaining", false, value);
}
bool GCBaseDoor::GetIsUsable() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bIsUsable");
}
void GCBaseDoor::SetIsUsable(bool value) {
    SetSchemaValue(m_ptr, "CBaseDoor", "m_bIsUsable", false, value);
}
std::string GCBaseDoor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseDoor::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseToggle GCBaseDoor::GetParent() const {
    GCBaseToggle value(m_ptr);
    return value;
}
void GCBaseDoor::SetParent(GCBaseToggle value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseDoor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseDoor>("CBaseDoor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MoveEntitySpace", &GCBaseDoor::GetMoveEntitySpace, &GCBaseDoor::SetMoveEntitySpace)
        .addProperty("MoveDirParentSpace", &GCBaseDoor::GetMoveDirParentSpace, &GCBaseDoor::SetMoveDirParentSpace)
        .addProperty("Ls", &GCBaseDoor::GetLs, &GCBaseDoor::SetLs)
        .addProperty("ForceClosed", &GCBaseDoor::GetForceClosed, &GCBaseDoor::SetForceClosed)
        .addProperty("DoorGroup", &GCBaseDoor::GetDoorGroup, &GCBaseDoor::SetDoorGroup)
        .addProperty("Locked", &GCBaseDoor::GetLocked, &GCBaseDoor::SetLocked)
        .addProperty("IgnoreDebris", &GCBaseDoor::GetIgnoreDebris, &GCBaseDoor::SetIgnoreDebris)
        .addProperty("SpawnPosition", &GCBaseDoor::GetSpawnPosition, &GCBaseDoor::SetSpawnPosition)
        .addProperty("BlockDamage", &GCBaseDoor::GetBlockDamage, &GCBaseDoor::SetBlockDamage)
        .addProperty("NoiseMoving", &GCBaseDoor::GetNoiseMoving, &GCBaseDoor::SetNoiseMoving)
        .addProperty("NoiseArrived", &GCBaseDoor::GetNoiseArrived, &GCBaseDoor::SetNoiseArrived)
        .addProperty("NoiseMovingClosed", &GCBaseDoor::GetNoiseMovingClosed, &GCBaseDoor::SetNoiseMovingClosed)
        .addProperty("NoiseArrivedClosed", &GCBaseDoor::GetNoiseArrivedClosed, &GCBaseDoor::SetNoiseArrivedClosed)
        .addProperty("ChainTarget", &GCBaseDoor::GetChainTarget, &GCBaseDoor::SetChainTarget)
        .addProperty("OnBlockedClosing", &GCBaseDoor::GetOnBlockedClosing, &GCBaseDoor::SetOnBlockedClosing)
        .addProperty("OnBlockedOpening", &GCBaseDoor::GetOnBlockedOpening, &GCBaseDoor::SetOnBlockedOpening)
        .addProperty("OnUnblockedClosing", &GCBaseDoor::GetOnUnblockedClosing, &GCBaseDoor::SetOnUnblockedClosing)
        .addProperty("OnUnblockedOpening", &GCBaseDoor::GetOnUnblockedOpening, &GCBaseDoor::SetOnUnblockedOpening)
        .addProperty("OnFullyClosed", &GCBaseDoor::GetOnFullyClosed, &GCBaseDoor::SetOnFullyClosed)
        .addProperty("OnFullyOpen", &GCBaseDoor::GetOnFullyOpen, &GCBaseDoor::SetOnFullyOpen)
        .addProperty("OnClose", &GCBaseDoor::GetOnClose, &GCBaseDoor::SetOnClose)
        .addProperty("OnOpen", &GCBaseDoor::GetOnOpen, &GCBaseDoor::SetOnOpen)
        .addProperty("OnLockedUse", &GCBaseDoor::GetOnLockedUse, &GCBaseDoor::SetOnLockedUse)
        .addProperty("LoopMoveSound", &GCBaseDoor::GetLoopMoveSound, &GCBaseDoor::SetLoopMoveSound)
        .addProperty("CreateNavObstacle", &GCBaseDoor::GetCreateNavObstacle, &GCBaseDoor::SetCreateNavObstacle)
        .addProperty("IsChaining", &GCBaseDoor::GetIsChaining, &GCBaseDoor::SetIsChaining)
        .addProperty("IsUsable", &GCBaseDoor::GetIsUsable, &GCBaseDoor::SetIsUsable)
        .addProperty("Parent", &GCBaseDoor::GetParent, &GCBaseDoor::SetParent)
        .addFunction("ToPtr", &GCBaseDoor::ToPtr)
        .addFunction("IsValid", &GCBaseDoor::IsValid)
        .endClass();
}