#include "../../../core/scripting/generated/classes/GCMotionSearchNode.h"
#include "../core.h"

void SetupLuaClassGCMotionSearchNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionSearchNode>("CMotionSearchNode")
        .addProperty("Children", &GCMotionSearchNode::GetChildren, &GCMotionSearchNode::SetChildren)
        .addProperty("Quantizer", &GCMotionSearchNode::GetQuantizer, &GCMotionSearchNode::SetQuantizer)
        .addProperty("SelectableSamples", &GCMotionSearchNode::GetSelectableSamples, &GCMotionSearchNode::SetSelectableSamples)
        .endClass();
}