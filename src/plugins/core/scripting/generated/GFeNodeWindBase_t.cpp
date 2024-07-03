#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeNodeWindBase_t::GFeNodeWindBase_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeNodeWindBase_t::GFeNodeWindBase_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFeNodeWindBase_t::GetNodeX0() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeNodeWindBase_t", "nNodeX0");
}
void GFeNodeWindBase_t::SetNodeX0(uint16_t value) {
    SetSchemaValue(m_ptr, "FeNodeWindBase_t", "nNodeX0", true, value);
}
uint16_t GFeNodeWindBase_t::GetNodeX1() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeNodeWindBase_t", "nNodeX1");
}
void GFeNodeWindBase_t::SetNodeX1(uint16_t value) {
    SetSchemaValue(m_ptr, "FeNodeWindBase_t", "nNodeX1", true, value);
}
uint16_t GFeNodeWindBase_t::GetNodeY0() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeNodeWindBase_t", "nNodeY0");
}
void GFeNodeWindBase_t::SetNodeY0(uint16_t value) {
    SetSchemaValue(m_ptr, "FeNodeWindBase_t", "nNodeY0", true, value);
}
uint16_t GFeNodeWindBase_t::GetNodeY1() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeNodeWindBase_t", "nNodeY1");
}
void GFeNodeWindBase_t::SetNodeY1(uint16_t value) {
    SetSchemaValue(m_ptr, "FeNodeWindBase_t", "nNodeY1", true, value);
}
std::string GFeNodeWindBase_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeNodeWindBase_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeNodeWindBase_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeNodeWindBase_t>("FeNodeWindBase_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NodeX0", &GFeNodeWindBase_t::GetNodeX0, &GFeNodeWindBase_t::SetNodeX0)
        .addProperty("NodeX1", &GFeNodeWindBase_t::GetNodeX1, &GFeNodeWindBase_t::SetNodeX1)
        .addProperty("NodeY0", &GFeNodeWindBase_t::GetNodeY0, &GFeNodeWindBase_t::SetNodeY0)
        .addProperty("NodeY1", &GFeNodeWindBase_t::GetNodeY1, &GFeNodeWindBase_t::SetNodeY1)
        .addFunction("ToPtr", &GFeNodeWindBase_t::ToPtr)
        .addFunction("IsValid", &GFeNodeWindBase_t::IsValid)
        .endClass();
}