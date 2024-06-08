#include "../../../core/scripting/generated/classes/GC_OP_UpdateLightSource.h"
#include "../core.h"

void SetupLuaClassGC_OP_UpdateLightSource(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_UpdateLightSource>("C_OP_UpdateLightSource")
        .addProperty("ColorTint", &GC_OP_UpdateLightSource::GetColorTint, &GC_OP_UpdateLightSource::SetColorTint)
        .addProperty("BrightnessScale", &GC_OP_UpdateLightSource::GetBrightnessScale, &GC_OP_UpdateLightSource::SetBrightnessScale)
        .addProperty("RadiusScale", &GC_OP_UpdateLightSource::GetRadiusScale, &GC_OP_UpdateLightSource::SetRadiusScale)
        .addProperty("MinimumLightingRadius", &GC_OP_UpdateLightSource::GetMinimumLightingRadius, &GC_OP_UpdateLightSource::SetMinimumLightingRadius)
        .addProperty("MaximumLightingRadius", &GC_OP_UpdateLightSource::GetMaximumLightingRadius, &GC_OP_UpdateLightSource::SetMaximumLightingRadius)
        .addProperty("PositionDampingConstant", &GC_OP_UpdateLightSource::GetPositionDampingConstant, &GC_OP_UpdateLightSource::SetPositionDampingConstant)
        .endClass();
}