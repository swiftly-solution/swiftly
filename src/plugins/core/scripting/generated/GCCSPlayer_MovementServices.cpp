#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_MovementServices::GCCSPlayer_MovementServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_MovementServices::GCCSPlayer_MovementServices(void *ptr) {
    m_ptr = ptr;
}
float GCCSPlayer_MovementServices::GetMaxFallVelocity() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flMaxFallVelocity");
}
void GCCSPlayer_MovementServices::SetMaxFallVelocity(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flMaxFallVelocity", false, value);
}
Vector GCCSPlayer_MovementServices::GetLadderNormal() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayer_MovementServices", "m_vecLadderNormal");
}
void GCCSPlayer_MovementServices::SetLadderNormal(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_vecLadderNormal", false, value);
}
int32_t GCCSPlayer_MovementServices::GetLadderSurfacePropIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nLadderSurfacePropIndex");
}
void GCCSPlayer_MovementServices::SetLadderSurfacePropIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nLadderSurfacePropIndex", false, value);
}
float GCCSPlayer_MovementServices::GetDuckAmount() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flDuckAmount");
}
void GCCSPlayer_MovementServices::SetDuckAmount(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flDuckAmount", false, value);
}
float GCCSPlayer_MovementServices::GetDuckSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flDuckSpeed");
}
void GCCSPlayer_MovementServices::SetDuckSpeed(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flDuckSpeed", false, value);
}
bool GCCSPlayer_MovementServices::GetDuckOverride() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bDuckOverride");
}
void GCCSPlayer_MovementServices::SetDuckOverride(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bDuckOverride", false, value);
}
bool GCCSPlayer_MovementServices::GetDesiresDuck() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bDesiresDuck");
}
void GCCSPlayer_MovementServices::SetDesiresDuck(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bDesiresDuck", false, value);
}
float GCCSPlayer_MovementServices::GetDuckOffset() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flDuckOffset");
}
void GCCSPlayer_MovementServices::SetDuckOffset(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flDuckOffset", false, value);
}
uint32_t GCCSPlayer_MovementServices::GetDuckTimeMsecs() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nDuckTimeMsecs");
}
void GCCSPlayer_MovementServices::SetDuckTimeMsecs(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nDuckTimeMsecs", false, value);
}
uint32_t GCCSPlayer_MovementServices::GetDuckJumpTimeMsecs() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nDuckJumpTimeMsecs");
}
void GCCSPlayer_MovementServices::SetDuckJumpTimeMsecs(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nDuckJumpTimeMsecs", false, value);
}
uint32_t GCCSPlayer_MovementServices::GetJumpTimeMsecs() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nJumpTimeMsecs");
}
void GCCSPlayer_MovementServices::SetJumpTimeMsecs(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nJumpTimeMsecs", false, value);
}
float GCCSPlayer_MovementServices::GetLastDuckTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flLastDuckTime");
}
void GCCSPlayer_MovementServices::SetLastDuckTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flLastDuckTime", false, value);
}
Vector2D GCCSPlayer_MovementServices::GetLastPositionAtFullCrouchSpeed() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CCSPlayer_MovementServices", "m_vecLastPositionAtFullCrouchSpeed");
}
void GCCSPlayer_MovementServices::SetLastPositionAtFullCrouchSpeed(Vector2D value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_vecLastPositionAtFullCrouchSpeed", false, value);
}
bool GCCSPlayer_MovementServices::GetDuckUntilOnGround() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_duckUntilOnGround");
}
void GCCSPlayer_MovementServices::SetDuckUntilOnGround(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_duckUntilOnGround", false, value);
}
bool GCCSPlayer_MovementServices::GetHasWalkMovedSinceLastJump() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bHasWalkMovedSinceLastJump");
}
void GCCSPlayer_MovementServices::SetHasWalkMovedSinceLastJump(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bHasWalkMovedSinceLastJump", false, value);
}
bool GCCSPlayer_MovementServices::GetInStuckTest() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bInStuckTest");
}
void GCCSPlayer_MovementServices::SetInStuckTest(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bInStuckTest", false, value);
}
int32_t GCCSPlayer_MovementServices::GetTraceCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nTraceCount");
}
void GCCSPlayer_MovementServices::SetTraceCount(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nTraceCount", false, value);
}
int32_t GCCSPlayer_MovementServices::GetStuckLast() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_StuckLast");
}
void GCCSPlayer_MovementServices::SetStuckLast(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_StuckLast", false, value);
}
bool GCCSPlayer_MovementServices::GetSpeedCropped() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bSpeedCropped");
}
void GCCSPlayer_MovementServices::SetSpeedCropped(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bSpeedCropped", false, value);
}
int32_t GCCSPlayer_MovementServices::GetOldWaterLevel() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nOldWaterLevel");
}
void GCCSPlayer_MovementServices::SetOldWaterLevel(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nOldWaterLevel", false, value);
}
float GCCSPlayer_MovementServices::GetWaterEntryTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flWaterEntryTime");
}
void GCCSPlayer_MovementServices::SetWaterEntryTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flWaterEntryTime", false, value);
}
Vector GCCSPlayer_MovementServices::GetForward() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayer_MovementServices", "m_vecForward");
}
void GCCSPlayer_MovementServices::SetForward(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_vecForward", false, value);
}
Vector GCCSPlayer_MovementServices::GetLeft() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayer_MovementServices", "m_vecLeft");
}
void GCCSPlayer_MovementServices::SetLeft(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_vecLeft", false, value);
}
Vector GCCSPlayer_MovementServices::GetUp() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayer_MovementServices", "m_vecUp");
}
void GCCSPlayer_MovementServices::SetUp(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_vecUp", false, value);
}
int32_t GCCSPlayer_MovementServices::GetGameCodeHasMovedPlayerAfterCommand() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nGameCodeHasMovedPlayerAfterCommand");
}
void GCCSPlayer_MovementServices::SetGameCodeHasMovedPlayerAfterCommand(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nGameCodeHasMovedPlayerAfterCommand", false, value);
}
bool GCCSPlayer_MovementServices::GetMadeFootstepNoise() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bMadeFootstepNoise");
}
void GCCSPlayer_MovementServices::SetMadeFootstepNoise(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bMadeFootstepNoise", false, value);
}
int32_t GCCSPlayer_MovementServices::GetFootsteps() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_iFootsteps");
}
void GCCSPlayer_MovementServices::SetFootsteps(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_iFootsteps", false, value);
}
bool GCCSPlayer_MovementServices::GetOldJumpPressed() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bOldJumpPressed");
}
void GCCSPlayer_MovementServices::SetOldJumpPressed(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bOldJumpPressed", false, value);
}
float GCCSPlayer_MovementServices::GetJumpPressedTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flJumpPressedTime");
}
void GCCSPlayer_MovementServices::SetJumpPressedTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flJumpPressedTime", false, value);
}
float GCCSPlayer_MovementServices::GetJumpUntil() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flJumpUntil");
}
void GCCSPlayer_MovementServices::SetJumpUntil(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flJumpUntil", false, value);
}
float GCCSPlayer_MovementServices::GetJumpVel() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flJumpVel");
}
void GCCSPlayer_MovementServices::SetJumpVel(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flJumpVel", false, value);
}
float GCCSPlayer_MovementServices::GetStashGrenadeParameterWhen() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_fStashGrenadeParameterWhen");
}
void GCCSPlayer_MovementServices::SetStashGrenadeParameterWhen(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_fStashGrenadeParameterWhen", false, value);
}
uint64_t GCCSPlayer_MovementServices::GetButtonDownMaskPrev() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSPlayer_MovementServices", "m_nButtonDownMaskPrev");
}
void GCCSPlayer_MovementServices::SetButtonDownMaskPrev(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nButtonDownMaskPrev", false, value);
}
float GCCSPlayer_MovementServices::GetOffsetTickCompleteTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flOffsetTickCompleteTime");
}
void GCCSPlayer_MovementServices::SetOffsetTickCompleteTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flOffsetTickCompleteTime", false, value);
}
float GCCSPlayer_MovementServices::GetOffsetTickStashedSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flOffsetTickStashedSpeed");
}
void GCCSPlayer_MovementServices::SetOffsetTickStashedSpeed(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flOffsetTickStashedSpeed", false, value);
}
float GCCSPlayer_MovementServices::GetStamina() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flStamina");
}
void GCCSPlayer_MovementServices::SetStamina(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flStamina", false, value);
}
float GCCSPlayer_MovementServices::GetHeightAtJumpStart() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flHeightAtJumpStart");
}
void GCCSPlayer_MovementServices::SetHeightAtJumpStart(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flHeightAtJumpStart", false, value);
}
float GCCSPlayer_MovementServices::GetMaxJumpHeightThisJump() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flMaxJumpHeightThisJump");
}
void GCCSPlayer_MovementServices::SetMaxJumpHeightThisJump(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flMaxJumpHeightThisJump", false, value);
}
std::string GCCSPlayer_MovementServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_MovementServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_MovementServices_Humanoid GCCSPlayer_MovementServices::GetParent() const {
    GCPlayer_MovementServices_Humanoid value(m_ptr);
    return value;
}
void GCCSPlayer_MovementServices::SetParent(GCPlayer_MovementServices_Humanoid value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_MovementServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_MovementServices>("CCSPlayer_MovementServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaxFallVelocity", &GCCSPlayer_MovementServices::GetMaxFallVelocity, &GCCSPlayer_MovementServices::SetMaxFallVelocity)
        .addProperty("LadderNormal", &GCCSPlayer_MovementServices::GetLadderNormal, &GCCSPlayer_MovementServices::SetLadderNormal)
        .addProperty("LadderSurfacePropIndex", &GCCSPlayer_MovementServices::GetLadderSurfacePropIndex, &GCCSPlayer_MovementServices::SetLadderSurfacePropIndex)
        .addProperty("DuckAmount", &GCCSPlayer_MovementServices::GetDuckAmount, &GCCSPlayer_MovementServices::SetDuckAmount)
        .addProperty("DuckSpeed", &GCCSPlayer_MovementServices::GetDuckSpeed, &GCCSPlayer_MovementServices::SetDuckSpeed)
        .addProperty("DuckOverride", &GCCSPlayer_MovementServices::GetDuckOverride, &GCCSPlayer_MovementServices::SetDuckOverride)
        .addProperty("DesiresDuck", &GCCSPlayer_MovementServices::GetDesiresDuck, &GCCSPlayer_MovementServices::SetDesiresDuck)
        .addProperty("DuckOffset", &GCCSPlayer_MovementServices::GetDuckOffset, &GCCSPlayer_MovementServices::SetDuckOffset)
        .addProperty("DuckTimeMsecs", &GCCSPlayer_MovementServices::GetDuckTimeMsecs, &GCCSPlayer_MovementServices::SetDuckTimeMsecs)
        .addProperty("DuckJumpTimeMsecs", &GCCSPlayer_MovementServices::GetDuckJumpTimeMsecs, &GCCSPlayer_MovementServices::SetDuckJumpTimeMsecs)
        .addProperty("JumpTimeMsecs", &GCCSPlayer_MovementServices::GetJumpTimeMsecs, &GCCSPlayer_MovementServices::SetJumpTimeMsecs)
        .addProperty("LastDuckTime", &GCCSPlayer_MovementServices::GetLastDuckTime, &GCCSPlayer_MovementServices::SetLastDuckTime)
        .addProperty("LastPositionAtFullCrouchSpeed", &GCCSPlayer_MovementServices::GetLastPositionAtFullCrouchSpeed, &GCCSPlayer_MovementServices::SetLastPositionAtFullCrouchSpeed)
        .addProperty("DuckUntilOnGround", &GCCSPlayer_MovementServices::GetDuckUntilOnGround, &GCCSPlayer_MovementServices::SetDuckUntilOnGround)
        .addProperty("HasWalkMovedSinceLastJump", &GCCSPlayer_MovementServices::GetHasWalkMovedSinceLastJump, &GCCSPlayer_MovementServices::SetHasWalkMovedSinceLastJump)
        .addProperty("InStuckTest", &GCCSPlayer_MovementServices::GetInStuckTest, &GCCSPlayer_MovementServices::SetInStuckTest)
        .addProperty("TraceCount", &GCCSPlayer_MovementServices::GetTraceCount, &GCCSPlayer_MovementServices::SetTraceCount)
        .addProperty("StuckLast", &GCCSPlayer_MovementServices::GetStuckLast, &GCCSPlayer_MovementServices::SetStuckLast)
        .addProperty("SpeedCropped", &GCCSPlayer_MovementServices::GetSpeedCropped, &GCCSPlayer_MovementServices::SetSpeedCropped)
        .addProperty("OldWaterLevel", &GCCSPlayer_MovementServices::GetOldWaterLevel, &GCCSPlayer_MovementServices::SetOldWaterLevel)
        .addProperty("WaterEntryTime", &GCCSPlayer_MovementServices::GetWaterEntryTime, &GCCSPlayer_MovementServices::SetWaterEntryTime)
        .addProperty("Forward", &GCCSPlayer_MovementServices::GetForward, &GCCSPlayer_MovementServices::SetForward)
        .addProperty("Left", &GCCSPlayer_MovementServices::GetLeft, &GCCSPlayer_MovementServices::SetLeft)
        .addProperty("Up", &GCCSPlayer_MovementServices::GetUp, &GCCSPlayer_MovementServices::SetUp)
        .addProperty("GameCodeHasMovedPlayerAfterCommand", &GCCSPlayer_MovementServices::GetGameCodeHasMovedPlayerAfterCommand, &GCCSPlayer_MovementServices::SetGameCodeHasMovedPlayerAfterCommand)
        .addProperty("MadeFootstepNoise", &GCCSPlayer_MovementServices::GetMadeFootstepNoise, &GCCSPlayer_MovementServices::SetMadeFootstepNoise)
        .addProperty("Footsteps", &GCCSPlayer_MovementServices::GetFootsteps, &GCCSPlayer_MovementServices::SetFootsteps)
        .addProperty("OldJumpPressed", &GCCSPlayer_MovementServices::GetOldJumpPressed, &GCCSPlayer_MovementServices::SetOldJumpPressed)
        .addProperty("JumpPressedTime", &GCCSPlayer_MovementServices::GetJumpPressedTime, &GCCSPlayer_MovementServices::SetJumpPressedTime)
        .addProperty("JumpUntil", &GCCSPlayer_MovementServices::GetJumpUntil, &GCCSPlayer_MovementServices::SetJumpUntil)
        .addProperty("JumpVel", &GCCSPlayer_MovementServices::GetJumpVel, &GCCSPlayer_MovementServices::SetJumpVel)
        .addProperty("StashGrenadeParameterWhen", &GCCSPlayer_MovementServices::GetStashGrenadeParameterWhen, &GCCSPlayer_MovementServices::SetStashGrenadeParameterWhen)
        .addProperty("ButtonDownMaskPrev", &GCCSPlayer_MovementServices::GetButtonDownMaskPrev, &GCCSPlayer_MovementServices::SetButtonDownMaskPrev)
        .addProperty("OffsetTickCompleteTime", &GCCSPlayer_MovementServices::GetOffsetTickCompleteTime, &GCCSPlayer_MovementServices::SetOffsetTickCompleteTime)
        .addProperty("OffsetTickStashedSpeed", &GCCSPlayer_MovementServices::GetOffsetTickStashedSpeed, &GCCSPlayer_MovementServices::SetOffsetTickStashedSpeed)
        .addProperty("Stamina", &GCCSPlayer_MovementServices::GetStamina, &GCCSPlayer_MovementServices::SetStamina)
        .addProperty("HeightAtJumpStart", &GCCSPlayer_MovementServices::GetHeightAtJumpStart, &GCCSPlayer_MovementServices::SetHeightAtJumpStart)
        .addProperty("MaxJumpHeightThisJump", &GCCSPlayer_MovementServices::GetMaxJumpHeightThisJump, &GCCSPlayer_MovementServices::SetMaxJumpHeightThisJump)
        .addProperty("Parent", &GCCSPlayer_MovementServices::GetParent, &GCCSPlayer_MovementServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_MovementServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_MovementServices::IsValid)
        .endClass();
}