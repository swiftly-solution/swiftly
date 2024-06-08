#include "../../../core/scripting/generated/classes/GVMixBoxverbDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixBoxverbDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixBoxverbDesc_t>("VMixBoxverbDesc_t")
        .addProperty("SizeMax", &GVMixBoxverbDesc_t::GetSizeMax, &GVMixBoxverbDesc_t::SetSizeMax)
        .addProperty("SizeMin", &GVMixBoxverbDesc_t::GetSizeMin, &GVMixBoxverbDesc_t::SetSizeMin)
        .addProperty("Complexity", &GVMixBoxverbDesc_t::GetComplexity, &GVMixBoxverbDesc_t::SetComplexity)
        .addProperty("Diffusion", &GVMixBoxverbDesc_t::GetDiffusion, &GVMixBoxverbDesc_t::SetDiffusion)
        .addProperty("ModDepth", &GVMixBoxverbDesc_t::GetModDepth, &GVMixBoxverbDesc_t::SetModDepth)
        .addProperty("ModRate", &GVMixBoxverbDesc_t::GetModRate, &GVMixBoxverbDesc_t::SetModRate)
        .addProperty("Parallel", &GVMixBoxverbDesc_t::GetParallel, &GVMixBoxverbDesc_t::SetParallel)
        .addProperty("FilterType", &GVMixBoxverbDesc_t::GetFilterType, &GVMixBoxverbDesc_t::SetFilterType)
        .addProperty("Width", &GVMixBoxverbDesc_t::GetWidth, &GVMixBoxverbDesc_t::SetWidth)
        .addProperty("Height", &GVMixBoxverbDesc_t::GetHeight, &GVMixBoxverbDesc_t::SetHeight)
        .addProperty("Depth", &GVMixBoxverbDesc_t::GetDepth, &GVMixBoxverbDesc_t::SetDepth)
        .addProperty("FeedbackScale", &GVMixBoxverbDesc_t::GetFeedbackScale, &GVMixBoxverbDesc_t::SetFeedbackScale)
        .addProperty("FeedbackWidth", &GVMixBoxverbDesc_t::GetFeedbackWidth, &GVMixBoxverbDesc_t::SetFeedbackWidth)
        .addProperty("FeedbackHeight", &GVMixBoxverbDesc_t::GetFeedbackHeight, &GVMixBoxverbDesc_t::SetFeedbackHeight)
        .addProperty("FeedbackDepth", &GVMixBoxverbDesc_t::GetFeedbackDepth, &GVMixBoxverbDesc_t::SetFeedbackDepth)
        .addProperty("OutputGain", &GVMixBoxverbDesc_t::GetOutputGain, &GVMixBoxverbDesc_t::SetOutputGain)
        .addProperty("Taps", &GVMixBoxverbDesc_t::GetTaps, &GVMixBoxverbDesc_t::SetTaps)
        .endClass();
}