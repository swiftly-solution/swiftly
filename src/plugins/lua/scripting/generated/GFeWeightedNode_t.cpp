#include "../../../core/scripting/generated/classes/GFeWeightedNode_t.h"
#include "../core.h"

void SetupLuaClassGFeWeightedNode_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeWeightedNode_t>("FeWeightedNode_t")
        .addProperty("Node", &GFeWeightedNode_t::GetNode, &GFeWeightedNode_t::SetNode)
        .addProperty("Weight", &GFeWeightedNode_t::GetWeight, &GFeWeightedNode_t::SetWeight)
        .endClass();
}