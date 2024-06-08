#include "../../../core/scripting/generated/classes/GC_INIT_CreationNoise.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreationNoise(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreationNoise>("C_INIT_CreationNoise")
        .addProperty("FieldOutput", &GC_INIT_CreationNoise::GetFieldOutput, &GC_INIT_CreationNoise::SetFieldOutput)
        .addProperty("AbsVal", &GC_INIT_CreationNoise::GetAbsVal, &GC_INIT_CreationNoise::SetAbsVal)
        .addProperty("AbsValInv", &GC_INIT_CreationNoise::GetAbsValInv, &GC_INIT_CreationNoise::SetAbsValInv)
        .addProperty("Offset", &GC_INIT_CreationNoise::GetOffset, &GC_INIT_CreationNoise::SetOffset)
        .addProperty("OutputMin", &GC_INIT_CreationNoise::GetOutputMin, &GC_INIT_CreationNoise::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_CreationNoise::GetOutputMax, &GC_INIT_CreationNoise::SetOutputMax)
        .addProperty("NoiseScale", &GC_INIT_CreationNoise::GetNoiseScale, &GC_INIT_CreationNoise::SetNoiseScale)
        .addProperty("NoiseScaleLoc", &GC_INIT_CreationNoise::GetNoiseScaleLoc, &GC_INIT_CreationNoise::SetNoiseScaleLoc)
        .addProperty("OffsetLoc", &GC_INIT_CreationNoise::GetOffsetLoc, &GC_INIT_CreationNoise::SetOffsetLoc)
        .addProperty("WorldTimeScale", &GC_INIT_CreationNoise::GetWorldTimeScale, &GC_INIT_CreationNoise::SetWorldTimeScale)
        .endClass();
}