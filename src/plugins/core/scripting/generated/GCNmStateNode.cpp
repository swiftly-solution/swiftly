#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmStateNode::GCNmStateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmStateNode::GCNmStateNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmStateNode::GetChildNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmStateNode", "m_nChildNodeIdx");
}
void GCNmStateNode::SetChildNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmStateNode", "m_nChildNodeIdx", false, value);
}
int16_t GCNmStateNode::GetLayerWeightNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmStateNode", "m_nLayerWeightNodeIdx");
}
void GCNmStateNode::SetLayerWeightNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmStateNode", "m_nLayerWeightNodeIdx", false, value);
}
int16_t GCNmStateNode::GetLayerRootMotionWeightNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmStateNode", "m_nLayerRootMotionWeightNodeIdx");
}
void GCNmStateNode::SetLayerRootMotionWeightNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmStateNode", "m_nLayerRootMotionWeightNodeIdx", false, value);
}
int16_t GCNmStateNode::GetLayerBoneMaskNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmStateNode", "m_nLayerBoneMaskNodeIdx");
}
void GCNmStateNode::SetLayerBoneMaskNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmStateNode", "m_nLayerBoneMaskNodeIdx", false, value);
}
bool GCNmStateNode::GetIsOffState() const {
    return GetSchemaValue<bool>(m_ptr, "CNmStateNode", "m_bIsOffState");
}
void GCNmStateNode::SetIsOffState(bool value) {
    SetSchemaValue(m_ptr, "CNmStateNode", "m_bIsOffState", false, value);
}
std::string GCNmStateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmStateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmPoseNode GCNmStateNode::GetParent() const {
    GCNmPoseNode value(m_ptr);
    return value;
}
void GCNmStateNode::SetParent(GCNmPoseNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmStateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmStateNode>("CNmStateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChildNodeIdx", &GCNmStateNode::GetChildNodeIdx, &GCNmStateNode::SetChildNodeIdx)
        .addProperty("LayerWeightNodeIdx", &GCNmStateNode::GetLayerWeightNodeIdx, &GCNmStateNode::SetLayerWeightNodeIdx)
        .addProperty("LayerRootMotionWeightNodeIdx", &GCNmStateNode::GetLayerRootMotionWeightNodeIdx, &GCNmStateNode::SetLayerRootMotionWeightNodeIdx)
        .addProperty("LayerBoneMaskNodeIdx", &GCNmStateNode::GetLayerBoneMaskNodeIdx, &GCNmStateNode::SetLayerBoneMaskNodeIdx)
        .addProperty("IsOffState", &GCNmStateNode::GetIsOffState, &GCNmStateNode::SetIsOffState)
        .addProperty("Parent", &GCNmStateNode::GetParent, &GCNmStateNode::SetParent)
        .addFunction("ToPtr", &GCNmStateNode::ToPtr)
        .addFunction("IsValid", &GCNmStateNode::IsValid)
        .endClass();
}