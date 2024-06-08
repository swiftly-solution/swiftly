#include "../../../core/scripting/generated/classes/GVMixDynamicsDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixDynamicsDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDynamicsDesc_t>("VMixDynamicsDesc_t")
        .addProperty("FldbGain", &GVMixDynamicsDesc_t::GetFldbGain, &GVMixDynamicsDesc_t::SetFldbGain)
        .addProperty("FldbNoiseGateThreshold", &GVMixDynamicsDesc_t::GetFldbNoiseGateThreshold, &GVMixDynamicsDesc_t::SetFldbNoiseGateThreshold)
        .addProperty("FldbCompressionThreshold", &GVMixDynamicsDesc_t::GetFldbCompressionThreshold, &GVMixDynamicsDesc_t::SetFldbCompressionThreshold)
        .addProperty("FldbLimiterThreshold", &GVMixDynamicsDesc_t::GetFldbLimiterThreshold, &GVMixDynamicsDesc_t::SetFldbLimiterThreshold)
        .addProperty("FldbKneeWidth", &GVMixDynamicsDesc_t::GetFldbKneeWidth, &GVMixDynamicsDesc_t::SetFldbKneeWidth)
        .addProperty("Ratio", &GVMixDynamicsDesc_t::GetRatio, &GVMixDynamicsDesc_t::SetRatio)
        .addProperty("LimiterRatio", &GVMixDynamicsDesc_t::GetLimiterRatio, &GVMixDynamicsDesc_t::SetLimiterRatio)
        .addProperty("AttackTimeMS", &GVMixDynamicsDesc_t::GetAttackTimeMS, &GVMixDynamicsDesc_t::SetAttackTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixDynamicsDesc_t::GetReleaseTimeMS, &GVMixDynamicsDesc_t::SetReleaseTimeMS)
        .addProperty("RMSTimeMS", &GVMixDynamicsDesc_t::GetRMSTimeMS, &GVMixDynamicsDesc_t::SetRMSTimeMS)
        .addProperty("WetMix", &GVMixDynamicsDesc_t::GetWetMix, &GVMixDynamicsDesc_t::SetWetMix)
        .addProperty("PeakMode", &GVMixDynamicsDesc_t::GetPeakMode, &GVMixDynamicsDesc_t::SetPeakMode)
        .endClass();
}