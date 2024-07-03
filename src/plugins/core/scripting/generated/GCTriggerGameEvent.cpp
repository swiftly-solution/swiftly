#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerGameEvent::GCTriggerGameEvent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerGameEvent::GCTriggerGameEvent(void *ptr) {
    m_ptr = ptr;
}
std::string GCTriggerGameEvent::GetStrStartTouchEventName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CTriggerGameEvent", "m_strStartTouchEventName").Get();
}
void GCTriggerGameEvent::SetStrStartTouchEventName(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerGameEvent", "m_strStartTouchEventName", false, CUtlString(value.c_str()));
}
std::string GCTriggerGameEvent::GetStrEndTouchEventName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CTriggerGameEvent", "m_strEndTouchEventName").Get();
}
void GCTriggerGameEvent::SetStrEndTouchEventName(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerGameEvent", "m_strEndTouchEventName", false, CUtlString(value.c_str()));
}
std::string GCTriggerGameEvent::GetStrTriggerID() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CTriggerGameEvent", "m_strTriggerID").Get();
}
void GCTriggerGameEvent::SetStrTriggerID(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerGameEvent", "m_strTriggerID", false, CUtlString(value.c_str()));
}
std::string GCTriggerGameEvent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerGameEvent::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerGameEvent::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerGameEvent::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerGameEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerGameEvent>("CTriggerGameEvent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StrStartTouchEventName", &GCTriggerGameEvent::GetStrStartTouchEventName, &GCTriggerGameEvent::SetStrStartTouchEventName)
        .addProperty("StrEndTouchEventName", &GCTriggerGameEvent::GetStrEndTouchEventName, &GCTriggerGameEvent::SetStrEndTouchEventName)
        .addProperty("StrTriggerID", &GCTriggerGameEvent::GetStrTriggerID, &GCTriggerGameEvent::SetStrTriggerID)
        .addProperty("Parent", &GCTriggerGameEvent::GetParent, &GCTriggerGameEvent::SetParent)
        .addFunction("ToPtr", &GCTriggerGameEvent::ToPtr)
        .addFunction("IsValid", &GCTriggerGameEvent::IsValid)
        .endClass();
}