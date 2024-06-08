#include "../../../core/scripting/generated/classes/GVMixFilterDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixFilterDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixFilterDesc_t>("VMixFilterDesc_t")
        .addProperty("FilterType", &GVMixFilterDesc_t::GetFilterType, &GVMixFilterDesc_t::SetFilterType)
        .addProperty("FilterSlope", &GVMixFilterDesc_t::GetFilterSlope, &GVMixFilterDesc_t::SetFilterSlope)
        .addProperty("Enabled", &GVMixFilterDesc_t::GetEnabled, &GVMixFilterDesc_t::SetEnabled)
        .addProperty("FldbGain", &GVMixFilterDesc_t::GetFldbGain, &GVMixFilterDesc_t::SetFldbGain)
        .addProperty("CutoffFreq", &GVMixFilterDesc_t::GetCutoffFreq, &GVMixFilterDesc_t::SetCutoffFreq)
        .addProperty("Q", &GVMixFilterDesc_t::GetQ, &GVMixFilterDesc_t::SetQ)
        .endClass();
}