#include "../../../core/scripting/generated/classes/GCSkeletonInstance.h"
#include "../core.h"

void SetupLuaClassGCSkeletonInstance(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkeletonInstance>("CSkeletonInstance")
        .addProperty("ModelState", &GCSkeletonInstance::GetModelState, &GCSkeletonInstance::SetModelState)
        .addProperty("IsAnimationEnabled", &GCSkeletonInstance::GetIsAnimationEnabled, &GCSkeletonInstance::SetIsAnimationEnabled)
        .addProperty("UseParentRenderBounds", &GCSkeletonInstance::GetUseParentRenderBounds, &GCSkeletonInstance::SetUseParentRenderBounds)
        .addProperty("DisableSolidCollisionsForHierarchy", &GCSkeletonInstance::GetDisableSolidCollisionsForHierarchy, &GCSkeletonInstance::SetDisableSolidCollisionsForHierarchy)
        .addProperty("MaterialGroup", &GCSkeletonInstance::GetMaterialGroup, &GCSkeletonInstance::SetMaterialGroup)
        .addProperty("HitboxSet", &GCSkeletonInstance::GetHitboxSet, &GCSkeletonInstance::SetHitboxSet)
        .endClass();
}