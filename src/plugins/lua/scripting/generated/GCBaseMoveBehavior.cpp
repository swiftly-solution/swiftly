#include "../../../core/scripting/generated/classes/GCBaseMoveBehavior.h"
#include "../core.h"

void SetupLuaClassGCBaseMoveBehavior(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseMoveBehavior>("CBaseMoveBehavior")
        .addProperty("PositionInterpolator", &GCBaseMoveBehavior::GetPositionInterpolator, &GCBaseMoveBehavior::SetPositionInterpolator)
        .addProperty("RotationInterpolator", &GCBaseMoveBehavior::GetRotationInterpolator, &GCBaseMoveBehavior::SetRotationInterpolator)
        .addProperty("AnimStartTime", &GCBaseMoveBehavior::GetAnimStartTime, &GCBaseMoveBehavior::SetAnimStartTime)
        .addProperty("AnimEndTime", &GCBaseMoveBehavior::GetAnimEndTime, &GCBaseMoveBehavior::SetAnimEndTime)
        .addProperty("AverageSpeedAcrossFrame", &GCBaseMoveBehavior::GetAverageSpeedAcrossFrame, &GCBaseMoveBehavior::SetAverageSpeedAcrossFrame)
        .addProperty("CurrentKeyFrame", &GCBaseMoveBehavior::GetCurrentKeyFrame, &GCBaseMoveBehavior::SetCurrentKeyFrame)
        .addProperty("TargetKeyFrame", &GCBaseMoveBehavior::GetTargetKeyFrame, &GCBaseMoveBehavior::SetTargetKeyFrame)
        .addProperty("PreKeyFrame", &GCBaseMoveBehavior::GetPreKeyFrame, &GCBaseMoveBehavior::SetPreKeyFrame)
        .addProperty("PostKeyFrame", &GCBaseMoveBehavior::GetPostKeyFrame, &GCBaseMoveBehavior::SetPostKeyFrame)
        .addProperty("TimeIntoFrame", &GCBaseMoveBehavior::GetTimeIntoFrame, &GCBaseMoveBehavior::SetTimeIntoFrame)
        .addProperty("Direction", &GCBaseMoveBehavior::GetDirection, &GCBaseMoveBehavior::SetDirection)
        .endClass();
}