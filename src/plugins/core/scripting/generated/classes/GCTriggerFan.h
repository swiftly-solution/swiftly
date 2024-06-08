class GCTriggerFan;

#ifndef _gcctriggerfan_h
#define _gcctriggerfan_h

#include "../../../scripting.h"


#include "GCountdownTimer.h"

class GCTriggerFan
{
private:
    void *m_ptr;

public:
    GCTriggerFan() {}
    GCTriggerFan(void *ptr) : m_ptr(ptr) {}

    Vector GetFanOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CTriggerFan", "m_vFanOrigin"); }
    void SetFanOrigin(Vector value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_vFanOrigin", false, value); }
    Vector GetFanEnd() const { return GetSchemaValue<Vector>(m_ptr, "CTriggerFan", "m_vFanEnd"); }
    void SetFanEnd(Vector value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_vFanEnd", false, value); }
    Vector GetNoise() const { return GetSchemaValue<Vector>(m_ptr, "CTriggerFan", "m_vNoise"); }
    void SetNoise(Vector value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_vNoise", false, value); }
    float GetForce() const { return GetSchemaValue<float>(m_ptr, "CTriggerFan", "m_flForce"); }
    void SetForce(float value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_flForce", false, value); }
    float GetRopeForceScale() const { return GetSchemaValue<float>(m_ptr, "CTriggerFan", "m_flRopeForceScale"); }
    void SetRopeForceScale(float value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_flRopeForceScale", false, value); }
    float GetPlayerForce() const { return GetSchemaValue<float>(m_ptr, "CTriggerFan", "m_flPlayerForce"); }
    void SetPlayerForce(float value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_flPlayerForce", false, value); }
    float GetRampTime() const { return GetSchemaValue<float>(m_ptr, "CTriggerFan", "m_flRampTime"); }
    void SetRampTime(float value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_flRampTime", false, value); }
    bool GetFalloff() const { return GetSchemaValue<bool>(m_ptr, "CTriggerFan", "m_bFalloff"); }
    void SetFalloff(bool value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_bFalloff", false, value); }
    bool GetPushPlayer() const { return GetSchemaValue<bool>(m_ptr, "CTriggerFan", "m_bPushPlayer"); }
    void SetPushPlayer(bool value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_bPushPlayer", false, value); }
    bool GetRampDown() const { return GetSchemaValue<bool>(m_ptr, "CTriggerFan", "m_bRampDown"); }
    void SetRampDown(bool value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_bRampDown", false, value); }
    bool GetAddNoise() const { return GetSchemaValue<bool>(m_ptr, "CTriggerFan", "m_bAddNoise"); }
    void SetAddNoise(bool value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_bAddNoise", false, value); }
    GCountdownTimer GetRampTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CTriggerFan", "m_RampTimer"); }
    void SetRampTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CTriggerFan", "m_RampTimer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif