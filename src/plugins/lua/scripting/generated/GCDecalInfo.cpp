#include "../../../core/scripting/generated/classes/GCDecalInfo.h"
#include "../core.h"

void SetupLuaClassGCDecalInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDecalInfo>("CDecalInfo")
        .addProperty("AnimationScale", &GCDecalInfo::GetAnimationScale, &GCDecalInfo::SetAnimationScale)
        .addProperty("AnimationLifeSpan", &GCDecalInfo::GetAnimationLifeSpan, &GCDecalInfo::SetAnimationLifeSpan)
        .addProperty("PlaceTime", &GCDecalInfo::GetPlaceTime, &GCDecalInfo::SetPlaceTime)
        .addProperty("FadeStartTime", &GCDecalInfo::GetFadeStartTime, &GCDecalInfo::SetFadeStartTime)
        .addProperty("FadeDuration", &GCDecalInfo::GetFadeDuration, &GCDecalInfo::SetFadeDuration)
        .addProperty("VBSlot", &GCDecalInfo::GetVBSlot, &GCDecalInfo::SetVBSlot)
        .addProperty("BoneIndex", &GCDecalInfo::GetBoneIndex, &GCDecalInfo::SetBoneIndex)
        .addProperty("Position", &GCDecalInfo::GetPosition, &GCDecalInfo::SetPosition)
        .addProperty("BoundingRadiusSqr", &GCDecalInfo::GetBoundingRadiusSqr, &GCDecalInfo::SetBoundingRadiusSqr)
        .addProperty("Next", &GCDecalInfo::GetNext, &GCDecalInfo::SetNext)
        .addProperty("Prev", &GCDecalInfo::GetPrev, &GCDecalInfo::SetPrev)
        .addProperty("DecalMaterialIndex", &GCDecalInfo::GetDecalMaterialIndex, &GCDecalInfo::SetDecalMaterialIndex)
        .endClass();
}