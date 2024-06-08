#include "../../../core/scripting/generated/classes/GCNmVirtualParameterVectorNode.h"
#include "../core.h"

void SetupLuaClassGCNmVirtualParameterVectorNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterVectorNode>("CNmVirtualParameterVectorNode")
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterVectorNode::GetChildNodeIdx, &GCNmVirtualParameterVectorNode::SetChildNodeIdx)
        .endClass();
}