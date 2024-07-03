#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeFollowNode_t::GFeFollowNode_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeFollowNode_t::GFeFollowNode_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFeFollowNode_t::GetParentNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeFollowNode_t", "nParentNode");
}
void GFeFollowNode_t::SetParentNode(uint16_t value) {
    SetSchemaValue(m_ptr, "FeFollowNode_t", "nParentNode", true, value);
}
uint16_t GFeFollowNode_t::GetChildNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeFollowNode_t", "nChildNode");
}
void GFeFollowNode_t::SetChildNode(uint16_t value) {
    SetSchemaValue(m_ptr, "FeFollowNode_t", "nChildNode", true, value);
}
float GFeFollowNode_t::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "FeFollowNode_t", "flWeight");
}
void GFeFollowNode_t::SetWeight(float value) {
    SetSchemaValue(m_ptr, "FeFollowNode_t", "flWeight", true, value);
}
std::string GFeFollowNode_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeFollowNode_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeFollowNode_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeFollowNode_t>("FeFollowNode_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ParentNode", &GFeFollowNode_t::GetParentNode, &GFeFollowNode_t::SetParentNode)
        .addProperty("ChildNode", &GFeFollowNode_t::GetChildNode, &GFeFollowNode_t::SetChildNode)
        .addProperty("Weight", &GFeFollowNode_t::GetWeight, &GFeFollowNode_t::SetWeight)
        .addFunction("ToPtr", &GFeFollowNode_t::ToPtr)
        .addFunction("IsValid", &GFeFollowNode_t::IsValid)
        .endClass();
}