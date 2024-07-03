#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVertexPositionNormal_t::GVertexPositionNormal_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVertexPositionNormal_t::GVertexPositionNormal_t(void *ptr) {
    m_ptr = ptr;
}
Vector GVertexPositionNormal_t::GetPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "VertexPositionNormal_t", "m_vPosition");
}
void GVertexPositionNormal_t::SetPosition(Vector value) {
    SetSchemaValue(m_ptr, "VertexPositionNormal_t", "m_vPosition", true, value);
}
Vector GVertexPositionNormal_t::GetNormal() const {
    return GetSchemaValue<Vector>(m_ptr, "VertexPositionNormal_t", "m_vNormal");
}
void GVertexPositionNormal_t::SetNormal(Vector value) {
    SetSchemaValue(m_ptr, "VertexPositionNormal_t", "m_vNormal", true, value);
}
std::string GVertexPositionNormal_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVertexPositionNormal_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVertexPositionNormal_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVertexPositionNormal_t>("VertexPositionNormal_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Position", &GVertexPositionNormal_t::GetPosition, &GVertexPositionNormal_t::SetPosition)
        .addProperty("Normal", &GVertexPositionNormal_t::GetNormal, &GVertexPositionNormal_t::SetNormal)
        .addFunction("ToPtr", &GVertexPositionNormal_t::ToPtr)
        .addFunction("IsValid", &GVertexPositionNormal_t::IsValid)
        .endClass();
}