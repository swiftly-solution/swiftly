#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicEventListener::GCLogicEventListener(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicEventListener::GCLogicEventListener(void *ptr) {
    m_ptr = ptr;
}
std::string GCLogicEventListener::GetStrEventName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CLogicEventListener", "m_strEventName").Get();
}
void GCLogicEventListener::SetStrEventName(std::string value) {
    SetSchemaValue(m_ptr, "CLogicEventListener", "m_strEventName", false, CUtlString(value.c_str()));
}
bool GCLogicEventListener::GetIsEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicEventListener", "m_bIsEnabled");
}
void GCLogicEventListener::SetIsEnabled(bool value) {
    SetSchemaValue(m_ptr, "CLogicEventListener", "m_bIsEnabled", false, value);
}
int32_t GCLogicEventListener::GetTeam() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicEventListener", "m_nTeam");
}
void GCLogicEventListener::SetTeam(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicEventListener", "m_nTeam", false, value);
}
GCEntityIOOutput GCLogicEventListener::GetOnEventFired() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicEventListener", "m_OnEventFired"));
    return value;
}
void GCLogicEventListener::SetOnEventFired(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicEventListener", "m_OnEventFired", false, value);
}
std::string GCLogicEventListener::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicEventListener::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicEventListener::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicEventListener::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicEventListener(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicEventListener>("CLogicEventListener")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StrEventName", &GCLogicEventListener::GetStrEventName, &GCLogicEventListener::SetStrEventName)
        .addProperty("IsEnabled", &GCLogicEventListener::GetIsEnabled, &GCLogicEventListener::SetIsEnabled)
        .addProperty("Team", &GCLogicEventListener::GetTeam, &GCLogicEventListener::SetTeam)
        .addProperty("OnEventFired", &GCLogicEventListener::GetOnEventFired, &GCLogicEventListener::SetOnEventFired)
        .addProperty("Parent", &GCLogicEventListener::GetParent, &GCLogicEventListener::SetParent)
        .addFunction("ToPtr", &GCLogicEventListener::ToPtr)
        .addFunction("IsValid", &GCLogicEventListener::IsValid)
        .endClass();
}