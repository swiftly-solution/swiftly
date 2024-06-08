#include "../../../core/scripting/generated/classes/GC_OP_RampScalarLinear.h"
#include "../core.h"

void SetupLuaClassGC_OP_RampScalarLinear(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RampScalarLinear>("C_OP_RampScalarLinear")
        .addProperty("RateMin", &GC_OP_RampScalarLinear::GetRateMin, &GC_OP_RampScalarLinear::SetRateMin)
        .addProperty("RateMax", &GC_OP_RampScalarLinear::GetRateMax, &GC_OP_RampScalarLinear::SetRateMax)
        .addProperty("StartTime_min", &GC_OP_RampScalarLinear::GetStartTime_min, &GC_OP_RampScalarLinear::SetStartTime_min)
        .addProperty("StartTime_max", &GC_OP_RampScalarLinear::GetStartTime_max, &GC_OP_RampScalarLinear::SetStartTime_max)
        .addProperty("EndTime_min", &GC_OP_RampScalarLinear::GetEndTime_min, &GC_OP_RampScalarLinear::SetEndTime_min)
        .addProperty("EndTime_max", &GC_OP_RampScalarLinear::GetEndTime_max, &GC_OP_RampScalarLinear::SetEndTime_max)
        .addProperty("Field", &GC_OP_RampScalarLinear::GetField, &GC_OP_RampScalarLinear::SetField)
        .addProperty("ProportionalOp", &GC_OP_RampScalarLinear::GetProportionalOp, &GC_OP_RampScalarLinear::SetProportionalOp)
        .endClass();
}