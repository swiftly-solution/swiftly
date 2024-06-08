#include "../../../core/scripting/generated/classes/GCMultiLightProxy.h"
#include "../core.h"

void SetupLuaClassGCMultiLightProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMultiLightProxy>("CMultiLightProxy")
        .addProperty("LightNameFilter", &GCMultiLightProxy::GetLightNameFilter, &GCMultiLightProxy::SetLightNameFilter)
        .addProperty("LightClassFilter", &GCMultiLightProxy::GetLightClassFilter, &GCMultiLightProxy::SetLightClassFilter)
        .addProperty("LightRadiusFilter", &GCMultiLightProxy::GetLightRadiusFilter, &GCMultiLightProxy::SetLightRadiusFilter)
        .addProperty("BrightnessDelta", &GCMultiLightProxy::GetBrightnessDelta, &GCMultiLightProxy::SetBrightnessDelta)
        .addProperty("PerformScreenFade", &GCMultiLightProxy::GetPerformScreenFade, &GCMultiLightProxy::SetPerformScreenFade)
        .addProperty("TargetBrightnessMultiplier", &GCMultiLightProxy::GetTargetBrightnessMultiplier, &GCMultiLightProxy::SetTargetBrightnessMultiplier)
        .addProperty("CurrentBrightnessMultiplier", &GCMultiLightProxy::GetCurrentBrightnessMultiplier, &GCMultiLightProxy::SetCurrentBrightnessMultiplier)
        .endClass();
}