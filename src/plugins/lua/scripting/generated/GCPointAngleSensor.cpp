#include "../../../core/scripting/generated/classes/GCPointAngleSensor.h"
#include "../core.h"

void SetupLuaClassGCPointAngleSensor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointAngleSensor>("CPointAngleSensor")
        .addProperty("Disabled", &GCPointAngleSensor::GetDisabled, &GCPointAngleSensor::SetDisabled)
        .addProperty("LookAtName", &GCPointAngleSensor::GetLookAtName, &GCPointAngleSensor::SetLookAtName)
        .addProperty("TargetEntity", &GCPointAngleSensor::GetTargetEntity, &GCPointAngleSensor::SetTargetEntity)
        .addProperty("LookAtEntity", &GCPointAngleSensor::GetLookAtEntity, &GCPointAngleSensor::SetLookAtEntity)
        .addProperty("Duration", &GCPointAngleSensor::GetDuration, &GCPointAngleSensor::SetDuration)
        .addProperty("DotTolerance", &GCPointAngleSensor::GetDotTolerance, &GCPointAngleSensor::SetDotTolerance)
        .addProperty("Fired", &GCPointAngleSensor::GetFired, &GCPointAngleSensor::SetFired)
        .addProperty("OnFacingLookat", &GCPointAngleSensor::GetOnFacingLookat, &GCPointAngleSensor::SetOnFacingLookat)
        .addProperty("OnNotFacingLookat", &GCPointAngleSensor::GetOnNotFacingLookat, &GCPointAngleSensor::SetOnNotFacingLookat)
        .endClass();
}