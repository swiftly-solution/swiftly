#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVariableInfo_t::GVariableInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVariableInfo_t::GVariableInfo_t(void *ptr) {
    m_ptr = ptr;
}
std::string GVariableInfo_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "VariableInfo_t", "m_name").Get();
}
void GVariableInfo_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "VariableInfo_t", "m_name", true, CUtlString(value.c_str()));
}
CUtlStringToken GVariableInfo_t::GetNameToken() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "VariableInfo_t", "m_nameToken");
}
void GVariableInfo_t::SetNameToken(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "VariableInfo_t", "m_nameToken", true, value);
}
GFuseVariableIndex_t GVariableInfo_t::GetIndex() const {
    GFuseVariableIndex_t value(GetSchemaPtr(m_ptr, "VariableInfo_t", "m_nIndex"));
    return value;
}
void GVariableInfo_t::SetIndex(GFuseVariableIndex_t value) {
    SetSchemaValue(m_ptr, "VariableInfo_t", "m_nIndex", true, value);
}
uint8_t GVariableInfo_t::GetNumComponents() const {
    return GetSchemaValue<uint8_t>(m_ptr, "VariableInfo_t", "m_nNumComponents");
}
void GVariableInfo_t::SetNumComponents(uint8_t value) {
    SetSchemaValue(m_ptr, "VariableInfo_t", "m_nNumComponents", true, value);
}
uint64_t GVariableInfo_t::GetVarType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VariableInfo_t", "m_eVarType");
}
void GVariableInfo_t::SetVarType(uint64_t value) {
    SetSchemaValue(m_ptr, "VariableInfo_t", "m_eVarType", true, value);
}
uint64_t GVariableInfo_t::GetAccess() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VariableInfo_t", "m_eAccess");
}
void GVariableInfo_t::SetAccess(uint64_t value) {
    SetSchemaValue(m_ptr, "VariableInfo_t", "m_eAccess", true, value);
}
std::string GVariableInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVariableInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVariableInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVariableInfo_t>("VariableInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GVariableInfo_t::GetName, &GVariableInfo_t::SetName)
        .addProperty("NameToken", &GVariableInfo_t::GetNameToken, &GVariableInfo_t::SetNameToken)
        .addProperty("Index", &GVariableInfo_t::GetIndex, &GVariableInfo_t::SetIndex)
        .addProperty("NumComponents", &GVariableInfo_t::GetNumComponents, &GVariableInfo_t::SetNumComponents)
        .addProperty("VarType", &GVariableInfo_t::GetVarType, &GVariableInfo_t::SetVarType)
        .addProperty("Access", &GVariableInfo_t::GetAccess, &GVariableInfo_t::SetAccess)
        .addFunction("ToPtr", &GVariableInfo_t::ToPtr)
        .addFunction("IsValid", &GVariableInfo_t::IsValid)
        .endClass();
}