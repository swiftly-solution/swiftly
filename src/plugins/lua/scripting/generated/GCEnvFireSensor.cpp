#include "../../../core/scripting/generated/classes/GCEnvFireSensor.h"
#include "../core.h"

void SetupLuaClassGCEnvFireSensor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvFireSensor>("CEnvFireSensor")
        .addProperty("Enabled", &GCEnvFireSensor::GetEnabled, &GCEnvFireSensor::SetEnabled)
        .addProperty("HeatAtLevel", &GCEnvFireSensor::GetHeatAtLevel, &GCEnvFireSensor::SetHeatAtLevel)
        .addProperty("Radius", &GCEnvFireSensor::GetRadius, &GCEnvFireSensor::SetRadius)
        .addProperty("TargetLevel", &GCEnvFireSensor::GetTargetLevel, &GCEnvFireSensor::SetTargetLevel)
        .addProperty("TargetTime", &GCEnvFireSensor::GetTargetTime, &GCEnvFireSensor::SetTargetTime)
        .addProperty("LevelTime", &GCEnvFireSensor::GetLevelTime, &GCEnvFireSensor::SetLevelTime)
        .addProperty("OnHeatLevelStart", &GCEnvFireSensor::GetOnHeatLevelStart, &GCEnvFireSensor::SetOnHeatLevelStart)
        .addProperty("OnHeatLevelEnd", &GCEnvFireSensor::GetOnHeatLevelEnd, &GCEnvFireSensor::SetOnHeatLevelEnd)
        .endClass();
}