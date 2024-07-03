#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeNodeReverseOffset_t::GFeNodeReverseOffset_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeNodeReverseOffset_t::GFeNodeReverseOffset_t(void *ptr) {
    m_ptr = ptr;
}
Vector GFeNodeReverseOffset_t::GetOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "FeNodeReverseOffset_t", "vOffset");
}
void GFeNodeReverseOffset_t::SetOffset(Vector value) {
    SetSchemaValue(m_ptr, "FeNodeReverseOffset_t", "vOffset", true, value);
}
uint16_t GFeNodeReverseOffset_t::GetBoneCtrl() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeNodeReverseOffset_t", "nBoneCtrl");
}
void GFeNodeReverseOffset_t::SetBoneCtrl(uint16_t value) {
    SetSchemaValue(m_ptr, "FeNodeReverseOffset_t", "nBoneCtrl", true, value);
}
uint16_t GFeNodeReverseOffset_t::GetTargetNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeNodeReverseOffset_t", "nTargetNode");
}
void GFeNodeReverseOffset_t::SetTargetNode(uint16_t value) {
    SetSchemaValue(m_ptr, "FeNodeReverseOffset_t", "nTargetNode", true, value);
}
std::string GFeNodeReverseOffset_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeNodeReverseOffset_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeNodeReverseOffset_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeNodeReverseOffset_t>("FeNodeReverseOffset_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Offset", &GFeNodeReverseOffset_t::GetOffset, &GFeNodeReverseOffset_t::SetOffset)
        .addProperty("BoneCtrl", &GFeNodeReverseOffset_t::GetBoneCtrl, &GFeNodeReverseOffset_t::SetBoneCtrl)
        .addProperty("TargetNode", &GFeNodeReverseOffset_t::GetTargetNode, &GFeNodeReverseOffset_t::SetTargetNode)
        .addFunction("ToPtr", &GFeNodeReverseOffset_t::ToPtr)
        .addFunction("IsValid", &GFeNodeReverseOffset_t::IsValid)
        .endClass();
}