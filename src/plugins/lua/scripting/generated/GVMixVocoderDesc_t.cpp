#include "../../../core/scripting/generated/classes/GVMixVocoderDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixVocoderDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixVocoderDesc_t>("VMixVocoderDesc_t")
        .addProperty("BandCount", &GVMixVocoderDesc_t::GetBandCount, &GVMixVocoderDesc_t::SetBandCount)
        .addProperty("Bandwidth", &GVMixVocoderDesc_t::GetBandwidth, &GVMixVocoderDesc_t::SetBandwidth)
        .addProperty("FldBModGain", &GVMixVocoderDesc_t::GetFldBModGain, &GVMixVocoderDesc_t::SetFldBModGain)
        .addProperty("FreqRangeStart", &GVMixVocoderDesc_t::GetFreqRangeStart, &GVMixVocoderDesc_t::SetFreqRangeStart)
        .addProperty("FreqRangeEnd", &GVMixVocoderDesc_t::GetFreqRangeEnd, &GVMixVocoderDesc_t::SetFreqRangeEnd)
        .addProperty("FldBUnvoicedGain", &GVMixVocoderDesc_t::GetFldBUnvoicedGain, &GVMixVocoderDesc_t::SetFldBUnvoicedGain)
        .addProperty("AttackTimeMS", &GVMixVocoderDesc_t::GetAttackTimeMS, &GVMixVocoderDesc_t::SetAttackTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixVocoderDesc_t::GetReleaseTimeMS, &GVMixVocoderDesc_t::SetReleaseTimeMS)
        .addProperty("DebugBand", &GVMixVocoderDesc_t::GetDebugBand, &GVMixVocoderDesc_t::SetDebugBand)
        .addProperty("PeakMode", &GVMixVocoderDesc_t::GetPeakMode, &GVMixVocoderDesc_t::SetPeakMode)
        .endClass();
}