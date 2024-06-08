#include "../../../core/scripting/generated/classes/GCRagdollUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCRagdollUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollUpdateNode>("CRagdollUpdateNode")
        .addProperty("WeightListIndex", &GCRagdollUpdateNode::GetWeightListIndex, &GCRagdollUpdateNode::SetWeightListIndex)
        .addProperty("PoseControlMethod", &GCRagdollUpdateNode::GetPoseControlMethod, &GCRagdollUpdateNode::SetPoseControlMethod)
        .endClass();
}