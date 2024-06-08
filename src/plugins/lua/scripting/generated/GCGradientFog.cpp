#include "../../../core/scripting/generated/classes/GCGradientFog.h"
#include "../core.h"

void SetupLuaClassGCGradientFog(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGradientFog>("CGradientFog")
        .addProperty("FogStartDistance", &GCGradientFog::GetFogStartDistance, &GCGradientFog::SetFogStartDistance)
        .addProperty("FogEndDistance", &GCGradientFog::GetFogEndDistance, &GCGradientFog::SetFogEndDistance)
        .addProperty("HeightFogEnabled", &GCGradientFog::GetHeightFogEnabled, &GCGradientFog::SetHeightFogEnabled)
        .addProperty("FogStartHeight", &GCGradientFog::GetFogStartHeight, &GCGradientFog::SetFogStartHeight)
        .addProperty("FogEndHeight", &GCGradientFog::GetFogEndHeight, &GCGradientFog::SetFogEndHeight)
        .addProperty("FarZ", &GCGradientFog::GetFarZ, &GCGradientFog::SetFarZ)
        .addProperty("FogMaxOpacity", &GCGradientFog::GetFogMaxOpacity, &GCGradientFog::SetFogMaxOpacity)
        .addProperty("FogFalloffExponent", &GCGradientFog::GetFogFalloffExponent, &GCGradientFog::SetFogFalloffExponent)
        .addProperty("FogVerticalExponent", &GCGradientFog::GetFogVerticalExponent, &GCGradientFog::SetFogVerticalExponent)
        .addProperty("FogColor", &GCGradientFog::GetFogColor, &GCGradientFog::SetFogColor)
        .addProperty("FogStrength", &GCGradientFog::GetFogStrength, &GCGradientFog::SetFogStrength)
        .addProperty("FadeTime", &GCGradientFog::GetFadeTime, &GCGradientFog::SetFadeTime)
        .addProperty("StartDisabled", &GCGradientFog::GetStartDisabled, &GCGradientFog::SetStartDisabled)
        .addProperty("IsEnabled", &GCGradientFog::GetIsEnabled, &GCGradientFog::SetIsEnabled)
        .addProperty("GradientFogNeedsTextures", &GCGradientFog::GetGradientFogNeedsTextures, &GCGradientFog::SetGradientFogNeedsTextures)
        .endClass();
}