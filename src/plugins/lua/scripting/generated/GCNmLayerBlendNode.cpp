#include "../../../core/scripting/generated/classes/GCNmLayerBlendNode.h"
#include "../core.h"

void SetupLuaClassGCNmLayerBlendNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmLayerBlendNode>("CNmLayerBlendNode")
        .addProperty("BaseNodeIdx", &GCNmLayerBlendNode::GetBaseNodeIdx, &GCNmLayerBlendNode::SetBaseNodeIdx)
        .addProperty("OnlySampleBaseRootMotion", &GCNmLayerBlendNode::GetOnlySampleBaseRootMotion, &GCNmLayerBlendNode::SetOnlySampleBaseRootMotion)
        .endClass();
}