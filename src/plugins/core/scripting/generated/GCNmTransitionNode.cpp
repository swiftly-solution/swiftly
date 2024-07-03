#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmTransitionNode::GCNmTransitionNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmTransitionNode::GCNmTransitionNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmTransitionNode::GetTargetCNmStateNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmTransitionNode", "m_targetCNmStateNodeIdx");
}
void GCNmTransitionNode::SetTargetCNmStateNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmTransitionNode", "m_targetCNmStateNodeIdx", false, value);
}
int16_t GCNmTransitionNode::GetDurationOverrideNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmTransitionNode", "m_durationOverrideNodeIdx");
}
void GCNmTransitionNode::SetDurationOverrideNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmTransitionNode", "m_durationOverrideNodeIdx", false, value);
}
int16_t GCNmTransitionNode::GetSyncEventOffsetOverrideNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmTransitionNode", "m_syncEventOffsetOverrideNodeIdx");
}
void GCNmTransitionNode::SetSyncEventOffsetOverrideNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmTransitionNode", "m_syncEventOffsetOverrideNodeIdx", false, value);
}
int16_t GCNmTransitionNode::GetStartBoneMaskNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmTransitionNode", "m_startBoneMaskNodeIdx");
}
void GCNmTransitionNode::SetStartBoneMaskNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmTransitionNode", "m_startBoneMaskNodeIdx", false, value);
}
float GCNmTransitionNode::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CNmTransitionNode", "m_flDuration");
}
void GCNmTransitionNode::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CNmTransitionNode", "m_flDuration", false, value);
}
GNmPercent_t GCNmTransitionNode::GetBoneMaskBlendInTimePercentage() const {
    GNmPercent_t value(GetSchemaPtr(m_ptr, "CNmTransitionNode", "m_boneMaskBlendInTimePercentage"));
    return value;
}
void GCNmTransitionNode::SetBoneMaskBlendInTimePercentage(GNmPercent_t value) {
    SetSchemaValue(m_ptr, "CNmTransitionNode", "m_boneMaskBlendInTimePercentage", false, value);
}
float GCNmTransitionNode::GetSyncEventOffset() const {
    return GetSchemaValue<float>(m_ptr, "CNmTransitionNode", "m_syncEventOffset");
}
void GCNmTransitionNode::SetSyncEventOffset(float value) {
    SetSchemaValue(m_ptr, "CNmTransitionNode", "m_syncEventOffset", false, value);
}
GCNmTransitionNode GCNmTransitionNode::GetTransitionOptions() const {
    GCNmTransitionNode value(GetSchemaPtr(m_ptr, "CNmTransitionNode", "m_transitionOptions"));
    return value;
}
void GCNmTransitionNode::SetTransitionOptions(GCNmTransitionNode value) {
    SetSchemaValue(m_ptr, "CNmTransitionNode", "m_transitionOptions", false, value);
}
int16_t GCNmTransitionNode::GetTargetSyncIDNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmTransitionNode", "m_targetSyncIDNodeIdx");
}
void GCNmTransitionNode::SetTargetSyncIDNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmTransitionNode", "m_targetSyncIDNodeIdx", false, value);
}
uint64_t GCNmTransitionNode::GetBlendWeightEasing() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CNmTransitionNode", "m_blendWeightEasing");
}
void GCNmTransitionNode::SetBlendWeightEasing(uint64_t value) {
    SetSchemaValue(m_ptr, "CNmTransitionNode", "m_blendWeightEasing", false, value);
}
uint64_t GCNmTransitionNode::GetRootMotionBlend() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CNmTransitionNode", "m_rootMotionBlend");
}
void GCNmTransitionNode::SetRootMotionBlend(uint64_t value) {
    SetSchemaValue(m_ptr, "CNmTransitionNode", "m_rootMotionBlend", false, value);
}
std::string GCNmTransitionNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmTransitionNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmPoseNode GCNmTransitionNode::GetParent() const {
    GCNmPoseNode value(m_ptr);
    return value;
}
void GCNmTransitionNode::SetParent(GCNmPoseNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmTransitionNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmTransitionNode>("CNmTransitionNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetCNmStateNodeIdx", &GCNmTransitionNode::GetTargetCNmStateNodeIdx, &GCNmTransitionNode::SetTargetCNmStateNodeIdx)
        .addProperty("DurationOverrideNodeIdx", &GCNmTransitionNode::GetDurationOverrideNodeIdx, &GCNmTransitionNode::SetDurationOverrideNodeIdx)
        .addProperty("SyncEventOffsetOverrideNodeIdx", &GCNmTransitionNode::GetSyncEventOffsetOverrideNodeIdx, &GCNmTransitionNode::SetSyncEventOffsetOverrideNodeIdx)
        .addProperty("StartBoneMaskNodeIdx", &GCNmTransitionNode::GetStartBoneMaskNodeIdx, &GCNmTransitionNode::SetStartBoneMaskNodeIdx)
        .addProperty("Duration", &GCNmTransitionNode::GetDuration, &GCNmTransitionNode::SetDuration)
        .addProperty("BoneMaskBlendInTimePercentage", &GCNmTransitionNode::GetBoneMaskBlendInTimePercentage, &GCNmTransitionNode::SetBoneMaskBlendInTimePercentage)
        .addProperty("SyncEventOffset", &GCNmTransitionNode::GetSyncEventOffset, &GCNmTransitionNode::SetSyncEventOffset)
        .addProperty("TransitionOptions", &GCNmTransitionNode::GetTransitionOptions, &GCNmTransitionNode::SetTransitionOptions)
        .addProperty("TargetSyncIDNodeIdx", &GCNmTransitionNode::GetTargetSyncIDNodeIdx, &GCNmTransitionNode::SetTargetSyncIDNodeIdx)
        .addProperty("BlendWeightEasing", &GCNmTransitionNode::GetBlendWeightEasing, &GCNmTransitionNode::SetBlendWeightEasing)
        .addProperty("RootMotionBlend", &GCNmTransitionNode::GetRootMotionBlend, &GCNmTransitionNode::SetRootMotionBlend)
        .addProperty("Parent", &GCNmTransitionNode::GetParent, &GCNmTransitionNode::SetParent)
        .addFunction("ToPtr", &GCNmTransitionNode::ToPtr)
        .addFunction("IsValid", &GCNmTransitionNode::IsValid)
        .endClass();
}