#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GTimedEvent::GTimedEvent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GTimedEvent::GTimedEvent(void *ptr) {
    m_ptr = ptr;
}
float GTimedEvent::GetTimeBetweenEvents() const {
    return GetSchemaValue<float>(m_ptr, "TimedEvent", "m_TimeBetweenEvents");
}
void GTimedEvent::SetTimeBetweenEvents(float value) {
    SetSchemaValue(m_ptr, "TimedEvent", "m_TimeBetweenEvents", false, value);
}
float GTimedEvent::GetNextEvent() const {
    return GetSchemaValue<float>(m_ptr, "TimedEvent", "m_fNextEvent");
}
void GTimedEvent::SetNextEvent(float value) {
    SetSchemaValue(m_ptr, "TimedEvent", "m_fNextEvent", false, value);
}
std::string GTimedEvent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GTimedEvent::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassTimedEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTimedEvent>("TimedEvent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TimeBetweenEvents", &GTimedEvent::GetTimeBetweenEvents, &GTimedEvent::SetTimeBetweenEvents)
        .addProperty("NextEvent", &GTimedEvent::GetNextEvent, &GTimedEvent::SetNextEvent)
        .addFunction("ToPtr", &GTimedEvent::ToPtr)
        .addFunction("IsValid", &GTimedEvent::IsValid)
        .endClass();
}