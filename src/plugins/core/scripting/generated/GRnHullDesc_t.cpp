#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnHullDesc_t::GRnHullDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnHullDesc_t::GRnHullDesc_t(void *ptr) {
    m_ptr = ptr;
}
GRnHull_t GRnHullDesc_t::GetHull() const {
    GRnHull_t value(GetSchemaPtr(m_ptr, "RnHullDesc_t", "m_Hull"));
    return value;
}
void GRnHullDesc_t::SetHull(GRnHull_t value) {
    SetSchemaValue(m_ptr, "RnHullDesc_t", "m_Hull", true, value);
}
std::string GRnHullDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnHullDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
GRnShapeDesc_t GRnHullDesc_t::GetParent() const {
    GRnShapeDesc_t value(m_ptr);
    return value;
}
void GRnHullDesc_t::SetParent(GRnShapeDesc_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassRnHullDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnHullDesc_t>("RnHullDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Hull", &GRnHullDesc_t::GetHull, &GRnHullDesc_t::SetHull)
        .addProperty("Parent", &GRnHullDesc_t::GetParent, &GRnHullDesc_t::SetParent)
        .addFunction("ToPtr", &GRnHullDesc_t::ToPtr)
        .addFunction("IsValid", &GRnHullDesc_t::IsValid)
        .endClass();
}