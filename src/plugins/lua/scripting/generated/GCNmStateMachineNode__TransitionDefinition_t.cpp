#include "../../../core/scripting/generated/classes/GCNmStateMachineNode__TransitionDefinition_t.h"
#include "../core.h"

void SetupLuaClassGCNmStateMachineNode__TransitionDefinition_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmStateMachineNode__TransitionDefinition_t>("CNmStateMachineNode__TransitionDefinition_t")
        .addProperty("TargetStateIdx", &GCNmStateMachineNode__TransitionDefinition_t::GetTargetStateIdx, &GCNmStateMachineNode__TransitionDefinition_t::SetTargetStateIdx)
        .addProperty("ConditionNodeIdx", &GCNmStateMachineNode__TransitionDefinition_t::GetConditionNodeIdx, &GCNmStateMachineNode__TransitionDefinition_t::SetConditionNodeIdx)
        .addProperty("TransitionNodeIdx", &GCNmStateMachineNode__TransitionDefinition_t::GetTransitionNodeIdx, &GCNmStateMachineNode__TransitionDefinition_t::SetTransitionNodeIdx)
        .addProperty("CanBeForced", &GCNmStateMachineNode__TransitionDefinition_t::GetCanBeForced, &GCNmStateMachineNode__TransitionDefinition_t::SetCanBeForced)
        .endClass();
}