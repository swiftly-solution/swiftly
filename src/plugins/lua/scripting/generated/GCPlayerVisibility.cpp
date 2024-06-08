#include "../../../core/scripting/generated/classes/GCPlayerVisibility.h"
#include "../core.h"

void SetupLuaClassGCPlayerVisibility(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerVisibility>("CPlayerVisibility")
        .addProperty("VisibilityStrength", &GCPlayerVisibility::GetVisibilityStrength, &GCPlayerVisibility::SetVisibilityStrength)
        .addProperty("FogDistanceMultiplier", &GCPlayerVisibility::GetFogDistanceMultiplier, &GCPlayerVisibility::SetFogDistanceMultiplier)
        .addProperty("FogMaxDensityMultiplier", &GCPlayerVisibility::GetFogMaxDensityMultiplier, &GCPlayerVisibility::SetFogMaxDensityMultiplier)
        .addProperty("FadeTime", &GCPlayerVisibility::GetFadeTime, &GCPlayerVisibility::SetFadeTime)
        .addProperty("StartDisabled", &GCPlayerVisibility::GetStartDisabled, &GCPlayerVisibility::SetStartDisabled)
        .addProperty("IsEnabled", &GCPlayerVisibility::GetIsEnabled, &GCPlayerVisibility::SetIsEnabled)
        .endClass();
}