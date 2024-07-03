#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGameRules::GCGameRules(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGameRules::GCGameRules(void *ptr) {
    m_ptr = ptr;
}
GCNetworkVarChainer GCGameRules::Get__pChainEntity() const {
    GCNetworkVarChainer value(GetSchemaPtr(m_ptr, "CGameRules", "__m_pChainEntity"));
    return value;
}
void GCGameRules::Set__pChainEntity(GCNetworkVarChainer value) {
    SetSchemaValue(m_ptr, "CGameRules", "__m_pChainEntity", false, value);
}
std::string GCGameRules::GetQuestName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CGameRules", "m_szQuestName");
}
void GCGameRules::SetQuestName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CGameRules", "m_szQuestName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 128);
}
int32_t GCGameRules::GetQuestPhase() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGameRules", "m_nQuestPhase");
}
void GCGameRules::SetQuestPhase(int32_t value) {
    SetSchemaValue(m_ptr, "CGameRules", "m_nQuestPhase", false, value);
}
int32_t GCGameRules::GetTotalPausedTicks() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGameRules", "m_nTotalPausedTicks");
}
void GCGameRules::SetTotalPausedTicks(int32_t value) {
    SetSchemaValue(m_ptr, "CGameRules", "m_nTotalPausedTicks", false, value);
}
int32_t GCGameRules::GetPauseStartTick() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGameRules", "m_nPauseStartTick");
}
void GCGameRules::SetPauseStartTick(int32_t value) {
    SetSchemaValue(m_ptr, "CGameRules", "m_nPauseStartTick", false, value);
}
bool GCGameRules::GetGamePaused() const {
    return GetSchemaValue<bool>(m_ptr, "CGameRules", "m_bGamePaused");
}
void GCGameRules::SetGamePaused(bool value) {
    SetSchemaValue(m_ptr, "CGameRules", "m_bGamePaused", false, value);
}
std::string GCGameRules::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGameRules::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCGameRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameRules>("CGameRules")
        .addConstructor<void (*)(std::string)>()
        .addProperty("__pChainEntity", &GCGameRules::Get__pChainEntity, &GCGameRules::Set__pChainEntity)
        .addProperty("QuestName", &GCGameRules::GetQuestName, &GCGameRules::SetQuestName)
        .addProperty("QuestPhase", &GCGameRules::GetQuestPhase, &GCGameRules::SetQuestPhase)
        .addProperty("TotalPausedTicks", &GCGameRules::GetTotalPausedTicks, &GCGameRules::SetTotalPausedTicks)
        .addProperty("PauseStartTick", &GCGameRules::GetPauseStartTick, &GCGameRules::SetPauseStartTick)
        .addProperty("GamePaused", &GCGameRules::GetGamePaused, &GCGameRules::SetGamePaused)
        .addFunction("ToPtr", &GCGameRules::ToPtr)
        .addFunction("IsValid", &GCGameRules::IsValid)
        .endClass();
}