#include "../../../core/scripting/generated/classes/GCGameEnd.h"
#include "../core.h"

void SetupLuaClassGCGameEnd(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameEnd>("CGameEnd")

        .endClass();
}