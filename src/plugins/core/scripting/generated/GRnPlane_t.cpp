#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnPlane_t::GRnPlane_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnPlane_t::GRnPlane_t(void *ptr) {
    m_ptr = ptr;
}
Vector GRnPlane_t::GetNormal() const {
    return GetSchemaValue<Vector>(m_ptr, "RnPlane_t", "m_vNormal");
}
void GRnPlane_t::SetNormal(Vector value) {
    SetSchemaValue(m_ptr, "RnPlane_t", "m_vNormal", true, value);
}
float GRnPlane_t::GetOffset() const {
    return GetSchemaValue<float>(m_ptr, "RnPlane_t", "m_flOffset");
}
void GRnPlane_t::SetOffset(float value) {
    SetSchemaValue(m_ptr, "RnPlane_t", "m_flOffset", true, value);
}
std::string GRnPlane_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnPlane_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnPlane_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnPlane_t>("RnPlane_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Normal", &GRnPlane_t::GetNormal, &GRnPlane_t::SetNormal)
        .addProperty("Offset", &GRnPlane_t::GetOffset, &GRnPlane_t::SetOffset)
        .addFunction("ToPtr", &GRnPlane_t::ToPtr)
        .addFunction("IsValid", &GRnPlane_t::IsValid)
        .endClass();
}