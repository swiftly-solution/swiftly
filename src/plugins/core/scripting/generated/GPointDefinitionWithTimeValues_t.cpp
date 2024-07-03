#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPointDefinitionWithTimeValues_t::GPointDefinitionWithTimeValues_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPointDefinitionWithTimeValues_t::GPointDefinitionWithTimeValues_t(void *ptr) {
    m_ptr = ptr;
}
float GPointDefinitionWithTimeValues_t::GetTimeDuration() const {
    return GetSchemaValue<float>(m_ptr, "PointDefinitionWithTimeValues_t", "m_flTimeDuration");
}
void GPointDefinitionWithTimeValues_t::SetTimeDuration(float value) {
    SetSchemaValue(m_ptr, "PointDefinitionWithTimeValues_t", "m_flTimeDuration", true, value);
}
std::string GPointDefinitionWithTimeValues_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPointDefinitionWithTimeValues_t::IsValid() {
    return (m_ptr != nullptr);
}
GPointDefinition_t GPointDefinitionWithTimeValues_t::GetParent() const {
    GPointDefinition_t value(m_ptr);
    return value;
}
void GPointDefinitionWithTimeValues_t::SetParent(GPointDefinition_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassPointDefinitionWithTimeValues_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPointDefinitionWithTimeValues_t>("PointDefinitionWithTimeValues_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TimeDuration", &GPointDefinitionWithTimeValues_t::GetTimeDuration, &GPointDefinitionWithTimeValues_t::SetTimeDuration)
        .addProperty("Parent", &GPointDefinitionWithTimeValues_t::GetParent, &GPointDefinitionWithTimeValues_t::SetParent)
        .addFunction("ToPtr", &GPointDefinitionWithTimeValues_t::ToPtr)
        .addFunction("IsValid", &GPointDefinitionWithTimeValues_t::IsValid)
        .endClass();
}