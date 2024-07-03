#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSBot::GCCSBot(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSBot::GCCSBot(void *ptr) {
    m_ptr = ptr;
}
Vector GCCSBot::GetEyePosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_eyePosition");
}
void GCCSBot::SetEyePosition(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_eyePosition", false, value);
}
std::string GCCSBot::GetName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSBot", "m_name");
}
void GCCSBot::SetName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSBot", "m_name", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 64);
}
float GCCSBot::GetCombatRange() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_combatRange");
}
void GCCSBot::SetCombatRange(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_combatRange", false, value);
}
bool GCCSBot::GetIsRogue() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isRogue");
}
void GCCSBot::SetIsRogue(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isRogue", false, value);
}
GCountdownTimer GCCSBot::GetRogueTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_rogueTimer"));
    return value;
}
void GCCSBot::SetRogueTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_rogueTimer", false, value);
}
bool GCCSBot::GetDiedLastRound() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_diedLastRound");
}
void GCCSBot::SetDiedLastRound(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_diedLastRound", false, value);
}
float GCCSBot::GetSafeTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_safeTime");
}
void GCCSBot::SetSafeTime(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_safeTime", false, value);
}
bool GCCSBot::GetWasSafe() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_wasSafe");
}
void GCCSBot::SetWasSafe(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_wasSafe", false, value);
}
bool GCCSBot::GetBlindFire() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_blindFire");
}
void GCCSBot::SetBlindFire(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_blindFire", false, value);
}
GCountdownTimer GCCSBot::GetSurpriseTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_surpriseTimer"));
    return value;
}
void GCCSBot::SetSurpriseTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_surpriseTimer", false, value);
}
bool GCCSBot::GetAllowActive() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_bAllowActive");
}
void GCCSBot::SetAllowActive(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_bAllowActive", false, value);
}
bool GCCSBot::GetIsFollowing() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isFollowing");
}
void GCCSBot::SetIsFollowing(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isFollowing", false, value);
}
GCCSPlayerPawn GCCSBot::GetLeader() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CCSBot", "m_leader"));
    return value;
}
void GCCSBot::SetLeader(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Leader' is not possible.\n");
}
float GCCSBot::GetFollowTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_followTimestamp");
}
void GCCSBot::SetFollowTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_followTimestamp", false, value);
}
float GCCSBot::GetAllowAutoFollowTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_allowAutoFollowTime");
}
void GCCSBot::SetAllowAutoFollowTime(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_allowAutoFollowTime", false, value);
}
GCountdownTimer GCCSBot::GetHurryTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_hurryTimer"));
    return value;
}
void GCCSBot::SetHurryTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_hurryTimer", false, value);
}
GCountdownTimer GCCSBot::GetAlertTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_alertTimer"));
    return value;
}
void GCCSBot::SetAlertTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_alertTimer", false, value);
}
GCountdownTimer GCCSBot::GetSneakTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_sneakTimer"));
    return value;
}
void GCCSBot::SetSneakTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_sneakTimer", false, value);
}
GCountdownTimer GCCSBot::GetPanicTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_panicTimer"));
    return value;
}
void GCCSBot::SetPanicTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_panicTimer", false, value);
}
float GCCSBot::GetStateTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_stateTimestamp");
}
void GCCSBot::SetStateTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_stateTimestamp", false, value);
}
bool GCCSBot::GetIsAttacking() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isAttacking");
}
void GCCSBot::SetIsAttacking(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isAttacking", false, value);
}
bool GCCSBot::GetIsOpeningDoor() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isOpeningDoor");
}
void GCCSBot::SetIsOpeningDoor(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isOpeningDoor", false, value);
}
GCBaseEntity GCCSBot::GetTaskEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CCSBot", "m_taskEntity"));
    return value;
}
void GCCSBot::SetTaskEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TaskEntity' is not possible.\n");
}
Vector GCCSBot::GetGoalPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_goalPosition");
}
void GCCSBot::SetGoalPosition(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_goalPosition", false, value);
}
GCBaseEntity GCCSBot::GetGoalEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CCSBot", "m_goalEntity"));
    return value;
}
void GCCSBot::SetGoalEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'GoalEntity' is not possible.\n");
}
GCBaseEntity GCCSBot::GetAvoid() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CCSBot", "m_avoid"));
    return value;
}
void GCCSBot::SetAvoid(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Avoid' is not possible.\n");
}
float GCCSBot::GetAvoidTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_avoidTimestamp");
}
void GCCSBot::SetAvoidTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_avoidTimestamp", false, value);
}
bool GCCSBot::GetIsStopping() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isStopping");
}
void GCCSBot::SetIsStopping(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isStopping", false, value);
}
bool GCCSBot::GetHasVisitedEnemySpawn() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_hasVisitedEnemySpawn");
}
void GCCSBot::SetHasVisitedEnemySpawn(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_hasVisitedEnemySpawn", false, value);
}
GIntervalTimer GCCSBot::GetStillTimer() const {
    GIntervalTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_stillTimer"));
    return value;
}
void GCCSBot::SetStillTimer(GIntervalTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_stillTimer", false, value);
}
bool GCCSBot::GetEyeAnglesUnderPathFinderControl() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_bEyeAnglesUnderPathFinderControl");
}
void GCCSBot::SetEyeAnglesUnderPathFinderControl(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_bEyeAnglesUnderPathFinderControl", false, value);
}
int32_t GCCSBot::GetPathIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_pathIndex");
}
void GCCSBot::SetPathIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_pathIndex", false, value);
}
float GCCSBot::GetAreaEnteredTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_areaEnteredTimestamp");
}
void GCCSBot::SetAreaEnteredTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_areaEnteredTimestamp", false, value);
}
GCountdownTimer GCCSBot::GetRepathTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_repathTimer"));
    return value;
}
void GCCSBot::SetRepathTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_repathTimer", false, value);
}
GCountdownTimer GCCSBot::GetAvoidFriendTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_avoidFriendTimer"));
    return value;
}
void GCCSBot::SetAvoidFriendTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_avoidFriendTimer", false, value);
}
bool GCCSBot::GetIsFriendInTheWay() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isFriendInTheWay");
}
void GCCSBot::SetIsFriendInTheWay(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isFriendInTheWay", false, value);
}
GCountdownTimer GCCSBot::GetPoliteTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_politeTimer"));
    return value;
}
void GCCSBot::SetPoliteTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_politeTimer", false, value);
}
bool GCCSBot::GetIsWaitingBehindFriend() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isWaitingBehindFriend");
}
void GCCSBot::SetIsWaitingBehindFriend(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isWaitingBehindFriend", false, value);
}
float GCCSBot::GetPathLadderEnd() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_pathLadderEnd");
}
void GCCSBot::SetPathLadderEnd(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_pathLadderEnd", false, value);
}
GCountdownTimer GCCSBot::GetMustRunTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_mustRunTimer"));
    return value;
}
void GCCSBot::SetMustRunTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_mustRunTimer", false, value);
}
GCountdownTimer GCCSBot::GetWaitTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_waitTimer"));
    return value;
}
void GCCSBot::SetWaitTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_waitTimer", false, value);
}
GCountdownTimer GCCSBot::GetUpdateTravelDistanceTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_updateTravelDistanceTimer"));
    return value;
}
void GCCSBot::SetUpdateTravelDistanceTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_updateTravelDistanceTimer", false, value);
}
std::vector<float> GCCSBot::GetPlayerTravelDistance() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSBot", "m_playerTravelDistance"); std::vector<float> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSBot::SetPlayerTravelDistance(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSBot", "m_playerTravelDistance"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSBot", "m_playerTravelDistance", false, outValue);
}
uint8_t GCCSBot::GetTravelDistancePhase() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_travelDistancePhase");
}
void GCCSBot::SetTravelDistancePhase(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_travelDistancePhase", false, value);
}
uint8_t GCCSBot::GetHostageEscortCount() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_hostageEscortCount");
}
void GCCSBot::SetHostageEscortCount(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_hostageEscortCount", false, value);
}
float GCCSBot::GetHostageEscortCountTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_hostageEscortCountTimestamp");
}
void GCCSBot::SetHostageEscortCountTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_hostageEscortCountTimestamp", false, value);
}
int32_t GCCSBot::GetDesiredTeam() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_desiredTeam");
}
void GCCSBot::SetDesiredTeam(int32_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_desiredTeam", false, value);
}
bool GCCSBot::GetHasJoined() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_hasJoined");
}
void GCCSBot::SetHasJoined(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_hasJoined", false, value);
}
bool GCCSBot::GetIsWaitingForHostage() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isWaitingForHostage");
}
void GCCSBot::SetIsWaitingForHostage(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isWaitingForHostage", false, value);
}
GCountdownTimer GCCSBot::GetInhibitWaitingForHostageTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_inhibitWaitingForHostageTimer"));
    return value;
}
void GCCSBot::SetInhibitWaitingForHostageTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_inhibitWaitingForHostageTimer", false, value);
}
GCountdownTimer GCCSBot::GetWaitForHostageTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_waitForHostageTimer"));
    return value;
}
void GCCSBot::SetWaitForHostageTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_waitForHostageTimer", false, value);
}
Vector GCCSBot::GetNoisePosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_noisePosition");
}
void GCCSBot::SetNoisePosition(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_noisePosition", false, value);
}
float GCCSBot::GetNoiseTravelDistance() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_noiseTravelDistance");
}
void GCCSBot::SetNoiseTravelDistance(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_noiseTravelDistance", false, value);
}
float GCCSBot::GetNoiseTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_noiseTimestamp");
}
void GCCSBot::SetNoiseTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_noiseTimestamp", false, value);
}
GCCSPlayerPawn GCCSBot::GetNoiseSource() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CCSBot", "m_noiseSource"));
    return value;
}
void GCCSBot::SetNoiseSource(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'NoiseSource' is not possible.\n");
}
GCountdownTimer GCCSBot::GetNoiseBendTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_noiseBendTimer"));
    return value;
}
void GCCSBot::SetNoiseBendTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_noiseBendTimer", false, value);
}
Vector GCCSBot::GetBentNoisePosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_bentNoisePosition");
}
void GCCSBot::SetBentNoisePosition(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_bentNoisePosition", false, value);
}
bool GCCSBot::GetBendNoisePositionValid() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_bendNoisePositionValid");
}
void GCCSBot::SetBendNoisePositionValid(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_bendNoisePositionValid", false, value);
}
float GCCSBot::GetLookAroundStateTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookAroundStateTimestamp");
}
void GCCSBot::SetLookAroundStateTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookAroundStateTimestamp", false, value);
}
float GCCSBot::GetLookAheadAngle() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookAheadAngle");
}
void GCCSBot::SetLookAheadAngle(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookAheadAngle", false, value);
}
float GCCSBot::GetForwardAngle() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_forwardAngle");
}
void GCCSBot::SetForwardAngle(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_forwardAngle", false, value);
}
float GCCSBot::GetInhibitLookAroundTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_inhibitLookAroundTimestamp");
}
void GCCSBot::SetInhibitLookAroundTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_inhibitLookAroundTimestamp", false, value);
}
Vector GCCSBot::GetLookAtSpot() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_lookAtSpot");
}
void GCCSBot::SetLookAtSpot(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpot", false, value);
}
float GCCSBot::GetLookAtSpotDuration() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookAtSpotDuration");
}
void GCCSBot::SetLookAtSpotDuration(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpotDuration", false, value);
}
float GCCSBot::GetLookAtSpotTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookAtSpotTimestamp");
}
void GCCSBot::SetLookAtSpotTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpotTimestamp", false, value);
}
float GCCSBot::GetLookAtSpotAngleTolerance() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookAtSpotAngleTolerance");
}
void GCCSBot::SetLookAtSpotAngleTolerance(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpotAngleTolerance", false, value);
}
bool GCCSBot::GetLookAtSpotClearIfClose() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_lookAtSpotClearIfClose");
}
void GCCSBot::SetLookAtSpotClearIfClose(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpotClearIfClose", false, value);
}
bool GCCSBot::GetLookAtSpotAttack() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_lookAtSpotAttack");
}
void GCCSBot::SetLookAtSpotAttack(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookAtSpotAttack", false, value);
}
std::string GCCSBot::GetLookAtDesc() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSBot", "m_lookAtDesc");
}
void GCCSBot::SetLookAtDesc(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSBot", "m_lookAtDesc", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
float GCCSBot::GetPeripheralTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_peripheralTimestamp");
}
void GCCSBot::SetPeripheralTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_peripheralTimestamp", false, value);
}
uint8_t GCCSBot::GetApproachPointCount() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_approachPointCount");
}
void GCCSBot::SetApproachPointCount(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_approachPointCount", false, value);
}
Vector GCCSBot::GetApproachPointViewPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_approachPointViewPosition");
}
void GCCSBot::SetApproachPointViewPosition(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_approachPointViewPosition", false, value);
}
GIntervalTimer GCCSBot::GetViewSteadyTimer() const {
    GIntervalTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_viewSteadyTimer"));
    return value;
}
void GCCSBot::SetViewSteadyTimer(GIntervalTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_viewSteadyTimer", false, value);
}
GCountdownTimer GCCSBot::GetTossGrenadeTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_tossGrenadeTimer"));
    return value;
}
void GCCSBot::SetTossGrenadeTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_tossGrenadeTimer", false, value);
}
GCountdownTimer GCCSBot::GetIsAvoidingGrenade() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_isAvoidingGrenade"));
    return value;
}
void GCCSBot::SetIsAvoidingGrenade(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isAvoidingGrenade", false, value);
}
float GCCSBot::GetSpotCheckTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_spotCheckTimestamp");
}
void GCCSBot::SetSpotCheckTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_spotCheckTimestamp", false, value);
}
int32_t GCCSBot::GetCheckedHidingSpotCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_checkedHidingSpotCount");
}
void GCCSBot::SetCheckedHidingSpotCount(int32_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_checkedHidingSpotCount", false, value);
}
float GCCSBot::GetLookPitch() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookPitch");
}
void GCCSBot::SetLookPitch(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookPitch", false, value);
}
float GCCSBot::GetLookPitchVel() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookPitchVel");
}
void GCCSBot::SetLookPitchVel(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookPitchVel", false, value);
}
float GCCSBot::GetLookYaw() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookYaw");
}
void GCCSBot::SetLookYaw(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookYaw", false, value);
}
float GCCSBot::GetLookYawVel() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lookYawVel");
}
void GCCSBot::SetLookYawVel(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookYawVel", false, value);
}
Vector GCCSBot::GetTargetSpot() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_targetSpot");
}
void GCCSBot::SetTargetSpot(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_targetSpot", false, value);
}
Vector GCCSBot::GetTargetSpotVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_targetSpotVelocity");
}
void GCCSBot::SetTargetSpotVelocity(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_targetSpotVelocity", false, value);
}
Vector GCCSBot::GetTargetSpotPredicted() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_targetSpotPredicted");
}
void GCCSBot::SetTargetSpotPredicted(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_targetSpotPredicted", false, value);
}
QAngle GCCSBot::GetAimError() const {
    return GetSchemaValue<QAngle>(m_ptr, "CCSBot", "m_aimError");
}
void GCCSBot::SetAimError(QAngle value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_aimError", false, value);
}
QAngle GCCSBot::GetAimGoal() const {
    return GetSchemaValue<QAngle>(m_ptr, "CCSBot", "m_aimGoal");
}
void GCCSBot::SetAimGoal(QAngle value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_aimGoal", false, value);
}
float GCCSBot::GetTargetSpotTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_targetSpotTime");
}
void GCCSBot::SetTargetSpotTime(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_targetSpotTime", false, value);
}
float GCCSBot::GetAimFocus() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_aimFocus");
}
void GCCSBot::SetAimFocus(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_aimFocus", false, value);
}
float GCCSBot::GetAimFocusInterval() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_aimFocusInterval");
}
void GCCSBot::SetAimFocusInterval(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_aimFocusInterval", false, value);
}
float GCCSBot::GetAimFocusNextUpdate() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_aimFocusNextUpdate");
}
void GCCSBot::SetAimFocusNextUpdate(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_aimFocusNextUpdate", false, value);
}
GCountdownTimer GCCSBot::GetIgnoreEnemiesTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_ignoreEnemiesTimer"));
    return value;
}
void GCCSBot::SetIgnoreEnemiesTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_ignoreEnemiesTimer", false, value);
}
GCCSPlayerPawn GCCSBot::GetEnemy() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CCSBot", "m_enemy"));
    return value;
}
void GCCSBot::SetEnemy(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Enemy' is not possible.\n");
}
bool GCCSBot::GetIsEnemyVisible() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isEnemyVisible");
}
void GCCSBot::SetIsEnemyVisible(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isEnemyVisible", false, value);
}
uint8_t GCCSBot::GetVisibleEnemyParts() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_visibleEnemyParts");
}
void GCCSBot::SetVisibleEnemyParts(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_visibleEnemyParts", false, value);
}
Vector GCCSBot::GetLastEnemyPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_lastEnemyPosition");
}
void GCCSBot::SetLastEnemyPosition(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lastEnemyPosition", false, value);
}
float GCCSBot::GetLastSawEnemyTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lastSawEnemyTimestamp");
}
void GCCSBot::SetLastSawEnemyTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lastSawEnemyTimestamp", false, value);
}
float GCCSBot::GetFirstSawEnemyTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_firstSawEnemyTimestamp");
}
void GCCSBot::SetFirstSawEnemyTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_firstSawEnemyTimestamp", false, value);
}
float GCCSBot::GetCurrentEnemyAcquireTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_currentEnemyAcquireTimestamp");
}
void GCCSBot::SetCurrentEnemyAcquireTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_currentEnemyAcquireTimestamp", false, value);
}
float GCCSBot::GetEnemyDeathTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_enemyDeathTimestamp");
}
void GCCSBot::SetEnemyDeathTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_enemyDeathTimestamp", false, value);
}
float GCCSBot::GetFriendDeathTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_friendDeathTimestamp");
}
void GCCSBot::SetFriendDeathTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_friendDeathTimestamp", false, value);
}
bool GCCSBot::GetIsLastEnemyDead() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isLastEnemyDead");
}
void GCCSBot::SetIsLastEnemyDead(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isLastEnemyDead", false, value);
}
int32_t GCCSBot::GetNearbyEnemyCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_nearbyEnemyCount");
}
void GCCSBot::SetNearbyEnemyCount(int32_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_nearbyEnemyCount", false, value);
}
GCCSPlayerPawn GCCSBot::GetBomber() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CCSBot", "m_bomber"));
    return value;
}
void GCCSBot::SetBomber(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Bomber' is not possible.\n");
}
int32_t GCCSBot::GetNearbyFriendCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_nearbyFriendCount");
}
void GCCSBot::SetNearbyFriendCount(int32_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_nearbyFriendCount", false, value);
}
GCCSPlayerPawn GCCSBot::GetClosestVisibleFriend() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CCSBot", "m_closestVisibleFriend"));
    return value;
}
void GCCSBot::SetClosestVisibleFriend(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ClosestVisibleFriend' is not possible.\n");
}
GCCSPlayerPawn GCCSBot::GetClosestVisibleHumanFriend() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CCSBot", "m_closestVisibleHumanFriend"));
    return value;
}
void GCCSBot::SetClosestVisibleHumanFriend(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ClosestVisibleHumanFriend' is not possible.\n");
}
GIntervalTimer GCCSBot::GetAttentionInterval() const {
    GIntervalTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_attentionInterval"));
    return value;
}
void GCCSBot::SetAttentionInterval(GIntervalTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_attentionInterval", false, value);
}
GCCSPlayerPawn GCCSBot::GetAttacker() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CCSBot", "m_attacker"));
    return value;
}
void GCCSBot::SetAttacker(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Attacker' is not possible.\n");
}
float GCCSBot::GetAttackedTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_attackedTimestamp");
}
void GCCSBot::SetAttackedTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_attackedTimestamp", false, value);
}
GIntervalTimer GCCSBot::GetBurnedByFlamesTimer() const {
    GIntervalTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_burnedByFlamesTimer"));
    return value;
}
void GCCSBot::SetBurnedByFlamesTimer(GIntervalTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_burnedByFlamesTimer", false, value);
}
int32_t GCCSBot::GetLastVictimID() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_lastVictimID");
}
void GCCSBot::SetLastVictimID(int32_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lastVictimID", false, value);
}
bool GCCSBot::GetIsAimingAtEnemy() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isAimingAtEnemy");
}
void GCCSBot::SetIsAimingAtEnemy(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isAimingAtEnemy", false, value);
}
bool GCCSBot::GetIsRapidFiring() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isRapidFiring");
}
void GCCSBot::SetIsRapidFiring(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isRapidFiring", false, value);
}
GIntervalTimer GCCSBot::GetEquipTimer() const {
    GIntervalTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_equipTimer"));
    return value;
}
void GCCSBot::SetEquipTimer(GIntervalTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_equipTimer", false, value);
}
GCountdownTimer GCCSBot::GetZoomTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_zoomTimer"));
    return value;
}
void GCCSBot::SetZoomTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_zoomTimer", false, value);
}
float GCCSBot::GetFireWeaponTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_fireWeaponTimestamp");
}
void GCCSBot::SetFireWeaponTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_fireWeaponTimestamp", false, value);
}
GCountdownTimer GCCSBot::GetLookForWeaponsOnGroundTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_lookForWeaponsOnGroundTimer"));
    return value;
}
void GCCSBot::SetLookForWeaponsOnGroundTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lookForWeaponsOnGroundTimer", false, value);
}
bool GCCSBot::GetIsSleeping() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_bIsSleeping");
}
void GCCSBot::SetIsSleeping(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_bIsSleeping", false, value);
}
bool GCCSBot::GetIsEnemySniperVisible() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isEnemySniperVisible");
}
void GCCSBot::SetIsEnemySniperVisible(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isEnemySniperVisible", false, value);
}
GCountdownTimer GCCSBot::GetSawEnemySniperTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_sawEnemySniperTimer"));
    return value;
}
void GCCSBot::SetSawEnemySniperTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_sawEnemySniperTimer", false, value);
}
uint8_t GCCSBot::GetEnemyQueueIndex() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_enemyQueueIndex");
}
void GCCSBot::SetEnemyQueueIndex(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_enemyQueueIndex", false, value);
}
uint8_t GCCSBot::GetEnemyQueueCount() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_enemyQueueCount");
}
void GCCSBot::SetEnemyQueueCount(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_enemyQueueCount", false, value);
}
uint8_t GCCSBot::GetEnemyQueueAttendIndex() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSBot", "m_enemyQueueAttendIndex");
}
void GCCSBot::SetEnemyQueueAttendIndex(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_enemyQueueAttendIndex", false, value);
}
bool GCCSBot::GetIsStuck() const {
    return GetSchemaValue<bool>(m_ptr, "CCSBot", "m_isStuck");
}
void GCCSBot::SetIsStuck(bool value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_isStuck", false, value);
}
float GCCSBot::GetStuckTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_stuckTimestamp");
}
void GCCSBot::SetStuckTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_stuckTimestamp", false, value);
}
Vector GCCSBot::GetStuckSpot() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_stuckSpot");
}
void GCCSBot::SetStuckSpot(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_stuckSpot", false, value);
}
GCountdownTimer GCCSBot::GetWiggleTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_wiggleTimer"));
    return value;
}
void GCCSBot::SetWiggleTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_wiggleTimer", false, value);
}
GCountdownTimer GCCSBot::GetStuckJumpTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CCSBot", "m_stuckJumpTimer"));
    return value;
}
void GCCSBot::SetStuckJumpTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_stuckJumpTimer", false, value);
}
float GCCSBot::GetNextCleanupCheckTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_nextCleanupCheckTimestamp");
}
void GCCSBot::SetNextCleanupCheckTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_nextCleanupCheckTimestamp", false, value);
}
std::vector<float> GCCSBot::GetAvgVel() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSBot", "m_avgVel"); std::vector<float> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSBot::SetAvgVel(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSBot", "m_avgVel"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSBot", "m_avgVel", false, outValue);
}
int32_t GCCSBot::GetAvgVelIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_avgVelIndex");
}
void GCCSBot::SetAvgVelIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_avgVelIndex", false, value);
}
int32_t GCCSBot::GetAvgVelCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_avgVelCount");
}
void GCCSBot::SetAvgVelCount(int32_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_avgVelCount", false, value);
}
Vector GCCSBot::GetLastOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_lastOrigin");
}
void GCCSBot::SetLastOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lastOrigin", false, value);
}
float GCCSBot::GetLastRadioRecievedTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lastRadioRecievedTimestamp");
}
void GCCSBot::SetLastRadioRecievedTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lastRadioRecievedTimestamp", false, value);
}
float GCCSBot::GetLastRadioSentTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_lastRadioSentTimestamp");
}
void GCCSBot::SetLastRadioSentTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lastRadioSentTimestamp", false, value);
}
GCCSPlayerPawn GCCSBot::GetRadioSubject() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CCSBot", "m_radioSubject"));
    return value;
}
void GCCSBot::SetRadioSubject(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'RadioSubject' is not possible.\n");
}
Vector GCCSBot::GetRadioPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSBot", "m_radioPosition");
}
void GCCSBot::SetRadioPosition(Vector value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_radioPosition", false, value);
}
float GCCSBot::GetVoiceEndTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSBot", "m_voiceEndTimestamp");
}
void GCCSBot::SetVoiceEndTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_voiceEndTimestamp", false, value);
}
int32_t GCCSBot::GetLastValidReactionQueueFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSBot", "m_lastValidReactionQueueFrame");
}
void GCCSBot::SetLastValidReactionQueueFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CCSBot", "m_lastValidReactionQueueFrame", false, value);
}
std::string GCCSBot::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSBot::IsValid() {
    return (m_ptr != nullptr);
}
GCBot GCCSBot::GetParent() const {
    GCBot value(m_ptr);
    return value;
}
void GCCSBot::SetParent(GCBot value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSBot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSBot>("CCSBot")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EyePosition", &GCCSBot::GetEyePosition, &GCCSBot::SetEyePosition)
        .addProperty("Name", &GCCSBot::GetName, &GCCSBot::SetName)
        .addProperty("CombatRange", &GCCSBot::GetCombatRange, &GCCSBot::SetCombatRange)
        .addProperty("IsRogue", &GCCSBot::GetIsRogue, &GCCSBot::SetIsRogue)
        .addProperty("RogueTimer", &GCCSBot::GetRogueTimer, &GCCSBot::SetRogueTimer)
        .addProperty("DiedLastRound", &GCCSBot::GetDiedLastRound, &GCCSBot::SetDiedLastRound)
        .addProperty("SafeTime", &GCCSBot::GetSafeTime, &GCCSBot::SetSafeTime)
        .addProperty("WasSafe", &GCCSBot::GetWasSafe, &GCCSBot::SetWasSafe)
        .addProperty("BlindFire", &GCCSBot::GetBlindFire, &GCCSBot::SetBlindFire)
        .addProperty("SurpriseTimer", &GCCSBot::GetSurpriseTimer, &GCCSBot::SetSurpriseTimer)
        .addProperty("AllowActive", &GCCSBot::GetAllowActive, &GCCSBot::SetAllowActive)
        .addProperty("IsFollowing", &GCCSBot::GetIsFollowing, &GCCSBot::SetIsFollowing)
        .addProperty("Leader", &GCCSBot::GetLeader, &GCCSBot::SetLeader)
        .addProperty("FollowTimestamp", &GCCSBot::GetFollowTimestamp, &GCCSBot::SetFollowTimestamp)
        .addProperty("AllowAutoFollowTime", &GCCSBot::GetAllowAutoFollowTime, &GCCSBot::SetAllowAutoFollowTime)
        .addProperty("HurryTimer", &GCCSBot::GetHurryTimer, &GCCSBot::SetHurryTimer)
        .addProperty("AlertTimer", &GCCSBot::GetAlertTimer, &GCCSBot::SetAlertTimer)
        .addProperty("SneakTimer", &GCCSBot::GetSneakTimer, &GCCSBot::SetSneakTimer)
        .addProperty("PanicTimer", &GCCSBot::GetPanicTimer, &GCCSBot::SetPanicTimer)
        .addProperty("StateTimestamp", &GCCSBot::GetStateTimestamp, &GCCSBot::SetStateTimestamp)
        .addProperty("IsAttacking", &GCCSBot::GetIsAttacking, &GCCSBot::SetIsAttacking)
        .addProperty("IsOpeningDoor", &GCCSBot::GetIsOpeningDoor, &GCCSBot::SetIsOpeningDoor)
        .addProperty("TaskEntity", &GCCSBot::GetTaskEntity, &GCCSBot::SetTaskEntity)
        .addProperty("GoalPosition", &GCCSBot::GetGoalPosition, &GCCSBot::SetGoalPosition)
        .addProperty("GoalEntity", &GCCSBot::GetGoalEntity, &GCCSBot::SetGoalEntity)
        .addProperty("Avoid", &GCCSBot::GetAvoid, &GCCSBot::SetAvoid)
        .addProperty("AvoidTimestamp", &GCCSBot::GetAvoidTimestamp, &GCCSBot::SetAvoidTimestamp)
        .addProperty("IsStopping", &GCCSBot::GetIsStopping, &GCCSBot::SetIsStopping)
        .addProperty("HasVisitedEnemySpawn", &GCCSBot::GetHasVisitedEnemySpawn, &GCCSBot::SetHasVisitedEnemySpawn)
        .addProperty("StillTimer", &GCCSBot::GetStillTimer, &GCCSBot::SetStillTimer)
        .addProperty("EyeAnglesUnderPathFinderControl", &GCCSBot::GetEyeAnglesUnderPathFinderControl, &GCCSBot::SetEyeAnglesUnderPathFinderControl)
        .addProperty("PathIndex", &GCCSBot::GetPathIndex, &GCCSBot::SetPathIndex)
        .addProperty("AreaEnteredTimestamp", &GCCSBot::GetAreaEnteredTimestamp, &GCCSBot::SetAreaEnteredTimestamp)
        .addProperty("RepathTimer", &GCCSBot::GetRepathTimer, &GCCSBot::SetRepathTimer)
        .addProperty("AvoidFriendTimer", &GCCSBot::GetAvoidFriendTimer, &GCCSBot::SetAvoidFriendTimer)
        .addProperty("IsFriendInTheWay", &GCCSBot::GetIsFriendInTheWay, &GCCSBot::SetIsFriendInTheWay)
        .addProperty("PoliteTimer", &GCCSBot::GetPoliteTimer, &GCCSBot::SetPoliteTimer)
        .addProperty("IsWaitingBehindFriend", &GCCSBot::GetIsWaitingBehindFriend, &GCCSBot::SetIsWaitingBehindFriend)
        .addProperty("PathLadderEnd", &GCCSBot::GetPathLadderEnd, &GCCSBot::SetPathLadderEnd)
        .addProperty("MustRunTimer", &GCCSBot::GetMustRunTimer, &GCCSBot::SetMustRunTimer)
        .addProperty("WaitTimer", &GCCSBot::GetWaitTimer, &GCCSBot::SetWaitTimer)
        .addProperty("UpdateTravelDistanceTimer", &GCCSBot::GetUpdateTravelDistanceTimer, &GCCSBot::SetUpdateTravelDistanceTimer)
        .addProperty("PlayerTravelDistance", &GCCSBot::GetPlayerTravelDistance, &GCCSBot::SetPlayerTravelDistance)
        .addProperty("TravelDistancePhase", &GCCSBot::GetTravelDistancePhase, &GCCSBot::SetTravelDistancePhase)
        .addProperty("HostageEscortCount", &GCCSBot::GetHostageEscortCount, &GCCSBot::SetHostageEscortCount)
        .addProperty("HostageEscortCountTimestamp", &GCCSBot::GetHostageEscortCountTimestamp, &GCCSBot::SetHostageEscortCountTimestamp)
        .addProperty("DesiredTeam", &GCCSBot::GetDesiredTeam, &GCCSBot::SetDesiredTeam)
        .addProperty("HasJoined", &GCCSBot::GetHasJoined, &GCCSBot::SetHasJoined)
        .addProperty("IsWaitingForHostage", &GCCSBot::GetIsWaitingForHostage, &GCCSBot::SetIsWaitingForHostage)
        .addProperty("InhibitWaitingForHostageTimer", &GCCSBot::GetInhibitWaitingForHostageTimer, &GCCSBot::SetInhibitWaitingForHostageTimer)
        .addProperty("WaitForHostageTimer", &GCCSBot::GetWaitForHostageTimer, &GCCSBot::SetWaitForHostageTimer)
        .addProperty("NoisePosition", &GCCSBot::GetNoisePosition, &GCCSBot::SetNoisePosition)
        .addProperty("NoiseTravelDistance", &GCCSBot::GetNoiseTravelDistance, &GCCSBot::SetNoiseTravelDistance)
        .addProperty("NoiseTimestamp", &GCCSBot::GetNoiseTimestamp, &GCCSBot::SetNoiseTimestamp)
        .addProperty("NoiseSource", &GCCSBot::GetNoiseSource, &GCCSBot::SetNoiseSource)
        .addProperty("NoiseBendTimer", &GCCSBot::GetNoiseBendTimer, &GCCSBot::SetNoiseBendTimer)
        .addProperty("BentNoisePosition", &GCCSBot::GetBentNoisePosition, &GCCSBot::SetBentNoisePosition)
        .addProperty("BendNoisePositionValid", &GCCSBot::GetBendNoisePositionValid, &GCCSBot::SetBendNoisePositionValid)
        .addProperty("LookAroundStateTimestamp", &GCCSBot::GetLookAroundStateTimestamp, &GCCSBot::SetLookAroundStateTimestamp)
        .addProperty("LookAheadAngle", &GCCSBot::GetLookAheadAngle, &GCCSBot::SetLookAheadAngle)
        .addProperty("ForwardAngle", &GCCSBot::GetForwardAngle, &GCCSBot::SetForwardAngle)
        .addProperty("InhibitLookAroundTimestamp", &GCCSBot::GetInhibitLookAroundTimestamp, &GCCSBot::SetInhibitLookAroundTimestamp)
        .addProperty("LookAtSpot", &GCCSBot::GetLookAtSpot, &GCCSBot::SetLookAtSpot)
        .addProperty("LookAtSpotDuration", &GCCSBot::GetLookAtSpotDuration, &GCCSBot::SetLookAtSpotDuration)
        .addProperty("LookAtSpotTimestamp", &GCCSBot::GetLookAtSpotTimestamp, &GCCSBot::SetLookAtSpotTimestamp)
        .addProperty("LookAtSpotAngleTolerance", &GCCSBot::GetLookAtSpotAngleTolerance, &GCCSBot::SetLookAtSpotAngleTolerance)
        .addProperty("LookAtSpotClearIfClose", &GCCSBot::GetLookAtSpotClearIfClose, &GCCSBot::SetLookAtSpotClearIfClose)
        .addProperty("LookAtSpotAttack", &GCCSBot::GetLookAtSpotAttack, &GCCSBot::SetLookAtSpotAttack)
        .addProperty("LookAtDesc", &GCCSBot::GetLookAtDesc, &GCCSBot::SetLookAtDesc)
        .addProperty("PeripheralTimestamp", &GCCSBot::GetPeripheralTimestamp, &GCCSBot::SetPeripheralTimestamp)
        .addProperty("ApproachPointCount", &GCCSBot::GetApproachPointCount, &GCCSBot::SetApproachPointCount)
        .addProperty("ApproachPointViewPosition", &GCCSBot::GetApproachPointViewPosition, &GCCSBot::SetApproachPointViewPosition)
        .addProperty("ViewSteadyTimer", &GCCSBot::GetViewSteadyTimer, &GCCSBot::SetViewSteadyTimer)
        .addProperty("TossGrenadeTimer", &GCCSBot::GetTossGrenadeTimer, &GCCSBot::SetTossGrenadeTimer)
        .addProperty("IsAvoidingGrenade", &GCCSBot::GetIsAvoidingGrenade, &GCCSBot::SetIsAvoidingGrenade)
        .addProperty("SpotCheckTimestamp", &GCCSBot::GetSpotCheckTimestamp, &GCCSBot::SetSpotCheckTimestamp)
        .addProperty("CheckedHidingSpotCount", &GCCSBot::GetCheckedHidingSpotCount, &GCCSBot::SetCheckedHidingSpotCount)
        .addProperty("LookPitch", &GCCSBot::GetLookPitch, &GCCSBot::SetLookPitch)
        .addProperty("LookPitchVel", &GCCSBot::GetLookPitchVel, &GCCSBot::SetLookPitchVel)
        .addProperty("LookYaw", &GCCSBot::GetLookYaw, &GCCSBot::SetLookYaw)
        .addProperty("LookYawVel", &GCCSBot::GetLookYawVel, &GCCSBot::SetLookYawVel)
        .addProperty("TargetSpot", &GCCSBot::GetTargetSpot, &GCCSBot::SetTargetSpot)
        .addProperty("TargetSpotVelocity", &GCCSBot::GetTargetSpotVelocity, &GCCSBot::SetTargetSpotVelocity)
        .addProperty("TargetSpotPredicted", &GCCSBot::GetTargetSpotPredicted, &GCCSBot::SetTargetSpotPredicted)
        .addProperty("AimError", &GCCSBot::GetAimError, &GCCSBot::SetAimError)
        .addProperty("AimGoal", &GCCSBot::GetAimGoal, &GCCSBot::SetAimGoal)
        .addProperty("TargetSpotTime", &GCCSBot::GetTargetSpotTime, &GCCSBot::SetTargetSpotTime)
        .addProperty("AimFocus", &GCCSBot::GetAimFocus, &GCCSBot::SetAimFocus)
        .addProperty("AimFocusInterval", &GCCSBot::GetAimFocusInterval, &GCCSBot::SetAimFocusInterval)
        .addProperty("AimFocusNextUpdate", &GCCSBot::GetAimFocusNextUpdate, &GCCSBot::SetAimFocusNextUpdate)
        .addProperty("IgnoreEnemiesTimer", &GCCSBot::GetIgnoreEnemiesTimer, &GCCSBot::SetIgnoreEnemiesTimer)
        .addProperty("Enemy", &GCCSBot::GetEnemy, &GCCSBot::SetEnemy)
        .addProperty("IsEnemyVisible", &GCCSBot::GetIsEnemyVisible, &GCCSBot::SetIsEnemyVisible)
        .addProperty("VisibleEnemyParts", &GCCSBot::GetVisibleEnemyParts, &GCCSBot::SetVisibleEnemyParts)
        .addProperty("LastEnemyPosition", &GCCSBot::GetLastEnemyPosition, &GCCSBot::SetLastEnemyPosition)
        .addProperty("LastSawEnemyTimestamp", &GCCSBot::GetLastSawEnemyTimestamp, &GCCSBot::SetLastSawEnemyTimestamp)
        .addProperty("FirstSawEnemyTimestamp", &GCCSBot::GetFirstSawEnemyTimestamp, &GCCSBot::SetFirstSawEnemyTimestamp)
        .addProperty("CurrentEnemyAcquireTimestamp", &GCCSBot::GetCurrentEnemyAcquireTimestamp, &GCCSBot::SetCurrentEnemyAcquireTimestamp)
        .addProperty("EnemyDeathTimestamp", &GCCSBot::GetEnemyDeathTimestamp, &GCCSBot::SetEnemyDeathTimestamp)
        .addProperty("FriendDeathTimestamp", &GCCSBot::GetFriendDeathTimestamp, &GCCSBot::SetFriendDeathTimestamp)
        .addProperty("IsLastEnemyDead", &GCCSBot::GetIsLastEnemyDead, &GCCSBot::SetIsLastEnemyDead)
        .addProperty("NearbyEnemyCount", &GCCSBot::GetNearbyEnemyCount, &GCCSBot::SetNearbyEnemyCount)
        .addProperty("Bomber", &GCCSBot::GetBomber, &GCCSBot::SetBomber)
        .addProperty("NearbyFriendCount", &GCCSBot::GetNearbyFriendCount, &GCCSBot::SetNearbyFriendCount)
        .addProperty("ClosestVisibleFriend", &GCCSBot::GetClosestVisibleFriend, &GCCSBot::SetClosestVisibleFriend)
        .addProperty("ClosestVisibleHumanFriend", &GCCSBot::GetClosestVisibleHumanFriend, &GCCSBot::SetClosestVisibleHumanFriend)
        .addProperty("AttentionInterval", &GCCSBot::GetAttentionInterval, &GCCSBot::SetAttentionInterval)
        .addProperty("Attacker", &GCCSBot::GetAttacker, &GCCSBot::SetAttacker)
        .addProperty("AttackedTimestamp", &GCCSBot::GetAttackedTimestamp, &GCCSBot::SetAttackedTimestamp)
        .addProperty("BurnedByFlamesTimer", &GCCSBot::GetBurnedByFlamesTimer, &GCCSBot::SetBurnedByFlamesTimer)
        .addProperty("LastVictimID", &GCCSBot::GetLastVictimID, &GCCSBot::SetLastVictimID)
        .addProperty("IsAimingAtEnemy", &GCCSBot::GetIsAimingAtEnemy, &GCCSBot::SetIsAimingAtEnemy)
        .addProperty("IsRapidFiring", &GCCSBot::GetIsRapidFiring, &GCCSBot::SetIsRapidFiring)
        .addProperty("EquipTimer", &GCCSBot::GetEquipTimer, &GCCSBot::SetEquipTimer)
        .addProperty("ZoomTimer", &GCCSBot::GetZoomTimer, &GCCSBot::SetZoomTimer)
        .addProperty("FireWeaponTimestamp", &GCCSBot::GetFireWeaponTimestamp, &GCCSBot::SetFireWeaponTimestamp)
        .addProperty("LookForWeaponsOnGroundTimer", &GCCSBot::GetLookForWeaponsOnGroundTimer, &GCCSBot::SetLookForWeaponsOnGroundTimer)
        .addProperty("IsSleeping", &GCCSBot::GetIsSleeping, &GCCSBot::SetIsSleeping)
        .addProperty("IsEnemySniperVisible", &GCCSBot::GetIsEnemySniperVisible, &GCCSBot::SetIsEnemySniperVisible)
        .addProperty("SawEnemySniperTimer", &GCCSBot::GetSawEnemySniperTimer, &GCCSBot::SetSawEnemySniperTimer)
        .addProperty("EnemyQueueIndex", &GCCSBot::GetEnemyQueueIndex, &GCCSBot::SetEnemyQueueIndex)
        .addProperty("EnemyQueueCount", &GCCSBot::GetEnemyQueueCount, &GCCSBot::SetEnemyQueueCount)
        .addProperty("EnemyQueueAttendIndex", &GCCSBot::GetEnemyQueueAttendIndex, &GCCSBot::SetEnemyQueueAttendIndex)
        .addProperty("IsStuck", &GCCSBot::GetIsStuck, &GCCSBot::SetIsStuck)
        .addProperty("StuckTimestamp", &GCCSBot::GetStuckTimestamp, &GCCSBot::SetStuckTimestamp)
        .addProperty("StuckSpot", &GCCSBot::GetStuckSpot, &GCCSBot::SetStuckSpot)
        .addProperty("WiggleTimer", &GCCSBot::GetWiggleTimer, &GCCSBot::SetWiggleTimer)
        .addProperty("StuckJumpTimer", &GCCSBot::GetStuckJumpTimer, &GCCSBot::SetStuckJumpTimer)
        .addProperty("NextCleanupCheckTimestamp", &GCCSBot::GetNextCleanupCheckTimestamp, &GCCSBot::SetNextCleanupCheckTimestamp)
        .addProperty("AvgVel", &GCCSBot::GetAvgVel, &GCCSBot::SetAvgVel)
        .addProperty("AvgVelIndex", &GCCSBot::GetAvgVelIndex, &GCCSBot::SetAvgVelIndex)
        .addProperty("AvgVelCount", &GCCSBot::GetAvgVelCount, &GCCSBot::SetAvgVelCount)
        .addProperty("LastOrigin", &GCCSBot::GetLastOrigin, &GCCSBot::SetLastOrigin)
        .addProperty("LastRadioRecievedTimestamp", &GCCSBot::GetLastRadioRecievedTimestamp, &GCCSBot::SetLastRadioRecievedTimestamp)
        .addProperty("LastRadioSentTimestamp", &GCCSBot::GetLastRadioSentTimestamp, &GCCSBot::SetLastRadioSentTimestamp)
        .addProperty("RadioSubject", &GCCSBot::GetRadioSubject, &GCCSBot::SetRadioSubject)
        .addProperty("RadioPosition", &GCCSBot::GetRadioPosition, &GCCSBot::SetRadioPosition)
        .addProperty("VoiceEndTimestamp", &GCCSBot::GetVoiceEndTimestamp, &GCCSBot::SetVoiceEndTimestamp)
        .addProperty("LastValidReactionQueueFrame", &GCCSBot::GetLastValidReactionQueueFrame, &GCCSBot::SetLastValidReactionQueueFrame)
        .addProperty("Parent", &GCCSBot::GetParent, &GCCSBot::SetParent)
        .addFunction("ToPtr", &GCCSBot::ToPtr)
        .addFunction("IsValid", &GCCSBot::IsValid)
        .endClass();
}