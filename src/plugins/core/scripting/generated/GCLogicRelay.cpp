#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicRelay::GCLogicRelay(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicRelay::GCLogicRelay(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCLogicRelay::GetOnTrigger() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicRelay", "m_OnTrigger"));
    return value;
}
void GCLogicRelay::SetOnTrigger(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicRelay", "m_OnTrigger", false, value);
}
GCEntityIOOutput GCLogicRelay::GetOnSpawn() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicRelay", "m_OnSpawn"));
    return value;
}
void GCLogicRelay::SetOnSpawn(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicRelay", "m_OnSpawn", false, value);
}
bool GCLogicRelay::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicRelay", "m_bDisabled");
}
void GCLogicRelay::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CLogicRelay", "m_bDisabled", false, value);
}
bool GCLogicRelay::GetWaitForRefire() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicRelay", "m_bWaitForRefire");
}
void GCLogicRelay::SetWaitForRefire(bool value) {
    SetSchemaValue(m_ptr, "CLogicRelay", "m_bWaitForRefire", false, value);
}
bool GCLogicRelay::GetTriggerOnce() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicRelay", "m_bTriggerOnce");
}
void GCLogicRelay::SetTriggerOnce(bool value) {
    SetSchemaValue(m_ptr, "CLogicRelay", "m_bTriggerOnce", false, value);
}
bool GCLogicRelay::GetFastRetrigger() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicRelay", "m_bFastRetrigger");
}
void GCLogicRelay::SetFastRetrigger(bool value) {
    SetSchemaValue(m_ptr, "CLogicRelay", "m_bFastRetrigger", false, value);
}
bool GCLogicRelay::GetPassthoughCaller() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicRelay", "m_bPassthoughCaller");
}
void GCLogicRelay::SetPassthoughCaller(bool value) {
    SetSchemaValue(m_ptr, "CLogicRelay", "m_bPassthoughCaller", false, value);
}
std::string GCLogicRelay::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicRelay::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicRelay::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicRelay::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicRelay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicRelay>("CLogicRelay")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnTrigger", &GCLogicRelay::GetOnTrigger, &GCLogicRelay::SetOnTrigger)
        .addProperty("OnSpawn", &GCLogicRelay::GetOnSpawn, &GCLogicRelay::SetOnSpawn)
        .addProperty("Disabled", &GCLogicRelay::GetDisabled, &GCLogicRelay::SetDisabled)
        .addProperty("WaitForRefire", &GCLogicRelay::GetWaitForRefire, &GCLogicRelay::SetWaitForRefire)
        .addProperty("TriggerOnce", &GCLogicRelay::GetTriggerOnce, &GCLogicRelay::SetTriggerOnce)
        .addProperty("FastRetrigger", &GCLogicRelay::GetFastRetrigger, &GCLogicRelay::SetFastRetrigger)
        .addProperty("PassthoughCaller", &GCLogicRelay::GetPassthoughCaller, &GCLogicRelay::SetPassthoughCaller)
        .addProperty("Parent", &GCLogicRelay::GetParent, &GCLogicRelay::SetParent)
        .addFunction("ToPtr", &GCLogicRelay::ToPtr)
        .addFunction("IsValid", &GCLogicRelay::IsValid)
        .endClass();
}