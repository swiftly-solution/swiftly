#include "../../../core/scripting/generated/classes/GCHEGrenade.h"
#include "../core.h"

void SetupLuaClassGCHEGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHEGrenade>("CHEGrenade")

        .endClass();
}