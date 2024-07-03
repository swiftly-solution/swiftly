#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSPerRoundStats_t::GCSPerRoundStats_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSPerRoundStats_t::GCSPerRoundStats_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSPerRoundStats_t::GetKills() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iKills");
}
void GCSPerRoundStats_t::SetKills(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iKills", true, value);
}
int32_t GCSPerRoundStats_t::GetDeaths() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iDeaths");
}
void GCSPerRoundStats_t::SetDeaths(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iDeaths", true, value);
}
int32_t GCSPerRoundStats_t::GetAssists() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iAssists");
}
void GCSPerRoundStats_t::SetAssists(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iAssists", true, value);
}
int32_t GCSPerRoundStats_t::GetDamage() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iDamage");
}
void GCSPerRoundStats_t::SetDamage(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iDamage", true, value);
}
int32_t GCSPerRoundStats_t::GetEquipmentValue() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iEquipmentValue");
}
void GCSPerRoundStats_t::SetEquipmentValue(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iEquipmentValue", true, value);
}
int32_t GCSPerRoundStats_t::GetMoneySaved() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iMoneySaved");
}
void GCSPerRoundStats_t::SetMoneySaved(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iMoneySaved", true, value);
}
int32_t GCSPerRoundStats_t::GetKillReward() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iKillReward");
}
void GCSPerRoundStats_t::SetKillReward(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iKillReward", true, value);
}
int32_t GCSPerRoundStats_t::GetLiveTime() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iLiveTime");
}
void GCSPerRoundStats_t::SetLiveTime(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iLiveTime", true, value);
}
int32_t GCSPerRoundStats_t::GetHeadShotKills() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iHeadShotKills");
}
void GCSPerRoundStats_t::SetHeadShotKills(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iHeadShotKills", true, value);
}
int32_t GCSPerRoundStats_t::GetObjective() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iObjective");
}
void GCSPerRoundStats_t::SetObjective(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iObjective", true, value);
}
int32_t GCSPerRoundStats_t::GetCashEarned() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iCashEarned");
}
void GCSPerRoundStats_t::SetCashEarned(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iCashEarned", true, value);
}
int32_t GCSPerRoundStats_t::GetUtilityDamage() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iUtilityDamage");
}
void GCSPerRoundStats_t::SetUtilityDamage(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iUtilityDamage", true, value);
}
int32_t GCSPerRoundStats_t::GetEnemiesFlashed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSPerRoundStats_t", "m_iEnemiesFlashed");
}
void GCSPerRoundStats_t::SetEnemiesFlashed(int32_t value) {
    SetSchemaValue(m_ptr, "CSPerRoundStats_t", "m_iEnemiesFlashed", true, value);
}
std::string GCSPerRoundStats_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSPerRoundStats_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSPerRoundStats_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSPerRoundStats_t>("CSPerRoundStats_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Kills", &GCSPerRoundStats_t::GetKills, &GCSPerRoundStats_t::SetKills)
        .addProperty("Deaths", &GCSPerRoundStats_t::GetDeaths, &GCSPerRoundStats_t::SetDeaths)
        .addProperty("Assists", &GCSPerRoundStats_t::GetAssists, &GCSPerRoundStats_t::SetAssists)
        .addProperty("Damage", &GCSPerRoundStats_t::GetDamage, &GCSPerRoundStats_t::SetDamage)
        .addProperty("EquipmentValue", &GCSPerRoundStats_t::GetEquipmentValue, &GCSPerRoundStats_t::SetEquipmentValue)
        .addProperty("MoneySaved", &GCSPerRoundStats_t::GetMoneySaved, &GCSPerRoundStats_t::SetMoneySaved)
        .addProperty("KillReward", &GCSPerRoundStats_t::GetKillReward, &GCSPerRoundStats_t::SetKillReward)
        .addProperty("LiveTime", &GCSPerRoundStats_t::GetLiveTime, &GCSPerRoundStats_t::SetLiveTime)
        .addProperty("HeadShotKills", &GCSPerRoundStats_t::GetHeadShotKills, &GCSPerRoundStats_t::SetHeadShotKills)
        .addProperty("Objective", &GCSPerRoundStats_t::GetObjective, &GCSPerRoundStats_t::SetObjective)
        .addProperty("CashEarned", &GCSPerRoundStats_t::GetCashEarned, &GCSPerRoundStats_t::SetCashEarned)
        .addProperty("UtilityDamage", &GCSPerRoundStats_t::GetUtilityDamage, &GCSPerRoundStats_t::SetUtilityDamage)
        .addProperty("EnemiesFlashed", &GCSPerRoundStats_t::GetEnemiesFlashed, &GCSPerRoundStats_t::SetEnemiesFlashed)
        .addFunction("ToPtr", &GCSPerRoundStats_t::ToPtr)
        .addFunction("IsValid", &GCSPerRoundStats_t::IsValid)
        .endClass();
}