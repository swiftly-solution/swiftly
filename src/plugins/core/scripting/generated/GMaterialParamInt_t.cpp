#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMaterialParamInt_t::GMaterialParamInt_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMaterialParamInt_t::GMaterialParamInt_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GMaterialParamInt_t::GetValue() const {
    return GetSchemaValue<int32_t>(m_ptr, "MaterialParamInt_t", "m_nValue");
}
void GMaterialParamInt_t::SetValue(int32_t value) {
    SetSchemaValue(m_ptr, "MaterialParamInt_t", "m_nValue", true, value);
}
std::string GMaterialParamInt_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMaterialParamInt_t::IsValid() {
    return (m_ptr != nullptr);
}
GMaterialParam_t GMaterialParamInt_t::GetParent() const {
    GMaterialParam_t value(m_ptr);
    return value;
}
void GMaterialParamInt_t::SetParent(GMaterialParam_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassMaterialParamInt_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamInt_t>("MaterialParamInt_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GMaterialParamInt_t::GetValue, &GMaterialParamInt_t::SetValue)
        .addProperty("Parent", &GMaterialParamInt_t::GetParent, &GMaterialParamInt_t::SetParent)
        .addFunction("ToPtr", &GMaterialParamInt_t::ToPtr)
        .addFunction("IsValid", &GMaterialParamInt_t::IsValid)
        .endClass();
}