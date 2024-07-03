#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPermModelDataAnimatedMaterialAttribute_t::GPermModelDataAnimatedMaterialAttribute_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPermModelDataAnimatedMaterialAttribute_t::GPermModelDataAnimatedMaterialAttribute_t(void *ptr) {
    m_ptr = ptr;
}
std::string GPermModelDataAnimatedMaterialAttribute_t::GetAttributeName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "PermModelDataAnimatedMaterialAttribute_t", "m_AttributeName").Get();
}
void GPermModelDataAnimatedMaterialAttribute_t::SetAttributeName(std::string value) {
    SetSchemaValue(m_ptr, "PermModelDataAnimatedMaterialAttribute_t", "m_AttributeName", true, CUtlString(value.c_str()));
}
int32_t GPermModelDataAnimatedMaterialAttribute_t::GetNumChannels() const {
    return GetSchemaValue<int32_t>(m_ptr, "PermModelDataAnimatedMaterialAttribute_t", "m_nNumChannels");
}
void GPermModelDataAnimatedMaterialAttribute_t::SetNumChannels(int32_t value) {
    SetSchemaValue(m_ptr, "PermModelDataAnimatedMaterialAttribute_t", "m_nNumChannels", true, value);
}
std::string GPermModelDataAnimatedMaterialAttribute_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPermModelDataAnimatedMaterialAttribute_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPermModelDataAnimatedMaterialAttribute_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPermModelDataAnimatedMaterialAttribute_t>("PermModelDataAnimatedMaterialAttribute_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AttributeName", &GPermModelDataAnimatedMaterialAttribute_t::GetAttributeName, &GPermModelDataAnimatedMaterialAttribute_t::SetAttributeName)
        .addProperty("NumChannels", &GPermModelDataAnimatedMaterialAttribute_t::GetNumChannels, &GPermModelDataAnimatedMaterialAttribute_t::SetNumChannels)
        .addFunction("ToPtr", &GPermModelDataAnimatedMaterialAttribute_t::ToPtr)
        .addFunction("IsValid", &GPermModelDataAnimatedMaterialAttribute_t::IsValid)
        .endClass();
}