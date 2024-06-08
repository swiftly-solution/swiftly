class GCCSBot;

#ifndef _gcccsbot_h
#define _gcccsbot_h

#include "../../../scripting.h"


#include "GCountdownTimer.h"
#include "GCCSPlayerPawn.h"
#include "GCBaseEntity.h"
#include "GIntervalTimer.h"

class GCCSBot
{
private:
    void *m_ptr;

public:
    GCCSBot() {}
    GCCSBot(void *ptr) : m_ptr(ptr) {}

    Vector GetEyePosition() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_eyePosition"); }
    void SetEyePosition(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_eyePosition", false, value); }
    std::string GetName() const { return GetSchemaValue<char*>(m_ptr, "CCSBot", "m_name"); }
    void SetName(std::string value) { SetSchemaValue(m_ptr, "CCSBot", "m_name", false, value); }
    float GetCombatRange() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_combatRange"); }
    void SetCombatRange(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_combatRange", false, value); }
    bool GetIsRogue() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isRogue"); }
    void SetIsRogue(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isRogue", false, value); }
    GCountdownTimer GetRogueTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_rogueTimer"); }
    void SetRogueTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_rogueTimer", false, value); }
    bool GetDiedLastRound() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_diedLastRound"); }
    void SetDiedLastRound(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_diedLastRound", false, value); }
    float GetSafeTime() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_safeTime"); }
    void SetSafeTime(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_safeTime", false, value); }
    bool GetWasSafe() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_wasSafe"); }
    void SetWasSafe(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_wasSafe", false, value); }
    bool GetBlindFire() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_blindFire"); }
    void SetBlindFire(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_blindFire", false, value); }
    GCountdownTimer GetSurpriseTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_surpriseTimer"); }
    void SetSurpriseTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_surpriseTimer", false, value); }
    bool GetAllowActive() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_bAllowActive"); }
    void SetAllowActive(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_bAllowActive", false, value); }
    bool GetIsFollowing() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isFollowing"); }
    void SetIsFollowing(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isFollowing", false, value); }
    GCCSPlayerPawn* GetLeader() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CCSBot", "m_leader"); }
    void SetLeader(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Leader' is not possible.\n"); }
    float GetFollowTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_followTimestamp"); }
    void SetFollowTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_followTimestamp", false, value); }
    float GetAllowAutoFollowTime() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_allowAutoFollowTime"); }
    void SetAllowAutoFollowTime(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_allowAutoFollowTime", false, value); }
    GCountdownTimer GetHurryTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_hurryTimer"); }
    void SetHurryTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_hurryTimer", false, value); }
    GCountdownTimer GetAlertTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_alertTimer"); }
    void SetAlertTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_alertTimer", false, value); }
    GCountdownTimer GetSneakTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_sneakTimer"); }
    void SetSneakTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_sneakTimer", false, value); }
    GCountdownTimer GetPanicTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_panicTimer"); }
    void SetPanicTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_panicTimer", false, value); }
    float GetStateTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_stateTimestamp"); }
    void SetStateTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_stateTimestamp", false, value); }
    bool GetIsAttacking() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isAttacking"); }
    void SetIsAttacking(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isAttacking", false, value); }
    bool GetIsOpeningDoor() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isOpeningDoor"); }
    void SetIsOpeningDoor(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isOpeningDoor", false, value); }
    GCBaseEntity* GetTaskEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CCSBot", "m_taskEntity"); }
    void SetTaskEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TaskEntity' is not possible.\n"); }
    Vector GetGoalPosition() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_goalPosition"); }
    void SetGoalPosition(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_goalPosition", false, value); }
    GCBaseEntity* GetGoalEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CCSBot", "m_goalEntity"); }
    void SetGoalEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'GoalEntity' is not possible.\n"); }
    GCBaseEntity* GetAvoid() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CCSBot", "m_avoid"); }
    void SetAvoid(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Avoid' is not possible.\n"); }
    float GetAvoidTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_avoidTimestamp"); }
    void SetAvoidTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_avoidTimestamp", false, value); }
    bool GetIsStopping() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isStopping"); }
    void SetIsStopping(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isStopping", false, value); }
    bool GetHasVisitedEnemySpawn() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_hasVisitedEnemySpawn"); }
    void SetHasVisitedEnemySpawn(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_hasVisitedEnemySpawn", false, value); }
    GIntervalTimer GetStillTimer() const { return GetSchemaValue<GIntervalTimer>(m_ptr, "CCSBot", "m_stillTimer"); }
    void SetStillTimer(GIntervalTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_stillTimer", false, value); }
    bool GetEyeAnglesUnderPathFinderControl() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_bEyeAnglesUnderPathFinderControl"); }
    void SetEyeAnglesUnderPathFinderControl(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_bEyeAnglesUnderPathFinderControl", false, value); }
    int32_t GetPathIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_pathIndex"); }
    void SetPathIndex(int32_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_pathIndex", false, value); }
    GCountdownTimer GetRepathTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_repathTimer"); }
    void SetRepathTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_repathTimer", false, value); }
    GCountdownTimer GetAvoidFriendTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_avoidFriendTimer"); }
    void SetAvoidFriendTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_avoidFriendTimer", false, value); }
    bool GetIsFriendInTheWay() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isFriendInTheWay"); }
    void SetIsFriendInTheWay(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isFriendInTheWay", false, value); }
    GCountdownTimer GetPoliteTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_politeTimer"); }
    void SetPoliteTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_politeTimer", false, value); }
    bool GetIsWaitingBehindFriend() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isWaitingBehindFriend"); }
    void SetIsWaitingBehindFriend(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isWaitingBehindFriend", false, value); }
    float GetPathLadderEnd() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_pathLadderEnd"); }
    void SetPathLadderEnd(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_pathLadderEnd", false, value); }
    GCountdownTimer GetMustRunTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_mustRunTimer"); }
    void SetMustRunTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_mustRunTimer", false, value); }
    GCountdownTimer GetWaitTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_waitTimer"); }
    void SetWaitTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_waitTimer", false, value); }
    GCountdownTimer GetUpdateTravelDistanceTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_updateTravelDistanceTimer"); }
    void SetUpdateTravelDistanceTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_updateTravelDistanceTimer", false, value); }
    std::vector<float> GetPlayerTravelDistance() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CCSBot", "m_playerTravelDistance"); std::vector<float> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetPlayerTravelDistance(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CCSBot", "m_playerTravelDistance"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSBot", "m_playerTravelDistance", false, outValue); }
    uint8_t GetTravelDistancePhase() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_travelDistancePhase"); }
    void SetTravelDistancePhase(uint8_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_travelDistancePhase", false, value); }
    uint8_t GetHostageEscortCount() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_hostageEscortCount"); }
    void SetHostageEscortCount(uint8_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_hostageEscortCount", false, value); }
    float GetHostageEscortCountTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_hostageEscortCountTimestamp"); }
    void SetHostageEscortCountTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_hostageEscortCountTimestamp", false, value); }
    int32_t GetDesiredTeam() const { return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_desiredTeam"); }
    void SetDesiredTeam(int32_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_desiredTeam", false, value); }
    bool GetHasJoined() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_hasJoined"); }
    void SetHasJoined(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_hasJoined", false, value); }
    bool GetIsWaitingForHostage() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isWaitingForHostage"); }
    void SetIsWaitingForHostage(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isWaitingForHostage", false, value); }
    GCountdownTimer GetInhibitWaitingForHostageTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_inhibitWaitingForHostageTimer"); }
    void SetInhibitWaitingForHostageTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_inhibitWaitingForHostageTimer", false, value); }
    GCountdownTimer GetWaitForHostageTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_waitForHostageTimer"); }
    void SetWaitForHostageTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_waitForHostageTimer", false, value); }
    Vector GetNoisePosition() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_noisePosition"); }
    void SetNoisePosition(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_noisePosition", false, value); }
    float GetNoiseTravelDistance() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_noiseTravelDistance"); }
    void SetNoiseTravelDistance(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_noiseTravelDistance", false, value); }
    float GetNoiseTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_noiseTimestamp"); }
    void SetNoiseTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_noiseTimestamp", false, value); }
    GCCSPlayerPawn* GetNoiseSource() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CCSBot", "m_noiseSource"); }
    void SetNoiseSource(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'NoiseSource' is not possible.\n"); }
    GCountdownTimer GetNoiseBendTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_noiseBendTimer"); }
    void SetNoiseBendTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_noiseBendTimer", false, value); }
    Vector GetBentNoisePosition() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_bentNoisePosition"); }
    void SetBentNoisePosition(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_bentNoisePosition", false, value); }
    bool GetBendNoisePositionValid() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_bendNoisePositionValid"); }
    void SetBendNoisePositionValid(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_bendNoisePositionValid", false, value); }
    float GetLookAroundStateTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookAroundStateTimestamp"); }
    void SetLookAroundStateTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookAroundStateTimestamp", false, value); }
    float GetLookAheadAngle() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookAheadAngle"); }
    void SetLookAheadAngle(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookAheadAngle", false, value); }
    float GetForwardAngle() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_forwardAngle"); }
    void SetForwardAngle(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_forwardAngle", false, value); }
    float GetInhibitLookAroundTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_inhibitLookAroundTimestamp"); }
    void SetInhibitLookAroundTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_inhibitLookAroundTimestamp", false, value); }
    Vector GetLookAtSpot() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_lookAtSpot"); }
    void SetLookAtSpot(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpot", false, value); }
    float GetLookAtSpotDuration() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookAtSpotDuration"); }
    void SetLookAtSpotDuration(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpotDuration", false, value); }
    float GetLookAtSpotTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookAtSpotTimestamp"); }
    void SetLookAtSpotTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpotTimestamp", false, value); }
    float GetLookAtSpotAngleTolerance() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookAtSpotAngleTolerance"); }
    void SetLookAtSpotAngleTolerance(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpotAngleTolerance", false, value); }
    bool GetLookAtSpotClearIfClose() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_lookAtSpotClearIfClose"); }
    void SetLookAtSpotClearIfClose(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpotClearIfClose", false, value); }
    bool GetLookAtSpotAttack() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_lookAtSpotAttack"); }
    void SetLookAtSpotAttack(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpotAttack", false, value); }
    std::string GetLookAtDesc() const { return GetSchemaValue<char*>(m_ptr, "CCSBot", "m_lookAtDesc"); }
    void SetLookAtDesc(std::string value) { WriteSchemaPtrValue(m_ptr, "CCSBot", "m_lookAtDesc", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    float GetPeripheralTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_peripheralTimestamp"); }
    void SetPeripheralTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_peripheralTimestamp", false, value); }
    uint8_t GetApproachPointCount() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_approachPointCount"); }
    void SetApproachPointCount(uint8_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_approachPointCount", false, value); }
    Vector GetApproachPointViewPosition() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_approachPointViewPosition"); }
    void SetApproachPointViewPosition(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_approachPointViewPosition", false, value); }
    GIntervalTimer GetViewSteadyTimer() const { return GetSchemaValue<GIntervalTimer>(m_ptr, "CCSBot", "m_viewSteadyTimer"); }
    void SetViewSteadyTimer(GIntervalTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_viewSteadyTimer", false, value); }
    GCountdownTimer GetTossGrenadeTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_tossGrenadeTimer"); }
    void SetTossGrenadeTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_tossGrenadeTimer", false, value); }
    GCountdownTimer GetIsAvoidingGrenade() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_isAvoidingGrenade"); }
    void SetIsAvoidingGrenade(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_isAvoidingGrenade", false, value); }
    float GetSpotCheckTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_spotCheckTimestamp"); }
    void SetSpotCheckTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_spotCheckTimestamp", false, value); }
    int32_t GetCheckedHidingSpotCount() const { return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_checkedHidingSpotCount"); }
    void SetCheckedHidingSpotCount(int32_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_checkedHidingSpotCount", false, value); }
    float GetLookPitch() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookPitch"); }
    void SetLookPitch(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookPitch", false, value); }
    float GetLookPitchVel() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookPitchVel"); }
    void SetLookPitchVel(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookPitchVel", false, value); }
    float GetLookYaw() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookYaw"); }
    void SetLookYaw(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookYaw", false, value); }
    float GetLookYawVel() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookYawVel"); }
    void SetLookYawVel(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookYawVel", false, value); }
    Vector GetTargetSpot() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_targetSpot"); }
    void SetTargetSpot(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_targetSpot", false, value); }
    Vector GetTargetSpotVelocity() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_targetSpotVelocity"); }
    void SetTargetSpotVelocity(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_targetSpotVelocity", false, value); }
    Vector GetTargetSpotPredicted() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_targetSpotPredicted"); }
    void SetTargetSpotPredicted(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_targetSpotPredicted", false, value); }
    QAngle GetAimError() const { return GetSchemaValue<QAngle>(m_ptr, "CCSBot", "m_aimError"); }
    void SetAimError(QAngle value) { SetSchemaValue(m_ptr, "CCSBot", "m_aimError", false, value); }
    QAngle GetAimGoal() const { return GetSchemaValue<QAngle>(m_ptr, "CCSBot", "m_aimGoal"); }
    void SetAimGoal(QAngle value) { SetSchemaValue(m_ptr, "CCSBot", "m_aimGoal", false, value); }
    float GetAimFocus() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_aimFocus"); }
    void SetAimFocus(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_aimFocus", false, value); }
    float GetAimFocusInterval() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_aimFocusInterval"); }
    void SetAimFocusInterval(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_aimFocusInterval", false, value); }
    GCountdownTimer GetIgnoreEnemiesTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_ignoreEnemiesTimer"); }
    void SetIgnoreEnemiesTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_ignoreEnemiesTimer", false, value); }
    GCCSPlayerPawn* GetEnemy() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CCSBot", "m_enemy"); }
    void SetEnemy(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Enemy' is not possible.\n"); }
    bool GetIsEnemyVisible() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isEnemyVisible"); }
    void SetIsEnemyVisible(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isEnemyVisible", false, value); }
    uint8_t GetVisibleEnemyParts() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_visibleEnemyParts"); }
    void SetVisibleEnemyParts(uint8_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_visibleEnemyParts", false, value); }
    Vector GetLastEnemyPosition() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_lastEnemyPosition"); }
    void SetLastEnemyPosition(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_lastEnemyPosition", false, value); }
    float GetLastSawEnemyTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lastSawEnemyTimestamp"); }
    void SetLastSawEnemyTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lastSawEnemyTimestamp", false, value); }
    float GetFirstSawEnemyTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_firstSawEnemyTimestamp"); }
    void SetFirstSawEnemyTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_firstSawEnemyTimestamp", false, value); }
    float GetCurrentEnemyAcquireTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_currentEnemyAcquireTimestamp"); }
    void SetCurrentEnemyAcquireTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_currentEnemyAcquireTimestamp", false, value); }
    float GetEnemyDeathTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_enemyDeathTimestamp"); }
    void SetEnemyDeathTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_enemyDeathTimestamp", false, value); }
    float GetFriendDeathTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_friendDeathTimestamp"); }
    void SetFriendDeathTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_friendDeathTimestamp", false, value); }
    bool GetIsLastEnemyDead() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isLastEnemyDead"); }
    void SetIsLastEnemyDead(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isLastEnemyDead", false, value); }
    int32_t GetNearbyEnemyCount() const { return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_nearbyEnemyCount"); }
    void SetNearbyEnemyCount(int32_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_nearbyEnemyCount", false, value); }
    GCCSPlayerPawn* GetBomber() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CCSBot", "m_bomber"); }
    void SetBomber(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Bomber' is not possible.\n"); }
    int32_t GetNearbyFriendCount() const { return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_nearbyFriendCount"); }
    void SetNearbyFriendCount(int32_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_nearbyFriendCount", false, value); }
    GCCSPlayerPawn* GetClosestVisibleFriend() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CCSBot", "m_closestVisibleFriend"); }
    void SetClosestVisibleFriend(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ClosestVisibleFriend' is not possible.\n"); }
    GCCSPlayerPawn* GetClosestVisibleHumanFriend() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CCSBot", "m_closestVisibleHumanFriend"); }
    void SetClosestVisibleHumanFriend(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ClosestVisibleHumanFriend' is not possible.\n"); }
    GIntervalTimer GetAttentionInterval() const { return GetSchemaValue<GIntervalTimer>(m_ptr, "CCSBot", "m_attentionInterval"); }
    void SetAttentionInterval(GIntervalTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_attentionInterval", false, value); }
    GCCSPlayerPawn* GetAttacker() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CCSBot", "m_attacker"); }
    void SetAttacker(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Attacker' is not possible.\n"); }
    float GetAttackedTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_attackedTimestamp"); }
    void SetAttackedTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_attackedTimestamp", false, value); }
    GIntervalTimer GetBurnedByFlamesTimer() const { return GetSchemaValue<GIntervalTimer>(m_ptr, "CCSBot", "m_burnedByFlamesTimer"); }
    void SetBurnedByFlamesTimer(GIntervalTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_burnedByFlamesTimer", false, value); }
    int32_t GetLastVictimID() const { return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_lastVictimID"); }
    void SetLastVictimID(int32_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_lastVictimID", false, value); }
    bool GetIsAimingAtEnemy() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isAimingAtEnemy"); }
    void SetIsAimingAtEnemy(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isAimingAtEnemy", false, value); }
    bool GetIsRapidFiring() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isRapidFiring"); }
    void SetIsRapidFiring(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isRapidFiring", false, value); }
    GIntervalTimer GetEquipTimer() const { return GetSchemaValue<GIntervalTimer>(m_ptr, "CCSBot", "m_equipTimer"); }
    void SetEquipTimer(GIntervalTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_equipTimer", false, value); }
    GCountdownTimer GetZoomTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_zoomTimer"); }
    void SetZoomTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_zoomTimer", false, value); }
    GCountdownTimer GetLookForWeaponsOnGroundTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_lookForWeaponsOnGroundTimer"); }
    void SetLookForWeaponsOnGroundTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_lookForWeaponsOnGroundTimer", false, value); }
    bool GetIsSleeping() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_bIsSleeping"); }
    void SetIsSleeping(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_bIsSleeping", false, value); }
    bool GetIsEnemySniperVisible() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isEnemySniperVisible"); }
    void SetIsEnemySniperVisible(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isEnemySniperVisible", false, value); }
    GCountdownTimer GetSawEnemySniperTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_sawEnemySniperTimer"); }
    void SetSawEnemySniperTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_sawEnemySniperTimer", false, value); }
    uint8_t GetEnemyQueueIndex() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_enemyQueueIndex"); }
    void SetEnemyQueueIndex(uint8_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_enemyQueueIndex", false, value); }
    uint8_t GetEnemyQueueCount() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_enemyQueueCount"); }
    void SetEnemyQueueCount(uint8_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_enemyQueueCount", false, value); }
    uint8_t GetEnemyQueueAttendIndex() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_enemyQueueAttendIndex"); }
    void SetEnemyQueueAttendIndex(uint8_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_enemyQueueAttendIndex", false, value); }
    bool GetIsStuck() const { return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isStuck"); }
    void SetIsStuck(bool value) { SetSchemaValue(m_ptr, "CCSBot", "m_isStuck", false, value); }
    Vector GetStuckSpot() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_stuckSpot"); }
    void SetStuckSpot(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_stuckSpot", false, value); }
    GCountdownTimer GetWiggleTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_wiggleTimer"); }
    void SetWiggleTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_wiggleTimer", false, value); }
    GCountdownTimer GetStuckJumpTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CCSBot", "m_stuckJumpTimer"); }
    void SetStuckJumpTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CCSBot", "m_stuckJumpTimer", false, value); }
    std::vector<float> GetAvgVel() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CCSBot", "m_avgVel"); std::vector<float> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetAvgVel(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CCSBot", "m_avgVel"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSBot", "m_avgVel", false, outValue); }
    int32_t GetAvgVelIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_avgVelIndex"); }
    void SetAvgVelIndex(int32_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_avgVelIndex", false, value); }
    int32_t GetAvgVelCount() const { return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_avgVelCount"); }
    void SetAvgVelCount(int32_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_avgVelCount", false, value); }
    Vector GetLastOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_lastOrigin"); }
    void SetLastOrigin(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_lastOrigin", false, value); }
    float GetLastRadioRecievedTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lastRadioRecievedTimestamp"); }
    void SetLastRadioRecievedTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lastRadioRecievedTimestamp", false, value); }
    float GetLastRadioSentTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lastRadioSentTimestamp"); }
    void SetLastRadioSentTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_lastRadioSentTimestamp", false, value); }
    GCCSPlayerPawn* GetRadioSubject() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CCSBot", "m_radioSubject"); }
    void SetRadioSubject(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'RadioSubject' is not possible.\n"); }
    Vector GetRadioPosition() const { return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_radioPosition"); }
    void SetRadioPosition(Vector value) { SetSchemaValue(m_ptr, "CCSBot", "m_radioPosition", false, value); }
    float GetVoiceEndTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSBot", "m_voiceEndTimestamp"); }
    void SetVoiceEndTimestamp(float value) { SetSchemaValue(m_ptr, "CCSBot", "m_voiceEndTimestamp", false, value); }
    int32_t GetLastValidReactionQueueFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_lastValidReactionQueueFrame"); }
    void SetLastValidReactionQueueFrame(int32_t value) { SetSchemaValue(m_ptr, "CCSBot", "m_lastValidReactionQueueFrame", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif