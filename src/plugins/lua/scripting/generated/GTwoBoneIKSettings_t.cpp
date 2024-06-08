#include "../../../core/scripting/generated/classes/GTwoBoneIKSettings_t.h"
#include "../core.h"

void SetupLuaClassGTwoBoneIKSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTwoBoneIKSettings_t>("TwoBoneIKSettings_t")
        .addProperty("EndEffectorType", &GTwoBoneIKSettings_t::GetEndEffectorType, &GTwoBoneIKSettings_t::SetEndEffectorType)
        .addProperty("EndEffectorAttachment", &GTwoBoneIKSettings_t::GetEndEffectorAttachment, &GTwoBoneIKSettings_t::SetEndEffectorAttachment)
        .addProperty("TargetType", &GTwoBoneIKSettings_t::GetTargetType, &GTwoBoneIKSettings_t::SetTargetType)
        .addProperty("TargetAttachment", &GTwoBoneIKSettings_t::GetTargetAttachment, &GTwoBoneIKSettings_t::SetTargetAttachment)
        .addProperty("TargetBoneIndex", &GTwoBoneIKSettings_t::GetTargetBoneIndex, &GTwoBoneIKSettings_t::SetTargetBoneIndex)
        .addProperty("PositionParam", &GTwoBoneIKSettings_t::GetPositionParam, &GTwoBoneIKSettings_t::SetPositionParam)
        .addProperty("RotationParam", &GTwoBoneIKSettings_t::GetRotationParam, &GTwoBoneIKSettings_t::SetRotationParam)
        .addProperty("AlwaysUseFallbackHinge", &GTwoBoneIKSettings_t::GetAlwaysUseFallbackHinge, &GTwoBoneIKSettings_t::SetAlwaysUseFallbackHinge)
        .addProperty("LsFallbackHingeAxis", &GTwoBoneIKSettings_t::GetLsFallbackHingeAxis, &GTwoBoneIKSettings_t::SetLsFallbackHingeAxis)
        .addProperty("FixedBoneIndex", &GTwoBoneIKSettings_t::GetFixedBoneIndex, &GTwoBoneIKSettings_t::SetFixedBoneIndex)
        .addProperty("MiddleBoneIndex", &GTwoBoneIKSettings_t::GetMiddleBoneIndex, &GTwoBoneIKSettings_t::SetMiddleBoneIndex)
        .addProperty("EndBoneIndex", &GTwoBoneIKSettings_t::GetEndBoneIndex, &GTwoBoneIKSettings_t::SetEndBoneIndex)
        .addProperty("MatchTargetOrientation", &GTwoBoneIKSettings_t::GetMatchTargetOrientation, &GTwoBoneIKSettings_t::SetMatchTargetOrientation)
        .addProperty("ConstrainTwist", &GTwoBoneIKSettings_t::GetConstrainTwist, &GTwoBoneIKSettings_t::SetConstrainTwist)
        .addProperty("MaxTwist", &GTwoBoneIKSettings_t::GetMaxTwist, &GTwoBoneIKSettings_t::SetMaxTwist)
        .endClass();
}