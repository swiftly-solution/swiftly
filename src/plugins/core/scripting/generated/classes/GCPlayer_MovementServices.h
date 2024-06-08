class GCPlayer_MovementServices;

#ifndef _gccplayer_movementservices_h
#define _gccplayer_movementservices_h

#include "../../../scripting.h"


#include "GCInButtonState.h"

class GCPlayer_MovementServices
{
private:
    void *m_ptr;

public:
    GCPlayer_MovementServices() {}
    GCPlayer_MovementServices(void *ptr) : m_ptr(ptr) {}

    int32_t GetImpulse() const { return GetSchemaValue<int32_t>(m_ptr, "CPlayer_MovementServices", "m_nImpulse"); }
    void SetImpulse(int32_t value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nImpulse", false, value); }
    GCInButtonState GetButtons() const { return GetSchemaValue<GCInButtonState>(m_ptr, "CPlayer_MovementServices", "m_nButtons"); }
    void SetButtons(GCInButtonState value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nButtons", false, value); }
    uint64_t GetQueuedButtonDownMask() const { return GetSchemaValue<uint64_t>(m_ptr, "CPlayer_MovementServices", "m_nQueuedButtonDownMask"); }
    void SetQueuedButtonDownMask(uint64_t value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nQueuedButtonDownMask", false, value); }
    uint64_t GetQueuedButtonChangeMask() const { return GetSchemaValue<uint64_t>(m_ptr, "CPlayer_MovementServices", "m_nQueuedButtonChangeMask"); }
    void SetQueuedButtonChangeMask(uint64_t value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nQueuedButtonChangeMask", false, value); }
    uint64_t GetButtonDoublePressed() const { return GetSchemaValue<uint64_t>(m_ptr, "CPlayer_MovementServices", "m_nButtonDoublePressed"); }
    void SetButtonDoublePressed(uint64_t value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nButtonDoublePressed", false, value); }
    std::vector<uint32_t> GetButtonPressedCmdNumber() const { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CPlayer_MovementServices", "m_pButtonPressedCmdNumber"); std::vector<uint32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetButtonPressedCmdNumber(std::vector<uint32_t> value) { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CPlayer_MovementServices", "m_pButtonPressedCmdNumber"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_pButtonPressedCmdNumber", false, outValue); }
    uint32_t GetLastCommandNumberProcessed() const { return GetSchemaValue<uint32_t>(m_ptr, "CPlayer_MovementServices", "m_nLastCommandNumberProcessed"); }
    void SetLastCommandNumberProcessed(uint32_t value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nLastCommandNumberProcessed", false, value); }
    uint64_t GetToggleButtonDownMask() const { return GetSchemaValue<uint64_t>(m_ptr, "CPlayer_MovementServices", "m_nToggleButtonDownMask"); }
    void SetToggleButtonDownMask(uint64_t value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nToggleButtonDownMask", false, value); }
    float GetMaxspeed() const { return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices", "m_flMaxspeed"); }
    void SetMaxspeed(float value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_flMaxspeed", false, value); }
    std::vector<float> GetForceSubtickMoveWhen() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CPlayer_MovementServices", "m_arrForceSubtickMoveWhen"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetForceSubtickMoveWhen(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CPlayer_MovementServices", "m_arrForceSubtickMoveWhen"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_arrForceSubtickMoveWhen", false, outValue); }
    float GetForwardMove() const { return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices", "m_flForwardMove"); }
    void SetForwardMove(float value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_flForwardMove", false, value); }
    float GetLeftMove() const { return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices", "m_flLeftMove"); }
    void SetLeftMove(float value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_flLeftMove", false, value); }
    float GetUpMove() const { return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices", "m_flUpMove"); }
    void SetUpMove(float value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_flUpMove", false, value); }
    Vector GetLastMovementImpulses() const { return GetSchemaValue<Vector>(m_ptr, "CPlayer_MovementServices", "m_vecLastMovementImpulses"); }
    void SetLastMovementImpulses(Vector value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_vecLastMovementImpulses", false, value); }
    QAngle GetOldViewAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CPlayer_MovementServices", "m_vecOldViewAngles"); }
    void SetOldViewAngles(QAngle value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_vecOldViewAngles", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif