#include "../../../core/scripting/generated/classes/GCNmGraphNode.h"
#include "../core.h"

void SetupLuaClassGCNmGraphNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmGraphNode>("CNmGraphNode")
        .addProperty("NodeIdx", &GCNmGraphNode::GetNodeIdx, &GCNmGraphNode::SetNodeIdx)
        .endClass();
}