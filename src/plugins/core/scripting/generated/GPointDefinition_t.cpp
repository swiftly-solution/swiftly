#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPointDefinition_t::GPointDefinition_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPointDefinition_t::GPointDefinition_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GPointDefinition_t::GetControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "PointDefinition_t", "m_nControlPoint");
}
void GPointDefinition_t::SetControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "PointDefinition_t", "m_nControlPoint", true, value);
}
bool GPointDefinition_t::GetLocalCoords() const {
    return GetSchemaValue<bool>(m_ptr, "PointDefinition_t", "m_bLocalCoords");
}
void GPointDefinition_t::SetLocalCoords(bool value) {
    SetSchemaValue(m_ptr, "PointDefinition_t", "m_bLocalCoords", true, value);
}
Vector GPointDefinition_t::GetOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "PointDefinition_t", "m_vOffset");
}
void GPointDefinition_t::SetOffset(Vector value) {
    SetSchemaValue(m_ptr, "PointDefinition_t", "m_vOffset", true, value);
}
std::string GPointDefinition_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPointDefinition_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPointDefinition_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPointDefinition_t>("PointDefinition_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ControlPoint", &GPointDefinition_t::GetControlPoint, &GPointDefinition_t::SetControlPoint)
        .addProperty("LocalCoords", &GPointDefinition_t::GetLocalCoords, &GPointDefinition_t::SetLocalCoords)
        .addProperty("Offset", &GPointDefinition_t::GetOffset, &GPointDefinition_t::SetOffset)
        .addFunction("ToPtr", &GPointDefinition_t::ToPtr)
        .addFunction("IsValid", &GPointDefinition_t::IsValid)
        .endClass();
}