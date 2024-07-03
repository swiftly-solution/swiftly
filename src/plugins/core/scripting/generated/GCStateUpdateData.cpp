#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStateUpdateData::GCStateUpdateData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStateUpdateData::GCStateUpdateData(void *ptr) {
    m_ptr = ptr;
}
std::string GCStateUpdateData::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CStateUpdateData", "m_name").Get();
}
void GCStateUpdateData::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CStateUpdateData", "m_name", false, CUtlString(value.c_str()));
}
GAnimScriptHandle GCStateUpdateData::GetScript() const {
    GAnimScriptHandle value(GetSchemaPtr(m_ptr, "CStateUpdateData", "m_hScript"));
    return value;
}
void GCStateUpdateData::SetScript(GAnimScriptHandle value) {
    SetSchemaValue(m_ptr, "CStateUpdateData", "m_hScript", false, value);
}
std::vector<int32> GCStateUpdateData::GetTransitionIndices() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CStateUpdateData", "m_transitionIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCStateUpdateData::SetTransitionIndices(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CStateUpdateData", "m_transitionIndices", false, value);
}
std::vector<GCStateActionUpdater> GCStateUpdateData::GetActions() const {
    CUtlVector<GCStateActionUpdater>* vec = GetSchemaValue<CUtlVector<GCStateActionUpdater>*>(m_ptr, "CStateUpdateData", "m_actions"); std::vector<GCStateActionUpdater> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCStateUpdateData::SetActions(std::vector<GCStateActionUpdater> value) {
    SetSchemaValueCUtlVector<GCStateActionUpdater>(m_ptr, "CStateUpdateData", "m_actions", false, value);
}
GAnimStateID GCStateUpdateData::GetStateID() const {
    GAnimStateID value(GetSchemaPtr(m_ptr, "CStateUpdateData", "m_stateID"));
    return value;
}
void GCStateUpdateData::SetStateID(GAnimStateID value) {
    SetSchemaValue(m_ptr, "CStateUpdateData", "m_stateID", false, value);
}
std::string GCStateUpdateData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStateUpdateData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCStateUpdateData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateUpdateData>("CStateUpdateData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCStateUpdateData::GetName, &GCStateUpdateData::SetName)
        .addProperty("Script", &GCStateUpdateData::GetScript, &GCStateUpdateData::SetScript)
        .addProperty("TransitionIndices", &GCStateUpdateData::GetTransitionIndices, &GCStateUpdateData::SetTransitionIndices)
        .addProperty("Actions", &GCStateUpdateData::GetActions, &GCStateUpdateData::SetActions)
        .addProperty("StateID", &GCStateUpdateData::GetStateID, &GCStateUpdateData::SetStateID)
        .addFunction("ToPtr", &GCStateUpdateData::ToPtr)
        .addFunction("IsValid", &GCStateUpdateData::IsValid)
        .endClass();
}