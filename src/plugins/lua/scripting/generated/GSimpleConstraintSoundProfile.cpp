#include "../../../core/scripting/generated/classes/GSimpleConstraintSoundProfile.h"
#include "../core.h"

void SetupLuaClassGSimpleConstraintSoundProfile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSimpleConstraintSoundProfile>("SimpleConstraintSoundProfile")
        .addProperty("Keypoints", &GSimpleConstraintSoundProfile::GetKeypoints, &GSimpleConstraintSoundProfile::SetKeypoints)
        .addProperty("KeyPoints", &GSimpleConstraintSoundProfile::GetKeyPoints, &GSimpleConstraintSoundProfile::SetKeyPoints)
        .addProperty("ReversalSoundThresholds", &GSimpleConstraintSoundProfile::GetReversalSoundThresholds, &GSimpleConstraintSoundProfile::SetReversalSoundThresholds)
        .endClass();
}