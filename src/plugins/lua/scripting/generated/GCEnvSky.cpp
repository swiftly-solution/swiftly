#include "../../../core/scripting/generated/classes/GCEnvSky.h"
#include "../core.h"

void SetupLuaClassGCEnvSky(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSky>("CEnvSky")
        .addProperty("StartDisabled", &GCEnvSky::GetStartDisabled, &GCEnvSky::SetStartDisabled)
        .addProperty("TintColor", &GCEnvSky::GetTintColor, &GCEnvSky::SetTintColor)
        .addProperty("TintColorLightingOnly", &GCEnvSky::GetTintColorLightingOnly, &GCEnvSky::SetTintColorLightingOnly)
        .addProperty("BrightnessScale", &GCEnvSky::GetBrightnessScale, &GCEnvSky::SetBrightnessScale)
        .addProperty("FogType", &GCEnvSky::GetFogType, &GCEnvSky::SetFogType)
        .addProperty("FogMinStart", &GCEnvSky::GetFogMinStart, &GCEnvSky::SetFogMinStart)
        .addProperty("FogMinEnd", &GCEnvSky::GetFogMinEnd, &GCEnvSky::SetFogMinEnd)
        .addProperty("FogMaxStart", &GCEnvSky::GetFogMaxStart, &GCEnvSky::SetFogMaxStart)
        .addProperty("FogMaxEnd", &GCEnvSky::GetFogMaxEnd, &GCEnvSky::SetFogMaxEnd)
        .addProperty("Enabled", &GCEnvSky::GetEnabled, &GCEnvSky::SetEnabled)
        .endClass();
}