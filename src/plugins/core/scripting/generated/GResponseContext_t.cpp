#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GResponseContext_t::GResponseContext_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GResponseContext_t::GResponseContext_t(void *ptr) {
    m_ptr = ptr;
}
std::string GResponseContext_t::GetName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "ResponseContext_t", "m_iszName").String();
}
void GResponseContext_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "ResponseContext_t", "m_iszName", true, CUtlSymbolLarge(value.c_str()));
}
std::string GResponseContext_t::GetValue() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "ResponseContext_t", "m_iszValue").String();
}
void GResponseContext_t::SetValue(std::string value) {
    SetSchemaValue(m_ptr, "ResponseContext_t", "m_iszValue", true, CUtlSymbolLarge(value.c_str()));
}
float GResponseContext_t::GetExpirationTime() const {
    return GetSchemaValue<float>(m_ptr, "ResponseContext_t", "m_fExpirationTime");
}
void GResponseContext_t::SetExpirationTime(float value) {
    SetSchemaValue(m_ptr, "ResponseContext_t", "m_fExpirationTime", true, value);
}
std::string GResponseContext_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GResponseContext_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassResponseContext_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GResponseContext_t>("ResponseContext_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GResponseContext_t::GetName, &GResponseContext_t::SetName)
        .addProperty("Value", &GResponseContext_t::GetValue, &GResponseContext_t::SetValue)
        .addProperty("ExpirationTime", &GResponseContext_t::GetExpirationTime, &GResponseContext_t::SetExpirationTime)
        .addFunction("ToPtr", &GResponseContext_t::ToPtr)
        .addFunction("IsValid", &GResponseContext_t::IsValid)
        .endClass();
}