#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBasePropDoor::GCBasePropDoor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBasePropDoor::GCBasePropDoor(void *ptr) {
    m_ptr = ptr;
}
float GCBasePropDoor::GetAutoReturnDelay() const {
    return GetSchemaValue<float>(m_ptr, "CBasePropDoor", "m_flAutoReturnDelay");
}
void GCBasePropDoor::SetAutoReturnDelay(float value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_flAutoReturnDelay", false, value);
}
int32_t GCBasePropDoor::GetHardwareType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePropDoor", "m_nHardwareType");
}
void GCBasePropDoor::SetHardwareType(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_nHardwareType", false, value);
}
bool GCBasePropDoor::GetNeedsHardware() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePropDoor", "m_bNeedsHardware");
}
void GCBasePropDoor::SetNeedsHardware(bool value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_bNeedsHardware", false, value);
}
uint64_t GCBasePropDoor::GetDoorState() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBasePropDoor", "m_eDoorState");
}
void GCBasePropDoor::SetDoorState(uint64_t value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_eDoorState", false, value);
}
bool GCBasePropDoor::GetLocked() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePropDoor", "m_bLocked");
}
void GCBasePropDoor::SetLocked(bool value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_bLocked", false, value);
}
Vector GCBasePropDoor::GetClosedPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CBasePropDoor", "m_closedPosition");
}
void GCBasePropDoor::SetClosedPosition(Vector value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_closedPosition", false, value);
}
QAngle GCBasePropDoor::GetClosedAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBasePropDoor", "m_closedAngles");
}
void GCBasePropDoor::SetClosedAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_closedAngles", false, value);
}
GCBaseEntity GCBasePropDoor::GetBlocker() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePropDoor", "m_hBlocker"));
    return value;
}
void GCBasePropDoor::SetBlocker(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Blocker' is not possible.\n");
}
bool GCBasePropDoor::GetFirstBlocked() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePropDoor", "m_bFirstBlocked");
}
void GCBasePropDoor::SetFirstBlocked(bool value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_bFirstBlocked", false, value);
}
Glocksound_t GCBasePropDoor::GetLs() const {
    Glocksound_t value(GetSchemaPtr(m_ptr, "CBasePropDoor", "m_ls"));
    return value;
}
void GCBasePropDoor::SetLs(Glocksound_t value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_ls", false, value);
}
bool GCBasePropDoor::GetForceClosed() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePropDoor", "m_bForceClosed");
}
void GCBasePropDoor::SetForceClosed(bool value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_bForceClosed", false, value);
}
Vector GCBasePropDoor::GetLatchWorldPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CBasePropDoor", "m_vecLatchWorldPosition");
}
void GCBasePropDoor::SetLatchWorldPosition(Vector value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_vecLatchWorldPosition", false, value);
}
GCBaseEntity GCBasePropDoor::GetActivator() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePropDoor", "m_hActivator"));
    return value;
}
void GCBasePropDoor::SetActivator(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n");
}
std::string GCBasePropDoor::GetSoundMoving() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundMoving").String();
}
void GCBasePropDoor::SetSoundMoving(std::string value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundMoving", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBasePropDoor::GetSoundOpen() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundOpen").String();
}
void GCBasePropDoor::SetSoundOpen(std::string value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundOpen", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBasePropDoor::GetSoundClose() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundClose").String();
}
void GCBasePropDoor::SetSoundClose(std::string value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundClose", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBasePropDoor::GetSoundLock() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundLock").String();
}
void GCBasePropDoor::SetSoundLock(std::string value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundLock", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBasePropDoor::GetSoundUnlock() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundUnlock").String();
}
void GCBasePropDoor::SetSoundUnlock(std::string value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundUnlock", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBasePropDoor::GetSoundLatch() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundLatch").String();
}
void GCBasePropDoor::SetSoundLatch(std::string value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundLatch", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBasePropDoor::GetSoundPound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundPound").String();
}
void GCBasePropDoor::SetSoundPound(std::string value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundPound", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBasePropDoor::GetSoundJiggle() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundJiggle").String();
}
void GCBasePropDoor::SetSoundJiggle(std::string value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundJiggle", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBasePropDoor::GetSoundLockedAnim() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundLockedAnim").String();
}
void GCBasePropDoor::SetSoundLockedAnim(std::string value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundLockedAnim", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCBasePropDoor::GetNumCloseAttempts() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePropDoor", "m_numCloseAttempts");
}
void GCBasePropDoor::SetNumCloseAttempts(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_numCloseAttempts", false, value);
}
CUtlStringToken GCBasePropDoor::GetPhysicsMaterial() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "CBasePropDoor", "m_nPhysicsMaterial");
}
void GCBasePropDoor::SetPhysicsMaterial(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_nPhysicsMaterial", false, value);
}
std::string GCBasePropDoor::GetSlaveName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SlaveName").String();
}
void GCBasePropDoor::SetSlaveName(std::string value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_SlaveName", false, CUtlSymbolLarge(value.c_str()));
}
GCBasePropDoor GCBasePropDoor::GetMaster() const {
    GCBasePropDoor value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePropDoor", "m_hMaster"));
    return value;
}
void GCBasePropDoor::SetMaster(GCBasePropDoor* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Master' is not possible.\n");
}
GCEntityIOOutput GCBasePropDoor::GetOnBlockedClosing() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBasePropDoor", "m_OnBlockedClosing"));
    return value;
}
void GCBasePropDoor::SetOnBlockedClosing(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnBlockedClosing", false, value);
}
GCEntityIOOutput GCBasePropDoor::GetOnBlockedOpening() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBasePropDoor", "m_OnBlockedOpening"));
    return value;
}
void GCBasePropDoor::SetOnBlockedOpening(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnBlockedOpening", false, value);
}
GCEntityIOOutput GCBasePropDoor::GetOnUnblockedClosing() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBasePropDoor", "m_OnUnblockedClosing"));
    return value;
}
void GCBasePropDoor::SetOnUnblockedClosing(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnUnblockedClosing", false, value);
}
GCEntityIOOutput GCBasePropDoor::GetOnUnblockedOpening() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBasePropDoor", "m_OnUnblockedOpening"));
    return value;
}
void GCBasePropDoor::SetOnUnblockedOpening(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnUnblockedOpening", false, value);
}
GCEntityIOOutput GCBasePropDoor::GetOnFullyClosed() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBasePropDoor", "m_OnFullyClosed"));
    return value;
}
void GCBasePropDoor::SetOnFullyClosed(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnFullyClosed", false, value);
}
GCEntityIOOutput GCBasePropDoor::GetOnFullyOpen() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBasePropDoor", "m_OnFullyOpen"));
    return value;
}
void GCBasePropDoor::SetOnFullyOpen(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnFullyOpen", false, value);
}
GCEntityIOOutput GCBasePropDoor::GetOnClose() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBasePropDoor", "m_OnClose"));
    return value;
}
void GCBasePropDoor::SetOnClose(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnClose", false, value);
}
GCEntityIOOutput GCBasePropDoor::GetOnOpen() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBasePropDoor", "m_OnOpen"));
    return value;
}
void GCBasePropDoor::SetOnOpen(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnOpen", false, value);
}
GCEntityIOOutput GCBasePropDoor::GetOnLockedUse() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBasePropDoor", "m_OnLockedUse"));
    return value;
}
void GCBasePropDoor::SetOnLockedUse(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnLockedUse", false, value);
}
GCEntityIOOutput GCBasePropDoor::GetOnAjarOpen() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBasePropDoor", "m_OnAjarOpen"));
    return value;
}
void GCBasePropDoor::SetOnAjarOpen(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnAjarOpen", false, value);
}
std::string GCBasePropDoor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBasePropDoor::IsValid() {
    return (m_ptr != nullptr);
}
GCDynamicProp GCBasePropDoor::GetParent() const {
    GCDynamicProp value(m_ptr);
    return value;
}
void GCBasePropDoor::SetParent(GCDynamicProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBasePropDoor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePropDoor>("CBasePropDoor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AutoReturnDelay", &GCBasePropDoor::GetAutoReturnDelay, &GCBasePropDoor::SetAutoReturnDelay)
        .addProperty("HardwareType", &GCBasePropDoor::GetHardwareType, &GCBasePropDoor::SetHardwareType)
        .addProperty("NeedsHardware", &GCBasePropDoor::GetNeedsHardware, &GCBasePropDoor::SetNeedsHardware)
        .addProperty("DoorState", &GCBasePropDoor::GetDoorState, &GCBasePropDoor::SetDoorState)
        .addProperty("Locked", &GCBasePropDoor::GetLocked, &GCBasePropDoor::SetLocked)
        .addProperty("ClosedPosition", &GCBasePropDoor::GetClosedPosition, &GCBasePropDoor::SetClosedPosition)
        .addProperty("ClosedAngles", &GCBasePropDoor::GetClosedAngles, &GCBasePropDoor::SetClosedAngles)
        .addProperty("Blocker", &GCBasePropDoor::GetBlocker, &GCBasePropDoor::SetBlocker)
        .addProperty("FirstBlocked", &GCBasePropDoor::GetFirstBlocked, &GCBasePropDoor::SetFirstBlocked)
        .addProperty("Ls", &GCBasePropDoor::GetLs, &GCBasePropDoor::SetLs)
        .addProperty("ForceClosed", &GCBasePropDoor::GetForceClosed, &GCBasePropDoor::SetForceClosed)
        .addProperty("LatchWorldPosition", &GCBasePropDoor::GetLatchWorldPosition, &GCBasePropDoor::SetLatchWorldPosition)
        .addProperty("Activator", &GCBasePropDoor::GetActivator, &GCBasePropDoor::SetActivator)
        .addProperty("SoundMoving", &GCBasePropDoor::GetSoundMoving, &GCBasePropDoor::SetSoundMoving)
        .addProperty("SoundOpen", &GCBasePropDoor::GetSoundOpen, &GCBasePropDoor::SetSoundOpen)
        .addProperty("SoundClose", &GCBasePropDoor::GetSoundClose, &GCBasePropDoor::SetSoundClose)
        .addProperty("SoundLock", &GCBasePropDoor::GetSoundLock, &GCBasePropDoor::SetSoundLock)
        .addProperty("SoundUnlock", &GCBasePropDoor::GetSoundUnlock, &GCBasePropDoor::SetSoundUnlock)
        .addProperty("SoundLatch", &GCBasePropDoor::GetSoundLatch, &GCBasePropDoor::SetSoundLatch)
        .addProperty("SoundPound", &GCBasePropDoor::GetSoundPound, &GCBasePropDoor::SetSoundPound)
        .addProperty("SoundJiggle", &GCBasePropDoor::GetSoundJiggle, &GCBasePropDoor::SetSoundJiggle)
        .addProperty("SoundLockedAnim", &GCBasePropDoor::GetSoundLockedAnim, &GCBasePropDoor::SetSoundLockedAnim)
        .addProperty("NumCloseAttempts", &GCBasePropDoor::GetNumCloseAttempts, &GCBasePropDoor::SetNumCloseAttempts)
        .addProperty("PhysicsMaterial", &GCBasePropDoor::GetPhysicsMaterial, &GCBasePropDoor::SetPhysicsMaterial)
        .addProperty("SlaveName", &GCBasePropDoor::GetSlaveName, &GCBasePropDoor::SetSlaveName)
        .addProperty("Master", &GCBasePropDoor::GetMaster, &GCBasePropDoor::SetMaster)
        .addProperty("OnBlockedClosing", &GCBasePropDoor::GetOnBlockedClosing, &GCBasePropDoor::SetOnBlockedClosing)
        .addProperty("OnBlockedOpening", &GCBasePropDoor::GetOnBlockedOpening, &GCBasePropDoor::SetOnBlockedOpening)
        .addProperty("OnUnblockedClosing", &GCBasePropDoor::GetOnUnblockedClosing, &GCBasePropDoor::SetOnUnblockedClosing)
        .addProperty("OnUnblockedOpening", &GCBasePropDoor::GetOnUnblockedOpening, &GCBasePropDoor::SetOnUnblockedOpening)
        .addProperty("OnFullyClosed", &GCBasePropDoor::GetOnFullyClosed, &GCBasePropDoor::SetOnFullyClosed)
        .addProperty("OnFullyOpen", &GCBasePropDoor::GetOnFullyOpen, &GCBasePropDoor::SetOnFullyOpen)
        .addProperty("OnClose", &GCBasePropDoor::GetOnClose, &GCBasePropDoor::SetOnClose)
        .addProperty("OnOpen", &GCBasePropDoor::GetOnOpen, &GCBasePropDoor::SetOnOpen)
        .addProperty("OnLockedUse", &GCBasePropDoor::GetOnLockedUse, &GCBasePropDoor::SetOnLockedUse)
        .addProperty("OnAjarOpen", &GCBasePropDoor::GetOnAjarOpen, &GCBasePropDoor::SetOnAjarOpen)
        .addProperty("Parent", &GCBasePropDoor::GetParent, &GCBasePropDoor::SetParent)
        .addFunction("ToPtr", &GCBasePropDoor::ToPtr)
        .addFunction("IsValid", &GCBasePropDoor::IsValid)
        .endClass();
}