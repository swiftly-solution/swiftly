#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFunctionInfo_t::GFunctionInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFunctionInfo_t::GFunctionInfo_t(void *ptr) {
    m_ptr = ptr;
}
std::string GFunctionInfo_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "FunctionInfo_t", "m_name").Get();
}
void GFunctionInfo_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "FunctionInfo_t", "m_name", true, CUtlString(value.c_str()));
}
CUtlStringToken GFunctionInfo_t::GetNameToken() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "FunctionInfo_t", "m_nameToken");
}
void GFunctionInfo_t::SetNameToken(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "FunctionInfo_t", "m_nameToken", true, value);
}
int32_t GFunctionInfo_t::GetParamCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "FunctionInfo_t", "m_nParamCount");
}
void GFunctionInfo_t::SetParamCount(int32_t value) {
    SetSchemaValue(m_ptr, "FunctionInfo_t", "m_nParamCount", true, value);
}
GFuseFunctionIndex_t GFunctionInfo_t::GetIndex() const {
    GFuseFunctionIndex_t value(GetSchemaPtr(m_ptr, "FunctionInfo_t", "m_nIndex"));
    return value;
}
void GFunctionInfo_t::SetIndex(GFuseFunctionIndex_t value) {
    SetSchemaValue(m_ptr, "FunctionInfo_t", "m_nIndex", true, value);
}
bool GFunctionInfo_t::GetIsPure() const {
    return GetSchemaValue<bool>(m_ptr, "FunctionInfo_t", "m_bIsPure");
}
void GFunctionInfo_t::SetIsPure(bool value) {
    SetSchemaValue(m_ptr, "FunctionInfo_t", "m_bIsPure", true, value);
}
std::string GFunctionInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFunctionInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFunctionInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFunctionInfo_t>("FunctionInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GFunctionInfo_t::GetName, &GFunctionInfo_t::SetName)
        .addProperty("NameToken", &GFunctionInfo_t::GetNameToken, &GFunctionInfo_t::SetNameToken)
        .addProperty("ParamCount", &GFunctionInfo_t::GetParamCount, &GFunctionInfo_t::SetParamCount)
        .addProperty("Index", &GFunctionInfo_t::GetIndex, &GFunctionInfo_t::SetIndex)
        .addProperty("IsPure", &GFunctionInfo_t::GetIsPure, &GFunctionInfo_t::SetIsPure)
        .addFunction("ToPtr", &GFunctionInfo_t::ToPtr)
        .addFunction("IsValid", &GFunctionInfo_t::IsValid)
        .endClass();
}