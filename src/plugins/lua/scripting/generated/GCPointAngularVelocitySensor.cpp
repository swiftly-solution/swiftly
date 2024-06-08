#include "../../../core/scripting/generated/classes/GCPointAngularVelocitySensor.h"
#include "../core.h"

void SetupLuaClassGCPointAngularVelocitySensor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointAngularVelocitySensor>("CPointAngularVelocitySensor")
        .addProperty("TargetEntity", &GCPointAngularVelocitySensor::GetTargetEntity, &GCPointAngularVelocitySensor::SetTargetEntity)
        .addProperty("Threshold", &GCPointAngularVelocitySensor::GetThreshold, &GCPointAngularVelocitySensor::SetThreshold)
        .addProperty("LastCompareResult", &GCPointAngularVelocitySensor::GetLastCompareResult, &GCPointAngularVelocitySensor::SetLastCompareResult)
        .addProperty("LastFireResult", &GCPointAngularVelocitySensor::GetLastFireResult, &GCPointAngularVelocitySensor::SetLastFireResult)
        .addProperty("FireInterval", &GCPointAngularVelocitySensor::GetFireInterval, &GCPointAngularVelocitySensor::SetFireInterval)
        .addProperty("LastAngVelocity", &GCPointAngularVelocitySensor::GetLastAngVelocity, &GCPointAngularVelocitySensor::SetLastAngVelocity)
        .addProperty("LastOrientation", &GCPointAngularVelocitySensor::GetLastOrientation, &GCPointAngularVelocitySensor::SetLastOrientation)
        .addProperty("Axis", &GCPointAngularVelocitySensor::GetAxis, &GCPointAngularVelocitySensor::SetAxis)
        .addProperty("UseHelper", &GCPointAngularVelocitySensor::GetUseHelper, &GCPointAngularVelocitySensor::SetUseHelper)
        .addProperty("OnLessThan", &GCPointAngularVelocitySensor::GetOnLessThan, &GCPointAngularVelocitySensor::SetOnLessThan)
        .addProperty("OnLessThanOrEqualTo", &GCPointAngularVelocitySensor::GetOnLessThanOrEqualTo, &GCPointAngularVelocitySensor::SetOnLessThanOrEqualTo)
        .addProperty("OnGreaterThan", &GCPointAngularVelocitySensor::GetOnGreaterThan, &GCPointAngularVelocitySensor::SetOnGreaterThan)
        .addProperty("OnGreaterThanOrEqualTo", &GCPointAngularVelocitySensor::GetOnGreaterThanOrEqualTo, &GCPointAngularVelocitySensor::SetOnGreaterThanOrEqualTo)
        .addProperty("OnEqualTo", &GCPointAngularVelocitySensor::GetOnEqualTo, &GCPointAngularVelocitySensor::SetOnEqualTo)
        .endClass();
}