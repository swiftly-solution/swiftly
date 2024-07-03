#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCommentarySystem::GCCommentarySystem(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCommentarySystem::GCCommentarySystem(void *ptr) {
    m_ptr = ptr;
}
bool GCCommentarySystem::GetCommentaryConvarsChanging() const {
    return GetSchemaValue<bool>(m_ptr, "CCommentarySystem", "m_bCommentaryConvarsChanging");
}
void GCCommentarySystem::SetCommentaryConvarsChanging(bool value) {
    SetSchemaValue(m_ptr, "CCommentarySystem", "m_bCommentaryConvarsChanging", false, value);
}
bool GCCommentarySystem::GetCommentaryEnabledMidGame() const {
    return GetSchemaValue<bool>(m_ptr, "CCommentarySystem", "m_bCommentaryEnabledMidGame");
}
void GCCommentarySystem::SetCommentaryEnabledMidGame(bool value) {
    SetSchemaValue(m_ptr, "CCommentarySystem", "m_bCommentaryEnabledMidGame", false, value);
}
float GCCommentarySystem::GetNextTeleportTime() const {
    return GetSchemaValue<float>(m_ptr, "CCommentarySystem", "m_flNextTeleportTime");
}
void GCCommentarySystem::SetNextTeleportTime(float value) {
    SetSchemaValue(m_ptr, "CCommentarySystem", "m_flNextTeleportTime", false, value);
}
int32_t GCCommentarySystem::GetTeleportStage() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCommentarySystem", "m_iTeleportStage");
}
void GCCommentarySystem::SetTeleportStage(int32_t value) {
    SetSchemaValue(m_ptr, "CCommentarySystem", "m_iTeleportStage", false, value);
}
bool GCCommentarySystem::GetCheatState() const {
    return GetSchemaValue<bool>(m_ptr, "CCommentarySystem", "m_bCheatState");
}
void GCCommentarySystem::SetCheatState(bool value) {
    SetSchemaValue(m_ptr, "CCommentarySystem", "m_bCheatState", false, value);
}
bool GCCommentarySystem::GetIsFirstSpawnGroupToLoad() const {
    return GetSchemaValue<bool>(m_ptr, "CCommentarySystem", "m_bIsFirstSpawnGroupToLoad");
}
void GCCommentarySystem::SetIsFirstSpawnGroupToLoad(bool value) {
    SetSchemaValue(m_ptr, "CCommentarySystem", "m_bIsFirstSpawnGroupToLoad", false, value);
}
std::string GCCommentarySystem::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCommentarySystem::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCommentarySystem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCommentarySystem>("CCommentarySystem")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CommentaryConvarsChanging", &GCCommentarySystem::GetCommentaryConvarsChanging, &GCCommentarySystem::SetCommentaryConvarsChanging)
        .addProperty("CommentaryEnabledMidGame", &GCCommentarySystem::GetCommentaryEnabledMidGame, &GCCommentarySystem::SetCommentaryEnabledMidGame)
        .addProperty("NextTeleportTime", &GCCommentarySystem::GetNextTeleportTime, &GCCommentarySystem::SetNextTeleportTime)
        .addProperty("TeleportStage", &GCCommentarySystem::GetTeleportStage, &GCCommentarySystem::SetTeleportStage)
        .addProperty("CheatState", &GCCommentarySystem::GetCheatState, &GCCommentarySystem::SetCheatState)
        .addProperty("IsFirstSpawnGroupToLoad", &GCCommentarySystem::GetIsFirstSpawnGroupToLoad, &GCCommentarySystem::SetIsFirstSpawnGroupToLoad)
        .addFunction("ToPtr", &GCCommentarySystem::ToPtr)
        .addFunction("IsValid", &GCCommentarySystem::IsValid)
        .endClass();
}