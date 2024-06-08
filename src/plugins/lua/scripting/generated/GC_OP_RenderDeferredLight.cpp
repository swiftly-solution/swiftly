#include "../../../core/scripting/generated/classes/GC_OP_RenderDeferredLight.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderDeferredLight(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderDeferredLight>("C_OP_RenderDeferredLight")
        .addProperty("UseAlphaTestWindow", &GC_OP_RenderDeferredLight::GetUseAlphaTestWindow, &GC_OP_RenderDeferredLight::SetUseAlphaTestWindow)
        .addProperty("UseTexture", &GC_OP_RenderDeferredLight::GetUseTexture, &GC_OP_RenderDeferredLight::SetUseTexture)
        .addProperty("RadiusScale", &GC_OP_RenderDeferredLight::GetRadiusScale, &GC_OP_RenderDeferredLight::SetRadiusScale)
        .addProperty("AlphaScale", &GC_OP_RenderDeferredLight::GetAlphaScale, &GC_OP_RenderDeferredLight::SetAlphaScale)
        .addProperty("Alpha2Field", &GC_OP_RenderDeferredLight::GetAlpha2Field, &GC_OP_RenderDeferredLight::SetAlpha2Field)
        .addProperty("ColorBlendType", &GC_OP_RenderDeferredLight::GetColorBlendType, &GC_OP_RenderDeferredLight::SetColorBlendType)
        .addProperty("LightDistance", &GC_OP_RenderDeferredLight::GetLightDistance, &GC_OP_RenderDeferredLight::SetLightDistance)
        .addProperty("StartFalloff", &GC_OP_RenderDeferredLight::GetStartFalloff, &GC_OP_RenderDeferredLight::SetStartFalloff)
        .addProperty("DistanceFalloff", &GC_OP_RenderDeferredLight::GetDistanceFalloff, &GC_OP_RenderDeferredLight::SetDistanceFalloff)
        .addProperty("SpotFoV", &GC_OP_RenderDeferredLight::GetSpotFoV, &GC_OP_RenderDeferredLight::SetSpotFoV)
        .addProperty("AlphaTestPointField", &GC_OP_RenderDeferredLight::GetAlphaTestPointField, &GC_OP_RenderDeferredLight::SetAlphaTestPointField)
        .addProperty("AlphaTestRangeField", &GC_OP_RenderDeferredLight::GetAlphaTestRangeField, &GC_OP_RenderDeferredLight::SetAlphaTestRangeField)
        .addProperty("AlphaTestSharpnessField", &GC_OP_RenderDeferredLight::GetAlphaTestSharpnessField, &GC_OP_RenderDeferredLight::SetAlphaTestSharpnessField)
        .addProperty("HSVShiftControlPoint", &GC_OP_RenderDeferredLight::GetHSVShiftControlPoint, &GC_OP_RenderDeferredLight::SetHSVShiftControlPoint)
        .endClass();
}