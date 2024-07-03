#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootAdjustmentUpdateNode::GCFootAdjustmentUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootAdjustmentUpdateNode::GCFootAdjustmentUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCPoseHandle GCFootAdjustmentUpdateNode::GetBasePoseCacheHandle() const {
    GCPoseHandle value(GetSchemaPtr(m_ptr, "CFootAdjustmentUpdateNode", "m_hBasePoseCacheHandle"));
    return value;
}
void GCFootAdjustmentUpdateNode::SetBasePoseCacheHandle(GCPoseHandle value) {
    SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_hBasePoseCacheHandle", false, value);
}
GCAnimParamHandle GCFootAdjustmentUpdateNode::GetFacingTarget() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CFootAdjustmentUpdateNode", "m_facingTarget"));
    return value;
}
void GCFootAdjustmentUpdateNode::SetFacingTarget(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_facingTarget", false, value);
}
float GCFootAdjustmentUpdateNode::GetTurnTimeMin() const {
    return GetSchemaValue<float>(m_ptr, "CFootAdjustmentUpdateNode", "m_flTurnTimeMin");
}
void GCFootAdjustmentUpdateNode::SetTurnTimeMin(float value) {
    SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_flTurnTimeMin", false, value);
}
float GCFootAdjustmentUpdateNode::GetTurnTimeMax() const {
    return GetSchemaValue<float>(m_ptr, "CFootAdjustmentUpdateNode", "m_flTurnTimeMax");
}
void GCFootAdjustmentUpdateNode::SetTurnTimeMax(float value) {
    SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_flTurnTimeMax", false, value);
}
float GCFootAdjustmentUpdateNode::GetStepHeightMax() const {
    return GetSchemaValue<float>(m_ptr, "CFootAdjustmentUpdateNode", "m_flStepHeightMax");
}
void GCFootAdjustmentUpdateNode::SetStepHeightMax(float value) {
    SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_flStepHeightMax", false, value);
}
float GCFootAdjustmentUpdateNode::GetStepHeightMaxAngle() const {
    return GetSchemaValue<float>(m_ptr, "CFootAdjustmentUpdateNode", "m_flStepHeightMaxAngle");
}
void GCFootAdjustmentUpdateNode::SetStepHeightMaxAngle(float value) {
    SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_flStepHeightMaxAngle", false, value);
}
bool GCFootAdjustmentUpdateNode::GetResetChild() const {
    return GetSchemaValue<bool>(m_ptr, "CFootAdjustmentUpdateNode", "m_bResetChild");
}
void GCFootAdjustmentUpdateNode::SetResetChild(bool value) {
    SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_bResetChild", false, value);
}
bool GCFootAdjustmentUpdateNode::GetAnimationDriven() const {
    return GetSchemaValue<bool>(m_ptr, "CFootAdjustmentUpdateNode", "m_bAnimationDriven");
}
void GCFootAdjustmentUpdateNode::SetAnimationDriven(bool value) {
    SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_bAnimationDriven", false, value);
}
std::string GCFootAdjustmentUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootAdjustmentUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCFootAdjustmentUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCFootAdjustmentUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFootAdjustmentUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootAdjustmentUpdateNode>("CFootAdjustmentUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BasePoseCacheHandle", &GCFootAdjustmentUpdateNode::GetBasePoseCacheHandle, &GCFootAdjustmentUpdateNode::SetBasePoseCacheHandle)
        .addProperty("FacingTarget", &GCFootAdjustmentUpdateNode::GetFacingTarget, &GCFootAdjustmentUpdateNode::SetFacingTarget)
        .addProperty("TurnTimeMin", &GCFootAdjustmentUpdateNode::GetTurnTimeMin, &GCFootAdjustmentUpdateNode::SetTurnTimeMin)
        .addProperty("TurnTimeMax", &GCFootAdjustmentUpdateNode::GetTurnTimeMax, &GCFootAdjustmentUpdateNode::SetTurnTimeMax)
        .addProperty("StepHeightMax", &GCFootAdjustmentUpdateNode::GetStepHeightMax, &GCFootAdjustmentUpdateNode::SetStepHeightMax)
        .addProperty("StepHeightMaxAngle", &GCFootAdjustmentUpdateNode::GetStepHeightMaxAngle, &GCFootAdjustmentUpdateNode::SetStepHeightMaxAngle)
        .addProperty("ResetChild", &GCFootAdjustmentUpdateNode::GetResetChild, &GCFootAdjustmentUpdateNode::SetResetChild)
        .addProperty("AnimationDriven", &GCFootAdjustmentUpdateNode::GetAnimationDriven, &GCFootAdjustmentUpdateNode::SetAnimationDriven)
        .addProperty("Parent", &GCFootAdjustmentUpdateNode::GetParent, &GCFootAdjustmentUpdateNode::SetParent)
        .addFunction("ToPtr", &GCFootAdjustmentUpdateNode::ToPtr)
        .addFunction("IsValid", &GCFootAdjustmentUpdateNode::IsValid)
        .endClass();
}