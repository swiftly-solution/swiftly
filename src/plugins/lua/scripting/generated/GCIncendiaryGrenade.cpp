#include "../../../core/scripting/generated/classes/GCIncendiaryGrenade.h"
#include "../core.h"

void SetupLuaClassGCIncendiaryGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCIncendiaryGrenade>("CIncendiaryGrenade")

        .endClass();
}