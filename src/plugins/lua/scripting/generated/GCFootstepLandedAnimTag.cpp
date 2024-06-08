#include "../../../core/scripting/generated/classes/GCFootstepLandedAnimTag.h"
#include "../core.h"

void SetupLuaClassGCFootstepLandedAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootstepLandedAnimTag>("CFootstepLandedAnimTag")
        .addProperty("FootstepType", &GCFootstepLandedAnimTag::GetFootstepType, &GCFootstepLandedAnimTag::SetFootstepType)
        .addProperty("OverrideSoundName", &GCFootstepLandedAnimTag::GetOverrideSoundName, &GCFootstepLandedAnimTag::SetOverrideSoundName)
        .addProperty("DebugAnimSourceString", &GCFootstepLandedAnimTag::GetDebugAnimSourceString, &GCFootstepLandedAnimTag::SetDebugAnimSourceString)
        .addProperty("BoneName", &GCFootstepLandedAnimTag::GetBoneName, &GCFootstepLandedAnimTag::SetBoneName)
        .endClass();
}