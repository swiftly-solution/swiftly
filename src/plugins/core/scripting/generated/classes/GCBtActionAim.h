class GCBtActionAim;

#ifndef _gccbtactionaim_h
#define _gccbtactionaim_h

#include "../../../scripting.h"


#include "GCountdownTimer.h"

class GCBtActionAim
{
private:
    void *m_ptr;

public:
    GCBtActionAim() {}
    GCBtActionAim(void *ptr) : m_ptr(ptr) {}

    CUtlString GetSensorInputKey() const { return GetSchemaValue<CUtlString>(m_ptr, "CBtActionAim", "m_szSensorInputKey"); }
    void SetSensorInputKey(CUtlString value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_szSensorInputKey", false, value); }
    CUtlString GetAimReadyKey() const { return GetSchemaValue<CUtlString>(m_ptr, "CBtActionAim", "m_szAimReadyKey"); }
    void SetAimReadyKey(CUtlString value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_szAimReadyKey", false, value); }
    float GetZoomCooldownTimestamp() const { return GetSchemaValue<float>(m_ptr, "CBtActionAim", "m_flZoomCooldownTimestamp"); }
    void SetZoomCooldownTimestamp(float value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_flZoomCooldownTimestamp", false, value); }
    bool GetDoneAiming() const { return GetSchemaValue<bool>(m_ptr, "CBtActionAim", "m_bDoneAiming"); }
    void SetDoneAiming(bool value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_bDoneAiming", false, value); }
    float GetLerpStartTime() const { return GetSchemaValue<float>(m_ptr, "CBtActionAim", "m_flLerpStartTime"); }
    void SetLerpStartTime(float value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_flLerpStartTime", false, value); }
    float GetNextLookTargetLerpTime() const { return GetSchemaValue<float>(m_ptr, "CBtActionAim", "m_flNextLookTargetLerpTime"); }
    void SetNextLookTargetLerpTime(float value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_flNextLookTargetLerpTime", false, value); }
    float GetPenaltyReductionRatio() const { return GetSchemaValue<float>(m_ptr, "CBtActionAim", "m_flPenaltyReductionRatio"); }
    void SetPenaltyReductionRatio(float value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_flPenaltyReductionRatio", false, value); }
    QAngle GetNextLookTarget() const { return GetSchemaValue<QAngle>(m_ptr, "CBtActionAim", "m_NextLookTarget"); }
    void SetNextLookTarget(QAngle value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_NextLookTarget", false, value); }
    GCountdownTimer GetAimTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CBtActionAim", "m_AimTimer"); }
    void SetAimTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_AimTimer", false, value); }
    GCountdownTimer GetSniperHoldTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CBtActionAim", "m_SniperHoldTimer"); }
    void SetSniperHoldTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_SniperHoldTimer", false, value); }
    GCountdownTimer GetFocusIntervalTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CBtActionAim", "m_FocusIntervalTimer"); }
    void SetFocusIntervalTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_FocusIntervalTimer", false, value); }
    bool GetAcquired() const { return GetSchemaValue<bool>(m_ptr, "CBtActionAim", "m_bAcquired"); }
    void SetAcquired(bool value) { SetSchemaValue(m_ptr, "CBtActionAim", "m_bAcquired", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif