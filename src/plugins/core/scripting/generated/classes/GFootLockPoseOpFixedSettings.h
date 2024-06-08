class GFootLockPoseOpFixedSettings;

#ifndef _gcfootlockposeopfixedsettings_h
#define _gcfootlockposeopfixedsettings_h

#include "../../../scripting.h"

#include "../types/GIKSolverType.h"
#include "GFootFixedData_t.h"
#include "GCAnimInputDamping.h"

class GFootLockPoseOpFixedSettings
{
private:
    void *m_ptr;

public:
    GFootLockPoseOpFixedSettings() {}
    GFootLockPoseOpFixedSettings(void *ptr) : m_ptr(ptr) {}

    std::vector<GFootFixedData_t> GetFootInfo() const { CUtlVector<GFootFixedData_t>* vec = GetSchemaValue<CUtlVector<GFootFixedData_t>*>(m_ptr, "FootLockPoseOpFixedSettings", "m_footInfo"); std::vector<GFootFixedData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFootInfo(std::vector<GFootFixedData_t> value) { SetSchemaValueCUtlVector<GFootFixedData_t>(m_ptr, "FootLockPoseOpFixedSettings", "m_footInfo", false, value); }
    GCAnimInputDamping GetHipDampingSettings() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "FootLockPoseOpFixedSettings", "m_hipDampingSettings"); }
    void SetHipDampingSettings(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_hipDampingSettings", false, value); }
    int32_t GetHipBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootLockPoseOpFixedSettings", "m_nHipBoneIndex"); }
    void SetHipBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_nHipBoneIndex", false, value); }
    IKSolverType GetIkSolverType() const { return GetSchemaValue<IKSolverType>(m_ptr, "FootLockPoseOpFixedSettings", "m_ikSolverType"); }
    void SetIkSolverType(IKSolverType value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_ikSolverType", false, value); }
    bool GetApplyTilt() const { return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyTilt"); }
    void SetApplyTilt(bool value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyTilt", false, value); }
    bool GetApplyHipDrop() const { return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyHipDrop"); }
    void SetApplyHipDrop(bool value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyHipDrop", false, value); }
    bool GetAlwaysUseFallbackHinge() const { return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bAlwaysUseFallbackHinge"); }
    void SetAlwaysUseFallbackHinge(bool value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bAlwaysUseFallbackHinge", false, value); }
    bool GetApplyFootRotationLimits() const { return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyFootRotationLimits"); }
    void SetApplyFootRotationLimits(bool value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyFootRotationLimits", false, value); }
    bool GetApplyLegTwistLimits() const { return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyLegTwistLimits"); }
    void SetApplyLegTwistLimits(bool value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyLegTwistLimits", false, value); }
    float GetMaxFootHeight() const { return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxFootHeight"); }
    void SetMaxFootHeight(float value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxFootHeight", false, value); }
    float GetExtensionScale() const { return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flExtensionScale"); }
    void SetExtensionScale(float value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flExtensionScale", false, value); }
    float GetMaxLegTwist() const { return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxLegTwist"); }
    void SetMaxLegTwist(float value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxLegTwist", false, value); }
    bool GetEnableLockBreaking() const { return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bEnableLockBreaking"); }
    void SetEnableLockBreaking(bool value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bEnableLockBreaking", false, value); }
    float GetLockBreakTolerance() const { return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flLockBreakTolerance"); }
    void SetLockBreakTolerance(float value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flLockBreakTolerance", false, value); }
    float GetLockBlendTime() const { return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flLockBlendTime"); }
    void SetLockBlendTime(float value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flLockBlendTime", false, value); }
    bool GetEnableStretching() const { return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bEnableStretching"); }
    void SetEnableStretching(bool value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bEnableStretching", false, value); }
    float GetMaxStretchAmount() const { return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxStretchAmount"); }
    void SetMaxStretchAmount(float value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxStretchAmount", false, value); }
    float GetStretchExtensionScale() const { return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flStretchExtensionScale"); }
    void SetStretchExtensionScale(float value) { SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flStretchExtensionScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif