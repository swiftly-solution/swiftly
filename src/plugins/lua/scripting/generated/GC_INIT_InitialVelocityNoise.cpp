#include "../../../core/scripting/generated/classes/GC_INIT_InitialVelocityNoise.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitialVelocityNoise(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitialVelocityNoise>("C_INIT_InitialVelocityNoise")
        .addProperty("AbsVal", &GC_INIT_InitialVelocityNoise::GetAbsVal, &GC_INIT_InitialVelocityNoise::SetAbsVal)
        .addProperty("AbsValInv", &GC_INIT_InitialVelocityNoise::GetAbsValInv, &GC_INIT_InitialVelocityNoise::SetAbsValInv)
        .addProperty("OffsetLoc", &GC_INIT_InitialVelocityNoise::GetOffsetLoc, &GC_INIT_InitialVelocityNoise::SetOffsetLoc)
        .addProperty("Offset", &GC_INIT_InitialVelocityNoise::GetOffset, &GC_INIT_InitialVelocityNoise::SetOffset)
        .addProperty("OutputMin", &GC_INIT_InitialVelocityNoise::GetOutputMin, &GC_INIT_InitialVelocityNoise::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_InitialVelocityNoise::GetOutputMax, &GC_INIT_InitialVelocityNoise::SetOutputMax)
        .addProperty("NoiseScale", &GC_INIT_InitialVelocityNoise::GetNoiseScale, &GC_INIT_InitialVelocityNoise::SetNoiseScale)
        .addProperty("NoiseScaleLoc", &GC_INIT_InitialVelocityNoise::GetNoiseScaleLoc, &GC_INIT_InitialVelocityNoise::SetNoiseScaleLoc)
        .addProperty("TransformInput", &GC_INIT_InitialVelocityNoise::GetTransformInput, &GC_INIT_InitialVelocityNoise::SetTransformInput)
        .addProperty("IgnoreDt", &GC_INIT_InitialVelocityNoise::GetIgnoreDt, &GC_INIT_InitialVelocityNoise::SetIgnoreDt)
        .endClass();
}