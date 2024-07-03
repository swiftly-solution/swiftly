#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSTeam::GCCSTeam(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSTeam::GCCSTeam(void *ptr) {
    m_ptr = ptr;
}
int32_t GCCSTeam::GetLastRecievedShorthandedRoundBonus() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_nLastRecievedShorthandedRoundBonus");
}
void GCCSTeam::SetLastRecievedShorthandedRoundBonus(int32_t value) {
    SetSchemaValue(m_ptr, "CCSTeam", "m_nLastRecievedShorthandedRoundBonus", false, value);
}
int32_t GCCSTeam::GetShorthandedRoundBonusStartRound() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_nShorthandedRoundBonusStartRound");
}
void GCCSTeam::SetShorthandedRoundBonusStartRound(int32_t value) {
    SetSchemaValue(m_ptr, "CCSTeam", "m_nShorthandedRoundBonusStartRound", false, value);
}
bool GCCSTeam::GetSurrendered() const {
    return GetSchemaValue<bool>(m_ptr, "CCSTeam", "m_bSurrendered");
}
void GCCSTeam::SetSurrendered(bool value) {
    SetSchemaValue(m_ptr, "CCSTeam", "m_bSurrendered", false, value);
}
std::string GCCSTeam::GetTeamMatchStat() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSTeam", "m_szTeamMatchStat");
}
void GCCSTeam::SetTeamMatchStat(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSTeam", "m_szTeamMatchStat", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 512);
}
int32_t GCCSTeam::GetNumMapVictories() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_numMapVictories");
}
void GCCSTeam::SetNumMapVictories(int32_t value) {
    SetSchemaValue(m_ptr, "CCSTeam", "m_numMapVictories", false, value);
}
int32_t GCCSTeam::GetScoreFirstHalf() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_scoreFirstHalf");
}
void GCCSTeam::SetScoreFirstHalf(int32_t value) {
    SetSchemaValue(m_ptr, "CCSTeam", "m_scoreFirstHalf", false, value);
}
int32_t GCCSTeam::GetScoreSecondHalf() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_scoreSecondHalf");
}
void GCCSTeam::SetScoreSecondHalf(int32_t value) {
    SetSchemaValue(m_ptr, "CCSTeam", "m_scoreSecondHalf", false, value);
}
int32_t GCCSTeam::GetScoreOvertime() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_scoreOvertime");
}
void GCCSTeam::SetScoreOvertime(int32_t value) {
    SetSchemaValue(m_ptr, "CCSTeam", "m_scoreOvertime", false, value);
}
std::string GCCSTeam::GetClanTeamname() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSTeam", "m_szClanTeamname");
}
void GCCSTeam::SetClanTeamname(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSTeam", "m_szClanTeamname", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 129);
}
uint32_t GCCSTeam::GetClanID() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSTeam", "m_iClanID");
}
void GCCSTeam::SetClanID(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSTeam", "m_iClanID", false, value);
}
std::string GCCSTeam::GetTeamFlagImage() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSTeam", "m_szTeamFlagImage");
}
void GCCSTeam::SetTeamFlagImage(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSTeam", "m_szTeamFlagImage", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 8);
}
std::string GCCSTeam::GetTeamLogoImage() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSTeam", "m_szTeamLogoImage");
}
void GCCSTeam::SetTeamLogoImage(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSTeam", "m_szTeamLogoImage", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 8);
}
float GCCSTeam::GetNextResourceTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSTeam", "m_flNextResourceTime");
}
void GCCSTeam::SetNextResourceTime(float value) {
    SetSchemaValue(m_ptr, "CCSTeam", "m_flNextResourceTime", false, value);
}
int32_t GCCSTeam::GetLastUpdateSentAt() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSTeam", "m_iLastUpdateSentAt");
}
void GCCSTeam::SetLastUpdateSentAt(int32_t value) {
    SetSchemaValue(m_ptr, "CCSTeam", "m_iLastUpdateSentAt", false, value);
}
std::string GCCSTeam::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSTeam::IsValid() {
    return (m_ptr != nullptr);
}
GCTeam GCCSTeam::GetParent() const {
    GCTeam value(m_ptr);
    return value;
}
void GCCSTeam::SetParent(GCTeam value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSTeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSTeam>("CCSTeam")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LastRecievedShorthandedRoundBonus", &GCCSTeam::GetLastRecievedShorthandedRoundBonus, &GCCSTeam::SetLastRecievedShorthandedRoundBonus)
        .addProperty("ShorthandedRoundBonusStartRound", &GCCSTeam::GetShorthandedRoundBonusStartRound, &GCCSTeam::SetShorthandedRoundBonusStartRound)
        .addProperty("Surrendered", &GCCSTeam::GetSurrendered, &GCCSTeam::SetSurrendered)
        .addProperty("TeamMatchStat", &GCCSTeam::GetTeamMatchStat, &GCCSTeam::SetTeamMatchStat)
        .addProperty("NumMapVictories", &GCCSTeam::GetNumMapVictories, &GCCSTeam::SetNumMapVictories)
        .addProperty("ScoreFirstHalf", &GCCSTeam::GetScoreFirstHalf, &GCCSTeam::SetScoreFirstHalf)
        .addProperty("ScoreSecondHalf", &GCCSTeam::GetScoreSecondHalf, &GCCSTeam::SetScoreSecondHalf)
        .addProperty("ScoreOvertime", &GCCSTeam::GetScoreOvertime, &GCCSTeam::SetScoreOvertime)
        .addProperty("ClanTeamname", &GCCSTeam::GetClanTeamname, &GCCSTeam::SetClanTeamname)
        .addProperty("ClanID", &GCCSTeam::GetClanID, &GCCSTeam::SetClanID)
        .addProperty("TeamFlagImage", &GCCSTeam::GetTeamFlagImage, &GCCSTeam::SetTeamFlagImage)
        .addProperty("TeamLogoImage", &GCCSTeam::GetTeamLogoImage, &GCCSTeam::SetTeamLogoImage)
        .addProperty("NextResourceTime", &GCCSTeam::GetNextResourceTime, &GCCSTeam::SetNextResourceTime)
        .addProperty("LastUpdateSentAt", &GCCSTeam::GetLastUpdateSentAt, &GCCSTeam::SetLastUpdateSentAt)
        .addProperty("Parent", &GCCSTeam::GetParent, &GCCSTeam::SetParent)
        .addFunction("ToPtr", &GCCSTeam::ToPtr)
        .addFunction("IsValid", &GCCSTeam::IsValid)
        .endClass();
}