#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GNmSyncTrackTime_t::GNmSyncTrackTime_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GNmSyncTrackTime_t::GNmSyncTrackTime_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GNmSyncTrackTime_t::GetEventIdx() const {
    return GetSchemaValue<int32_t>(m_ptr, "NmSyncTrackTime_t", "m_nEventIdx");
}
void GNmSyncTrackTime_t::SetEventIdx(int32_t value) {
    SetSchemaValue(m_ptr, "NmSyncTrackTime_t", "m_nEventIdx", true, value);
}
GNmPercent_t GNmSyncTrackTime_t::GetPercentageThrough() const {
    GNmPercent_t value(GetSchemaPtr(m_ptr, "NmSyncTrackTime_t", "m_percentageThrough"));
    return value;
}
void GNmSyncTrackTime_t::SetPercentageThrough(GNmPercent_t value) {
    SetSchemaValue(m_ptr, "NmSyncTrackTime_t", "m_percentageThrough", true, value);
}
std::string GNmSyncTrackTime_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GNmSyncTrackTime_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassNmSyncTrackTime_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNmSyncTrackTime_t>("NmSyncTrackTime_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EventIdx", &GNmSyncTrackTime_t::GetEventIdx, &GNmSyncTrackTime_t::SetEventIdx)
        .addProperty("PercentageThrough", &GNmSyncTrackTime_t::GetPercentageThrough, &GNmSyncTrackTime_t::SetPercentageThrough)
        .addFunction("ToPtr", &GNmSyncTrackTime_t::ToPtr)
        .addFunction("IsValid", &GNmSyncTrackTime_t::IsValid)
        .endClass();
}