#include "../../../core/scripting/generated/classes/GC_OP_RampScalarSpline.h"
#include "../core.h"

void SetupLuaClassGC_OP_RampScalarSpline(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RampScalarSpline>("C_OP_RampScalarSpline")
        .addProperty("RateMin", &GC_OP_RampScalarSpline::GetRateMin, &GC_OP_RampScalarSpline::SetRateMin)
        .addProperty("RateMax", &GC_OP_RampScalarSpline::GetRateMax, &GC_OP_RampScalarSpline::SetRateMax)
        .addProperty("StartTime_min", &GC_OP_RampScalarSpline::GetStartTime_min, &GC_OP_RampScalarSpline::SetStartTime_min)
        .addProperty("StartTime_max", &GC_OP_RampScalarSpline::GetStartTime_max, &GC_OP_RampScalarSpline::SetStartTime_max)
        .addProperty("EndTime_min", &GC_OP_RampScalarSpline::GetEndTime_min, &GC_OP_RampScalarSpline::SetEndTime_min)
        .addProperty("EndTime_max", &GC_OP_RampScalarSpline::GetEndTime_max, &GC_OP_RampScalarSpline::SetEndTime_max)
        .addProperty("Bias", &GC_OP_RampScalarSpline::GetBias, &GC_OP_RampScalarSpline::SetBias)
        .addProperty("Field", &GC_OP_RampScalarSpline::GetField, &GC_OP_RampScalarSpline::SetField)
        .addProperty("ProportionalOp", &GC_OP_RampScalarSpline::GetProportionalOp, &GC_OP_RampScalarSpline::SetProportionalOp)
        .addProperty("EaseOut", &GC_OP_RampScalarSpline::GetEaseOut, &GC_OP_RampScalarSpline::SetEaseOut)
        .endClass();
}