#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmLayerBlendNode::GCNmLayerBlendNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmLayerBlendNode::GCNmLayerBlendNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmLayerBlendNode::GetBaseNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmLayerBlendNode", "m_nBaseNodeIdx");
}
void GCNmLayerBlendNode::SetBaseNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmLayerBlendNode", "m_nBaseNodeIdx", false, value);
}
bool GCNmLayerBlendNode::GetOnlySampleBaseRootMotion() const {
    return GetSchemaValue<bool>(m_ptr, "CNmLayerBlendNode", "m_bOnlySampleBaseRootMotion");
}
void GCNmLayerBlendNode::SetOnlySampleBaseRootMotion(bool value) {
    SetSchemaValue(m_ptr, "CNmLayerBlendNode", "m_bOnlySampleBaseRootMotion", false, value);
}
std::string GCNmLayerBlendNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmLayerBlendNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmPoseNode GCNmLayerBlendNode::GetParent() const {
    GCNmPoseNode value(m_ptr);
    return value;
}
void GCNmLayerBlendNode::SetParent(GCNmPoseNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmLayerBlendNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmLayerBlendNode>("CNmLayerBlendNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BaseNodeIdx", &GCNmLayerBlendNode::GetBaseNodeIdx, &GCNmLayerBlendNode::SetBaseNodeIdx)
        .addProperty("OnlySampleBaseRootMotion", &GCNmLayerBlendNode::GetOnlySampleBaseRootMotion, &GCNmLayerBlendNode::SetOnlySampleBaseRootMotion)
        .addProperty("Parent", &GCNmLayerBlendNode::GetParent, &GCNmLayerBlendNode::SetParent)
        .addFunction("ToPtr", &GCNmLayerBlendNode::ToPtr)
        .addFunction("IsValid", &GCNmLayerBlendNode::IsValid)
        .endClass();
}