#include "../../../core/scripting/generated/classes/GC_INIT_RingWave.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RingWave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RingWave>("C_INIT_RingWave")
        .addProperty("TransformInput", &GC_INIT_RingWave::GetTransformInput, &GC_INIT_RingWave::SetTransformInput)
        .addProperty("ParticlesPerOrbit", &GC_INIT_RingWave::GetParticlesPerOrbit, &GC_INIT_RingWave::SetParticlesPerOrbit)
        .addProperty("InitialRadius", &GC_INIT_RingWave::GetInitialRadius, &GC_INIT_RingWave::SetInitialRadius)
        .addProperty("Thickness", &GC_INIT_RingWave::GetThickness, &GC_INIT_RingWave::SetThickness)
        .addProperty("InitialSpeedMin", &GC_INIT_RingWave::GetInitialSpeedMin, &GC_INIT_RingWave::SetInitialSpeedMin)
        .addProperty("InitialSpeedMax", &GC_INIT_RingWave::GetInitialSpeedMax, &GC_INIT_RingWave::SetInitialSpeedMax)
        .addProperty("Roll", &GC_INIT_RingWave::GetRoll, &GC_INIT_RingWave::SetRoll)
        .addProperty("Pitch", &GC_INIT_RingWave::GetPitch, &GC_INIT_RingWave::SetPitch)
        .addProperty("Yaw", &GC_INIT_RingWave::GetYaw, &GC_INIT_RingWave::SetYaw)
        .addProperty("EvenDistribution", &GC_INIT_RingWave::GetEvenDistribution, &GC_INIT_RingWave::SetEvenDistribution)
        .addProperty("XYVelocityOnly", &GC_INIT_RingWave::GetXYVelocityOnly, &GC_INIT_RingWave::SetXYVelocityOnly)
        .endClass();
}