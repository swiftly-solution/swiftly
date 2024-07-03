#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCompMatMutatorCondition_t::GCompMatMutatorCondition_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCompMatMutatorCondition_t::GCompMatMutatorCondition_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCompMatMutatorCondition_t::GetMutatorCondition() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CompMatMutatorCondition_t", "m_nMutatorCondition");
}
void GCompMatMutatorCondition_t::SetMutatorCondition(uint64_t value) {
    SetSchemaValue(m_ptr, "CompMatMutatorCondition_t", "m_nMutatorCondition", true, value);
}
std::string GCompMatMutatorCondition_t::GetStrMutatorConditionContainerName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerName").Get();
}
void GCompMatMutatorCondition_t::SetStrMutatorConditionContainerName(std::string value) {
    SetSchemaValue(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerName", true, CUtlString(value.c_str()));
}
std::string GCompMatMutatorCondition_t::GetStrMutatorConditionContainerVarName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerVarName").Get();
}
void GCompMatMutatorCondition_t::SetStrMutatorConditionContainerVarName(std::string value) {
    SetSchemaValue(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerVarName", true, CUtlString(value.c_str()));
}
std::string GCompMatMutatorCondition_t::GetStrMutatorConditionContainerVarValue() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerVarValue").Get();
}
void GCompMatMutatorCondition_t::SetStrMutatorConditionContainerVarValue(std::string value) {
    SetSchemaValue(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerVarValue", true, CUtlString(value.c_str()));
}
bool GCompMatMutatorCondition_t::GetPassWhenTrue() const {
    return GetSchemaValue<bool>(m_ptr, "CompMatMutatorCondition_t", "m_bPassWhenTrue");
}
void GCompMatMutatorCondition_t::SetPassWhenTrue(bool value) {
    SetSchemaValue(m_ptr, "CompMatMutatorCondition_t", "m_bPassWhenTrue", true, value);
}
std::string GCompMatMutatorCondition_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCompMatMutatorCondition_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCompMatMutatorCondition_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompMatMutatorCondition_t>("CompMatMutatorCondition_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MutatorCondition", &GCompMatMutatorCondition_t::GetMutatorCondition, &GCompMatMutatorCondition_t::SetMutatorCondition)
        .addProperty("StrMutatorConditionContainerName", &GCompMatMutatorCondition_t::GetStrMutatorConditionContainerName, &GCompMatMutatorCondition_t::SetStrMutatorConditionContainerName)
        .addProperty("StrMutatorConditionContainerVarName", &GCompMatMutatorCondition_t::GetStrMutatorConditionContainerVarName, &GCompMatMutatorCondition_t::SetStrMutatorConditionContainerVarName)
        .addProperty("StrMutatorConditionContainerVarValue", &GCompMatMutatorCondition_t::GetStrMutatorConditionContainerVarValue, &GCompMatMutatorCondition_t::SetStrMutatorConditionContainerVarValue)
        .addProperty("PassWhenTrue", &GCompMatMutatorCondition_t::GetPassWhenTrue, &GCompMatMutatorCondition_t::SetPassWhenTrue)
        .addFunction("ToPtr", &GCompMatMutatorCondition_t::ToPtr)
        .addFunction("IsValid", &GCompMatMutatorCondition_t::IsValid)
        .endClass();
}