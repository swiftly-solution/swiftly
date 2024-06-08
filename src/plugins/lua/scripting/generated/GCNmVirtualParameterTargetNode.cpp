#include "../../../core/scripting/generated/classes/GCNmVirtualParameterTargetNode.h"
#include "../core.h"

void SetupLuaClassGCNmVirtualParameterTargetNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterTargetNode>("CNmVirtualParameterTargetNode")
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterTargetNode::GetChildNodeIdx, &GCNmVirtualParameterTargetNode::SetChildNodeIdx)
        .endClass();
}