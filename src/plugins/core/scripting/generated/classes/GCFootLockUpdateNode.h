class GCFootLockUpdateNode;

#ifndef _gccfootlockupdatenode_h
#define _gccfootlockupdatenode_h

#include "../../../scripting.h"


#include "GFootLockPoseOpFixedSettings.h"
#include "GFootFixedSettings.h"
#include "GCAnimInputDamping.h"

class GCFootLockUpdateNode
{
private:
    void *m_ptr;

public:
    GCFootLockUpdateNode() {}
    GCFootLockUpdateNode(void *ptr) : m_ptr(ptr) {}

    GFootLockPoseOpFixedSettings GetOpFixedSettings() const { return GetSchemaValue<GFootLockPoseOpFixedSettings>(m_ptr, "CFootLockUpdateNode", "m_opFixedSettings"); }
    void SetOpFixedSettings(GFootLockPoseOpFixedSettings value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_opFixedSettings", false, value); }
    std::vector<GFootFixedSettings> GetFootSettings() const { CUtlVector<GFootFixedSettings>* vec = GetSchemaValue<CUtlVector<GFootFixedSettings>*>(m_ptr, "CFootLockUpdateNode", "m_footSettings"); std::vector<GFootFixedSettings> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFootSettings(std::vector<GFootFixedSettings> value) { SetSchemaValueCUtlVector<GFootFixedSettings>(m_ptr, "CFootLockUpdateNode", "m_footSettings", false, value); }
    GCAnimInputDamping GetHipShiftDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CFootLockUpdateNode", "m_hipShiftDamping"); }
    void SetHipShiftDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_hipShiftDamping", false, value); }
    GCAnimInputDamping GetRootHeightDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CFootLockUpdateNode", "m_rootHeightDamping"); }
    void SetRootHeightDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_rootHeightDamping", false, value); }
    float GetStrideCurveScale() const { return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flStrideCurveScale"); }
    void SetStrideCurveScale(float value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flStrideCurveScale", false, value); }
    float GetStrideCurveLimitScale() const { return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flStrideCurveLimitScale"); }
    void SetStrideCurveLimitScale(float value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flStrideCurveLimitScale", false, value); }
    float GetStepHeightIncreaseScale() const { return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flStepHeightIncreaseScale"); }
    void SetStepHeightIncreaseScale(float value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flStepHeightIncreaseScale", false, value); }
    float GetStepHeightDecreaseScale() const { return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flStepHeightDecreaseScale"); }
    void SetStepHeightDecreaseScale(float value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flStepHeightDecreaseScale", false, value); }
    float GetHipShiftScale() const { return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flHipShiftScale"); }
    void SetHipShiftScale(float value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flHipShiftScale", false, value); }
    float GetBlendTime() const { return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flBlendTime"); }
    void SetBlendTime(float value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flBlendTime", false, value); }
    float GetMaxRootHeightOffset() const { return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flMaxRootHeightOffset"); }
    void SetMaxRootHeightOffset(float value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flMaxRootHeightOffset", false, value); }
    float GetMinRootHeightOffset() const { return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flMinRootHeightOffset"); }
    void SetMinRootHeightOffset(float value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flMinRootHeightOffset", false, value); }
    float GetTiltPlanePitchSpringStrength() const { return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flTiltPlanePitchSpringStrength"); }
    void SetTiltPlanePitchSpringStrength(float value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flTiltPlanePitchSpringStrength", false, value); }
    float GetTiltPlaneRollSpringStrength() const { return GetSchemaValue<float>(m_ptr, "CFootLockUpdateNode", "m_flTiltPlaneRollSpringStrength"); }
    void SetTiltPlaneRollSpringStrength(float value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_flTiltPlaneRollSpringStrength", false, value); }
    bool GetApplyFootRotationLimits() const { return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bApplyFootRotationLimits"); }
    void SetApplyFootRotationLimits(bool value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bApplyFootRotationLimits", false, value); }
    bool GetApplyHipShift() const { return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bApplyHipShift"); }
    void SetApplyHipShift(bool value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bApplyHipShift", false, value); }
    bool GetModulateStepHeight() const { return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bModulateStepHeight"); }
    void SetModulateStepHeight(bool value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bModulateStepHeight", false, value); }
    bool GetResetChild() const { return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bResetChild"); }
    void SetResetChild(bool value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bResetChild", false, value); }
    bool GetEnableVerticalCurvedPaths() const { return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bEnableVerticalCurvedPaths"); }
    void SetEnableVerticalCurvedPaths(bool value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bEnableVerticalCurvedPaths", false, value); }
    bool GetEnableRootHeightDamping() const { return GetSchemaValue<bool>(m_ptr, "CFootLockUpdateNode", "m_bEnableRootHeightDamping"); }
    void SetEnableRootHeightDamping(bool value) { SetSchemaValue(m_ptr, "CFootLockUpdateNode", "m_bEnableRootHeightDamping", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif