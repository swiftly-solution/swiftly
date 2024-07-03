#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEntityIOConnectionData_t::GEntityIOConnectionData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEntityIOConnectionData_t::GEntityIOConnectionData_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEntityIOConnectionData_t::GetOutputName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "EntityIOConnectionData_t", "m_outputName").Get();
}
void GEntityIOConnectionData_t::SetOutputName(std::string value) {
    SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_outputName", true, CUtlString(value.c_str()));
}
uint32_t GEntityIOConnectionData_t::GetTargetType() const {
    return GetSchemaValue<uint32_t>(m_ptr, "EntityIOConnectionData_t", "m_targetType");
}
void GEntityIOConnectionData_t::SetTargetType(uint32_t value) {
    SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_targetType", true, value);
}
std::string GEntityIOConnectionData_t::GetTargetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "EntityIOConnectionData_t", "m_targetName").Get();
}
void GEntityIOConnectionData_t::SetTargetName(std::string value) {
    SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_targetName", true, CUtlString(value.c_str()));
}
std::string GEntityIOConnectionData_t::GetInputName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "EntityIOConnectionData_t", "m_inputName").Get();
}
void GEntityIOConnectionData_t::SetInputName(std::string value) {
    SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_inputName", true, CUtlString(value.c_str()));
}
std::string GEntityIOConnectionData_t::GetOverrideParam() const {
    return GetSchemaValue<CUtlString>(m_ptr, "EntityIOConnectionData_t", "m_overrideParam").Get();
}
void GEntityIOConnectionData_t::SetOverrideParam(std::string value) {
    SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_overrideParam", true, CUtlString(value.c_str()));
}
float GEntityIOConnectionData_t::GetDelay() const {
    return GetSchemaValue<float>(m_ptr, "EntityIOConnectionData_t", "m_flDelay");
}
void GEntityIOConnectionData_t::SetDelay(float value) {
    SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_flDelay", true, value);
}
int32_t GEntityIOConnectionData_t::GetTimesToFire() const {
    return GetSchemaValue<int32_t>(m_ptr, "EntityIOConnectionData_t", "m_nTimesToFire");
}
void GEntityIOConnectionData_t::SetTimesToFire(int32_t value) {
    SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_nTimesToFire", true, value);
}
std::string GEntityIOConnectionData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEntityIOConnectionData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEntityIOConnectionData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntityIOConnectionData_t>("EntityIOConnectionData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OutputName", &GEntityIOConnectionData_t::GetOutputName, &GEntityIOConnectionData_t::SetOutputName)
        .addProperty("TargetType", &GEntityIOConnectionData_t::GetTargetType, &GEntityIOConnectionData_t::SetTargetType)
        .addProperty("TargetName", &GEntityIOConnectionData_t::GetTargetName, &GEntityIOConnectionData_t::SetTargetName)
        .addProperty("InputName", &GEntityIOConnectionData_t::GetInputName, &GEntityIOConnectionData_t::SetInputName)
        .addProperty("OverrideParam", &GEntityIOConnectionData_t::GetOverrideParam, &GEntityIOConnectionData_t::SetOverrideParam)
        .addProperty("Delay", &GEntityIOConnectionData_t::GetDelay, &GEntityIOConnectionData_t::SetDelay)
        .addProperty("TimesToFire", &GEntityIOConnectionData_t::GetTimesToFire, &GEntityIOConnectionData_t::SetTimesToFire)
        .addFunction("ToPtr", &GEntityIOConnectionData_t::ToPtr)
        .addFunction("IsValid", &GEntityIOConnectionData_t::IsValid)
        .endClass();
}