#include "../../../core/scripting/generated/classes/GCStateMachineUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCStateMachineUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateMachineUpdateNode>("CStateMachineUpdateNode")
        .addProperty("StateMachine", &GCStateMachineUpdateNode::GetStateMachine, &GCStateMachineUpdateNode::SetStateMachine)
        .addProperty("StateData", &GCStateMachineUpdateNode::GetStateData, &GCStateMachineUpdateNode::SetStateData)
        .addProperty("TransitionData", &GCStateMachineUpdateNode::GetTransitionData, &GCStateMachineUpdateNode::SetTransitionData)
        .addProperty("BlockWaningTags", &GCStateMachineUpdateNode::GetBlockWaningTags, &GCStateMachineUpdateNode::SetBlockWaningTags)
        .addProperty("LockStateWhenWaning", &GCStateMachineUpdateNode::GetLockStateWhenWaning, &GCStateMachineUpdateNode::SetLockStateWhenWaning)
        .endClass();
}