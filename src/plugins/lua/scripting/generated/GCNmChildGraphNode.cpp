#include "../../../core/scripting/generated/classes/GCNmChildGraphNode.h"
#include "../core.h"

void SetupLuaClassGCNmChildGraphNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmChildGraphNode>("CNmChildGraphNode")
        .addProperty("ChildGraphIdx", &GCNmChildGraphNode::GetChildGraphIdx, &GCNmChildGraphNode::SetChildGraphIdx)
        .endClass();
}