#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicGameEventListener::GCLogicGameEventListener(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicGameEventListener::GCLogicGameEventListener(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCLogicGameEventListener::GetOnEventFired() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicGameEventListener", "m_OnEventFired"));
    return value;
}
void GCLogicGameEventListener::SetOnEventFired(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicGameEventListener", "m_OnEventFired", false, value);
}
std::string GCLogicGameEventListener::GetGameEventName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicGameEventListener", "m_iszGameEventName").String();
}
void GCLogicGameEventListener::SetGameEventName(std::string value) {
    SetSchemaValue(m_ptr, "CLogicGameEventListener", "m_iszGameEventName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCLogicGameEventListener::GetGameEventItem() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicGameEventListener", "m_iszGameEventItem").String();
}
void GCLogicGameEventListener::SetGameEventItem(std::string value) {
    SetSchemaValue(m_ptr, "CLogicGameEventListener", "m_iszGameEventItem", false, CUtlSymbolLarge(value.c_str()));
}
bool GCLogicGameEventListener::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicGameEventListener", "m_bEnabled");
}
void GCLogicGameEventListener::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CLogicGameEventListener", "m_bEnabled", false, value);
}
bool GCLogicGameEventListener::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicGameEventListener", "m_bStartDisabled");
}
void GCLogicGameEventListener::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CLogicGameEventListener", "m_bStartDisabled", false, value);
}
std::string GCLogicGameEventListener::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicGameEventListener::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicGameEventListener::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicGameEventListener::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicGameEventListener(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicGameEventListener>("CLogicGameEventListener")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnEventFired", &GCLogicGameEventListener::GetOnEventFired, &GCLogicGameEventListener::SetOnEventFired)
        .addProperty("GameEventName", &GCLogicGameEventListener::GetGameEventName, &GCLogicGameEventListener::SetGameEventName)
        .addProperty("GameEventItem", &GCLogicGameEventListener::GetGameEventItem, &GCLogicGameEventListener::SetGameEventItem)
        .addProperty("Enabled", &GCLogicGameEventListener::GetEnabled, &GCLogicGameEventListener::SetEnabled)
        .addProperty("StartDisabled", &GCLogicGameEventListener::GetStartDisabled, &GCLogicGameEventListener::SetStartDisabled)
        .addProperty("Parent", &GCLogicGameEventListener::GetParent, &GCLogicGameEventListener::SetParent)
        .addFunction("ToPtr", &GCLogicGameEventListener::ToPtr)
        .addFunction("IsValid", &GCLogicGameEventListener::IsValid)
        .endClass();
}