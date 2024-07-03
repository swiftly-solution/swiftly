#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GControlPointReference_t::GControlPointReference_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GControlPointReference_t::GControlPointReference_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GControlPointReference_t::GetControlPointNameString() const {
    return GetSchemaValue<int32_t>(m_ptr, "ControlPointReference_t", "m_controlPointNameString");
}
void GControlPointReference_t::SetControlPointNameString(int32_t value) {
    SetSchemaValue(m_ptr, "ControlPointReference_t", "m_controlPointNameString", true, value);
}
Vector GControlPointReference_t::GetOffsetFromControlPoint() const {
    return GetSchemaValue<Vector>(m_ptr, "ControlPointReference_t", "m_vOffsetFromControlPoint");
}
void GControlPointReference_t::SetOffsetFromControlPoint(Vector value) {
    SetSchemaValue(m_ptr, "ControlPointReference_t", "m_vOffsetFromControlPoint", true, value);
}
bool GControlPointReference_t::GetOffsetInLocalSpace() const {
    return GetSchemaValue<bool>(m_ptr, "ControlPointReference_t", "m_bOffsetInLocalSpace");
}
void GControlPointReference_t::SetOffsetInLocalSpace(bool value) {
    SetSchemaValue(m_ptr, "ControlPointReference_t", "m_bOffsetInLocalSpace", true, value);
}
std::string GControlPointReference_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GControlPointReference_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassControlPointReference_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GControlPointReference_t>("ControlPointReference_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ControlPointNameString", &GControlPointReference_t::GetControlPointNameString, &GControlPointReference_t::SetControlPointNameString)
        .addProperty("OffsetFromControlPoint", &GControlPointReference_t::GetOffsetFromControlPoint, &GControlPointReference_t::SetOffsetFromControlPoint)
        .addProperty("OffsetInLocalSpace", &GControlPointReference_t::GetOffsetInLocalSpace, &GControlPointReference_t::SetOffsetInLocalSpace)
        .addFunction("ToPtr", &GControlPointReference_t::ToPtr)
        .addFunction("IsValid", &GControlPointReference_t::IsValid)
        .endClass();
}