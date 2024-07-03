#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIntervalTimer::GIntervalTimer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIntervalTimer::GIntervalTimer(void *ptr) {
    m_ptr = ptr;
}
float GIntervalTimer::GetTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "IntervalTimer", "m_timestamp");
}
void GIntervalTimer::SetTimestamp(float value) {
    SetSchemaValue(m_ptr, "IntervalTimer", "m_timestamp", false, value);
}
WorldGroupId_t GIntervalTimer::GetWorldGroupId() const {
    return GetSchemaValue<WorldGroupId_t>(m_ptr, "IntervalTimer", "m_nWorldGroupId");
}
void GIntervalTimer::SetWorldGroupId(WorldGroupId_t value) {
    SetSchemaValue(m_ptr, "IntervalTimer", "m_nWorldGroupId", false, value);
}
std::string GIntervalTimer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIntervalTimer::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIntervalTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIntervalTimer>("IntervalTimer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Timestamp", &GIntervalTimer::GetTimestamp, &GIntervalTimer::SetTimestamp)
        .addProperty("WorldGroupId", &GIntervalTimer::GetWorldGroupId, &GIntervalTimer::SetWorldGroupId)
        .addFunction("ToPtr", &GIntervalTimer::ToPtr)
        .addFunction("IsValid", &GIntervalTimer::IsValid)
        .endClass();
}