#include "../../../core/scripting/generated/classes/GCDecoyGrenade.h"
#include "../core.h"

void SetupLuaClassGCDecoyGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDecoyGrenade>("CDecoyGrenade")

        .endClass();
}