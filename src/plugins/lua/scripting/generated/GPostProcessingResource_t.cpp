#include "../../../core/scripting/generated/classes/GPostProcessingResource_t.h"
#include "../core.h"

void SetupLuaClassGPostProcessingResource_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPostProcessingResource_t>("PostProcessingResource_t")
        .addProperty("HasTonemapParams", &GPostProcessingResource_t::GetHasTonemapParams, &GPostProcessingResource_t::SetHasTonemapParams)
        .addProperty("ToneMapParams", &GPostProcessingResource_t::GetToneMapParams, &GPostProcessingResource_t::SetToneMapParams)
        .addProperty("HasBloomParams", &GPostProcessingResource_t::GetHasBloomParams, &GPostProcessingResource_t::SetHasBloomParams)
        .addProperty("BloomParams", &GPostProcessingResource_t::GetBloomParams, &GPostProcessingResource_t::SetBloomParams)
        .addProperty("HasVignetteParams", &GPostProcessingResource_t::GetHasVignetteParams, &GPostProcessingResource_t::SetHasVignetteParams)
        .addProperty("VignetteParams", &GPostProcessingResource_t::GetVignetteParams, &GPostProcessingResource_t::SetVignetteParams)
        .addProperty("HasLocalContrastParams", &GPostProcessingResource_t::GetHasLocalContrastParams, &GPostProcessingResource_t::SetHasLocalContrastParams)
        .addProperty("LocalConstrastParams", &GPostProcessingResource_t::GetLocalConstrastParams, &GPostProcessingResource_t::SetLocalConstrastParams)
        .addProperty("ColorCorrectionVolumeDim", &GPostProcessingResource_t::GetColorCorrectionVolumeDim, &GPostProcessingResource_t::SetColorCorrectionVolumeDim)
        .addProperty("HasColorCorrection", &GPostProcessingResource_t::GetHasColorCorrection, &GPostProcessingResource_t::SetHasColorCorrection)
        .endClass();
}