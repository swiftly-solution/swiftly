#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVertexPositionColor_t::GVertexPositionColor_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVertexPositionColor_t::GVertexPositionColor_t(void *ptr) {
    m_ptr = ptr;
}
Vector GVertexPositionColor_t::GetPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "VertexPositionColor_t", "m_vPosition");
}
void GVertexPositionColor_t::SetPosition(Vector value) {
    SetSchemaValue(m_ptr, "VertexPositionColor_t", "m_vPosition", true, value);
}
std::string GVertexPositionColor_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVertexPositionColor_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVertexPositionColor_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVertexPositionColor_t>("VertexPositionColor_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Position", &GVertexPositionColor_t::GetPosition, &GVertexPositionColor_t::SetPosition)
        .addFunction("ToPtr", &GVertexPositionColor_t::ToPtr)
        .addFunction("IsValid", &GVertexPositionColor_t::IsValid)
        .endClass();
}