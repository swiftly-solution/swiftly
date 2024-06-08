#include "../../../core/scripting/generated/classes/GIPhysicsPlayerController.h"
#include "../core.h"

void SetupLuaClassGIPhysicsPlayerController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIPhysicsPlayerController>("IPhysicsPlayerController")

        .endClass();
}