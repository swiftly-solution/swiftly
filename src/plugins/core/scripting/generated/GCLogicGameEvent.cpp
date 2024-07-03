#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicGameEvent::GCLogicGameEvent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicGameEvent::GCLogicGameEvent(void *ptr) {
    m_ptr = ptr;
}
std::string GCLogicGameEvent::GetEventName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicGameEvent", "m_iszEventName").String();
}
void GCLogicGameEvent::SetEventName(std::string value) {
    SetSchemaValue(m_ptr, "CLogicGameEvent", "m_iszEventName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCLogicGameEvent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicGameEvent::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicGameEvent::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicGameEvent::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicGameEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicGameEvent>("CLogicGameEvent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EventName", &GCLogicGameEvent::GetEventName, &GCLogicGameEvent::SetEventName)
        .addProperty("Parent", &GCLogicGameEvent::GetParent, &GCLogicGameEvent::SetParent)
        .addFunction("ToPtr", &GCLogicGameEvent::ToPtr)
        .addFunction("IsValid", &GCLogicGameEvent::IsValid)
        .endClass();
}