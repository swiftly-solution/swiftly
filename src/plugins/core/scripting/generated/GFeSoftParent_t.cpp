#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeSoftParent_t::GFeSoftParent_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeSoftParent_t::GFeSoftParent_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GFeSoftParent_t::GetParent() const {
    return GetSchemaValue<int32_t>(m_ptr, "FeSoftParent_t", "nParent");
}
void GFeSoftParent_t::SetParent(int32_t value) {
    SetSchemaValue(m_ptr, "FeSoftParent_t", "nParent", true, value);
}
float GFeSoftParent_t::GetAlpha() const {
    return GetSchemaValue<float>(m_ptr, "FeSoftParent_t", "flAlpha");
}
void GFeSoftParent_t::SetAlpha(float value) {
    SetSchemaValue(m_ptr, "FeSoftParent_t", "flAlpha", true, value);
}
std::string GFeSoftParent_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeSoftParent_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeSoftParent_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSoftParent_t>("FeSoftParent_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GFeSoftParent_t::GetParent, &GFeSoftParent_t::SetParent)
        .addProperty("Alpha", &GFeSoftParent_t::GetAlpha, &GFeSoftParent_t::SetAlpha)
        .addFunction("ToPtr", &GFeSoftParent_t::ToPtr)
        .addFunction("IsValid", &GFeSoftParent_t::IsValid)
        .endClass();
}