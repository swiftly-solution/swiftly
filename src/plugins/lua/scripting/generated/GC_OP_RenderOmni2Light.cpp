#include "../../../core/scripting/generated/classes/GC_OP_RenderOmni2Light.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderOmni2Light(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderOmni2Light>("C_OP_RenderOmni2Light")
        .addProperty("LightType", &GC_OP_RenderOmni2Light::GetLightType, &GC_OP_RenderOmni2Light::SetLightType)
        .addProperty("ColorBlendType", &GC_OP_RenderOmni2Light::GetColorBlendType, &GC_OP_RenderOmni2Light::SetColorBlendType)
        .addProperty("BrightnessUnit", &GC_OP_RenderOmni2Light::GetBrightnessUnit, &GC_OP_RenderOmni2Light::SetBrightnessUnit)
        .addProperty("BrightnessLumens", &GC_OP_RenderOmni2Light::GetBrightnessLumens, &GC_OP_RenderOmni2Light::SetBrightnessLumens)
        .addProperty("BrightnessCandelas", &GC_OP_RenderOmni2Light::GetBrightnessCandelas, &GC_OP_RenderOmni2Light::SetBrightnessCandelas)
        .addProperty("CastShadows", &GC_OP_RenderOmni2Light::GetCastShadows, &GC_OP_RenderOmni2Light::SetCastShadows)
        .addProperty("LuminaireRadius", &GC_OP_RenderOmni2Light::GetLuminaireRadius, &GC_OP_RenderOmni2Light::SetLuminaireRadius)
        .addProperty("Skirt", &GC_OP_RenderOmni2Light::GetSkirt, &GC_OP_RenderOmni2Light::SetSkirt)
        .addProperty("Range", &GC_OP_RenderOmni2Light::GetRange, &GC_OP_RenderOmni2Light::SetRange)
        .addProperty("InnerConeAngle", &GC_OP_RenderOmni2Light::GetInnerConeAngle, &GC_OP_RenderOmni2Light::SetInnerConeAngle)
        .addProperty("OuterConeAngle", &GC_OP_RenderOmni2Light::GetOuterConeAngle, &GC_OP_RenderOmni2Light::SetOuterConeAngle)
        .addProperty("SphericalCookie", &GC_OP_RenderOmni2Light::GetSphericalCookie, &GC_OP_RenderOmni2Light::SetSphericalCookie)
        .endClass();
}