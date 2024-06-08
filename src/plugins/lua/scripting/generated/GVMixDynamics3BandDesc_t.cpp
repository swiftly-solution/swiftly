#include "../../../core/scripting/generated/classes/GVMixDynamics3BandDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixDynamics3BandDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDynamics3BandDesc_t>("VMixDynamics3BandDesc_t")
        .addProperty("FldbGainOutput", &GVMixDynamics3BandDesc_t::GetFldbGainOutput, &GVMixDynamics3BandDesc_t::SetFldbGainOutput)
        .addProperty("RMSTimeMS", &GVMixDynamics3BandDesc_t::GetRMSTimeMS, &GVMixDynamics3BandDesc_t::SetRMSTimeMS)
        .addProperty("FldbKneeWidth", &GVMixDynamics3BandDesc_t::GetFldbKneeWidth, &GVMixDynamics3BandDesc_t::SetFldbKneeWidth)
        .addProperty("Depth", &GVMixDynamics3BandDesc_t::GetDepth, &GVMixDynamics3BandDesc_t::SetDepth)
        .addProperty("WetMix", &GVMixDynamics3BandDesc_t::GetWetMix, &GVMixDynamics3BandDesc_t::SetWetMix)
        .addProperty("TimeScale", &GVMixDynamics3BandDesc_t::GetTimeScale, &GVMixDynamics3BandDesc_t::SetTimeScale)
        .addProperty("LowCutoffFreq", &GVMixDynamics3BandDesc_t::GetLowCutoffFreq, &GVMixDynamics3BandDesc_t::SetLowCutoffFreq)
        .addProperty("HighCutoffFreq", &GVMixDynamics3BandDesc_t::GetHighCutoffFreq, &GVMixDynamics3BandDesc_t::SetHighCutoffFreq)
        .addProperty("PeakMode", &GVMixDynamics3BandDesc_t::GetPeakMode, &GVMixDynamics3BandDesc_t::SetPeakMode)
        .addProperty("BandDesc", &GVMixDynamics3BandDesc_t::GetBandDesc, &GVMixDynamics3BandDesc_t::SetBandDesc)
        .endClass();
}