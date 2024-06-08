#include "../../../core/scripting/generated/classes/GCMelee.h"
#include "../core.h"

void SetupLuaClassGCMelee(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMelee>("CMelee")

        .endClass();
}