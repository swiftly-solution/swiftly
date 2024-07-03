#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMaterialVariable_t::GMaterialVariable_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMaterialVariable_t::GMaterialVariable_t(void *ptr) {
    m_ptr = ptr;
}
std::string GMaterialVariable_t::GetStrVariable() const {
    return GetSchemaValue<CUtlString>(m_ptr, "MaterialVariable_t", "m_strVariable").Get();
}
void GMaterialVariable_t::SetStrVariable(std::string value) {
    SetSchemaValue(m_ptr, "MaterialVariable_t", "m_strVariable", true, CUtlString(value.c_str()));
}
GParticleAttributeIndex_t GMaterialVariable_t::GetVariableField() const {
    GParticleAttributeIndex_t value(GetSchemaPtr(m_ptr, "MaterialVariable_t", "m_nVariableField"));
    return value;
}
void GMaterialVariable_t::SetVariableField(GParticleAttributeIndex_t value) {
    SetSchemaValue(m_ptr, "MaterialVariable_t", "m_nVariableField", true, value);
}
float GMaterialVariable_t::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "MaterialVariable_t", "m_flScale");
}
void GMaterialVariable_t::SetScale(float value) {
    SetSchemaValue(m_ptr, "MaterialVariable_t", "m_flScale", true, value);
}
std::string GMaterialVariable_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMaterialVariable_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassMaterialVariable_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialVariable_t>("MaterialVariable_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StrVariable", &GMaterialVariable_t::GetStrVariable, &GMaterialVariable_t::SetStrVariable)
        .addProperty("VariableField", &GMaterialVariable_t::GetVariableField, &GMaterialVariable_t::SetVariableField)
        .addProperty("Scale", &GMaterialVariable_t::GetScale, &GMaterialVariable_t::SetScale)
        .addFunction("ToPtr", &GMaterialVariable_t::ToPtr)
        .addFunction("IsValid", &GMaterialVariable_t::IsValid)
        .endClass();
}