#include "../../../core/scripting/generated/classes/GC_OP_Noise.h"
#include "../core.h"

void SetupLuaClassGC_OP_Noise(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_Noise>("C_OP_Noise")
        .addProperty("FieldOutput", &GC_OP_Noise::GetFieldOutput, &GC_OP_Noise::SetFieldOutput)
        .addProperty("OutputMin", &GC_OP_Noise::GetOutputMin, &GC_OP_Noise::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_Noise::GetOutputMax, &GC_OP_Noise::SetOutputMax)
        .addProperty("4NoiseScale", &GC_OP_Noise::Get4NoiseScale, &GC_OP_Noise::Set4NoiseScale)
        .addProperty("Additive", &GC_OP_Noise::GetAdditive, &GC_OP_Noise::SetAdditive)
        .addProperty("NoiseAnimationTimeScale", &GC_OP_Noise::GetNoiseAnimationTimeScale, &GC_OP_Noise::SetNoiseAnimationTimeScale)
        .endClass();
}