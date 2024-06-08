#include "../../../core/scripting/generated/classes/GCNmStateMachineNode__StateDefinition_t.h"
#include "../core.h"

void SetupLuaClassGCNmStateMachineNode__StateDefinition_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmStateMachineNode__StateDefinition_t>("CNmStateMachineNode__StateDefinition_t")
        .addProperty("StateNodeIdx", &GCNmStateMachineNode__StateDefinition_t::GetStateNodeIdx, &GCNmStateMachineNode__StateDefinition_t::SetStateNodeIdx)
        .addProperty("EntryConditionNodeIdx", &GCNmStateMachineNode__StateDefinition_t::GetEntryConditionNodeIdx, &GCNmStateMachineNode__StateDefinition_t::SetEntryConditionNodeIdx)
        .endClass();
}