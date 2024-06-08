#include "../../../core/scripting/generated/classes/GCNmVirtualParameterIDNode.h"
#include "../core.h"

void SetupLuaClassGCNmVirtualParameterIDNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterIDNode>("CNmVirtualParameterIDNode")
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterIDNode::GetChildNodeIdx, &GCNmVirtualParameterIDNode::SetChildNodeIdx)
        .endClass();
}