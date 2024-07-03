#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGameChoreoServices::GCGameChoreoServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGameChoreoServices::GCGameChoreoServices(void *ptr) {
    m_ptr = ptr;
}
GCBaseAnimGraph GCGameChoreoServices::GetOwner() const {
    GCBaseAnimGraph value(*GetSchemaValuePtr<void*>(m_ptr, "CGameChoreoServices", "m_hOwner"));
    return value;
}
void GCGameChoreoServices::SetOwner(GCBaseAnimGraph* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n");
}
GCScriptedSequence GCGameChoreoServices::GetScriptedSequence() const {
    GCScriptedSequence value(*GetSchemaValuePtr<void*>(m_ptr, "CGameChoreoServices", "m_hScriptedSequence"));
    return value;
}
void GCGameChoreoServices::SetScriptedSequence(GCScriptedSequence* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ScriptedSequence' is not possible.\n");
}
GIChoreoServices GCGameChoreoServices::GetScriptState() const {
    GIChoreoServices value(GetSchemaPtr(m_ptr, "CGameChoreoServices", "m_scriptState"));
    return value;
}
void GCGameChoreoServices::SetScriptState(GIChoreoServices value) {
    SetSchemaValue(m_ptr, "CGameChoreoServices", "m_scriptState", false, value);
}
GIChoreoServices GCGameChoreoServices::GetChoreoState() const {
    GIChoreoServices value(GetSchemaPtr(m_ptr, "CGameChoreoServices", "m_choreoState"));
    return value;
}
void GCGameChoreoServices::SetChoreoState(GIChoreoServices value) {
    SetSchemaValue(m_ptr, "CGameChoreoServices", "m_choreoState", false, value);
}
float GCGameChoreoServices::GetTimeStartedState() const {
    return GetSchemaValue<float>(m_ptr, "CGameChoreoServices", "m_flTimeStartedState");
}
void GCGameChoreoServices::SetTimeStartedState(float value) {
    SetSchemaValue(m_ptr, "CGameChoreoServices", "m_flTimeStartedState", false, value);
}
std::string GCGameChoreoServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGameChoreoServices::IsValid() {
    return (m_ptr != nullptr);
}
GIChoreoServices GCGameChoreoServices::GetParent() const {
    GIChoreoServices value(m_ptr);
    return value;
}
void GCGameChoreoServices::SetParent(GIChoreoServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGameChoreoServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameChoreoServices>("CGameChoreoServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Owner", &GCGameChoreoServices::GetOwner, &GCGameChoreoServices::SetOwner)
        .addProperty("ScriptedSequence", &GCGameChoreoServices::GetScriptedSequence, &GCGameChoreoServices::SetScriptedSequence)
        .addProperty("ScriptState", &GCGameChoreoServices::GetScriptState, &GCGameChoreoServices::SetScriptState)
        .addProperty("ChoreoState", &GCGameChoreoServices::GetChoreoState, &GCGameChoreoServices::SetChoreoState)
        .addProperty("TimeStartedState", &GCGameChoreoServices::GetTimeStartedState, &GCGameChoreoServices::SetTimeStartedState)
        .addProperty("Parent", &GCGameChoreoServices::GetParent, &GCGameChoreoServices::SetParent)
        .addFunction("ToPtr", &GCGameChoreoServices::ToPtr)
        .addFunction("IsValid", &GCGameChoreoServices::IsValid)
        .endClass();
}