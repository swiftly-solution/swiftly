#include "../../../core/scripting/generated/classes/GFeFollowNode_t.h"
#include "../core.h"

void SetupLuaClassGFeFollowNode_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeFollowNode_t>("FeFollowNode_t")
        .addProperty("ParentNode", &GFeFollowNode_t::GetParentNode, &GFeFollowNode_t::SetParentNode)
        .addProperty("ChildNode", &GFeFollowNode_t::GetChildNode, &GFeFollowNode_t::SetChildNode)
        .addProperty("Weight", &GFeFollowNode_t::GetWeight, &GFeFollowNode_t::SetWeight)
        .endClass();
}