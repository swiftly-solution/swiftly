#include "../../../core/scripting/generated/classes/GFootLockPoseOpFixedSettings.h"
#include "../core.h"

void SetupLuaClassGFootLockPoseOpFixedSettings(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFootLockPoseOpFixedSettings>("FootLockPoseOpFixedSettings")
        .addProperty("FootInfo", &GFootLockPoseOpFixedSettings::GetFootInfo, &GFootLockPoseOpFixedSettings::SetFootInfo)
        .addProperty("HipDampingSettings", &GFootLockPoseOpFixedSettings::GetHipDampingSettings, &GFootLockPoseOpFixedSettings::SetHipDampingSettings)
        .addProperty("HipBoneIndex", &GFootLockPoseOpFixedSettings::GetHipBoneIndex, &GFootLockPoseOpFixedSettings::SetHipBoneIndex)
        .addProperty("IkSolverType", &GFootLockPoseOpFixedSettings::GetIkSolverType, &GFootLockPoseOpFixedSettings::SetIkSolverType)
        .addProperty("ApplyTilt", &GFootLockPoseOpFixedSettings::GetApplyTilt, &GFootLockPoseOpFixedSettings::SetApplyTilt)
        .addProperty("ApplyHipDrop", &GFootLockPoseOpFixedSettings::GetApplyHipDrop, &GFootLockPoseOpFixedSettings::SetApplyHipDrop)
        .addProperty("AlwaysUseFallbackHinge", &GFootLockPoseOpFixedSettings::GetAlwaysUseFallbackHinge, &GFootLockPoseOpFixedSettings::SetAlwaysUseFallbackHinge)
        .addProperty("ApplyFootRotationLimits", &GFootLockPoseOpFixedSettings::GetApplyFootRotationLimits, &GFootLockPoseOpFixedSettings::SetApplyFootRotationLimits)
        .addProperty("ApplyLegTwistLimits", &GFootLockPoseOpFixedSettings::GetApplyLegTwistLimits, &GFootLockPoseOpFixedSettings::SetApplyLegTwistLimits)
        .addProperty("MaxFootHeight", &GFootLockPoseOpFixedSettings::GetMaxFootHeight, &GFootLockPoseOpFixedSettings::SetMaxFootHeight)
        .addProperty("ExtensionScale", &GFootLockPoseOpFixedSettings::GetExtensionScale, &GFootLockPoseOpFixedSettings::SetExtensionScale)
        .addProperty("MaxLegTwist", &GFootLockPoseOpFixedSettings::GetMaxLegTwist, &GFootLockPoseOpFixedSettings::SetMaxLegTwist)
        .addProperty("EnableLockBreaking", &GFootLockPoseOpFixedSettings::GetEnableLockBreaking, &GFootLockPoseOpFixedSettings::SetEnableLockBreaking)
        .addProperty("LockBreakTolerance", &GFootLockPoseOpFixedSettings::GetLockBreakTolerance, &GFootLockPoseOpFixedSettings::SetLockBreakTolerance)
        .addProperty("LockBlendTime", &GFootLockPoseOpFixedSettings::GetLockBlendTime, &GFootLockPoseOpFixedSettings::SetLockBlendTime)
        .addProperty("EnableStretching", &GFootLockPoseOpFixedSettings::GetEnableStretching, &GFootLockPoseOpFixedSettings::SetEnableStretching)
        .addProperty("MaxStretchAmount", &GFootLockPoseOpFixedSettings::GetMaxStretchAmount, &GFootLockPoseOpFixedSettings::SetMaxStretchAmount)
        .addProperty("StretchExtensionScale", &GFootLockPoseOpFixedSettings::GetStretchExtensionScale, &GFootLockPoseOpFixedSettings::SetStretchExtensionScale)
        .endClass();
}