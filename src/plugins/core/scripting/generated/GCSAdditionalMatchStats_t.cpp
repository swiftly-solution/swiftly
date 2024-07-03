#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSAdditionalMatchStats_t::GCSAdditionalMatchStats_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSAdditionalMatchStats_t::GCSAdditionalMatchStats_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSAdditionalMatchStats_t::GetNumRoundsSurvived() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numRoundsSurvived");
}
void GCSAdditionalMatchStats_t::SetNumRoundsSurvived(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numRoundsSurvived", true, value);
}
int32_t GCSAdditionalMatchStats_t::GetMaxNumRoundsSurvived() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_maxNumRoundsSurvived");
}
void GCSAdditionalMatchStats_t::SetMaxNumRoundsSurvived(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_maxNumRoundsSurvived", true, value);
}
int32_t GCSAdditionalMatchStats_t::GetNumRoundsSurvivedTotal() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numRoundsSurvivedTotal");
}
void GCSAdditionalMatchStats_t::SetNumRoundsSurvivedTotal(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numRoundsSurvivedTotal", true, value);
}
int32_t GCSAdditionalMatchStats_t::GetRoundsWonWithoutPurchase() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_iRoundsWonWithoutPurchase");
}
void GCSAdditionalMatchStats_t::SetRoundsWonWithoutPurchase(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_iRoundsWonWithoutPurchase", true, value);
}
int32_t GCSAdditionalMatchStats_t::GetRoundsWonWithoutPurchaseTotal() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_iRoundsWonWithoutPurchaseTotal");
}
void GCSAdditionalMatchStats_t::SetRoundsWonWithoutPurchaseTotal(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_iRoundsWonWithoutPurchaseTotal", true, value);
}
int32_t GCSAdditionalMatchStats_t::GetNumFirstKills() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numFirstKills");
}
void GCSAdditionalMatchStats_t::SetNumFirstKills(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numFirstKills", true, value);
}
int32_t GCSAdditionalMatchStats_t::GetNumClutchKills() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numClutchKills");
}
void GCSAdditionalMatchStats_t::SetNumClutchKills(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numClutchKills", true, value);
}
int32_t GCSAdditionalMatchStats_t::GetNumPistolKills() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numPistolKills");
}
void GCSAdditionalMatchStats_t::SetNumPistolKills(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numPistolKills", true, value);
}
int32_t GCSAdditionalMatchStats_t::GetNumSniperKills() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_numSniperKills");
}
void GCSAdditionalMatchStats_t::SetNumSniperKills(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_numSniperKills", true, value);
}
int32_t GCSAdditionalMatchStats_t::GetNumSuicides() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_iNumSuicides");
}
void GCSAdditionalMatchStats_t::SetNumSuicides(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_iNumSuicides", true, value);
}
int32_t GCSAdditionalMatchStats_t::GetNumTeamKills() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_iNumTeamKills");
}
void GCSAdditionalMatchStats_t::SetNumTeamKills(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_iNumTeamKills", true, value);
}
int32_t GCSAdditionalMatchStats_t::GetTeamDamage() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalMatchStats_t", "m_iTeamDamage");
}
void GCSAdditionalMatchStats_t::SetTeamDamage(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalMatchStats_t", "m_iTeamDamage", true, value);
}
std::string GCSAdditionalMatchStats_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSAdditionalMatchStats_t::IsValid() {
    return (m_ptr != nullptr);
}
GCSAdditionalPerRoundStats_t GCSAdditionalMatchStats_t::GetParent() const {
    GCSAdditionalPerRoundStats_t value(m_ptr);
    return value;
}
void GCSAdditionalMatchStats_t::SetParent(GCSAdditionalPerRoundStats_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSAdditionalMatchStats_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSAdditionalMatchStats_t>("CSAdditionalMatchStats_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NumRoundsSurvived", &GCSAdditionalMatchStats_t::GetNumRoundsSurvived, &GCSAdditionalMatchStats_t::SetNumRoundsSurvived)
        .addProperty("MaxNumRoundsSurvived", &GCSAdditionalMatchStats_t::GetMaxNumRoundsSurvived, &GCSAdditionalMatchStats_t::SetMaxNumRoundsSurvived)
        .addProperty("NumRoundsSurvivedTotal", &GCSAdditionalMatchStats_t::GetNumRoundsSurvivedTotal, &GCSAdditionalMatchStats_t::SetNumRoundsSurvivedTotal)
        .addProperty("RoundsWonWithoutPurchase", &GCSAdditionalMatchStats_t::GetRoundsWonWithoutPurchase, &GCSAdditionalMatchStats_t::SetRoundsWonWithoutPurchase)
        .addProperty("RoundsWonWithoutPurchaseTotal", &GCSAdditionalMatchStats_t::GetRoundsWonWithoutPurchaseTotal, &GCSAdditionalMatchStats_t::SetRoundsWonWithoutPurchaseTotal)
        .addProperty("NumFirstKills", &GCSAdditionalMatchStats_t::GetNumFirstKills, &GCSAdditionalMatchStats_t::SetNumFirstKills)
        .addProperty("NumClutchKills", &GCSAdditionalMatchStats_t::GetNumClutchKills, &GCSAdditionalMatchStats_t::SetNumClutchKills)
        .addProperty("NumPistolKills", &GCSAdditionalMatchStats_t::GetNumPistolKills, &GCSAdditionalMatchStats_t::SetNumPistolKills)
        .addProperty("NumSniperKills", &GCSAdditionalMatchStats_t::GetNumSniperKills, &GCSAdditionalMatchStats_t::SetNumSniperKills)
        .addProperty("NumSuicides", &GCSAdditionalMatchStats_t::GetNumSuicides, &GCSAdditionalMatchStats_t::SetNumSuicides)
        .addProperty("NumTeamKills", &GCSAdditionalMatchStats_t::GetNumTeamKills, &GCSAdditionalMatchStats_t::SetNumTeamKills)
        .addProperty("TeamDamage", &GCSAdditionalMatchStats_t::GetTeamDamage, &GCSAdditionalMatchStats_t::SetTeamDamage)
        .addProperty("Parent", &GCSAdditionalMatchStats_t::GetParent, &GCSAdditionalMatchStats_t::SetParent)
        .addFunction("ToPtr", &GCSAdditionalMatchStats_t::ToPtr)
        .addFunction("IsValid", &GCSAdditionalMatchStats_t::IsValid)
        .endClass();
}