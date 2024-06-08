#include "../../../core/scripting/generated/classes/GVMixPlateverbDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixPlateverbDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixPlateverbDesc_t>("VMixPlateverbDesc_t")
        .addProperty("Prefilter", &GVMixPlateverbDesc_t::GetPrefilter, &GVMixPlateverbDesc_t::SetPrefilter)
        .addProperty("InputDiffusion1", &GVMixPlateverbDesc_t::GetInputDiffusion1, &GVMixPlateverbDesc_t::SetInputDiffusion1)
        .addProperty("InputDiffusion2", &GVMixPlateverbDesc_t::GetInputDiffusion2, &GVMixPlateverbDesc_t::SetInputDiffusion2)
        .addProperty("Decay", &GVMixPlateverbDesc_t::GetDecay, &GVMixPlateverbDesc_t::SetDecay)
        .addProperty("Damp", &GVMixPlateverbDesc_t::GetDamp, &GVMixPlateverbDesc_t::SetDamp)
        .addProperty("FeedbackDiffusion1", &GVMixPlateverbDesc_t::GetFeedbackDiffusion1, &GVMixPlateverbDesc_t::SetFeedbackDiffusion1)
        .addProperty("FeedbackDiffusion2", &GVMixPlateverbDesc_t::GetFeedbackDiffusion2, &GVMixPlateverbDesc_t::SetFeedbackDiffusion2)
        .endClass();
}