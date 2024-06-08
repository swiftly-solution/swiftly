#include "../../../core/scripting/generated/classes/GCFootLockUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCFootLockUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootLockUpdateNode>("CFootLockUpdateNode")
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
        .endClass();
}