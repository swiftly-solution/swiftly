#include "../../../core/scripting/generated/classes/GCPointVelocitySensor.h"
#include "../core.h"

void SetupLuaClassGCPointVelocitySensor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointVelocitySensor>("CPointVelocitySensor")
        .addProperty("TargetEntity", &GCPointVelocitySensor::GetTargetEntity, &GCPointVelocitySensor::SetTargetEntity)
        .addProperty("Axis", &GCPointVelocitySensor::GetAxis, &GCPointVelocitySensor::SetAxis)
        .addProperty("Enabled", &GCPointVelocitySensor::GetEnabled, &GCPointVelocitySensor::SetEnabled)
        .addProperty("PrevVelocity", &GCPointVelocitySensor::GetPrevVelocity, &GCPointVelocitySensor::SetPrevVelocity)
        .addProperty("AvgInterval", &GCPointVelocitySensor::GetAvgInterval, &GCPointVelocitySensor::SetAvgInterval)
        .endClass();
}