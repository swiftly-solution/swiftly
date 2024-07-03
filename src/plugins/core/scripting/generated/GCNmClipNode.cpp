#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmClipNode::GCNmClipNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmClipNode::GCNmClipNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmClipNode::GetPlayInReverseValueNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmClipNode", "m_nPlayInReverseValueNodeIdx");
}
void GCNmClipNode::SetPlayInReverseValueNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmClipNode", "m_nPlayInReverseValueNodeIdx", false, value);
}
int16_t GCNmClipNode::GetResetTimeValueNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmClipNode", "m_nResetTimeValueNodeIdx");
}
void GCNmClipNode::SetResetTimeValueNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmClipNode", "m_nResetTimeValueNodeIdx", false, value);
}
bool GCNmClipNode::GetSampleRootMotion() const {
    return GetSchemaValue<bool>(m_ptr, "CNmClipNode", "m_bSampleRootMotion");
}
void GCNmClipNode::SetSampleRootMotion(bool value) {
    SetSchemaValue(m_ptr, "CNmClipNode", "m_bSampleRootMotion", false, value);
}
bool GCNmClipNode::GetAllowLooping() const {
    return GetSchemaValue<bool>(m_ptr, "CNmClipNode", "m_bAllowLooping");
}
void GCNmClipNode::SetAllowLooping(bool value) {
    SetSchemaValue(m_ptr, "CNmClipNode", "m_bAllowLooping", false, value);
}
int16_t GCNmClipNode::GetDataSlotIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmClipNode", "m_nDataSlotIdx");
}
void GCNmClipNode::SetDataSlotIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmClipNode", "m_nDataSlotIdx", false, value);
}
std::string GCNmClipNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmClipNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmPoseNode GCNmClipNode::GetParent() const {
    GCNmPoseNode value(m_ptr);
    return value;
}
void GCNmClipNode::SetParent(GCNmPoseNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmClipNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmClipNode>("CNmClipNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PlayInReverseValueNodeIdx", &GCNmClipNode::GetPlayInReverseValueNodeIdx, &GCNmClipNode::SetPlayInReverseValueNodeIdx)
        .addProperty("ResetTimeValueNodeIdx", &GCNmClipNode::GetResetTimeValueNodeIdx, &GCNmClipNode::SetResetTimeValueNodeIdx)
        .addProperty("SampleRootMotion", &GCNmClipNode::GetSampleRootMotion, &GCNmClipNode::SetSampleRootMotion)
        .addProperty("AllowLooping", &GCNmClipNode::GetAllowLooping, &GCNmClipNode::SetAllowLooping)
        .addProperty("DataSlotIdx", &GCNmClipNode::GetDataSlotIdx, &GCNmClipNode::SetDataSlotIdx)
        .addProperty("Parent", &GCNmClipNode::GetParent, &GCNmClipNode::SetParent)
        .addFunction("ToPtr", &GCNmClipNode::ToPtr)
        .addFunction("IsValid", &GCNmClipNode::IsValid)
        .endClass();
}