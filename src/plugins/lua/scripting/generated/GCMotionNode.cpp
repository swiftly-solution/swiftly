#include "../../../core/scripting/generated/classes/GCMotionNode.h"
#include "../core.h"

void SetupLuaClassGCMotionNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionNode>("CMotionNode")
        .addProperty("Name", &GCMotionNode::GetName, &GCMotionNode::SetName)
        .addProperty("Id", &GCMotionNode::GetId, &GCMotionNode::SetId)
        .endClass();
}