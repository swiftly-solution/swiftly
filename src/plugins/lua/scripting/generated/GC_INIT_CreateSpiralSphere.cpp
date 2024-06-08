#include "../../../core/scripting/generated/classes/GC_INIT_CreateSpiralSphere.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateSpiralSphere(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateSpiralSphere>("C_INIT_CreateSpiralSphere")
        .addProperty("ControlPointNumber", &GC_INIT_CreateSpiralSphere::GetControlPointNumber, &GC_INIT_CreateSpiralSphere::SetControlPointNumber)
        .addProperty("OverrideCP", &GC_INIT_CreateSpiralSphere::GetOverrideCP, &GC_INIT_CreateSpiralSphere::SetOverrideCP)
        .addProperty("Density", &GC_INIT_CreateSpiralSphere::GetDensity, &GC_INIT_CreateSpiralSphere::SetDensity)
        .addProperty("InitialRadius", &GC_INIT_CreateSpiralSphere::GetInitialRadius, &GC_INIT_CreateSpiralSphere::SetInitialRadius)
        .addProperty("InitialSpeedMin", &GC_INIT_CreateSpiralSphere::GetInitialSpeedMin, &GC_INIT_CreateSpiralSphere::SetInitialSpeedMin)
        .addProperty("InitialSpeedMax", &GC_INIT_CreateSpiralSphere::GetInitialSpeedMax, &GC_INIT_CreateSpiralSphere::SetInitialSpeedMax)
        .addProperty("UseParticleCount", &GC_INIT_CreateSpiralSphere::GetUseParticleCount, &GC_INIT_CreateSpiralSphere::SetUseParticleCount)
        .endClass();
}