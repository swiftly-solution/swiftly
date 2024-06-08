#include "../../../core/scripting/generated/classes/GCInfoDeathmatchSpawn.h"
#include "../core.h"

void SetupLuaClassGCInfoDeathmatchSpawn(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoDeathmatchSpawn>("CInfoDeathmatchSpawn")

        .endClass();
}