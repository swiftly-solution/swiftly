#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GConstantInfo_t::GConstantInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GConstantInfo_t::GConstantInfo_t(void *ptr) {
    m_ptr = ptr;
}
std::string GConstantInfo_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ConstantInfo_t", "m_name").Get();
}
void GConstantInfo_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "ConstantInfo_t", "m_name", true, CUtlString(value.c_str()));
}
CUtlStringToken GConstantInfo_t::GetNameToken() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "ConstantInfo_t", "m_nameToken");
}
void GConstantInfo_t::SetNameToken(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "ConstantInfo_t", "m_nameToken", true, value);
}
float GConstantInfo_t::GetValue() const {
    return GetSchemaValue<float>(m_ptr, "ConstantInfo_t", "m_flValue");
}
void GConstantInfo_t::SetValue(float value) {
    SetSchemaValue(m_ptr, "ConstantInfo_t", "m_flValue", true, value);
}
std::string GConstantInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GConstantInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassConstantInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GConstantInfo_t>("ConstantInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GConstantInfo_t::GetName, &GConstantInfo_t::SetName)
        .addProperty("NameToken", &GConstantInfo_t::GetNameToken, &GConstantInfo_t::SetNameToken)
        .addProperty("Value", &GConstantInfo_t::GetValue, &GConstantInfo_t::SetValue)
        .addFunction("ToPtr", &GConstantInfo_t::ToPtr)
        .addFunction("IsValid", &GConstantInfo_t::IsValid)
        .endClass();
}