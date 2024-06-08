#include "../../../core/scripting/generated/classes/GVMixConvolutionDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixConvolutionDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixConvolutionDesc_t>("VMixConvolutionDesc_t")
        .addProperty("FldbGain", &GVMixConvolutionDesc_t::GetFldbGain, &GVMixConvolutionDesc_t::SetFldbGain)
        .addProperty("PreDelayMS", &GVMixConvolutionDesc_t::GetPreDelayMS, &GVMixConvolutionDesc_t::SetPreDelayMS)
        .addProperty("WetMix", &GVMixConvolutionDesc_t::GetWetMix, &GVMixConvolutionDesc_t::SetWetMix)
        .addProperty("FldbLow", &GVMixConvolutionDesc_t::GetFldbLow, &GVMixConvolutionDesc_t::SetFldbLow)
        .addProperty("FldbMid", &GVMixConvolutionDesc_t::GetFldbMid, &GVMixConvolutionDesc_t::SetFldbMid)
        .addProperty("FldbHigh", &GVMixConvolutionDesc_t::GetFldbHigh, &GVMixConvolutionDesc_t::SetFldbHigh)
        .addProperty("LowCutoffFreq", &GVMixConvolutionDesc_t::GetLowCutoffFreq, &GVMixConvolutionDesc_t::SetLowCutoffFreq)
        .addProperty("HighCutoffFreq", &GVMixConvolutionDesc_t::GetHighCutoffFreq, &GVMixConvolutionDesc_t::SetHighCutoffFreq)
        .endClass();
}