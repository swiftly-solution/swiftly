#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmEvent::GCNmEvent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmEvent::GCNmEvent(void *ptr) {
    m_ptr = ptr;
}
float GCNmEvent::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CNmEvent", "m_flStartTime");
}
void GCNmEvent::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CNmEvent", "m_flStartTime", false, value);
}
float GCNmEvent::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CNmEvent", "m_flDuration");
}
void GCNmEvent::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CNmEvent", "m_flDuration", false, value);
}
std::string GCNmEvent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmEvent::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmEvent>("CNmEvent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartTime", &GCNmEvent::GetStartTime, &GCNmEvent::SetStartTime)
        .addProperty("Duration", &GCNmEvent::GetDuration, &GCNmEvent::SetDuration)
        .addFunction("ToPtr", &GCNmEvent::ToPtr)
        .addFunction("IsValid", &GCNmEvent::IsValid)
        .endClass();
}