#include "../../../core/scripting/generated/classes/GPostProcessingTonemapParameters_t.h"
#include "../core.h"

void SetupLuaClassGPostProcessingTonemapParameters_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPostProcessingTonemapParameters_t>("PostProcessingTonemapParameters_t")
        .addProperty("ExposureBias", &GPostProcessingTonemapParameters_t::GetExposureBias, &GPostProcessingTonemapParameters_t::SetExposureBias)
        .addProperty("ShoulderStrength", &GPostProcessingTonemapParameters_t::GetShoulderStrength, &GPostProcessingTonemapParameters_t::SetShoulderStrength)
        .addProperty("LinearStrength", &GPostProcessingTonemapParameters_t::GetLinearStrength, &GPostProcessingTonemapParameters_t::SetLinearStrength)
        .addProperty("LinearAngle", &GPostProcessingTonemapParameters_t::GetLinearAngle, &GPostProcessingTonemapParameters_t::SetLinearAngle)
        .addProperty("ToeStrength", &GPostProcessingTonemapParameters_t::GetToeStrength, &GPostProcessingTonemapParameters_t::SetToeStrength)
        .addProperty("ToeNum", &GPostProcessingTonemapParameters_t::GetToeNum, &GPostProcessingTonemapParameters_t::SetToeNum)
        .addProperty("ToeDenom", &GPostProcessingTonemapParameters_t::GetToeDenom, &GPostProcessingTonemapParameters_t::SetToeDenom)
        .addProperty("WhitePoint", &GPostProcessingTonemapParameters_t::GetWhitePoint, &GPostProcessingTonemapParameters_t::SetWhitePoint)
        .addProperty("LuminanceSource", &GPostProcessingTonemapParameters_t::GetLuminanceSource, &GPostProcessingTonemapParameters_t::SetLuminanceSource)
        .addProperty("ExposureBiasShadows", &GPostProcessingTonemapParameters_t::GetExposureBiasShadows, &GPostProcessingTonemapParameters_t::SetExposureBiasShadows)
        .addProperty("ExposureBiasHighlights", &GPostProcessingTonemapParameters_t::GetExposureBiasHighlights, &GPostProcessingTonemapParameters_t::SetExposureBiasHighlights)
        .addProperty("MinShadowLum", &GPostProcessingTonemapParameters_t::GetMinShadowLum, &GPostProcessingTonemapParameters_t::SetMinShadowLum)
        .addProperty("MaxShadowLum", &GPostProcessingTonemapParameters_t::GetMaxShadowLum, &GPostProcessingTonemapParameters_t::SetMaxShadowLum)
        .addProperty("MinHighlightLum", &GPostProcessingTonemapParameters_t::GetMinHighlightLum, &GPostProcessingTonemapParameters_t::SetMinHighlightLum)
        .addProperty("MaxHighlightLum", &GPostProcessingTonemapParameters_t::GetMaxHighlightLum, &GPostProcessingTonemapParameters_t::SetMaxHighlightLum)
        .endClass();
}