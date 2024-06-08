#include "../../../core/scripting/generated/classes/GCNmStateMachineNode.h"
#include "../core.h"

void SetupLuaClassGCNmStateMachineNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmStateMachineNode>("CNmStateMachineNode")
        .addProperty("DefaultStateIndex", &GCNmStateMachineNode::GetDefaultStateIndex, &GCNmStateMachineNode::SetDefaultStateIndex)
        .endClass();
}