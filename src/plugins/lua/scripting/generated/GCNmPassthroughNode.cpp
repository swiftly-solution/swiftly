#include "../../../core/scripting/generated/classes/GCNmPassthroughNode.h"
#include "../core.h"

void SetupLuaClassGCNmPassthroughNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmPassthroughNode>("CNmPassthroughNode")
        .addProperty("ChildNodeIdx", &GCNmPassthroughNode::GetChildNodeIdx, &GCNmPassthroughNode::SetChildNodeIdx)
        .endClass();
}