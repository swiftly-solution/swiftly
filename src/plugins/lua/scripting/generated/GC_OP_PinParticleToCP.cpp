#include "../../../core/scripting/generated/classes/GC_OP_PinParticleToCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_PinParticleToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_PinParticleToCP>("C_OP_PinParticleToCP")
        .addProperty("ControlPointNumber", &GC_OP_PinParticleToCP::GetControlPointNumber, &GC_OP_PinParticleToCP::SetControlPointNumber)
        .addProperty("OffsetLocal", &GC_OP_PinParticleToCP::GetOffsetLocal, &GC_OP_PinParticleToCP::SetOffsetLocal)
        .addProperty("ParticleSelection", &GC_OP_PinParticleToCP::GetParticleSelection, &GC_OP_PinParticleToCP::SetParticleSelection)
        .addProperty("ParticleNumber", &GC_OP_PinParticleToCP::GetParticleNumber, &GC_OP_PinParticleToCP::SetParticleNumber)
        .addProperty("PinBreakType", &GC_OP_PinParticleToCP::GetPinBreakType, &GC_OP_PinParticleToCP::SetPinBreakType)
        .addProperty("BreakDistance", &GC_OP_PinParticleToCP::GetBreakDistance, &GC_OP_PinParticleToCP::SetBreakDistance)
        .addProperty("BreakSpeed", &GC_OP_PinParticleToCP::GetBreakSpeed, &GC_OP_PinParticleToCP::SetBreakSpeed)
        .addProperty("Age", &GC_OP_PinParticleToCP::GetAge, &GC_OP_PinParticleToCP::SetAge)
        .addProperty("BreakControlPointNumber", &GC_OP_PinParticleToCP::GetBreakControlPointNumber, &GC_OP_PinParticleToCP::SetBreakControlPointNumber)
        .addProperty("BreakControlPointNumber2", &GC_OP_PinParticleToCP::GetBreakControlPointNumber2, &GC_OP_PinParticleToCP::SetBreakControlPointNumber2)
        .addProperty("BreakValue", &GC_OP_PinParticleToCP::GetBreakValue, &GC_OP_PinParticleToCP::SetBreakValue)
        .addProperty("Interpolation", &GC_OP_PinParticleToCP::GetInterpolation, &GC_OP_PinParticleToCP::SetInterpolation)
        .endClass();
}