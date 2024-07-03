#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeWeightedNode_t::GFeWeightedNode_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeWeightedNode_t::GFeWeightedNode_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFeWeightedNode_t::GetNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeWeightedNode_t", "nNode");
}
void GFeWeightedNode_t::SetNode(uint16_t value) {
    SetSchemaValue(m_ptr, "FeWeightedNode_t", "nNode", true, value);
}
uint16_t GFeWeightedNode_t::GetWeight() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeWeightedNode_t", "nWeight");
}
void GFeWeightedNode_t::SetWeight(uint16_t value) {
    SetSchemaValue(m_ptr, "FeWeightedNode_t", "nWeight", true, value);
}
std::string GFeWeightedNode_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeWeightedNode_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeWeightedNode_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeWeightedNode_t>("FeWeightedNode_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GFeWeightedNode_t::GetNode, &GFeWeightedNode_t::SetNode)
        .addProperty("Weight", &GFeWeightedNode_t::GetWeight, &GFeWeightedNode_t::SetWeight)
        .addFunction("ToPtr", &GFeWeightedNode_t::ToPtr)
        .addFunction("IsValid", &GFeWeightedNode_t::IsValid)
        .endClass();
}