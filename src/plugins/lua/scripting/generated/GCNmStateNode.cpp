#include "../../../core/scripting/generated/classes/GCNmStateNode.h"
#include "../core.h"

void SetupLuaClassGCNmStateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmStateNode>("CNmStateNode")
        .addProperty("ChildNodeIdx", &GCNmStateNode::GetChildNodeIdx, &GCNmStateNode::SetChildNodeIdx)
        .addProperty("LayerWeightNodeIdx", &GCNmStateNode::GetLayerWeightNodeIdx, &GCNmStateNode::SetLayerWeightNodeIdx)
        .addProperty("LayerRootMotionWeightNodeIdx", &GCNmStateNode::GetLayerRootMotionWeightNodeIdx, &GCNmStateNode::SetLayerRootMotionWeightNodeIdx)
        .addProperty("LayerBoneMaskNodeIdx", &GCNmStateNode::GetLayerBoneMaskNodeIdx, &GCNmStateNode::SetLayerBoneMaskNodeIdx)
        .addProperty("IsOffState", &GCNmStateNode::GetIsOffState, &GCNmStateNode::SetIsOffState)
        .endClass();
}