#include "../../../core/scripting/generated/classes/GCBtActionAim.h"
#include "../core.h"

void SetupLuaClassGCBtActionAim(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtActionAim>("CBtActionAim")
        .addProperty("SensorInputKey", &GCBtActionAim::GetSensorInputKey, &GCBtActionAim::SetSensorInputKey)
        .addProperty("AimReadyKey", &GCBtActionAim::GetAimReadyKey, &GCBtActionAim::SetAimReadyKey)
        .addProperty("ZoomCooldownTimestamp", &GCBtActionAim::GetZoomCooldownTimestamp, &GCBtActionAim::SetZoomCooldownTimestamp)
        .addProperty("DoneAiming", &GCBtActionAim::GetDoneAiming, &GCBtActionAim::SetDoneAiming)
        .addProperty("LerpStartTime", &GCBtActionAim::GetLerpStartTime, &GCBtActionAim::SetLerpStartTime)
        .addProperty("NextLookTargetLerpTime", &GCBtActionAim::GetNextLookTargetLerpTime, &GCBtActionAim::SetNextLookTargetLerpTime)
        .addProperty("PenaltyReductionRatio", &GCBtActionAim::GetPenaltyReductionRatio, &GCBtActionAim::SetPenaltyReductionRatio)
        .addProperty("NextLookTarget", &GCBtActionAim::GetNextLookTarget, &GCBtActionAim::SetNextLookTarget)
        .addProperty("AimTimer", &GCBtActionAim::GetAimTimer, &GCBtActionAim::SetAimTimer)
        .addProperty("SniperHoldTimer", &GCBtActionAim::GetSniperHoldTimer, &GCBtActionAim::SetSniperHoldTimer)
        .addProperty("FocusIntervalTimer", &GCBtActionAim::GetFocusIntervalTimer, &GCBtActionAim::SetFocusIntervalTimer)
        .addProperty("Acquired", &GCBtActionAim::GetAcquired, &GCBtActionAim::SetAcquired)
        .endClass();
}