#include "../../../core/scripting/generated/classes/GCNmVirtualParameterBoolNode.h"
#include "../core.h"

void SetupLuaClassGCNmVirtualParameterBoolNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterBoolNode>("CNmVirtualParameterBoolNode")
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterBoolNode::GetChildNodeIdx, &GCNmVirtualParameterBoolNode::SetChildNodeIdx)
        .endClass();
}