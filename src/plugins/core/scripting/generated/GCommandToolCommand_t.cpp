#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCommandToolCommand_t::GCommandToolCommand_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCommandToolCommand_t::GCommandToolCommand_t(void *ptr) {
    m_ptr = ptr;
}
bool GCommandToolCommand_t::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CommandToolCommand_t", "m_bEnabled");
}
void GCommandToolCommand_t::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_bEnabled", true, value);
}
bool GCommandToolCommand_t::GetOpened() const {
    return GetSchemaValue<bool>(m_ptr, "CommandToolCommand_t", "m_bOpened");
}
void GCommandToolCommand_t::SetOpened(bool value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_bOpened", true, value);
}
uint32_t GCommandToolCommand_t::GetInternalId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CommandToolCommand_t", "m_InternalId");
}
void GCommandToolCommand_t::SetInternalId(uint32_t value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_InternalId", true, value);
}
std::string GCommandToolCommand_t::GetShortName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CommandToolCommand_t", "m_ShortName").Get();
}
void GCommandToolCommand_t::SetShortName(std::string value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_ShortName", true, CUtlString(value.c_str()));
}
uint64_t GCommandToolCommand_t::GetExecMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CommandToolCommand_t", "m_ExecMode");
}
void GCommandToolCommand_t::SetExecMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_ExecMode", true, value);
}
std::string GCommandToolCommand_t::GetSpawnGroup() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CommandToolCommand_t", "m_SpawnGroup").Get();
}
void GCommandToolCommand_t::SetSpawnGroup(std::string value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_SpawnGroup", true, CUtlString(value.c_str()));
}
float GCommandToolCommand_t::GetPeriodicExecDelay() const {
    return GetSchemaValue<float>(m_ptr, "CommandToolCommand_t", "m_PeriodicExecDelay");
}
void GCommandToolCommand_t::SetPeriodicExecDelay(float value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_PeriodicExecDelay", true, value);
}
uint64_t GCommandToolCommand_t::GetSpecType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CommandToolCommand_t", "m_SpecType");
}
void GCommandToolCommand_t::SetSpecType(uint64_t value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_SpecType", true, value);
}
std::string GCommandToolCommand_t::GetEntitySpec() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CommandToolCommand_t", "m_EntitySpec").Get();
}
void GCommandToolCommand_t::SetEntitySpec(std::string value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_EntitySpec", true, CUtlString(value.c_str()));
}
std::string GCommandToolCommand_t::GetCommands() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CommandToolCommand_t", "m_Commands").Get();
}
void GCommandToolCommand_t::SetCommands(std::string value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_Commands", true, CUtlString(value.c_str()));
}
uint64_t GCommandToolCommand_t::GetSetDebugBits() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CommandToolCommand_t", "m_SetDebugBits");
}
void GCommandToolCommand_t::SetSetDebugBits(uint64_t value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_SetDebugBits", true, value);
}
uint64_t GCommandToolCommand_t::GetClearDebugBits() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CommandToolCommand_t", "m_ClearDebugBits");
}
void GCommandToolCommand_t::SetClearDebugBits(uint64_t value) {
    SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_ClearDebugBits", true, value);
}
std::string GCommandToolCommand_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCommandToolCommand_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCommandToolCommand_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCommandToolCommand_t>("CommandToolCommand_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Enabled", &GCommandToolCommand_t::GetEnabled, &GCommandToolCommand_t::SetEnabled)
        .addProperty("Opened", &GCommandToolCommand_t::GetOpened, &GCommandToolCommand_t::SetOpened)
        .addProperty("InternalId", &GCommandToolCommand_t::GetInternalId, &GCommandToolCommand_t::SetInternalId)
        .addProperty("ShortName", &GCommandToolCommand_t::GetShortName, &GCommandToolCommand_t::SetShortName)
        .addProperty("ExecMode", &GCommandToolCommand_t::GetExecMode, &GCommandToolCommand_t::SetExecMode)
        .addProperty("SpawnGroup", &GCommandToolCommand_t::GetSpawnGroup, &GCommandToolCommand_t::SetSpawnGroup)
        .addProperty("PeriodicExecDelay", &GCommandToolCommand_t::GetPeriodicExecDelay, &GCommandToolCommand_t::SetPeriodicExecDelay)
        .addProperty("SpecType", &GCommandToolCommand_t::GetSpecType, &GCommandToolCommand_t::SetSpecType)
        .addProperty("EntitySpec", &GCommandToolCommand_t::GetEntitySpec, &GCommandToolCommand_t::SetEntitySpec)
        .addProperty("Commands", &GCommandToolCommand_t::GetCommands, &GCommandToolCommand_t::SetCommands)
        .addProperty("SetDebugBits", &GCommandToolCommand_t::GetSetDebugBits, &GCommandToolCommand_t::SetSetDebugBits)
        .addProperty("ClearDebugBits", &GCommandToolCommand_t::GetClearDebugBits, &GCommandToolCommand_t::SetClearDebugBits)
        .addFunction("ToPtr", &GCommandToolCommand_t::ToPtr)
        .addFunction("IsValid", &GCommandToolCommand_t::IsValid)
        .endClass();
}