#include "../../../core/scripting/generated/classes/GVMixUtilityDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixUtilityDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixUtilityDesc_t>("VMixUtilityDesc_t")
        .addProperty("Op", &GVMixUtilityDesc_t::GetOp, &GVMixUtilityDesc_t::SetOp)
        .addProperty("InputPan", &GVMixUtilityDesc_t::GetInputPan, &GVMixUtilityDesc_t::SetInputPan)
        .addProperty("OutputBalance", &GVMixUtilityDesc_t::GetOutputBalance, &GVMixUtilityDesc_t::SetOutputBalance)
        .addProperty("FldbOutputGain", &GVMixUtilityDesc_t::GetFldbOutputGain, &GVMixUtilityDesc_t::SetFldbOutputGain)
        .addProperty("BassMono", &GVMixUtilityDesc_t::GetBassMono, &GVMixUtilityDesc_t::SetBassMono)
        .addProperty("BassFreq", &GVMixUtilityDesc_t::GetBassFreq, &GVMixUtilityDesc_t::SetBassFreq)
        .endClass();
}