#include "../../../core/scripting/generated/classes/GVMixDelayDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixDelayDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDelayDesc_t>("VMixDelayDesc_t")
        .addProperty("FeedbackFilter", &GVMixDelayDesc_t::GetFeedbackFilter, &GVMixDelayDesc_t::SetFeedbackFilter)
        .addProperty("EnableFilter", &GVMixDelayDesc_t::GetEnableFilter, &GVMixDelayDesc_t::SetEnableFilter)
        .addProperty("Delay", &GVMixDelayDesc_t::GetDelay, &GVMixDelayDesc_t::SetDelay)
        .addProperty("DirectGain", &GVMixDelayDesc_t::GetDirectGain, &GVMixDelayDesc_t::SetDirectGain)
        .addProperty("DelayGain", &GVMixDelayDesc_t::GetDelayGain, &GVMixDelayDesc_t::SetDelayGain)
        .addProperty("FeedbackGain", &GVMixDelayDesc_t::GetFeedbackGain, &GVMixDelayDesc_t::SetFeedbackGain)
        .addProperty("Width", &GVMixDelayDesc_t::GetWidth, &GVMixDelayDesc_t::SetWidth)
        .endClass();
}