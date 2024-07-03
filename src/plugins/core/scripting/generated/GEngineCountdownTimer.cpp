#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEngineCountdownTimer::GEngineCountdownTimer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEngineCountdownTimer::GEngineCountdownTimer(void *ptr) {
    m_ptr = ptr;
}
float GEngineCountdownTimer::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "EngineCountdownTimer", "m_duration");
}
void GEngineCountdownTimer::SetDuration(float value) {
    SetSchemaValue(m_ptr, "EngineCountdownTimer", "m_duration", false, value);
}
float GEngineCountdownTimer::GetTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "EngineCountdownTimer", "m_timestamp");
}
void GEngineCountdownTimer::SetTimestamp(float value) {
    SetSchemaValue(m_ptr, "EngineCountdownTimer", "m_timestamp", false, value);
}
float GEngineCountdownTimer::GetTimescale() const {
    return GetSchemaValue<float>(m_ptr, "EngineCountdownTimer", "m_timescale");
}
void GEngineCountdownTimer::SetTimescale(float value) {
    SetSchemaValue(m_ptr, "EngineCountdownTimer", "m_timescale", false, value);
}
std::string GEngineCountdownTimer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEngineCountdownTimer::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEngineCountdownTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEngineCountdownTimer>("EngineCountdownTimer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Duration", &GEngineCountdownTimer::GetDuration, &GEngineCountdownTimer::SetDuration)
        .addProperty("Timestamp", &GEngineCountdownTimer::GetTimestamp, &GEngineCountdownTimer::SetTimestamp)
        .addProperty("Timescale", &GEngineCountdownTimer::GetTimescale, &GEngineCountdownTimer::SetTimescale)
        .addFunction("ToPtr", &GEngineCountdownTimer::ToPtr)
        .addFunction("IsValid", &GEngineCountdownTimer::IsValid)
        .endClass();
}