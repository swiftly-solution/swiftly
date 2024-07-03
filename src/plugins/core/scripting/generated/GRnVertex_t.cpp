#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnVertex_t::GRnVertex_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnVertex_t::GRnVertex_t(void *ptr) {
    m_ptr = ptr;
}
uint8_t GRnVertex_t::GetEdge() const {
    return GetSchemaValue<uint8_t>(m_ptr, "RnVertex_t", "m_nEdge");
}
void GRnVertex_t::SetEdge(uint8_t value) {
    SetSchemaValue(m_ptr, "RnVertex_t", "m_nEdge", true, value);
}
std::string GRnVertex_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnVertex_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnVertex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnVertex_t>("RnVertex_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Edge", &GRnVertex_t::GetEdge, &GRnVertex_t::SetEdge)
        .addFunction("ToPtr", &GRnVertex_t::ToPtr)
        .addFunction("IsValid", &GRnVertex_t::IsValid)
        .endClass();
}