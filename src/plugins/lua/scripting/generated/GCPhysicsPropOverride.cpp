#include "../../../core/scripting/generated/classes/GCPhysicsPropOverride.h"
#include "../core.h"

void SetupLuaClassGCPhysicsPropOverride(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsPropOverride>("CPhysicsPropOverride")

        .endClass();
}