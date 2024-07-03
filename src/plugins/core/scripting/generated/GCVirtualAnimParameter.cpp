#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVirtualAnimParameter::GCVirtualAnimParameter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVirtualAnimParameter::GCVirtualAnimParameter(void *ptr) {
    m_ptr = ptr;
}
std::string GCVirtualAnimParameter::GetExpressionString() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CVirtualAnimParameter", "m_expressionString").Get();
}
void GCVirtualAnimParameter::SetExpressionString(std::string value) {
    SetSchemaValue(m_ptr, "CVirtualAnimParameter", "m_expressionString", false, CUtlString(value.c_str()));
}
uint64_t GCVirtualAnimParameter::GetParamType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CVirtualAnimParameter", "m_eParamType");
}
void GCVirtualAnimParameter::SetParamType(uint64_t value) {
    SetSchemaValue(m_ptr, "CVirtualAnimParameter", "m_eParamType", false, value);
}
std::string GCVirtualAnimParameter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVirtualAnimParameter::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimParameterBase GCVirtualAnimParameter::GetParent() const {
    GCAnimParameterBase value(m_ptr);
    return value;
}
void GCVirtualAnimParameter::SetParent(GCAnimParameterBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVirtualAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVirtualAnimParameter>("CVirtualAnimParameter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ExpressionString", &GCVirtualAnimParameter::GetExpressionString, &GCVirtualAnimParameter::SetExpressionString)
        .addProperty("ParamType", &GCVirtualAnimParameter::GetParamType, &GCVirtualAnimParameter::SetParamType)
        .addProperty("Parent", &GCVirtualAnimParameter::GetParent, &GCVirtualAnimParameter::SetParent)
        .addFunction("ToPtr", &GCVirtualAnimParameter::ToPtr)
        .addFunction("IsValid", &GCVirtualAnimParameter::IsValid)
        .endClass();
}