class GCChicken;

#ifndef _gccchicken_h
#define _gccchicken_h

#include "../../../scripting.h"

#include "../types/GChickenActivity.h"
#include "GCAttributeContainer.h"
#include "GCountdownTimer.h"
#include "GCBaseEntity.h"
#include "GCCSPlayerPawn.h"

class GCChicken
{
private:
    void *m_ptr;

public:
    GCChicken() {}
    GCChicken(void *ptr) : m_ptr(ptr) {}

    GCAttributeContainer GetAttributeManager() const { return GetSchemaValue<GCAttributeContainer>(m_ptr, "CChicken", "m_AttributeManager"); }
    void SetAttributeManager(GCAttributeContainer value) { SetSchemaValue(m_ptr, "CChicken", "m_AttributeManager", false, value); }
    CUtlStringToken GetActivityFinishedTag() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CChicken", "m_sActivityFinishedTag"); }
    void SetActivityFinishedTag(CUtlStringToken value) { SetSchemaValue(m_ptr, "CChicken", "m_sActivityFinishedTag", false, value); }
    GCountdownTimer GetUpdateTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_updateTimer"); }
    void SetUpdateTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_updateTimer", false, value); }
    Vector GetStuckAnchor() const { return GetSchemaValue<Vector>(m_ptr, "CChicken", "m_stuckAnchor"); }
    void SetStuckAnchor(Vector value) { SetSchemaValue(m_ptr, "CChicken", "m_stuckAnchor", false, value); }
    GCountdownTimer GetStuckTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_stuckTimer"); }
    void SetStuckTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_stuckTimer", false, value); }
    GCountdownTimer GetCollisionStuckTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_collisionStuckTimer"); }
    void SetCollisionStuckTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_collisionStuckTimer", false, value); }
    bool GetIsOnGround() const { return GetSchemaValue<bool>(m_ptr, "CChicken", "m_isOnGround"); }
    void SetIsOnGround(bool value) { SetSchemaValue(m_ptr, "CChicken", "m_isOnGround", false, value); }
    Vector GetFallVelocity() const { return GetSchemaValue<Vector>(m_ptr, "CChicken", "m_vFallVelocity"); }
    void SetFallVelocity(Vector value) { SetSchemaValue(m_ptr, "CChicken", "m_vFallVelocity", false, value); }
    ChickenActivity GetDesiredActivity() const { return GetSchemaValue<ChickenActivity>(m_ptr, "CChicken", "m_desiredActivity"); }
    void SetDesiredActivity(ChickenActivity value) { SetSchemaValue(m_ptr, "CChicken", "m_desiredActivity", false, value); }
    ChickenActivity GetCurrentActivity() const { return GetSchemaValue<ChickenActivity>(m_ptr, "CChicken", "m_currentActivity"); }
    void SetCurrentActivity(ChickenActivity value) { SetSchemaValue(m_ptr, "CChicken", "m_currentActivity", false, value); }
    GCountdownTimer GetActivityTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_activityTimer"); }
    void SetActivityTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_activityTimer", false, value); }
    float GetTurnRate() const { return GetSchemaValue<float>(m_ptr, "CChicken", "m_turnRate"); }
    void SetTurnRate(float value) { SetSchemaValue(m_ptr, "CChicken", "m_turnRate", false, value); }
    GCBaseEntity* GetFleeFrom() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CChicken", "m_fleeFrom"); }
    void SetFleeFrom(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'FleeFrom' is not possible.\n"); }
    GCountdownTimer GetMoveRateThrottleTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_moveRateThrottleTimer"); }
    void SetMoveRateThrottleTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_moveRateThrottleTimer", false, value); }
    GCountdownTimer GetStartleTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_startleTimer"); }
    void SetStartleTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_startleTimer", false, value); }
    GCountdownTimer GetVocalizeTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_vocalizeTimer"); }
    void SetVocalizeTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_vocalizeTimer", false, value); }
    bool GetJumpedThisFrame() const { return GetSchemaValue<bool>(m_ptr, "CChicken", "m_jumpedThisFrame"); }
    void SetJumpedThisFrame(bool value) { SetSchemaValue(m_ptr, "CChicken", "m_jumpedThisFrame", false, value); }
    GCCSPlayerPawn* GetLeader() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CChicken", "m_leader"); }
    void SetLeader(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Leader' is not possible.\n"); }
    GCountdownTimer GetReuseTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_reuseTimer"); }
    void SetReuseTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_reuseTimer", false, value); }
    bool GetHasBeenUsed() const { return GetSchemaValue<bool>(m_ptr, "CChicken", "m_hasBeenUsed"); }
    void SetHasBeenUsed(bool value) { SetSchemaValue(m_ptr, "CChicken", "m_hasBeenUsed", false, value); }
    GCountdownTimer GetJumpTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_jumpTimer"); }
    void SetJumpTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_jumpTimer", false, value); }
    float GetLastJumpTime() const { return GetSchemaValue<float>(m_ptr, "CChicken", "m_flLastJumpTime"); }
    void SetLastJumpTime(float value) { SetSchemaValue(m_ptr, "CChicken", "m_flLastJumpTime", false, value); }
    bool GetInJump() const { return GetSchemaValue<bool>(m_ptr, "CChicken", "m_bInJump"); }
    void SetInJump(bool value) { SetSchemaValue(m_ptr, "CChicken", "m_bInJump", false, value); }
    bool GetIsWaitingForLeader() const { return GetSchemaValue<bool>(m_ptr, "CChicken", "m_isWaitingForLeader"); }
    void SetIsWaitingForLeader(bool value) { SetSchemaValue(m_ptr, "CChicken", "m_isWaitingForLeader", false, value); }
    GCountdownTimer GetRepathTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_repathTimer"); }
    void SetRepathTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_repathTimer", false, value); }
    GCountdownTimer GetInhibitDoorTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_inhibitDoorTimer"); }
    void SetInhibitDoorTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_inhibitDoorTimer", false, value); }
    GCountdownTimer GetInhibitObstacleAvoidanceTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_inhibitObstacleAvoidanceTimer"); }
    void SetInhibitObstacleAvoidanceTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_inhibitObstacleAvoidanceTimer", false, value); }
    Vector GetPathGoal() const { return GetSchemaValue<Vector>(m_ptr, "CChicken", "m_vecPathGoal"); }
    void SetPathGoal(Vector value) { SetSchemaValue(m_ptr, "CChicken", "m_vecPathGoal", false, value); }
    GCountdownTimer GetFollowMinuteTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_followMinuteTimer"); }
    void SetFollowMinuteTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_followMinuteTimer", false, value); }
    Vector GetLastEggPoopPosition() const { return GetSchemaValue<Vector>(m_ptr, "CChicken", "m_vecLastEggPoopPosition"); }
    void SetLastEggPoopPosition(Vector value) { SetSchemaValue(m_ptr, "CChicken", "m_vecLastEggPoopPosition", false, value); }
    GCountdownTimer GetBlockDirectionTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CChicken", "m_BlockDirectionTimer"); }
    void SetBlockDirectionTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CChicken", "m_BlockDirectionTimer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif