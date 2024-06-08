#include "../../../core/scripting/generated/classes/GCNmVirtualParameterFloatNode.h"
#include "../core.h"

void SetupLuaClassGCNmVirtualParameterFloatNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterFloatNode>("CNmVirtualParameterFloatNode")
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterFloatNode::GetChildNodeIdx, &GCNmVirtualParameterFloatNode::SetChildNodeIdx)
        .endClass();
}