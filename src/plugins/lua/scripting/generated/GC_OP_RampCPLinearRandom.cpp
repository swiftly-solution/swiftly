#include "../../../core/scripting/generated/classes/GC_OP_RampCPLinearRandom.h"
#include "../core.h"

void SetupLuaClassGC_OP_RampCPLinearRandom(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RampCPLinearRandom>("C_OP_RampCPLinearRandom")
        .addProperty("OutControlPointNumber", &GC_OP_RampCPLinearRandom::GetOutControlPointNumber, &GC_OP_RampCPLinearRandom::SetOutControlPointNumber)
        .addProperty("RateMin", &GC_OP_RampCPLinearRandom::GetRateMin, &GC_OP_RampCPLinearRandom::SetRateMin)
        .addProperty("RateMax", &GC_OP_RampCPLinearRandom::GetRateMax, &GC_OP_RampCPLinearRandom::SetRateMax)
        .endClass();
}