#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GNmSyncTrackTimeRange_t::GNmSyncTrackTimeRange_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GNmSyncTrackTimeRange_t::GNmSyncTrackTimeRange_t(void *ptr) {
    m_ptr = ptr;
}
GNmSyncTrackTime_t GNmSyncTrackTimeRange_t::GetStartTime() const {
    GNmSyncTrackTime_t value(GetSchemaPtr(m_ptr, "NmSyncTrackTimeRange_t", "m_startTime"));
    return value;
}
void GNmSyncTrackTimeRange_t::SetStartTime(GNmSyncTrackTime_t value) {
    SetSchemaValue(m_ptr, "NmSyncTrackTimeRange_t", "m_startTime", true, value);
}
GNmSyncTrackTime_t GNmSyncTrackTimeRange_t::GetEndTime() const {
    GNmSyncTrackTime_t value(GetSchemaPtr(m_ptr, "NmSyncTrackTimeRange_t", "m_endTime"));
    return value;
}
void GNmSyncTrackTimeRange_t::SetEndTime(GNmSyncTrackTime_t value) {
    SetSchemaValue(m_ptr, "NmSyncTrackTimeRange_t", "m_endTime", true, value);
}
std::string GNmSyncTrackTimeRange_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GNmSyncTrackTimeRange_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassNmSyncTrackTimeRange_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNmSyncTrackTimeRange_t>("NmSyncTrackTimeRange_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartTime", &GNmSyncTrackTimeRange_t::GetStartTime, &GNmSyncTrackTimeRange_t::SetStartTime)
        .addProperty("EndTime", &GNmSyncTrackTimeRange_t::GetEndTime, &GNmSyncTrackTimeRange_t::SetEndTime)
        .addFunction("ToPtr", &GNmSyncTrackTimeRange_t::ToPtr)
        .addFunction("IsValid", &GNmSyncTrackTimeRange_t::IsValid)
        .endClass();
}