#include "../../../core/scripting/generated/classes/GCSkeletonAnimationController.h"
#include "../core.h"

void SetupLuaClassGCSkeletonAnimationController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkeletonAnimationController>("CSkeletonAnimationController")
        .addProperty("SkeletonInstance", &GCSkeletonAnimationController::GetSkeletonInstance, &GCSkeletonAnimationController::SetSkeletonInstance)
        .endClass();
}