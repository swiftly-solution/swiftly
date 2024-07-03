#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRagdollUpdateNode::GCRagdollUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRagdollUpdateNode::GCRagdollUpdateNode(void *ptr) {
    m_ptr = ptr;
}
int32_t GCRagdollUpdateNode::GetWeightListIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRagdollUpdateNode", "m_nWeightListIndex");
}
void GCRagdollUpdateNode::SetWeightListIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CRagdollUpdateNode", "m_nWeightListIndex", false, value);
}
uint64_t GCRagdollUpdateNode::GetPoseControlMethod() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CRagdollUpdateNode", "m_poseControlMethod");
}
void GCRagdollUpdateNode::SetPoseControlMethod(uint64_t value) {
    SetSchemaValue(m_ptr, "CRagdollUpdateNode", "m_poseControlMethod", false, value);
}
std::string GCRagdollUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRagdollUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCRagdollUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCRagdollUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRagdollUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollUpdateNode>("CRagdollUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WeightListIndex", &GCRagdollUpdateNode::GetWeightListIndex, &GCRagdollUpdateNode::SetWeightListIndex)
        .addProperty("PoseControlMethod", &GCRagdollUpdateNode::GetPoseControlMethod, &GCRagdollUpdateNode::SetPoseControlMethod)
        .addProperty("Parent", &GCRagdollUpdateNode::GetParent, &GCRagdollUpdateNode::SetParent)
        .addFunction("ToPtr", &GCRagdollUpdateNode::ToPtr)
        .addFunction("IsValid", &GCRagdollUpdateNode::IsValid)
        .endClass();
}