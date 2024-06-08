class GCBot;

#ifndef _gccbot_h
#define _gccbot_h

#include "../../../scripting.h"


#include "GCCSPlayerController.h"
#include "GCCSPlayerPawn.h"

class GCBot
{
private:
    void *m_ptr;

public:
    GCBot() {}
    GCBot(void *ptr) : m_ptr(ptr) {}

    GCCSPlayerController* GetController() const { return GetSchemaValue<GCCSPlayerController*>(m_ptr, "CBot", "m_pController"); }
    void SetController(GCCSPlayerController* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Controller' is not possible.\n"); }
    GCCSPlayerPawn* GetPlayer() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CBot", "m_pPlayer"); }
    void SetPlayer(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Player' is not possible.\n"); }
    bool GetHasSpawned() const { return GetSchemaValue<bool>(m_ptr, "CBot", "m_bHasSpawned"); }
    void SetHasSpawned(bool value) { SetSchemaValue(m_ptr, "CBot", "m_bHasSpawned", false, value); }
    uint32_t GetId() const { return GetSchemaValue<uint32_t>(m_ptr, "CBot", "m_id"); }
    void SetId(uint32_t value) { SetSchemaValue(m_ptr, "CBot", "m_id", false, value); }
    bool GetIsRunning() const { return GetSchemaValue<bool>(m_ptr, "CBot", "m_isRunning"); }
    void SetIsRunning(bool value) { SetSchemaValue(m_ptr, "CBot", "m_isRunning", false, value); }
    bool GetIsCrouching() const { return GetSchemaValue<bool>(m_ptr, "CBot", "m_isCrouching"); }
    void SetIsCrouching(bool value) { SetSchemaValue(m_ptr, "CBot", "m_isCrouching", false, value); }
    float GetForwardSpeed() const { return GetSchemaValue<float>(m_ptr, "CBot", "m_forwardSpeed"); }
    void SetForwardSpeed(float value) { SetSchemaValue(m_ptr, "CBot", "m_forwardSpeed", false, value); }
    float GetLeftSpeed() const { return GetSchemaValue<float>(m_ptr, "CBot", "m_leftSpeed"); }
    void SetLeftSpeed(float value) { SetSchemaValue(m_ptr, "CBot", "m_leftSpeed", false, value); }
    float GetVerticalSpeed() const { return GetSchemaValue<float>(m_ptr, "CBot", "m_verticalSpeed"); }
    void SetVerticalSpeed(float value) { SetSchemaValue(m_ptr, "CBot", "m_verticalSpeed", false, value); }
    uint64_t GetButtonFlags() const { return GetSchemaValue<uint64_t>(m_ptr, "CBot", "m_buttonFlags"); }
    void SetButtonFlags(uint64_t value) { SetSchemaValue(m_ptr, "CBot", "m_buttonFlags", false, value); }
    float GetJumpTimestamp() const { return GetSchemaValue<float>(m_ptr, "CBot", "m_jumpTimestamp"); }
    void SetJumpTimestamp(float value) { SetSchemaValue(m_ptr, "CBot", "m_jumpTimestamp", false, value); }
    Vector GetViewForward() const { return GetSchemaValue<Vector>(m_ptr, "CBot", "m_viewForward"); }
    void SetViewForward(Vector value) { SetSchemaValue(m_ptr, "CBot", "m_viewForward", false, value); }
    int32_t GetPostureStackIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CBot", "m_postureStackIndex"); }
    void SetPostureStackIndex(int32_t value) { SetSchemaValue(m_ptr, "CBot", "m_postureStackIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif