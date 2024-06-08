#include "../../../core/scripting/generated/classes/GFootPinningPoseOpFixedData_t.h"
#include "../core.h"

void SetupLuaClassGFootPinningPoseOpFixedData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFootPinningPoseOpFixedData_t>("FootPinningPoseOpFixedData_t")
        .addProperty("FootInfo", &GFootPinningPoseOpFixedData_t::GetFootInfo, &GFootPinningPoseOpFixedData_t::SetFootInfo)
        .addProperty("BlendTime", &GFootPinningPoseOpFixedData_t::GetBlendTime, &GFootPinningPoseOpFixedData_t::SetBlendTime)
        .addProperty("LockBreakDistance", &GFootPinningPoseOpFixedData_t::GetLockBreakDistance, &GFootPinningPoseOpFixedData_t::SetLockBreakDistance)
        .addProperty("MaxLegTwist", &GFootPinningPoseOpFixedData_t::GetMaxLegTwist, &GFootPinningPoseOpFixedData_t::SetMaxLegTwist)
        .addProperty("HipBoneIndex", &GFootPinningPoseOpFixedData_t::GetHipBoneIndex, &GFootPinningPoseOpFixedData_t::SetHipBoneIndex)
        .addProperty("ApplyLegTwistLimits", &GFootPinningPoseOpFixedData_t::GetApplyLegTwistLimits, &GFootPinningPoseOpFixedData_t::SetApplyLegTwistLimits)
        .addProperty("ApplyFootRotationLimits", &GFootPinningPoseOpFixedData_t::GetApplyFootRotationLimits, &GFootPinningPoseOpFixedData_t::SetApplyFootRotationLimits)
        .endClass();
}