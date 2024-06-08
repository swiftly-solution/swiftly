#include "../../../core/scripting/generated/classes/GFollowTargetOpFixedSettings_t.h"
#include "../core.h"

void SetupLuaClassGFollowTargetOpFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFollowTargetOpFixedSettings_t>("FollowTargetOpFixedSettings_t")
        .addProperty("BoneIndex", &GFollowTargetOpFixedSettings_t::GetBoneIndex, &GFollowTargetOpFixedSettings_t::SetBoneIndex)
        .addProperty("BoneTarget", &GFollowTargetOpFixedSettings_t::GetBoneTarget, &GFollowTargetOpFixedSettings_t::SetBoneTarget)
        .addProperty("BoneTargetIndex", &GFollowTargetOpFixedSettings_t::GetBoneTargetIndex, &GFollowTargetOpFixedSettings_t::SetBoneTargetIndex)
        .addProperty("WorldCoodinateTarget", &GFollowTargetOpFixedSettings_t::GetWorldCoodinateTarget, &GFollowTargetOpFixedSettings_t::SetWorldCoodinateTarget)
        .addProperty("MatchTargetOrientation", &GFollowTargetOpFixedSettings_t::GetMatchTargetOrientation, &GFollowTargetOpFixedSettings_t::SetMatchTargetOrientation)
        .endClass();
}