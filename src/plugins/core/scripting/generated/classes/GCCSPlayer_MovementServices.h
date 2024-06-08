class GCCSPlayer_MovementServices;

#ifndef _gcccsplayer_movementservices_h
#define _gcccsplayer_movementservices_h

#include "../../../scripting.h"




class GCCSPlayer_MovementServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_MovementServices() {}
    GCCSPlayer_MovementServices(void *ptr) : m_ptr(ptr) {}

    float GetMaxFallVelocity() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flMaxFallVelocity"); }
    void SetMaxFallVelocity(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flMaxFallVelocity", false, value); }
    Vector GetLadderNormal() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayer_MovementServices", "m_vecLadderNormal"); }
    void SetLadderNormal(Vector value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_vecLadderNormal", false, value); }
    int32_t GetLadderSurfacePropIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nLadderSurfacePropIndex"); }
    void SetLadderSurfacePropIndex(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nLadderSurfacePropIndex", false, value); }
    float GetDuckAmount() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flDuckAmount"); }
    void SetDuckAmount(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flDuckAmount", false, value); }
    float GetDuckSpeed() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flDuckSpeed"); }
    void SetDuckSpeed(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flDuckSpeed", false, value); }
    bool GetDuckOverride() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bDuckOverride"); }
    void SetDuckOverride(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bDuckOverride", false, value); }
    bool GetDesiresDuck() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bDesiresDuck"); }
    void SetDesiresDuck(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bDesiresDuck", false, value); }
    float GetDuckOffset() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flDuckOffset"); }
    void SetDuckOffset(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flDuckOffset", false, value); }
    uint32_t GetDuckTimeMsecs() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nDuckTimeMsecs"); }
    void SetDuckTimeMsecs(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nDuckTimeMsecs", false, value); }
    uint32_t GetDuckJumpTimeMsecs() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nDuckJumpTimeMsecs"); }
    void SetDuckJumpTimeMsecs(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nDuckJumpTimeMsecs", false, value); }
    uint32_t GetJumpTimeMsecs() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nJumpTimeMsecs"); }
    void SetJumpTimeMsecs(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nJumpTimeMsecs", false, value); }
    float GetLastDuckTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flLastDuckTime"); }
    void SetLastDuckTime(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flLastDuckTime", false, value); }
    Vector2D GetLastPositionAtFullCrouchSpeed() const { return GetSchemaValue<Vector2D>(m_ptr, "CCSPlayer_MovementServices", "m_vecLastPositionAtFullCrouchSpeed"); }
    void SetLastPositionAtFullCrouchSpeed(Vector2D value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_vecLastPositionAtFullCrouchSpeed", false, value); }
    bool GetDuckUntilOnGround() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_duckUntilOnGround"); }
    void SetDuckUntilOnGround(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_duckUntilOnGround", false, value); }
    bool GetHasWalkMovedSinceLastJump() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bHasWalkMovedSinceLastJump"); }
    void SetHasWalkMovedSinceLastJump(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bHasWalkMovedSinceLastJump", false, value); }
    bool GetInStuckTest() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bInStuckTest"); }
    void SetInStuckTest(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bInStuckTest", false, value); }
    int32_t GetTraceCount() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nTraceCount"); }
    void SetTraceCount(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nTraceCount", false, value); }
    int32_t GetStuckLast() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_StuckLast"); }
    void SetStuckLast(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_StuckLast", false, value); }
    bool GetSpeedCropped() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bSpeedCropped"); }
    void SetSpeedCropped(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bSpeedCropped", false, value); }
    int32_t GetOldWaterLevel() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nOldWaterLevel"); }
    void SetOldWaterLevel(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nOldWaterLevel", false, value); }
    float GetWaterEntryTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flWaterEntryTime"); }
    void SetWaterEntryTime(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flWaterEntryTime", false, value); }
    Vector GetForward() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayer_MovementServices", "m_vecForward"); }
    void SetForward(Vector value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_vecForward", false, value); }
    Vector GetLeft() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayer_MovementServices", "m_vecLeft"); }
    void SetLeft(Vector value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_vecLeft", false, value); }
    Vector GetUp() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayer_MovementServices", "m_vecUp"); }
    void SetUp(Vector value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_vecUp", false, value); }
    int32_t GetGameCodeHasMovedPlayerAfterCommand() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_nGameCodeHasMovedPlayerAfterCommand"); }
    void SetGameCodeHasMovedPlayerAfterCommand(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nGameCodeHasMovedPlayerAfterCommand", false, value); }
    bool GetMadeFootstepNoise() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bMadeFootstepNoise"); }
    void SetMadeFootstepNoise(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bMadeFootstepNoise", false, value); }
    int32_t GetFootsteps() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_MovementServices", "m_iFootsteps"); }
    void SetFootsteps(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_iFootsteps", false, value); }
    bool GetOldJumpPressed() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_MovementServices", "m_bOldJumpPressed"); }
    void SetOldJumpPressed(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_bOldJumpPressed", false, value); }
    float GetJumpPressedTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flJumpPressedTime"); }
    void SetJumpPressedTime(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flJumpPressedTime", false, value); }
    float GetJumpUntil() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flJumpUntil"); }
    void SetJumpUntil(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flJumpUntil", false, value); }
    float GetJumpVel() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flJumpVel"); }
    void SetJumpVel(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flJumpVel", false, value); }
    uint64_t GetButtonDownMaskPrev() const { return GetSchemaValue<uint64_t>(m_ptr, "CCSPlayer_MovementServices", "m_nButtonDownMaskPrev"); }
    void SetButtonDownMaskPrev(uint64_t value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_nButtonDownMaskPrev", false, value); }
    float GetOffsetTickCompleteTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flOffsetTickCompleteTime"); }
    void SetOffsetTickCompleteTime(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flOffsetTickCompleteTime", false, value); }
    float GetOffsetTickStashedSpeed() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flOffsetTickStashedSpeed"); }
    void SetOffsetTickStashedSpeed(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flOffsetTickStashedSpeed", false, value); }
    float GetStamina() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flStamina"); }
    void SetStamina(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flStamina", false, value); }
    float GetHeightAtJumpStart() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flHeightAtJumpStart"); }
    void SetHeightAtJumpStart(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flHeightAtJumpStart", false, value); }
    float GetMaxJumpHeightThisJump() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_MovementServices", "m_flMaxJumpHeightThisJump"); }
    void SetMaxJumpHeightThisJump(float value) { SetSchemaValue(m_ptr, "CCSPlayer_MovementServices", "m_flMaxJumpHeightThisJump", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif