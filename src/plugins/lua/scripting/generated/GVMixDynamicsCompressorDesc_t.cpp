#include "../../../core/scripting/generated/classes/GVMixDynamicsCompressorDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixDynamicsCompressorDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDynamicsCompressorDesc_t>("VMixDynamicsCompressorDesc_t")
        .addProperty("FldbOutputGain", &GVMixDynamicsCompressorDesc_t::GetFldbOutputGain, &GVMixDynamicsCompressorDesc_t::SetFldbOutputGain)
        .addProperty("FldbCompressionThreshold", &GVMixDynamicsCompressorDesc_t::GetFldbCompressionThreshold, &GVMixDynamicsCompressorDesc_t::SetFldbCompressionThreshold)
        .addProperty("FldbKneeWidth", &GVMixDynamicsCompressorDesc_t::GetFldbKneeWidth, &GVMixDynamicsCompressorDesc_t::SetFldbKneeWidth)
        .addProperty("CompressionRatio", &GVMixDynamicsCompressorDesc_t::GetCompressionRatio, &GVMixDynamicsCompressorDesc_t::SetCompressionRatio)
        .addProperty("AttackTimeMS", &GVMixDynamicsCompressorDesc_t::GetAttackTimeMS, &GVMixDynamicsCompressorDesc_t::SetAttackTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixDynamicsCompressorDesc_t::GetReleaseTimeMS, &GVMixDynamicsCompressorDesc_t::SetReleaseTimeMS)
        .addProperty("RMSTimeMS", &GVMixDynamicsCompressorDesc_t::GetRMSTimeMS, &GVMixDynamicsCompressorDesc_t::SetRMSTimeMS)
        .addProperty("WetMix", &GVMixDynamicsCompressorDesc_t::GetWetMix, &GVMixDynamicsCompressorDesc_t::SetWetMix)
        .addProperty("PeakMode", &GVMixDynamicsCompressorDesc_t::GetPeakMode, &GVMixDynamicsCompressorDesc_t::SetPeakMode)
        .endClass();
}