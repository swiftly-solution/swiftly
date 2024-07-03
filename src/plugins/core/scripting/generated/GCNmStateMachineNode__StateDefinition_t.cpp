#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmStateMachineNode__StateDefinition_t::GCNmStateMachineNode__StateDefinition_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmStateMachineNode__StateDefinition_t::GCNmStateMachineNode__StateDefinition_t(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmStateMachineNode__StateDefinition_t::GetStateNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode__StateDefinition_t", "m_nStateNodeIdx");
}
void GCNmStateMachineNode__StateDefinition_t::SetStateNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmStateMachineNode__StateDefinition_t", "m_nStateNodeIdx", true, value);
}
int16_t GCNmStateMachineNode__StateDefinition_t::GetEntryConditionNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode__StateDefinition_t", "m_entryConditionNodeIdx");
}
void GCNmStateMachineNode__StateDefinition_t::SetEntryConditionNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmStateMachineNode__StateDefinition_t", "m_entryConditionNodeIdx", true, value);
}
std::string GCNmStateMachineNode__StateDefinition_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmStateMachineNode__StateDefinition_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmStateMachineNode__StateDefinition_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmStateMachineNode__StateDefinition_t>("CNmStateMachineNode__StateDefinition_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StateNodeIdx", &GCNmStateMachineNode__StateDefinition_t::GetStateNodeIdx, &GCNmStateMachineNode__StateDefinition_t::SetStateNodeIdx)
        .addProperty("EntryConditionNodeIdx", &GCNmStateMachineNode__StateDefinition_t::GetEntryConditionNodeIdx, &GCNmStateMachineNode__StateDefinition_t::SetEntryConditionNodeIdx)
        .addFunction("ToPtr", &GCNmStateMachineNode__StateDefinition_t::ToPtr)
        .addFunction("IsValid", &GCNmStateMachineNode__StateDefinition_t::IsValid)
        .endClass();
}