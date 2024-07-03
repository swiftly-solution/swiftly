#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeNodeBase_t::GFeNodeBase_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeNodeBase_t::GFeNodeBase_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFeNodeBase_t::GetNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeNodeBase_t", "nNode");
}
void GFeNodeBase_t::SetNode(uint16_t value) {
    SetSchemaValue(m_ptr, "FeNodeBase_t", "nNode", true, value);
}
std::vector<uint16_t> GFeNodeBase_t::GetDummy() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeNodeBase_t", "nDummy"); std::vector<uint16_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeNodeBase_t::SetDummy(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeNodeBase_t", "nDummy"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeNodeBase_t", "nDummy", true, outValue);
}
uint16_t GFeNodeBase_t::GetNodeX0() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeNodeBase_t", "nNodeX0");
}
void GFeNodeBase_t::SetNodeX0(uint16_t value) {
    SetSchemaValue(m_ptr, "FeNodeBase_t", "nNodeX0", true, value);
}
uint16_t GFeNodeBase_t::GetNodeX1() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeNodeBase_t", "nNodeX1");
}
void GFeNodeBase_t::SetNodeX1(uint16_t value) {
    SetSchemaValue(m_ptr, "FeNodeBase_t", "nNodeX1", true, value);
}
uint16_t GFeNodeBase_t::GetNodeY0() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeNodeBase_t", "nNodeY0");
}
void GFeNodeBase_t::SetNodeY0(uint16_t value) {
    SetSchemaValue(m_ptr, "FeNodeBase_t", "nNodeY0", true, value);
}
uint16_t GFeNodeBase_t::GetNodeY1() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeNodeBase_t", "nNodeY1");
}
void GFeNodeBase_t::SetNodeY1(uint16_t value) {
    SetSchemaValue(m_ptr, "FeNodeBase_t", "nNodeY1", true, value);
}
std::string GFeNodeBase_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeNodeBase_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeNodeBase_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeNodeBase_t>("FeNodeBase_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GFeNodeBase_t::GetNode, &GFeNodeBase_t::SetNode)
        .addProperty("Dummy", &GFeNodeBase_t::GetDummy, &GFeNodeBase_t::SetDummy)
        .addProperty("NodeX0", &GFeNodeBase_t::GetNodeX0, &GFeNodeBase_t::SetNodeX0)
        .addProperty("NodeX1", &GFeNodeBase_t::GetNodeX1, &GFeNodeBase_t::SetNodeX1)
        .addProperty("NodeY0", &GFeNodeBase_t::GetNodeY0, &GFeNodeBase_t::SetNodeY0)
        .addProperty("NodeY1", &GFeNodeBase_t::GetNodeY1, &GFeNodeBase_t::SetNodeY1)
        .addFunction("ToPtr", &GFeNodeBase_t::ToPtr)
        .addFunction("IsValid", &GFeNodeBase_t::IsValid)
        .endClass();
}