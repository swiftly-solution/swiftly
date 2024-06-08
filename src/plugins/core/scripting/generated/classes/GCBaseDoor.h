class GCBaseDoor;

#ifndef _gccbasedoor_h
#define _gccbasedoor_h

#include "../../../scripting.h"

#include "../types/GFuncDoorSpawnPos_t.h"
#include "Glocksound_t.h"
#include "GCEntityIOOutput.h"

class GCBaseDoor
{
private:
    void *m_ptr;

public:
    GCBaseDoor() {}
    GCBaseDoor(void *ptr) : m_ptr(ptr) {}

    QAngle GetMoveEntitySpace() const { return GetSchemaValue<QAngle>(m_ptr, "CBaseDoor", "m_angMoveEntitySpace"); }
    void SetMoveEntitySpace(QAngle value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_angMoveEntitySpace", false, value); }
    Vector GetMoveDirParentSpace() const { return GetSchemaValue<Vector>(m_ptr, "CBaseDoor", "m_vecMoveDirParentSpace"); }
    void SetMoveDirParentSpace(Vector value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_vecMoveDirParentSpace", false, value); }
    Glocksound_t GetLs() const { return GetSchemaValue<Glocksound_t>(m_ptr, "CBaseDoor", "m_ls"); }
    void SetLs(Glocksound_t value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_ls", false, value); }
    bool GetForceClosed() const { return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bForceClosed"); }
    void SetForceClosed(bool value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_bForceClosed", false, value); }
    bool GetDoorGroup() const { return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bDoorGroup"); }
    void SetDoorGroup(bool value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_bDoorGroup", false, value); }
    bool GetLocked() const { return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bLocked"); }
    void SetLocked(bool value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_bLocked", false, value); }
    bool GetIgnoreDebris() const { return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bIgnoreDebris"); }
    void SetIgnoreDebris(bool value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_bIgnoreDebris", false, value); }
    FuncDoorSpawnPos_t GetSpawnPosition() const { return GetSchemaValue<FuncDoorSpawnPos_t>(m_ptr, "CBaseDoor", "m_eSpawnPosition"); }
    void SetSpawnPosition(FuncDoorSpawnPos_t value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_eSpawnPosition", false, value); }
    float GetBlockDamage() const { return GetSchemaValue<float>(m_ptr, "CBaseDoor", "m_flBlockDamage"); }
    void SetBlockDamage(float value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_flBlockDamage", false, value); }
    CUtlSymbolLarge GetNoiseMoving() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDoor", "m_NoiseMoving"); }
    void SetNoiseMoving(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_NoiseMoving", false, value); }
    CUtlSymbolLarge GetNoiseArrived() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDoor", "m_NoiseArrived"); }
    void SetNoiseArrived(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_NoiseArrived", false, value); }
    CUtlSymbolLarge GetNoiseMovingClosed() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDoor", "m_NoiseMovingClosed"); }
    void SetNoiseMovingClosed(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_NoiseMovingClosed", false, value); }
    CUtlSymbolLarge GetNoiseArrivedClosed() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDoor", "m_NoiseArrivedClosed"); }
    void SetNoiseArrivedClosed(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_NoiseArrivedClosed", false, value); }
    CUtlSymbolLarge GetChainTarget() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDoor", "m_ChainTarget"); }
    void SetChainTarget(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_ChainTarget", false, value); }
    GCEntityIOOutput GetOnBlockedClosing() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseDoor", "m_OnBlockedClosing"); }
    void SetOnBlockedClosing(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_OnBlockedClosing", false, value); }
    GCEntityIOOutput GetOnBlockedOpening() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseDoor", "m_OnBlockedOpening"); }
    void SetOnBlockedOpening(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_OnBlockedOpening", false, value); }
    GCEntityIOOutput GetOnUnblockedClosing() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseDoor", "m_OnUnblockedClosing"); }
    void SetOnUnblockedClosing(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_OnUnblockedClosing", false, value); }
    GCEntityIOOutput GetOnUnblockedOpening() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseDoor", "m_OnUnblockedOpening"); }
    void SetOnUnblockedOpening(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_OnUnblockedOpening", false, value); }
    GCEntityIOOutput GetOnFullyClosed() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseDoor", "m_OnFullyClosed"); }
    void SetOnFullyClosed(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_OnFullyClosed", false, value); }
    GCEntityIOOutput GetOnFullyOpen() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseDoor", "m_OnFullyOpen"); }
    void SetOnFullyOpen(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_OnFullyOpen", false, value); }
    GCEntityIOOutput GetOnClose() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseDoor", "m_OnClose"); }
    void SetOnClose(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_OnClose", false, value); }
    GCEntityIOOutput GetOnOpen() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseDoor", "m_OnOpen"); }
    void SetOnOpen(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_OnOpen", false, value); }
    GCEntityIOOutput GetOnLockedUse() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseDoor", "m_OnLockedUse"); }
    void SetOnLockedUse(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_OnLockedUse", false, value); }
    bool GetLoopMoveSound() const { return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bLoopMoveSound"); }
    void SetLoopMoveSound(bool value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_bLoopMoveSound", false, value); }
    bool GetCreateNavObstacle() const { return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bCreateNavObstacle"); }
    void SetCreateNavObstacle(bool value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_bCreateNavObstacle", false, value); }
    bool GetIsChaining() const { return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_isChaining"); }
    void SetIsChaining(bool value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_isChaining", false, value); }
    bool GetIsUsable() const { return GetSchemaValue<bool>(m_ptr, "CBaseDoor", "m_bIsUsable"); }
    void SetIsUsable(bool value) { SetSchemaValue(m_ptr, "CBaseDoor", "m_bIsUsable", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif