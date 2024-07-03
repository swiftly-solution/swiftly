#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCChicken::GCChicken(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCChicken::GCChicken(void *ptr) {
    m_ptr = ptr;
}
GCAttributeContainer GCChicken::GetAttributeManager() const {
    GCAttributeContainer value(GetSchemaPtr(m_ptr, "CChicken", "m_AttributeManager"));
    return value;
}
void GCChicken::SetAttributeManager(GCAttributeContainer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_AttributeManager", false, value);
}
CUtlStringToken GCChicken::GetActivityFinishedTag() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "CChicken", "m_sActivityFinishedTag");
}
void GCChicken::SetActivityFinishedTag(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "CChicken", "m_sActivityFinishedTag", false, value);
}
GCountdownTimer GCChicken::GetUpdateTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_updateTimer"));
    return value;
}
void GCChicken::SetUpdateTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_updateTimer", false, value);
}
Vector GCChicken::GetStuckAnchor() const {
    return GetSchemaValue<Vector>(m_ptr, "CChicken", "m_stuckAnchor");
}
void GCChicken::SetStuckAnchor(Vector value) {
    SetSchemaValue(m_ptr, "CChicken", "m_stuckAnchor", false, value);
}
GCountdownTimer GCChicken::GetStuckTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_stuckTimer"));
    return value;
}
void GCChicken::SetStuckTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_stuckTimer", false, value);
}
GCountdownTimer GCChicken::GetCollisionStuckTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_collisionStuckTimer"));
    return value;
}
void GCChicken::SetCollisionStuckTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_collisionStuckTimer", false, value);
}
bool GCChicken::GetIsOnGround() const {
    return GetSchemaValue<bool>(m_ptr, "CChicken", "m_isOnGround");
}
void GCChicken::SetIsOnGround(bool value) {
    SetSchemaValue(m_ptr, "CChicken", "m_isOnGround", false, value);
}
Vector GCChicken::GetFallVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "CChicken", "m_vFallVelocity");
}
void GCChicken::SetFallVelocity(Vector value) {
    SetSchemaValue(m_ptr, "CChicken", "m_vFallVelocity", false, value);
}
uint64_t GCChicken::GetDesiredActivity() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CChicken", "m_desiredActivity");
}
void GCChicken::SetDesiredActivity(uint64_t value) {
    SetSchemaValue(m_ptr, "CChicken", "m_desiredActivity", false, value);
}
uint64_t GCChicken::GetCurrentActivity() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CChicken", "m_currentActivity");
}
void GCChicken::SetCurrentActivity(uint64_t value) {
    SetSchemaValue(m_ptr, "CChicken", "m_currentActivity", false, value);
}
GCountdownTimer GCChicken::GetActivityTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_activityTimer"));
    return value;
}
void GCChicken::SetActivityTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_activityTimer", false, value);
}
float GCChicken::GetTurnRate() const {
    return GetSchemaValue<float>(m_ptr, "CChicken", "m_turnRate");
}
void GCChicken::SetTurnRate(float value) {
    SetSchemaValue(m_ptr, "CChicken", "m_turnRate", false, value);
}
GCBaseEntity GCChicken::GetFleeFrom() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CChicken", "m_fleeFrom"));
    return value;
}
void GCChicken::SetFleeFrom(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'FleeFrom' is not possible.\n");
}
GCountdownTimer GCChicken::GetMoveRateThrottleTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_moveRateThrottleTimer"));
    return value;
}
void GCChicken::SetMoveRateThrottleTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_moveRateThrottleTimer", false, value);
}
GCountdownTimer GCChicken::GetStartleTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_startleTimer"));
    return value;
}
void GCChicken::SetStartleTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_startleTimer", false, value);
}
GCountdownTimer GCChicken::GetVocalizeTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_vocalizeTimer"));
    return value;
}
void GCChicken::SetVocalizeTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_vocalizeTimer", false, value);
}
float GCChicken::GetWhenZombified() const {
    return GetSchemaValue<float>(m_ptr, "CChicken", "m_flWhenZombified");
}
void GCChicken::SetWhenZombified(float value) {
    SetSchemaValue(m_ptr, "CChicken", "m_flWhenZombified", false, value);
}
bool GCChicken::GetJumpedThisFrame() const {
    return GetSchemaValue<bool>(m_ptr, "CChicken", "m_jumpedThisFrame");
}
void GCChicken::SetJumpedThisFrame(bool value) {
    SetSchemaValue(m_ptr, "CChicken", "m_jumpedThisFrame", false, value);
}
GCCSPlayerPawn GCChicken::GetLeader() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CChicken", "m_leader"));
    return value;
}
void GCChicken::SetLeader(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Leader' is not possible.\n");
}
GCountdownTimer GCChicken::GetReuseTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_reuseTimer"));
    return value;
}
void GCChicken::SetReuseTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_reuseTimer", false, value);
}
bool GCChicken::GetHasBeenUsed() const {
    return GetSchemaValue<bool>(m_ptr, "CChicken", "m_hasBeenUsed");
}
void GCChicken::SetHasBeenUsed(bool value) {
    SetSchemaValue(m_ptr, "CChicken", "m_hasBeenUsed", false, value);
}
GCountdownTimer GCChicken::GetJumpTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_jumpTimer"));
    return value;
}
void GCChicken::SetJumpTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_jumpTimer", false, value);
}
float GCChicken::GetLastJumpTime() const {
    return GetSchemaValue<float>(m_ptr, "CChicken", "m_flLastJumpTime");
}
void GCChicken::SetLastJumpTime(float value) {
    SetSchemaValue(m_ptr, "CChicken", "m_flLastJumpTime", false, value);
}
bool GCChicken::GetInJump() const {
    return GetSchemaValue<bool>(m_ptr, "CChicken", "m_bInJump");
}
void GCChicken::SetInJump(bool value) {
    SetSchemaValue(m_ptr, "CChicken", "m_bInJump", false, value);
}
bool GCChicken::GetIsWaitingForLeader() const {
    return GetSchemaValue<bool>(m_ptr, "CChicken", "m_isWaitingForLeader");
}
void GCChicken::SetIsWaitingForLeader(bool value) {
    SetSchemaValue(m_ptr, "CChicken", "m_isWaitingForLeader", false, value);
}
GCountdownTimer GCChicken::GetRepathTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_repathTimer"));
    return value;
}
void GCChicken::SetRepathTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_repathTimer", false, value);
}
GCountdownTimer GCChicken::GetInhibitDoorTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_inhibitDoorTimer"));
    return value;
}
void GCChicken::SetInhibitDoorTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_inhibitDoorTimer", false, value);
}
GCountdownTimer GCChicken::GetInhibitObstacleAvoidanceTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_inhibitObstacleAvoidanceTimer"));
    return value;
}
void GCChicken::SetInhibitObstacleAvoidanceTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_inhibitObstacleAvoidanceTimer", false, value);
}
Vector GCChicken::GetPathGoal() const {
    return GetSchemaValue<Vector>(m_ptr, "CChicken", "m_vecPathGoal");
}
void GCChicken::SetPathGoal(Vector value) {
    SetSchemaValue(m_ptr, "CChicken", "m_vecPathGoal", false, value);
}
float GCChicken::GetActiveFollowStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CChicken", "m_flActiveFollowStartTime");
}
void GCChicken::SetActiveFollowStartTime(float value) {
    SetSchemaValue(m_ptr, "CChicken", "m_flActiveFollowStartTime", false, value);
}
GCountdownTimer GCChicken::GetFollowMinuteTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_followMinuteTimer"));
    return value;
}
void GCChicken::SetFollowMinuteTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_followMinuteTimer", false, value);
}
Vector GCChicken::GetLastEggPoopPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CChicken", "m_vecLastEggPoopPosition");
}
void GCChicken::SetLastEggPoopPosition(Vector value) {
    SetSchemaValue(m_ptr, "CChicken", "m_vecLastEggPoopPosition", false, value);
}
GCountdownTimer GCChicken::GetBlockDirectionTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CChicken", "m_BlockDirectionTimer"));
    return value;
}
void GCChicken::SetBlockDirectionTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CChicken", "m_BlockDirectionTimer", false, value);
}
std::string GCChicken::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCChicken::IsValid() {
    return (m_ptr != nullptr);
}
GCDynamicProp GCChicken::GetParent() const {
    GCDynamicProp value(m_ptr);
    return value;
}
void GCChicken::SetParent(GCDynamicProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCChicken(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCChicken>("CChicken")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AttributeManager", &GCChicken::GetAttributeManager, &GCChicken::SetAttributeManager)
        .addProperty("ActivityFinishedTag", &GCChicken::GetActivityFinishedTag, &GCChicken::SetActivityFinishedTag)
        .addProperty("UpdateTimer", &GCChicken::GetUpdateTimer, &GCChicken::SetUpdateTimer)
        .addProperty("StuckAnchor", &GCChicken::GetStuckAnchor, &GCChicken::SetStuckAnchor)
        .addProperty("StuckTimer", &GCChicken::GetStuckTimer, &GCChicken::SetStuckTimer)
        .addProperty("CollisionStuckTimer", &GCChicken::GetCollisionStuckTimer, &GCChicken::SetCollisionStuckTimer)
        .addProperty("IsOnGround", &GCChicken::GetIsOnGround, &GCChicken::SetIsOnGround)
        .addProperty("FallVelocity", &GCChicken::GetFallVelocity, &GCChicken::SetFallVelocity)
        .addProperty("DesiredActivity", &GCChicken::GetDesiredActivity, &GCChicken::SetDesiredActivity)
        .addProperty("CurrentActivity", &GCChicken::GetCurrentActivity, &GCChicken::SetCurrentActivity)
        .addProperty("ActivityTimer", &GCChicken::GetActivityTimer, &GCChicken::SetActivityTimer)
        .addProperty("TurnRate", &GCChicken::GetTurnRate, &GCChicken::SetTurnRate)
        .addProperty("FleeFrom", &GCChicken::GetFleeFrom, &GCChicken::SetFleeFrom)
        .addProperty("MoveRateThrottleTimer", &GCChicken::GetMoveRateThrottleTimer, &GCChicken::SetMoveRateThrottleTimer)
        .addProperty("StartleTimer", &GCChicken::GetStartleTimer, &GCChicken::SetStartleTimer)
        .addProperty("VocalizeTimer", &GCChicken::GetVocalizeTimer, &GCChicken::SetVocalizeTimer)
        .addProperty("WhenZombified", &GCChicken::GetWhenZombified, &GCChicken::SetWhenZombified)
        .addProperty("JumpedThisFrame", &GCChicken::GetJumpedThisFrame, &GCChicken::SetJumpedThisFrame)
        .addProperty("Leader", &GCChicken::GetLeader, &GCChicken::SetLeader)
        .addProperty("ReuseTimer", &GCChicken::GetReuseTimer, &GCChicken::SetReuseTimer)
        .addProperty("HasBeenUsed", &GCChicken::GetHasBeenUsed, &GCChicken::SetHasBeenUsed)
        .addProperty("JumpTimer", &GCChicken::GetJumpTimer, &GCChicken::SetJumpTimer)
        .addProperty("LastJumpTime", &GCChicken::GetLastJumpTime, &GCChicken::SetLastJumpTime)
        .addProperty("InJump", &GCChicken::GetInJump, &GCChicken::SetInJump)
        .addProperty("IsWaitingForLeader", &GCChicken::GetIsWaitingForLeader, &GCChicken::SetIsWaitingForLeader)
        .addProperty("RepathTimer", &GCChicken::GetRepathTimer, &GCChicken::SetRepathTimer)
        .addProperty("InhibitDoorTimer", &GCChicken::GetInhibitDoorTimer, &GCChicken::SetInhibitDoorTimer)
        .addProperty("InhibitObstacleAvoidanceTimer", &GCChicken::GetInhibitObstacleAvoidanceTimer, &GCChicken::SetInhibitObstacleAvoidanceTimer)
        .addProperty("PathGoal", &GCChicken::GetPathGoal, &GCChicken::SetPathGoal)
        .addProperty("ActiveFollowStartTime", &GCChicken::GetActiveFollowStartTime, &GCChicken::SetActiveFollowStartTime)
        .addProperty("FollowMinuteTimer", &GCChicken::GetFollowMinuteTimer, &GCChicken::SetFollowMinuteTimer)
        .addProperty("LastEggPoopPosition", &GCChicken::GetLastEggPoopPosition, &GCChicken::SetLastEggPoopPosition)
        .addProperty("BlockDirectionTimer", &GCChicken::GetBlockDirectionTimer, &GCChicken::SetBlockDirectionTimer)
        .addProperty("Parent", &GCChicken::GetParent, &GCChicken::SetParent)
        .addFunction("ToPtr", &GCChicken::ToPtr)
        .addFunction("IsValid", &GCChicken::IsValid)
        .endClass();
}