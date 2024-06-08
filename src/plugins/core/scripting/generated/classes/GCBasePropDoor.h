class GCBasePropDoor;

#ifndef _gccbasepropdoor_h
#define _gccbasepropdoor_h

#include "../../../scripting.h"

#include "../types/GDoorState_t.h"
#include "GCBaseEntity.h"
#include "Glocksound_t.h"
#include "GCBaseProp.h"
#include "GCBasePropDoor.h"
#include "GCEntityIOOutput.h"

class GCBasePropDoor
{
private:
    void *m_ptr;

public:
    GCBasePropDoor() {}
    GCBasePropDoor(void *ptr) : m_ptr(ptr) {}

    float GetAutoReturnDelay() const { return GetSchemaValue<float>(m_ptr, "CBasePropDoor", "m_flAutoReturnDelay"); }
    void SetAutoReturnDelay(float value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_flAutoReturnDelay", false, value); }
    int32_t GetHardwareType() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePropDoor", "m_nHardwareType"); }
    void SetHardwareType(int32_t value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_nHardwareType", false, value); }
    bool GetNeedsHardware() const { return GetSchemaValue<bool>(m_ptr, "CBasePropDoor", "m_bNeedsHardware"); }
    void SetNeedsHardware(bool value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_bNeedsHardware", false, value); }
    DoorState_t GetDoorState() const { return GetSchemaValue<DoorState_t>(m_ptr, "CBasePropDoor", "m_eDoorState"); }
    void SetDoorState(DoorState_t value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_eDoorState", false, value); }
    bool GetLocked() const { return GetSchemaValue<bool>(m_ptr, "CBasePropDoor", "m_bLocked"); }
    void SetLocked(bool value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_bLocked", false, value); }
    Vector GetClosedPosition() const { return GetSchemaValue<Vector>(m_ptr, "CBasePropDoor", "m_closedPosition"); }
    void SetClosedPosition(Vector value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_closedPosition", false, value); }
    QAngle GetClosedAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CBasePropDoor", "m_closedAngles"); }
    void SetClosedAngles(QAngle value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_closedAngles", false, value); }
    GCBaseEntity* GetBlocker() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBasePropDoor", "m_hBlocker"); }
    void SetBlocker(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Blocker' is not possible.\n"); }
    bool GetFirstBlocked() const { return GetSchemaValue<bool>(m_ptr, "CBasePropDoor", "m_bFirstBlocked"); }
    void SetFirstBlocked(bool value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_bFirstBlocked", false, value); }
    Glocksound_t GetLs() const { return GetSchemaValue<Glocksound_t>(m_ptr, "CBasePropDoor", "m_ls"); }
    void SetLs(Glocksound_t value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_ls", false, value); }
    bool GetForceClosed() const { return GetSchemaValue<bool>(m_ptr, "CBasePropDoor", "m_bForceClosed"); }
    void SetForceClosed(bool value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_bForceClosed", false, value); }
    Vector GetLatchWorldPosition() const { return GetSchemaValue<Vector>(m_ptr, "CBasePropDoor", "m_vecLatchWorldPosition"); }
    void SetLatchWorldPosition(Vector value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_vecLatchWorldPosition", false, value); }
    GCBaseEntity* GetActivator() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBasePropDoor", "m_hActivator"); }
    void SetActivator(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n"); }
    CUtlSymbolLarge GetSoundMoving() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundMoving"); }
    void SetSoundMoving(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundMoving", false, value); }
    CUtlSymbolLarge GetSoundOpen() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundOpen"); }
    void SetSoundOpen(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundOpen", false, value); }
    CUtlSymbolLarge GetSoundClose() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundClose"); }
    void SetSoundClose(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundClose", false, value); }
    CUtlSymbolLarge GetSoundLock() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundLock"); }
    void SetSoundLock(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundLock", false, value); }
    CUtlSymbolLarge GetSoundUnlock() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundUnlock"); }
    void SetSoundUnlock(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundUnlock", false, value); }
    CUtlSymbolLarge GetSoundLatch() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundLatch"); }
    void SetSoundLatch(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundLatch", false, value); }
    CUtlSymbolLarge GetSoundPound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundPound"); }
    void SetSoundPound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundPound", false, value); }
    CUtlSymbolLarge GetSoundJiggle() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundJiggle"); }
    void SetSoundJiggle(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundJiggle", false, value); }
    CUtlSymbolLarge GetSoundLockedAnim() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SoundLockedAnim"); }
    void SetSoundLockedAnim(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_SoundLockedAnim", false, value); }
    int32_t GetNumCloseAttempts() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePropDoor", "m_numCloseAttempts"); }
    void SetNumCloseAttempts(int32_t value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_numCloseAttempts", false, value); }
    CUtlStringToken GetPhysicsMaterial() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CBasePropDoor", "m_nPhysicsMaterial"); }
    void SetPhysicsMaterial(CUtlStringToken value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_nPhysicsMaterial", false, value); }
    CUtlSymbolLarge GetSlaveName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePropDoor", "m_SlaveName"); }
    void SetSlaveName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_SlaveName", false, value); }
    GCBasePropDoor* GetMaster() const { return GetSchemaValue<GCBasePropDoor*>(m_ptr, "CBasePropDoor", "m_hMaster"); }
    void SetMaster(GCBasePropDoor* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Master' is not possible.\n"); }
    GCEntityIOOutput GetOnBlockedClosing() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBasePropDoor", "m_OnBlockedClosing"); }
    void SetOnBlockedClosing(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnBlockedClosing", false, value); }
    GCEntityIOOutput GetOnBlockedOpening() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBasePropDoor", "m_OnBlockedOpening"); }
    void SetOnBlockedOpening(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnBlockedOpening", false, value); }
    GCEntityIOOutput GetOnUnblockedClosing() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBasePropDoor", "m_OnUnblockedClosing"); }
    void SetOnUnblockedClosing(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnUnblockedClosing", false, value); }
    GCEntityIOOutput GetOnUnblockedOpening() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBasePropDoor", "m_OnUnblockedOpening"); }
    void SetOnUnblockedOpening(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnUnblockedOpening", false, value); }
    GCEntityIOOutput GetOnFullyClosed() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBasePropDoor", "m_OnFullyClosed"); }
    void SetOnFullyClosed(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnFullyClosed", false, value); }
    GCEntityIOOutput GetOnFullyOpen() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBasePropDoor", "m_OnFullyOpen"); }
    void SetOnFullyOpen(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnFullyOpen", false, value); }
    GCEntityIOOutput GetOnClose() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBasePropDoor", "m_OnClose"); }
    void SetOnClose(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnClose", false, value); }
    GCEntityIOOutput GetOnOpen() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBasePropDoor", "m_OnOpen"); }
    void SetOnOpen(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnOpen", false, value); }
    GCEntityIOOutput GetOnLockedUse() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBasePropDoor", "m_OnLockedUse"); }
    void SetOnLockedUse(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnLockedUse", false, value); }
    GCEntityIOOutput GetOnAjarOpen() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBasePropDoor", "m_OnAjarOpen"); }
    void SetOnAjarOpen(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBasePropDoor", "m_OnAjarOpen", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif