#include "../../../core/scripting/generated/classes/GC_INIT_RemapSpeedToScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapSpeedToScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapSpeedToScalar>("C_INIT_RemapSpeedToScalar")
        .addProperty("FieldOutput", &GC_INIT_RemapSpeedToScalar::GetFieldOutput, &GC_INIT_RemapSpeedToScalar::SetFieldOutput)
        .addProperty("ControlPointNumber", &GC_INIT_RemapSpeedToScalar::GetControlPointNumber, &GC_INIT_RemapSpeedToScalar::SetControlPointNumber)
        .addProperty("StartTime", &GC_INIT_RemapSpeedToScalar::GetStartTime, &GC_INIT_RemapSpeedToScalar::SetStartTime)
        .addProperty("EndTime", &GC_INIT_RemapSpeedToScalar::GetEndTime, &GC_INIT_RemapSpeedToScalar::SetEndTime)
        .addProperty("InputMin", &GC_INIT_RemapSpeedToScalar::GetInputMin, &GC_INIT_RemapSpeedToScalar::SetInputMin)
        .addProperty("InputMax", &GC_INIT_RemapSpeedToScalar::GetInputMax, &GC_INIT_RemapSpeedToScalar::SetInputMax)
        .addProperty("OutputMin", &GC_INIT_RemapSpeedToScalar::GetOutputMin, &GC_INIT_RemapSpeedToScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_RemapSpeedToScalar::GetOutputMax, &GC_INIT_RemapSpeedToScalar::SetOutputMax)
        .addProperty("SetMethod", &GC_INIT_RemapSpeedToScalar::GetSetMethod, &GC_INIT_RemapSpeedToScalar::SetSetMethod)
        .addProperty("PerParticle", &GC_INIT_RemapSpeedToScalar::GetPerParticle, &GC_INIT_RemapSpeedToScalar::SetPerParticle)
        .endClass();
}