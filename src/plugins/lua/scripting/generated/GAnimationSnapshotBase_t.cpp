#include "../../../core/scripting/generated/classes/GAnimationSnapshotBase_t.h"
#include "../core.h"

void SetupLuaClassGAnimationSnapshotBase_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimationSnapshotBase_t>("AnimationSnapshotBase_t")
        .addProperty("RealTime", &GAnimationSnapshotBase_t::GetRealTime, &GAnimationSnapshotBase_t::SetRealTime)
        .addProperty("RootToWorld", &GAnimationSnapshotBase_t::GetRootToWorld, &GAnimationSnapshotBase_t::SetRootToWorld)
        .addProperty("BonesInWorldSpace", &GAnimationSnapshotBase_t::GetBonesInWorldSpace, &GAnimationSnapshotBase_t::SetBonesInWorldSpace)
        .addProperty("BoneSetupMask", &GAnimationSnapshotBase_t::GetBoneSetupMask, &GAnimationSnapshotBase_t::SetBoneSetupMask)
        .addProperty("BoneTransforms", &GAnimationSnapshotBase_t::GetBoneTransforms, &GAnimationSnapshotBase_t::SetBoneTransforms)
        .addProperty("FlexControllers", &GAnimationSnapshotBase_t::GetFlexControllers, &GAnimationSnapshotBase_t::SetFlexControllers)
        .addProperty("SnapshotType", &GAnimationSnapshotBase_t::GetSnapshotType, &GAnimationSnapshotBase_t::SetSnapshotType)
        .addProperty("HasDecodeDump", &GAnimationSnapshotBase_t::GetHasDecodeDump, &GAnimationSnapshotBase_t::SetHasDecodeDump)
        .addProperty("DecodeDump", &GAnimationSnapshotBase_t::GetDecodeDump, &GAnimationSnapshotBase_t::SetDecodeDump)
        .endClass();
}