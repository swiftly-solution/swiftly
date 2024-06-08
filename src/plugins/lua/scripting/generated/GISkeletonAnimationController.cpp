#include "../../../core/scripting/generated/classes/GISkeletonAnimationController.h"
#include "../core.h"

void SetupLuaClassGISkeletonAnimationController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GISkeletonAnimationController>("ISkeletonAnimationController")

        .endClass();
}