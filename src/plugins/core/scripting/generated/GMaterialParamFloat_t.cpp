#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMaterialParamFloat_t::GMaterialParamFloat_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMaterialParamFloat_t::GMaterialParamFloat_t(void *ptr) {
    m_ptr = ptr;
}
float GMaterialParamFloat_t::GetValue() const {
    return GetSchemaValue<float>(m_ptr, "MaterialParamFloat_t", "m_flValue");
}
void GMaterialParamFloat_t::SetValue(float value) {
    SetSchemaValue(m_ptr, "MaterialParamFloat_t", "m_flValue", true, value);
}
std::string GMaterialParamFloat_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMaterialParamFloat_t::IsValid() {
    return (m_ptr != nullptr);
}
GMaterialParam_t GMaterialParamFloat_t::GetParent() const {
    GMaterialParam_t value(m_ptr);
    return value;
}
void GMaterialParamFloat_t::SetParent(GMaterialParam_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassMaterialParamFloat_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamFloat_t>("MaterialParamFloat_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GMaterialParamFloat_t::GetValue, &GMaterialParamFloat_t::SetValue)
        .addProperty("Parent", &GMaterialParamFloat_t::GetParent, &GMaterialParamFloat_t::SetParent)
        .addFunction("ToPtr", &GMaterialParamFloat_t::ToPtr)
        .addFunction("IsValid", &GMaterialParamFloat_t::IsValid)
        .endClass();
}