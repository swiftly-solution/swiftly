#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmStateMachineNode__TransitionDefinition_t::GCNmStateMachineNode__TransitionDefinition_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmStateMachineNode__TransitionDefinition_t::GCNmStateMachineNode__TransitionDefinition_t(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmStateMachineNode__TransitionDefinition_t::GetTargetStateIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nTargetStateIdx");
}
void GCNmStateMachineNode__TransitionDefinition_t::SetTargetStateIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nTargetStateIdx", true, value);
}
int16_t GCNmStateMachineNode__TransitionDefinition_t::GetConditionNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nConditionNodeIdx");
}
void GCNmStateMachineNode__TransitionDefinition_t::SetConditionNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nConditionNodeIdx", true, value);
}
int16_t GCNmStateMachineNode__TransitionDefinition_t::GetTransitionNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nTransitionNodeIdx");
}
void GCNmStateMachineNode__TransitionDefinition_t::SetTransitionNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_nTransitionNodeIdx", true, value);
}
bool GCNmStateMachineNode__TransitionDefinition_t::GetCanBeForced() const {
    return GetSchemaValue<bool>(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_bCanBeForced");
}
void GCNmStateMachineNode__TransitionDefinition_t::SetCanBeForced(bool value) {
    SetSchemaValue(m_ptr, "CNmStateMachineNode__TransitionDefinition_t", "m_bCanBeForced", true, value);
}
std::string GCNmStateMachineNode__TransitionDefinition_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmStateMachineNode__TransitionDefinition_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmStateMachineNode__TransitionDefinition_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmStateMachineNode__TransitionDefinition_t>("CNmStateMachineNode__TransitionDefinition_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetStateIdx", &GCNmStateMachineNode__TransitionDefinition_t::GetTargetStateIdx, &GCNmStateMachineNode__TransitionDefinition_t::SetTargetStateIdx)
        .addProperty("ConditionNodeIdx", &GCNmStateMachineNode__TransitionDefinition_t::GetConditionNodeIdx, &GCNmStateMachineNode__TransitionDefinition_t::SetConditionNodeIdx)
        .addProperty("TransitionNodeIdx", &GCNmStateMachineNode__TransitionDefinition_t::GetTransitionNodeIdx, &GCNmStateMachineNode__TransitionDefinition_t::SetTransitionNodeIdx)
        .addProperty("CanBeForced", &GCNmStateMachineNode__TransitionDefinition_t::GetCanBeForced, &GCNmStateMachineNode__TransitionDefinition_t::SetCanBeForced)
        .addFunction("ToPtr", &GCNmStateMachineNode__TransitionDefinition_t::ToPtr)
        .addFunction("IsValid", &GCNmStateMachineNode__TransitionDefinition_t::IsValid)
        .endClass();
}