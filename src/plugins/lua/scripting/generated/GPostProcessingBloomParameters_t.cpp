#include "../../../core/scripting/generated/classes/GPostProcessingBloomParameters_t.h"
#include "../core.h"

void SetupLuaClassGPostProcessingBloomParameters_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPostProcessingBloomParameters_t>("PostProcessingBloomParameters_t")
        .addProperty("BlendMode", &GPostProcessingBloomParameters_t::GetBlendMode, &GPostProcessingBloomParameters_t::SetBlendMode)
        .addProperty("BloomStrength", &GPostProcessingBloomParameters_t::GetBloomStrength, &GPostProcessingBloomParameters_t::SetBloomStrength)
        .addProperty("ScreenBloomStrength", &GPostProcessingBloomParameters_t::GetScreenBloomStrength, &GPostProcessingBloomParameters_t::SetScreenBloomStrength)
        .addProperty("BlurBloomStrength", &GPostProcessingBloomParameters_t::GetBlurBloomStrength, &GPostProcessingBloomParameters_t::SetBlurBloomStrength)
        .addProperty("BloomThreshold", &GPostProcessingBloomParameters_t::GetBloomThreshold, &GPostProcessingBloomParameters_t::SetBloomThreshold)
        .addProperty("BloomThresholdWidth", &GPostProcessingBloomParameters_t::GetBloomThresholdWidth, &GPostProcessingBloomParameters_t::SetBloomThresholdWidth)
        .addProperty("SkyboxBloomStrength", &GPostProcessingBloomParameters_t::GetSkyboxBloomStrength, &GPostProcessingBloomParameters_t::SetSkyboxBloomStrength)
        .addProperty("BloomStartValue", &GPostProcessingBloomParameters_t::GetBloomStartValue, &GPostProcessingBloomParameters_t::SetBloomStartValue)
        .addProperty("BlurWeight", &GPostProcessingBloomParameters_t::GetBlurWeight, &GPostProcessingBloomParameters_t::SetBlurWeight)
        .addProperty("BlurTint", &GPostProcessingBloomParameters_t::GetBlurTint, &GPostProcessingBloomParameters_t::SetBlurTint)
        .endClass();
}