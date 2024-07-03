#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHostage::GCHostage(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHostage::GCHostage(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCHostage::GetOnHostageBeginGrab() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CHostage", "m_OnHostageBeginGrab"));
    return value;
}
void GCHostage::SetOnHostageBeginGrab(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CHostage", "m_OnHostageBeginGrab", false, value);
}
GCEntityIOOutput GCHostage::GetOnFirstPickedUp() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CHostage", "m_OnFirstPickedUp"));
    return value;
}
void GCHostage::SetOnFirstPickedUp(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CHostage", "m_OnFirstPickedUp", false, value);
}
GCEntityIOOutput GCHostage::GetOnDroppedNotRescued() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CHostage", "m_OnDroppedNotRescued"));
    return value;
}
void GCHostage::SetOnDroppedNotRescued(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CHostage", "m_OnDroppedNotRescued", false, value);
}
GCEntityIOOutput GCHostage::GetOnRescued() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CHostage", "m_OnRescued"));
    return value;
}
void GCHostage::SetOnRescued(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CHostage", "m_OnRescued", false, value);
}
GEntitySpottedState_t GCHostage::GetEntitySpottedState() const {
    GEntitySpottedState_t value(GetSchemaPtr(m_ptr, "CHostage", "m_entitySpottedState"));
    return value;
}
void GCHostage::SetEntitySpottedState(GEntitySpottedState_t value) {
    SetSchemaValue(m_ptr, "CHostage", "m_entitySpottedState", false, value);
}
int32_t GCHostage::GetSpotRules() const {
    return GetSchemaValue<int32_t>(m_ptr, "CHostage", "m_nSpotRules");
}
void GCHostage::SetSpotRules(int32_t value) {
    SetSchemaValue(m_ptr, "CHostage", "m_nSpotRules", false, value);
}
uint32_t GCHostage::GetUiHostageSpawnExclusionGroupMask() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CHostage", "m_uiHostageSpawnExclusionGroupMask");
}
void GCHostage::SetUiHostageSpawnExclusionGroupMask(uint32_t value) {
    SetSchemaValue(m_ptr, "CHostage", "m_uiHostageSpawnExclusionGroupMask", false, value);
}
uint32_t GCHostage::GetHostageSpawnRandomFactor() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CHostage", "m_nHostageSpawnRandomFactor");
}
void GCHostage::SetHostageSpawnRandomFactor(uint32_t value) {
    SetSchemaValue(m_ptr, "CHostage", "m_nHostageSpawnRandomFactor", false, value);
}
bool GCHostage::GetRemove() const {
    return GetSchemaValue<bool>(m_ptr, "CHostage", "m_bRemove");
}
void GCHostage::SetRemove(bool value) {
    SetSchemaValue(m_ptr, "CHostage", "m_bRemove", false, value);
}
Vector GCHostage::GetVel() const {
    return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_vel");
}
void GCHostage::SetVel(Vector value) {
    SetSchemaValue(m_ptr, "CHostage", "m_vel", false, value);
}
bool GCHostage::GetIsRescued() const {
    return GetSchemaValue<bool>(m_ptr, "CHostage", "m_isRescued");
}
void GCHostage::SetIsRescued(bool value) {
    SetSchemaValue(m_ptr, "CHostage", "m_isRescued", false, value);
}
bool GCHostage::GetJumpedThisFrame() const {
    return GetSchemaValue<bool>(m_ptr, "CHostage", "m_jumpedThisFrame");
}
void GCHostage::SetJumpedThisFrame(bool value) {
    SetSchemaValue(m_ptr, "CHostage", "m_jumpedThisFrame", false, value);
}
int32_t GCHostage::GetHostageState() const {
    return GetSchemaValue<int32_t>(m_ptr, "CHostage", "m_nHostageState");
}
void GCHostage::SetHostageState(int32_t value) {
    SetSchemaValue(m_ptr, "CHostage", "m_nHostageState", false, value);
}
GCBaseEntity GCHostage::GetLeader() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CHostage", "m_leader"));
    return value;
}
void GCHostage::SetLeader(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Leader' is not possible.\n");
}
GCCSPlayerPawnBase GCHostage::GetLastLeader() const {
    GCCSPlayerPawnBase value(*GetSchemaValuePtr<void*>(m_ptr, "CHostage", "m_lastLeader"));
    return value;
}
void GCHostage::SetLastLeader(GCCSPlayerPawnBase* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastLeader' is not possible.\n");
}
GCountdownTimer GCHostage::GetReuseTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CHostage", "m_reuseTimer"));
    return value;
}
void GCHostage::SetReuseTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CHostage", "m_reuseTimer", false, value);
}
bool GCHostage::GetHasBeenUsed() const {
    return GetSchemaValue<bool>(m_ptr, "CHostage", "m_hasBeenUsed");
}
void GCHostage::SetHasBeenUsed(bool value) {
    SetSchemaValue(m_ptr, "CHostage", "m_hasBeenUsed", false, value);
}
Vector GCHostage::GetAccel() const {
    return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_accel");
}
void GCHostage::SetAccel(Vector value) {
    SetSchemaValue(m_ptr, "CHostage", "m_accel", false, value);
}
bool GCHostage::GetIsRunning() const {
    return GetSchemaValue<bool>(m_ptr, "CHostage", "m_isRunning");
}
void GCHostage::SetIsRunning(bool value) {
    SetSchemaValue(m_ptr, "CHostage", "m_isRunning", false, value);
}
bool GCHostage::GetIsCrouching() const {
    return GetSchemaValue<bool>(m_ptr, "CHostage", "m_isCrouching");
}
void GCHostage::SetIsCrouching(bool value) {
    SetSchemaValue(m_ptr, "CHostage", "m_isCrouching", false, value);
}
GCountdownTimer GCHostage::GetJumpTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CHostage", "m_jumpTimer"));
    return value;
}
void GCHostage::SetJumpTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CHostage", "m_jumpTimer", false, value);
}
bool GCHostage::GetIsWaitingForLeader() const {
    return GetSchemaValue<bool>(m_ptr, "CHostage", "m_isWaitingForLeader");
}
void GCHostage::SetIsWaitingForLeader(bool value) {
    SetSchemaValue(m_ptr, "CHostage", "m_isWaitingForLeader", false, value);
}
GCountdownTimer GCHostage::GetRepathTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CHostage", "m_repathTimer"));
    return value;
}
void GCHostage::SetRepathTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CHostage", "m_repathTimer", false, value);
}
GCountdownTimer GCHostage::GetInhibitDoorTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CHostage", "m_inhibitDoorTimer"));
    return value;
}
void GCHostage::SetInhibitDoorTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CHostage", "m_inhibitDoorTimer", false, value);
}
GCountdownTimer GCHostage::GetInhibitObstacleAvoidanceTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CHostage", "m_inhibitObstacleAvoidanceTimer"));
    return value;
}
void GCHostage::SetInhibitObstacleAvoidanceTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CHostage", "m_inhibitObstacleAvoidanceTimer", false, value);
}
GCountdownTimer GCHostage::GetWiggleTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CHostage", "m_wiggleTimer"));
    return value;
}
void GCHostage::SetWiggleTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CHostage", "m_wiggleTimer", false, value);
}
bool GCHostage::GetIsAdjusted() const {
    return GetSchemaValue<bool>(m_ptr, "CHostage", "m_isAdjusted");
}
void GCHostage::SetIsAdjusted(bool value) {
    SetSchemaValue(m_ptr, "CHostage", "m_isAdjusted", false, value);
}
bool GCHostage::GetHandsHaveBeenCut() const {
    return GetSchemaValue<bool>(m_ptr, "CHostage", "m_bHandsHaveBeenCut");
}
void GCHostage::SetHandsHaveBeenCut(bool value) {
    SetSchemaValue(m_ptr, "CHostage", "m_bHandsHaveBeenCut", false, value);
}
GCCSPlayerPawn GCHostage::GetHostageGrabber() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CHostage", "m_hHostageGrabber"));
    return value;
}
void GCHostage::SetHostageGrabber(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'HostageGrabber' is not possible.\n");
}
float GCHostage::GetLastGrabTime() const {
    return GetSchemaValue<float>(m_ptr, "CHostage", "m_fLastGrabTime");
}
void GCHostage::SetLastGrabTime(float value) {
    SetSchemaValue(m_ptr, "CHostage", "m_fLastGrabTime", false, value);
}
Vector GCHostage::GetPositionWhenStartedDroppingToGround() const {
    return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_vecPositionWhenStartedDroppingToGround");
}
void GCHostage::SetPositionWhenStartedDroppingToGround(Vector value) {
    SetSchemaValue(m_ptr, "CHostage", "m_vecPositionWhenStartedDroppingToGround", false, value);
}
Vector GCHostage::GetGrabbedPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_vecGrabbedPos");
}
void GCHostage::SetGrabbedPos(Vector value) {
    SetSchemaValue(m_ptr, "CHostage", "m_vecGrabbedPos", false, value);
}
float GCHostage::GetRescueStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CHostage", "m_flRescueStartTime");
}
void GCHostage::SetRescueStartTime(float value) {
    SetSchemaValue(m_ptr, "CHostage", "m_flRescueStartTime", false, value);
}
float GCHostage::GetGrabSuccessTime() const {
    return GetSchemaValue<float>(m_ptr, "CHostage", "m_flGrabSuccessTime");
}
void GCHostage::SetGrabSuccessTime(float value) {
    SetSchemaValue(m_ptr, "CHostage", "m_flGrabSuccessTime", false, value);
}
float GCHostage::GetDropStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CHostage", "m_flDropStartTime");
}
void GCHostage::SetDropStartTime(float value) {
    SetSchemaValue(m_ptr, "CHostage", "m_flDropStartTime", false, value);
}
int32_t GCHostage::GetApproachRewardPayouts() const {
    return GetSchemaValue<int32_t>(m_ptr, "CHostage", "m_nApproachRewardPayouts");
}
void GCHostage::SetApproachRewardPayouts(int32_t value) {
    SetSchemaValue(m_ptr, "CHostage", "m_nApproachRewardPayouts", false, value);
}
int32_t GCHostage::GetPickupEventCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CHostage", "m_nPickupEventCount");
}
void GCHostage::SetPickupEventCount(int32_t value) {
    SetSchemaValue(m_ptr, "CHostage", "m_nPickupEventCount", false, value);
}
Vector GCHostage::GetSpawnGroundPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_vecSpawnGroundPos");
}
void GCHostage::SetSpawnGroundPos(Vector value) {
    SetSchemaValue(m_ptr, "CHostage", "m_vecSpawnGroundPos", false, value);
}
Vector GCHostage::GetHostageResetPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CHostage", "m_vecHostageResetPosition");
}
void GCHostage::SetHostageResetPosition(Vector value) {
    SetSchemaValue(m_ptr, "CHostage", "m_vecHostageResetPosition", false, value);
}
std::string GCHostage::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHostage::IsValid() {
    return (m_ptr != nullptr);
}
GCHostageExpresserShim GCHostage::GetParent() const {
    GCHostageExpresserShim value(m_ptr);
    return value;
}
void GCHostage::SetParent(GCHostageExpresserShim value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHostage(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostage>("CHostage")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnHostageBeginGrab", &GCHostage::GetOnHostageBeginGrab, &GCHostage::SetOnHostageBeginGrab)
        .addProperty("OnFirstPickedUp", &GCHostage::GetOnFirstPickedUp, &GCHostage::SetOnFirstPickedUp)
        .addProperty("OnDroppedNotRescued", &GCHostage::GetOnDroppedNotRescued, &GCHostage::SetOnDroppedNotRescued)
        .addProperty("OnRescued", &GCHostage::GetOnRescued, &GCHostage::SetOnRescued)
        .addProperty("EntitySpottedState", &GCHostage::GetEntitySpottedState, &GCHostage::SetEntitySpottedState)
        .addProperty("SpotRules", &GCHostage::GetSpotRules, &GCHostage::SetSpotRules)
        .addProperty("UiHostageSpawnExclusionGroupMask", &GCHostage::GetUiHostageSpawnExclusionGroupMask, &GCHostage::SetUiHostageSpawnExclusionGroupMask)
        .addProperty("HostageSpawnRandomFactor", &GCHostage::GetHostageSpawnRandomFactor, &GCHostage::SetHostageSpawnRandomFactor)
        .addProperty("Remove", &GCHostage::GetRemove, &GCHostage::SetRemove)
        .addProperty("Vel", &GCHostage::GetVel, &GCHostage::SetVel)
        .addProperty("IsRescued", &GCHostage::GetIsRescued, &GCHostage::SetIsRescued)
        .addProperty("JumpedThisFrame", &GCHostage::GetJumpedThisFrame, &GCHostage::SetJumpedThisFrame)
        .addProperty("HostageState", &GCHostage::GetHostageState, &GCHostage::SetHostageState)
        .addProperty("Leader", &GCHostage::GetLeader, &GCHostage::SetLeader)
        .addProperty("LastLeader", &GCHostage::GetLastLeader, &GCHostage::SetLastLeader)
        .addProperty("ReuseTimer", &GCHostage::GetReuseTimer, &GCHostage::SetReuseTimer)
        .addProperty("HasBeenUsed", &GCHostage::GetHasBeenUsed, &GCHostage::SetHasBeenUsed)
        .addProperty("Accel", &GCHostage::GetAccel, &GCHostage::SetAccel)
        .addProperty("IsRunning", &GCHostage::GetIsRunning, &GCHostage::SetIsRunning)
        .addProperty("IsCrouching", &GCHostage::GetIsCrouching, &GCHostage::SetIsCrouching)
        .addProperty("JumpTimer", &GCHostage::GetJumpTimer, &GCHostage::SetJumpTimer)
        .addProperty("IsWaitingForLeader", &GCHostage::GetIsWaitingForLeader, &GCHostage::SetIsWaitingForLeader)
        .addProperty("RepathTimer", &GCHostage::GetRepathTimer, &GCHostage::SetRepathTimer)
        .addProperty("InhibitDoorTimer", &GCHostage::GetInhibitDoorTimer, &GCHostage::SetInhibitDoorTimer)
        .addProperty("InhibitObstacleAvoidanceTimer", &GCHostage::GetInhibitObstacleAvoidanceTimer, &GCHostage::SetInhibitObstacleAvoidanceTimer)
        .addProperty("WiggleTimer", &GCHostage::GetWiggleTimer, &GCHostage::SetWiggleTimer)
        .addProperty("IsAdjusted", &GCHostage::GetIsAdjusted, &GCHostage::SetIsAdjusted)
        .addProperty("HandsHaveBeenCut", &GCHostage::GetHandsHaveBeenCut, &GCHostage::SetHandsHaveBeenCut)
        .addProperty("HostageGrabber", &GCHostage::GetHostageGrabber, &GCHostage::SetHostageGrabber)
        .addProperty("LastGrabTime", &GCHostage::GetLastGrabTime, &GCHostage::SetLastGrabTime)
        .addProperty("PositionWhenStartedDroppingToGround", &GCHostage::GetPositionWhenStartedDroppingToGround, &GCHostage::SetPositionWhenStartedDroppingToGround)
        .addProperty("GrabbedPos", &GCHostage::GetGrabbedPos, &GCHostage::SetGrabbedPos)
        .addProperty("RescueStartTime", &GCHostage::GetRescueStartTime, &GCHostage::SetRescueStartTime)
        .addProperty("GrabSuccessTime", &GCHostage::GetGrabSuccessTime, &GCHostage::SetGrabSuccessTime)
        .addProperty("DropStartTime", &GCHostage::GetDropStartTime, &GCHostage::SetDropStartTime)
        .addProperty("ApproachRewardPayouts", &GCHostage::GetApproachRewardPayouts, &GCHostage::SetApproachRewardPayouts)
        .addProperty("PickupEventCount", &GCHostage::GetPickupEventCount, &GCHostage::SetPickupEventCount)
        .addProperty("SpawnGroundPos", &GCHostage::GetSpawnGroundPos, &GCHostage::SetSpawnGroundPos)
        .addProperty("HostageResetPosition", &GCHostage::GetHostageResetPosition, &GCHostage::SetHostageResetPosition)
        .addProperty("Parent", &GCHostage::GetParent, &GCHostage::SetParent)
        .addFunction("ToPtr", &GCHostage::ToPtr)
        .addFunction("IsValid", &GCHostage::IsValid)
        .endClass();
}