#include "../../../core/scripting/generated/classes/GC_INIT_VelocityRandom.h"
#include "../core.h"

void SetupLuaClassGC_INIT_VelocityRandom(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_VelocityRandom>("C_INIT_VelocityRandom")
        .addProperty("ControlPointNumber", &GC_INIT_VelocityRandom::GetControlPointNumber, &GC_INIT_VelocityRandom::SetControlPointNumber)
        .addProperty("SpeedMin", &GC_INIT_VelocityRandom::GetSpeedMin, &GC_INIT_VelocityRandom::SetSpeedMin)
        .addProperty("SpeedMax", &GC_INIT_VelocityRandom::GetSpeedMax, &GC_INIT_VelocityRandom::SetSpeedMax)
        .addProperty("LocalCoordinateSystemSpeedMin", &GC_INIT_VelocityRandom::GetLocalCoordinateSystemSpeedMin, &GC_INIT_VelocityRandom::SetLocalCoordinateSystemSpeedMin)
        .addProperty("LocalCoordinateSystemSpeedMax", &GC_INIT_VelocityRandom::GetLocalCoordinateSystemSpeedMax, &GC_INIT_VelocityRandom::SetLocalCoordinateSystemSpeedMax)
        .addProperty("IgnoreDT", &GC_INIT_VelocityRandom::GetIgnoreDT, &GC_INIT_VelocityRandom::SetIgnoreDT)
        .addProperty("RandomnessParameters", &GC_INIT_VelocityRandom::GetRandomnessParameters, &GC_INIT_VelocityRandom::SetRandomnessParameters)
        .endClass();
}