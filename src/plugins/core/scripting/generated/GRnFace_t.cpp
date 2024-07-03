#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnFace_t::GRnFace_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnFace_t::GRnFace_t(void *ptr) {
    m_ptr = ptr;
}
uint8_t GRnFace_t::GetEdge() const {
    return GetSchemaValue<uint8_t>(m_ptr, "RnFace_t", "m_nEdge");
}
void GRnFace_t::SetEdge(uint8_t value) {
    SetSchemaValue(m_ptr, "RnFace_t", "m_nEdge", true, value);
}
std::string GRnFace_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnFace_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnFace_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnFace_t>("RnFace_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Edge", &GRnFace_t::GetEdge, &GRnFace_t::SetEdge)
        .addFunction("ToPtr", &GRnFace_t::ToPtr)
        .addFunction("IsValid", &GRnFace_t::IsValid)
        .endClass();
}