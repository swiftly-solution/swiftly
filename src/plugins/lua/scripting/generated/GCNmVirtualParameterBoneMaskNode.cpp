#include "../../../core/scripting/generated/classes/GCNmVirtualParameterBoneMaskNode.h"
#include "../core.h"

void SetupLuaClassGCNmVirtualParameterBoneMaskNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterBoneMaskNode>("CNmVirtualParameterBoneMaskNode")
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterBoneMaskNode::GetChildNodeIdx, &GCNmVirtualParameterBoneMaskNode::SetChildNodeIdx)
        .endClass();
}