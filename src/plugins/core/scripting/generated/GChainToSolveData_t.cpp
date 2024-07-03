#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GChainToSolveData_t::GChainToSolveData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GChainToSolveData_t::GChainToSolveData_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GChainToSolveData_t::GetChainIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "ChainToSolveData_t", "m_nChainIndex");
}
void GChainToSolveData_t::SetChainIndex(int32_t value) {
    SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_nChainIndex", true, value);
}
GIKSolverSettings_t GChainToSolveData_t::GetSolverSettings() const {
    GIKSolverSettings_t value(GetSchemaPtr(m_ptr, "ChainToSolveData_t", "m_SolverSettings"));
    return value;
}
void GChainToSolveData_t::SetSolverSettings(GIKSolverSettings_t value) {
    SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_SolverSettings", true, value);
}
GIKTargetSettings_t GChainToSolveData_t::GetTargetSettings() const {
    GIKTargetSettings_t value(GetSchemaPtr(m_ptr, "ChainToSolveData_t", "m_TargetSettings"));
    return value;
}
void GChainToSolveData_t::SetTargetSettings(GIKTargetSettings_t value) {
    SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_TargetSettings", true, value);
}
uint64_t GChainToSolveData_t::GetDebugSetting() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ChainToSolveData_t", "m_DebugSetting");
}
void GChainToSolveData_t::SetDebugSetting(uint64_t value) {
    SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_DebugSetting", true, value);
}
float GChainToSolveData_t::GetDebugNormalizedValue() const {
    return GetSchemaValue<float>(m_ptr, "ChainToSolveData_t", "m_flDebugNormalizedValue");
}
void GChainToSolveData_t::SetDebugNormalizedValue(float value) {
    SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_flDebugNormalizedValue", true, value);
}
Vector GChainToSolveData_t::GetDebugOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "ChainToSolveData_t", "m_vDebugOffset");
}
void GChainToSolveData_t::SetDebugOffset(Vector value) {
    SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_vDebugOffset", true, value);
}
std::string GChainToSolveData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GChainToSolveData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassChainToSolveData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GChainToSolveData_t>("ChainToSolveData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChainIndex", &GChainToSolveData_t::GetChainIndex, &GChainToSolveData_t::SetChainIndex)
        .addProperty("SolverSettings", &GChainToSolveData_t::GetSolverSettings, &GChainToSolveData_t::SetSolverSettings)
        .addProperty("TargetSettings", &GChainToSolveData_t::GetTargetSettings, &GChainToSolveData_t::SetTargetSettings)
        .addProperty("DebugSetting", &GChainToSolveData_t::GetDebugSetting, &GChainToSolveData_t::SetDebugSetting)
        .addProperty("DebugNormalizedValue", &GChainToSolveData_t::GetDebugNormalizedValue, &GChainToSolveData_t::SetDebugNormalizedValue)
        .addProperty("DebugOffset", &GChainToSolveData_t::GetDebugOffset, &GChainToSolveData_t::SetDebugOffset)
        .addFunction("ToPtr", &GChainToSolveData_t::ToPtr)
        .addFunction("IsValid", &GChainToSolveData_t::IsValid)
        .endClass();
}