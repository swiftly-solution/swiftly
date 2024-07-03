#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSMatchStats_t::GCSMatchStats_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSMatchStats_t::GCSMatchStats_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSMatchStats_t::GetEnemy5Ks() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemy5Ks");
}
void GCSMatchStats_t::SetEnemy5Ks(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemy5Ks", true, value);
}
int32_t GCSMatchStats_t::GetEnemy4Ks() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemy4Ks");
}
void GCSMatchStats_t::SetEnemy4Ks(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemy4Ks", true, value);
}
int32_t GCSMatchStats_t::GetEnemy3Ks() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemy3Ks");
}
void GCSMatchStats_t::SetEnemy3Ks(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemy3Ks", true, value);
}
int32_t GCSMatchStats_t::GetEnemyKnifeKills() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemyKnifeKills");
}
void GCSMatchStats_t::SetEnemyKnifeKills(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemyKnifeKills", true, value);
}
int32_t GCSMatchStats_t::GetEnemyTaserKills() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemyTaserKills");
}
void GCSMatchStats_t::SetEnemyTaserKills(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemyTaserKills", true, value);
}
int32_t GCSMatchStats_t::GetEnemy2Ks() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemy2Ks");
}
void GCSMatchStats_t::SetEnemy2Ks(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemy2Ks", true, value);
}
int32_t GCSMatchStats_t::GetUtility_Count() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iUtility_Count");
}
void GCSMatchStats_t::SetUtility_Count(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iUtility_Count", true, value);
}
int32_t GCSMatchStats_t::GetUtility_Successes() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iUtility_Successes");
}
void GCSMatchStats_t::SetUtility_Successes(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iUtility_Successes", true, value);
}
int32_t GCSMatchStats_t::GetUtility_Enemies() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iUtility_Enemies");
}
void GCSMatchStats_t::SetUtility_Enemies(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iUtility_Enemies", true, value);
}
int32_t GCSMatchStats_t::GetFlash_Count() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iFlash_Count");
}
void GCSMatchStats_t::SetFlash_Count(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iFlash_Count", true, value);
}
int32_t GCSMatchStats_t::GetFlash_Successes() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iFlash_Successes");
}
void GCSMatchStats_t::SetFlash_Successes(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iFlash_Successes", true, value);
}
int32_t GCSMatchStats_t::GetHealthPointsRemovedTotal() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_nHealthPointsRemovedTotal");
}
void GCSMatchStats_t::SetHealthPointsRemovedTotal(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_nHealthPointsRemovedTotal", true, value);
}
int32_t GCSMatchStats_t::GetHealthPointsDealtTotal() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_nHealthPointsDealtTotal");
}
void GCSMatchStats_t::SetHealthPointsDealtTotal(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_nHealthPointsDealtTotal", true, value);
}
int32_t GCSMatchStats_t::GetShotsFiredTotal() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_nShotsFiredTotal");
}
void GCSMatchStats_t::SetShotsFiredTotal(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_nShotsFiredTotal", true, value);
}
int32_t GCSMatchStats_t::GetShotsOnTargetTotal() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_nShotsOnTargetTotal");
}
void GCSMatchStats_t::SetShotsOnTargetTotal(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_nShotsOnTargetTotal", true, value);
}
int32_t GCSMatchStats_t::Get1v1Count() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_i1v1Count");
}
void GCSMatchStats_t::Set1v1Count(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_i1v1Count", true, value);
}
int32_t GCSMatchStats_t::Get1v1Wins() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_i1v1Wins");
}
void GCSMatchStats_t::Set1v1Wins(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_i1v1Wins", true, value);
}
int32_t GCSMatchStats_t::Get1v2Count() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_i1v2Count");
}
void GCSMatchStats_t::Set1v2Count(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_i1v2Count", true, value);
}
int32_t GCSMatchStats_t::Get1v2Wins() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_i1v2Wins");
}
void GCSMatchStats_t::Set1v2Wins(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_i1v2Wins", true, value);
}
int32_t GCSMatchStats_t::GetEntryCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEntryCount");
}
void GCSMatchStats_t::SetEntryCount(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEntryCount", true, value);
}
int32_t GCSMatchStats_t::GetEntryWins() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEntryWins");
}
void GCSMatchStats_t::SetEntryWins(int32_t value) {
    SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEntryWins", true, value);
}
std::string GCSMatchStats_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSMatchStats_t::IsValid() {
    return (m_ptr != nullptr);
}
GCSPerRoundStats_t GCSMatchStats_t::GetParent() const {
    GCSPerRoundStats_t value(m_ptr);
    return value;
}
void GCSMatchStats_t::SetParent(GCSPerRoundStats_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSMatchStats_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSMatchStats_t>("CSMatchStats_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Enemy5Ks", &GCSMatchStats_t::GetEnemy5Ks, &GCSMatchStats_t::SetEnemy5Ks)
        .addProperty("Enemy4Ks", &GCSMatchStats_t::GetEnemy4Ks, &GCSMatchStats_t::SetEnemy4Ks)
        .addProperty("Enemy3Ks", &GCSMatchStats_t::GetEnemy3Ks, &GCSMatchStats_t::SetEnemy3Ks)
        .addProperty("EnemyKnifeKills", &GCSMatchStats_t::GetEnemyKnifeKills, &GCSMatchStats_t::SetEnemyKnifeKills)
        .addProperty("EnemyTaserKills", &GCSMatchStats_t::GetEnemyTaserKills, &GCSMatchStats_t::SetEnemyTaserKills)
        .addProperty("Enemy2Ks", &GCSMatchStats_t::GetEnemy2Ks, &GCSMatchStats_t::SetEnemy2Ks)
        .addProperty("Utility_Count", &GCSMatchStats_t::GetUtility_Count, &GCSMatchStats_t::SetUtility_Count)
        .addProperty("Utility_Successes", &GCSMatchStats_t::GetUtility_Successes, &GCSMatchStats_t::SetUtility_Successes)
        .addProperty("Utility_Enemies", &GCSMatchStats_t::GetUtility_Enemies, &GCSMatchStats_t::SetUtility_Enemies)
        .addProperty("Flash_Count", &GCSMatchStats_t::GetFlash_Count, &GCSMatchStats_t::SetFlash_Count)
        .addProperty("Flash_Successes", &GCSMatchStats_t::GetFlash_Successes, &GCSMatchStats_t::SetFlash_Successes)
        .addProperty("HealthPointsRemovedTotal", &GCSMatchStats_t::GetHealthPointsRemovedTotal, &GCSMatchStats_t::SetHealthPointsRemovedTotal)
        .addProperty("HealthPointsDealtTotal", &GCSMatchStats_t::GetHealthPointsDealtTotal, &GCSMatchStats_t::SetHealthPointsDealtTotal)
        .addProperty("ShotsFiredTotal", &GCSMatchStats_t::GetShotsFiredTotal, &GCSMatchStats_t::SetShotsFiredTotal)
        .addProperty("ShotsOnTargetTotal", &GCSMatchStats_t::GetShotsOnTargetTotal, &GCSMatchStats_t::SetShotsOnTargetTotal)
        .addProperty("1v1Count", &GCSMatchStats_t::Get1v1Count, &GCSMatchStats_t::Set1v1Count)
        .addProperty("1v1Wins", &GCSMatchStats_t::Get1v1Wins, &GCSMatchStats_t::Set1v1Wins)
        .addProperty("1v2Count", &GCSMatchStats_t::Get1v2Count, &GCSMatchStats_t::Set1v2Count)
        .addProperty("1v2Wins", &GCSMatchStats_t::Get1v2Wins, &GCSMatchStats_t::Set1v2Wins)
        .addProperty("EntryCount", &GCSMatchStats_t::GetEntryCount, &GCSMatchStats_t::SetEntryCount)
        .addProperty("EntryWins", &GCSMatchStats_t::GetEntryWins, &GCSMatchStats_t::SetEntryWins)
        .addProperty("Parent", &GCSMatchStats_t::GetParent, &GCSMatchStats_t::SetParent)
        .addFunction("ToPtr", &GCSMatchStats_t::ToPtr)
        .addFunction("IsValid", &GCSMatchStats_t::IsValid)
        .endClass();
}