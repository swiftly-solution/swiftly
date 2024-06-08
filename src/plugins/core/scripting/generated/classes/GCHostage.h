class GCHostage;

#ifndef _gcchostage_h
#define _gcchostage_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"
#include "GEntitySpottedState_t.h"
#include "GCBaseEntity.h"
#include "GCCSPlayerPawnBase.h"
#include "GCCSPlayerPawn.h"
#include "GCountdownTimer.h"

class GCHostage
{
private:
    void *m_ptr;

public:
    GCHostage() {}
    GCHostage(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnHostageBeginGrab() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CHostage", "m_OnHostageBeginGrab"); }
    void SetOnHostageBeginGrab(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CHostage", "m_OnHostageBeginGrab", false, value); }
    GCEntityIOOutput GetOnFirstPickedUp() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CHostage", "m_OnFirstPickedUp"); }
    void SetOnFirstPickedUp(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CHostage", "m_OnFirstPickedUp", false, value); }
    GCEntityIOOutput GetOnDroppedNotRescued() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CHostage", "m_OnDroppedNotRescued"); }
    void SetOnDroppedNotRescued(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CHostage", "m_OnDroppedNotRescued", false, value); }
    GCEntityIOOutput GetOnRescued() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CHostage", "m_OnRescued"); }
    void SetOnRescued(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CHostage", "m_OnRescued", false, value); }
    GEntitySpottedState_t GetEntitySpottedState() const { return GetSchemaValue<GEntitySpottedState_t>(m_ptr, "CHostage", "m_entitySpottedState"); }
    void SetEntitySpottedState(GEntitySpottedState_t value) { SetSchemaValue(m_ptr, "CHostage", "m_entitySpottedState", false, value); }
    int32_t GetSpotRules() const { return GetSchemaValue<int32_t>(m_ptr, "CHostage", "m_nSpotRules"); }
    void SetSpotRules(int32_t value) { SetSchemaValue(m_ptr, "CHostage", "m_nSpotRules", false, value); }
    uint32_t GetUiHostageSpawnExclusionGroupMask() const { return GetSchemaValue<uint32_t>(m_ptr, "CHostage", "m_uiHostageSpawnExclusionGroupMask"); }
    void SetUiHostageSpawnExclusionGroupMask(uint32_t value) { SetSchemaValue(m_ptr, "CHostage", "m_uiHostageSpawnExclusionGroupMask", false, value); }
    uint32_t GetHostageSpawnRandomFactor() const { return GetSchemaValue<uint32_t>(m_ptr, "CHostage", "m_nHostageSpawnRandomFactor"); }
    void SetHostageSpawnRandomFactor(uint32_t value) { SetSchemaValue(m_ptr, "CHostage", "m_nHostageSpawnRandomFactor", false, value); }
    bool GetRemove() const { return GetSchemaValue<bool>(m_ptr, "CHostage", "m_bRemove"); }
    void SetRemove(bool value) { SetSchemaValue(m_ptr, "CHostage", "m_bRemove", false, value); }
    Vector GetVel() const { return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_vel"); }
    void SetVel(Vector value) { SetSchemaValue(m_ptr, "CHostage", "m_vel", false, value); }
    bool GetIsRescued() const { return GetSchemaValue<bool>(m_ptr, "CHostage", "m_isRescued"); }
    void SetIsRescued(bool value) { SetSchemaValue(m_ptr, "CHostage", "m_isRescued", false, value); }
    bool GetJumpedThisFrame() const { return GetSchemaValue<bool>(m_ptr, "CHostage", "m_jumpedThisFrame"); }
    void SetJumpedThisFrame(bool value) { SetSchemaValue(m_ptr, "CHostage", "m_jumpedThisFrame", false, value); }
    int32_t GetHostageState() const { return GetSchemaValue<int32_t>(m_ptr, "CHostage", "m_nHostageState"); }
    void SetHostageState(int32_t value) { SetSchemaValue(m_ptr, "CHostage", "m_nHostageState", false, value); }
    GCBaseEntity* GetLeader() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CHostage", "m_leader"); }
    void SetLeader(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Leader' is not possible.\n"); }
    GCCSPlayerPawnBase* GetLastLeader() const { return GetSchemaValue<GCCSPlayerPawnBase*>(m_ptr, "CHostage", "m_lastLeader"); }
    void SetLastLeader(GCCSPlayerPawnBase* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastLeader' is not possible.\n"); }
    GCountdownTimer GetReuseTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CHostage", "m_reuseTimer"); }
    void SetReuseTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CHostage", "m_reuseTimer", false, value); }
    bool GetHasBeenUsed() const { return GetSchemaValue<bool>(m_ptr, "CHostage", "m_hasBeenUsed"); }
    void SetHasBeenUsed(bool value) { SetSchemaValue(m_ptr, "CHostage", "m_hasBeenUsed", false, value); }
    Vector GetAccel() const { return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_accel"); }
    void SetAccel(Vector value) { SetSchemaValue(m_ptr, "CHostage", "m_accel", false, value); }
    bool GetIsRunning() const { return GetSchemaValue<bool>(m_ptr, "CHostage", "m_isRunning"); }
    void SetIsRunning(bool value) { SetSchemaValue(m_ptr, "CHostage", "m_isRunning", false, value); }
    bool GetIsCrouching() const { return GetSchemaValue<bool>(m_ptr, "CHostage", "m_isCrouching"); }
    void SetIsCrouching(bool value) { SetSchemaValue(m_ptr, "CHostage", "m_isCrouching", false, value); }
    GCountdownTimer GetJumpTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CHostage", "m_jumpTimer"); }
    void SetJumpTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CHostage", "m_jumpTimer", false, value); }
    bool GetIsWaitingForLeader() const { return GetSchemaValue<bool>(m_ptr, "CHostage", "m_isWaitingForLeader"); }
    void SetIsWaitingForLeader(bool value) { SetSchemaValue(m_ptr, "CHostage", "m_isWaitingForLeader", false, value); }
    GCountdownTimer GetRepathTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CHostage", "m_repathTimer"); }
    void SetRepathTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CHostage", "m_repathTimer", false, value); }
    GCountdownTimer GetInhibitDoorTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CHostage", "m_inhibitDoorTimer"); }
    void SetInhibitDoorTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CHostage", "m_inhibitDoorTimer", false, value); }
    GCountdownTimer GetInhibitObstacleAvoidanceTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CHostage", "m_inhibitObstacleAvoidanceTimer"); }
    void SetInhibitObstacleAvoidanceTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CHostage", "m_inhibitObstacleAvoidanceTimer", false, value); }
    GCountdownTimer GetWiggleTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CHostage", "m_wiggleTimer"); }
    void SetWiggleTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CHostage", "m_wiggleTimer", false, value); }
    bool GetIsAdjusted() const { return GetSchemaValue<bool>(m_ptr, "CHostage", "m_isAdjusted"); }
    void SetIsAdjusted(bool value) { SetSchemaValue(m_ptr, "CHostage", "m_isAdjusted", false, value); }
    bool GetHandsHaveBeenCut() const { return GetSchemaValue<bool>(m_ptr, "CHostage", "m_bHandsHaveBeenCut"); }
    void SetHandsHaveBeenCut(bool value) { SetSchemaValue(m_ptr, "CHostage", "m_bHandsHaveBeenCut", false, value); }
    GCCSPlayerPawn* GetHostageGrabber() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CHostage", "m_hHostageGrabber"); }
    void SetHostageGrabber(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'HostageGrabber' is not possible.\n"); }
    Vector GetPositionWhenStartedDroppingToGround() const { return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_vecPositionWhenStartedDroppingToGround"); }
    void SetPositionWhenStartedDroppingToGround(Vector value) { SetSchemaValue(m_ptr, "CHostage", "m_vecPositionWhenStartedDroppingToGround", false, value); }
    Vector GetGrabbedPos() const { return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_vecGrabbedPos"); }
    void SetGrabbedPos(Vector value) { SetSchemaValue(m_ptr, "CHostage", "m_vecGrabbedPos", false, value); }
    int32_t GetApproachRewardPayouts() const { return GetSchemaValue<int32_t>(m_ptr, "CHostage", "m_nApproachRewardPayouts"); }
    void SetApproachRewardPayouts(int32_t value) { SetSchemaValue(m_ptr, "CHostage", "m_nApproachRewardPayouts", false, value); }
    int32_t GetPickupEventCount() const { return GetSchemaValue<int32_t>(m_ptr, "CHostage", "m_nPickupEventCount"); }
    void SetPickupEventCount(int32_t value) { SetSchemaValue(m_ptr, "CHostage", "m_nPickupEventCount", false, value); }
    Vector GetSpawnGroundPos() const { return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_vecSpawnGroundPos"); }
    void SetSpawnGroundPos(Vector value) { SetSchemaValue(m_ptr, "CHostage", "m_vecSpawnGroundPos", false, value); }
    Vector GetHostageResetPosition() const { return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_vecHostageResetPosition"); }
    void SetHostageResetPosition(Vector value) { SetSchemaValue(m_ptr, "CHostage", "m_vecHostageResetPosition", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif