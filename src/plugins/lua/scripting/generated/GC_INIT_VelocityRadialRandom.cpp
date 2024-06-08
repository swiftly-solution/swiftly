#include "../../../core/scripting/generated/classes/GC_INIT_VelocityRadialRandom.h"
#include "../core.h"

void SetupLuaClassGC_INIT_VelocityRadialRandom(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_VelocityRadialRandom>("C_INIT_VelocityRadialRandom")
        .addProperty("ControlPointNumber", &GC_INIT_VelocityRadialRandom::GetControlPointNumber, &GC_INIT_VelocityRadialRandom::SetControlPointNumber)
        .addProperty("SpeedMin", &GC_INIT_VelocityRadialRandom::GetSpeedMin, &GC_INIT_VelocityRadialRandom::SetSpeedMin)
        .addProperty("SpeedMax", &GC_INIT_VelocityRadialRandom::GetSpeedMax, &GC_INIT_VelocityRadialRandom::SetSpeedMax)
        .addProperty("LocalCoordinateSystemSpeedScale", &GC_INIT_VelocityRadialRandom::GetLocalCoordinateSystemSpeedScale, &GC_INIT_VelocityRadialRandom::SetLocalCoordinateSystemSpeedScale)
        .addProperty("IgnoreDelta", &GC_INIT_VelocityRadialRandom::GetIgnoreDelta, &GC_INIT_VelocityRadialRandom::SetIgnoreDelta)
        .endClass();
}