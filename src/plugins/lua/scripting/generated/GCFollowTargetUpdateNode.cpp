#include "../../../core/scripting/generated/classes/GCFollowTargetUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCFollowTargetUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFollowTargetUpdateNode>("CFollowTargetUpdateNode")
        .addProperty("OpFixedData", &GCFollowTargetUpdateNode::GetOpFixedData, &GCFollowTargetUpdateNode::SetOpFixedData)
        .addProperty("ParameterPosition", &GCFollowTargetUpdateNode::GetParameterPosition, &GCFollowTargetUpdateNode::SetParameterPosition)
        .addProperty("ParameterOrientation", &GCFollowTargetUpdateNode::GetParameterOrientation, &GCFollowTargetUpdateNode::SetParameterOrientation)
        .endClass();
}