#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmSyncTrack__EventMarker_t::GCNmSyncTrack__EventMarker_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmSyncTrack__EventMarker_t::GCNmSyncTrack__EventMarker_t(void *ptr) {
    m_ptr = ptr;
}
GNmPercent_t GCNmSyncTrack__EventMarker_t::GetStartTime() const {
    GNmPercent_t value(GetSchemaPtr(m_ptr, "CNmSyncTrack__EventMarker_t", "m_startTime"));
    return value;
}
void GCNmSyncTrack__EventMarker_t::SetStartTime(GNmPercent_t value) {
    SetSchemaValue(m_ptr, "CNmSyncTrack__EventMarker_t", "m_startTime", true, value);
}
std::string GCNmSyncTrack__EventMarker_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmSyncTrack__EventMarker_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmSyncTrack__EventMarker_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmSyncTrack__EventMarker_t>("CNmSyncTrack__EventMarker_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartTime", &GCNmSyncTrack__EventMarker_t::GetStartTime, &GCNmSyncTrack__EventMarker_t::SetStartTime)
        .addFunction("ToPtr", &GCNmSyncTrack__EventMarker_t::ToPtr)
        .addFunction("IsValid", &GCNmSyncTrack__EventMarker_t::IsValid)
        .endClass();
}