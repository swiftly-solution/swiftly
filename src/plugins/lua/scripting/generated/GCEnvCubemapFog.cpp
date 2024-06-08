#include "../../../core/scripting/generated/classes/GCEnvCubemapFog.h"
#include "../core.h"

void SetupLuaClassGCEnvCubemapFog(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvCubemapFog>("CEnvCubemapFog")
        .addProperty("EndDistance", &GCEnvCubemapFog::GetEndDistance, &GCEnvCubemapFog::SetEndDistance)
        .addProperty("StartDistance", &GCEnvCubemapFog::GetStartDistance, &GCEnvCubemapFog::SetStartDistance)
        .addProperty("FogFalloffExponent", &GCEnvCubemapFog::GetFogFalloffExponent, &GCEnvCubemapFog::SetFogFalloffExponent)
        .addProperty("HeightFogEnabled", &GCEnvCubemapFog::GetHeightFogEnabled, &GCEnvCubemapFog::SetHeightFogEnabled)
        .addProperty("FogHeightWidth", &GCEnvCubemapFog::GetFogHeightWidth, &GCEnvCubemapFog::SetFogHeightWidth)
        .addProperty("FogHeightEnd", &GCEnvCubemapFog::GetFogHeightEnd, &GCEnvCubemapFog::SetFogHeightEnd)
        .addProperty("FogHeightStart", &GCEnvCubemapFog::GetFogHeightStart, &GCEnvCubemapFog::SetFogHeightStart)
        .addProperty("FogHeightExponent", &GCEnvCubemapFog::GetFogHeightExponent, &GCEnvCubemapFog::SetFogHeightExponent)
        .addProperty("LODBias", &GCEnvCubemapFog::GetLODBias, &GCEnvCubemapFog::SetLODBias)
        .addProperty("Active", &GCEnvCubemapFog::GetActive, &GCEnvCubemapFog::SetActive)
        .addProperty("StartDisabled", &GCEnvCubemapFog::GetStartDisabled, &GCEnvCubemapFog::SetStartDisabled)
        .addProperty("FogMaxOpacity", &GCEnvCubemapFog::GetFogMaxOpacity, &GCEnvCubemapFog::SetFogMaxOpacity)
        .addProperty("CubemapSourceType", &GCEnvCubemapFog::GetCubemapSourceType, &GCEnvCubemapFog::SetCubemapSourceType)
        .addProperty("SkyEntity", &GCEnvCubemapFog::GetSkyEntity, &GCEnvCubemapFog::SetSkyEntity)
        .addProperty("HasHeightFogEnd", &GCEnvCubemapFog::GetHasHeightFogEnd, &GCEnvCubemapFog::SetHasHeightFogEnd)
        .addProperty("FirstTime", &GCEnvCubemapFog::GetFirstTime, &GCEnvCubemapFog::SetFirstTime)
        .endClass();
}