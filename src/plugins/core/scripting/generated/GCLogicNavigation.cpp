#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicNavigation::GCLogicNavigation(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicNavigation::GCLogicNavigation(void *ptr) {
    m_ptr = ptr;
}
bool GCLogicNavigation::GetIsOn() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicNavigation", "m_isOn");
}
void GCLogicNavigation::SetIsOn(bool value) {
    SetSchemaValue(m_ptr, "CLogicNavigation", "m_isOn", false, value);
}
uint64_t GCLogicNavigation::GetNavProperty() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CLogicNavigation", "m_navProperty");
}
void GCLogicNavigation::SetNavProperty(uint64_t value) {
    SetSchemaValue(m_ptr, "CLogicNavigation", "m_navProperty", false, value);
}
std::string GCLogicNavigation::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicNavigation::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicNavigation::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicNavigation::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicNavigation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicNavigation>("CLogicNavigation")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IsOn", &GCLogicNavigation::GetIsOn, &GCLogicNavigation::SetIsOn)
        .addProperty("NavProperty", &GCLogicNavigation::GetNavProperty, &GCLogicNavigation::SetNavProperty)
        .addProperty("Parent", &GCLogicNavigation::GetParent, &GCLogicNavigation::SetParent)
        .addFunction("ToPtr", &GCLogicNavigation::ToPtr)
        .addFunction("IsValid", &GCLogicNavigation::IsValid)
        .endClass();
}