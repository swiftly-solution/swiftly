#include "../../../core/scripting/generated/classes/GCSubtractUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCSubtractUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSubtractUpdateNode>("CSubtractUpdateNode")
        .addProperty("FootMotionTiming", &GCSubtractUpdateNode::GetFootMotionTiming, &GCSubtractUpdateNode::SetFootMotionTiming)
        .addProperty("ApplyToFootMotion", &GCSubtractUpdateNode::GetApplyToFootMotion, &GCSubtractUpdateNode::SetApplyToFootMotion)
        .addProperty("ApplyChannelsSeparately", &GCSubtractUpdateNode::GetApplyChannelsSeparately, &GCSubtractUpdateNode::SetApplyChannelsSeparately)
        .addProperty("UseModelSpace", &GCSubtractUpdateNode::GetUseModelSpace, &GCSubtractUpdateNode::SetUseModelSpace)
        .endClass();
}