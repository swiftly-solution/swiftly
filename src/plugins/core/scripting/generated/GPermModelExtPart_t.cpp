#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPermModelExtPart_t::GPermModelExtPart_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPermModelExtPart_t::GPermModelExtPart_t(void *ptr) {
    m_ptr = ptr;
}
std::string GPermModelExtPart_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "PermModelExtPart_t", "m_Name").Get();
}
void GPermModelExtPart_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "PermModelExtPart_t", "m_Name", true, CUtlString(value.c_str()));
}
int32_t GPermModelExtPart_t::GetParent() const {
    return GetSchemaValue<int32_t>(m_ptr, "PermModelExtPart_t", "m_nParent");
}
void GPermModelExtPart_t::SetParent(int32_t value) {
    SetSchemaValue(m_ptr, "PermModelExtPart_t", "m_nParent", true, value);
}
std::string GPermModelExtPart_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPermModelExtPart_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPermModelExtPart_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPermModelExtPart_t>("PermModelExtPart_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GPermModelExtPart_t::GetName, &GPermModelExtPart_t::SetName)
        .addProperty("Parent", &GPermModelExtPart_t::GetParent, &GPermModelExtPart_t::SetParent)
        .addFunction("ToPtr", &GPermModelExtPart_t::ToPtr)
        .addFunction("IsValid", &GPermModelExtPart_t::IsValid)
        .endClass();
}