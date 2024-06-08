#include "../../../core/scripting/generated/classes/GC_INIT_AgeNoise.h"
#include "../core.h"

void SetupLuaClassGC_INIT_AgeNoise(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_AgeNoise>("C_INIT_AgeNoise")
        .addProperty("AbsVal", &GC_INIT_AgeNoise::GetAbsVal, &GC_INIT_AgeNoise::SetAbsVal)
        .addProperty("AbsValInv", &GC_INIT_AgeNoise::GetAbsValInv, &GC_INIT_AgeNoise::SetAbsValInv)
        .addProperty("Offset", &GC_INIT_AgeNoise::GetOffset, &GC_INIT_AgeNoise::SetOffset)
        .addProperty("AgeMin", &GC_INIT_AgeNoise::GetAgeMin, &GC_INIT_AgeNoise::SetAgeMin)
        .addProperty("AgeMax", &GC_INIT_AgeNoise::GetAgeMax, &GC_INIT_AgeNoise::SetAgeMax)
        .addProperty("NoiseScale", &GC_INIT_AgeNoise::GetNoiseScale, &GC_INIT_AgeNoise::SetNoiseScale)
        .addProperty("NoiseScaleLoc", &GC_INIT_AgeNoise::GetNoiseScaleLoc, &GC_INIT_AgeNoise::SetNoiseScaleLoc)
        .addProperty("OffsetLoc", &GC_INIT_AgeNoise::GetOffsetLoc, &GC_INIT_AgeNoise::SetOffsetLoc)
        .endClass();
}