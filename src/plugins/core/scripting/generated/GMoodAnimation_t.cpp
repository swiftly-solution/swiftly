#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMoodAnimation_t::GMoodAnimation_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMoodAnimation_t::GMoodAnimation_t(void *ptr) {
    m_ptr = ptr;
}
std::string GMoodAnimation_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "MoodAnimation_t", "m_sName").Get();
}
void GMoodAnimation_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "MoodAnimation_t", "m_sName", true, CUtlString(value.c_str()));
}
float GMoodAnimation_t::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "MoodAnimation_t", "m_flWeight");
}
void GMoodAnimation_t::SetWeight(float value) {
    SetSchemaValue(m_ptr, "MoodAnimation_t", "m_flWeight", true, value);
}
std::string GMoodAnimation_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMoodAnimation_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassMoodAnimation_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMoodAnimation_t>("MoodAnimation_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GMoodAnimation_t::GetName, &GMoodAnimation_t::SetName)
        .addProperty("Weight", &GMoodAnimation_t::GetWeight, &GMoodAnimation_t::SetWeight)
        .addFunction("ToPtr", &GMoodAnimation_t::ToPtr)
        .addFunction("IsValid", &GMoodAnimation_t::IsValid)
        .endClass();
}