#include "../../../core/scripting/generated/classes/GVMixSubgraphSwitchDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixSubgraphSwitchDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixSubgraphSwitchDesc_t>("VMixSubgraphSwitchDesc_t")
        .addProperty("InterpolationMode", &GVMixSubgraphSwitchDesc_t::GetInterpolationMode, &GVMixSubgraphSwitchDesc_t::SetInterpolationMode)
        .addProperty("OnlyTailsOnFadeOut", &GVMixSubgraphSwitchDesc_t::GetOnlyTailsOnFadeOut, &GVMixSubgraphSwitchDesc_t::SetOnlyTailsOnFadeOut)
        .addProperty("InterpolationTime", &GVMixSubgraphSwitchDesc_t::GetInterpolationTime, &GVMixSubgraphSwitchDesc_t::SetInterpolationTime)
        .endClass();
}