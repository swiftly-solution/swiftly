#include "../../../core/scripting/generated/classes/GC_OP_OscillateScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_OscillateScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_OscillateScalar>("C_OP_OscillateScalar")
        .addProperty("RateMin", &GC_OP_OscillateScalar::GetRateMin, &GC_OP_OscillateScalar::SetRateMin)
        .addProperty("RateMax", &GC_OP_OscillateScalar::GetRateMax, &GC_OP_OscillateScalar::SetRateMax)
        .addProperty("FrequencyMin", &GC_OP_OscillateScalar::GetFrequencyMin, &GC_OP_OscillateScalar::SetFrequencyMin)
        .addProperty("FrequencyMax", &GC_OP_OscillateScalar::GetFrequencyMax, &GC_OP_OscillateScalar::SetFrequencyMax)
        .addProperty("Field", &GC_OP_OscillateScalar::GetField, &GC_OP_OscillateScalar::SetField)
        .addProperty("Proportional", &GC_OP_OscillateScalar::GetProportional, &GC_OP_OscillateScalar::SetProportional)
        .addProperty("ProportionalOp", &GC_OP_OscillateScalar::GetProportionalOp, &GC_OP_OscillateScalar::SetProportionalOp)
        .addProperty("StartTime_min", &GC_OP_OscillateScalar::GetStartTime_min, &GC_OP_OscillateScalar::SetStartTime_min)
        .addProperty("StartTime_max", &GC_OP_OscillateScalar::GetStartTime_max, &GC_OP_OscillateScalar::SetStartTime_max)
        .addProperty("EndTime_min", &GC_OP_OscillateScalar::GetEndTime_min, &GC_OP_OscillateScalar::SetEndTime_min)
        .addProperty("EndTime_max", &GC_OP_OscillateScalar::GetEndTime_max, &GC_OP_OscillateScalar::SetEndTime_max)
        .addProperty("OscMult", &GC_OP_OscillateScalar::GetOscMult, &GC_OP_OscillateScalar::SetOscMult)
        .addProperty("OscAdd", &GC_OP_OscillateScalar::GetOscAdd, &GC_OP_OscillateScalar::SetOscAdd)
        .endClass();
}