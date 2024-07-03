#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMaterialParamVector_t::GMaterialParamVector_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMaterialParamVector_t::GMaterialParamVector_t(void *ptr) {
    m_ptr = ptr;
}
Vector4D GMaterialParamVector_t::GetValue() const {
    return GetSchemaValue<Vector4D>(m_ptr, "MaterialParamVector_t", "m_value");
}
void GMaterialParamVector_t::SetValue(Vector4D value) {
    SetSchemaValue(m_ptr, "MaterialParamVector_t", "m_value", true, value);
}
std::string GMaterialParamVector_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMaterialParamVector_t::IsValid() {
    return (m_ptr != nullptr);
}
GMaterialParam_t GMaterialParamVector_t::GetParent() const {
    GMaterialParam_t value(m_ptr);
    return value;
}
void GMaterialParamVector_t::SetParent(GMaterialParam_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassMaterialParamVector_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamVector_t>("MaterialParamVector_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GMaterialParamVector_t::GetValue, &GMaterialParamVector_t::SetValue)
        .addProperty("Parent", &GMaterialParamVector_t::GetParent, &GMaterialParamVector_t::SetParent)
        .addFunction("ToPtr", &GMaterialParamVector_t::ToPtr)
        .addFunction("IsValid", &GMaterialParamVector_t::IsValid)
        .endClass();
}