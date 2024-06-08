#include "../../../core/scripting/generated/classes/GCPhysicsPropMultiplayer.h"
#include "../core.h"

void SetupLuaClassGCPhysicsPropMultiplayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsPropMultiplayer>("CPhysicsPropMultiplayer")

        .endClass();
}