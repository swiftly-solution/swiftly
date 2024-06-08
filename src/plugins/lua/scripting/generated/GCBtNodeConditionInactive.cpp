#include "../../../core/scripting/generated/classes/GCBtNodeConditionInactive.h"
#include "../core.h"

void SetupLuaClassGCBtNodeConditionInactive(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtNodeConditionInactive>("CBtNodeConditionInactive")
        .addProperty("RoundStartThresholdSeconds", &GCBtNodeConditionInactive::GetRoundStartThresholdSeconds, &GCBtNodeConditionInactive::SetRoundStartThresholdSeconds)
        .addProperty("SensorInactivityThresholdSeconds", &GCBtNodeConditionInactive::GetSensorInactivityThresholdSeconds, &GCBtNodeConditionInactive::SetSensorInactivityThresholdSeconds)
        .addProperty("SensorInactivityTimer", &GCBtNodeConditionInactive::GetSensorInactivityTimer, &GCBtNodeConditionInactive::SetSensorInactivityTimer)
        .endClass();
}