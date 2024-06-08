#include "../../../core/scripting/generated/classes/GVMixModDelayDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixModDelayDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixModDelayDesc_t>("VMixModDelayDesc_t")
        .addProperty("FeedbackFilter", &GVMixModDelayDesc_t::GetFeedbackFilter, &GVMixModDelayDesc_t::SetFeedbackFilter)
        .addProperty("PhaseInvert", &GVMixModDelayDesc_t::GetPhaseInvert, &GVMixModDelayDesc_t::SetPhaseInvert)
        .addProperty("GlideTime", &GVMixModDelayDesc_t::GetGlideTime, &GVMixModDelayDesc_t::SetGlideTime)
        .addProperty("Delay", &GVMixModDelayDesc_t::GetDelay, &GVMixModDelayDesc_t::SetDelay)
        .addProperty("OutputGain", &GVMixModDelayDesc_t::GetOutputGain, &GVMixModDelayDesc_t::SetOutputGain)
        .addProperty("FeedbackGain", &GVMixModDelayDesc_t::GetFeedbackGain, &GVMixModDelayDesc_t::SetFeedbackGain)
        .addProperty("ModRate", &GVMixModDelayDesc_t::GetModRate, &GVMixModDelayDesc_t::SetModRate)
        .addProperty("ModDepth", &GVMixModDelayDesc_t::GetModDepth, &GVMixModDelayDesc_t::SetModDepth)
        .addProperty("ApplyAntialiasing", &GVMixModDelayDesc_t::GetApplyAntialiasing, &GVMixModDelayDesc_t::SetApplyAntialiasing)
        .endClass();
}