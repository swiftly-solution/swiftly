#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayerController_ActionTrackingServices::GCCSPlayerController_ActionTrackingServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayerController_ActionTrackingServices::GCCSPlayerController_ActionTrackingServices(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCSPerRoundStats_t> GCCSPlayerController_ActionTrackingServices::GetPerRoundStats() const {
    CUtlVector<GCSPerRoundStats_t>* vec = GetSchemaValue<CUtlVector<GCSPerRoundStats_t>*>(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_perRoundStats"); std::vector<GCSPerRoundStats_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSPlayerController_ActionTrackingServices::SetPerRoundStats(std::vector<GCSPerRoundStats_t> value) {
    SetSchemaValueCUtlVector<GCSPerRoundStats_t>(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_perRoundStats", false, value);
}
GCSMatchStats_t GCCSPlayerController_ActionTrackingServices::GetMatchStats() const {
    GCSMatchStats_t value(GetSchemaPtr(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_matchStats"));
    return value;
}
void GCCSPlayerController_ActionTrackingServices::SetMatchStats(GCSMatchStats_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_matchStats", false, value);
}
int32_t GCCSPlayerController_ActionTrackingServices::GetNumRoundKills() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_iNumRoundKills");
}
void GCCSPlayerController_ActionTrackingServices::SetNumRoundKills(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_iNumRoundKills", false, value);
}
int32_t GCCSPlayerController_ActionTrackingServices::GetNumRoundKillsHeadshots() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_iNumRoundKillsHeadshots");
}
void GCCSPlayerController_ActionTrackingServices::SetNumRoundKillsHeadshots(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_iNumRoundKillsHeadshots", false, value);
}
uint32_t GCCSPlayerController_ActionTrackingServices::GetTotalRoundDamageDealt() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_unTotalRoundDamageDealt");
}
void GCCSPlayerController_ActionTrackingServices::SetTotalRoundDamageDealt(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_unTotalRoundDamageDealt", false, value);
}
std::string GCCSPlayerController_ActionTrackingServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayerController_ActionTrackingServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerControllerComponent GCCSPlayerController_ActionTrackingServices::GetParent() const {
    GCPlayerControllerComponent value(m_ptr);
    return value;
}
void GCCSPlayerController_ActionTrackingServices::SetParent(GCPlayerControllerComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayerController_ActionTrackingServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerController_ActionTrackingServices>("CCSPlayerController_ActionTrackingServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PerRoundStats", &GCCSPlayerController_ActionTrackingServices::GetPerRoundStats, &GCCSPlayerController_ActionTrackingServices::SetPerRoundStats)
        .addProperty("MatchStats", &GCCSPlayerController_ActionTrackingServices::GetMatchStats, &GCCSPlayerController_ActionTrackingServices::SetMatchStats)
        .addProperty("NumRoundKills", &GCCSPlayerController_ActionTrackingServices::GetNumRoundKills, &GCCSPlayerController_ActionTrackingServices::SetNumRoundKills)
        .addProperty("NumRoundKillsHeadshots", &GCCSPlayerController_ActionTrackingServices::GetNumRoundKillsHeadshots, &GCCSPlayerController_ActionTrackingServices::SetNumRoundKillsHeadshots)
        .addProperty("TotalRoundDamageDealt", &GCCSPlayerController_ActionTrackingServices::GetTotalRoundDamageDealt, &GCCSPlayerController_ActionTrackingServices::SetTotalRoundDamageDealt)
        .addProperty("Parent", &GCCSPlayerController_ActionTrackingServices::GetParent, &GCCSPlayerController_ActionTrackingServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayerController_ActionTrackingServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayerController_ActionTrackingServices::IsValid)
        .endClass();
}