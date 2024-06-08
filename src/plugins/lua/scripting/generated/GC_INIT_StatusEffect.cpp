#include "../../../core/scripting/generated/classes/GC_INIT_StatusEffect.h"
#include "../core.h"

void SetupLuaClassGC_INIT_StatusEffect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_StatusEffect>("C_INIT_StatusEffect")
        .addProperty("Detail2Combo", &GC_INIT_StatusEffect::GetDetail2Combo, &GC_INIT_StatusEffect::SetDetail2Combo)
        .addProperty("Detail2Rotation", &GC_INIT_StatusEffect::GetDetail2Rotation, &GC_INIT_StatusEffect::SetDetail2Rotation)
        .addProperty("Detail2Scale", &GC_INIT_StatusEffect::GetDetail2Scale, &GC_INIT_StatusEffect::SetDetail2Scale)
        .addProperty("Detail2BlendFactor", &GC_INIT_StatusEffect::GetDetail2BlendFactor, &GC_INIT_StatusEffect::SetDetail2BlendFactor)
        .addProperty("ColorWarpIntensity", &GC_INIT_StatusEffect::GetColorWarpIntensity, &GC_INIT_StatusEffect::SetColorWarpIntensity)
        .addProperty("DiffuseWarpBlendToFull", &GC_INIT_StatusEffect::GetDiffuseWarpBlendToFull, &GC_INIT_StatusEffect::SetDiffuseWarpBlendToFull)
        .addProperty("EnvMapIntensity", &GC_INIT_StatusEffect::GetEnvMapIntensity, &GC_INIT_StatusEffect::SetEnvMapIntensity)
        .addProperty("AmbientScale", &GC_INIT_StatusEffect::GetAmbientScale, &GC_INIT_StatusEffect::SetAmbientScale)
        .addProperty("SpecularColor", &GC_INIT_StatusEffect::GetSpecularColor, &GC_INIT_StatusEffect::SetSpecularColor)
        .addProperty("SpecularScale", &GC_INIT_StatusEffect::GetSpecularScale, &GC_INIT_StatusEffect::SetSpecularScale)
        .addProperty("SpecularExponent", &GC_INIT_StatusEffect::GetSpecularExponent, &GC_INIT_StatusEffect::SetSpecularExponent)
        .addProperty("SpecularExponentBlendToFull", &GC_INIT_StatusEffect::GetSpecularExponentBlendToFull, &GC_INIT_StatusEffect::SetSpecularExponentBlendToFull)
        .addProperty("SpecularBlendToFull", &GC_INIT_StatusEffect::GetSpecularBlendToFull, &GC_INIT_StatusEffect::SetSpecularBlendToFull)
        .addProperty("RimLightColor", &GC_INIT_StatusEffect::GetRimLightColor, &GC_INIT_StatusEffect::SetRimLightColor)
        .addProperty("RimLightScale", &GC_INIT_StatusEffect::GetRimLightScale, &GC_INIT_StatusEffect::SetRimLightScale)
        .addProperty("ReflectionsTintByBaseBlendToNone", &GC_INIT_StatusEffect::GetReflectionsTintByBaseBlendToNone, &GC_INIT_StatusEffect::SetReflectionsTintByBaseBlendToNone)
        .addProperty("MetalnessBlendToFull", &GC_INIT_StatusEffect::GetMetalnessBlendToFull, &GC_INIT_StatusEffect::SetMetalnessBlendToFull)
        .addProperty("SelfIllumBlendToFull", &GC_INIT_StatusEffect::GetSelfIllumBlendToFull, &GC_INIT_StatusEffect::SetSelfIllumBlendToFull)
        .endClass();
}