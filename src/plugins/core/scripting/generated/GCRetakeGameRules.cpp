#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRetakeGameRules::GCRetakeGameRules(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRetakeGameRules::GCRetakeGameRules(void *ptr) {
    m_ptr = ptr;
}
int32_t GCRetakeGameRules::GetMatchSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRetakeGameRules", "m_nMatchSeed");
}
void GCRetakeGameRules::SetMatchSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CRetakeGameRules", "m_nMatchSeed", false, value);
}
bool GCRetakeGameRules::GetBlockersPresent() const {
    return GetSchemaValue<bool>(m_ptr, "CRetakeGameRules", "m_bBlockersPresent");
}
void GCRetakeGameRules::SetBlockersPresent(bool value) {
    SetSchemaValue(m_ptr, "CRetakeGameRules", "m_bBlockersPresent", false, value);
}
bool GCRetakeGameRules::GetRoundInProgress() const {
    return GetSchemaValue<bool>(m_ptr, "CRetakeGameRules", "m_bRoundInProgress");
}
void GCRetakeGameRules::SetRoundInProgress(bool value) {
    SetSchemaValue(m_ptr, "CRetakeGameRules", "m_bRoundInProgress", false, value);
}
int32_t GCRetakeGameRules::GetFirstSecondHalfRound() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRetakeGameRules", "m_iFirstSecondHalfRound");
}
void GCRetakeGameRules::SetFirstSecondHalfRound(int32_t value) {
    SetSchemaValue(m_ptr, "CRetakeGameRules", "m_iFirstSecondHalfRound", false, value);
}
int32_t GCRetakeGameRules::GetBombSite() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRetakeGameRules", "m_iBombSite");
}
void GCRetakeGameRules::SetBombSite(int32_t value) {
    SetSchemaValue(m_ptr, "CRetakeGameRules", "m_iBombSite", false, value);
}
std::string GCRetakeGameRules::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRetakeGameRules::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCRetakeGameRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRetakeGameRules>("CRetakeGameRules")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MatchSeed", &GCRetakeGameRules::GetMatchSeed, &GCRetakeGameRules::SetMatchSeed)
        .addProperty("BlockersPresent", &GCRetakeGameRules::GetBlockersPresent, &GCRetakeGameRules::SetBlockersPresent)
        .addProperty("RoundInProgress", &GCRetakeGameRules::GetRoundInProgress, &GCRetakeGameRules::SetRoundInProgress)
        .addProperty("FirstSecondHalfRound", &GCRetakeGameRules::GetFirstSecondHalfRound, &GCRetakeGameRules::SetFirstSecondHalfRound)
        .addProperty("BombSite", &GCRetakeGameRules::GetBombSite, &GCRetakeGameRules::SetBombSite)
        .addFunction("ToPtr", &GCRetakeGameRules::ToPtr)
        .addFunction("IsValid", &GCRetakeGameRules::IsValid)
        .endClass();
}