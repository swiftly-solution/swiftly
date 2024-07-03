#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimStateMachineUpdater::GCAnimStateMachineUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimStateMachineUpdater::GCAnimStateMachineUpdater(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCStateUpdateData> GCAnimStateMachineUpdater::GetStates() const {
    CUtlVector<GCStateUpdateData>* vec = GetSchemaValue<CUtlVector<GCStateUpdateData>*>(m_ptr, "CAnimStateMachineUpdater", "m_states"); std::vector<GCStateUpdateData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimStateMachineUpdater::SetStates(std::vector<GCStateUpdateData> value) {
    SetSchemaValueCUtlVector<GCStateUpdateData>(m_ptr, "CAnimStateMachineUpdater", "m_states", false, value);
}
std::vector<GCTransitionUpdateData> GCAnimStateMachineUpdater::GetTransitions() const {
    CUtlVector<GCTransitionUpdateData>* vec = GetSchemaValue<CUtlVector<GCTransitionUpdateData>*>(m_ptr, "CAnimStateMachineUpdater", "m_transitions"); std::vector<GCTransitionUpdateData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimStateMachineUpdater::SetTransitions(std::vector<GCTransitionUpdateData> value) {
    SetSchemaValueCUtlVector<GCTransitionUpdateData>(m_ptr, "CAnimStateMachineUpdater", "m_transitions", false, value);
}
int32_t GCAnimStateMachineUpdater::GetStartStateIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimStateMachineUpdater", "m_startStateIndex");
}
void GCAnimStateMachineUpdater::SetStartStateIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimStateMachineUpdater", "m_startStateIndex", false, value);
}
std::string GCAnimStateMachineUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimStateMachineUpdater::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimStateMachineUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimStateMachineUpdater>("CAnimStateMachineUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("States", &GCAnimStateMachineUpdater::GetStates, &GCAnimStateMachineUpdater::SetStates)
        .addProperty("Transitions", &GCAnimStateMachineUpdater::GetTransitions, &GCAnimStateMachineUpdater::SetTransitions)
        .addProperty("StartStateIndex", &GCAnimStateMachineUpdater::GetStartStateIndex, &GCAnimStateMachineUpdater::SetStartStateIndex)
        .addFunction("ToPtr", &GCAnimStateMachineUpdater::ToPtr)
        .addFunction("IsValid", &GCAnimStateMachineUpdater::IsValid)
        .endClass();
}