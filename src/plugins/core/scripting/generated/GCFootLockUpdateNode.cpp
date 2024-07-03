#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootLockUpdateNode::GCFootLockUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootLockUpdateNode::GCFootLockUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GFootLockPoseOpFixedSettings GCFootLockUpdateNode::GetOpFixedSettings() const {
    GFootLockPoseOpFixedSettings value(GetSchemaPtr(m_ptr, "CFootLockUpdateNode", "m_opFixedSettings"));
    return value;
}
void GCFootLockUpdateNode::SetOpFixedSettings(GFootLockPoseOpFixedSettings value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_opFixedSettings", false, value);
}
std::vector<GFootFixedSettings> GCFootLockUpdateNode::GetFootSettings() const {
    CUtlVector<GFootFixedSettings>* vec = GetSchemaValue<CUtlVector<GFootFixedSettings>*>(m_ptr, "CFootLockUpdateNode", "m_footSettings"); std::vector<GFootFixedSettings> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFootLockUpdateNode::SetFootSettings(std::vector<GFootFixedSettings> value) {
    SetSchemaValueCUtlVector<GFootFixedSettings>(m_ptr, "CFootLockUpdateNode", "m_footSettings", false, value);
}
GCAnimInputDamping GCFootLockUpdateNode::GetHipShiftDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CFootLockUpdateNode", "m_hipShiftDamping"));
    return value;
}
void GCFootLockUpdateNode::SetHipShiftDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_hipShiftDamping", false, value);
}
GCAnimInputDamping GCFootLockUpdateNode::GetRootHeightDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CFootLockUpdateNode", "m_rootHeightDamping"));
    return value;
}
void GCFootLockUpdateNode::SetRootHeightDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_rootHeightDamping", false, value);
}
float GCFootLockUpdateNode::GetStrideCurveScale() const {
    return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flStrideCurveScale");
}
void GCFootLockUpdateNode::SetStrideCurveScale(float value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flStrideCurveScale", false, value);
}
float GCFootLockUpdateNode::GetStrideCurveLimitScale() const {
    return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flStrideCurveLimitScale");
}
void GCFootLockUpdateNode::SetStrideCurveLimitScale(float value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flStrideCurveLimitScale", false, value);
}
float GCFootLockUpdateNode::GetStepHeightIncreaseScale() const {
    return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flStepHeightIncreaseScale");
}
void GCFootLockUpdateNode::SetStepHeightIncreaseScale(float value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flStepHeightIncreaseScale", false, value);
}
float GCFootLockUpdateNode::GetStepHeightDecreaseScale() const {
    return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flStepHeightDecreaseScale");
}
void GCFootLockUpdateNode::SetStepHeightDecreaseScale(float value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flStepHeightDecreaseScale", false, value);
}
float GCFootLockUpdateNode::GetHipShiftScale() const {
    return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flHipShiftScale");
}
void GCFootLockUpdateNode::SetHipShiftScale(float value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flHipShiftScale", false, value);
}
float GCFootLockUpdateNode::GetBlendTime() const {
    return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flBlendTime");
}
void GCFootLockUpdateNode::SetBlendTime(float value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flBlendTime", false, value);
}
float GCFootLockUpdateNode::GetMaxRootHeightOffset() const {
    return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flMaxRootHeightOffset");
}
void GCFootLockUpdateNode::SetMaxRootHeightOffset(float value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flMaxRootHeightOffset", false, value);
}
float GCFootLockUpdateNode::GetMinRootHeightOffset() const {
    return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flMinRootHeightOffset");
}
void GCFootLockUpdateNode::SetMinRootHeightOffset(float value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flMinRootHeightOffset", false, value);
}
float GCFootLockUpdateNode::GetTiltPlanePitchSpringStrength() const {
    return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flTiltPlanePitchSpringStrength");
}
void GCFootLockUpdateNode::SetTiltPlanePitchSpringStrength(float value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flTiltPlanePitchSpringStrength", false, value);
}
float GCFootLockUpdateNode::GetTiltPlaneRollSpringStrength() const {
    return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flTiltPlaneRollSpringStrength");
}
void GCFootLockUpdateNode::SetTiltPlaneRollSpringStrength(float value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flTiltPlaneRollSpringStrength", false, value);
}
bool GCFootLockUpdateNode::GetApplyFootRotationLimits() const {
    return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bApplyFootRotationLimits");
}
void GCFootLockUpdateNode::SetApplyFootRotationLimits(bool value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bApplyFootRotationLimits", false, value);
}
bool GCFootLockUpdateNode::GetApplyHipShift() const {
    return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bApplyHipShift");
}
void GCFootLockUpdateNode::SetApplyHipShift(bool value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bApplyHipShift", false, value);
}
bool GCFootLockUpdateNode::GetModulateStepHeight() const {
    return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bModulateStepHeight");
}
void GCFootLockUpdateNode::SetModulateStepHeight(bool value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bModulateStepHeight", false, value);
}
bool GCFootLockUpdateNode::GetResetChild() const {
    return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bResetChild");
}
void GCFootLockUpdateNode::SetResetChild(bool value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bResetChild", false, value);
}
bool GCFootLockUpdateNode::GetEnableVerticalCurvedPaths() const {
    return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bEnableVerticalCurvedPaths");
}
void GCFootLockUpdateNode::SetEnableVerticalCurvedPaths(bool value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bEnableVerticalCurvedPaths", false, value);
}
bool GCFootLockUpdateNode::GetEnableRootHeightDamping() const {
    return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bEnableRootHeightDamping");
}
void GCFootLockUpdateNode::SetEnableRootHeightDamping(bool value) {
    SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bEnableRootHeightDamping", false, value);
}
std::string GCFootLockUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootLockUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCFootLockUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCFootLockUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFootLockUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootLockUpdateNode>("CFootLockUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OpFixedSettings", &GCFootLockUpdateNode::GetOpFixedSettings, &GCFootLockUpdateNode::SetOpFixedSettings)
        .addProperty("FootSettings", &GCFootLockUpdateNode::GetFootSettings, &GCFootLockUpdateNode::SetFootSettings)
        .addProperty("HipShiftDamping", &GCFootLockUpdateNode::GetHipShiftDamping, &GCFootLockUpdateNode::SetHipShiftDamping)
        .addProperty("RootHeightDamping", &GCFootLockUpdateNode::GetRootHeightDamping, &GCFootLockUpdateNode::SetRootHeightDamping)
        .addProperty("StrideCurveScale", &GCFootLockUpdateNode::GetStrideCurveScale, &GCFootLockUpdateNode::SetStrideCurveScale)
        .addProperty("StrideCurveLimitScale", &GCFootLockUpdateNode::GetStrideCurveLimitScale, &GCFootLockUpdateNode::SetStrideCurveLimitScale)
        .addProperty("StepHeightIncreaseScale", &GCFootLockUpdateNode::GetStepHeightIncreaseScale, &GCFootLockUpdateNode::SetStepHeightIncreaseScale)
        .addProperty("StepHeightDecreaseScale", &GCFootLockUpdateNode::GetStepHeightDecreaseScale, &GCFootLockUpdateNode::SetStepHeightDecreaseScale)
        .addProperty("HipShiftScale", &GCFootLockUpdateNode::GetHipShiftScale, &GCFootLockUpdateNode::SetHipShiftScale)
        .addProperty("BlendTime", &GCFootLockUpdateNode::GetBlendTime, &GCFootLockUpdateNode::SetBlendTime)
        .addProperty("MaxRootHeightOffset", &GCFootLockUpdateNode::GetMaxRootHeightOffset, &GCFootLockUpdateNode::SetMaxRootHeightOffset)
        .addProperty("MinRootHeightOffset", &GCFootLockUpdateNode::GetMinRootHeightOffset, &GCFootLockUpdateNode::SetMinRootHeightOffset)
        .addProperty("TiltPlanePitchSpringStrength", &GCFootLockUpdateNode::GetTiltPlanePitchSpringStrength, &GCFootLockUpdateNode::SetTiltPlanePitchSpringStrength)
        .addProperty("TiltPlaneRollSpringStrength", &GCFootLockUpdateNode::GetTiltPlaneRollSpringStrength, &GCFootLockUpdateNode::SetTiltPlaneRollSpringStrength)
        .addProperty("ApplyFootRotationLimits", &GCFootLockUpdateNode::GetApplyFootRotationLimits, &GCFootLockUpdateNode::SetApplyFootRotationLimits)
        .addProperty("ApplyHipShift", &GCFootLockUpdateNode::GetApplyHipShift, &GCFootLockUpdateNode::SetApplyHipShift)
        .addProperty("ModulateStepHeight", &GCFootLockUpdateNode::GetModulateStepHeight, &GCFootLockUpdateNode::SetModulateStepHeight)
        .addProperty("ResetChild", &GCFootLockUpdateNode::GetResetChild, &GCFootLockUpdateNode::SetResetChild)
        .addProperty("EnableVerticalCurvedPaths", &GCFootLockUpdateNode::GetEnableVerticalCurvedPaths, &GCFootLockUpdateNode::SetEnableVerticalCurvedPaths)
        .addProperty("EnableRootHeightDamping", &GCFootLockUpdateNode::GetEnableRootHeightDamping, &GCFootLockUpdateNode::SetEnableRootHeightDamping)
        .addProperty("Parent", &GCFootLockUpdateNode::GetParent, &GCFootLockUpdateNode::SetParent)
        .addFunction("ToPtr", &GCFootLockUpdateNode::ToPtr)
        .addFunction("IsValid", &GCFootLockUpdateNode::IsValid)
        .endClass();
}