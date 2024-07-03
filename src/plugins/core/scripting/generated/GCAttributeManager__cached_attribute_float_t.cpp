#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAttributeManager__cached_attribute_float_t::GCAttributeManager__cached_attribute_float_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAttributeManager__cached_attribute_float_t::GCAttributeManager__cached_attribute_float_t(void *ptr) {
    m_ptr = ptr;
}
float GCAttributeManager__cached_attribute_float_t::GetIn() const {
    return GetSchemaValue<float>(m_ptr, "CAttributeManager__cached_attribute_float_t", "flIn");
}
void GCAttributeManager__cached_attribute_float_t::SetIn(float value) {
    SetSchemaValue(m_ptr, "CAttributeManager__cached_attribute_float_t", "flIn", true, value);
}
std::string GCAttributeManager__cached_attribute_float_t::GetAttribHook() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAttributeManager__cached_attribute_float_t", "iAttribHook").String();
}
void GCAttributeManager__cached_attribute_float_t::SetAttribHook(std::string value) {
    SetSchemaValue(m_ptr, "CAttributeManager__cached_attribute_float_t", "iAttribHook", true, CUtlSymbolLarge(value.c_str()));
}
float GCAttributeManager__cached_attribute_float_t::GetOut() const {
    return GetSchemaValue<float>(m_ptr, "CAttributeManager__cached_attribute_float_t", "flOut");
}
void GCAttributeManager__cached_attribute_float_t::SetOut(float value) {
    SetSchemaValue(m_ptr, "CAttributeManager__cached_attribute_float_t", "flOut", true, value);
}
std::string GCAttributeManager__cached_attribute_float_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAttributeManager__cached_attribute_float_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAttributeManager__cached_attribute_float_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAttributeManager__cached_attribute_float_t>("CAttributeManager__cached_attribute_float_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("In", &GCAttributeManager__cached_attribute_float_t::GetIn, &GCAttributeManager__cached_attribute_float_t::SetIn)
        .addProperty("AttribHook", &GCAttributeManager__cached_attribute_float_t::GetAttribHook, &GCAttributeManager__cached_attribute_float_t::SetAttribHook)
        .addProperty("Out", &GCAttributeManager__cached_attribute_float_t::GetOut, &GCAttributeManager__cached_attribute_float_t::SetOut)
        .addFunction("ToPtr", &GCAttributeManager__cached_attribute_float_t::ToPtr)
        .addFunction("IsValid", &GCAttributeManager__cached_attribute_float_t::IsValid)
        .endClass();
}