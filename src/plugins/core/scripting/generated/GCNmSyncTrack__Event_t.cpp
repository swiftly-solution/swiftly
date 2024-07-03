#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmSyncTrack__Event_t::GCNmSyncTrack__Event_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmSyncTrack__Event_t::GCNmSyncTrack__Event_t(void *ptr) {
    m_ptr = ptr;
}
GNmPercent_t GCNmSyncTrack__Event_t::GetStartTime() const {
    GNmPercent_t value(GetSchemaPtr(m_ptr, "CNmSyncTrack__Event_t", "m_startTime"));
    return value;
}
void GCNmSyncTrack__Event_t::SetStartTime(GNmPercent_t value) {
    SetSchemaValue(m_ptr, "CNmSyncTrack__Event_t", "m_startTime", true, value);
}
GNmPercent_t GCNmSyncTrack__Event_t::GetDuration() const {
    GNmPercent_t value(GetSchemaPtr(m_ptr, "CNmSyncTrack__Event_t", "m_duration"));
    return value;
}
void GCNmSyncTrack__Event_t::SetDuration(GNmPercent_t value) {
    SetSchemaValue(m_ptr, "CNmSyncTrack__Event_t", "m_duration", true, value);
}
std::string GCNmSyncTrack__Event_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmSyncTrack__Event_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmSyncTrack__Event_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmSyncTrack__Event_t>("CNmSyncTrack__Event_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartTime", &GCNmSyncTrack__Event_t::GetStartTime, &GCNmSyncTrack__Event_t::SetStartTime)
        .addProperty("Duration", &GCNmSyncTrack__Event_t::GetDuration, &GCNmSyncTrack__Event_t::SetDuration)
        .addFunction("ToPtr", &GCNmSyncTrack__Event_t::ToPtr)
        .addFunction("IsValid", &GCNmSyncTrack__Event_t::IsValid)
        .endClass();
}