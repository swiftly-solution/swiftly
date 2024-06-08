#include "../../../core/scripting/generated/classes/GVMixShaperDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixShaperDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixShaperDesc_t>("VMixShaperDesc_t")
        .addProperty("Shape", &GVMixShaperDesc_t::GetShape, &GVMixShaperDesc_t::SetShape)
        .addProperty("FldbDrive", &GVMixShaperDesc_t::GetFldbDrive, &GVMixShaperDesc_t::SetFldbDrive)
        .addProperty("FldbOutputGain", &GVMixShaperDesc_t::GetFldbOutputGain, &GVMixShaperDesc_t::SetFldbOutputGain)
        .addProperty("WetMix", &GVMixShaperDesc_t::GetWetMix, &GVMixShaperDesc_t::SetWetMix)
        .addProperty("OversampleFactor", &GVMixShaperDesc_t::GetOversampleFactor, &GVMixShaperDesc_t::SetOversampleFactor)
        .endClass();
}