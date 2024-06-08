#include "../../../core/scripting/generated/classes/GVMixDiffusorDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixDiffusorDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDiffusorDesc_t>("VMixDiffusorDesc_t")
        .addProperty("Size", &GVMixDiffusorDesc_t::GetSize, &GVMixDiffusorDesc_t::SetSize)
        .addProperty("Complexity", &GVMixDiffusorDesc_t::GetComplexity, &GVMixDiffusorDesc_t::SetComplexity)
        .addProperty("Feedback", &GVMixDiffusorDesc_t::GetFeedback, &GVMixDiffusorDesc_t::SetFeedback)
        .addProperty("OutputGain", &GVMixDiffusorDesc_t::GetOutputGain, &GVMixDiffusorDesc_t::SetOutputGain)
        .endClass();
}