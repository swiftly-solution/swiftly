#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMaterialParamString_t::GMaterialParamString_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMaterialParamString_t::GMaterialParamString_t(void *ptr) {
    m_ptr = ptr;
}
std::string GMaterialParamString_t::GetValue() const {
    return GetSchemaValue<CUtlString>(m_ptr, "MaterialParamString_t", "m_value").Get();
}
void GMaterialParamString_t::SetValue(std::string value) {
    SetSchemaValue(m_ptr, "MaterialParamString_t", "m_value", true, CUtlString(value.c_str()));
}
std::string GMaterialParamString_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMaterialParamString_t::IsValid() {
    return (m_ptr != nullptr);
}
GMaterialParam_t GMaterialParamString_t::GetParent() const {
    GMaterialParam_t value(m_ptr);
    return value;
}
void GMaterialParamString_t::SetParent(GMaterialParam_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassMaterialParamString_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamString_t>("MaterialParamString_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GMaterialParamString_t::GetValue, &GMaterialParamString_t::SetValue)
        .addProperty("Parent", &GMaterialParamString_t::GetParent, &GMaterialParamString_t::SetParent)
        .addFunction("ToPtr", &GMaterialParamString_t::ToPtr)
        .addFunction("IsValid", &GMaterialParamString_t::IsValid)
        .endClass();
}