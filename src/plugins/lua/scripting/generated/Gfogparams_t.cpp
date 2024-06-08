#include "../../../core/scripting/generated/classes/Gfogparams_t.h"
#include "../core.h"

void SetupLuaClassGfogparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gfogparams_t>("fogparams_t")
        .addProperty("DirPrimary", &Gfogparams_t::GetDirPrimary, &Gfogparams_t::SetDirPrimary)
        .addProperty("ColorPrimary", &Gfogparams_t::GetColorPrimary, &Gfogparams_t::SetColorPrimary)
        .addProperty("ColorSecondary", &Gfogparams_t::GetColorSecondary, &Gfogparams_t::SetColorSecondary)
        .addProperty("ColorPrimaryLerpTo", &Gfogparams_t::GetColorPrimaryLerpTo, &Gfogparams_t::SetColorPrimaryLerpTo)
        .addProperty("ColorSecondaryLerpTo", &Gfogparams_t::GetColorSecondaryLerpTo, &Gfogparams_t::SetColorSecondaryLerpTo)
        .addProperty("Start", &Gfogparams_t::GetStart, &Gfogparams_t::SetStart)
        .addProperty("End", &Gfogparams_t::GetEnd, &Gfogparams_t::SetEnd)
        .addProperty("Farz", &Gfogparams_t::GetFarz, &Gfogparams_t::SetFarz)
        .addProperty("Maxdensity", &Gfogparams_t::GetMaxdensity, &Gfogparams_t::SetMaxdensity)
        .addProperty("Exponent", &Gfogparams_t::GetExponent, &Gfogparams_t::SetExponent)
        .addProperty("HDRColorScale", &Gfogparams_t::GetHDRColorScale, &Gfogparams_t::SetHDRColorScale)
        .addProperty("SkyboxFogFactor", &Gfogparams_t::GetSkyboxFogFactor, &Gfogparams_t::SetSkyboxFogFactor)
        .addProperty("SkyboxFogFactorLerpTo", &Gfogparams_t::GetSkyboxFogFactorLerpTo, &Gfogparams_t::SetSkyboxFogFactorLerpTo)
        .addProperty("StartLerpTo", &Gfogparams_t::GetStartLerpTo, &Gfogparams_t::SetStartLerpTo)
        .addProperty("EndLerpTo", &Gfogparams_t::GetEndLerpTo, &Gfogparams_t::SetEndLerpTo)
        .addProperty("MaxdensityLerpTo", &Gfogparams_t::GetMaxdensityLerpTo, &Gfogparams_t::SetMaxdensityLerpTo)
        .addProperty("Duration", &Gfogparams_t::GetDuration, &Gfogparams_t::SetDuration)
        .addProperty("Blendtobackground", &Gfogparams_t::GetBlendtobackground, &Gfogparams_t::SetBlendtobackground)
        .addProperty("Scattering", &Gfogparams_t::GetScattering, &Gfogparams_t::SetScattering)
        .addProperty("Locallightscale", &Gfogparams_t::GetLocallightscale, &Gfogparams_t::SetLocallightscale)
        .addProperty("Enable", &Gfogparams_t::GetEnable, &Gfogparams_t::SetEnable)
        .addProperty("Blend", &Gfogparams_t::GetBlend, &Gfogparams_t::SetBlend)
        .addProperty("NoReflectionFog", &Gfogparams_t::GetNoReflectionFog, &Gfogparams_t::SetNoReflectionFog)
        .addProperty("Padding", &Gfogparams_t::GetPadding, &Gfogparams_t::SetPadding)
        .endClass();
}