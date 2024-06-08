#include "../../../core/scripting/generated/classes/GC_OP_VectorNoise.h"
#include "../core.h"

void SetupLuaClassGC_OP_VectorNoise(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_VectorNoise>("C_OP_VectorNoise")
        .addProperty("FieldOutput", &GC_OP_VectorNoise::GetFieldOutput, &GC_OP_VectorNoise::SetFieldOutput)
        .addProperty("OutputMin", &GC_OP_VectorNoise::GetOutputMin, &GC_OP_VectorNoise::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_VectorNoise::GetOutputMax, &GC_OP_VectorNoise::SetOutputMax)
        .addProperty("4NoiseScale", &GC_OP_VectorNoise::Get4NoiseScale, &GC_OP_VectorNoise::Set4NoiseScale)
        .addProperty("Additive", &GC_OP_VectorNoise::GetAdditive, &GC_OP_VectorNoise::SetAdditive)
        .addProperty("Offset", &GC_OP_VectorNoise::GetOffset, &GC_OP_VectorNoise::SetOffset)
        .addProperty("NoiseAnimationTimeScale", &GC_OP_VectorNoise::GetNoiseAnimationTimeScale, &GC_OP_VectorNoise::SetNoiseAnimationTimeScale)
        .endClass();
}