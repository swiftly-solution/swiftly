#include "../../../core/scripting/generated/classes/GC_OP_OscillateVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_OscillateVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_OscillateVector>("C_OP_OscillateVector")
        .addProperty("RateMin", &GC_OP_OscillateVector::GetRateMin, &GC_OP_OscillateVector::SetRateMin)
        .addProperty("RateMax", &GC_OP_OscillateVector::GetRateMax, &GC_OP_OscillateVector::SetRateMax)
        .addProperty("FrequencyMin", &GC_OP_OscillateVector::GetFrequencyMin, &GC_OP_OscillateVector::SetFrequencyMin)
        .addProperty("FrequencyMax", &GC_OP_OscillateVector::GetFrequencyMax, &GC_OP_OscillateVector::SetFrequencyMax)
        .addProperty("Field", &GC_OP_OscillateVector::GetField, &GC_OP_OscillateVector::SetField)
        .addProperty("Proportional", &GC_OP_OscillateVector::GetProportional, &GC_OP_OscillateVector::SetProportional)
        .addProperty("ProportionalOp", &GC_OP_OscillateVector::GetProportionalOp, &GC_OP_OscillateVector::SetProportionalOp)
        .addProperty("Offset", &GC_OP_OscillateVector::GetOffset, &GC_OP_OscillateVector::SetOffset)
        .addProperty("StartTime_min", &GC_OP_OscillateVector::GetStartTime_min, &GC_OP_OscillateVector::SetStartTime_min)
        .addProperty("StartTime_max", &GC_OP_OscillateVector::GetStartTime_max, &GC_OP_OscillateVector::SetStartTime_max)
        .addProperty("EndTime_min", &GC_OP_OscillateVector::GetEndTime_min, &GC_OP_OscillateVector::SetEndTime_min)
        .addProperty("EndTime_max", &GC_OP_OscillateVector::GetEndTime_max, &GC_OP_OscillateVector::SetEndTime_max)
        .addProperty("OscMult", &GC_OP_OscillateVector::GetOscMult, &GC_OP_OscillateVector::SetOscMult)
        .addProperty("OscAdd", &GC_OP_OscillateVector::GetOscAdd, &GC_OP_OscillateVector::SetOscAdd)
        .addProperty("RateScale", &GC_OP_OscillateVector::GetRateScale, &GC_OP_OscillateVector::SetRateScale)
        .endClass();
}