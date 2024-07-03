#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCountdownTimer::GCountdownTimer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCountdownTimer::GCountdownTimer(void *ptr) {
    m_ptr = ptr;
}
float GCountdownTimer::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CountdownTimer", "m_duration");
}
void GCountdownTimer::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CountdownTimer", "m_duration", false, value);
}
float GCountdownTimer::GetTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CountdownTimer", "m_timestamp");
}
void GCountdownTimer::SetTimestamp(float value) {
    SetSchemaValue(m_ptr, "CountdownTimer", "m_timestamp", false, value);
}
float GCountdownTimer::GetTimescale() const {
    return GetSchemaValue<float>(m_ptr, "CountdownTimer", "m_timescale");
}
void GCountdownTimer::SetTimescale(float value) {
    SetSchemaValue(m_ptr, "CountdownTimer", "m_timescale", false, value);
}
WorldGroupId_t GCountdownTimer::GetWorldGroupId() const {
    return GetSchemaValue<WorldGroupId_t>(m_ptr, "CountdownTimer", "m_nWorldGroupId");
}
void GCountdownTimer::SetWorldGroupId(WorldGroupId_t value) {
    SetSchemaValue(m_ptr, "CountdownTimer", "m_nWorldGroupId", false, value);
}
std::string GCountdownTimer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCountdownTimer::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCountdownTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCountdownTimer>("CountdownTimer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Duration", &GCountdownTimer::GetDuration, &GCountdownTimer::SetDuration)
        .addProperty("Timestamp", &GCountdownTimer::GetTimestamp, &GCountdownTimer::SetTimestamp)
        .addProperty("Timescale", &GCountdownTimer::GetTimescale, &GCountdownTimer::SetTimescale)
        .addProperty("WorldGroupId", &GCountdownTimer::GetWorldGroupId, &GCountdownTimer::SetWorldGroupId)
        .addFunction("ToPtr", &GCountdownTimer::ToPtr)
        .addFunction("IsValid", &GCountdownTimer::IsValid)
        .endClass();
}